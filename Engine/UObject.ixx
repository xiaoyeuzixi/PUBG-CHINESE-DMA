export module UObject;
import <cstdint>;
import dma;
import FName;
import Offsets;

export class UObject {
public:
	FName m_FName{};
public:
	UObject() = default;
	explicit UObject(int64_t addr, bool isRaw = false) : ptr(isRaw ? addr : dma::Read<int64_t>(addr)) {}

	void set_ptr_read(uint64_t addr) { ptr = dma::Read<int64_t>(addr); }

	void* get_ptr_data() { return &ptr; }

	const void* get_ptr_data() const { return &ptr; }

	FName get_FName();

	void scatter_FName(VMMDLL_SCATTER_HANDLE hs);

	explicit operator bool() const {
		return dma::IsValidPointer(ptr);
	}

	int64_t ptr = 0;

};

FName UObject::get_FName()
{
	return dma::Read<FName>(ptr + Offsets::UObject::FName);
}

void UObject::scatter_FName(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs , ptr + Offsets::UObject::FName , &m_FName , sizeof(m_FName));
}
