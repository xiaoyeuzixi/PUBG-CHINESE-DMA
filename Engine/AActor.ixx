export module AActor;

import UObject;
import Offsets;
import Struct;
import dma;
import AActorType;
import std;
import USceneComponent;
import <cstdint>;

export class AActor : public UObject {
public:
	using UObject::UObject;

	EntityType m_type{};

	std::string CachedName{};

	USceneComponent m_RootComponent{};
public:

	EntityType get_type(std::string name);

	void update_type(std::string name);

	void scatter_RootComponent(VMMDLL_SCATTER_HANDLE hs);

};

EntityType AActor::get_type(std::string name)
{
	return AActorType::get_type(name);
}
void AActor::update_type(std::string name)
{
	m_type = AActorType::get_type(name);
}

void AActor::scatter_RootComponent(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs , ptr + Offsets::AActor::RootComponent , m_RootComponent.get_ptr_data() , sizeof(uint64_t));
}
