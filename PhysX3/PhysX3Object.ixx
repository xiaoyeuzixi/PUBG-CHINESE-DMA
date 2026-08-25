export module PhysX3Object;
import dma;
import <cstdint>;
import Offsets_PhysX3;

export class PhysX3Object {


public:
	PhysX3Object() = default;
	explicit PhysX3Object(int64_t addr, bool isRaw = false) : ptr(isRaw ? addr : dma::Read<int64_t>(addr)) {}

	void Update(int64_t addr);
	int64_t GetPrt() ;

protected:
	int64_t ptr = 0;


};

int64_t PhysX3Object::GetPrt() 
{
	return ptr;
}
