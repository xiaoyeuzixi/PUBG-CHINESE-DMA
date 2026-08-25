export module USceneComponent;
import UObject;
import Offsets;
import dma;
import Struct;


export class USceneComponent : public UObject {
public:
	FTransform m_ComponentToWorld{};
	FVector3D m_ComponentVelocity{}; // 新增速度字段

	void scatter_ComponentToWorld(VMMDLL_SCATTER_HANDLE hs);
	void scatter_ComponentVelocity(VMMDLL_SCATTER_HANDLE hs); // 新增散读方法

};

void USceneComponent::scatter_ComponentToWorld(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::USceneComponent::ComponentToWorld, &m_ComponentToWorld, sizeof(FTransform));
}

void USceneComponent::scatter_ComponentVelocity(VMMDLL_SCATTER_HANDLE hs)
{
	// ComponentVelocity 偏移量 0x0250 (参考 SDK)
	dma::Scatter_PrepareEx(hs, ptr + 0x250, &m_ComponentVelocity, sizeof(FVector3D));
}
