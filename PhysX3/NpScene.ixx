

export module PhNpScene;
import <cstdint>;
import dma;
import Offsets_PhysX3;
import PhysX3Object;
import PhPxActorArray;

export class PhNpScene :public PhysX3Object {
public:
	using PhysX3Object::PhysX3Object;

	PhPxActorArray GetPxActorsPArray() {
		return PhPxActorArray(ptr + Offsets_PhysX3::NpScene::PxActors);
	};



};