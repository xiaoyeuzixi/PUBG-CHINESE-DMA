module;
#include <PxPhysicsAPI.h>

export module PhPxTriangleMeshGeometry;
import <cstdint>;
import dma;
import Struct_PhysX3;
import PhysX3Object;



export class PhPxTriangleMeshGeometry :public PhysX3Object {
public:

	PhPxTriangleMeshGeometry(int64_t addr, bool isRaw = false) : PhysX3Object(addr, isRaw) {
		auto selfStruct = dma::Read<PxTriangleMeshGeometry_>(ptr);
		scale = selfStruct.scale;
		meshFlags = selfStruct.meshFlags;
		triangleMesh = selfStruct.triangleMesh;

	}

	Physx3::PhPxTriangleMesh GetTriangleMesh() {
		return dma::Read<Physx3::PhPxTriangleMesh>(triangleMesh);
	}


public:
	physx::PxMeshScale scale;
	uint8_t meshFlags;
	uint64_t triangleMesh;


private:


	struct  PxTriangleMeshGeometry_ :Physx3::PhPxGeometry
	{
		physx::PxMeshScale scale;
		uint8_t meshFlags;
		uint8_t paddingFromScale[0x3];
		uint8_t padding[0x4];
		uint64_t triangleMesh; // PxTriangleMesh*
	};



};