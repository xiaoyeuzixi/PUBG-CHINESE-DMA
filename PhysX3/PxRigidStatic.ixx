module;
#include <PxPhysicsAPI.h>

export module PhPxRigidStatic;
import <cstdint>;
import dma;
import PhPxRigidBody;
import Struct_PhysX3;
import Offsets_PhysX3;


export class PhPxRigidStatic :public PhPxRigidBody {
public:
	using PhPxRigidBody::PhPxRigidBody;

	physx::PxTransform GetBody2World() {

		auto addr = ptr + Offsets_PhysX3::NpRigidStatic::Body2World;
		if (GetmControlState() & 0x40) {
			addr = GetmStreamPtr() + 0xB0;
		};

		return dma::Read<physx::PxTransform>(addr);
	}
	 
	uint8_t GetmControlState() {
		auto addr = ptr + Offsets_PhysX3::NpRigidStatic::mControlState;
		return dma::Read<uint8_t>(addr);
	}


};