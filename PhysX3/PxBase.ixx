export module PxBase;
import <cstdint>;
import dma;
import Offsets_PhysX3;
import PhysX3Object;


export class PhPxBase :public PhysX3Object {
public:
	using PhysX3Object::PhysX3Object;
	//uint16_t								mConcreteType;			// 6 D 7 S concrete type identifier - see PxConcreteType.
	//uint16_t								mBaseFlags;				// internal flags


	uint16_t GetmConcreteType() {
		return dma::Read<uint16_t>(ptr + Offsets_PhysX3::PxBase::mConcreteType);
	}

	uint16_t GetmBaseFlags() {
		return dma::Read<uint16_t>(ptr + Offsets_PhysX3::PxBase::mBaseFlags);
	}

};

