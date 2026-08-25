export module ASTExtraVehicleBase;
import APawn;
import Offsets;
import dma;
import UVehicleCommonComponent;
import Struct;

export class ASTExtraVehicleBase : public APawn
{
public:
	using APawn::APawn;

	UVehicleCommonComponent m_VehicleCommon{ 0 };
	FVector m_LinearVelocity{};

	void scatter_VehicleCommon(VMMDLL_SCATTER_HANDLE hs);
	void scatter_ReplicatedMovement(VMMDLL_SCATTER_HANDLE hs);
};

void ASTExtraVehicleBase::scatter_VehicleCommon(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::ASTExtraVehicleBase::VehicleCommon, m_VehicleCommon.get_ptr_data(), sizeof(uint64_t));
}

void ASTExtraVehicleBase::scatter_ReplicatedMovement(VMMDLL_SCATTER_HANDLE hs)
{
	// FRepMovement structure start at 0x170. LinearVelocity is at offset 0.
	dma::Scatter_PrepareEx(hs, ptr + Offsets::AActor::ReplicatedMovement, &m_LinearVelocity, sizeof(FVector));
}
 