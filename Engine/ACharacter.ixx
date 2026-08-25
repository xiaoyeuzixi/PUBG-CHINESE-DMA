export module ACharacter;
import APawn;
import dma;
import Offsets;
import USkeletalMeshComponent;
import <cstdint>;

export class ACharacter : public APawn {
public:
	using APawn::APawn;

	USkeletalMeshComponent m_Mesh{};

	void scatter_Mesh(VMMDLL_SCATTER_HANDLE hs);

};

void ACharacter::scatter_Mesh(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs , ptr + Offsets::ACharacter::Mesh , m_Mesh.get_ptr_data() , sizeof(uint64_t));
}
