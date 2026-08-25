module;
#include <PxPhysicsAPI.h>

export module PhPxHeightFieldGeometry;
import <cstdint>;
import dma;
import Struct_PhysX3;
import PhysX3Object;
import Offsets_PhysX3;

using namespace Physx3;

export class PhPxHeightFieldGeometry:public PhysX3Object {
public:
	using PhysX3Object::PhysX3Object;

	PhPxHeightFieldGeometry(int64_t addr , bool isRaw = false) : PhysX3Object(addr, isRaw) {
		auto selfStruct = dma::Read<PxHeightFieldGeometry_>(ptr);

		heightField = selfStruct.heightField;
		heightScale = selfStruct.heightScale;
		rowScale = selfStruct.rowScale;
		columnScale = selfStruct.columnScale;
		heightFieldFlags = selfStruct.heightFieldFlags;
	}


	PhPxHeightField GetHeightField() {
		return dma::Read<PhPxHeightField>(heightField);
	}


public:
	int64_t heightField;
	physx::PxReal heightScale;
	physx::PxReal rowScale;
	physx::PxReal columnScale;
	int32_t heightFieldFlags;


private:

	struct PxHeightFieldGeometry_ :PhPxGeometry {
		uint8_t padding[0x6];
		int64_t heightField; // PxHeightField*
		float heightScale;
		float rowScale;
		float columnScale;
		int32_t heightFieldFlags;

	};




}; 



