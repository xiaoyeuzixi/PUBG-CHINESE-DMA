module;
#include <cstdint>
export module PhPxActor;
import dma;
import PxBase;
import Offsets_PhysX3;
import Struct_PhysX3;


export class PhPxActor : public PhPxBase {
public:
	using PhPxBase::PhPxBase;

	Physx3::PhNpShapeManager GetmShapeManager() {
		return dma::Read<Physx3::PhNpShapeManager>(ptr + Offsets_PhysX3::PxActors::mShapeManager);
	}

	int64_t GetmStreamPtr() {
		return dma::Read<int64_t>(ptr + Offsets_PhysX3::PxActors::mStreamPtr);
	}
	uint8_t GetmActorFlags() {
		return dma::Read<uint8_t>(ptr + Offsets_PhysX3::PxActors::mActorFlags);
	}

};


