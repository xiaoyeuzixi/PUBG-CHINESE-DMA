export module UWeaponEntity;

import UObject;
import Offsets;
import std;
import dma;

export class UWeaponEntity : public UObject {
public:
	using UObject::UObject;

    void write_NoRecoil() {
        if (!ptr) return;
        float zero = 0.0f;
        dma::Write(ptr + Offsets::UWeaponEntity::VRecoilFactor, &zero, sizeof(float));
        dma::Write(ptr + Offsets::UWeaponEntity::VRecoilModifier, &zero, sizeof(float));
        dma::Write(ptr + Offsets::UWeaponEntity::HRecoilFactor, &zero, sizeof(float));
        dma::Write(ptr + Offsets::UWeaponEntity::HRecoilModifier, &zero, sizeof(float));
        dma::Write(ptr + Offsets::UWeaponEntity::RecoveryFactor, &zero, sizeof(float));
    }
};
