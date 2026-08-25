export module APlayerController;
import AController;
import APawn;
import dma;
import Offsets;
import APlayerCameraManager;
import <cstdint>;

export class APlayerController :public AController {
public:
	APawn m_AcknowledgedPawn{};
	APlayerCameraManager m_PlayerCameraManager{};
public:
	using AController::AController;

	void update_AcknowledgedPawn();
	void scatter_AcknowledgedPawn(VMMDLL_SCATTER_HANDLE hs);

	void update_PlayerCameraManager();
	void scatter_PlayerCameraManager(VMMDLL_SCATTER_HANDLE hs);

	void write_ControlRotation(float Pitch, float Yaw);
};

void APlayerController::update_AcknowledgedPawn()
{
	auto addr = ptr + Offsets::APlayerController::AcknowledgedPawn;
	m_AcknowledgedPawn.set_ptr_read(addr);
}

void APlayerController::scatter_AcknowledgedPawn(VMMDLL_SCATTER_HANDLE hs)
{
	auto addr = ptr + Offsets::APlayerController::AcknowledgedPawn;
	dma::Scatter_PrepareEx(hs , addr, m_AcknowledgedPawn.get_ptr_data(), sizeof(uint64_t));
}

void APlayerController::update_PlayerCameraManager()
{
	auto addr = ptr + Offsets::APlayerController::PlayerCameraManager;
	m_PlayerCameraManager.set_ptr_read(addr);
}

void APlayerController::scatter_PlayerCameraManager(VMMDLL_SCATTER_HANDLE hs)
{
	auto addr = ptr + Offsets::APlayerController::PlayerCameraManager;
	dma::Scatter_PrepareEx(hs , addr, m_PlayerCameraManager.get_ptr_data(), sizeof(uint64_t));
}

void APlayerController::write_ControlRotation(float Pitch, float Yaw)
{
	struct { float Pitch; float Yaw; float Roll; } rotation = { Pitch, Yaw, 0.0f };
	auto addr = ptr + Offsets::APlayerController::ControlRotation;
	dma::Write(addr, &rotation, sizeof(rotation));
}
