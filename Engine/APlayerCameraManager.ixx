export module APlayerCameraManager;
import AActor;
import Offsets;
import dma;
import Struct;

export class APlayerCameraManager :public AActor {
public:
	AActor::AActor;


	FCameraCacheEntry m_CameraCache{};


	void scatter_CameraCacheEntry(VMMDLL_SCATTER_HANDLE hs);
	FCameraCacheEntry get_CameraCacheEntry();


};

void APlayerCameraManager::scatter_CameraCacheEntry(VMMDLL_SCATTER_HANDLE hs)
{
	auto addr = ptr + Offsets::APlayerCameraManager::CameraCache;
	dma::Scatter_PrepareEx(hs , addr  , &m_CameraCache  , sizeof(m_CameraCache));
}

FCameraCacheEntry APlayerCameraManager::get_CameraCacheEntry()
{
	auto addr = ptr + Offsets::APlayerCameraManager::CameraCache;
	return dma::Read<FCameraCacheEntry>(addr);
}
