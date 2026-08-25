module;
#include <Windows.h>

export module Engine;
import CanvasMap;
import UWorld;
import dma;
import Offsets;
import <cstdint>;
import FName;
import Struct;
import std;

export class Engine {
public:
	RectInfo m_rect{};
	FVector2D m_rect_center{};

public:

	bool init();

	CanvasMap get_CanvasMap();

	UWorld get_Uworld();

	FVector3D GetBoneWorldPos(const FTransform& BoneFTransform, const FTransform& MeshTransform);

	bool WorldToScreen(const FVector3D& WorldPos, const FMatrix& ViewProjMatrix, FVector2D& Out);

	bool WorldToScreen1(FVector3D World, FCameraCacheEntry CameraCachePrivate, FVector2D& Screen);

	std::string GetBoneName(int BoneID) {
		switch (BoneID) {
		case 6: return "head";
		case 5: return "neck_01";
		case 4: return "spine_03";
		case 3: return "spine_02";
		case 2: return "spine_01";
		case 1: return "pelvis";
		default: return "";
		}
	}

private:
	uint64_t ptr = 0;

};

bool Engine::init()
{

	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	m_rect = { 0,0,screenWidth ,screenHeight };

	m_rect_center = { (float)screenWidth  /2 , (float)screenHeight /2};

	// 循环等待游戏进程启动
	std::println("等待游戏进程...");
	while (true) {
		auto ret = dma::InitPidGetFromName(Offsets::process_name.c_str());
		if (ret) {
			std::println("找到游戏进程");
			break;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	}

	ptr = dma::ProcessGetModuleBaseU(Offsets::process_name.c_str());

	FName::m_GNames = dma::Read<uint64_t>(ptr + Offsets::Base::GNames);

	if (ptr == 0) {
		return false;
	}
	return true;
}

CanvasMap Engine::get_CanvasMap()
{
	return CanvasMap(ptr + Offsets::Base::CanvasMap);
}

UWorld Engine::get_Uworld()
{
	return UWorld(ptr + Offsets::Base::GWorld);
}


FVector3D Engine::GetBoneWorldPos(const FTransform& BoneFTransform, const FTransform& MeshTransform) {
	auto MeshFMatrix = FMatrix::ToMatrixWithScale(MeshTransform);
	auto BoneFMatrix = FMatrix::ToMatrixWithScale(BoneFTransform);

	const auto FMatrix44Temp = BoneFMatrix * MeshFMatrix;
	const auto BoneWorldPos = FMatrix::GetOrigin(FMatrix44Temp);

	return BoneWorldPos;
}


bool Engine::WorldToScreen(const FVector3D& WorldPos, const FMatrix& ViewProjMatrix, FVector2D& Out) {
	FVector4D clip{};

	clip.W = WorldPos.X * ViewProjMatrix.M[0][3] + WorldPos.Y * ViewProjMatrix.M[1][3] + WorldPos.Z * ViewProjMatrix.M[2][3] + ViewProjMatrix.M[3][3];

	if (clip.W < 0.001) return false; // 在相机后面


	clip.X = WorldPos.X * ViewProjMatrix.M[0][0] + WorldPos.Y * ViewProjMatrix.M[1][0] + WorldPos.Z * ViewProjMatrix.M[2][0] + ViewProjMatrix.M[3][0];
	clip.Y = WorldPos.X * ViewProjMatrix.M[0][1] + WorldPos.Y * ViewProjMatrix.M[1][1] + WorldPos.Z * ViewProjMatrix.M[2][1] + ViewProjMatrix.M[3][1];
	clip.Z = WorldPos.X * ViewProjMatrix.M[0][2] + WorldPos.Y * ViewProjMatrix.M[1][2] + WorldPos.Z * ViewProjMatrix.M[2][2] + ViewProjMatrix.M[3][2];

	double invW = 1.0 / clip.W;
	double ndcX = clip.X * invW;
	double ndcY = clip.Y * invW;

	Out.X = (ndcX * 0.5 + 0.5) * m_rect.w;
	Out.Y = (1.0 - (ndcY * 0.5 + 0.5)) * m_rect.h;

	if (std::isnan(Out.X) || std::isnan(Out.Y) || std::isinf(Out.X) || std::isinf(Out.Y)) {
		return false;
	}

	return true;
}


bool Engine::WorldToScreen1(FVector3D World, FCameraCacheEntry CameraCachePrivate, FVector2D& Screen)
{
	FVector2D screenPos;
	FVector3D transformed;
	FVector3D AxisX, AxisY, AxisZ;
	FVector3D delta = World - CameraCachePrivate.POV.Location;

	FVector3D::GetAxes(CameraCachePrivate.POV.Rotation, &AxisX, &AxisY, &AxisZ);

	transformed.X = delta.Dot(AxisY);
	transformed.Y = delta.Dot(AxisZ);
	transformed.Z = delta.Dot(AxisX);

	if (transformed.Z < 1.0) {
		transformed.Z = 1.0;
	}

	if (transformed.Z / 100 < 0) {
		return false;
	}

	int ScreenCentenX = m_rect.w / 2;
	int ScreenCentenY = m_rect.h / 2;


	double fovTan = std::tan(CameraCachePrivate.POV.FOV * 3.1415926525 / 360.0);
	Screen.X = ScreenCentenX + transformed.X * (ScreenCentenX / fovTan) / transformed.Z;
	Screen.Y = ScreenCentenY - transformed.Y * (ScreenCentenX / fovTan) / transformed.Z;

	if (std::isnan(Screen.X) || std::isnan(Screen.Y) || std::isinf(Screen.X) || std::isinf(Screen.Y)) {
		return false;
	}

	return true;
}