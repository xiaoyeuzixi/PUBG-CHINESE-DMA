export module CanvasMap;

import UObject;
import Offsets;
import DebugCanvasObject;
import dma;
import <cstdint>;

export class CanvasMap : public UObject {
public:
	using UObject::UObject;

	DebugCanvasObject m_DebugCanvasObject{};

	DebugCanvasObject get_DebugCanvasObject();

	void scatter_DebugCanvasObject(VMMDLL_SCATTER_HANDLE hs);


};

DebugCanvasObject CanvasMap::get_DebugCanvasObject()
{
	auto addr = ptr + Offsets::CanvasMap::DebugCanvasObject;
	return DebugCanvasObject(addr);
}

void CanvasMap::scatter_DebugCanvasObject(VMMDLL_SCATTER_HANDLE hs)
{
	auto addr = ptr + Offsets::CanvasMap::DebugCanvasObject;
	dma::Scatter_PrepareEx(hs , addr , m_DebugCanvasObject.get_ptr_data() , sizeof(uint64_t));
}
