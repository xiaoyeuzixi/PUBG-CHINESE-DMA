export module UWorld;
import UObject;
import Offsets;
import ULevel;
import UGameInstance;
import dma;
import UNetDriver;
import <cstdint>;

export class UWorld : public UObject {
public:
	using UObject::UObject;

	UNetDriver m_NetDriver{};
	ULevel m_PersistentLevel{};
	UGameInstance m_OwningGameInstance{};
public:

	ULevel get_PersistentLevel();

	void scatter_NetDriver(VMMDLL_SCATTER_HANDLE hs);
	void scatter_PersistentLevel(VMMDLL_SCATTER_HANDLE hs);
	void scatter_OwningGameInstance(VMMDLL_SCATTER_HANDLE hs);
};


ULevel UWorld::get_PersistentLevel() { 
	auto addr = ptr + Offsets::UWorld::PersistentLevel;
	return ULevel(addr);
}

void UWorld::scatter_NetDriver(VMMDLL_SCATTER_HANDLE hs)
{
	auto addr = ptr + Offsets::UWorld::NetDriver;
	dma::Scatter_PrepareEx(hs, addr, m_NetDriver.get_ptr_data(), sizeof(uint64_t));
}

void UWorld::scatter_PersistentLevel(VMMDLL_SCATTER_HANDLE hs)
{
	auto addr = ptr + Offsets::UWorld::PersistentLevel;
	dma::Scatter_PrepareEx(hs, addr, m_PersistentLevel.get_ptr_data() , sizeof(uint64_t));

}

void UWorld::scatter_OwningGameInstance(VMMDLL_SCATTER_HANDLE hs)
{
	auto addr = ptr + Offsets::UWorld::OwningGameInstance;
	dma::Scatter_PrepareEx(hs, addr, m_OwningGameInstance.get_ptr_data(), sizeof(uint64_t));
}
