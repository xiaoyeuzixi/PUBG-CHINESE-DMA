module;
#include <PxPhysicsAPI.h>
#include  <cstdint>
export module Struct_PhysX3;
import std;
import Struct;
import dma;

export namespace Physx3
{

	export struct PArray {
		int64_t Data;
		int32_t NumElements;
		int32_t MaxElements;

	};

	export struct xBox
	{
		std::array<physx::PxVec3, 8> box;
		physx::PxFilterData fiterData;

	};
	export struct xHeight {
		uint32_t row, clos;
		std::vector<FVector3D> vec3;
	};

	export struct xTrigle {
		physx::PxVec3 t1, t2, t3;
	};


	export struct PtrTable {
		int64_t mSingle;  // NpShape
		int16_t mCount;
		bool	mOwnsMemory;
		bool	mBufferUsed;		// dark magic in serialization requires this, otherwise redundant because it's logically equivalent to mCount == 1.

	};

	export struct PhNpShapeManager {
		PtrTable mShapes; //0x0000
	};

	export struct PhPxGeometry
	{
		int16_t type;

	};




	export struct CenterExtents {
		physx::PxVec3		mCenter;
		physx::PxVec3		mExtents;
	};



	export struct HeightFieldData {

		CenterExtents									AABB;
		physx::PxU32											rows;
		physx::PxU32											columns;
		physx::PxReal											rowLimit;
		physx::PxReal	                                        colLimit;
		physx::PxReal	                                        nbColumns;
		uint8_t										    pad_4[0x4];
		int64_t											samples; // PxHeightFieldSample*[]
	};



	export struct PhPxHeightField {
	public:
		uint8_t				paddingV[0x20];
		HeightFieldData		mData;
		physx::PxU32 				mSampleStride;
		physx::PxU32				mNbSamples;
		physx::PxReal				mMinHeight;
		physx::PxReal				mMaxHeight;
		physx::PxU32				mModifyCount;

	};




	export struct PhPxTriangleMesh {
		uint8_t			paddingV[0x20];
		physx::PxU32			mNbVertices;
		physx::PxU32			mNbTriangles;
		int64_t			mVertices; // PxVec3* array
		int64_t			mTriangles; // PxU16* array
		CenterExtents	AABB;
		int64_t 			mExtraTrigData; // PxU8* 
		physx::PxReal 			mGeomEpsilon;
		physx::PxU8			mFlags;
	};





	export struct PhHullPolygonData
	{

		physx::PxPlane		mPlane;		
		physx::PxU16		mVRef8;
		physx::PxU8		mNbVerts;
		physx::PxU8		mMinIndex;

	};



	export struct PhConvexHullData
	{
		CenterExtents			mAABB;
		physx::PxVec3			mCenterOfMass;

		physx::PxBitAndWord		mNbEdges;

		physx::PxU8				mNbHullVertices;
		physx::PxU8 			mNbPolygons;
		PhHullPolygonData*		mPolygons;		// [mNbPolygons]



		__forceinline const physx::PxVec3* getHullVertices()	const	//!< Convex hull vertices
		{
			const char* tmp = reinterpret_cast<const char*>(mPolygons);
			tmp += sizeof(PhHullPolygonData) * mNbPolygons;
			return reinterpret_cast<const physx::PxVec3*>(tmp);
		}

		__forceinline	const physx::PxU8* getFacesByEdges8()	const	//!< for each edge, gives 2 adjacent polygons; used by convex-convex code to come up with all the convex' edge normals.  
		{
			const char* tmp = reinterpret_cast<const char*>(mPolygons);
			tmp += sizeof(PhHullPolygonData) * mNbPolygons;
			tmp += sizeof(physx::PxVec3) * mNbHullVertices;
			return reinterpret_cast<const physx::PxU8*>(tmp);
		}

		__forceinline const physx::PxU8* getFacesByVertices8()	const	//!< for each edge, gives 2 adjacent polygons; used by convex-convex code to come up with all the convex' edge normals.  
		{
			const char* tmp = reinterpret_cast<const char*>(mPolygons);
			tmp += sizeof(PhHullPolygonData) * mNbPolygons;
			tmp += sizeof(physx::PxVec3) * mNbHullVertices;
			tmp += sizeof(physx::PxU8) * mNbEdges * 2;
			return reinterpret_cast<const physx::PxU8*>(tmp);
		}

		//If we don't build the convex hull with grb data, we will return NULL pointer
		__forceinline	const physx::PxU16* getVerticesByEdges16()	const	//!< Vertex indices indexed by unique edges
		{
			if (mNbEdges.isBitSet())
			{
				const char* tmp = reinterpret_cast<const char*>(mPolygons);
				tmp += sizeof(PhHullPolygonData) * mNbPolygons;
				tmp += sizeof(physx::PxVec3) * mNbHullVertices;
				tmp += sizeof(physx::PxU8) * mNbEdges * 2;
				tmp += sizeof(physx::PxU8) * mNbHullVertices * 3;
				return reinterpret_cast<const physx::PxU16*>(tmp);
			}
			return NULL;
		}

		__forceinline const physx::PxU8* getVertexData8()	const	//!< Vertex indices indexed by hull polygons
		{
			const char* tmp = reinterpret_cast<const char*>(mPolygons);
			tmp += sizeof(PhHullPolygonData) * mNbPolygons;
			tmp += sizeof(physx::PxVec3) * mNbHullVertices;
			tmp += sizeof(physx::PxU8) * mNbEdges * 2;
			tmp += sizeof(physx::PxU8) * mNbHullVertices * 3;
			if (mNbEdges.isBitSet())
				tmp += sizeof(physx::PxU16) * mNbEdges * 2;
			return reinterpret_cast<const physx::PxU8*>(tmp);
		}

	};



	export struct PhPxConvexMesh {

		uint8_t				padding1[0x20];
		PhConvexHullData	mHullData;


		bool getPolygonData(physx::PxU32 i, PhHullPolygonData* polygons , physx::PxHullPolygon& data) const
		{
			if (i >= mHullData.mNbPolygons)
				return false;

			const PhHullPolygonData& poly = polygons[i];

			data.mPlane[0] = poly.mPlane.n.x;
			data.mPlane[1] = poly.mPlane.n.y;
			data.mPlane[2] = poly.mPlane.n.z;
			data.mPlane[3] = poly.mPlane.d;
			data.mNbVerts = poly.mNbVerts;
			data.mIndexBase = poly.mVRef8;
			return true;
		}


	};




	export struct PhPxBoxGeometry : public PhPxGeometry {
	public:
		physx::PxU16 padding;
		physx::PxVec3 halfExtents;


		xBox GetBox(physx::PxMat44 mat) const {
			xBox box{};
			physx::PxVec3 h = halfExtents;
			box.box[0] = mat.transform(physx::PxVec3(-h.x, -h.y, -h.z));
			box.box[1] = mat.transform(physx::PxVec3(h.x, -h.y, -h.z));
			box.box[2] = mat.transform(physx::PxVec3(h.x, h.y, -h.z));
			box.box[3] = mat.transform(physx::PxVec3(-h.x, h.y, -h.z));
							
			box.box[4] = mat.transform(physx::PxVec3(-h.x, -h.y, h.z));
			box.box[5] = mat.transform(physx::PxVec3(h.x, -h.y, h.z));
			box.box[6] = mat.transform(physx::PxVec3(h.x, h.y, h.z));
			box.box[7] = mat.transform(physx::PxVec3(-h.x, h.y, h.z));

			return box;
		}
	};





	struct PxShapeFlag
	{
		enum Enum:uint8_t
		{

			eSIMULATION_SHAPE = (1 << 0),

			eSCENE_QUERY_SHAPE = (1 << 1),


			eTRIGGER_SHAPE = (1 << 2),

			eVISUALIZATION = (1 << 3),

			ePARTICLE_DRAIN = (1 << 4)
		};
	};



}

