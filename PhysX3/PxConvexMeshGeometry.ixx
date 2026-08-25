module;
#include <PxPhysicsAPI.h>

export module PhPxConvexMeshGeometry;
import PhysX3Object;
import <cstdint>;
import dma;
import Struct_PhysX3;
import std;


export class PhPxConvexMeshGeometry : public  PhysX3Object {

public:

	PhPxConvexMeshGeometry(int64_t addr, bool isRaw = false) : PhysX3Object(addr, isRaw) {
		auto selfStruct = dma::Read<PxConvexMeshGeometry_>(ptr);
		scale = selfStruct.scale;
		convexMesh = selfStruct.convexMesh;
		maxMargin = selfStruct.maxMargin;
		meshFlags = selfStruct.meshFlags;
	}


	Physx3::PhPxConvexMesh GetConvexMesh() {
		return dma::Read<Physx3::PhPxConvexMesh>(convexMesh);
	}

public:
	physx::PxMeshScale scale;
	int64_t convexMesh;			// PxConvexMesh*
	float maxMargin;
	uint8_t meshFlags;


	struct PxConvexMeshGeometry_ :Physx3::PhPxGeometry
	{
		uint8_t						padding1[0x2];
		physx::PxMeshScale			scale;
		int64_t						convexMesh;			// PxConvexMesh*
		float						maxMargin;
		uint8_t 					meshFlags;
		uint8_t						padding2[0x3];
	};


};