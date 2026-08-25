module;
#include <PxPhysicsAPI.h>

export module PhPxRigidDynamic;
import <cstdint>;
import dma;
import PhPxRigidBody;
import Offsets_PhysX3;
import Struct_PhysX3;


export class PhPxRigidDynamic :public PhPxRigidBody {
public:
	using PhPxRigidBody::PhPxRigidBody;
	
	physx::PxTransform Getbody2Actor() {

		int64_t addr = ptr + Offsets_PhysX3::NpRigidDynamic::body2Actor;

		if (GetmBodyBufferFlags() & 0x200) {
			addr = GetmStreamPtr() + 0xE0;
		};

		return dma::Read<physx::PxTransform>(addr);
	}

	physx::PxTransform GetmBufferedBody2World() {

		auto addr = ptr + Offsets_PhysX3::NpRigidDynamic::mBufferedBody2World;
		return dma::Read<physx::PxTransform>(addr);
	}

	int32_t GetmBodyBufferFlags() {
		return dma::Read<int32_t>(ptr + Offsets_PhysX3::NpRigidDynamic::mBodyBufferFlags);
	}
};