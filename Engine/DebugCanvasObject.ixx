export module DebugCanvasObject;

import UObject;
import Offsets;
import Struct;
import dma;

export class DebugCanvasObject : public UObject {
public:
	using UObject::UObject;

	FMatrix get_FMatrix();


};

FMatrix DebugCanvasObject::get_FMatrix()
{
	return dma::Read<FMatrix>(ptr + Offsets::DebugCanvasObject::Matrix);
}
