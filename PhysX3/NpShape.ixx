module;
#include <PxPhysicsAPI.h>

export module PhNpShape;
import <cstdint>;
import dma;
import PhysX3Object;
import Struct_PhysX3;
import Offsets_PhysX3;
import PhPxHeightFieldGeometry;
import PhPxTriangleMeshGeometry;
import PhPxConvexMeshGeometry;



export class PhNpShape :public PhysX3Object {
public:
	using PhysX3Object::PhysX3Object;

	uint8_t GetmControlState() {
		return dma::Read<uint8_t>(ptr + Offsets_PhysX3::NpShape::mControlState);
	}

	int64_t GetmStreamPtr() {
	
		return dma::Read<int64_t>(ptr + Offsets_PhysX3::NpShape::mStreamPtr);
	}

	physx::PxTransform GetmLocalpos() {
		int64_t addr = ptr + Offsets_PhysX3::NpShape::mLocalpos;
		//if (GetmControlState() & 4) {
		//	addr = GetmStreamPtr();
		//}

		return dma::Read<physx::PxTransform>(addr);
	}

	uint8_t GetmFlags() {

		int64_t addr = ptr + Offsets_PhysX3::NpShape::mFlags;
		//if (GetmControlState() & 0x40) {
		//	addr = GetmStreamPtr() + 0x34;
		//}

		return dma::Read<uint8_t>(addr);
	}

	physx::PxFilterData GetmFilterData() {

		auto addr = ptr + Offsets_PhysX3::NpShape::mFilterData;
		//if (GetmControlState() & 8) {
		//	addr = GetmStreamPtr() + 0x1C;
		//}

		return dma::Read<physx::PxFilterData>(addr);
	}
	 
	Physx3::PhPxGeometry GetmPxGeometry() {

		return dma::Read<Physx3::PhPxGeometry>(ptr + Offsets_PhysX3::NpShape::mGeometry);
	}

	Physx3::PhPxBoxGeometry GetmPxBoxGeometry() {

		return dma::Read<Physx3::PhPxBoxGeometry>(ptr + Offsets_PhysX3::NpShape::mGeometry);
	}

	PhPxHeightFieldGeometry GetmPxHeightFieldGeometry() {
		return PhPxHeightFieldGeometry(ptr + Offsets_PhysX3::NpShape::mGeometry,true);
	}

	PhPxTriangleMeshGeometry GetmPxTriangleMeshGeometry() {
		return PhPxTriangleMeshGeometry(ptr + Offsets_PhysX3::NpShape::mGeometry,true);
	}

	PhPxConvexMeshGeometry GetmPxConvexMeshGeometry() {
		return PhPxConvexMeshGeometry(ptr + Offsets_PhysX3::NpShape::mGeometry,true);
	}

};