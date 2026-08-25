export module UPlayer;
import UObject;
import APlayerController;
import Offsets;
import dma;
import <cstdint>;

export class UPlayer : public UObject
{
public:

	APlayerController m_PlayerController{};

public:
	using UObject::UObject;

	void update_PlayerController();

};



void UPlayer::update_PlayerController()
{
	auto addr = ptr + Offsets::UPlayer::PlayerController;
	dma::Read(addr , m_PlayerController.get_ptr_data() , sizeof(uint64_t));

}
