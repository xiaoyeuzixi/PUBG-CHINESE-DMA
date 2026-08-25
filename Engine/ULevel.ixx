export module ULevel;

export import UObject;
import Offsets;
import TArray;
import AActor;
import dma;


export class ULevel : public UObject {
public:
	using UObject::UObject;


	TArray<AActor*> get_Actors();


};

TArray<AActor*> ULevel::get_Actors()
{
	return dma::Read<TArray<AActor*>>(ptr + Offsets::ULevel::Actors);
}
