module;
#include <cstdint>
export module PhNpSenceArray;
import Struct_PhysX3;
import dma;
import PhNpScene;




export class PhNpSenceArray {
public:
	int64_t Data;
	int32_t NumElements;
	int32_t MaxElements;


	PhNpSenceArray(int64_t addr);


	PhNpScene operator[](int index) const;


private:
	Physx3::PArray m_NpSencePArray;

};

PhNpSenceArray::PhNpSenceArray(int64_t addr) : m_NpSencePArray(dma::Read<Physx3::PArray>(addr)) {

	Data = m_NpSencePArray.Data;
	NumElements = m_NpSencePArray.NumElements;
	MaxElements = m_NpSencePArray.MaxElements;
}


PhNpScene PhNpSenceArray::operator[](int index) const
{
	if (index >= 0 && index < m_NpSencePArray.NumElements) {
		auto addr = m_NpSencePArray.Data + index * 8;
		return PhNpScene(addr);
	}
	return PhNpScene(0, true);

}
