module;
#include <PxPhysicsAPI.h>
#include <cstdint>
export module PhPxActorArray;
import Struct_PhysX3;
import dma;
import PhPxActor;


export class PhPxActorArray {

public:
	PhPxActorArray() = default;

	PhPxActorArray(int64_t addr);

	PhPxActor operator[](int index) const;

public:
	int64_t Data;
	int32_t NumElements;
	int32_t MaxElements;

private:
	Physx3::PArray m_PxActorPArray;

};

PhPxActorArray::PhPxActorArray(int64_t addr): m_PxActorPArray(dma::Read<Physx3::PArray>(addr))
{
	Data = m_PxActorPArray.Data;
	NumElements = m_PxActorPArray.NumElements;
	MaxElements = m_PxActorPArray.MaxElements;
}

PhPxActor PhPxActorArray::operator[](int index) const
{
	if (index >= 0 && index < m_PxActorPArray.NumElements) {
		auto addr = m_PxActorPArray.Data + index * 8;
		return PhPxActor(addr);
	}
	return PhPxActor(0, true);
}

