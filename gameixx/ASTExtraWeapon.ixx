export module ASTExtraWeapon;

import AActor;
import Offsets;
import std;
import dma;
import UWeaponEntity;
import <cstdint>;

export class ASTExtraWeapon : public AActor {
public:
	using AActor::AActor;

	UWeaponEntity m_WeaponEntityComp{};
	int m_CurBulletNumInClip{};
	int m_CurMaxBulletNumInOneClip{};

	void scatter_WeaponEntityComp(VMMDLL_SCATTER_HANDLE hs);
	void scatter_CurBulletNumInClip(VMMDLL_SCATTER_HANDLE hs);
	void scatter_CurMaxBulletNumInOneClip(VMMDLL_SCATTER_HANDLE hs);

};

void ASTExtraWeapon::scatter_WeaponEntityComp(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::ASTExtraWeapon::WeaponEntityComp, m_WeaponEntityComp.get_ptr_data(), sizeof(uint64_t));
}

void ASTExtraWeapon::scatter_CurBulletNumInClip(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::ASTExtraWeapon::CurBulletNumInClip, &m_CurBulletNumInClip, sizeof(int));
}

void ASTExtraWeapon::scatter_CurMaxBulletNumInOneClip(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::ASTExtraWeapon::CurMaxBulletNumInOneClip, &m_CurMaxBulletNumInOneClip, sizeof(int));
}
