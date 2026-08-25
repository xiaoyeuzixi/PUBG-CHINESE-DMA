export module UGameInstance;
import UObject;
import dma;
import Offsets;
import TArray;
import ULocalPlayer;
import <cstdint>;


export class UGameInstance :public UObject {
public:
	TArray<ULocalPlayer*> m_LocalPlayer{};
public:
	UObject::UObject;


	void update_LocalPlayer();


};

void UGameInstance::update_LocalPlayer()
{
	uint64_t addr = ptr + Offsets::UGameInstance::LocalPlayers;
	m_LocalPlayer = dma::Read<TArray<ULocalPlayer*>>(addr);

}
