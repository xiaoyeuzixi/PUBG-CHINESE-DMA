export module USkeletalMesh;
import UObject;
import TArray;
import Struct;
import Offsets;
import dma;

export class USkeletalMesh :public UObject {
public:

	TArray<FMeshBoneInfo> m_MeshBoneInfo_TArray{};

	std::vector<FMeshBoneInfo> m_MeshBoneInfo_Vector{};

	FBoxSphereBounds m_ExtendedBounds{};

public:
	using UObject::UObject;

	void scatter_ExtendedBounds(VMMDLL_SCATTER_HANDLE hs);

	void scatter_MeshBoneInfo_TArray(VMMDLL_SCATTER_HANDLE hs);

	void scatter_MeshBoneInfo_Vector(VMMDLL_SCATTER_HANDLE hs);

	void update_bone_info_map();

	std::map<std::string, int > m_bone_info_map{};

};

void USkeletalMesh::scatter_ExtendedBounds(VMMDLL_SCATTER_HANDLE hs)
{
	auto addr = ptr + Offsets::USkeletalMesh::ExtendedBounds;
	dma::Scatter_PrepareEx(hs, addr, &m_ExtendedBounds, sizeof(m_ExtendedBounds));
}

void USkeletalMesh::scatter_MeshBoneInfo_TArray(VMMDLL_SCATTER_HANDLE hs)
{
	auto addr = ptr + Offsets::USkeletalMesh::MeshBoneInfo;
	dma::Scatter_PrepareEx(hs , addr , &m_MeshBoneInfo_TArray, sizeof(m_MeshBoneInfo_TArray));
}

void USkeletalMesh::scatter_MeshBoneInfo_Vector(VMMDLL_SCATTER_HANDLE hs)
{
	if (!dma::IsValidPointer(m_MeshBoneInfo_TArray.Data) || m_MeshBoneInfo_TArray.NumElements > 500) {
		return;
	}

	m_MeshBoneInfo_Vector.resize(m_MeshBoneInfo_TArray.NumElements);
	dma::Scatter_PrepareEx(hs , m_MeshBoneInfo_TArray.Data, m_MeshBoneInfo_Vector.data(), m_MeshBoneInfo_TArray.NumElements * sizeof(FMeshBoneInfo));

}



void USkeletalMesh::update_bone_info_map()
{
	m_bone_info_map.clear();
	for (int i = 0; i < m_MeshBoneInfo_Vector.size(); i++) {
		auto bone_name = m_MeshBoneInfo_Vector[i].Name_p.ToString();
		m_bone_info_map[bone_name] = i;
	}

}