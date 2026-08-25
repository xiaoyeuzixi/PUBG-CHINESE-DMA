export module USkinnedMeshComponent;
import USceneComponent;
import dma;
import Offsets;
import Struct;
import TArray;
import USkeletalMesh;
import <cstdint>;


export class USkinnedMeshComponent : public USceneComponent {
public:
	using USceneComponent::USceneComponent;

	TArray<FTransform> m_boneTArray{};

	std::vector<FTransform> m_boneVector{};

	USkeletalMesh m_SkeletalMesh{};

	uint32_t m_boneNow{};

	FBoxSphereBounds m_CachedLocalBounds{};

public:

	void scatter_SkeletalMesh(VMMDLL_SCATTER_HANDLE hs);

	void scatter_boneNow(VMMDLL_SCATTER_HANDLE hs);

	void scatter_boneTArray(VMMDLL_SCATTER_HANDLE hs);

	void scatter_boneVector(VMMDLL_SCATTER_HANDLE hs);

	void scatter_CachedLocalBounds(VMMDLL_SCATTER_HANDLE hs);

private:

	void scatter_boneTArray1(VMMDLL_SCATTER_HANDLE hs);

	void scatter_boneTArray2(VMMDLL_SCATTER_HANDLE hs);


};

void USkinnedMeshComponent::scatter_SkeletalMesh(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::USkinnedMeshComponent::SkeletalMesh, m_SkeletalMesh.get_ptr_data(), sizeof(uint64_t));
}

void USkinnedMeshComponent::scatter_boneNow(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs , ptr + Offsets::USkinnedMeshComponent::boneNow , &m_boneNow , sizeof(m_boneNow));
}

void USkinnedMeshComponent::scatter_boneTArray(VMMDLL_SCATTER_HANDLE hs)
{
	if (m_boneNow == 1) {
		scatter_boneTArray2(hs);
	}
	else {
		scatter_boneTArray1(hs);
	}
}

void USkinnedMeshComponent::scatter_boneVector(VMMDLL_SCATTER_HANDLE hs)
{
	if (!dma::IsValidPointer(m_boneTArray.Data) || m_boneTArray.NumElements > 500) {
		return;
	}
	m_boneVector.resize(m_boneTArray.NumElements);
	dma::Scatter_PrepareEx(hs, m_boneTArray.Data, m_boneVector.data(), m_boneTArray.NumElements * sizeof(FTransform));
}


void USkinnedMeshComponent::scatter_CachedLocalBounds(VMMDLL_SCATTER_HANDLE hs)
{
	auto addr = ptr + Offsets::USkinnedMeshComponent::CachedLocalBounds;
	dma::Scatter_PrepareEx(hs, addr, &m_CachedLocalBounds, sizeof(m_CachedLocalBounds));
}

void USkinnedMeshComponent::scatter_boneTArray1(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::USkinnedMeshComponent::boneArr1, &m_boneTArray, sizeof(m_boneTArray));
}

void USkinnedMeshComponent::scatter_boneTArray2(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::USkinnedMeshComponent::boneArr2, &m_boneTArray, sizeof(m_boneTArray));
}
