#include "NetConfig/kmboxNet.h"
#include "NetConfig/KmBox.h"
#include "NetConfig/MoBox.h"
#include "NetConfig/Lurker.h"
#include "NetConfig/dma_pic.h"
#include <atomic>
#include <chrono>
#include <windows.h>
#include "imgui.h"
#include "imgui_internal.h"

import bm;
import std;
import dma;
import dx11;
import Engine;
import AActor;
import Struct;
import AUAECharacter;
import CanvasMap;
import UWorld;
import dx11_menu;
import render;
import PhysX3;
import physxEngine;
import ASTExtraVehicleBase;
import UVehicleCommonComponent;
import InputDMA;
import InputUtils;

struct AimWarningInfoData {
	std::string name;
	std::string weapon;
	int distance;
};

std::vector<AUAECharacter> g_RenderList;
std::mutex g_DataMutex;

VMMDLL_SCATTER_HANDLE g_hs_esp;

Engine m_Engine;

import WeaponTranslation;
import ItemTranslation;

std::atomic<bool> g_running{ true };
std::atomic<std::shared_ptr<UWorld>> g_uworld;
std::atomic<std::shared_ptr<AUAECharacter>> g_my_player;

std::atomic<std::shared_ptr<std::vector<AActor>>> g_item_list;
std::atomic<std::shared_ptr<std::vector<AUAECharacter>>> g_playerList;
std::atomic<std::shared_ptr<std::vector<ASTExtraVehicleBase>>> g_vehicleList;


void draw_physx_shape(ImDrawList* draw_list, PxRigidActor* actor, PxShape* shape, FCameraCacheEntry& camera_cache_private) {


	auto GlobalPos = actor->getGlobalPose();
	auto LocalPos = shape->getLocalPose();
	auto WorldPos = GlobalPos * LocalPos;

	PxMat44 m44(WorldPos);
	auto m_GeometryType = shape->getGeometryType();
	auto FilterData = shape->getQueryFilterData();


	if (m_GeometryType == PxGeometryType::eBOX)
	{

		PxBoxGeometry box{};
		if (!shape->getBoxGeometry(box)) {
			return;
		};

		PxVec3 box_pos[8]{};
		PxVec3 h = box.halfExtents;
		box_pos[0] = m44.transform(PxVec3(-h.x, -h.y, -h.z));
		box_pos[1] = m44.transform(PxVec3(h.x, -h.y, -h.z));
		box_pos[2] = m44.transform(PxVec3(h.x, h.y, -h.z));
		box_pos[3] = m44.transform(PxVec3(-h.x, h.y, -h.z));

		box_pos[4] = m44.transform(PxVec3(-h.x, -h.y, h.z));
		box_pos[5] = m44.transform(PxVec3(h.x, -h.y, h.z));
		box_pos[6] = m44.transform(PxVec3(h.x, h.y, h.z));
		box_pos[7] = m44.transform(PxVec3(-h.x, h.y, h.z));

		FVector3D check_pos = { box_pos[0].x , box_pos[0].y , box_pos[0].z };

		FVector2D out[8]{};
		bool ret[8]{};
		for (int i = 0; i < 8; i++) {

			ret[i] = m_Engine.WorldToScreen1({ box_pos[i].x , box_pos[i].y , box_pos[i].z }, camera_cache_private, out[i]);
		}


		if (!ret[0] || !ret[1] || !ret[2] || !ret[3] || !ret[4] || !ret[5] || !ret[6] || !ret[7]) {
			return;
		}





		draw_list->AddLine({ out[0].X , out[0].Y }, { out[1].X , out[1].Y }, IM_COL32(255, 255, 255, 255));
		draw_list->AddLine({ out[1].X , out[1].Y }, { out[2].X , out[2].Y }, IM_COL32(255, 255, 255, 255));
		draw_list->AddLine({ out[2].X , out[2].Y }, { out[3].X , out[3].Y }, IM_COL32(255, 255, 255, 255));
		draw_list->AddLine({ out[3].X , out[3].Y }, { out[0].X , out[0].Y }, IM_COL32(255, 255, 255, 255));

		draw_list->AddLine({ out[3].X , out[3].Y }, { out[7].X , out[7].Y }, IM_COL32(255, 255, 255, 255));
		draw_list->AddLine({ out[2].X , out[2].Y }, { out[6].X , out[6].Y }, IM_COL32(255, 255, 255, 255));
		draw_list->AddLine({ out[0].X , out[0].Y }, { out[4].X , out[4].Y }, IM_COL32(255, 255, 255, 255));
		draw_list->AddLine({ out[1].X , out[1].Y }, { out[5].X , out[5].Y }, IM_COL32(255, 255, 255, 255));

		draw_list->AddLine({ out[4].X , out[4].Y }, { out[5].X , out[5].Y }, IM_COL32(255, 255, 255, 255));
		draw_list->AddLine({ out[5].X , out[5].Y }, { out[6].X , out[6].Y }, IM_COL32(255, 255, 255, 255));
		draw_list->AddLine({ out[6].X , out[6].Y }, { out[7].X , out[7].Y }, IM_COL32(255, 255, 255, 255));
		draw_list->AddLine({ out[7].X , out[7].Y }, { out[4].X , out[4].Y }, IM_COL32(255, 255, 255, 255));


	}
	else if (m_GeometryType == PxGeometryType::eTRIANGLEMESH)
	{

		PxTriangleMeshGeometry tri{};
		if (!shape->getTriangleMeshGeometry(tri)) {
			return;
		};


		const PxU32 nbVerts = tri.triangleMesh->getNbVertices();
		const PxVec3* Verts = tri.triangleMesh->getVertices();
		const PxU32 NbTris = tri.triangleMesh->getNbTriangles();
		const void* tris = tri.triangleMesh->getTriangles();
		bool has16bit = tri.triangleMesh->getTriangleMeshFlags() & PxTriangleMeshFlag::e16_BIT_INDICES;

		uint32_t index_count{};
		PxVec3 tempVec3[3]{};
		for (int i{}; i < NbTris; i++) {
			PxU32 index[3]{};


			if (has16bit) {
				uint16_t* temp16bitBuf = (uint16_t*)tris;

				index[0] = temp16bitBuf[index_count++];
				index[1] = temp16bitBuf[index_count++];
				index[2] = temp16bitBuf[index_count++];

			}
			else {
				uint32_t* temp32bitBuf = (uint32_t*)tris;
				index[0] = temp32bitBuf[index_count++];
				index[1] = temp32bitBuf[index_count++];
				index[2] = temp32bitBuf[index_count++];

			}
			if (index[0] >= nbVerts || index[1] >= nbVerts || index[2] >= nbVerts) {
				continue;
			}

			tempVec3[0] = Verts[index[0]] * tri.scale.scale;
			tempVec3[1] = Verts[index[1]] * tri.scale.scale;
			tempVec3[2] = Verts[index[2]] * tri.scale.scale;

			tempVec3[0] = m44.transform(tempVec3[0]);
			tempVec3[1] = m44.transform(tempVec3[1]);
			tempVec3[2] = m44.transform(tempVec3[2]);


			FVector3D posv1{ tempVec3[0].x , tempVec3[0].y , tempVec3[0].z };
			FVector3D posv2{ tempVec3[1].x , tempVec3[1].y , tempVec3[1].z };
			FVector3D posv3{ tempVec3[2].x , tempVec3[2].y , tempVec3[2].z };


			FVector2D out1{}, out2{}, out3{};

			bool ret1 = m_Engine.WorldToScreen1(posv1, camera_cache_private, out1);
			bool ret2 = m_Engine.WorldToScreen1(posv2, camera_cache_private, out2);
			bool ret3 = m_Engine.WorldToScreen1(posv3, camera_cache_private, out3);

			if (!ret1 || !ret2 || !ret3) {
				continue;
			}

			if (out1.X < 0 || out1.Y < 0) {
				continue;
			}

			if (out1.X > m_Engine.m_rect.w || out1.Y > m_Engine.m_rect.h) {
				continue;
			}
			if (out2.X < 0 || out2.Y < 0) {
				continue;
			}

			if (out2.X > m_Engine.m_rect.w || out2.Y > m_Engine.m_rect.h) {
				continue;
			}

			if (out3.X < 0 || out3.Y < 0) {
				continue;
			}

			if (out3.X > m_Engine.m_rect.w || out3.Y > m_Engine.m_rect.h) {
				continue;
			}


			ImVec2 pos1{}, pos2{}, pos3{};
			pos1 = { out1.X ,out1.Y };
			pos2 = { out2.X ,out2.Y };
			pos3 = { out3.X ,out3.Y };

			draw_list->AddTriangle(pos1, pos2, pos3, imguiColor::Orange);


		}


	}
	else if (m_GeometryType == PxGeometryType::eCONVEXMESH)
	{
		physx::PxConvexMeshGeometry con_try{};
		if (!shape->getConvexMeshGeometry(con_try)) {
			return;
		};

		const physx::PxU32 polygonCount = con_try.convexMesh->getNbPolygons();
		const physx::PxU8* indexBuffer = con_try.convexMesh->getIndexBuffer();
		const physx::PxVec3* vertexBuffer = con_try.convexMesh->getVertices();


		for (physx::PxU32 i = 0; i < polygonCount; i++) {
			physx::PxHullPolygon polygon_data{};
			con_try.convexMesh->getPolygonData(i, polygon_data);

			physx::PxU32 NbVertex = polygon_data.mNbVerts;
			physx::PxVec3 tempVec3[3]{};
			for (uint32_t j = 0; j < NbVertex - 2; j++) {
				const physx::PxVec3& v0 = vertexBuffer[indexBuffer[j + 0]] * con_try.scale.scale;
				const physx::PxVec3& v1 = vertexBuffer[indexBuffer[j + 1]] * con_try.scale.scale;
				const physx::PxVec3& v2 = vertexBuffer[indexBuffer[j + 2]] * con_try.scale.scale;


				tempVec3[0] = m44.transform(v0);
				tempVec3[1] = m44.transform(v1);
				tempVec3[2] = m44.transform(v2);

				FVector3D posv1{ tempVec3[0].x , tempVec3[0].y , tempVec3[0].z };
				FVector3D posv2{ tempVec3[1].x , tempVec3[1].y , tempVec3[1].z };
				FVector3D posv3{ tempVec3[2].x , tempVec3[2].y , tempVec3[2].z };


				FVector2D out1{}, out2{}, out3{};

				bool ret1 = m_Engine.WorldToScreen1(posv1, camera_cache_private, out1);
				bool ret2 = m_Engine.WorldToScreen1(posv2, camera_cache_private, out2);
				bool ret3 = m_Engine.WorldToScreen1(posv3, camera_cache_private, out3);


				if (!ret1 || !ret2 || !ret3) {
					continue;
				}

				if (out1.X < 0 || out1.Y < 0) {
					continue;
				}

				if (out1.X > m_Engine.m_rect.w || out1.Y > m_Engine.m_rect.h) {
					continue;
				}
				if (out2.X < 0 || out2.Y < 0) {
					continue;
				}

				if (out2.X > m_Engine.m_rect.w || out2.Y > m_Engine.m_rect.h) {
					continue;
				}

				if (out3.X < 0 || out3.Y < 0) {
					continue;
				}

				if (out3.X > m_Engine.m_rect.w || out3.Y > m_Engine.m_rect.h) {
					continue;
				}
				ImVec2 pos1{}, pos2{}, pos3{};
				pos1 = { out1.X ,out1.Y };
				pos2 = { out2.X ,out2.Y };
				pos3 = { out3.X ,out3.Y };

				draw_list->AddTriangle(pos1, pos2, pos3, imguiColor::Green);

			};
			indexBuffer += NbVertex;

		}

	}
	else if (m_GeometryType == PxGeometryType::eHEIGHTFIELD)
	{
		physx::PxHeightFieldGeometry hei_try{};
		if (!shape->getHeightFieldGeometry(hei_try)) {
			return;
		}

		physx::PxU32 nbRows = hei_try.heightField->getNbRows();
		physx::PxU32 nbCols = hei_try.heightField->getNbColumns();

		const float rowScale = hei_try.rowScale;
		const float colScale = hei_try.columnScale;
		const float heightScale = hei_try.heightScale;

		// 遍历每个单元格
		for (physx::PxU32 r = 0; r < nbRows - 1; r++) {
			for (physx::PxU32 c = 0; c < nbCols - 1; c++) {

				// 四个顶点样本
				const auto& s00 = hei_try.heightField->getSample(r, c);
				const auto& s01 = hei_try.heightField->getSample(r, c + 1);
				const auto& s10 = hei_try.heightField->getSample(r + 1, c);
				const auto& s11 = hei_try.heightField->getSample(r + 1, c + 1);

				// 高度值
				float h00 = s00.height * heightScale;
				float h01 = s01.height * heightScale;
				float h10 = s10.height * heightScale;
				float h11 = s11.height * heightScale;

				// 局部坐标
				PxVec3 local00(c * colScale, h00, r * rowScale);
				PxVec3 local01((c + 1) * colScale, h01, r * rowScale);
				PxVec3 local10(c * colScale, h10, (r + 1) * rowScale);
				PxVec3 local11((c + 1) * colScale, h11, (r + 1) * rowScale);

				// 转换为世界坐标
				PxVec3 world00 = m44.transform(local00);
				PxVec3 world01 = m44.transform(local01);
				PxVec3 world10 = m44.transform(local10);
				PxVec3 world11 = m44.transform(local11);

				FVector3D pos00{ world00.x, world00.y, world00.z };
				FVector3D pos01{ world01.x, world01.y, world01.z };
				FVector3D pos10{ world10.x, world10.y, world10.z };
				FVector3D pos11{ world11.x, world11.y, world11.z };

				// 屏幕坐标
				FVector2D out00{}, out01{}, out10{}, out11{};
				bool ret00 = m_Engine.WorldToScreen1(pos00, camera_cache_private, out00);
				bool ret01 = m_Engine.WorldToScreen1(pos01, camera_cache_private, out01);
				bool ret10 = m_Engine.WorldToScreen1(pos10, camera_cache_private, out10);
				bool ret11 = m_Engine.WorldToScreen1(pos11, camera_cache_private, out11);

				if (!ret00 || !ret01 || !ret10 || !ret11)
					continue;

				// 绘制两组三角形
				ImVec2 v00{ out00.X, out00.Y };
				ImVec2 v01{ out01.X, out01.Y };
				ImVec2 v10{ out10.X, out10.Y };
				ImVec2 v11{ out11.X, out11.Y };

				draw_list->AddTriangle(v00, v01, v11, imguiColor::Blue);
				draw_list->AddTriangle(v00, v11, v10, imguiColor::Blue);
			}
		}
	}


}

void draw_physx(ImDrawList* draw_list, FCameraCacheEntry camera_cache_private, FVector3D worldOrigin = {}) {
	if (!dx11_menu::esp::show_physx_models) return;


	auto dir = camera_cache_private.GetCameraForwardLocation(30000);

	auto hit = physxEngine::LineTraceSingle(camera_cache_private.POV.Location, dir);

	if (hit.hasAnyHits()) {

		draw_physx_shape(draw_list, hit.block.actor, hit.block.shape, camera_cache_private);
	}


}

void draw_all_physx_actors(ImDrawList* draw_list, FCameraCacheEntry& camera_cache_private) {
	if (!dx11_menu::esp::show_physx_models) return;

	std::shared_lock<std::shared_mutex> lock(physxEngine::sceneMutex);
	if (!physxEngine::gScene) return;

	PxU32 nbActors = physxEngine::gScene->getNbActors(PxActorTypeFlags(PxActorTypeFlag::eRIGID_DYNAMIC | PxActorTypeFlag::eRIGID_STATIC));
	if (nbActors == 0) return;

	std::vector<PxActor*> actors(nbActors);
	physxEngine::gScene->getActors(PxActorTypeFlags(PxActorTypeFlag::eRIGID_DYNAMIC | PxActorTypeFlag::eRIGID_STATIC), actors.data(), nbActors);

	for (PxU32 i = 0; i < nbActors; i++) {
		PxRigidActor* actor = actors[i]->is<PxRigidActor>();
		if (!actor) continue;

		PxU32 nbShapes = actor->getNbShapes();
		std::vector<PxShape*> shapes(nbShapes);
		actor->getShapes(shapes.data(), nbShapes);

		for (PxU32 j = 0; j < nbShapes; j++) {
			draw_physx_shape(draw_list, actor, shapes[j], camera_cache_private);
		}
	}
}

void update_item(VMMDLL_SCATTER_HANDLE hs_data, std::vector<AActor>& item_list) {


	for (auto& item : item_list) {
		item.scatter_RootComponent(hs_data);
	}
	dma::Scatter_ExecuteRead(hs_data);

	for (auto& item : item_list) {
		item.m_RootComponent.scatter_ComponentToWorld(hs_data);
	}
	dma::Scatter_ExecuteRead(hs_data);

	g_item_list.store(std::make_shared<std::vector<AActor>>(item_list), std::memory_order_release);


}

void update_player(VMMDLL_SCATTER_HANDLE hs_data, std::vector<AUAECharacter>& player_list) {

	for (auto& player : player_list) {
		player.scatter_PlayerName_FStr(hs_data);
		player.scatter_TeamID(hs_data);
		player.scatter_bIsAI(hs_data);
		player.scatter_PawnState(hs_data);
		player.scatter_PawnStateRepSyncData_TArray(hs_data);
		player.scatter_PawnStatesExtend_FStr(hs_data);
		player.scatter_HealthStatus(hs_data);
		player.scatter_Mesh(hs_data);
		player.scatter_RootComponent(hs_data);


		player.scatter_Health(hs_data);
		player.scatter_SignalHP(hs_data);
		player.scatter_CurrentUsingWeaponSafety(hs_data);
		player.scatter_PlayerState(hs_data);
	}
	dma::Scatter_ExecuteRead(hs_data);

	for (auto& player : player_list) {
		player.m_Mesh.scatter_SkeletalMesh(hs_data);
		player.scatter_PlayerName_FFtrToWstr(hs_data);
		player.scatter_PawnStatesExtend_FStrToWstr(hs_data);
		player.scatter_PawnStateRepSyncData_Content(hs_data);

		player.m_CurrentUsingWeaponSafety.scatter_FName(hs_data);
		player.m_CurrentUsingWeaponSafety.scatter_WeaponEntityComp(hs_data);
		player.m_CurrentUsingWeaponSafety.scatter_CurBulletNumInClip(hs_data);
		player.m_CurrentUsingWeaponSafety.scatter_CurMaxBulletNumInOneClip(hs_data);
		player.scatter_PlayerStateData(hs_data);
	}
	dma::Scatter_ExecuteRead(hs_data);

	for (auto& player : player_list) {
		player.m_Mesh.m_SkeletalMesh.scatter_MeshBoneInfo_TArray(hs_data);

	}
	dma::Scatter_ExecuteRead(hs_data);

	for (auto& player : player_list) {
		player.m_Mesh.m_SkeletalMesh.scatter_MeshBoneInfo_Vector(hs_data);
	}
	dma::Scatter_ExecuteRead(hs_data);

	for (auto& player : player_list) {
		player.m_Mesh.m_SkeletalMesh.update_bone_info_map();
	}

	g_playerList.store(std::make_shared<std::vector<AUAECharacter>>(player_list), std::memory_order_release);
}

std::mutex g_vehicleMtx;
std::vector<ASTExtraVehicleBase> g_vehicleTargets;

void update_vehicle(VMMDLL_SCATTER_HANDLE hs_data, std::vector<ASTExtraVehicleBase>& vehicle_list) {
	for (auto& vehicle : vehicle_list) {
		vehicle.scatter_VehicleCommon(hs_data);
		vehicle.scatter_RootComponent(hs_data);
		vehicle.scatter_FName(hs_data);
		vehicle.scatter_ReplicatedMovement(hs_data);
	}
	dma::Scatter_ExecuteRead(hs_data);

	for (auto& vehicle : vehicle_list) {
		vehicle.m_VehicleCommon.scatter_HPMax(hs_data);
		vehicle.m_VehicleCommon.scatter_HP(hs_data);
		vehicle.m_VehicleCommon.scatter_FuelMax(hs_data);
		vehicle.m_VehicleCommon.scatter_Fuel(hs_data);
		vehicle.m_VehicleCommon.scatter_WheelsCurrentHP_TArray(hs_data);
		vehicle.m_RootComponent.scatter_ComponentToWorld(hs_data);
	}
	dma::Scatter_ExecuteRead(hs_data);

	for (auto& vehicle : vehicle_list) {
		vehicle.m_VehicleCommon.scatter_WheelsCurrentHP_Data(hs_data);
	}
	dma::Scatter_ExecuteRead(hs_data);

	g_vehicleList.store(std::make_shared<std::vector<ASTExtraVehicleBase>>(vehicle_list), std::memory_order_release);
}

void vehicle_update_thread() {
	VMMDLL_SCATTER_HANDLE hs_veh = NULL;
	while (g_running) {
		if (!hs_veh) {
			hs_veh = dma::Scatter_Initialize();
		}

		std::vector<ASTExtraVehicleBase> current_vehicles;
		{
			std::lock_guard<std::mutex> lock(g_vehicleMtx);
			current_vehicles = g_vehicleTargets;
		}

		if (current_vehicles.empty()) {
			update_vehicle(hs_veh, current_vehicles);
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			continue;
		}

		update_vehicle(hs_veh, current_vehicles);
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}

	if (hs_veh) dma::Scatter_CloseHandle(hs_veh);
}

std::mutex g_itemMtx;
std::vector<AActor> g_itemTargets;

void item_update_thread() {
	VMMDLL_SCATTER_HANDLE hs_item = NULL;
	while (g_running) {
		if (!hs_item) {
			hs_item = dma::Scatter_Initialize();
		}

		std::vector<AActor> current_items;
		{
			std::lock_guard<std::mutex> lock(g_itemMtx);
			current_items = g_itemTargets;
		}

		if (current_items.empty()) {
			std::this_thread::sleep_for(std::chrono::milliseconds(500)); // 没有物资时休眠更久
			continue;
		}

		update_item(hs_item, current_items);

		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}

	if (hs_item) dma::Scatter_CloseHandle(hs_item);
}

void read_data() {

	VMMDLL_SCATTER_HANDLE hs_data = NULL;

	std::unordered_map<uint64_t, std::string> g_ActorNameCache;

	bool physx_cleared = false;

	auto last_console_update = std::chrono::steady_clock::now();
	int loop_counter = 0;
	double total_read_time = 0;


	double time_tarray_get = 0;
	double time_name_read = 0;
	double time_update_player = 0;
	double time_update_vehicle = 0;
	double time_update_item = 0;
	double time_uworld_init = 0;
	double time_physx = 0;


	int array_read_counter = 0;
	TArray<AActor*> actors_TArray{};
	std::vector<AActor> actor_vec{};


	std::vector<AUAECharacter> cached_player_targets{};
	std::vector<ASTExtraVehicleBase> cached_vehicle_targets{};
	std::vector<AActor> cached_item_targets{};
	bool my_player_in_list = false;

	while (g_running) {
		auto loop_start = std::chrono::steady_clock::now();

		static bool was_invalid = false; // 跟踪是否刚从无效状态恢复

		if (!hs_data) {
			hs_data = dma::Scatter_Initialize();
		}


		static int tlb_refresh_counter = 0;
		if (++tlb_refresh_counter > 200) {
			dma::Refresh_TLB();
			tlb_refresh_counter = 0;
		}

		auto uworld_start = std::chrono::steady_clock::now();
		auto uworld = m_Engine.get_Uworld();


		if (!dma::IsValidPointer(uworld.ptr)) {
			if (!physx_cleared) {
				PhysX3::clearPhysx();
				physx_cleared = true;
			}
			if (hs_data) {
				dma::Scatter_CloseHandle(hs_data);
				hs_data = NULL;
			}

			g_playerList.store(std::make_shared<std::vector<AUAECharacter>>(), std::memory_order_release);
			g_item_list.store(std::make_shared<std::vector<AActor>>(), std::memory_order_release);
			g_vehicleList.store(std::make_shared<std::vector<ASTExtraVehicleBase>>(), std::memory_order_release);
			{
				std::lock_guard<std::mutex> lock(g_vehicleMtx);
				g_vehicleTargets.clear();
			}
			g_ActorNameCache.clear();

			// 刷新TLB，确保从无效状态恢复后读取最新数据
			if (!was_invalid) {
				dma::Refresh_TLB();
				dma::Refresh_MEDIUM();
				tlb_refresh_counter = 0;
			}
			was_invalid = true;
			continue;
		}

		// 从无效状态恢复 → 强制刷新并立即读取Actor数组
		if (was_invalid) {
			dma::Refresh_TLB();
			tlb_refresh_counter = 0;
			array_read_counter = 11; // 强制下一轮立即读取Actor数组
			was_invalid = false;
		}

		uworld.scatter_FName(hs_data);
		uworld.scatter_PersistentLevel(hs_data);
		uworld.scatter_NetDriver(hs_data);
		dma::Scatter_ExecuteRead(hs_data);

		uworld.m_NetDriver.update_ServerConnection();

		if (!uworld.m_NetDriver.m_ServerConnection) {
			if (!physx_cleared) {
				PhysX3::clearPhysx();
				physx_cleared = true;
			}

			if (hs_data) {
				dma::Scatter_CloseHandle(hs_data);
				hs_data = NULL;
			}

			g_playerList.store(std::make_shared<std::vector<AUAECharacter>>(), std::memory_order_release);
			g_item_list.store(std::make_shared<std::vector<AActor>>(), std::memory_order_release);
			g_vehicleList.store(std::make_shared<std::vector<ASTExtraVehicleBase>>(), std::memory_order_release);
			{
				std::lock_guard<std::mutex> lock(g_vehicleMtx);
				g_vehicleTargets.clear();
			}
			g_ActorNameCache.clear();
			continue;
		}

		uworld.m_NetDriver.m_ServerConnection.update_PlayerController();
		uworld.m_NetDriver.m_ServerConnection.m_PlayerController.scatter_AcknowledgedPawn(hs_data);
		uworld.m_NetDriver.m_ServerConnection.m_PlayerController.scatter_PlayerCameraManager(hs_data);
		dma::Scatter_ExecuteRead(hs_data);

		g_uworld.store(std::make_shared<UWorld>(uworld), std::memory_order_release);

		auto my_ptr = uworld.m_NetDriver.m_ServerConnection.m_PlayerController.m_AcknowledgedPawn.ptr;
		AUAECharacter my_player(my_ptr, true);
		my_player.scatter_TeamID(hs_data);
		my_player.scatter_CurrentUsingWeaponSafety(hs_data);
		dma::Scatter_ExecuteRead(hs_data);

		if (my_player.m_CurrentUsingWeaponSafety.ptr) {
			my_player.m_CurrentUsingWeaponSafety.scatter_FName(hs_data);
			my_player.m_CurrentUsingWeaponSafety.scatter_WeaponEntityComp(hs_data);
			my_player.m_CurrentUsingWeaponSafety.scatter_CurBulletNumInClip(hs_data);
			dma::Scatter_ExecuteRead(hs_data);
		}

		auto tarray_start = std::chrono::steady_clock::now();
		time_uworld_init += std::chrono::duration<double, std::milli>(tarray_start - uworld_start).count();

		if (++array_read_counter > 10) {
			actors_TArray = uworld.m_PersistentLevel.get_Actors();
			if (!dma::IsValidPointer(actors_TArray.Data) || actors_TArray.NumElements > 50000 || actors_TArray.NumElements <= 0) {
				if (!physx_cleared) {
					PhysX3::clearPhysx();
					physx_cleared = true;
				}

				if (hs_data) {
					dma::Scatter_CloseHandle(hs_data);
					hs_data = NULL;
				}

				g_playerList.store(std::make_shared<std::vector<AUAECharacter>>(), std::memory_order_release);
				g_item_list.store(std::make_shared<std::vector<AActor>>(), std::memory_order_release);
				g_vehicleList.store(std::make_shared<std::vector<ASTExtraVehicleBase>>(), std::memory_order_release);
				{
					std::lock_guard<std::mutex> lock(g_vehicleMtx);
					g_vehicleTargets.clear();
				}
				{
					std::lock_guard<std::mutex> lock(g_itemMtx);
					g_itemTargets.clear();
				}
				g_ActorNameCache.clear();
				array_read_counter = 0;
				continue;
			}

			if (actors_TArray.NumElements > 0 && actors_TArray.NumElements < 10000) {
				actor_vec = actors_TArray.get_vector();
			}
			else {

				if (hs_data) {
					dma::Scatter_CloseHandle(hs_data);
					hs_data = NULL;
				}
				array_read_counter = 0;
				continue;
			}


			auto name_read_start = std::chrono::steady_clock::now();
			time_tarray_get += std::chrono::duration<double, std::milli>(name_read_start - tarray_start).count();

			for (auto& actor : actor_vec) {
				actor.scatter_FName(hs_data);
			}
			dma::Scatter_ExecuteRead(hs_data);

			auto update_player_start = std::chrono::steady_clock::now();
			time_name_read += std::chrono::duration<double, std::milli>(update_player_start - name_read_start).count();

			std::vector<AUAECharacter> new_player{};
			std::vector<AActor> new_item{};
			std::vector<ASTExtraVehicleBase> new_vehicle{};
			my_player_in_list = false;

			for (auto& actor : actor_vec) {
				auto name = actor.m_FName.ToString();


				if (name.empty() || name == "fail" || name == "None") {
					if (g_ActorNameCache.count(actor.ptr)) {
						std::string cached_name = g_ActorNameCache[actor.ptr];
						EntityType cached_type = actor.get_type(cached_name);
						if (cached_type == EntityType::Player ||
							cached_type == EntityType::Vehicle ||
							cached_type == EntityType::AirDrop ||
							cached_type == EntityType::DeadBox) {
							name = cached_name;
						}
					}
				}
				else {
					g_ActorNameCache[actor.ptr] = name;
				}
				// --------------------

				actor.CachedName = name;
				actor.update_type(name);

				if (actor.m_type == EntityType::Player) {
					auto& p = new_player.emplace_back(actor.ptr, true);
					p.CachedName = actor.CachedName;
					if (actor.ptr == my_ptr) my_player_in_list = true;

				}
				else if (actor.m_type == EntityType::Vehicle) {
					auto& veh = new_vehicle.emplace_back(actor.ptr, true);
					veh.CachedName = actor.CachedName;
				}
				else if (dx11_menu::esp::show_all_classes || actor.m_type == EntityType::Item || actor.m_type == EntityType::AirDrop || actor.m_type == EntityType::DeadBox || actor.m_type == EntityType::Project) {
					new_item.emplace_back(actor);
				}

				if (dx11_menu::esp::metro_monster) {

					if (name.find("BP_PlayerPawn_C") != std::string::npos ||
						name.find("BP_PlayerPawn_CG35_C") != std::string::npos ||
						name.find("BP_PlayerPawn_Chimera") != std::string::npos ||
						name.find("BP_PlaneCharacter_PUBGPlane_CG028") != std::string::npos ||
						name.find("BP_PlayerPawn_Desert_CG35") != std::string::npos ||
						name.find("BP_TrainPlayerPawn_C") != std::string::npos ||
						name.find("BP_PlayerPawn_TDM_TPP_C") != std::string::npos ||
						name.find("BP_PlayerPawn_TDM_C") != std::string::npos ||
						name.find("BP_PlayerPawn_CG015Event_C") != std::string::npos ||
						name.find("_PlayerPawn_SpaceCity_C") != std::string::npos ||
						name.find("_PlayerPawn_C") != std::string::npos ||
						name.find("_TrainPlayerPawn_C") != std::string::npos ||
						name.find("_PlayerPawn_TDM_TPP_C") != std::string::npos ||
						name.find("_PlayerPawn_TDM_C") != std::string::npos ||
						name.find("_PlayerPawn_CG015Event_C") != std::string::npos ||
						name.find("BP_PlayerPawn_TDM_FPP_C") != std::string::npos ||
						name.find("BPPawn_Bomb_C") != std::string::npos ||
						name.find("BPPawn_Zombie_Dog_C") != std::string::npos ||
						name.find("BPPawn_Zombie_M_C") != std::string::npos ||
						name.find("BPPawn_Zombie_F_C") != std::string::npos ||
						name.find("BPPawn_Venom_C") != std::string::npos ||
						name.find("BPPawn_Jump_C") != std::string::npos ||
						name.find("BPPawn_Tyrant_C") != std::string::npos ||
						name.find("BP_PlayerPawn_Happy_MJ_C") != std::string::npos ||
						name.find("BP_PlayerPawn_Happy_GY_C") != std::string::npos ||
						name.find("BP_PlayerPawn_SpaceCity_C") != std::string::npos ||
						name.find("BP_PlayerPawn_CG028_C") != std::string::npos ||
						name.find("BP_PlayerPawn_Escape_C") != std::string::npos ||
						name.find("BPPawn_Escape") != std::string::npos ||
						name.find("BP_PlayerPawn_CG029_C") != std::string::npos ||
						name.find("BPPawn_Tank_C") != std::string::npos) {
						if (!dx11_menu::esp::metro_mode) continue;
						new_player.emplace_back(actor.ptr, true);
					}
				}
			}

			if (!my_player_in_list && my_ptr != 0) {
				auto& p = new_player.emplace_back(my_ptr, true);
				p.CachedName = "Me";
			}

			cached_player_targets = new_player;
			cached_vehicle_targets = new_vehicle;
			cached_item_targets = new_item;

			array_read_counter = 0;
		}

		auto update_player_start = std::chrono::steady_clock::now();

		update_player(hs_data, cached_player_targets);

		auto update_player_end = std::chrono::steady_clock::now();
		time_update_player += std::chrono::duration<double, std::milli>(update_player_end - update_player_start).count();

		{
			std::lock_guard<std::mutex> lock(g_vehicleMtx);
			g_vehicleTargets = cached_vehicle_targets;
		}

		auto update_veh_end = std::chrono::steady_clock::now();
		time_update_vehicle += std::chrono::duration<double, std::milli>(update_veh_end - update_player_end).count();

		{
			std::lock_guard<std::mutex> lock(g_itemMtx);
			g_itemTargets = cached_item_targets;
		}
		auto update_item_end = std::chrono::steady_clock::now();
		time_update_item += std::chrono::duration<double, std::milli>(update_item_end - update_veh_end).count();


		g_my_player.store(std::make_shared<AUAECharacter>(my_player), std::memory_order_release);


		static std::atomic<double> last_async_physx_time{ 0.0 };

		static std::atomic<bool> is_physx_loading{ false };

		auto physx_start = std::chrono::steady_clock::now();

		static int physx_counter = 0;
		if (++physx_counter > 600) {

			bool expected = false;
			if (is_physx_loading.compare_exchange_strong(expected, true)) {
				std::thread([]() {
					auto t_start = std::chrono::steady_clock::now();
					PhysX3::runPhysx("model.bin");
					auto t_end = std::chrono::steady_clock::now();
					last_async_physx_time.store(std::chrono::duration<double, std::milli>(t_end - t_start).count(), std::memory_order_relaxed);

					std::this_thread::sleep_for(std::chrono::milliseconds(500));
					is_physx_loading.store(false, std::memory_order_release);
					}).detach();
				physx_cleared = false;
			}
			physx_counter = 0;
		}
		auto physx_end = std::chrono::steady_clock::now();

		time_physx = last_async_physx_time.load(std::memory_order_relaxed);


		if (hs_data) {

		}


		auto loop_end = std::chrono::steady_clock::now();
		std::chrono::duration<double, std::milli> diff = loop_end - loop_start;
		total_read_time += diff.count();
		loop_counter++;

		auto now = std::chrono::steady_clock::now();
		if (std::chrono::duration_cast<std::chrono::seconds>(now - last_console_update).count() >= 1) {

			if (loop_counter <= 0) loop_counter = 1;

			double avg_read_time = total_read_time / loop_counter;

			size_t player_count = 0;
			size_t item_count = 0;
			size_t vehicle_count = 0;

			auto p_list = g_playerList.load(std::memory_order_relaxed);
			if (p_list) player_count = p_list->size();

			auto i_list = g_item_list.load(std::memory_order_relaxed);
			if (i_list) item_count = i_list->size();

			auto v_list = g_vehicleList.load(std::memory_order_relaxed);
			if (v_list) vehicle_count = v_list->size();

			std::cout << std::format("Fps: {} | T: {:.2f} ms | UWorld: {:.2f} | Array: {:.2f} | Name: {:.2f} | P: {:.2f} | V: {:.2f} | I: {:.2f} | PhysX: {:.2f}",
				loop_counter, avg_read_time,
				time_uworld_init / loop_counter,
				time_tarray_get / loop_counter,
				time_name_read / loop_counter,
				time_update_player / loop_counter,
				time_update_vehicle / loop_counter,
				time_update_item / loop_counter,
				time_physx / loop_counter
			) << std::endl;

			loop_counter = 0;
			total_read_time = 0;
			time_tarray_get = 0;
			time_name_read = 0;
			time_update_player = 0;
			time_update_vehicle = 0;
			time_update_item = 0;
			time_uworld_init = 0;
			time_physx = 0;
			last_console_update = now;
		}
	}


	if (hs_data) {
		dma::Scatter_CloseHandle(hs_data);
	}
}

void draw_item(ImDrawList* draw_list, VMMDLL_SCATTER_HANDLE hs_esp, FCameraCacheEntry& CameraCacheEntry) {
	if (!dx11_menu::esp::item && !dx11_menu::esp::show_all_classes) {
		return;
	}
	auto item_list = g_item_list.load(std::memory_order_acquire);
	if (!item_list) {
		return;
	}

	struct DrawableItem {
		FVector2D pos;
		std::string name;
	};
	std::vector<DrawableItem> drawables;

	for (auto& item : *item_list) {

		auto item_pos = item.m_RootComponent.m_ComponentToWorld.Translation;
		FVector2D item_pos_2d{};
		auto ret = m_Engine.WorldToScreen1(item_pos, CameraCacheEntry, item_pos_2d);

		if (!ret) {
			continue;
		}

		if (item_pos_2d.X < 0 || item_pos_2d.Y < 0) {
			continue;
		}

		if (item_pos_2d.X > m_Engine.m_rect.w || item_pos_2d.Y > m_Engine.m_rect.h) {
			continue;
		}

		std::string item_name_str;
		if (!item.CachedName.empty()) {
			item_name_str = item.CachedName;
		}
		else {
			// fallback: 如果缓存为空，尝试现场读取（可能会卡顿，但总比不显示好）
			item_name_str = item.m_FName.ToString();
		}

		// 过滤
		if (!dx11_menu::esp::item_filter_map.empty()) {
			if (dx11_menu::esp::item_filter_map.find(item_name_str) != dx11_menu::esp::item_filter_map.end()) {
				if (!dx11_menu::esp::item_filter_map[item_name_str]) continue;
			}
		}

		auto cn_name = GetItemName(item_name_str);

		// 分类过滤
		if (cn_name.find("空投") != std::string::npos && !dx11_menu::esp::item_airdrop) continue;
		if ((cn_name.find("手雷") != std::string::npos || cn_name.find("燃烧瓶") != std::string::npos) && !dx11_menu::esp::item_grenade) continue;
		if ((cn_name.find("急救包") != std::string::npos || cn_name.find("止痛药") != std::string::npos || cn_name.find("能量饮料") != std::string::npos || cn_name.find("绷带") != std::string::npos || cn_name.find("医疗箱") != std::string::npos || cn_name.find("肾上腺素") != std::string::npos) && !dx11_menu::esp::item_meds) continue;

		if (!cn_name.empty()) {
			item_name_str = cn_name;
		}

		drawables.push_back({ item_pos_2d, item_name_str });
	}

	// 叠加处理
	if (dx11_menu::esp::item_collapse) {
		for (size_t i = 0; i < drawables.size(); ++i) {
			for (size_t j = 0; j < i; ++j) {
				float dx = abs(drawables[i].pos.X - drawables[j].pos.X);
				float dy = abs(drawables[i].pos.Y - drawables[j].pos.Y);
				if (dx < 20.0f && dy < dx11_menu::esp::item_size) { // 简单判断重叠
					drawables[i].pos.Y += dx11_menu::esp::item_size; // 下移
				}
			}
		}
	}

	for (auto& d : drawables) {
		render::AddText(draw_list, { d.pos.X, d.pos.Y }, imguiColor::Green, d.name.c_str(), dx11_menu::esp::item_size);
	}

}

void draw_player_box(ImDrawList* draw_list, FCameraCacheEntry& CameraCacheEntry, AUAECharacter& player) {

	bool is_groggy = (player.m_HealthStatus == 2);

	if (!is_groggy && !player.m_PawnStateRepSyncData_Data.empty()) {
		for (size_t i = 0; i < player.m_PawnStateRepSyncData_Data.size(); ++i) {
			unsigned char byte = player.m_PawnStateRepSyncData_Data[i];
			if (byte == 0) continue;
			for (int bit = 0; bit < 8; ++bit) {
				if ((byte >> bit) & 1) {
					int idx = i * 8 + bit;
					if (idx == 16) {
						is_groggy = true;
						break;
					}
				}
			}
			if (is_groggy) break;
		}
	}

	ImU32 box_color = is_groggy ? imguiColor::SolidGray : ImGui::ColorConvertFloat4ToU32(ImVec4(dx11_menu::esp::color_box[0], dx11_menu::esp::color_box[1], dx11_menu::esp::color_box[2], dx11_menu::esp::color_box[3]));

	if (dx11_menu::esp::player_box) {
		auto box = player.m_Mesh.m_CachedLocalBounds.GetBoxCorners(player.m_Mesh.m_ComponentToWorld);
		if (player.m_Mesh.m_CachedLocalBounds.BoxExtent.Z < 10.0f) {
			FBoxSphereBounds root_bounds;
			root_bounds.Origin = { 0.0f, 0.0f, 0.0f };
			root_bounds.BoxExtent = { 40.0f, 40.0f, 100.0f };
			FTransform root_transform;
			root_transform.Translation = player.m_RootComponent.m_ComponentToWorld.Translation;
			root_transform.Rotation = { 0.0f, 0.0f, 0.0f, 1.0f };
			root_transform.Scale3D = { 1.0f, 1.0f, 1.0f };
			box = root_bounds.GetBoxCorners(root_transform);
		}

		FVector2D box_out[8]{};
		bool ret[8]{};
		for (int i = 0; i < 8; i++) {
			ret[i] = m_Engine.WorldToScreen1(box[i], CameraCacheEntry, box_out[i]);
			if (!ret[i]) {
				continue;
			}

			if (box_out[i].X < 0 || box_out[i].Y < 0) {
				ret[i] = false;
				continue;
			}

			if (box_out[i].X > m_Engine.m_rect.w || box_out[i].Y > m_Engine.m_rect.h) {
				ret[i] = false;
				continue;
			}

		}

		if (ret[0] && ret[1] && ret[2] && ret[3]) {

			draw_list->AddQuad(
				ImVec2{ box_out[0].X, box_out[0].Y }, ImVec2{ box_out[1].X, box_out[1].Y },
				ImVec2{ box_out[2].X, box_out[2].Y }, ImVec2{ box_out[3].X, box_out[3].Y },
				box_color, dx11_menu::esp::width_box
			);
		}


		if (ret[4] && ret[5] && ret[6] && ret[7]) {
			draw_list->AddQuad(
				ImVec2{ box_out[4].X, box_out[4].Y }, ImVec2{ box_out[5].X, box_out[5].Y },
				ImVec2{ box_out[6].X, box_out[6].Y }, ImVec2{ box_out[7].X, box_out[7].Y },
				box_color, dx11_menu::esp::width_box
			);
		}

		if (ret[0] && ret[4]) {
			draw_list->AddLine(ImVec2{ box_out[0].X , box_out[0].Y }, ImVec2{ box_out[4].X , box_out[4].Y }, box_color, dx11_menu::esp::width_box);
		}
		if (ret[1] && ret[5]) {
			draw_list->AddLine(ImVec2{ box_out[1].X , box_out[1].Y }, ImVec2{ box_out[5].X , box_out[5].Y }, box_color, dx11_menu::esp::width_box);
		}
		if (ret[2] && ret[6]) {
			draw_list->AddLine(ImVec2{ box_out[2].X , box_out[2].Y }, ImVec2{ box_out[6].X , box_out[6].Y }, box_color, dx11_menu::esp::width_box);
		}
		if (ret[3] && ret[7]) {
			draw_list->AddLine(ImVec2{ box_out[3].X , box_out[3].Y }, ImVec2{ box_out[7].X , box_out[7].Y }, box_color, dx11_menu::esp::width_box);
		}


		if (is_groggy && dx11_menu::esp::player_groggy) {
			float min_x = 99999.0f;
			float min_y = 99999.0f;
			float max_y = -99999.0f;
			bool has_valid_points = false;

			for (int i = 0; i < 8; i++) {
				if (ret[i]) {
					if (box_out[i].X < min_x) min_x = box_out[i].X;
					if (box_out[i].Y < min_y) min_y = box_out[i].Y;
					if (box_out[i].Y > max_y) max_y = box_out[i].Y;
					has_valid_points = true;
				}
			}

			if (has_valid_points) {
				const char* text = reinterpret_cast<const char*>(u8"倒地");
				ImVec2 textSize = ImGui::CalcTextSize(text);

				float center_y = (min_y + max_y) / 2.0f;
				ImVec2 pos = { min_x - textSize.x - 2.0f, center_y - textSize.y / 2.0f };
				render::AddText(draw_list, pos, imguiColor::Purple, text);
			}
		}
	}


	if (dx11_menu::esp::player_permission) {
		float min_x = 99999.0f;
		float min_y = 99999.0f;
		float max_y = -99999.0f;
		bool has_valid_points = false;


		auto box = player.m_Mesh.m_CachedLocalBounds.GetBoxCorners(player.m_Mesh.m_ComponentToWorld);

		if (player.m_Mesh.m_CachedLocalBounds.BoxExtent.Z < 10.0f) {
			FBoxSphereBounds root_bounds;
			root_bounds.Origin = { 0.0f, 0.0f, 0.0f };
			root_bounds.BoxExtent = { 40.0f, 40.0f, 100.0f };
			FTransform root_transform;
			root_transform.Translation = player.m_RootComponent.m_ComponentToWorld.Translation;
			root_transform.Rotation = { 0.0f, 0.0f, 0.0f, 1.0f };
			root_transform.Scale3D = { 1.0f, 1.0f, 1.0f };
			box = root_bounds.GetBoxCorners(root_transform);
		}

		FVector2D box_out_perm[8]{};
		bool ret_perm[8]{};

		for (int i = 0; i < 8; i++) {
			ret_perm[i] = m_Engine.WorldToScreen1(box[i], CameraCacheEntry, box_out_perm[i]);
			if (ret_perm[i]) {
				if (box_out_perm[i].X < 0 || box_out_perm[i].Y < 0 ||
					box_out_perm[i].X > m_Engine.m_rect.w || box_out_perm[i].Y > m_Engine.m_rect.h) {
					// 屏幕外
				}
				else {
					if (box_out_perm[i].X < min_x) min_x = box_out_perm[i].X;
					if (box_out_perm[i].Y < min_y) min_y = box_out_perm[i].Y;
					if (box_out_perm[i].Y > max_y) max_y = box_out_perm[i].Y;
					has_valid_points = true;
				}
			}
		}

		if (has_valid_points) {
			const char* text = reinterpret_cast<const char*>(u8"非权限狗");
			ImVec2 textSize = ImGui::CalcTextSize(text);

			float center_y = (min_y + max_y) / 2.0f;
			ImVec2 pos = { min_x - textSize.x - 2.0f, center_y - textSize.y / 2.0f };
			render::AddText(draw_list, pos, imguiColor::Red, text);
		}
	}



}

void draw_player_info(ImDrawList* draw_list, FCameraCacheEntry& CameraCacheEntry, AUAECharacter& player) {
	auto top_center = player.m_Mesh.m_CachedLocalBounds.GetTopCenter(player.m_Mesh.m_ComponentToWorld);
	auto bottom_center = player.m_Mesh.m_CachedLocalBounds.GetBottomCenter(player.m_Mesh.m_ComponentToWorld);


	if (player.m_Mesh.m_CachedLocalBounds.BoxExtent.Z < 10.0f) {
		top_center = player.m_RootComponent.m_ComponentToWorld.Translation;
		top_center.Z += 100.0f;
		bottom_center = player.m_RootComponent.m_ComponentToWorld.Translation;
		bottom_center.Z -= 100.0f;
	}

	FVector2D top_center_out{}, bottom_center_out{};
	bool ret1 = m_Engine.WorldToScreen1(top_center, CameraCacheEntry, top_center_out);
	bool ret2 = m_Engine.WorldToScreen1(bottom_center, CameraCacheEntry, bottom_center_out);

	if (!ret1 || !ret2) {
		return;
	};

	if (dx11_menu::esp::player_line) {
		ImVec2 line_origin;
		if (dx11_menu::esp::line_pos == 0) line_origin = { m_Engine.m_rect_center.X, 0 };
		else if (dx11_menu::esp::line_pos == 1) line_origin = { m_Engine.m_rect_center.X, m_Engine.m_rect_center.Y };
		else line_origin = { m_Engine.m_rect_center.X, (float)m_Engine.m_rect.h };

		draw_list->AddLine(line_origin, { top_center_out.X , top_center_out.Y }, ImGui::ColorConvertFloat4ToU32(ImVec4(dx11_menu::esp::color_line[0], dx11_menu::esp::color_line[1], dx11_menu::esp::color_line[2], dx11_menu::esp::color_line[3])), dx11_menu::esp::width_line);
	}

	if (top_center_out.X < 0 || top_center_out.Y < 0 || bottom_center_out.X < 0 || bottom_center_out.Y < 0) {
		return;
	}

	if (top_center_out.X > m_Engine.m_rect.w || top_center_out.Y > m_Engine.m_rect.h) {
		return;
	}


	auto pos_top = ImVec2{ top_center_out.X , top_center_out.Y };


	auto pos_bottom = ImVec2{ bottom_center_out.X , bottom_center_out.Y };




	if (dx11_menu::esp::player_health) {
		auto hp_height = 4;
		auto hp_width = 40;
		pos_top.y -= (hp_height + 2);
		render::DrawHealthBar(draw_list, pos_top, hp_width, hp_height, player.m_Health, player.m_HealthMax, dx11_menu::esp::player_health_style);


		if (dx11_menu::esp::player_team) {
			auto team_id_str = std::to_string(player.m_TeamID);
			auto team_id_char = team_id_str.c_str();


			float padding = 6.0f;

			ImVec2 text_size = ImGui::GetFont()->CalcTextSizeA(dx11_menu::esp::size_team_id, FLT_MAX, 0.0f, team_id_char);

			ImVec2 text_pos = {
				pos_top.x - (hp_width / 2) - padding - text_size.x,
				pos_top.y + (hp_height / 2) - (text_size.y / 2)
			};

			render::AddText(draw_list, text_pos, ImGui::ColorConvertFloat4ToU32(ImVec4(dx11_menu::esp::color_team_id[0], dx11_menu::esp::color_team_id[1], dx11_menu::esp::color_team_id[2], dx11_menu::esp::color_team_id[3])), team_id_char, dx11_menu::esp::size_team_id);
		}

		if (dx11_menu::esp::player_energy || dx11_menu::esp::player_kills) {
			float right_x = pos_top.x + (hp_width / 2) + 6.0f;
			float start_y = pos_top.y;

			float total_h = 0;
			if (dx11_menu::esp::player_energy) total_h += 12.0f;
			if (dx11_menu::esp::player_kills) total_h += 12.0f;

			float cur_y = start_y - (total_h / 2.0f);

			if (dx11_menu::esp::player_energy) {
				std::string str = "";
				ImU32 color = ImGui::ColorConvertFloat4ToU32(ImVec4(dx11_menu::esp::color_energy[0], dx11_menu::esp::color_energy[1], dx11_menu::esp::color_energy[2], dx11_menu::esp::color_energy[3]));


				if (player.m_SignalHP > 0) {
					str = std::string(reinterpret_cast<const char*>(u8"能量:")) + std::format("{:.0f}", player.m_SignalHP);
					color = IM_COL32(0, 255, 255, 255);
				}

				else {
					float show_energy = player.m_Energy;
					if (player.m_EnergyBuff > show_energy) show_energy = player.m_EnergyBuff;

					if (show_energy > 0) {
						str = std::string(reinterpret_cast<const char*>(u8"能量:")) + std::format("{:.0f}", show_energy);
					}
				}

				if (!str.empty()) {

					draw_list->AddText(NULL, dx11_menu::esp::size_energy, ImVec2(right_x + 1, cur_y + 1), IM_COL32(0, 0, 0, 255), str.c_str());
					draw_list->AddText(NULL, dx11_menu::esp::size_energy, ImVec2(right_x, cur_y), color, str.c_str());
					cur_y += 12.0f;
				}
			}
			if (dx11_menu::esp::player_kills) {
				std::string str = std::string(reinterpret_cast<const char*>(u8"击杀:")) + std::to_string(player.m_Kills);
				draw_list->AddText(NULL, dx11_menu::esp::size_kills, ImVec2(right_x + 1, cur_y + 1), IM_COL32(0, 0, 0, 255), str.c_str());
				draw_list->AddText(NULL, dx11_menu::esp::size_kills, ImVec2(right_x, cur_y), ImGui::ColorConvertFloat4ToU32(ImVec4(dx11_menu::esp::color_kills[0], dx11_menu::esp::color_kills[1], dx11_menu::esp::color_kills[2], dx11_menu::esp::color_kills[3])), str.c_str());
			}
		}

		pos_top.y -= 2;
	}

	if (dx11_menu::esp::player_name) {
		std::string player_name_str;

		if (player.m_bIsAI) {
			player_name_str = reinterpret_cast<const char*>(u8"[AI]人机");
		}
		else {
			player_name_str = bm::bm_wstrTostr_utf8(player.m_PlayerName);
		}



		auto player_name = player_name_str.c_str();

		float font_size = dx11_menu::esp::size_name;


		ImVec2 textSize = ImGui::GetFont()->CalcTextSizeA(dx11_menu::esp::size_name, FLT_MAX, 0.0f, player_name);
		pos_top.y -= textSize.y;

		render::AddText(draw_list, pos_top, ImGui::ColorConvertFloat4ToU32(ImVec4(dx11_menu::esp::color_name[0], dx11_menu::esp::color_name[1], dx11_menu::esp::color_name[2], dx11_menu::esp::color_name[3])), player_name, font_size);
	}


	if (dx11_menu::esp::player_weapon) {
		auto player_weapon_name_str = player.m_CurrentUsingWeaponSafety.m_FName.ToString();

		if (player_weapon_name_str.find("None") == player_weapon_name_str.npos) {

			std::string display_str = player_weapon_name_str;
			std::string translatedName = GetWeaponName(player_weapon_name_str);
			if (!translatedName.empty()) {
				display_str = translatedName;
			}


			bool is_melee_or_throwable = false;
			if (!translatedName.empty()) {
				if (translatedName.find(reinterpret_cast<const char*>(u8"砍刀")) != std::string::npos ||
					translatedName.find(reinterpret_cast<const char*>(u8"平底锅")) != std::string::npos ||
					translatedName.find(reinterpret_cast<const char*>(u8"撬棍")) != std::string::npos ||
					translatedName.find(reinterpret_cast<const char*>(u8"镰刀")) != std::string::npos ||
					translatedName.find(reinterpret_cast<const char*>(u8"手雷")) != std::string::npos ||
					translatedName.find(reinterpret_cast<const char*>(u8"烟雾")) != std::string::npos ||
					translatedName.find(reinterpret_cast<const char*>(u8"燃烧")) != std::string::npos ||
					translatedName.find(reinterpret_cast<const char*>(u8"闪光")) != std::string::npos ||
					translatedName.find(reinterpret_cast<const char*>(u8"铝热")) != std::string::npos ||
					translatedName.find(reinterpret_cast<const char*>(u8"电磁")) != std::string::npos ||
					translatedName.find(reinterpret_cast<const char*>(u8"拳头")) != std::string::npos) {
					is_melee_or_throwable = true;
				}
			}

			if (!is_melee_or_throwable) {

				auto bullet_str = std::format(" {}/{}", player.m_CurrentUsingWeaponSafety.m_CurBulletNumInClip, player.m_CurrentUsingWeaponSafety.m_CurMaxBulletNumInOneClip);
				display_str += bullet_str;
			}


			ImVec2 textSize = ImGui::GetFont()->CalcTextSizeA(dx11_menu::esp::size_weapon, FLT_MAX, 0.0f, display_str.c_str());
			pos_top.y -= textSize.y;

			render::AddText(draw_list, pos_top, ImGui::ColorConvertFloat4ToU32(ImVec4(dx11_menu::esp::color_weapon[0], dx11_menu::esp::color_weapon[1], dx11_menu::esp::color_weapon[2], dx11_menu::esp::color_weapon[3])), display_str.c_str(), dx11_menu::esp::size_weapon);
		}
	}




	if (dx11_menu::esp::player_dis) {
		auto player_dis = (int)CameraCacheEntry.POV.Location.GetDistanceToInMeters(player.m_Mesh.m_ComponentToWorld.Translation);
		auto player_dis_str = std::format("[{}M]", player_dis);
		auto player_dis_char = player_dis_str.c_str();

		ImVec2 textSize = ImGui::GetFont()->CalcTextSizeA(dx11_menu::esp::size_distance, FLT_MAX, 0.0f, player_dis_char);
		pos_bottom.y += 2;
		render::AddText(draw_list, pos_bottom, ImGui::ColorConvertFloat4ToU32(ImVec4(dx11_menu::esp::color_distance[0], dx11_menu::esp::color_distance[1], dx11_menu::esp::color_distance[2], dx11_menu::esp::color_distance[3])), player_dis_char, dx11_menu::esp::size_distance);
		pos_bottom.y += textSize.y;
	}

	if (dx11_menu::esp::player_action) {
		std::string action_str = "";


		bool is_groggy = (player.m_HealthStatus == 2);


		if (!is_groggy && !player.m_PawnStateRepSyncData_Data.empty()) {
			for (size_t i = 0; i < player.m_PawnStateRepSyncData_Data.size(); ++i) {
				unsigned char byte = player.m_PawnStateRepSyncData_Data[i];
				if (byte == 0) continue;
				for (int bit = 0; bit < 8; ++bit) {
					if ((byte >> bit) & 1) {
						int idx = i * 8 + bit;
						if (idx == 16) {
							is_groggy = true;
							break;
						}
					}
				}
				if (is_groggy) break;
			}
		}

		if (is_groggy) {
			if (dx11_menu::esp::player_groggy) {
				action_str = reinterpret_cast<const char*>(u8"倒地");
			}
		}
		else {
			bool has_state = false;


			if (!player.m_PawnStateRepSyncData_Data.empty()) {
				std::vector<int> active_indices;
				for (size_t i = 0; i < player.m_PawnStateRepSyncData_Data.size(); ++i) {
					unsigned char byte = player.m_PawnStateRepSyncData_Data[i];
					if (byte == 0) continue;
					for (int bit = 0; bit < 8; ++bit) {
						if ((byte >> bit) & 1) {
							active_indices.push_back(i * 8 + bit);
						}
					}
				}

				if (!active_indices.empty()) {

					std::string pose_str = "";
					std::string action_str_sub = "";
					bool is_firing = false;

					for (int idx : active_indices) {

						if (idx == 0 || idx == 1 || idx == 2) pose_str = reinterpret_cast<const char*>(u8"跑");
						else if (idx == 3) pose_str = reinterpret_cast<const char*>(u8"爬行");
						else if (idx == 11) pose_str = reinterpret_cast<const char*>(u8"走");
						else if (idx == 4) { if (pose_str.empty()) pose_str = reinterpret_cast<const char*>(u8"站"); }
						else if (idx == 5) pose_str = reinterpret_cast<const char*>(u8"蹲");
						else if (idx == 6) pose_str = reinterpret_cast<const char*>(u8"趴");
						else if (idx == 7) pose_str = reinterpret_cast<const char*>(u8"跳");
						else if (idx == 21) pose_str = reinterpret_cast<const char*>(u8"驾驶");
						else if (idx == 25) pose_str = reinterpret_cast<const char*>(u8"跳伞");
						else if (idx == 18) pose_str = reinterpret_cast<const char*>(u8"救援");


						else if (idx == 9) action_str_sub = reinterpret_cast<const char*>(u8"换弹");
						else if (idx == 12) action_str_sub = reinterpret_cast<const char*>(u8"探头");
						else if (idx == 13) action_str_sub = reinterpret_cast<const char*>(u8"切枪");
						else if (idx == 15) action_str_sub = reinterpret_cast<const char*>(u8"挥拳");
						else if (idx == 16) {

							if (!is_groggy) {
								action_str_sub = reinterpret_cast<const char*>(u8"倒地");
							}
						}


						if (idx == 8 || idx == 10) is_firing = true;
					}


					if (pose_str.empty() && !active_indices.empty()) pose_str = std::to_string(active_indices[0]);

					action_str += pose_str;

					if (!action_str_sub.empty()) {
						action_str += "/" + action_str_sub;
					}

					if (is_firing) {
						action_str += reinterpret_cast<const char*>(u8"-开火");
					}

					has_state = true;
				}
			}


			if (!has_state) {
				action_str += "0";
			}

			if (!player.m_PawnStatesExtend.empty()) {
				action_str += " " + bm::bm_wstrTostr_utf8(player.m_PawnStatesExtend);
			}

		}

		ImVec2 textSize = ImGui::GetFont()->CalcTextSizeA(dx11_menu::esp::size_action, FLT_MAX, 0.0f, action_str.c_str());
		pos_bottom.y += 2;
		render::AddText(draw_list, pos_bottom, ImGui::ColorConvertFloat4ToU32(ImVec4(dx11_menu::esp::color_action[0], dx11_menu::esp::color_action[1], dx11_menu::esp::color_action[2], dx11_menu::esp::color_action[3])), action_str.c_str(), dx11_menu::esp::size_action);
		pos_bottom.y += textSize.y;
	}

}

void draw_player_bone(ImDrawList* draw_list, FCameraCacheEntry& CameraCacheEntry, AUAECharacter& player) {


	// 定义骨骼连接关系
	static std::vector<std::pair<std::string, std::string>> connections = {
		// 脊柱连接
		{"pelvis", "spine_01"},{"spine_01", "spine_02"},{"spine_02", "spine_03"},{"spine_03", "neck_01"},{"neck_01", "head"},

		// 左臂连接
		{"spine_03", "clavicle_l"},{"clavicle_l", "upperarm_l"},{"upperarm_l", "lowerarm_l"},{"lowerarm_l", "hand_l"},

		// 右臂连接
		{"spine_03", "clavicle_r"},{"clavicle_r", "upperarm_r"},{"upperarm_r", "lowerarm_r"},{"lowerarm_r", "hand_r"},

		// 左腿连接
		{"pelvis", "thigh_l"},{"thigh_l", "calf_l"},{"calf_l", "foot_l"},

		// 右腿连接
		{"pelvis", "thigh_r"},{"thigh_r", "calf_r"},{"calf_r", "foot_r"},

	};


	if (!player.m_Mesh.m_boneVector.size()) {
		return;
	}

	for (const auto& relation : connections) {
		auto it1 = player.m_Mesh.m_SkeletalMesh.m_bone_info_map.find(relation.first);
		if (it1 == player.m_Mesh.m_SkeletalMesh.m_bone_info_map.end()) continue;
		auto it2 = player.m_Mesh.m_SkeletalMesh.m_bone_info_map.find(relation.second);
		if (it2 == player.m_Mesh.m_SkeletalMesh.m_bone_info_map.end()) continue;


		if (it1->second >= player.m_Mesh.m_boneVector.size()) {
			continue;
		}
		if (it2->second >= player.m_Mesh.m_boneVector.size()) {
			continue;
		}


		auto& bone_FT1 = player.m_Mesh.m_boneVector[it1->second];
		auto& bone_FT2 = player.m_Mesh.m_boneVector[it2->second];

		auto bone_pos1 = m_Engine.GetBoneWorldPos(bone_FT1, player.m_Mesh.m_ComponentToWorld);
		auto bone_pos2 = m_Engine.GetBoneWorldPos(bone_FT2, player.m_Mesh.m_ComponentToWorld);


		FVector2D bone_pos_out1, bone_pos_out2;

		auto ret1 = m_Engine.WorldToScreen1(bone_pos1, CameraCacheEntry, bone_pos_out1);
		auto ret2 = m_Engine.WorldToScreen1(bone_pos2, CameraCacheEntry, bone_pos_out2);
		if (!ret1 || !ret2) continue;

		if (bone_pos_out1.X < 0 || bone_pos_out1.Y < 0 || bone_pos_out2.X < 0 && bone_pos_out2.Y < 0) {
			continue;
		}

		if (bone_pos_out1.X > m_Engine.m_rect.w || bone_pos_out1.Y > m_Engine.m_rect.h || bone_pos_out2.X > m_Engine.m_rect.w || bone_pos_out2.Y > m_Engine.m_rect.h) {
			continue;
		}
		bool is_groggy = (player.m_HealthStatus == 2);
		if (!is_groggy && !player.m_PawnStateRepSyncData_Data.empty()) {
			for (size_t i = 0; i < player.m_PawnStateRepSyncData_Data.size(); ++i) {
				unsigned char byte = player.m_PawnStateRepSyncData_Data[i];
				if (byte == 0) continue;
				for (int bit = 0; bit < 8; ++bit) {
					if ((byte >> bit) & 1) {
						int idx = i * 8 + bit;
						if (idx == 16) {
							is_groggy = true;
							break;
						}
					}
				}
				if (is_groggy) break;
			}
		}

		if (dx11_menu::esp::player_bone) {
			ImU32 color = ImGui::ColorConvertFloat4ToU32(ImVec4(dx11_menu::esp::color_bone_invis[0], dx11_menu::esp::color_bone_invis[1], dx11_menu::esp::color_bone_invis[2], dx11_menu::esp::color_bone_invis[3]));

			if (is_groggy) {
				color = imguiColor::SolidGray;
			}
			else if (dx11_menu::esp::player_vis_check) {
				auto hit1 = physxEngine::LineTraceSingle(CameraCacheEntry.POV.Location, bone_pos1);
				auto hit2 = physxEngine::LineTraceSingle(CameraCacheEntry.POV.Location, bone_pos2);

				bool v1 = !hit1.hasAnyHits();
				bool v2 = !hit2.hasAnyHits();

				if (v1 && v2) {
					color = ImGui::ColorConvertFloat4ToU32(ImVec4(dx11_menu::esp::color_bone_vis[0], dx11_menu::esp::color_bone_vis[1], dx11_menu::esp::color_bone_vis[2], dx11_menu::esp::color_bone_vis[3]));
				}
				else if (v1 || v2) {

					color = ImGui::ColorConvertFloat4ToU32(ImVec4(dx11_menu::esp::color_bone_vis[0], dx11_menu::esp::color_bone_vis[1], dx11_menu::esp::color_bone_vis[2], dx11_menu::esp::color_bone_vis[3]));
				}
			}
			else {

				color = ImGui::ColorConvertFloat4ToU32(ImVec4(dx11_menu::esp::color_bone_vis[0], dx11_menu::esp::color_bone_vis[1], dx11_menu::esp::color_bone_vis[2], dx11_menu::esp::color_bone_vis[3]));
			}

			draw_list->AddLine(ImVec2(bone_pos_out1.X, bone_pos_out1.Y), ImVec2(bone_pos_out2.X, bone_pos_out2.Y), color, dx11_menu::esp::width_bone);
		}


		if (dx11_menu::esp::player_bone_id) {
			char buf[8];
			sprintf_s(buf, "%d", it1->second);
			draw_list->AddText(ImVec2(bone_pos_out1.X, bone_pos_out1.Y), IM_COL32(255, 255, 0, 255), buf);
		}
	}
	if (dx11_menu::esp::player_bone && dx11_menu::esp::player_bone_style == 1) {
		auto it_head = player.m_Mesh.m_SkeletalMesh.m_bone_info_map.find("head");
		if (it_head != player.m_Mesh.m_SkeletalMesh.m_bone_info_map.end() && it_head->second < player.m_Mesh.m_boneVector.size()) {
			auto& bone_head = player.m_Mesh.m_boneVector[it_head->second];
			auto head_pos = m_Engine.GetBoneWorldPos(bone_head, player.m_Mesh.m_ComponentToWorld);
			FVector2D head_screen;

			if (m_Engine.WorldToScreen1(head_pos, CameraCacheEntry, head_screen)) {
				// 倒地判断
				bool is_groggy = (player.m_HealthStatus == 2);
				if (!is_groggy && !player.m_PawnStateRepSyncData_Data.empty()) {
					for (size_t i = 0; i < player.m_PawnStateRepSyncData_Data.size(); ++i) {
						unsigned char byte = player.m_PawnStateRepSyncData_Data[i];
						if (byte == 0) continue;
						for (int bit = 0; bit < 8; ++bit) {
							if ((byte >> bit) & 1) {
								int idx = i * 8 + bit;
								if (idx == 16) {
									is_groggy = true;
									break;
								}
							}
						}
						if (is_groggy) break;
					}
				}

				// 颜色选择
				ImU32 color = ImGui::ColorConvertFloat4ToU32(ImVec4(dx11_menu::esp::color_bone_invis[0], dx11_menu::esp::color_bone_invis[1], dx11_menu::esp::color_bone_invis[2], dx11_menu::esp::color_bone_invis[3]));

				if (is_groggy) {
					color = imguiColor::SolidGray;
				}
				else if (dx11_menu::esp::player_vis_check) {
					auto hit = physxEngine::LineTraceSingle(CameraCacheEntry.POV.Location, head_pos);
					if (!hit.hasAnyHits()) {
						color = ImGui::ColorConvertFloat4ToU32(ImVec4(dx11_menu::esp::color_bone_vis[0], dx11_menu::esp::color_bone_vis[1], dx11_menu::esp::color_bone_vis[2], dx11_menu::esp::color_bone_vis[3]));
					}
				}
				else {
					color = ImGui::ColorConvertFloat4ToU32(ImVec4(dx11_menu::esp::color_bone_vis[0], dx11_menu::esp::color_bone_vis[1], dx11_menu::esp::color_bone_vis[2], dx11_menu::esp::color_bone_vis[3]));
				}

				// 计算半径
				float dist = CameraCacheEntry.POV.Location.GetDistanceToInMeters(head_pos);
				float radius = 200.0f / (dist + 0.1f);
				if (radius < 3.0f) radius = 3.0f;
				if (radius > 30.0f) radius = 30.0f;

				draw_list->AddCircle(ImVec2(head_screen.X, head_screen.Y), radius, color, 0, dx11_menu::esp::width_bone);
			}
		}
	}



}

void update_dma_data_internal(VMMDLL_SCATTER_HANDLE hs_esp, std::vector<AUAECharacter>& list_to_update) {
	if (list_to_update.empty()) return;

		for (auto& player : list_to_update) {
		player.m_Mesh.scatter_ComponentToWorld(hs_esp);
		player.m_Mesh.scatter_CachedLocalBounds(hs_esp);
		player.m_Mesh.m_SkeletalMesh.scatter_ExtendedBounds(hs_esp);
		player.m_RootComponent.scatter_ComponentToWorld(hs_esp);
		player.m_Mesh.scatter_boneNow(hs_esp);
	}
	dma::Scatter_ExecuteRead(hs_esp);

	for (auto& player : list_to_update) {
		player.m_Mesh.scatter_boneTArray(hs_esp);
	}
	dma::Scatter_ExecuteRead(hs_esp);

	for (auto& player : list_to_update) {
		player.m_Mesh.scatter_boneVector(hs_esp);
	}
	dma::Scatter_ExecuteRead(hs_esp);
}

void draw_player(ImDrawList* draw_list, FCameraCacheEntry& CameraCacheEntry) {
	auto my_player = g_my_player.load(std::memory_order_acquire);
	auto player_list = g_playerList.load(std::memory_order_acquire);

	if (!my_player || !player_list) {
		return;
	}

	int nearby_players = 0;
	int nearby_ai = 0;
	int behind_enemies = 0;
		std::vector<AimWarningInfoData> aiming_enemies;
	aiming_enemies.reserve(10);

	FVector3D my_loc = CameraCacheEntry.POV.Location;

	FVector3D forward_point = CameraCacheEntry.GetCameraForwardLocation(100.0f);
	FVector3D forward = { forward_point.X - my_loc.X, forward_point.Y - my_loc.Y, forward_point.Z - my_loc.Z };
	float forward_len = std::sqrt(forward.X * forward.X + forward.Y * forward.Y + forward.Z * forward.Z);
	if (forward_len > 0.001f) {
		forward.X /= forward_len; forward.Y /= forward_len; forward.Z /= forward_len;
	}

	std::vector<AUAECharacter> local_list;
	{
		std::lock_guard<std::mutex> lock(g_DataMutex);
		if (g_RenderList.empty()) {
			return;
		}
		local_list = g_RenderList;
	}

	for (auto& player : local_list) {

		if (player.ptr == my_player->ptr) {
			if (dx11_menu::esp::player_ignore_me) continue;
		}
		else if (player.m_TeamID == my_player->m_TeamID) {
			if (dx11_menu::esp::player_ignore_team) continue;
		}

		bool is_enemy = (player.ptr != my_player->ptr && player.m_TeamID != my_player->m_TeamID);
		FVector3D enemy_loc = player.m_Mesh.m_ComponentToWorld.Translation;
		FVector3D to_enemy = { enemy_loc.X - my_loc.X, enemy_loc.Y - my_loc.Y, enemy_loc.Z - my_loc.Z };

		float dot = to_enemy.X * forward.X + to_enemy.Y * forward.Y + to_enemy.Z * forward.Z;
		bool is_behind = (dot < 0);

		if (is_enemy) {
			if (player.m_bIsAI) nearby_ai++;
			else nearby_players++;

			if (is_behind) behind_enemies++;

			if (dx11_menu::esp::player_aim_warning) {
				float to_me_len_sq = to_enemy.X * to_enemy.X + to_enemy.Y * to_enemy.Y + to_enemy.Z * to_enemy.Z;

				if (to_me_len_sq < 2500000000.0f) {
					FMatrix mesh_matrix = FMatrix::ToMatrixWithScale(player.m_Mesh.m_ComponentToWorld);
					FVector3D enemy_forward = { mesh_matrix.M[0][0], mesh_matrix.M[0][1], mesh_matrix.M[0][2] };

					FVector3D to_me = { -to_enemy.X, -to_enemy.Y, -to_enemy.Z };
					float to_me_len = std::sqrt(to_me_len_sq);
					float enemy_fwd_len = std::sqrt(enemy_forward.X * enemy_forward.X + enemy_forward.Y * enemy_forward.Y + enemy_forward.Z * enemy_forward.Z);

					if (to_me_len > 0.0f && enemy_fwd_len > 0.0f) {
						float aim_dot = (to_me.X * enemy_forward.X + to_me.Y * enemy_forward.Y + to_me.Z * enemy_forward.Z) / (to_me_len * enemy_fwd_len);

						if (aim_dot > 0.95f) {
							std::string name_str = player.m_bIsAI ? "[AI]人机" : bm::bm_wstrTostr_utf8(player.m_PlayerName);
							std::string weapon_str = "";
							auto weapon_name = player.m_CurrentUsingWeaponSafety.CachedName;
							if (weapon_name.empty()) weapon_name = player.m_CurrentUsingWeaponSafety.m_FName.ToString();

							if (!weapon_name.empty() && weapon_name != "None") {
								auto cn_name = GetWeaponName(weapon_name);
								if (!cn_name.empty()) weapon_str = cn_name;
							}

							bool already_added = false;
							for (const auto& aim_info : aiming_enemies) {
								if (aim_info.name == name_str) { already_added = true; break; }
							}

							if (!already_added) {
								aiming_enemies.push_back({ name_str, weapon_str, static_cast<int>(to_me_len / 100.0f) });
							}
						}
					}
				}
			}
		}

		if (is_behind || player.m_Mesh.m_boneTArray.NumElements <= 0) {
						continue;
		}

		draw_player_bone(draw_list, CameraCacheEntry, player);
		draw_player_box(draw_list, CameraCacheEntry, player);
		draw_player_info(draw_list, CameraCacheEntry, player);
	}

	char buffer[256];

	if (dx11_menu::esp::player_warning) {
		snprintf(buffer, sizeof(buffer), "附近玩家[%d]-附近人机[%d]-背后人数[%d]", nearby_players, nearby_ai, behind_enemies);
		ImVec2 pos = { m_Engine.m_rect.w * dx11_menu::esp::info_warning_x, dx11_menu::esp::info_warning_y };
		render::AddText(draw_list, pos, ImGui::ColorConvertFloat4ToU32(ImVec4(dx11_menu::esp::color_info_warning[0], dx11_menu::esp::color_info_warning[1], dx11_menu::esp::color_info_warning[2], dx11_menu::esp::color_info_warning[3])), buffer, dx11_menu::esp::size_info_warning);
	}

	if (dx11_menu::esp::player_aim_warning && !aiming_enemies.empty()) {
		float start_y = 50.0f;
		float start_x = m_Engine.m_rect.w - 20.0f;

		for (const auto& aim_info : aiming_enemies) {
			if (aim_info.weapon.empty()) {
				snprintf(buffer, sizeof(buffer), "[%s]-正在瞄准您[%d 米]", aim_info.name.c_str(), aim_info.distance);
			}
			else {
				snprintf(buffer, sizeof(buffer), "[%s]-正在使用[%s]瞄准您[%d 米]", aim_info.name.c_str(), aim_info.weapon.c_str(), aim_info.distance);
			}

			ImVec2 text_size = ImGui::GetFont()->CalcTextSizeA(dx11_menu::esp::size_aim_warning, FLT_MAX, 0.0f, buffer);
			ImVec2 pos = { start_x - text_size.x, start_y };

			render::AddText(draw_list, pos, ImGui::ColorConvertFloat4ToU32(ImVec4(dx11_menu::esp::color_aim_warning[0], dx11_menu::esp::color_aim_warning[1], dx11_menu::esp::color_aim_warning[2], dx11_menu::esp::color_aim_warning[3])), buffer, dx11_menu::esp::size_aim_warning);

			start_y += text_size.y + 5.0f;
		}
	}
}

void SetupImGuiStyle() {
	ImGuiStyle& style = ImGui::GetStyle();
	ImVec4* colors = style.Colors;

	// 赛博朋克主题 — 深空黑 #080C14 / 青 #00E5FF / 紫 #B44CFF
	colors[ImGuiCol_Text] = ImVec4(0.80f, 0.95f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.25f, 0.50f, 0.60f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.03f, 0.05f, 0.08f, 0.94f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.05f, 0.07f, 0.10f, 0.40f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.03f, 0.04f, 0.07f, 0.94f);
	colors[ImGuiCol_Border] = ImVec4(0.00f, 0.65f, 0.80f, 0.50f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.08f, 0.04f, 0.15f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.00f, 0.45f, 0.60f, 0.40f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.00f, 0.55f, 0.75f, 0.67f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.02f, 0.10f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.25f, 0.05f, 0.40f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.06f, 0.03f, 0.12f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.04f, 0.53f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.20f, 0.06f, 0.35f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.00f, 0.50f, 0.70f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.00f, 0.70f, 0.90f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.00f, 0.90f, 1.00f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.00f, 0.90f, 1.00f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.30f, 0.95f, 1.00f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.25f, 0.05f, 0.40f, 0.40f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.00f, 0.60f, 0.85f, 1.00f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.00f, 0.85f, 1.00f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.20f, 0.05f, 0.35f, 0.31f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.55f, 0.75f, 0.80f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.00f, 0.80f, 1.00f, 1.00f);
	colors[ImGuiCol_Separator] = colors[ImGuiCol_Border];
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.00f, 0.50f, 0.70f, 0.78f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.00f, 0.80f, 1.00f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.50f, 0.70f, 0.20f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.00f, 0.65f, 0.85f, 0.67f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.00f, 0.90f, 1.00f, 0.95f);
	colors[ImGuiCol_Tab] = ImVec4(0.18f, 0.03f, 0.30f, 0.86f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.00f, 0.65f, 0.85f, 0.80f);
	colors[ImGuiCol_TabActive] = ImVec4(0.00f, 0.80f, 1.00f, 1.00f);
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.04f, 0.02f, 0.08f, 0.97f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.10f, 0.04f, 0.20f, 1.00f);

	style.WindowRounding = 4.0f;
	style.ChildRounding = 4.0f;
	style.FrameRounding = 3.0f;
	style.PopupRounding = 4.0f;
	style.ScrollbarRounding = 3.0f;
	style.GrabRounding = 2.0f;
	style.TabRounding = 3.0f;

	style.WindowPadding = ImVec2(10.0f, 10.0f);
	style.FramePadding = ImVec2(6.0f, 4.0f);
	style.ItemSpacing = ImVec2(8.0f, 6.0f);
	style.ItemInnerSpacing = ImVec2(6.0f, 6.0f);
	style.ScrollbarSize = 12.0f;
}

namespace Config { void Save(); }

// 自定义滑动开关控件
bool ToggleButton(const char* str_id, bool* v)
{
	ImVec2 p = ImGui::GetCursorScreenPos();
	ImDrawList* draw_list = ImGui::GetWindowDrawList();

	float height = ImGui::GetFrameHeight();
	float width = height * 1.55f;
	float radius = height * 0.50f;

	bool changed = false;
	ImGui::InvisibleButton(str_id, ImVec2(width, height));
	if (ImGui::IsItemClicked()) {
		*v = !*v;
		changed = true;
		Config::Save();
	}

	float t = *v ? 1.0f : 0.0f;

	ImGuiContext& g = *GImGui;
	float ANIM_SPEED = 0.08f;
	if (g.LastActiveId == g.CurrentWindow->GetID(str_id))// && g.LastActiveIdTimer < ANIM_SPEED)
	{
		float t_anim = ImClamp(g.LastActiveIdTimer / ANIM_SPEED, 0.0f, 1.0f);
		t = *v ? (t_anim) : (1.0f - t_anim);
	}

	ImU32 col_bg;
	if (ImGui::IsItemHovered())
		col_bg = ImGui::GetColorU32(ImLerp(ImVec4(0.20f, 0.05f, 0.30f, 0.40f), ImVec4(0.00f, 0.85f, 1.00f, 0.80f), t));
	else
		col_bg = ImGui::GetColorU32(ImLerp(ImVec4(0.20f, 0.05f, 0.30f, 0.20f), ImVec4(0.00f, 0.85f, 1.00f, 0.60f), t));

	draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, height * 0.5f);
	draw_list->AddCircleFilled(ImVec2(p.x + radius + t * (width - radius * 2.0f), p.y + radius), radius - 1.5f, IM_COL32(255, 255, 255, 255));

	// 绘制文字
	ImGui::SameLine();
	ImGui::Text("%s", str_id);

	return changed;
}

int GetItemCategory(const std::string& name) {
	if (name.find("突击步枪") != std::string::npos || name.find("冲锋枪") != std::string::npos ||
		name.find("狙击枪") != std::string::npos || name.find("射手步枪") != std::string::npos ||
		name.find("霰弹枪") != std::string::npos || name.find("轻机枪") != std::string::npos ||
		name.find("手枪") != std::string::npos || name.find("平底锅") != std::string::npos ||
		name.find("镰刀") != std::string::npos || name.find("撬棍") != std::string::npos ||
		name.find("大砍刀") != std::string::npos || name.find("十字弩") != std::string::npos ||
		name.find("战术弩") != std::string::npos || name.find("爆炸猎弓") != std::string::npos ||
		name.find("复合弓") != std::string::npos || name.find("迫击炮") != std::string::npos ||
		name.find("手雷") != std::string::npos || name.find("烟雾弹") != std::string::npos ||
		name.find("燃烧瓶") != std::string::npos || name.find("闪光弹") != std::string::npos ||
		name.find("C4") != std::string::npos || name.find("陷阱") != std::string::npos) {
		return 1; // 武器
	}
	if (name.find("瞄准镜") != std::string::npos || name.find("瞄具") != std::string::npos ||
		name.find("倍镜") != std::string::npos || name.find("补偿") != std::string::npos ||
		name.find("消音") != std::string::npos || name.find("消焰") != std::string::npos ||
		name.find("快扩") != std::string::npos || name.find("扩容") != std::string::npos ||
		name.find("快速") != std::string::npos || name.find("子弹袋") != std::string::npos ||
		name.find("托腮板") != std::string::npos || name.find("折叠托") != std::string::npos ||
		name.find("战术托") != std::string::npos || name.find("枪托") != std::string::npos ||
		name.find("握把") != std::string::npos || name.find("鸭嘴") != std::string::npos ||
		name.find("收束器") != std::string::npos || name.find("弩箭袋") != std::string::npos) {
		return 2; // 配件
	}
	if (name.find("头") != std::string::npos || name.find("甲") != std::string::npos ||
		name.find("包") != std::string::npos || name.find("吉利服") != std::string::npos ||
		name.find("修理") != std::string::npos) {
		return 3; // 装备
	}
	if (name.find("医疗箱") != std::string::npos || name.find("急救包") != std::string::npos ||
		name.find("绷带") != std::string::npos || name.find("能量饮料") != std::string::npos ||
		name.find("止痛药") != std::string::npos || name.find("肾上腺素") != std::string::npos ||
		name.find("除颤器") != std::string::npos || name.find("杏皮茶") != std::string::npos) {
		return 4; // 药品
	}
	if (name.find("mm") != std::string::npos || name.find("马格南") != std::string::npos ||
		name.find(".45") != std::string::npos || name.find("12号") != std::string::npos ||
		name.find("弩箭") != std::string::npos || name.find("50BMG") != std::string::npos ||
		name.find("信号弹") != std::string::npos || name.find("炮弹") != std::string::npos) {
		return 5; // 弹药
	}
	if (name.find("空投") != std::string::npos || name.find("盒子") != std::string::npos ||
		name.find("骨灰盒") != std::string::npos || name.find("箱子") != std::string::npos) {
		return 6; // 空投/盒子
	}
	return 7; // 其他
}

int GetVehicleCategory(const std::string& name) {
	if (name.find("轿车") != std::string::npos || name.find("吉普") != std::string::npos ||
		name.find("跑车") != std::string::npos || name.find("蹦蹦") != std::string::npos ||
		name.find("越野") != std::string::npos || name.find("皮卡") != std::string::npos ||
		name.find("罗尼") != std::string::npos || name.find("大脚") != std::string::npos ||
		name.find("装甲") != std::string::npos || name.find("碰碰") != std::string::npos ||
		name.find("公交") != std::string::npos || name.find("赛车") != std::string::npos ||
		name.find("漂移") != std::string::npos || name.find("布朗") != std::string::npos ||
		name.find("旅行车") != std::string::npos || name.find("全地形") != std::string::npos) {
		return 1; // 汽车
	}
	if (name.find("摩托") != std::string::npos || name.find("三轮") != std::string::npos ||
		name.find("小绵羊") != std::string::npos || name.find("自行车") != std::string::npos) {
		return 2; // 摩托
	}
	if (name.find("快艇") != std::string::npos || name.find("水上") != std::string::npos) {
		return 3; // 船
	}
	return 4; // 其他
}

int g_box_type = 0;
bool g_box_connected = false; // PUBG_DMA 风格: 全局连接状态

// ═══ 自瞄日志系统 (写入 aim_log.txt) ═══
static std::mutex g_aim_log_mutex;
static FILE* g_aim_log_fp = nullptr;
template<typename... Args>
static void aim_log(std::string_view fmt, Args&&... args) {
	std::string msg;
	try {
		msg = std::vformat(fmt, std::make_format_args(args...));
	} catch (...) { return; }
	std::lock_guard<std::mutex> lock(g_aim_log_mutex);
	if (!g_aim_log_fp) {
		fopen_s(&g_aim_log_fp, "aim_log.txt", "a");
	}
	if (g_aim_log_fp) {
		auto now = std::chrono::system_clock::now();
		auto t = std::chrono::system_clock::to_time_t(now);
		std::tm tm_buf;
		localtime_s(&tm_buf, &t);
		fprintf(g_aim_log_fp, "[%02d:%02d:%02d] %s\n", tm_buf.tm_hour, tm_buf.tm_min, tm_buf.tm_sec, msg.c_str());
		// 不调用fflush: 让OS缓冲区自动管理, 避免每帧阻塞IO导致盒子超时
	}
}
// ═══

// ═══ PUBG_DMA 风格: 统一硬件盒子调用包装（移植自 AimBot.h + KmBoxNet.h） ═══
static void Box_Move(int x, int y) {
	switch (g_box_type) {
	case 0: kmNet_mouse_move_auto(x, y, 1); break; // KmBoxNet (网络版)
	case 1: KmBox::Move(x, y); Sleep(1); break;     // KmBox (COM串口+防溢出)
	case 2: Lurker::Move(x, y); break;              // Lurker
	case 3: MoBox::Move(x, y); break;               // MoBox
	}
}

static void Box_Click() {
	if (!g_box_connected) return;
	switch (g_box_type) {
	case 0: kmNet_mouse_left(1); break;
	// KmBox COM/Lurker/MoBox 不支持模拟点击，跳过
	default: break;
	}
}

static void Box_Release() {
	if (!g_box_connected) return;
	switch (g_box_type) {
	case 0: kmNet_mouse_left(0); break;
	default: break;
	}
}

static void Box_ScrollUp() {
	if (!g_box_connected) return;
	switch (g_box_type) {
	case 0: kmNet_mouse_wheel(-1); break;
	default: break;
	}
}

static void Box_ScrollDown() {
	if (!g_box_connected) return;
	switch (g_box_type) {
	case 0: kmNet_mouse_wheel(1); break;
	default: break;
	}
}
// ═══ 盒子包装函数结束 ═══
char g_ip[32] = "192.168.2.188";
char g_port[16] = "6234";
char g_uuid[64] = "UUID";
char g_com_port[32] = "COM1";

namespace Config {
	const char* config_file = ".\\config.ini";


	void WriteFloat(const char* section, const char* key, float value) {
		char buf[32];
		sprintf_s(buf, "%.3f", value);
		WritePrivateProfileStringA(section, key, buf, config_file);
	}

	void WriteInt(const char* section, const char* key, int value) {
		char buf[32];
		sprintf_s(buf, "%d", value);
		WritePrivateProfileStringA(section, key, buf, config_file);
	}

	void WriteBool(const char* section, const char* key, bool value) {
		WritePrivateProfileStringA(section, key, value ? "1" : "0", config_file);
	}

	void WriteColor(const char* section, const char* key, float* color) {
		char buf[64];
		sprintf_s(buf, "%.3f,%.3f,%.3f,%.3f", color[0], color[1], color[2], color[3]);
		WritePrivateProfileStringA(section, key, buf, config_file);
	}

	void WriteString(const char* section, const char* key, const char* value) {
		WritePrivateProfileStringA(section, key, value, config_file);
	}

	float ReadFloat(const char* section, const char* key, float default_val) {
		char buf[32];
		GetPrivateProfileStringA(section, key, "", buf, 32, config_file);
		if (buf[0] == 0) return default_val;
		return (float)atof(buf);
	}

	int ReadInt(const char* section, const char* key, int default_val) {
		return GetPrivateProfileIntA(section, key, default_val, config_file);
	}

	bool ReadBool(const char* section, const char* key, bool default_val) {
		return GetPrivateProfileIntA(section, key, default_val ? 1 : 0, config_file) != 0;
	}

	void ReadColor(const char* section, const char* key, float* color) {
		char buf[64];
		GetPrivateProfileStringA(section, key, "", buf, 64, config_file);
		if (buf[0] != 0) {
			sscanf_s(buf, "%f,%f,%f,%f", &color[0], &color[1], &color[2], &color[3]);
		}
	}

	void ReadString(const char* section, const char* key, char* buf, int size) {
		GetPrivateProfileStringA(section, key, "", buf, size, config_file);
	}

	void Save() {
		// ESP
		WriteBool("ESP", "player", dx11_menu::esp::player);
		WriteBool("ESP", "player_bone", dx11_menu::esp::player_bone);
		WriteBool("ESP", "player_bone_id", dx11_menu::esp::player_bone_id);
		WriteInt("ESP", "player_bone_style", dx11_menu::esp::player_bone_style);
		WriteBool("ESP", "player_box", dx11_menu::esp::player_box);
		WriteBool("ESP", "player_name", dx11_menu::esp::player_name);
		WriteBool("ESP", "player_weapon", dx11_menu::esp::player_weapon);
		WriteBool("ESP", "player_dis", dx11_menu::esp::player_dis);
		WriteBool("ESP", "player_team", dx11_menu::esp::player_team);
		WriteBool("ESP", "player_health", dx11_menu::esp::player_health);
		WriteInt("ESP", "player_health_style", dx11_menu::esp::player_health_style);
		WriteBool("ESP", "player_energy", dx11_menu::esp::player_energy);
		WriteBool("ESP", "player_kills", dx11_menu::esp::player_kills);
		WriteBool("ESP", "player_action", dx11_menu::esp::player_action);
		WriteBool("ESP", "player_groggy", dx11_menu::esp::player_groggy);
		WriteBool("ESP", "player_line", dx11_menu::esp::player_line);
		WriteBool("ESP", "player_ignore_me", dx11_menu::esp::player_ignore_me);
		WriteBool("ESP", "player_ignore_team", dx11_menu::esp::player_ignore_team);
		WriteBool("ESP", "player_permission", dx11_menu::esp::player_permission);
		WriteBool("ESP", "player_warning", dx11_menu::esp::player_warning);
		WriteBool("ESP", "player_aim_warning", dx11_menu::esp::player_aim_warning);
		WriteBool("ESP", "player_vis_check", dx11_menu::esp::player_vis_check);
		WriteBool("ESP", "vehicle", dx11_menu::esp::vehicle);
		WriteBool("ESP", "vehicle_hp", dx11_menu::esp::vehicle_hp);
		WriteBool("ESP", "vehicle_fuel", dx11_menu::esp::vehicle_fuel);
		WriteBool("ESP", "vehicle_tire", dx11_menu::esp::vehicle_tire);
		WriteBool("ESP", "vehicle_dis", dx11_menu::esp::vehicle_dis);
		WriteBool("ESP", "item_collapse", dx11_menu::esp::item_collapse);
		WriteBool("ESP", "item_airdrop", dx11_menu::esp::item_airdrop);
		WriteBool("ESP", "item_grenade", dx11_menu::esp::item_grenade);
		WriteBool("ESP", "item_meds", dx11_menu::esp::item_meds);
		WriteFloat("ESP", "item_size", dx11_menu::esp::item_size);
		WriteBool("ESP", "vehicle_name", dx11_menu::esp::vehicle_name);
		WriteInt("ESP", "vehicle_tire_style", dx11_menu::esp::vehicle_tire_style);

		WriteBool("ESP", "show_all_classes", dx11_menu::esp::show_all_classes);
		WriteBool("ESP", "show_physx_models", dx11_menu::esp::show_physx_models);
		WriteBool("ESP", "metro_mode", dx11_menu::esp::metro_mode);
		WriteBool("ESP", "metro_monster", dx11_menu::esp::metro_monster);

		// Colors
		WriteColor("ESP", "color_box", dx11_menu::esp::color_box);
		WriteColor("ESP", "color_bone_vis", dx11_menu::esp::color_bone_vis);
		WriteColor("ESP", "color_bone_invis", dx11_menu::esp::color_bone_invis);
		WriteColor("ESP", "color_team_id", dx11_menu::esp::color_team_id);
		WriteColor("ESP", "color_distance", dx11_menu::esp::color_distance);
		WriteColor("ESP", "color_energy", dx11_menu::esp::color_energy);
		WriteColor("ESP", "color_kills", dx11_menu::esp::color_kills);
		WriteColor("ESP", "color_name", dx11_menu::esp::color_name);
		WriteColor("ESP", "color_weapon", dx11_menu::esp::color_weapon);
		WriteColor("ESP", "color_action", dx11_menu::esp::color_action);
		WriteColor("ESP", "color_line", dx11_menu::esp::color_line);
		WriteColor("ESP", "color_warning", dx11_menu::esp::color_warning);
		WriteColor("ESP", "color_aim_warning", dx11_menu::esp::color_aim_warning);
		WriteColor("ESP", "color_info_warning", dx11_menu::esp::color_info_warning);
		WriteColor("ESP", "color_fov", dx11_menu::esp::color_fov);
		WriteColor("ESP", "color_trigger_fov", dx11_menu::esp::color_trigger_fov);
		WriteColor("ESP", "color_aim_line", dx11_menu::esp::color_aim_line);
		WriteColor("ESP", "color_target_bone", dx11_menu::esp::color_target_bone);
		WriteColor("ESP", "color_player_out_of_fov_arrow", dx11_menu::esp::color_player_out_of_fov_arrow);

		WriteColor("ESP", "color_vehicle_name", dx11_menu::esp::color_vehicle_name);
		WriteColor("ESP", "color_vehicle_hp", dx11_menu::esp::color_vehicle_hp);
		WriteColor("ESP", "color_vehicle_fuel", dx11_menu::esp::color_vehicle_fuel);
		WriteColor("ESP", "color_vehicle_tire", dx11_menu::esp::color_vehicle_tire);

		// Widths
		WriteFloat("ESP", "width_bone", dx11_menu::esp::width_bone);
		WriteFloat("ESP", "width_box", dx11_menu::esp::width_box);
		WriteFloat("ESP", "width_line", dx11_menu::esp::width_line);

		// Sizes
		WriteFloat("ESP", "size_team_id", dx11_menu::esp::size_team_id);
		WriteFloat("ESP", "size_kills", dx11_menu::esp::size_kills);
		WriteFloat("ESP", "size_name", dx11_menu::esp::size_name);
		WriteFloat("ESP", "size_weapon", dx11_menu::esp::size_weapon);
		WriteFloat("ESP", "size_energy", dx11_menu::esp::size_energy);
		WriteFloat("ESP", "size_distance", dx11_menu::esp::size_distance);
		WriteFloat("ESP", "size_action", dx11_menu::esp::size_action);
		WriteFloat("ESP", "size_aim_warning", dx11_menu::esp::size_aim_warning);
		WriteFloat("ESP", "size_info_warning", dx11_menu::esp::size_info_warning);
		WriteFloat("ESP", "size_vehicle_name", dx11_menu::esp::size_vehicle_name);
		WriteFloat("ESP", "size_vehicle_hp", dx11_menu::esp::size_vehicle_hp);
		WriteFloat("ESP", "size_vehicle_fuel", dx11_menu::esp::size_vehicle_fuel);
		WriteFloat("ESP", "size_vehicle_tire", dx11_menu::esp::size_vehicle_tire);

		// Positions
		WriteFloat("ESP", "info_warning_x", dx11_menu::esp::info_warning_x);
		WriteFloat("ESP", "info_warning_y", dx11_menu::esp::info_warning_y);
		WriteInt("ESP", "line_pos", dx11_menu::esp::line_pos);

		// Filters & Buffers
		WriteString("ESP", "item_search_buf", dx11_menu::esp::item_search_buf);
		WriteInt("ESP", "item_filter_type", dx11_menu::esp::item_filter_type);
		WriteString("ESP", "vehicle_search_buf", dx11_menu::esp::vehicle_search_buf);
		WriteInt("ESP", "vehicle_filter_type", dx11_menu::esp::vehicle_filter_type);

		// Radar
		WriteBool("Radar", "radar", dx11_menu::esp::radar);
		WriteInt("Radar", "radar_style", dx11_menu::esp::radar_style);
		WriteBool("Radar", "radar_name", dx11_menu::esp::radar_name);
		WriteBool("Radar", "radar_vehicle", dx11_menu::esp::radar_vehicle);
		WriteBool("Radar", "radar_dis", dx11_menu::esp::radar_dis);
		WriteBool("Radar", "radar_ai", dx11_menu::esp::radar_ai);
		WriteBool("Radar", "radar_item", dx11_menu::esp::radar_item);
		WriteFloat("Radar", "radar_x", dx11_menu::esp::radar_x);
		WriteFloat("Radar", "radar_y", dx11_menu::esp::radar_y);
		WriteFloat("Radar", "radar_size", dx11_menu::esp::radar_size);
		WriteFloat("Radar", "radar_range", dx11_menu::esp::radar_range);

		// Aim
		WriteBool("Aim", "enable", dx11_menu::aim::enable);
		WriteFloat("Aim", "fov", dx11_menu::aim::fov);
		WriteFloat("Aim", "smooth", dx11_menu::aim::smooth);
		WriteFloat("Aim", "dist", dx11_menu::aim::dist);
		WriteFloat("Aim", "x", dx11_menu::aim::x);
		WriteFloat("Aim", "y", dx11_menu::aim::y);
		WriteInt("Aim", "key1", dx11_menu::aim::key1);
		WriteInt("Aim", "key2", dx11_menu::aim::key2);
		WriteBool("Aim", "show_fov", dx11_menu::aim::show_fov);
		WriteBool("Aim", "prediction", dx11_menu::aim::prediction);
		WriteBool("Aim", "no_recoil", dx11_menu::aim::no_recoil);
		WriteBool("Aim", "ignore_groggy", dx11_menu::aim::ignore_groggy);
		WriteBool("Aim", "ignore_ai", dx11_menu::aim::ignore_ai);
		WriteBool("Aim", "vis_check", dx11_menu::aim::vis_check);
		WriteBool("Aim", "bone_scan", dx11_menu::aim::bone_scan);
		WriteInt("Aim", "aim_bone_mode", dx11_menu::aim::aim_bone_mode);
		WriteInt("Aim", "aim_bone_id", dx11_menu::aim::aim_bone_id);
		WriteBool("Aim", "humanize", dx11_menu::aim::humanize);
		WriteBool("Aim", "ignore_bow", dx11_menu::aim::ignore_bow);
		WriteBool("Aim", "ignore_empty", dx11_menu::aim::ignore_empty);
		WriteBool("Aim", "auto_lock", dx11_menu::aim::auto_lock);
		WriteBool("Aim", "range_boost", dx11_menu::aim::range_boost);
		WriteBool("Aim", "draw_line", dx11_menu::aim::draw_line);
		WriteBool("Aim", "fire_aim", dx11_menu::aim::fire_aim);
		WriteBool("Aim", "dynamic_fov", dx11_menu::aim::dynamic_fov);
		WriteBool("Aim", "draw_target_bone", dx11_menu::aim::draw_target_bone);

		// Trigger
		WriteBool("Trigger", "enable", dx11_menu::trigger::enable);
		WriteBool("Trigger", "aim_sync", dx11_menu::trigger::aim_sync);
		WriteBool("Trigger", "show_fov", dx11_menu::trigger::show_fov);
		WriteFloat("Trigger", "fov", dx11_menu::trigger::fov);
		WriteInt("Trigger", "delay", dx11_menu::trigger::delay);
		WriteInt("Trigger", "key1", dx11_menu::trigger::key1);
		WriteInt("Trigger", "key2", dx11_menu::trigger::key2);
		WriteFloat("Trigger", "aim_smooth", dx11_menu::trigger::aim_smooth);
		WriteFloat("Trigger", "aim_fov", dx11_menu::trigger::aim_fov);
		WriteBool("Trigger", "show_aim_fov", dx11_menu::trigger::show_aim_fov);
		WriteBool("Trigger", "ignore_groggy", dx11_menu::trigger::ignore_groggy);
		WriteBool("Trigger", "ignore_ai", dx11_menu::trigger::ignore_ai);
		WriteBool("Trigger", "dynamic_fov", dx11_menu::trigger::dynamic_fov);

		// Shortcut
		WriteBool("Shortcut", "enable", dx11_menu::shortcut::enable);
		WriteBool("Shortcut", "show_time", dx11_menu::shortcut::show_time);
		WriteBool("Shortcut", "show_status", dx11_menu::shortcut::show_status);
		WriteInt("Shortcut", "key_toggle_menu", dx11_menu::shortcut::key_toggle_menu);
		WriteInt("Shortcut", "key_fusion", dx11_menu::shortcut::key_fusion);
		WriteInt("Shortcut", "key_aim", dx11_menu::shortcut::key_aim);
		WriteInt("Shortcut", "key_meds", dx11_menu::shortcut::key_meds);
		WriteInt("Shortcut", "key_vehicle", dx11_menu::shortcut::key_vehicle);
		WriteInt("Shortcut", "key_weapon", dx11_menu::shortcut::key_weapon);
		WriteFloat("Shortcut", "x", dx11_menu::shortcut::x);
		WriteFloat("Shortcut", "y", dx11_menu::shortcut::y);
		WriteFloat("Shortcut", "size", dx11_menu::shortcut::size);
		WriteColor("Shortcut", "color", dx11_menu::shortcut::color);

		WriteInt("Menu", "key", dx11_menu::esp::menu_key);

		// Hardware
		WriteInt("Hardware", "box_type", g_box_type);
		WriteString("Hardware", "ip", g_ip);
		WriteString("Hardware", "port", g_port);
		WriteString("Hardware", "uuid", g_uuid);
		WriteString("Hardware", "com_port", g_com_port);

		// Arrow
		WriteBool("ESP", "player_out_of_fov_arrow", dx11_menu::esp::player_out_of_fov_arrow);
		WriteFloat("ESP", "player_out_of_fov_arrow_radius", dx11_menu::esp::player_out_of_fov_arrow_radius);
		WriteFloat("ESP", "player_out_of_fov_arrow_size", dx11_menu::esp::player_out_of_fov_arrow_size);

		// Snow
		WriteBool("ESP", "snow_effect", dx11_menu::esp::snow_effect);
	}

	void Load() {
		// Hardware
		g_box_type = ReadInt("Hardware", "box_type", g_box_type);
		ReadString("Hardware", "ip", g_ip, sizeof(g_ip));
		ReadString("Hardware", "port", g_port, sizeof(g_port));
		ReadString("Hardware", "uuid", g_uuid, sizeof(g_uuid));
		ReadString("Hardware", "com_port", g_com_port, sizeof(g_com_port));

		// ESP
		dx11_menu::esp::player = ReadBool("ESP", "player", dx11_menu::esp::player);
		dx11_menu::esp::player_out_of_fov_arrow = ReadBool("ESP", "player_out_of_fov_arrow", dx11_menu::esp::player_out_of_fov_arrow);
		dx11_menu::esp::player_out_of_fov_arrow_radius = ReadFloat("ESP", "player_out_of_fov_arrow_radius", dx11_menu::esp::player_out_of_fov_arrow_radius);
		dx11_menu::esp::player_out_of_fov_arrow_size = ReadFloat("ESP", "player_out_of_fov_arrow_size", dx11_menu::esp::player_out_of_fov_arrow_size);
		dx11_menu::esp::snow_effect = ReadBool("ESP", "snow_effect", dx11_menu::esp::snow_effect);
		// ... (Rest of Load code)
		dx11_menu::esp::player_bone = ReadBool("ESP", "player_bone", dx11_menu::esp::player_bone);
		dx11_menu::esp::player_bone_id = ReadBool("ESP", "player_bone_id", dx11_menu::esp::player_bone_id);
		dx11_menu::esp::player_bone_style = ReadInt("ESP", "player_bone_style", dx11_menu::esp::player_bone_style);
		dx11_menu::esp::player_box = ReadBool("ESP", "player_box", dx11_menu::esp::player_box);
		dx11_menu::esp::player_name = ReadBool("ESP", "player_name", dx11_menu::esp::player_name);
		dx11_menu::esp::player_weapon = ReadBool("ESP", "player_weapon", dx11_menu::esp::player_weapon);
		dx11_menu::esp::player_dis = ReadBool("ESP", "player_dis", dx11_menu::esp::player_dis);
		dx11_menu::esp::player_team = ReadBool("ESP", "player_team", dx11_menu::esp::player_team);
		dx11_menu::esp::player_health = ReadBool("ESP", "player_health", dx11_menu::esp::player_health);
		dx11_menu::esp::player_health_style = ReadInt("ESP", "player_health_style", dx11_menu::esp::player_health_style);
		dx11_menu::esp::player_energy = ReadBool("ESP", "player_energy", dx11_menu::esp::player_energy);
		dx11_menu::esp::player_kills = ReadBool("ESP", "player_kills", dx11_menu::esp::player_kills);
		dx11_menu::esp::player_action = ReadBool("ESP", "player_action", dx11_menu::esp::player_action);
		dx11_menu::esp::player_groggy = ReadBool("ESP", "player_groggy", dx11_menu::esp::player_groggy);
		dx11_menu::esp::player_line = ReadBool("ESP", "player_line", dx11_menu::esp::player_line);
		dx11_menu::esp::player_ignore_me = ReadBool("ESP", "player_ignore_me", dx11_menu::esp::player_ignore_me);
		dx11_menu::esp::player_ignore_team = ReadBool("ESP", "player_ignore_team", dx11_menu::esp::player_ignore_team);
		dx11_menu::esp::player_permission = ReadBool("ESP", "player_permission", dx11_menu::esp::player_permission);
		dx11_menu::esp::player_warning = ReadBool("ESP", "player_warning", dx11_menu::esp::player_warning);
		dx11_menu::esp::player_aim_warning = ReadBool("ESP", "player_aim_warning", dx11_menu::esp::player_aim_warning);
		dx11_menu::esp::player_vis_check = ReadBool("ESP", "player_vis_check", dx11_menu::esp::player_vis_check);
		dx11_menu::esp::vehicle = ReadBool("ESP", "vehicle", dx11_menu::esp::vehicle);
		dx11_menu::esp::vehicle_hp = ReadBool("ESP", "vehicle_hp", dx11_menu::esp::vehicle_hp);
		dx11_menu::esp::vehicle_fuel = ReadBool("ESP", "vehicle_fuel", dx11_menu::esp::vehicle_fuel);
		dx11_menu::esp::vehicle_tire = ReadBool("ESP", "vehicle_tire", dx11_menu::esp::vehicle_tire);
		dx11_menu::esp::vehicle_dis = ReadBool("ESP", "vehicle_dis", dx11_menu::esp::vehicle_dis);
		dx11_menu::esp::item_collapse = ReadBool("ESP", "item_collapse", dx11_menu::esp::item_collapse);
		dx11_menu::esp::item_airdrop = ReadBool("ESP", "item_airdrop", dx11_menu::esp::item_airdrop);
		dx11_menu::esp::item_grenade = ReadBool("ESP", "item_grenade", dx11_menu::esp::item_grenade);
		dx11_menu::esp::item_meds = ReadBool("ESP", "item_meds", dx11_menu::esp::item_meds);
		dx11_menu::esp::item_size = ReadFloat("ESP", "item_size", dx11_menu::esp::item_size);
		dx11_menu::esp::vehicle_name = ReadBool("ESP", "vehicle_name", dx11_menu::esp::vehicle_name);
		dx11_menu::esp::vehicle_tire_style = ReadInt("ESP", "vehicle_tire_style", dx11_menu::esp::vehicle_tire_style);

		dx11_menu::esp::show_all_classes = ReadBool("ESP", "show_all_classes", dx11_menu::esp::show_all_classes);
		dx11_menu::esp::show_physx_models = ReadBool("ESP", "show_physx_models", dx11_menu::esp::show_physx_models);
		dx11_menu::esp::metro_mode = ReadBool("ESP", "metro_mode", dx11_menu::esp::metro_mode);
		dx11_menu::esp::metro_monster = ReadBool("ESP", "metro_monster", dx11_menu::esp::metro_monster);

		// Colors
		ReadColor("ESP", "color_box", dx11_menu::esp::color_box);
		ReadColor("ESP", "color_bone_vis", dx11_menu::esp::color_bone_vis);
		ReadColor("ESP", "color_bone_invis", dx11_menu::esp::color_bone_invis);
		ReadColor("ESP", "color_team_id", dx11_menu::esp::color_team_id);
		ReadColor("ESP", "color_distance", dx11_menu::esp::color_distance);
		ReadColor("ESP", "color_energy", dx11_menu::esp::color_energy);
		ReadColor("ESP", "color_kills", dx11_menu::esp::color_kills);
		ReadColor("ESP", "color_name", dx11_menu::esp::color_name);
		ReadColor("ESP", "color_weapon", dx11_menu::esp::color_weapon);
		ReadColor("ESP", "color_action", dx11_menu::esp::color_action);
		ReadColor("ESP", "color_line", dx11_menu::esp::color_line);
		ReadColor("ESP", "color_warning", dx11_menu::esp::color_warning);
		ReadColor("ESP", "color_aim_warning", dx11_menu::esp::color_aim_warning);
		ReadColor("ESP", "color_info_warning", dx11_menu::esp::color_info_warning);
		ReadColor("ESP", "color_fov", dx11_menu::esp::color_fov);
		ReadColor("ESP", "color_trigger_fov", dx11_menu::esp::color_trigger_fov);
		ReadColor("ESP", "color_aim_line", dx11_menu::esp::color_aim_line);
		ReadColor("ESP", "color_target_bone", dx11_menu::esp::color_target_bone);
		ReadColor("ESP", "color_player_out_of_fov_arrow", dx11_menu::esp::color_player_out_of_fov_arrow);

		ReadColor("ESP", "color_vehicle_name", dx11_menu::esp::color_vehicle_name);
		ReadColor("ESP", "color_vehicle_hp", dx11_menu::esp::color_vehicle_hp);
		ReadColor("ESP", "color_vehicle_fuel", dx11_menu::esp::color_vehicle_fuel);
		ReadColor("ESP", "color_vehicle_tire", dx11_menu::esp::color_vehicle_tire);

		// Widths
		dx11_menu::esp::width_bone = ReadFloat("ESP", "width_bone", dx11_menu::esp::width_bone);
		dx11_menu::esp::width_box = ReadFloat("ESP", "width_box", dx11_menu::esp::width_box);
		dx11_menu::esp::width_line = ReadFloat("ESP", "width_line", dx11_menu::esp::width_line);

		// Sizes
		dx11_menu::esp::size_team_id = ReadFloat("ESP", "size_team_id", dx11_menu::esp::size_team_id);
		dx11_menu::esp::size_kills = ReadFloat("ESP", "size_kills", dx11_menu::esp::size_kills);
		dx11_menu::esp::size_name = ReadFloat("ESP", "size_name", dx11_menu::esp::size_name);
		dx11_menu::esp::size_weapon = ReadFloat("ESP", "size_weapon", dx11_menu::esp::size_weapon);
		dx11_menu::esp::size_energy = ReadFloat("ESP", "size_energy", dx11_menu::esp::size_energy);
		dx11_menu::esp::size_distance = ReadFloat("ESP", "size_distance", dx11_menu::esp::size_distance);
		dx11_menu::esp::size_action = ReadFloat("ESP", "size_action", dx11_menu::esp::size_action);
		dx11_menu::esp::size_aim_warning = ReadFloat("ESP", "size_aim_warning", dx11_menu::esp::size_aim_warning);
		dx11_menu::esp::size_info_warning = ReadFloat("ESP", "size_info_warning", dx11_menu::esp::size_info_warning);
		dx11_menu::esp::size_vehicle_name = ReadFloat("ESP", "size_vehicle_name", dx11_menu::esp::size_vehicle_name);
		dx11_menu::esp::size_vehicle_hp = ReadFloat("ESP", "size_vehicle_hp", dx11_menu::esp::size_vehicle_hp);
		dx11_menu::esp::size_vehicle_fuel = ReadFloat("ESP", "size_vehicle_fuel", dx11_menu::esp::size_vehicle_fuel);
		dx11_menu::esp::size_vehicle_tire = ReadFloat("ESP", "size_vehicle_tire", dx11_menu::esp::size_vehicle_tire);

		// Positions
		dx11_menu::esp::info_warning_x = ReadFloat("ESP", "info_warning_x", dx11_menu::esp::info_warning_x);
		dx11_menu::esp::info_warning_y = ReadFloat("ESP", "info_warning_y", dx11_menu::esp::info_warning_y);
		dx11_menu::esp::line_pos = ReadInt("ESP", "line_pos", dx11_menu::esp::line_pos);

		// Filters & Buffers
		ReadString("ESP", "item_search_buf", dx11_menu::esp::item_search_buf, sizeof(dx11_menu::esp::item_search_buf));
		dx11_menu::esp::item_filter_type = ReadInt("ESP", "item_filter_type", dx11_menu::esp::item_filter_type);
		ReadString("ESP", "vehicle_search_buf", dx11_menu::esp::vehicle_search_buf, sizeof(dx11_menu::esp::vehicle_search_buf));
		dx11_menu::esp::vehicle_filter_type = ReadInt("ESP", "vehicle_filter_type", dx11_menu::esp::vehicle_filter_type);

		// Radar
		dx11_menu::esp::radar = ReadBool("Radar", "radar", dx11_menu::esp::radar);
		dx11_menu::esp::radar_style = ReadInt("Radar", "radar_style", dx11_menu::esp::radar_style);
		dx11_menu::esp::radar_name = ReadBool("Radar", "radar_name", dx11_menu::esp::radar_name);
		dx11_menu::esp::radar_vehicle = ReadBool("Radar", "radar_vehicle", dx11_menu::esp::radar_vehicle);
		dx11_menu::esp::radar_dis = ReadBool("Radar", "radar_dis", dx11_menu::esp::radar_dis);
		dx11_menu::esp::radar_ai = ReadBool("Radar", "radar_ai", dx11_menu::esp::radar_ai);
		dx11_menu::esp::radar_item = ReadBool("Radar", "radar_item", dx11_menu::esp::radar_item);
		dx11_menu::esp::radar_x = ReadFloat("Radar", "radar_x", dx11_menu::esp::radar_x);
		dx11_menu::esp::radar_y = ReadFloat("Radar", "radar_y", dx11_menu::esp::radar_y);
		dx11_menu::esp::radar_size = ReadFloat("Radar", "radar_size", dx11_menu::esp::radar_size);
		dx11_menu::esp::radar_range = ReadFloat("Radar", "radar_range", dx11_menu::esp::radar_range);

		// Aim
		dx11_menu::aim::enable = ReadBool("Aim", "enable", dx11_menu::aim::enable);
		dx11_menu::aim::fov = ReadFloat("Aim", "fov", dx11_menu::aim::fov);
		dx11_menu::aim::smooth = ReadFloat("Aim", "smooth", dx11_menu::aim::smooth);
		dx11_menu::aim::dist = ReadFloat("Aim", "dist", dx11_menu::aim::dist);
		dx11_menu::aim::x = ReadFloat("Aim", "x", dx11_menu::aim::x);
		dx11_menu::aim::y = ReadFloat("Aim", "y", dx11_menu::aim::y);
		dx11_menu::aim::key1 = ReadInt("Aim", "key1", dx11_menu::aim::key1);
		dx11_menu::aim::key2 = ReadInt("Aim", "key2", dx11_menu::aim::key2);
		dx11_menu::aim::show_fov = ReadBool("Aim", "show_fov", dx11_menu::aim::show_fov);
		dx11_menu::aim::prediction = ReadBool("Aim", "prediction", dx11_menu::aim::prediction);
		dx11_menu::aim::prediction = false; // 暂时无法使用
		dx11_menu::aim::no_recoil = ReadBool("Aim", "no_recoil", dx11_menu::aim::no_recoil);
		dx11_menu::aim::ignore_groggy = ReadBool("Aim", "ignore_groggy", dx11_menu::aim::ignore_groggy);
		dx11_menu::aim::ignore_ai = ReadBool("Aim", "ignore_ai", dx11_menu::aim::ignore_ai);
		dx11_menu::aim::vis_check = ReadBool("Aim", "vis_check", dx11_menu::aim::vis_check);
		dx11_menu::aim::bone_scan = ReadBool("Aim", "bone_scan", dx11_menu::aim::bone_scan);
		dx11_menu::aim::aim_bone_mode = ReadInt("Aim", "aim_bone_mode", -1);
		dx11_menu::aim::aim_bone_id = ReadInt("Aim", "aim_bone_id", 6);
		// 兼容老配置：如果 ini 里没有 aim_bone_mode，从旧 bone_scan 推算
		if (dx11_menu::aim::aim_bone_mode == -1) {
			dx11_menu::aim::aim_bone_mode = dx11_menu::aim::bone_scan ? 1 : 0;
		}
		dx11_menu::aim::humanize = ReadBool("Aim", "humanize", dx11_menu::aim::humanize);
		dx11_menu::aim::ignore_bow = ReadBool("Aim", "ignore_bow", dx11_menu::aim::ignore_bow);
		dx11_menu::aim::ignore_empty = ReadBool("Aim", "ignore_empty", dx11_menu::aim::ignore_empty);
		dx11_menu::aim::auto_lock = ReadBool("Aim", "auto_lock", dx11_menu::aim::auto_lock);
		dx11_menu::aim::auto_lock = false; // 默认关闭
		dx11_menu::aim::range_boost = ReadBool("Aim", "range_boost", dx11_menu::aim::range_boost);
		dx11_menu::aim::draw_line = ReadBool("Aim", "draw_line", dx11_menu::aim::draw_line);
		dx11_menu::aim::fire_aim = ReadBool("Aim", "fire_aim", dx11_menu::aim::fire_aim);
		dx11_menu::aim::dynamic_fov = ReadBool("Aim", "dynamic_fov", dx11_menu::aim::dynamic_fov);
		dx11_menu::aim::draw_target_bone = ReadBool("Aim", "draw_target_bone", dx11_menu::aim::draw_target_bone);

		// Trigger
		dx11_menu::trigger::enable = ReadBool("Trigger", "enable", dx11_menu::trigger::enable);
		dx11_menu::trigger::aim_sync = ReadBool("Trigger", "aim_sync", dx11_menu::trigger::aim_sync);
		dx11_menu::trigger::show_fov = ReadBool("Trigger", "show_fov", dx11_menu::trigger::show_fov);
		dx11_menu::trigger::fov = ReadFloat("Trigger", "fov", dx11_menu::trigger::fov);
		dx11_menu::trigger::delay = ReadInt("Trigger", "delay", dx11_menu::trigger::delay);
		dx11_menu::trigger::key1 = ReadInt("Trigger", "key1", dx11_menu::trigger::key1);
		dx11_menu::trigger::key2 = ReadInt("Trigger", "key2", dx11_menu::trigger::key2);
		dx11_menu::trigger::aim_smooth = ReadFloat("Trigger", "aim_smooth", dx11_menu::trigger::aim_smooth);
		dx11_menu::trigger::aim_fov = ReadFloat("Trigger", "aim_fov", dx11_menu::trigger::aim_fov);
		dx11_menu::trigger::show_aim_fov = ReadBool("Trigger", "show_aim_fov", dx11_menu::trigger::show_aim_fov);
		dx11_menu::trigger::ignore_groggy = ReadBool("Trigger", "ignore_groggy", dx11_menu::trigger::ignore_groggy);
		dx11_menu::trigger::ignore_ai = ReadBool("Trigger", "ignore_ai", dx11_menu::trigger::ignore_ai);
		dx11_menu::trigger::dynamic_fov = ReadBool("Trigger", "dynamic_fov", dx11_menu::trigger::dynamic_fov);

		// Shortcut
		dx11_menu::shortcut::enable = ReadBool("Shortcut", "enable", dx11_menu::shortcut::enable);
		dx11_menu::shortcut::show_time = ReadBool("Shortcut", "show_time", dx11_menu::shortcut::show_time);
		dx11_menu::shortcut::show_status = ReadBool("Shortcut", "show_status", dx11_menu::shortcut::show_status);
		dx11_menu::shortcut::key_toggle_menu = ReadInt("Shortcut", "key_toggle_menu", dx11_menu::shortcut::key_toggle_menu);
		dx11_menu::shortcut::key_fusion = ReadInt("Shortcut", "key_fusion", dx11_menu::shortcut::key_fusion);
		dx11_menu::shortcut::key_aim = ReadInt("Shortcut", "key_aim", dx11_menu::shortcut::key_aim);
		dx11_menu::shortcut::key_meds = ReadInt("Shortcut", "key_meds", dx11_menu::shortcut::key_meds);
		dx11_menu::shortcut::key_vehicle = ReadInt("Shortcut", "key_vehicle", dx11_menu::shortcut::key_vehicle);
		dx11_menu::shortcut::key_weapon = ReadInt("Shortcut", "key_weapon", dx11_menu::shortcut::key_weapon);
		dx11_menu::shortcut::x = ReadFloat("Shortcut", "x", dx11_menu::shortcut::x);
		dx11_menu::shortcut::y = ReadFloat("Shortcut", "y", dx11_menu::shortcut::y);
		dx11_menu::shortcut::size = ReadFloat("Shortcut", "size", dx11_menu::shortcut::size);
		ReadColor("Shortcut", "color", dx11_menu::shortcut::color);

		dx11_menu::esp::menu_key = ReadInt("Menu", "key", dx11_menu::esp::menu_key);
	}
}

void draw_menu() {
	static bool initialized_style = false;
	if (!initialized_style) {
		SetupImGuiStyle();
		if (std::filesystem::exists(Config::config_file)) {
			Config::Load();
		}
		else {
			Config::Save();
		}
		initialized_style = true;
	}

	ImGui::SetNextWindowSize(ImVec2(1220, 1020), ImGuiCond_FirstUseEver);
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.08f, 0.08f, 0.08f, 0.94f));
	ImGui::Begin("VEX和平DMA", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);

	// 左侧导航栏布局
	static int active_tab = 0;

	ImGui::BeginChild("LeftNav", ImVec2(200, 0), true);

	// 标题
	ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[0]);
	ImGui::SetWindowFontScale(1.5f);
	ImGui::TextColored(ImVec4(0.00f, 0.90f, 1.00f, 1.0f), "VEX和平DMA");
	ImGui::SetWindowFontScale(1.0f);
	ImGui::PopFont();
	ImGui::Separator();
	ImGui::Spacing();

	const char* tabs[] = { "自动瞄准", "视觉透视", "物资载具", "雷达设置", "内存设置", "其他设置" };
	for (int i = 0; i < IM_ARRAYSIZE(tabs); i++) {
		if (ImGui::Selectable(tabs[i], active_tab == i, 0, ImVec2(0, 40))) {
			active_tab = i;
		}
	}

	ImGui::Spacing();
	ImGui::Separator();
	ImGui::Spacing();

	// ── 快捷键设置 ──
	{
		ImGui::TextColored(ImVec4(0.00f, 0.90f, 1.00f, 1.0f), "快捷键设置");
		ImGui::Separator();

		auto GetKeyLabel = [](int key) -> std::string {
			if (key == 0) return "未绑定";
			char keyName[128] = { 0 };
			UINT scanCode = MapVirtualKeyA(key, MAPVK_VK_TO_VSC);
			switch (key) {
			case VK_LEFT: case VK_UP: case VK_RIGHT: case VK_DOWN:
			case VK_PRIOR: case VK_NEXT: case VK_END: case VK_HOME:
			case VK_INSERT: case VK_DELETE: case VK_DIVIDE: case VK_NUMLOCK:
				scanCode |= 0x100; break;
			}
			if (GetKeyNameTextA(scanCode << 16, keyName, sizeof(keyName))) {
				return std::string(keyName);
			}
			return "Key " + std::to_string(key);
		};

		auto BindKeySidebar = [&](const char* label, int* key) {
			std::string keyLabel = GetKeyLabel(*key);
			char buf[128];
			sprintf_s(buf, "%s: %s", label, keyLabel.c_str());
			if (ImGui::Button(buf, ImVec2(ImGui::GetContentRegionAvail().x, 24))) {
				ImGui::OpenPopup(label);
			}
			if (ImGui::BeginPopup(label)) {
				ImGui::Text("按任意键 (ESC=清除)");
				for (int i = 1; i < 256; i++) {
					if (i == 1 || i == 2) continue;
					if (InputUtils::is_key_pressed(i)) {
						static float open_time = 0.0f;
						if (ImGui::IsWindowAppearing()) open_time = ImGui::GetTime();
						if (ImGui::GetTime() - open_time < 0.2f) continue;
						if (i == VK_ESCAPE) *key = 0;
						else *key = i;
						Config::Save();
						ImGui::CloseCurrentPopup();
					}
				}
				ImGui::EndPopup();
			}
		};

		BindKeySidebar("隐显菜单", &dx11_menu::shortcut::key_toggle_menu);
		BindKeySidebar("融合模式", &dx11_menu::shortcut::key_fusion);
		BindKeySidebar("自瞄启用", &dx11_menu::shortcut::key_aim);
		BindKeySidebar("药品显示", &dx11_menu::shortcut::key_meds);
		BindKeySidebar("载具显示", &dx11_menu::shortcut::key_vehicle);
		BindKeySidebar("显示枪械", &dx11_menu::shortcut::key_weapon);
		BindKeySidebar("菜单显隐", &dx11_menu::esp::menu_key);
	}

	ImGui::Spacing();
	ImGui::Separator();
	ImGui::Spacing();

	// ── 菜单显示/隐藏 ──
	if (ImGui::Button(dx11_menu::esp::show_menu ? "隐藏菜单" : "显示菜单", ImVec2(ImGui::GetContentRegionAvail().x, 28))) {
		dx11_menu::esp::show_menu = !dx11_menu::esp::show_menu;
	}

	ImGui::Spacing();
	ImGui::Separator();
	ImGui::Spacing();

	if (ImGui::Button("退出程序", ImVec2(ImGui::GetContentRegionAvail().x, 36))) {
		g_running = false;
	}

	ImGui::EndChild();

	ImGui::SameLine();

	// 右侧内容区
	ImGui::BeginChild("RightContent", ImVec2(0, 0), true);
	{
		ImDrawList* draw_list = ImGui::GetWindowDrawList();
		ImVec2 p_min = ImGui::GetWindowPos();
		ImVec2 p_max = ImVec2(p_min.x + ImGui::GetWindowWidth(), p_min.y + ImGui::GetWindowHeight());

		// 下雪动画逻辑
		if (dx11_menu::esp::snow_effect) {
			static struct Snowflake {
				float x, y;
				float speed;
				float size;
				float alpha;
			} snowflakes[100];
			static bool init_snow = false;

			if (!init_snow) {
				for (int i = 0; i < 100; i++) {
					snowflakes[i].x = (float)(rand() % (int)(p_max.x - p_min.x));
					snowflakes[i].y = (float)(rand() % (int)(p_max.y - p_min.y));
					snowflakes[i].speed = 1.0f + (float)(rand() % 100) / 50.0f;
					snowflakes[i].size = 2.0f + (float)(rand() % 100) / 50.0f;
					snowflakes[i].alpha = 0.5f + (float)(rand() % 50) / 100.0f;
				}
				init_snow = true;
			}

			float dt = ImGui::GetIO().DeltaTime;
			for (int i = 0; i < 100; i++) {
				snowflakes[i].y += snowflakes[i].speed * 60.0f * dt;
				if (snowflakes[i].y > p_max.y - p_min.y) {
					snowflakes[i].y = -10.0f;
					snowflakes[i].x = (float)(rand() % (int)(p_max.x - p_min.x));
				}

				draw_list->AddCircleFilled(
					ImVec2(p_min.x + snowflakes[i].x, p_min.y + snowflakes[i].y),
					snowflakes[i].size,
					IM_COL32(255, 255, 255, (int)(snowflakes[i].alpha * 255))
				);
			}
		}

		const char* text = "VEX和平DMA";
		float font_size = 60.0f; // 大号字体

		// 计算文字大小以居中
		ImVec2 text_size = ImGui::GetFont()->CalcTextSizeA(font_size, FLT_MAX, 0.0f, text);
		ImVec2 text_pos = ImVec2(
			p_min.x + (ImGui::GetWindowWidth() - text_size.x) * 0.5f,
			p_min.y + (ImGui::GetWindowHeight() - text_size.y) * 0.5f
		);

		draw_list->AddText(ImGui::GetFont(), font_size, text_pos, IM_COL32(255, 255, 255, 25), text);
	}

	if (active_tab == 0) { // 自动瞄准
		// 计算卡片尺寸
		float content_w = ImGui::GetContentRegionAvail().x;
		float content_h = ImGui::GetContentRegionAvail().y;
		float card_w = content_w * 0.5f - 8.0f;
		float card_h = content_h * 0.5f - 8.0f;

		auto ColorItem = [](const char* label, float* col) {
			ImGui::Text("%s", label);
			ImGui::SameLine(ImGui::GetContentRegionAvail().x - 30); // 靠右
			std::string id = std::string("##") + label;
			ImGui::ColorEdit4(id.c_str(), col, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoLabel);
			};

		// 按键设置辅助函数
		auto KeyBind = [](const char* label, int* key) {
			ImGui::PushID(label);
			char buf[32];
			if (*key == 0) sprintf_s(buf, "无");
			else {
				char keyName[128] = { 0 };
				if (GetKeyNameTextA(MapVirtualKeyA(*key, MAPVK_VK_TO_VSC) << 16, keyName, sizeof(keyName))) {
					sprintf_s(buf, "%s", keyName);
				}
				else {
					sprintf_s(buf, "Key %d", *key);
				}
			}

			ImGui::Text("%s:", label);
			ImGui::SameLine();
			if (ImGui::Button(buf, ImVec2(80, 0))) {
				ImGui::OpenPopup("bind_popup");
			}

			if (ImGui::BeginPopup("bind_popup")) {
				ImGui::Text("按下任意键设置 (ESC取消/清除)");
				for (int i = 1; i < 256; i++) {

					if (InputUtils::is_key_pressed(i)) {
						static float open_time = 0.0f;
						if (ImGui::IsWindowAppearing()) {
							open_time = ImGui::GetTime();
						}

						if (ImGui::GetTime() - open_time < 0.2f) {
							continue;
						}

						if (i == VK_ESCAPE) *key = 0;
						else *key = i;
						Config::Save(); // 保存按键设置
						ImGui::CloseCurrentPopup();
					}
				}
				ImGui::EndPopup();
			}
			ImGui::PopID(); // 恢复 ID 栈
			};


		ImGui::BeginChild("BasicAim", ImVec2(card_w, card_h), true);
		ImGui::Text("基础自瞄");
		ImGui::Text("%.1f", ImGui::GetIO().Framerate);
		ImGui::Separator();
		if (ToggleButton("启用自瞄", &dx11_menu::aim::enable)) Config::Save();
		if (ToggleButton("自动压枪", &dx11_menu::aim::no_recoil)) Config::Save();
		if (ToggleButton("显示范围", &dx11_menu::aim::show_fov)) Config::Save();
		ColorItem("范围颜色", dx11_menu::esp::color_fov);
		if (ImGui::IsItemDeactivatedAfterEdit()) Config::Save();
		// 自瞄预判暂时无法使用
		ImGui::BeginDisabled();
		ToggleButton("自瞄预判(不可用)", &dx11_menu::aim::prediction);
		ImGui::EndDisabled();
		if (ToggleButton("倒地不锁", &dx11_menu::aim::ignore_groggy)) Config::Save();
		if (ToggleButton("不锁人机", &dx11_menu::aim::ignore_ai)) Config::Save();
		if (ToggleButton("可视判断", &dx11_menu::aim::vis_check)) Config::Save();

		// ── 自瞄部位选择 ──
		{
			const char* bone_modes[] = { "仅头部", "漏打扫描", "固定部位", "随机部位" };
			if (ImGui::Combo("自瞄部位", &dx11_menu::aim::aim_bone_mode, bone_modes, IM_ARRAYSIZE(bone_modes)))
				Config::Save();

			if (dx11_menu::aim::aim_bone_mode == 2) {
				const char* bone_names[] = { "头部(6)", "脖子(65)", "胸部(5)", "腹部(4)", "腰部(3)", "大腿(2)", "骨盆(1)" };
				int bone_ids[] = { 6, 65, 5, 4, 3, 2, 1 };
				int selected_idx = 0;
				for (int i = 0; i < IM_ARRAYSIZE(bone_ids); i++) {
					if (bone_ids[i] == dx11_menu::aim::aim_bone_id) { selected_idx = i; break; }
				}
				if (ImGui::Combo("固定部位", &selected_idx, bone_names, IM_ARRAYSIZE(bone_names))) {
					dx11_menu::aim::aim_bone_id = bone_ids[selected_idx];
					Config::Save();
				}
			}

			ImGui::Spacing();
			if (ToggleButton("模拟真人", &dx11_menu::aim::humanize)) Config::Save();
			if (dx11_menu::aim::humanize) {
				ImGui::TextColored(ImVec4(0.5f, 0.8f, 0.5f, 1.0f), "  延迟+抖动+过甩");
			}
		}
		ImGui::EndChild();

		ImGui::SameLine();


		ImGui::BeginChild("OtherAim", ImVec2(card_w, card_h), true);
		ImGui::Text("其他自瞄");
		ImGui::Separator();
		if (ToggleButton("弓箭不锁", &dx11_menu::aim::ignore_bow)) Config::Save();
		if (ToggleButton("空仓不锁", &dx11_menu::aim::ignore_empty)) Config::Save();
		if (ToggleButton("持续锁定", &dx11_menu::aim::auto_lock)) Config::Save();
		if (ToggleButton("50米增强", &dx11_menu::aim::range_boost)) Config::Save();
		if (ToggleButton("自瞄射线", &dx11_menu::aim::draw_line)) Config::Save();
		ColorItem("自瞄射线颜色", dx11_menu::esp::color_aim_line);
		if (ImGui::IsItemDeactivatedAfterEdit()) Config::Save();
		if (ToggleButton("开火自瞄", &dx11_menu::aim::fire_aim)) Config::Save();
		if (ToggleButton("动态范围", &dx11_menu::aim::dynamic_fov)) Config::Save();
		if (ToggleButton("瞄准点显示", &dx11_menu::aim::draw_target_bone)) Config::Save();
		ColorItem("瞄准点颜色", dx11_menu::esp::color_target_bone);
		if (ImGui::IsItemDeactivatedAfterEdit()) Config::Save();
		ImGui::EndChild();

		ImGui::BeginChild("AimParams", ImVec2(card_w, card_h), true);
		ImGui::Text("自瞄参数");
		ImGui::Separator();
		if (ImGui::SliderFloat("自瞄范围", &dx11_menu::aim::fov, 10.0f, 1000.0f, "%.1f")) Config::Save();
		if (ImGui::SliderFloat("自瞄平滑", &dx11_menu::aim::smooth, 0.01f, 20.0f, "%.2f")) Config::Save();
		if (ImGui::SliderFloat("自瞄距离", &dx11_menu::aim::dist, 0.0f, 1000.0f, "%.0f M")) Config::Save();
		if (ImGui::SliderFloat("自瞄X", &dx11_menu::aim::x, 0.0f, 1.0f, "%.2f")) Config::Save();
		if (ImGui::SliderFloat("自瞄Y", &dx11_menu::aim::y, 0.0f, 1.0f, "%.2f")) Config::Save();
		KeyBind("自瞄按键#1", &dx11_menu::aim::key1);
		KeyBind("自瞄按键#2", &dx11_menu::aim::key2);
		ImGui::EndChild();

		ImGui::SameLine();


		ImGui::BeginChild("TriggerBot", ImVec2(card_w, card_h), true);
		ImGui::Text("扳机基础");
		ImGui::Separator();
		if (ToggleButton("启用扳机", &dx11_menu::trigger::enable)) Config::Save();
		if (ImGui::SliderFloat("扳机范围", &dx11_menu::trigger::fov, 1.0f, 1000.0f, "%.1f")) Config::Save();
		if (ImGui::SliderInt("扳机延迟 (ms)", &dx11_menu::trigger::delay, 0, 1000)) Config::Save();
		if (ToggleButton("显示扳机范围", &dx11_menu::trigger::show_fov)) Config::Save();
		KeyBind("扳机按键1", &dx11_menu::trigger::key1);
		KeyBind("扳机按键2", &dx11_menu::trigger::key2);
		if (ToggleButton("扳机忽略倒地", &dx11_menu::trigger::ignore_groggy)) Config::Save();
		if (ToggleButton("扳机忽略人机", &dx11_menu::trigger::ignore_ai)) Config::Save();
		if (ToggleButton("扳机动态范围", &dx11_menu::trigger::dynamic_fov)) Config::Save();
		if (ToggleButton("扳机自瞄", &dx11_menu::trigger::aim_sync)) Config::Save();
		if (ImGui::SliderFloat("扳机自瞄速度", &dx11_menu::trigger::aim_smooth, 1.0f, 20.0f, "%.1f")) Config::Save();
		if (ImGui::SliderFloat("扳机自瞄范围", &dx11_menu::trigger::aim_fov, 10.0f, 1000.0f, "%.1f")) Config::Save();
		if (ToggleButton("显示扳机自瞄范围", &dx11_menu::trigger::show_aim_fov)) Config::Save();
		ImGui::EndChild();
	}
	else if (active_tab == 1) { // 视觉透视

		float content_w = ImGui::GetContentRegionAvail().x;
		float content_h = ImGui::GetContentRegionAvail().y;
		float card_w = content_w * 0.5f - 8.0f;
		float card_h = content_h * 0.5f - 8.0f;

		ImGui::BeginChild("BasicConfig", ImVec2(card_w, card_h), true);
		ImGui::Text("基础透视");
		ImGui::Separator();
		if (ToggleButton("显示玩家", &dx11_menu::esp::player)) Config::Save();
		if (ToggleButton("显示骨骼", &dx11_menu::esp::player_bone)) Config::Save();
		if (dx11_menu::esp::player_bone) {
			ImGui::SameLine();
			if (ToggleButton("ID", &dx11_menu::esp::player_bone_id)) Config::Save();
		}
		if (ToggleButton("显示方框", &dx11_menu::esp::player_box)) Config::Save();
		if (ToggleButton("显示射线", &dx11_menu::esp::player_line)) Config::Save();
		if (ToggleButton("倒地判断", &dx11_menu::esp::player_groggy)) Config::Save();
		if (ToggleButton("可视判断", &dx11_menu::esp::player_vis_check)) Config::Save();
		if (ToggleButton("被瞄警告", &dx11_menu::esp::player_aim_warning)) Config::Save();
		if (ToggleButton("信息预警", &dx11_menu::esp::player_warning)) Config::Save();
		if (ToggleButton("视场外箭头", &dx11_menu::esp::player_out_of_fov_arrow)) Config::Save();
		ImGui::SameLine();
		if (ImGui::Button("设置##arrow_setting")) {
			ImGui::OpenPopup("视场外箭头设置");
		}
		if (ImGui::BeginPopup("视场外箭头设置")) {
			if (ImGui::SliderFloat("箭头半径", &dx11_menu::esp::player_out_of_fov_arrow_radius, 50.0f, 500.0f, "%.0f px")) Config::Save();
			if (ImGui::SliderFloat("箭头大小", &dx11_menu::esp::player_out_of_fov_arrow_size, 5.0f, 30.0f, "%.0f px")) Config::Save();
			ImGui::EndPopup();
		}

		ImGui::SameLine();
		if (ImGui::Button("设置##info_warning_pos")) {
			ImGui::OpenPopup("信息预警位置设置");
		}
		if (ImGui::BeginPopup("信息预警位置设置")) {
			if (ImGui::SliderFloat("水平位置 (X)", &dx11_menu::esp::info_warning_x, 0.0f, 1.0f, "%.2f")) Config::Save();
			if (ImGui::SliderFloat("垂直位置 (Y)", &dx11_menu::esp::info_warning_y, 0.0f, 1000.0f, "%.0f px")) Config::Save();
			ImGui::EndPopup();
		}

		if (ToggleButton("过滤本人", &dx11_menu::esp::player_ignore_me)) Config::Save();
		if (ToggleButton("过滤队友", &dx11_menu::esp::player_ignore_team)) Config::Save();
		ImGui::EndChild();

		ImGui::SameLine();

		ImGui::BeginChild("PlayerInfo", ImVec2(card_w, card_h), true);
		ImGui::Text("玩家信息");
		ImGui::Separator();
		if (ToggleButton("显示名称", &dx11_menu::esp::player_name)) Config::Save();
		if (ToggleButton("显示手持", &dx11_menu::esp::player_weapon)) Config::Save();
		if (ToggleButton("显示血量", &dx11_menu::esp::player_health)) Config::Save();
		ToggleButton("显示能量", &dx11_menu::esp::player_energy);
		ToggleButton("显示击杀", &dx11_menu::esp::player_kills);
		ToggleButton("显示距离", &dx11_menu::esp::player_dis);
		ToggleButton("显示队伍", &dx11_menu::esp::player_team);
		ToggleButton("显示动作", &dx11_menu::esp::player_action);
		ToggleButton("显示巡查", &dx11_menu::esp::player_permission);
		ImGui::EndChild();


		ImGui::BeginChild("ColorSettings", ImVec2(card_w, card_h), true);
		ImGui::Text("颜色设置");
		ImGui::Separator();


		auto ColorItem = [](const char* label, float* col) {
			ImGui::Text("%s", label);
			ImGui::SameLine(ImGui::GetContentRegionAvail().x - 30); // 靠右
			std::string id = std::string("##") + label;
			if (ImGui::ColorEdit4(id.c_str(), col, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoLabel)) {
				Config::Save();
			}
			};

		ColorItem("方框颜色", dx11_menu::esp::color_box);
		ColorItem("骨骼可视颜色", dx11_menu::esp::color_bone_vis);
		ColorItem("骨骼不可视颜色", dx11_menu::esp::color_bone_invis);
		ColorItem("射线颜色", dx11_menu::esp::color_line);
		ColorItem("名称颜色", dx11_menu::esp::color_name);
		ColorItem("手持颜色", dx11_menu::esp::color_weapon);
		ColorItem("能量颜色", dx11_menu::esp::color_energy);
		ColorItem("队伍颜色", dx11_menu::esp::color_team_id);
		ColorItem("距离颜色", dx11_menu::esp::color_distance);
		ColorItem("击杀颜色", dx11_menu::esp::color_kills);
		ColorItem("动作颜色", dx11_menu::esp::color_action);
		ColorItem("被瞄警告颜色", dx11_menu::esp::color_aim_warning);
		ColorItem("信息预警颜色", dx11_menu::esp::color_info_warning);
		ColorItem("视场外箭头", dx11_menu::esp::color_player_out_of_fov_arrow);

		ImGui::EndChild();

		ImGui::SameLine();


		ImGui::BeginChild("OtherSettings", ImVec2(card_w, card_h), true);
		ImGui::Text("其他设置");
		ImGui::Separator();

		ImGui::Text("线粗设置:");
		if (ImGui::SliderFloat("方框线粗", &dx11_menu::esp::width_box, 0.1f, 5.0f)) Config::Save();
		if (ImGui::SliderFloat("骨骼线粗", &dx11_menu::esp::width_bone, 0.1f, 5.0f)) Config::Save();
		if (ImGui::SliderFloat("射线线粗", &dx11_menu::esp::width_line, 0.1f, 5.0f)) Config::Save();

		ImGui::Separator();
		ImGui::Text("字体大小:");
		if (ImGui::SliderFloat("名称大小", &dx11_menu::esp::size_name, 10.0f, 30.0f)) Config::Save();
		if (ImGui::SliderFloat("手持大小", &dx11_menu::esp::size_weapon, 10.0f, 30.0f)) Config::Save();
		if (ImGui::SliderFloat("能量大小", &dx11_menu::esp::size_energy, 10.0f, 30.0f)) Config::Save();
		if (ImGui::SliderFloat("队伍大小", &dx11_menu::esp::size_team_id, 10.0f, 30.0f)) Config::Save();
		if (ImGui::SliderFloat("距离大小", &dx11_menu::esp::size_distance, 10.0f, 30.0f)) Config::Save();
		if (ImGui::SliderFloat("击杀大小", &dx11_menu::esp::size_kills, 10.0f, 30.0f)) Config::Save();
		if (ImGui::SliderFloat("动作大小", &dx11_menu::esp::size_action, 10.0f, 30.0f)) Config::Save();
		if (ImGui::SliderFloat("被瞄警告大小", &dx11_menu::esp::size_aim_warning, 10.0f, 40.0f)) Config::Save();
		if (ImGui::SliderFloat("信息预警大小", &dx11_menu::esp::size_info_warning, 10.0f, 40.0f)) Config::Save();

		ImGui::Separator();
		ImGui::Text("其他:");
		if (ImGui::Combo("射线位置", &dx11_menu::esp::line_pos, "顶部\0中心\0底部\0")) Config::Save();
		if (ImGui::Combo("血条样式", &dx11_menu::esp::player_health_style, "渐变\0跟随血量\0科技风\0")) Config::Save();
		if (ImGui::Combo("骨骼样式", &dx11_menu::esp::player_bone_style, "无头骨\0有头骨\0")) Config::Save();

		ImGui::EndChild();
	}
	else if (active_tab == 2) { // 物资载具
		if (ImGui::BeginTabBar("ItemVehicleTabs")) {
			// --- 物资页 ---
			if (ImGui::BeginTabItem("物资")) {
				ImGui::Columns(2, "ItemColumns", false);
				ImGui::SetColumnWidth(0, 260);

				// 左侧设置
				ImGui::Text("物资设置");
				ImGui::Separator();
				if (ToggleButton("物资总开关", &dx11_menu::esp::item)) Config::Save();
				if (ToggleButton("禁止叠加", &dx11_menu::esp::item_collapse)) Config::Save();
				if (ToggleButton("显示空投", &dx11_menu::esp::item_airdrop)) Config::Save();
				if (ToggleButton("显示手雷", &dx11_menu::esp::item_grenade)) Config::Save();
				if (ToggleButton("显示药品", &dx11_menu::esp::item_meds)) Config::Save();
				if (ImGui::SliderFloat("物资大小", &dx11_menu::esp::item_size, 10.0f, 30.0f)) Config::Save();

				ImGui::NextColumn();

				// 右侧列表
				ImGui::Text("物资列表");
				ImGui::SameLine();
				if (ImGui::InputText("搜索##Item", dx11_menu::esp::item_search_buf, 64)) Config::Save();

				// 分类筛选
				if (ImGui::Combo("分类筛选", &dx11_menu::esp::item_filter_type, "全部\0武器\0配件\0装备\0药品\0弹药\0空投/盒子\0其他\0")) Config::Save();

				// 初始化
				if (dx11_menu::esp::item_filter_map.empty()) {
					for (auto& [key, name] : ItemMap) {
						dx11_menu::esp::item_filter_map[key] = true;
					}
				}

				ImGui::BeginChild("ItemList", ImVec2(0, 0), true);
				for (auto& [key, name] : ItemMap) {
					// 搜索过滤
					if (dx11_menu::esp::item_search_buf[0] != '\0') {
						if (name.find(dx11_menu::esp::item_search_buf) == std::string::npos) continue;
					}

					// 分类过滤
					if (dx11_menu::esp::item_filter_type != 0) {
						int cat = GetItemCategory(name);
						if (cat != dx11_menu::esp::item_filter_type) continue;
					}

					bool enabled = dx11_menu::esp::item_filter_map[key];
					std::string label = name + "##" + key;
					if (ImGui::Checkbox(label.c_str(), &enabled)) {
						dx11_menu::esp::item_filter_map[key] = enabled;
					}
				}
				ImGui::EndChild();

				ImGui::Columns(1);
				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("载具")) {
				ImGui::Columns(2, "VehicleColumns", false);
				ImGui::SetColumnWidth(0, 350); // 左侧稍微宽一点因为有颜色选择器

				ImGui::BeginChild("VehicleLeft", ImVec2(0, 0), false);

				ToggleButton("载具总开关", &dx11_menu::esp::vehicle);
				ToggleButton("显示名称", &dx11_menu::esp::vehicle_name);
				ToggleButton("显示血量", &dx11_menu::esp::vehicle_hp);
				ToggleButton("显示油量", &dx11_menu::esp::vehicle_fuel);
				ToggleButton("显示轮胎", &dx11_menu::esp::vehicle_tire);
				ToggleButton("显示距离", &dx11_menu::esp::vehicle_dis);

				ImGui::Separator();
				ImGui::Text("样式设置");
				if (ImGui::Combo("轮胎样式", &dx11_menu::esp::vehicle_tire_style, "文字\0图形\0")) Config::Save();

				ImGui::Separator();
				ImGui::Text("大小设置");
				if (ImGui::SliderFloat("名称大小", &dx11_menu::esp::size_vehicle_name, 10.0f, 30.0f)) Config::Save();
				if (ImGui::SliderFloat("血量大小", &dx11_menu::esp::size_vehicle_hp, 10.0f, 30.0f)) Config::Save();
				if (ImGui::SliderFloat("油量大小", &dx11_menu::esp::size_vehicle_fuel, 10.0f, 30.0f)) Config::Save();
				if (ImGui::SliderFloat("轮胎大小", &dx11_menu::esp::size_vehicle_tire, 10.0f, 30.0f)) Config::Save();

				ImGui::Separator();
				ImGui::Text("颜色设置");
				auto ColorItem = [](const char* label, float* col) {
					ImGui::Text("%s", label);
					ImGui::SameLine(ImGui::GetContentRegionAvail().x - 30);
					std::string id = std::string("##") + label;
					if (ImGui::ColorEdit4(id.c_str(), col, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoLabel)) {
						Config::Save();
					}
					};
				ColorItem("名称颜色", dx11_menu::esp::color_vehicle_name);
				ColorItem("血量颜色", dx11_menu::esp::color_vehicle_hp);
				ColorItem("油量颜色", dx11_menu::esp::color_vehicle_fuel);
				ColorItem("轮胎颜色", dx11_menu::esp::color_vehicle_tire);

				ImGui::EndChild();

				ImGui::NextColumn();

				// 右侧列表
				ImGui::Text("载具列表");
				ImGui::SameLine();
				if (ImGui::InputText("搜索##Vehicle", dx11_menu::esp::vehicle_search_buf, 64)) Config::Save();

				// 分类筛选
				if (ImGui::Combo("分类筛选", &dx11_menu::esp::vehicle_filter_type, "全部\0汽车\0摩托\0船\0其他\0")) Config::Save();

				if (dx11_menu::esp::vehicle_filter_map.empty()) {
					for (auto& [key, name] : VehicleMap) {
						dx11_menu::esp::vehicle_filter_map[key] = true;
					}
				}

				ImGui::BeginChild("VehicleList", ImVec2(0, 0), true);
				for (auto& [key, name] : VehicleMap) {
					if (dx11_menu::esp::vehicle_search_buf[0] != '\0') {
						if (name.find(dx11_menu::esp::vehicle_search_buf) == std::string::npos) continue;
					}

					// 分类过滤
					if (dx11_menu::esp::vehicle_filter_type != 0) {
						int cat = GetVehicleCategory(name);
						if (cat != dx11_menu::esp::vehicle_filter_type) continue;
					}

					bool enabled = dx11_menu::esp::vehicle_filter_map[key];
					std::string label = name + "##" + key;
					if (ImGui::Checkbox(label.c_str(), &enabled)) {
						dx11_menu::esp::vehicle_filter_map[key] = enabled;
					}
				}
				ImGui::EndChild();

				ImGui::Columns(1);
				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();
		}
	}
	else if (active_tab == 3) { // 雷达设置
		ImGui::Text("雷达设置");
		ImGui::Separator();
		if (ToggleButton("开启雷达", &dx11_menu::esp::radar)) Config::Save();
		ImGui::Combo("雷达样式", &dx11_menu::esp::radar_style, "军事\0电竞\0");
		if (ImGui::IsItemDeactivatedAfterEdit()) Config::Save();
		if (ToggleButton("雷达_名字", &dx11_menu::esp::radar_name)) Config::Save();
		if (ToggleButton("雷达_载具", &dx11_menu::esp::radar_vehicle)) Config::Save();
		if (ToggleButton("雷达_距离", &dx11_menu::esp::radar_dis)) Config::Save();
		if (ToggleButton("雷达_人机", &dx11_menu::esp::radar_ai)) Config::Save();
		if (ToggleButton("雷达_物资", &dx11_menu::esp::radar_item)) Config::Save();

		ImGui::SliderFloat("雷达X", &dx11_menu::esp::radar_x, 0.0f, 2560.0f);
		if (ImGui::IsItemDeactivatedAfterEdit()) Config::Save();
		ImGui::SliderFloat("雷达Y", &dx11_menu::esp::radar_y, 0.0f, 1440.0f);
		if (ImGui::IsItemDeactivatedAfterEdit()) Config::Save();
		ImGui::SliderFloat("雷达大小", &dx11_menu::esp::radar_size, 100.0f, 500.0f);
		if (ImGui::IsItemDeactivatedAfterEdit()) Config::Save();
		ImGui::SliderFloat("雷达范围", &dx11_menu::esp::radar_range, 50.0f, 1000.0f);
		if (ImGui::IsItemDeactivatedAfterEdit()) Config::Save();
	}
	else if (active_tab == 4) { // 内存设置
		ImGui::Text("内存功能(高风险)");
		ImGui::Separator();
		if (ToggleButton("静默自瞄", &dx11_menu::aim::silent_aim)) Config::Save();
		ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "注意: 内存功能极易封号，请谨慎使用！");
	}
	else if (active_tab == 5) { // 其他设置
		ImGui::Text("其他功能");
		ImGui::Separator();
		ImGui::Text("配置管理");
		if (ImGui::Button("保存配置")) Config::Save();
		ImGui::SameLine();
		if (ImGui::Button("读取配置")) Config::Load();
		ImGui::Separator();
		if (ToggleButton("显示所有类名", &dx11_menu::esp::show_all_classes)) Config::Save();
		if (ToggleButton("绘制PhysX模型", &dx11_menu::esp::show_physx_models)) Config::Save();
		if (ToggleButton("地铁模式", &dx11_menu::esp::metro_mode)) Config::Save();
		if (ToggleButton("地铁怪物", &dx11_menu::esp::metro_monster)) Config::Save();
		if (ToggleButton("下雪动画", &dx11_menu::esp::snow_effect)) Config::Save();


		ImGui::Separator();
		ImGui::Text("盒子连接");
		ImGui::Separator();

		if (ImGui::Combo("连接方式", &g_box_type, "KMBOX网络版\0KMBOX COM串口\0Lurker\0MoBox(DLL)\0")) Config::Save();

		// ═══ PUBG_DMA 风格: 统一连接状态反馈 ═══
		static std::string status_msg;
		static double status_until = 0.0;
		auto show_status = [&](const char* msg, bool success) {
			status_msg = msg;
			status_until = ImGui::GetTime() + 3.0; // 消息显示3秒
			aim_log("[盒子] {} (connected={} type={})", msg, g_box_connected, g_box_type);
		};

		// 连接状态指示器（始终可见）
		ImGui::AlignTextToFramePadding();
		ImGui::Text("状态: ");
		ImGui::SameLine();
		if (g_box_connected) {
			ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "● 已连接");
		} else {
			ImGui::TextColored(ImVec4(1.0f, 0.2f, 0.2f, 1.0f), "● 未连接");
		}

		// 显示连接结果消息（Toast风格）
		if (ImGui::GetTime() < status_until && !status_msg.empty()) {
			ImVec4 msg_color = g_box_connected ? ImVec4(0.2f, 1.0f, 0.2f, 1.0f) : ImVec4(1.0f, 0.5f, 0.2f, 1.0f);
			ImGui::TextColored(msg_color, "> %s", status_msg.c_str());
		}

		ImGui::Spacing();

		if (g_box_type == 0) { // KMBOX网络版 (UDP)
			if (ImGui::InputText("IP地址", g_ip, sizeof(g_ip))) Config::Save();
			if (ImGui::InputText("端口", g_port, sizeof(g_port))) Config::Save();
			if (ImGui::InputText("UUID", g_uuid, sizeof(g_uuid))) Config::Save();

			if (ImGui::Button(g_box_connected ? "断开连接" : "开始连接", ImVec2(120, 30))) {
				if (g_box_connected) {
					kmNet_reboot();
					g_box_connected = false;
					show_status("已断开KmBoxNet连接", false);
				} else {
					if (kmNet_init(g_ip, g_port, g_uuid) == 0) {
						g_box_connected = true;
						show_status("KmBoxNet 连接成功!", true);
					} else {
						g_box_connected = false;
						show_status("KmBoxNet 连接失败，请检查IP/端口/UUID", false);
					}
				}
			}
			ImGui::SameLine();
			if (g_box_connected) {
				if (ImGui::Button("测试移动", ImVec2(80, 30)))
					kmNet_mouse_move_auto(0, 100, 1);
			}
		}
		else if (g_box_type == 1) { // KMBOX COM串口
			static int kmbox_com = 1;
			if (ImGui::InputInt("COM端口号", &kmbox_com)) Config::Save();
			if (ImGui::Button(g_box_connected ? "断开连接" : "开始连接", ImVec2(120, 30))) {
				if (g_box_connected) {
					KmBox::Close();
					g_box_connected = false;
					show_status("已断开KmBox COM连接", false);
				} else {
					if (KmBox::Init(kmbox_com)) {
						g_box_connected = true;
						show_status("KmBox COM 连接成功!", true);
					} else {
						g_box_connected = false;
						show_status("KmBox COM 连接失败，请检查COM端口号", false);
					}
				}
			}
			ImGui::SameLine();
			if (g_box_connected) {
				if (ImGui::Button("测试移动", ImVec2(80, 30)))
					KmBox::Move(0, 100);
			}
		}
		else if (g_box_type == 2) { // Lurker
			static int lurker_com = 1;
			if (ImGui::InputInt("COM端口号", &lurker_com)) Config::Save();
			if (ImGui::Button(g_box_connected ? "断开连接" : "开始连接", ImVec2(120, 30))) {
				if (g_box_connected) {
					Lurker::Close();
					g_box_connected = false;
					show_status("已断开Lurker连接", false);
				} else {
					if (Lurker::Init(lurker_com)) {
						g_box_connected = true;
						show_status("Lurker 连接成功!", true);
					} else {
						g_box_connected = false;
						show_status("Lurker 连接失败，请检查COM端口号", false);
					}
				}
			}
			ImGui::SameLine();
			if (g_box_connected) {
				if (ImGui::Button("测试移动", ImVec2(80, 30)))
					Lurker::Move(0, 100);
			}
		}
		else if (g_box_type == 3) { // MoBox (DLL)
			static int mobox_com = 1;
			if (ImGui::InputInt("COM端口号", &mobox_com)) Config::Save();
			if (ImGui::Button(g_box_connected ? "断开连接" : "开始连接", ImVec2(120, 30))) {
				if (g_box_connected) {
					MoBox::Close();
					g_box_connected = false;
					show_status("已断开MoBox连接", false);
				} else {
					if (MoBox::Init(mobox_com)) {
						g_box_connected = true;
						show_status("MoBox 连接成功!", true);
					} else {
						g_box_connected = false;
						show_status("MoBox 连接失败，请检查COM端口号", false);
					}
				}
			}
			ImGui::SameLine();
			if (g_box_connected) {
				if (ImGui::Button("测试移动", ImVec2(80, 30)))
					MoBox::Move(0, 100);
			}
		}
	}

	ImVec2 window_size = ImGui::GetWindowSize();
	ImVec2 cursor_pos = ImGui::GetCursorPos();

	ImGui::SetCursorPos(ImVec2(window_size.x - 150, window_size.y - 30));

	static float scale = 1.0f;
	ImGui::SetNextItemWidth(100);
	if (ImGui::SliderFloat("##MenuScale", &scale, 0.5f, 2.0f, "缩放: %.1f")) {
		ImGui::GetIO().FontGlobalScale = scale;
	}

	ImGui::EndChild();
	ImGui::End();
	ImGui::PopStyleColor();
};

void draw_vehicle(ImDrawList* draw_list, VMMDLL_SCATTER_HANDLE hs_esp, FCameraCacheEntry& CameraCacheEntry) {
	if (!dx11_menu::esp::vehicle) {
		return;
	}
	auto vehicle_list = g_vehicleList.load(std::memory_order_acquire);
	if (!vehicle_list) {
		return;
	}

	auto my_player = g_my_player.load(std::memory_order_acquire);

	static auto last_time = std::chrono::steady_clock::now();
	auto now = std::chrono::steady_clock::now();
	float delta_time = std::chrono::duration<float>(now - last_time).count();

	float prediction_time = 0.0f;

	for (auto& vehicle : *vehicle_list) {
		vehicle.m_RootComponent.scatter_ComponentToWorld(hs_esp);
	}
	dma::Scatter_ExecuteRead(hs_esp);

	for (auto& vehicle : *vehicle_list) {
		if (dx11_menu::esp::player_ignore_me && my_player) {
			if (vehicle.m_RootComponent.m_ComponentToWorld.Translation.GetDistanceToInMeters(my_player->m_Mesh.m_ComponentToWorld.Translation) < 2.0f) {
				continue;
			}
		}

		auto vehicle_pos = vehicle.m_RootComponent.m_ComponentToWorld.Translation;

		// Apply prediction
		if (prediction_time > 0.0f) {
			vehicle_pos.X += vehicle.m_LinearVelocity.X * prediction_time;
			vehicle_pos.Y += vehicle.m_LinearVelocity.Y * prediction_time;
			vehicle_pos.Z += vehicle.m_LinearVelocity.Z * prediction_time;
		}

		FVector2D vehicle_pos_2d{};
		auto ret = m_Engine.WorldToScreen1(vehicle_pos, CameraCacheEntry, vehicle_pos_2d);

		if (!ret) {
			continue;
		}

		if (vehicle_pos_2d.X < 0 || vehicle_pos_2d.Y < 0) {
			continue;
		}

		if (vehicle_pos_2d.X > m_Engine.m_rect.w || vehicle_pos_2d.Y > m_Engine.m_rect.h) {
			continue;
		}

		std::string vehicle_name_str;
		if (!vehicle.CachedName.empty()) {
			vehicle_name_str = vehicle.CachedName;
		}
		else {
			vehicle_name_str = vehicle.m_FName.ToString();
		}

		// 载具过滤
		if (!dx11_menu::esp::vehicle_filter_map.empty()) {
			if (dx11_menu::esp::vehicle_filter_map.find(vehicle_name_str) != dx11_menu::esp::vehicle_filter_map.end()) {
				if (!dx11_menu::esp::vehicle_filter_map[vehicle_name_str]) continue;
			}
		}

		auto cn_name = GetItemName(vehicle_name_str);
		if (!cn_name.empty()) {
			vehicle_name_str = cn_name;
		}

		float current_x = vehicle_pos_2d.X;
		float current_y = vehicle_pos_2d.Y;

		// 收集所有需要绘制的片段
		struct TextSegment {
			std::string text;
			ImU32 color;
			float size;
			float width;
		};
		std::vector<TextSegment> segments;

		// 名称 & 距离
		if (dx11_menu::esp::vehicle_name || dx11_menu::esp::vehicle_dis) {
			std::string str = "";
			if (dx11_menu::esp::vehicle_name) str += vehicle_name_str;
			if (dx11_menu::esp::vehicle_dis) {
				auto vehicle_dis = (int)CameraCacheEntry.POV.Location.GetDistanceToInMeters(vehicle.m_RootComponent.m_ComponentToWorld.Translation);
				str += std::format(" [{}M]", vehicle_dis);
			}
			float size = dx11_menu::esp::size_vehicle_name;
			ImVec2 textSize = ImGui::GetFont()->CalcTextSizeA(size, FLT_MAX, 0.0f, str.c_str());
			segments.push_back({ str, ImGui::ColorConvertFloat4ToU32(*(ImVec4*)dx11_menu::esp::color_vehicle_name), size, textSize.x });
		}

		// 血量
		if (dx11_menu::esp::vehicle_hp) {
			float hp_percent = 0.0f;
			if (vehicle.m_VehicleCommon.m_HPMax > 0.0f) {
				hp_percent = (vehicle.m_VehicleCommon.m_HP / vehicle.m_VehicleCommon.m_HPMax) * 100.0f;
			}
			std::string str = std::format(" 血:{:.0f}%", hp_percent);
			float size = dx11_menu::esp::size_vehicle_hp;
			ImVec2 textSize = ImGui::GetFont()->CalcTextSizeA(size, FLT_MAX, 0.0f, str.c_str());
			segments.push_back({ str, ImGui::ColorConvertFloat4ToU32(*(ImVec4*)dx11_menu::esp::color_vehicle_hp), size, textSize.x });
		}

		//  油量
		if (dx11_menu::esp::vehicle_fuel) {
			float fuel_percent = 0.0f;
			if (vehicle.m_VehicleCommon.m_FuelMax > 0.0f) {
				fuel_percent = (vehicle.m_VehicleCommon.m_Fuel / vehicle.m_VehicleCommon.m_FuelMax) * 100.0f;
			}
			std::string str = std::format(" 油:{:.0f}%", fuel_percent);
			float size = dx11_menu::esp::size_vehicle_fuel;
			ImVec2 textSize = ImGui::GetFont()->CalcTextSizeA(size, FLT_MAX, 0.0f, str.c_str());
			segments.push_back({ str, ImGui::ColorConvertFloat4ToU32(*(ImVec4*)dx11_menu::esp::color_vehicle_fuel), size, textSize.x });
		}

		// 轮胎
		if (dx11_menu::esp::vehicle_tire) {
			if (vehicle_name_str.find("装甲车") == std::string::npos &&
				vehicle_name_str.find("快艇") == std::string::npos &&
				vehicle_name_str.find("水上摩托") == std::string::npos &&
				vehicle_name_str.find("碰碰车") == std::string::npos) {

				std::string str = " 胎:";
				if (dx11_menu::esp::vehicle_tire_style == 0) { // 文字
					for (float hp : vehicle.m_VehicleCommon.m_WheelsCurrentHP) {
						str += std::format("{:.0f} ", hp);
					}
				}
				else { // 图形
					for (float hp : vehicle.m_VehicleCommon.m_WheelsCurrentHP) {
						str += (hp > 0.0f) ? "O" : "X";
					}
				}
				float size = dx11_menu::esp::size_vehicle_tire;
				ImVec2 textSize = ImGui::GetFont()->CalcTextSizeA(size, FLT_MAX, 0.0f, str.c_str());
				segments.push_back({ str, ImGui::ColorConvertFloat4ToU32(*(ImVec4*)dx11_menu::esp::color_vehicle_tire), size, textSize.x });
			}
		}

		// 计算总宽度并居中绘制
		float total_width = 0.0f;
		for (const auto& seg : segments) {
			total_width += seg.width;
		}

		float start_x = vehicle_pos_2d.X - (total_width / 2.0f);

		for (const auto& seg : segments) {

			draw_list->AddText(ImGui::GetFont(), seg.size, { start_x, current_y }, seg.color, seg.text.c_str());
			start_x += seg.width;
		}
	}
}

void draw_radar(ImDrawList* draw_list, FCameraCacheEntry& CameraCacheEntry) {
	if (!dx11_menu::esp::radar) return;

	ImVec2 center = { dx11_menu::esp::radar_x, dx11_menu::esp::radar_y };
	float size = dx11_menu::esp::radar_size;
	float range = dx11_menu::esp::radar_range;

	// 绘制背景
	if (dx11_menu::esp::radar_style == 0) { // 军事
		draw_list->AddCircleFilled(center, size / 2, IM_COL32(0, 0, 0, 128));
		draw_list->AddCircle(center, size / 2, IM_COL32(0, 255, 0, 255));
		draw_list->AddLine({ center.x - size / 2, center.y }, { center.x + size / 2, center.y }, IM_COL32(0, 255, 0, 128));
		draw_list->AddLine({ center.x, center.y - size / 2 }, { center.x, center.y + size / 2 }, IM_COL32(0, 255, 0, 128));
	}
	else { // 电竞
		float half_size = size / 2;
		ImVec2 tl = { center.x - half_size, center.y - half_size };
		ImVec2 tr = { center.x + half_size, center.y - half_size };
		ImVec2 bl = { center.x - half_size, center.y + half_size };
		ImVec2 br = { center.x + half_size, center.y + half_size };

		// 上边框 
		draw_list->AddRectFilledMultiColor(tl, { tr.x, tr.y + 2 },
			IM_COL32(255, 0, 0, 0), IM_COL32(255, 0, 0, 255), IM_COL32(255, 0, 0, 255), IM_COL32(255, 0, 0, 0));
		// 下边框
		draw_list->AddRectFilledMultiColor({ bl.x, bl.y - 2 }, br,
			IM_COL32(255, 0, 0, 0), IM_COL32(255, 0, 0, 255), IM_COL32(255, 0, 0, 255), IM_COL32(255, 0, 0, 0));
		// 左边框
		draw_list->AddRectFilledMultiColor(tl, { tl.x + 2, bl.y },
			IM_COL32(255, 0, 0, 0), IM_COL32(255, 0, 0, 0), IM_COL32(255, 0, 0, 255), IM_COL32(255, 0, 0, 255));
		// 右边框
		draw_list->AddRectFilledMultiColor({ tr.x - 2, tr.y }, br,
			IM_COL32(255, 0, 0, 0), IM_COL32(255, 0, 0, 0), IM_COL32(255, 0, 0, 255), IM_COL32(255, 0, 0, 255));
	}

	// 获取玩家信息
	auto my_player = g_my_player.load(std::memory_order_acquire);
	if (!my_player) return;

	FVector3D player_pos = CameraCacheEntry.POV.Location;
	float yaw = CameraCacheEntry.POV.Rotation.Yaw;
	float yaw_rad = yaw * 3.1415926535f / 180.0f;
	float cos_yaw = cosf(yaw_rad);
	float sin_yaw = sinf(yaw_rad);

	auto world_to_radar = [&](FVector3D target_pos, float& out_x, float& out_y) -> bool {
		float dx = target_pos.X - player_pos.X;
		float dy = target_pos.Y - player_pos.Y;

		float proj_fwd = dx * cos_yaw + dy * sin_yaw;
		float proj_right = -dx * sin_yaw + dy * cos_yaw;

		// 缩放
		float dist = sqrtf(proj_fwd * proj_fwd + proj_right * proj_right);

		// 限制
		if (dist > range) {
			float scale = range / dist;
			proj_fwd *= scale;
			proj_right *= scale;
		}

		out_x = center.x + proj_right * (size / 2 / range);
		out_y = center.y - proj_fwd * (size / 2 / range); // Forward is Up (-Y)

		// 范围检查
		if (dx11_menu::esp::radar_style == 0) {
			float r2 = (size / 2) * (size / 2);
			float d2 = (out_x - center.x) * (out_x - center.x) + (out_y - center.y) * (out_y - center.y);
			return d2 <= r2 + 1.0f;
		}
		else {
			return out_x >= center.x - size / 2 && out_x <= center.x + size / 2 &&
				out_y >= center.y - size / 2 && out_y <= center.y + size / 2;
		}
		};

	// 绘制自己
	draw_list->AddCircleFilled(center, 4.0f, IM_COL32(255, 255, 255, 255)); // 本人使用白色圆点

	// 绘制玩家
	auto player_list = g_playerList.load(std::memory_order_acquire);
	if (player_list) {
		for (auto& player : *player_list) {
			if (player.ptr == my_player->ptr) continue; // 不画自己
			// 过滤队友
			if (dx11_menu::esp::player_ignore_team && player.m_TeamID == my_player->m_TeamID) continue;
			// 过滤人机
			if (!dx11_menu::esp::radar_ai && player.m_bIsAI) continue;

			float rx, ry;
			if (world_to_radar(player.m_Mesh.m_ComponentToWorld.Translation, rx, ry)) {
				ImU32 color = player.m_bIsAI ? IM_COL32(200, 200, 200, 255) : IM_COL32(255, 0, 0, 255);
				if (player.m_TeamID == my_player->m_TeamID) color = IM_COL32(0, 255, 0, 255);

				draw_list->AddCircleFilled({ rx, ry }, 3.0f, color);

				if (dx11_menu::esp::radar_name) {
					std::string name;
					if (player.m_bIsAI) {
						name = reinterpret_cast<const char*>(u8"人机");
					}
					else {
						name = bm::bm_wstrTostr_utf8(player.m_PlayerName);
					}

					draw_list->AddText({ rx + 4, ry - 14 }, IM_COL32(255, 255, 255, 255), name.c_str());
				}

				if (dx11_menu::esp::radar_dis) {
					float dist = player.m_Mesh.m_ComponentToWorld.Translation.GetDistanceToInMeters(player_pos);
					std::string dist_str = std::to_string((int)dist);
					draw_list->AddText({ rx + 4, ry - 4 }, IM_COL32(255, 255, 255, 255), dist_str.c_str());
				}
			}
		}
	}

	// 绘制载具
	if (dx11_menu::esp::radar_vehicle) {
		auto vehicle_list = g_vehicleList.load(std::memory_order_acquire);
		if (vehicle_list) {
			for (auto& vehicle : *vehicle_list) {
				float rx, ry;
				if (world_to_radar(vehicle.m_RootComponent.m_ComponentToWorld.Translation, rx, ry)) {
					draw_list->AddCircleFilled({ rx, ry }, 3.0f, IM_COL32(255, 255, 0, 255)); // Yellow
				}
			}
		}
	}

	// 绘制物资
	if (dx11_menu::esp::radar_item) {
		auto item_list = g_item_list.load(std::memory_order_acquire);
		if (item_list) {
			for (auto& item : *item_list) {
				float rx, ry;
				if (world_to_radar(item.m_RootComponent.m_ComponentToWorld.Translation, rx, ry)) {
					draw_list->AddCircleFilled({ rx, ry }, 2.0f, IM_COL32(0, 255, 255, 255)); // Cyan
				}
			}
		}
	}
}

void recoil_control() {
	if (!dx11_menu::aim::no_recoil) return;

	auto my_player = g_my_player.load(std::memory_order_acquire);
	if (!my_player) return;

	if (my_player->m_CurrentUsingWeaponSafety.ptr) {
		my_player->m_CurrentUsingWeaponSafety.m_WeaponEntityComp.write_NoRecoil();
	}
}

void draw_trigger(FCameraCacheEntry& CameraCacheEntry) {
	static enum class TriggerState {
		IDLE,
		WAITING_DELAY,
		CLICK_DOWN
	} trigger_state = TriggerState::IDLE;
	static auto state_start_time = std::chrono::steady_clock::now();

	auto reset_trigger = [&]() {
		if (trigger_state == TriggerState::CLICK_DOWN) {
			Box_Release();
		}
		trigger_state = TriggerState::IDLE;
		};

	if (!dx11_menu::trigger::enable) {
		reset_trigger();
		return;
	}

	// 检查按键
	bool is_key_down = false;
	if (dx11_menu::trigger::key1 != 0 && InputUtils::check_single_key(dx11_menu::trigger::key1)) is_key_down = true;
	if (dx11_menu::trigger::key2 != 0 && InputUtils::check_single_key(dx11_menu::trigger::key2)) is_key_down = true;

	if (!is_key_down) {
		reset_trigger();
		return;
	}

	auto player_list = g_playerList.load(std::memory_order_acquire);
	if (!player_list) return;

	auto my_player = g_my_player.load(std::memory_order_acquire);
	if (!my_player) return;

	float screen_center_x = m_Engine.m_rect.w / 2;
	float screen_center_y = m_Engine.m_rect.h / 2;

	// 扳机动态范围计算
	float current_trigger_fov = dx11_menu::trigger::fov;
	if (dx11_menu::trigger::dynamic_fov) {
		float game_fov = CameraCacheEntry.POV.FOV;
		if (game_fov > 0.1f) {
			current_trigger_fov = dx11_menu::trigger::fov * (90.0f / game_fov);
		}
	}

	bool trigger_active = false;
	AUAECharacter* best_target = nullptr;
	float min_crosshair_dist = FLT_MAX;
	FVector2D best_screen_pos = { 0, 0 };
	FVector3D best_target_pos_world = { 0, 0, 0 };

	for (auto& player : *player_list) {
		if (player.ptr == my_player->ptr) continue;
		if (player.m_Health <= 0.0f) continue;
		if (player.m_HealthStatus == 2) {
			if (dx11_menu::trigger::ignore_groggy) continue;
		}
		if (player.m_TeamID == my_player->m_TeamID) continue;
		if (dx11_menu::trigger::ignore_ai && player.m_bIsAI) continue;

		// 检查所有骨骼
		for (auto& bone_info : player.m_Mesh.m_SkeletalMesh.m_bone_info_map) {
			if (bone_info.second >= player.m_Mesh.m_boneVector.size()) continue;

			auto& bone_FT = player.m_Mesh.m_boneVector[bone_info.second];
			FVector3D bone_pos = m_Engine.GetBoneWorldPos(bone_FT, player.m_Mesh.m_ComponentToWorld);

			FVector2D screen_pos;
			if (!m_Engine.WorldToScreen1(bone_pos, CameraCacheEntry, screen_pos)) continue;

			float dx = screen_pos.X - screen_center_x;
			float dy = screen_pos.Y - screen_center_y;
			float dist = sqrtf(dx * dx + dy * dy);

			// 扳机判定
			if (dist <= current_trigger_fov) {
				// 可视检查 
				auto hit = physxEngine::LineTraceSingle(CameraCacheEntry.POV.Location, bone_pos);
				if (!hit.hasAnyHits()) {
					trigger_active = true;
				}
			}

			// 扳机自瞄判定
			if (dx11_menu::trigger::aim_sync && dist <= dx11_menu::trigger::aim_fov && dist < min_crosshair_dist) {
				// 可视检查
				auto hit = physxEngine::LineTraceSingle(CameraCacheEntry.POV.Location, bone_pos);
				if (!hit.hasAnyHits()) {
					min_crosshair_dist = dist;
					best_target = &player;
					best_screen_pos = screen_pos;
					best_target_pos_world = bone_pos;
				}
			}
		}
		if (trigger_active && !dx11_menu::trigger::aim_sync) break; // 如果不需要自瞄，找到一个触发点就够了
	}

	auto now = std::chrono::steady_clock::now();

	if (trigger_active) {
		if (trigger_state == TriggerState::IDLE) {
			trigger_state = TriggerState::WAITING_DELAY;
			state_start_time = now;
		}
	}
	else {
		// 如果目标离开准星，且还没开火，重置状态
		if (trigger_state == TriggerState::WAITING_DELAY) {
			trigger_state = TriggerState::IDLE;
		}
	}

	// 状态机处理
	if (trigger_state == TriggerState::WAITING_DELAY) {
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - state_start_time).count();
		if (elapsed >= dx11_menu::trigger::delay) {
			Box_Click();
			trigger_state = TriggerState::CLICK_DOWN;
			state_start_time = now;
		}
	}
	else if (trigger_state == TriggerState::CLICK_DOWN) {
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - state_start_time).count();
		if (elapsed >= 20) { // 20ms 点击持续时间
			Box_Release();
			trigger_state = TriggerState::IDLE;
		}
	}

	// 扳机自瞄逻辑
	if (dx11_menu::trigger::aim_sync && best_target) {
		float dx = best_screen_pos.X - screen_center_x;
		float dy = best_screen_pos.Y - screen_center_y;

		float smooth = dx11_menu::trigger::aim_smooth;
		if (smooth < 1.0f) smooth = 1.0f;

		int move_x = (int)(dx / smooth);
		int move_y = (int)(dy / smooth);

		// 静默自瞄逻辑
		if (dx11_menu::aim::silent_aim) {
			// 使用预判后的世界坐标 
			FVector3D target_pos = best_target_pos_world;

			// 计算 Delta Rotation
			FVector3D my_loc = CameraCacheEntry.POV.Location;
			FVector3D delta = { target_pos.X - my_loc.X, target_pos.Y - my_loc.Y, target_pos.Z - my_loc.Z };
			float dist = sqrtf(delta.X * delta.X + delta.Y * delta.Y + delta.Z * delta.Z);

			float pitch = -asinf(delta.Z / dist) * (180.0f / 3.1415926f);
			float yaw = atan2f(delta.Y, delta.X) * (180.0f / 3.1415926f);

			// 写入 ControlRotation
			auto uworld = g_uworld.load(std::memory_order_acquire);
			if (uworld) {
				uworld->m_NetDriver.m_ServerConnection.m_PlayerController.write_ControlRotation(pitch, yaw);
			}
		}
		// 只有在非静默自瞄，或者静默自瞄未开启时，才执行模拟鼠标移动
		else if (abs(move_x) > 0 || abs(move_y) > 0) {
			Box_Move(move_x, move_y);
		}
	}
}

// 绘制箭头辅助函数
void draw_arrow(ImDrawList* draw_list, float x, float y, float angle, float size, ImU32 color) {
	float cos_a = cosf(angle);
	float sin_a = sinf(angle);

	// 箭头顶点
	ImVec2 p1 = ImVec2(x + size * cos_a, y + size * sin_a);
	// 箭头左翼
	ImVec2 p2 = ImVec2(x + size * 0.5f * cosf(angle + 2.5f), y + size * 0.5f * sinf(angle + 2.5f));
	// 箭头右翼
	ImVec2 p3 = ImVec2(x + size * 0.5f * cosf(angle - 2.5f), y + size * 0.5f * sinf(angle - 2.5f));

	draw_list->AddTriangleFilled(p1, p2, p3, color);
}

void draw_aim(ImDrawList* draw_list, FCameraCacheEntry& CameraCacheEntry) {
	//基础开关检查
	if (!dx11_menu::aim::enable) return;

	// 按键模式：至少绑定一个键 或 开启持续锁定 或 开启开火自瞄
	if (dx11_menu::aim::key1 == 0 && dx11_menu::aim::key2 == 0
		&& !dx11_menu::aim::auto_lock && !dx11_menu::aim::fire_aim) return;

	//  绘制 FOV 圈
	float current_fov = dx11_menu::aim::fov;
	if (dx11_menu::aim::dynamic_fov) {
		float game_fov = CameraCacheEntry.POV.FOV;
		// 简单的动态计算：基础FOV * (默认FOV / 当前游戏FOV)
		// 假设默认游戏FOV是90
		if (game_fov > 0.1f) {
			current_fov = dx11_menu::aim::fov * (90.0f / game_fov);
		}
	}

	float screen_center_x = m_Engine.m_rect.w * 0.5f;
	float screen_center_y = m_Engine.m_rect.h * 0.5f;

	if (dx11_menu::aim::show_fov) {
		draw_list->AddCircle(
			ImVec2(screen_center_x, screen_center_y),
			current_fov,
			ImGui::ColorConvertFloat4ToU32(ImVec4(dx11_menu::esp::color_fov[0], dx11_menu::esp::color_fov[1], dx11_menu::esp::color_fov[2], dx11_menu::esp::color_fov[3])),
			100
		);
	}

	// 视场外箭头绘制逻辑
	if (dx11_menu::esp::player_out_of_fov_arrow) {
		auto player_list = g_playerList.load(std::memory_order_acquire);
		auto my_player = g_my_player.load(std::memory_order_acquire);

		if (player_list && my_player) {
			for (auto& player : *player_list) {
				if (player.ptr == my_player->ptr) continue;
				if (player.m_TeamID == my_player->m_TeamID && dx11_menu::esp::player_ignore_team) continue;
				if (player.m_bIsAI && dx11_menu::aim::ignore_ai) continue;
				if (player.m_HealthStatus == 2 && dx11_menu::aim::ignore_groggy) continue;
				if (player.m_Health <= 0.0f) continue;

				FVector2D screen_pos;
				bool on_screen = m_Engine.WorldToScreen1(player.m_Mesh.m_ComponentToWorld.Translation, CameraCacheEntry, screen_pos);

				if (!on_screen) {
					// 计算相对角度
					FVector3D my_pos = CameraCacheEntry.POV.Location;
					FVector3D target_pos = player.m_Mesh.m_ComponentToWorld.Translation;

					float dx = target_pos.X - my_pos.X;
					float dy = target_pos.Y - my_pos.Y;

					// 目标相对于我的世界坐标角度
					float target_yaw = atan2f(dy, dx) * 180.0f / 3.1415926f;

					// 我的视角角度
					float my_yaw = CameraCacheEntry.POV.Rotation.Yaw;

					// 相对角度差
					float delta_yaw = target_yaw - my_yaw;

					// 规范化到 -180 到 180
					while (delta_yaw > 180.0f) delta_yaw -= 360.0f;
					while (delta_yaw < -180.0f) delta_yaw += 360.0f;

					// 转换为弧度
					float angle_rad = delta_yaw * 3.1415926f / 180.0f;

					// 计算屏幕上的位置
					float radius = dx11_menu::esp::player_out_of_fov_arrow_radius;
					float arrow_x = screen_center_x + radius * sinf(angle_rad); // 注意：屏幕坐标系Y轴向下，角度需要调整
					float arrow_y = screen_center_y - radius * cosf(angle_rad);

					// 绘制箭头 
					draw_arrow(draw_list, arrow_x, arrow_y, angle_rad - 3.1415926f * 0.5f, dx11_menu::esp::player_out_of_fov_arrow_size, ImGui::ColorConvertFloat4ToU32(ImVec4(dx11_menu::esp::color_player_out_of_fov_arrow[0], dx11_menu::esp::color_player_out_of_fov_arrow[1], dx11_menu::esp::color_player_out_of_fov_arrow[2], dx11_menu::esp::color_player_out_of_fov_arrow[3])));
				}
			}
		}
	}

	// 按键检测
	bool is_key_down = false;
	bool k1 = dx11_menu::aim::key1 != 0 && InputUtils::check_single_key(dx11_menu::aim::key1);
	bool k2 = dx11_menu::aim::key2 != 0 && InputUtils::check_single_key(dx11_menu::aim::key2);
	bool lk = dx11_menu::aim::auto_lock;
	bool fa = dx11_menu::aim::fire_aim && InputUtils::check_single_key(VK_LBUTTON);
	if (k1 || k2) is_key_down = true;
	if (lk) is_key_down = true;
	if (fa) is_key_down = true;

	if (!is_key_down) return;

	//  获取玩家列表（用 g_RenderList，它有骨骼数据）
	std::vector<AUAECharacter> local_aim_list;
	{
		std::lock_guard<std::mutex> lock(g_DataMutex);
		if (g_RenderList.empty()) return;
		local_aim_list = g_RenderList;
	}
	// player_list 引用 local_aim_list 用于后续循环
	auto& player_list = local_aim_list;

	auto my_player = g_my_player.load(std::memory_order_acquire);
	if (!my_player) return;

	// 空仓不锁逻辑
	if (dx11_menu::aim::ignore_empty) {
		if (!my_player->m_CurrentUsingWeaponSafety.ptr || my_player->m_CurrentUsingWeaponSafety.m_CurBulletNumInClip <= 0) {
			return;
		}
	}

	// 弓箭不锁逻辑
	if (dx11_menu::aim::ignore_bow) {
		if (my_player->m_CurrentUsingWeaponSafety.ptr) {
			std::string weapon_name = my_player->m_CurrentUsingWeaponSafety.m_FName.ToString();
			if (weapon_name.find("CrossBow") != std::string::npos ||
				weapon_name.find("Crossbow") != std::string::npos ||
				weapon_name.find("HuntingBow") != std::string::npos ||
				weapon_name.find("CompoundBow") != std::string::npos) {
				return;
			}
		}
	}

	// 寻找目标
	AUAECharacter* best_target = nullptr;
	float min_crosshair_dist = FLT_MAX;
	FVector2D best_screen_pos = { 0, 0 };
	FVector3D best_target_pos_world = { 0, 0, 0 }; // 用于存储最佳目标的世界坐标

	screen_center_x = m_Engine.m_rect.w / 2;
	screen_center_y = m_Engine.m_rect.h / 2;

	// 获取自身位置和速度
	FVector3D my_pos = CameraCacheEntry.POV.Location;
	FVector3D my_vel = { 0,0,0 }; // 设为0

	// 目标锁定逻辑
	static uint64_t locked_target_ptr = 0;
	if (!is_key_down) {
		locked_target_ptr = 0;
	}

	// 验证锁定目标是否依然有效（完整检查）
	if (locked_target_ptr != 0) {
		bool still_valid = false;
		for (auto& player : player_list) {
			if (player.ptr == locked_target_ptr) {
				// 检查死亡
				if (player.m_Health <= 0.0f && player.m_Health > -1.0f) break;
				// 检查倒地
				if (dx11_menu::aim::ignore_groggy && player.m_HealthStatus == 2) break;
				// 检查队伍
				if (player.m_TeamID == my_player->m_TeamID && player.m_TeamID < 100) break;
				// 检查AI
				if (dx11_menu::aim::ignore_ai && player.m_bIsAI) break;
			// 检查距离（直接用 boneVector 索引）
			float lock_dist = 999999.0f;
			if (!player.m_Mesh.m_boneVector.empty()) {
				for (int idx : {6, 5}) {
					if (idx < (int)player.m_Mesh.m_boneVector.size()) {
						auto& ft = player.m_Mesh.m_boneVector[idx];
						FVector3D bp = m_Engine.GetBoneWorldPos(ft, player.m_Mesh.m_ComponentToWorld);
						lock_dist = bp.GetDistanceToInMeters(my_pos);
						break;
					}
				}
			}
			if (lock_dist > dx11_menu::aim::dist) break;
				still_valid = true;
				break;
			}
		}
		if (!still_valid) {
			locked_target_ptr = 0;
		}
	}

	for (auto& player : player_list) {
		// 如果有锁定目标，且当前玩家不是锁定目标，跳过
		if (locked_target_ptr != 0 && player.ptr != locked_target_ptr) continue;

		// 过滤条件
		if (player.ptr == my_player->ptr) continue;
		// if (player.m_bIsAI) continue; // 暂时过滤人机，可根据需求修改
		if (dx11_menu::aim::ignore_ai && player.m_bIsAI) continue; // 自瞄忽略人机
		if (player.m_TeamID == my_player->m_TeamID) {
			// TeamID 异常值（>100）说明偏移过期，跳过队友过滤
			if (player.m_TeamID < 100) continue;
		}
		if (player.m_Health <= 0.0f && player.m_Health > -1.0f) continue; // 过滤死亡（跳过异常值）
		if (dx11_menu::aim::ignore_groggy && player.m_HealthStatus == 2) continue; // 过滤倒地


		// 距离判断：直接用 boneVector 索引（bone_info_map 偏移过期用不了名字查找）
		float dist = 999999.0f;
		if (!player.m_Mesh.m_boneVector.empty()) {
			// UE骨骼标准顺序: 5=neck_01, 6=head
			for (int idx : {6, 5}) {
				if (idx < (int)player.m_Mesh.m_boneVector.size()) {
					auto& ft = player.m_Mesh.m_boneVector[idx];
					FVector3D bp = m_Engine.GetBoneWorldPos(ft, player.m_Mesh.m_ComponentToWorld);
					dist = bp.GetDistanceToInMeters(my_pos);
					break;
				}
			}
		}
		if (dist > dx11_menu::aim::dist) continue;

		static const std::vector<int> target_bones_all = { 65, 6, 5, 4, 3, 2, 1 };
		static const std::vector<int> target_bones_head = { 65, 6 };

		const std::vector<int>* target_bones_ptr;
		int bone_mode = dx11_menu::aim::aim_bone_mode;

		if (bone_mode == 0) {
			target_bones_ptr = &target_bones_head;  // 仅头部
		}
		else if (bone_mode == 2) {
			// 固定部位：只瞄准指定骨骼
			static std::vector<int> fixed_bone_list;
			fixed_bone_list = { dx11_menu::aim::aim_bone_id };
			target_bones_ptr = &fixed_bone_list;
		}
		else if (bone_mode == 3) {
			// 随机部位：每帧从全身骨骼中随机选一个
			static std::vector<int> random_bone_list;
			static int last_frame = -1;
			static std::mt19937 rng(std::random_device{}());
			int current_frame = (int)ImGui::GetFrameCount();
			if (current_frame != last_frame) {
				last_frame = current_frame;
				int idx = rng() % target_bones_all.size();
				random_bone_list = { target_bones_all[idx] };
			}
			target_bones_ptr = &random_bone_list;
		}
		else {
			// mode == 1: 漏打扫描（自上而下）
			target_bones_ptr = &target_bones_all;
		}

		const std::vector<int>& target_bones = *target_bones_ptr;

		FTransform bone_transform;
		bool found_visible_bone = false;

		int selected_bone_id = 0;
		for (int bone_id : target_bones) {
			// 直接用 bone_id 作为 boneVector 索引（bone_info_map 偏移过期）
			if (bone_id < 0 || bone_id >= (int)player.m_Mesh.m_boneVector.size()) continue;
			auto& bone_FT = player.m_Mesh.m_boneVector[bone_id];
			bone_transform.Translation = m_Engine.GetBoneWorldPos(bone_FT, player.m_Mesh.m_ComponentToWorld);

			// 可视判断
			if (dx11_menu::aim::vis_check) {
				// 可见性检查 
				auto hit = physxEngine::LineTraceSingle(CameraCacheEntry.POV.Location, bone_transform.Translation);
				if (!hit.hasAnyHits()) { // 无遮挡，即可见
					found_visible_bone = true;
					selected_bone_id = bone_id;
					break; // 找到第一个可见部位即停止，优先打头
				}
			}
			else {
				// 不进行可视判断，直接认为可见
				found_visible_bone = true;
				selected_bone_id = bone_id;
				break;
			}
		}

		// 这里如果不强制瞄准，则 continue 跳过该目标
		if (!found_visible_bone) {
			// 如果你想强制锁头即使不可见，这里可以回退到头部
			// if (!player.m_Mesh.GetBoneTransform(6, bone_transform)) continue;
			continue; // 跳过不可见目标
		}

		FVector3D target_pos = bone_transform.Translation;

		// ═══ PUBG_DMA 完整弹道预测引擎（移植自 AimBot.h GetBulletDropAndTravelTime + GetDragForce） ═══
		FVector3D predicted_pos = target_pos;

		if (dx11_menu::aim::prediction || dx11_menu::aim::silent_aim) {
			float dx_ = target_pos.X - my_pos.X;
			float dy_ = target_pos.Y - my_pos.Y;
			float dz_ = target_pos.Z - my_pos.Z;
			float dist_cm = sqrtf(dx_*dx_ + dy_*dy_ + dz_*dz_);
			float dist_m = dist_cm / 100.0f;

			// 获取武器名用于阻力查表 (PUBG_DMA GetDragForce 精确移植)
			std::string weapon_name = "Unknown";
			if (my_player->m_CurrentUsingWeaponSafety.ptr)
				weapon_name = my_player->m_CurrentUsingWeaponSafety.m_FName.ToString();

			// === GetDragForce: 三组武器独立阻力表 ===
			float drag_force = 1.0f; // 默认无衰减
			{
				static const std::set<std::string> GunNamesOne = {
					"WeapAK47_C","WeapLunchmeats_AK47_C","WeapGroza_C","WeapBerylM762_C",
					"WeapMini14_C","WeapQBU88_C","Weapon_G36C_C","WeapKar98k_C",
					"WeapMosinNagant_C","WeapJulies_Kar98k_C","WeapM24_C","WeapAWM_C",
					"WeapHK416_C","WeapDuncans_M416_C","WeapK2_C","WeapSCAR-L_C",
					"WeapM16A4_C","WeapQBZ95_C","WeapAUG_C","Weapon_Mosin_C",
					"Weapon_M249_C","WeaponMk14_C","Weapon_L6_C","WeapMG3_C",
					"WeapMads_QBU88_C","WeapFamasG2_C"
				};
				static const std::set<std::string> GunNamesTwo = {
					"WeapSKS_C","WeapFNFal_C","Weapon_Mk47Mutant_C",
					"WeapMk14_C","WeapMk12_C","WeapDragunov_C"
				};

				if (GunNamesOne.count(weapon_name)) { // 组1: 主武器
					if      (dist_m > 10  && dist_m <= 50)  drag_force = 0.41f;
					else if (dist_m > 50  && dist_m <= 100) drag_force = 0.42f;
					else if (dist_m > 100 && dist_m <= 150) drag_force = 0.43f;
					else if (dist_m > 150 && dist_m <= 200) drag_force = 0.44f;
					else if (dist_m > 200 && dist_m <= 250) drag_force = 0.45f;
					else if (dist_m > 250 && dist_m <= 300) drag_force = 0.60f;
					else if (dist_m > 300 && dist_m <= 350) drag_force = 0.80f;
					else if (dist_m > 350 && dist_m <= 400) drag_force = 0.95f;
					else if (dist_m > 400 && dist_m <= 450) drag_force = 1.00f;
					else if (dist_m > 450 && dist_m <= 500) drag_force = 1.05f;
					else if (dist_m > 500 && dist_m <= 550) drag_force = 1.10f;
					else if (dist_m > 550 && dist_m <= 600) drag_force = 1.15f;
					else if (dist_m > 600 && dist_m <= 650) drag_force = 1.20f;
					else if (dist_m > 650 && dist_m <= 700) drag_force = 1.25f;
					else if (dist_m > 700 && dist_m <= 750) drag_force = 1.30f;
					else if (dist_m > 750 && dist_m <= 800) drag_force = 1.35f;
					else if (dist_m > 800 && dist_m <= 850) drag_force = 1.40f;
					else if (dist_m > 850 && dist_m <= 900) drag_force = 1.45f;
					else if (dist_m > 900 && dist_m <= 950) drag_force = 1.50f;
					else if (dist_m > 950 && dist_m <= 1000)drag_force = 1.55f;
					else if (dist_m > 1000 && dist_m <= 1050)drag_force = 1.60f;
				}
				else if (GunNamesTwo.count(weapon_name)) { // 组2: 半自动/DMR
					if      (dist_m > 10  && dist_m <= 50)  drag_force = 0.38f;
					else if (dist_m > 50  && dist_m <= 100) drag_force = 0.39f;
					else if (dist_m > 100 && dist_m <= 150) drag_force = 0.41f;
					else if (dist_m > 150 && dist_m <= 200) drag_force = 0.43f;
					else if (dist_m > 200 && dist_m <= 250) drag_force = 0.46f;
					else if (dist_m > 250 && dist_m <= 300) drag_force = 0.55f;
					else if (dist_m > 300 && dist_m <= 400) drag_force = 0.75f;
					else if (dist_m > 400 && dist_m <= 500) drag_force = 0.90f;
					else if (dist_m > 500 && dist_m <= 600) drag_force = 1.02f;
					else if (dist_m > 600 && dist_m <= 800) drag_force = 1.18f;
					else if (dist_m > 800 && dist_m <= 1000)drag_force = 1.30f;
				}
				else { // 默认通用衰减
					drag_force = (std::min)(1.5f, 0.37f + dist_m * 0.00115f);
				}
			}

			// 获取子弹速度 (按武器类型查表，避免额外DMA读取UWeaponEntity)
			float bullet_speed = 88000.0f; // 默认 880m/s (cm/s)
			{
				static const std::map<std::string, float> SpeedTable = {
					{"WeapAWM_C", 91000.0f},  {"WeapKar98k_C", 76000.0f}, {"WeapM24_C", 79000.0f},
					{"WeapMini14_C", 99000.0f}, {"WeapQBU88_C", 94500.0f}, {"WeapMk14_C", 85300.0f},
					{"WeapSKS_C", 80000.0f},   {"WeapDragunov_C", 83000.0f},{"WeapAK47_C", 71500.0f},
					{"WeapGroza_C", 71500.0f}, {"WeapBerylM762_C", 71500.0f},{"WeapHK416_C", 88000.0f},
					{"WeapAUG_C", 94000.0f},   {"WeapM16A4_C", 90000.0f}, {"WeapSCAR-L_C", 87000.0f},
				};
				auto it = SpeedTable.find(weapon_name);
				if (it != SpeedTable.end()) bullet_speed = it->second;
			}

			float TrajectoryGravityZ = -980.0f; // PUBG标准重力 cm/s²

			// === SimulateWeaponTrajectory 核心公式: 分步积分模拟 ===
			float sim_time = 0.0f;
			float sim_dt = 0.01f;   // 10ms 子步长 (PUBG_DMA 标准)
			int max_steps = 300;     // 最多模拟3秒
			FVector3D sim_pos = { 0, 0, 0 }; // 相对位置
			FVector3D sim_vel = { dist_m * 100.0f, 0, 0 }; // 初始速度沿X方向, 单位cm

			for (int step = 0; step < max_steps; step++) {
				float speed_sq = sim_vel.X*sim_vel.X + sim_vel.Y*sim_vel.Y + sim_vel.Z*sim_vel.Z;
				float speed_val = sqrtf(speed_sq);
				if (speed_val < 1.0f) break;

				// 阻力: F_drag = v² * DragCoefficient * BallisticDragScale / speed
				float drag_mag = speed_sq * 0.001f * drag_force / speed_val;
				FVector3D drag_acc = { -sim_vel.X * drag_mag, -sim_vel.Y * drag_mag, -sim_vel.Z * drag_mag };

				// 总加速度 = 阻力 + 重力
				sim_vel.X += (drag_acc.X) * sim_dt;
				sim_vel.Y += (drag_acc.Y) * sim_dt;
				sim_vel.Z += (TrajectoryGravityZ + drag_acc.Z) * sim_dt;

				sim_pos.X += sim_vel.X * sim_dt;
				sim_pos.Y += sim_vel.Y * sim_dt;
				sim_pos.Z += sim_vel.Z * sim_dt;

				sim_time += sim_dt;
				if (sim_pos.X >= dist_cm) break; // 到达目标距离
			}

			// 目标速度外推 (预判移动目标)
			FVector3D target_vel = player.m_Mesh.m_ComponentVelocity;
			predicted_pos.X += target_vel.X * sim_time;
			predicted_pos.Y += target_vel.Y * sim_time;
			predicted_pos.Z += target_vel.Z * sim_time;

			// 应用下坠修正 (从模拟结果获取 Z轴偏移)
			predicted_pos.Z -= fabsf(sim_pos.Z);
		}

		if (dx11_menu::aim::prediction) {
			target_pos = predicted_pos;
		}


		// ═══ PUBG_DMA 风格：角度 FOV（不依赖 WorldToScreen） ═══
		FVector3D dir_to_target = { target_pos.X - CameraCacheEntry.POV.Location.X,
		                            target_pos.Y - CameraCacheEntry.POV.Location.Y,
		                            target_pos.Z - CameraCacheEntry.POV.Location.Z };
		float dist_to_target = sqrtf(dir_to_target.X*dir_to_target.X + dir_to_target.Y*dir_to_target.Y + dir_to_target.Z*dir_to_target.Z);
		if (dist_to_target > 0.1f) {
			dir_to_target.X /= dist_to_target;
			dir_to_target.Y /= dist_to_target;
			dir_to_target.Z /= dist_to_target;
		}

		// 从 Camera rotation 计算前向向量
		float pitch_rad = CameraCacheEntry.POV.Rotation.Pitch * 3.1415926f / 180.0f;
		float yaw_rad   = CameraCacheEntry.POV.Rotation.Yaw   * 3.1415926f / 180.0f;
		float forward_x = cosf(pitch_rad) * cosf(yaw_rad);
		float forward_y = cosf(pitch_rad) * sinf(yaw_rad);
		float forward_z = sinf(pitch_rad);

		float dot_product = forward_x * dir_to_target.X + forward_y * dir_to_target.Y + forward_z * dir_to_target.Z;
		dot_product = std::clamp(dot_product, -1.0f, 1.0f);
		float angle_to_target = acosf(dot_product) * 180.0f / 3.1415926f;

		float aim_fov = current_fov * 15.0f / 100.0f; // fov=100→15°, fov=200→30°, fov=300→45°

		if (dx11_menu::aim::range_boost && dist < 50.0f) {
			aim_fov *= 1.5f;
		}

		if (angle_to_target > aim_fov) continue;

		// 最佳目标（按角度选择）
		if (angle_to_target < min_crosshair_dist) {
			min_crosshair_dist = angle_to_target;
			best_target = &player;
			best_target_pos_world = predicted_pos;

			// 计算屏幕坐标用于绘制射线
			m_Engine.WorldToScreen1(target_pos, CameraCacheEntry, best_screen_pos);
		}
	}

	// 锁定目标
	if (best_target) {
		locked_target_ptr = best_target->ptr;
	}
	else {
		locked_target_ptr = 0;
	}

	// ═══════════════════════════════════════════════════════════
	// PUBG_DMA AimBot::Run() 精确移植: 角度空间计算 + AimBotAPI平滑
	// ═══════════════════════════════════════════════════════════
	if (best_target) {
		// === Step 1: 世界空间方向向量 (PUBG_DMA) ===
		FVector3D dir_to_target = {
			best_target_pos_world.X - CameraCacheEntry.POV.Location.X,
			best_target_pos_world.Y - CameraCacheEntry.POV.Location.Y,
			best_target_pos_world.Z - CameraCacheEntry.POV.Location.Z
		};

		// === Step 2: 方向向量 → FRotator (PUBG_DMA GetDirectionRotator) ===
		float dir_xy = sqrtf(dir_to_target.X * dir_to_target.X + dir_to_target.Y * dir_to_target.Y);
		FRotator target_rotation;
		target_rotation.Yaw   = atan2f(dir_to_target.Y, dir_to_target.X) * 180.0f / 3.1415926f;
		target_rotation.Pitch = atan2f(-dir_to_target.Z, dir_xy) * 180.0f / 3.1415926f;
		target_rotation.Roll  = 0.0f;

		// === Step 3: 与当前视角的差值 (PUBG_DMA: RotationInput) ===
		FRotator aim_rotation = CameraCacheEntry.POV.Rotation;
		FRotator rotation_input;
		rotation_input.Yaw   = target_rotation.Yaw - aim_rotation.Yaw;
		rotation_input.Pitch = target_rotation.Pitch - aim_rotation.Pitch;
		rotation_input.Roll  = 0.0f;

		// 角度标准化 (±180°)
		if (rotation_input.Yaw > 180.0f) rotation_input.Yaw -= 360.0f;
		if (rotation_input.Yaw < -180.0f) rotation_input.Yaw += 360.0f;

		// === Step 4: 角度 → 鼠标像素 (PUBG_DMA GetMouseXY) ===
		float CameraFOV = CameraCacheEntry.POV.FOV;
		if (CameraFOV < 1.0f) CameraFOV = 90.0f;
		float FOVRatio = 90.0f / CameraFOV;
		float MouseXSensitivity = 0.02f;
		float MouseYSensitivity = 0.02f;
		float AimSpeedMaxFactor = 1.0f;

		// PUBG_DMA 精确公式: Yaw/0.02*0.4*FOVRatio, -Pitch/0.02*0.4*FOVRatio
		float raw_dx = (rotation_input.Yaw / MouseXSensitivity) * 0.4f * FOVRatio * AimSpeedMaxFactor;
		float raw_dy = (-rotation_input.Pitch / MouseYSensitivity) * 0.4f * FOVRatio * AimSpeedMaxFactor;

		// === 可选: humanize (模拟真人) ===
		bool skip_move = false;
		if (dx11_menu::aim::humanize) {
			static uint64_t last_target_ptr = 0;
			static double cooldown_until = 0.0;
			static float target_offset_x = 0.0f, target_offset_y = 0.0f;
			static std::mt19937_64 rng_h(std::random_device{}());
			static bool overshooting = false;
			static int overshoot_frames = 0;

			if (best_target->ptr != last_target_ptr) {
				last_target_ptr = best_target->ptr;
				double delay = 0.08 + (rng_h() % 220) / 1000.0;
				cooldown_until = ImGui::GetTime() + delay;
				float off_range = 5.0f + (rng_h() % 10);
				float ang = (rng_h() % 628) / 100.0f;
				target_offset_x = cosf(ang) * off_range;
				target_offset_y = sinf(ang) * off_range;
				overshooting = (rng_h() % 100) < 30;
				overshoot_frames = 3 + (rng_h() % 5);
			}

			if (ImGui::GetTime() < cooldown_until) {
				skip_move = true;
			} else {
				raw_dx += target_offset_x;
				raw_dy += target_offset_y;
				if (overshooting && overshoot_frames > 0) {
					float ov = 1.3f + (rng_h() % 20) / 100.0f;
					raw_dx *= ov;
					raw_dy *= ov;
					overshoot_frames--;
				}
			}
		}

		// 屏幕坐标 WorldToScreen
		FVector2D screen_pos;
		m_Engine.WorldToScreen1(best_target_pos_world, CameraCacheEntry, screen_pos);
		float screen_dx = screen_pos.X - screen_center_x;
		float screen_dy = screen_pos.Y - screen_center_y;

		// 绘制射线+圆环
		if (dx11_menu::aim::draw_line) {
			ImU32 lc = ImGui::ColorConvertFloat4ToU32(
				ImVec4(dx11_menu::esp::color_aim_line[0], dx11_menu::esp::color_aim_line[1],
					dx11_menu::esp::color_aim_line[2], dx11_menu::esp::color_aim_line[3]));
			draw_list->AddLine(ImVec2(screen_center_x, screen_center_y),
				ImVec2(screen_center_x + screen_dx, screen_center_y + screen_dy), lc, 1.0f);
			draw_list->AddLine(ImVec2(screen_center_x + screen_dx - 5.0f, screen_center_y + screen_dy),
				ImVec2(screen_center_x + screen_dx + 5.0f, screen_center_y + screen_dy), IM_COL32(255, 50, 50, 255), 1.0f);
			draw_list->AddLine(ImVec2(screen_center_x + screen_dx, screen_center_y + screen_dy - 5.0f),
				ImVec2(screen_center_x + screen_dx, screen_center_y + screen_dy + 5.0f), IM_COL32(255, 50, 50, 255), 1.0f);
		}
		if (dx11_menu::aim::draw_target_bone) {
			draw_list->AddCircle(ImVec2(screen_center_x + screen_dx, screen_center_y + screen_dy), 5.0f,
				IM_COL32(255, 0, 0, 255), 16, 1.5f);
			draw_list->AddCircleFilled(ImVec2(screen_center_x + screen_dx, screen_center_y + screen_dy), 2.0f,
				IM_COL32(255, 200, 200, 255));
		}

		// === Step 5: PUBG_DMA AimBotAPI (InitialValue渐进累积平滑) ===
		if (!skip_move) {
			static float RemainMouseX = 0.0f, RemainMouseY = 0.0f;

			// InitialValue=100 配合旧版smooth映射: 保证 0.3≈80px/帧, 5≈9px/帧
			const float InitialValue = 100.0f;
			float x_speed = 150.0f / (dx11_menu::aim::smooth * 3.0f + 1.0f);
			float y_speed = x_speed;
			x_speed = (std::clamp)(x_speed, 1.0f, 200.0f);
			y_speed = (std::clamp)(y_speed, 1.0f, 200.0f);

			float move_x = RemainMouseX + (std::clamp)(x_speed * (screen_dx > 0 ? 1.0f : -1.0f),
				-fabsf(screen_dx), fabsf(screen_dx));
			float move_y = RemainMouseY + (std::clamp)(y_speed * (screen_dy > 0 ? 1.0f : -1.0f),
				-fabsf(screen_dy), fabsf(screen_dy));

			RemainMouseX = move_x - truncf(move_x);
			RemainMouseY = move_y - truncf(move_y);

			int tx = (int)truncf(move_x);
			int ty = (int)truncf(move_y);

			if (tx != 0 || ty != 0) {
				Box_Move(tx, ty);
			}

			if (!best_target || !is_key_down) {
				RemainMouseX = RemainMouseY = 0.0f;
			}
		} else {
		}
	}
}

void draw_shortcut_menu(ImDrawList* draw_list) {
	// 处理快捷键逻辑
	static std::map<int, bool> key_states;
	auto check_key_toggle = [](int key, bool& toggle_var) {
		if (key == 0) return;
		bool is_pressed = InputUtils::is_key_pressed(key);
		if (is_pressed && !key_states[key]) {
			toggle_var = !toggle_var;
			key_states[key] = true;
		}
		else if (!is_pressed) {
			key_states[key] = false;
		}
		};

	// 始终检查"显/隐本菜单"的按键，无论当前菜单是否显示
	check_key_toggle(dx11_menu::shortcut::key_toggle_menu, dx11_menu::shortcut::enable);

	if (!dx11_menu::shortcut::enable) return;

	check_key_toggle(dx11_menu::shortcut::key_fusion, dx11_menu::shortcut::fusion_mode);
	check_key_toggle(dx11_menu::shortcut::key_aim, dx11_menu::aim::enable);
	check_key_toggle(dx11_menu::shortcut::key_meds, dx11_menu::esp::item_meds);
	check_key_toggle(dx11_menu::shortcut::key_vehicle, dx11_menu::esp::vehicle);
	check_key_toggle(dx11_menu::shortcut::key_weapon, dx11_menu::esp::player_weapon);

	// 获取按键名称的辅助函数
	auto GetKeyName = [](int key) -> std::string {
		if (key == 0) return "未绑定";
		char keyName[128] = { 0 };
		UINT scanCode = MapVirtualKeyA(key, MAPVK_VK_TO_VSC);
		switch (key) {
		case VK_LEFT: case VK_UP: case VK_RIGHT: case VK_DOWN:
		case VK_PRIOR: case VK_NEXT: case VK_END: case VK_HOME:
		case VK_INSERT: case VK_DELETE: case VK_DIVIDE: case VK_NUMLOCK:
			scanCode |= 0x100; break;
		}
		if (GetKeyNameTextA(scanCode << 16, keyName, sizeof(keyName))) {
			return std::string(keyName);
		}
		return "Key " + std::to_string(key);
		};

	std::vector<std::string> lines;

	// 菜单项
	if (dx11_menu::shortcut::show_status) {
		auto uworld = g_uworld.load(std::memory_order_acquire);
		lines.push_back(std::format("游戏状态:{}", uworld ? "正在进行游戏" : "等待进入游戏..."));
	}
	lines.push_back(std::format("[{}]融合模式:{}", GetKeyName(dx11_menu::shortcut::key_fusion), dx11_menu::shortcut::fusion_mode ? "开" : "关"));
	lines.push_back(std::format("[{}]显示载具:{}", GetKeyName(dx11_menu::shortcut::key_vehicle), dx11_menu::esp::vehicle ? "开" : "关"));
	lines.push_back(std::format("[{}]显示枪械:{}", GetKeyName(dx11_menu::shortcut::key_weapon), dx11_menu::esp::player_weapon ? "开" : "关"));
	lines.push_back(std::format("[{}]显示药品:{}", GetKeyName(dx11_menu::shortcut::key_meds), dx11_menu::esp::item_meds ? "开" : "关"));
	lines.push_back(std::format("[{}]自瞄开关:{}", GetKeyName(dx11_menu::shortcut::key_aim), dx11_menu::aim::enable ? "开" : "关"));
	lines.push_back(std::format("[{}]显/隐本菜单", GetKeyName(dx11_menu::shortcut::key_toggle_menu)));

	// 时间
	if (dx11_menu::shortcut::show_time) {
		auto now = std::chrono::system_clock::now();
		auto in_time_t = std::chrono::system_clock::to_time_t(now);
		std::tm buf;
		gmtime_s(&buf, &in_time_t);
		// 处理北京时间 (UTC+8)
		in_time_t += 8 * 3600;
		gmtime_s(&buf, &in_time_t);
		lines.push_back(std::format("北京时间:{:04d}年{:02d}月{:02d}日{:02d}时{:02d}分{:02d}秒",
			buf.tm_year + 1900, buf.tm_mon + 1, buf.tm_mday, buf.tm_hour, buf.tm_min, buf.tm_sec));
	}

	// 计算背景大小
	float max_width = 0.0f;
	float line_height = dx11_menu::shortcut::size * 1.2f;
	for (const auto& line : lines) {
		ImVec2 textSize = ImGui::GetFont()->CalcTextSizeA(dx11_menu::shortcut::size, FLT_MAX, 0.0f, line.c_str());
		if (textSize.x > max_width) max_width = textSize.x;
	}

	float padding = 10.0f;
	ImVec2 pos(dx11_menu::shortcut::x, dx11_menu::shortcut::y);

	// 绘制文字
	ImU32 text_color = ImGui::ColorConvertFloat4ToU32(*(ImVec4*)dx11_menu::shortcut::color);
	float current_y = pos.y + padding;
	for (const auto& line : lines) {
		draw_list->AddText(ImGui::GetFont(), dx11_menu::shortcut::size, ImVec2(pos.x + padding, current_y), text_color, line.c_str());
		current_y += line_height;
	}
}

void dma_thread_func() {
	while (g_running) {
		auto original_list_ptr = g_playerList.load(std::memory_order_acquire);
		if (!original_list_ptr || original_list_ptr->empty()) {
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
			continue;
		}

		std::vector<AUAECharacter> temp_list = *original_list_ptr;

		update_dma_data_internal(g_hs_esp, temp_list);

		{
			std::lock_guard<std::mutex> lock(g_DataMutex);
			g_RenderList = std::move(temp_list);
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

void draw() {

	auto hs_esp = dma::Scatter_Initialize();

	static bool show_intro = true;
	static float intro_start_time = 0.0f;

	while (g_running) {
		dx11::Begin();

		if (show_intro) {
			if (intro_start_time == 0.0f) intro_start_time = ImGui::GetTime();

			float elapsed = ImGui::GetTime() - intro_start_time;
			if (elapsed > 3.0f) {
				show_intro = false;
			}
			else {
				ImDrawList* draw_list = ImGui::GetForegroundDrawList();

				// 全屏背景
				draw_list->AddRectFilled(ImVec2(0, 0), ImVec2((float)m_Engine.m_rect.w, (float)m_Engine.m_rect.h), IM_COL32(15, 15, 15, 255));

				// 文字
				const char* text = "VEX和平DMA";
				float font_size = 80.0f;
				ImVec2 text_size = ImGui::GetFont()->CalcTextSizeA(font_size, FLT_MAX, 0.0f, text);
				ImVec2 text_pos = ImVec2(
					(m_Engine.m_rect.w - text_size.x) * 0.5f,
					(m_Engine.m_rect.h - text_size.y) * 0.5f
				);

				float alpha = 0.0f;
				if (elapsed < 1.0f) alpha = elapsed; // 淡入
				else if (elapsed < 2.5f) alpha = 1.0f; // 保持
				else alpha = 1.0f - (elapsed - 2.5f) * 2.0f; // 快速淡出

				if (alpha < 0.0f) alpha = 0.0f;
				if (alpha > 1.0f) alpha = 1.0f;

				draw_list->AddText(ImGui::GetFont(), font_size, text_pos, ImGui::ColorConvertFloat4ToU32(ImVec4(0.00f, 0.90f, 1.00f, alpha)), text);

				dx11::End();
				continue;
			}
		}

		InputUtils::UpdateInput();
		if (InputUtils::is_key_pressed(dx11_menu::esp::menu_key)) {
			dx11_menu::esp::show_menu = !dx11_menu::esp::show_menu;
		}

		if (dx11_menu::esp::show_menu) {
			draw_menu();
		}

		auto draw_list = ImGui::GetForegroundDrawList();
		draw_shortcut_menu(draw_list);

		auto uworld = g_uworld.load(std::memory_order_acquire);

		if (!uworld) {
			dx11::End();
			continue;
		}

		auto CameraCacheEntry = uworld->m_NetDriver.m_ServerConnection.m_PlayerController.m_PlayerCameraManager.get_CameraCacheEntry();
		draw_item(draw_list, hs_esp, CameraCacheEntry);

		draw_player(draw_list, CameraCacheEntry);

		draw_vehicle(draw_list, hs_esp, CameraCacheEntry);

		draw_radar(draw_list, CameraCacheEntry);

		draw_physx(draw_list, CameraCacheEntry);

		recoil_control();
		draw_trigger(CameraCacheEntry);
		draw_aim(draw_list, CameraCacheEntry);

		//draw_all_physx_actors(draw_list, CameraCacheEntry);

		float current_trigger_fov = dx11_menu::trigger::fov;
		if (dx11_menu::trigger::dynamic_fov) {
			float game_fov = CameraCacheEntry.POV.FOV;
			if (game_fov > 0.1f) {
				current_trigger_fov = dx11_menu::trigger::fov * (90.0f / game_fov);
			}
		}

		if (dx11_menu::trigger::show_fov) {
			draw_list->AddCircle(
				ImVec2(m_Engine.m_rect.w / 2, m_Engine.m_rect.h / 2),
				current_trigger_fov,
				ImGui::ColorConvertFloat4ToU32(ImVec4(dx11_menu::esp::color_trigger_fov[0], dx11_menu::esp::color_trigger_fov[1], dx11_menu::esp::color_trigger_fov[2], dx11_menu::esp::color_trigger_fov[3])),
				100
			);
		}

		if (dx11_menu::trigger::show_aim_fov) {
			draw_list->AddCircle(
				ImVec2(m_Engine.m_rect.w / 2, m_Engine.m_rect.h / 2),
				dx11_menu::trigger::aim_fov,
				IM_COL32(255, 255, 0, 255), // 黄色
				100
			);
		}

		dx11::End();

	}

}


int main()
{
	auto ret = dma::init();
	g_hs_esp = dma::Scatter_Initialize();

	if (!ret) {
		std::println("dma初始化失败");
		std::cin.get();
		return -1;
	}
	dma::Refresh_MEDIUM();

	std::println("dma初始化成功");

	ret = m_Engine.init();

	/*if (!ret) {
		std::println("m_Engine初始化失败");
		std::cin.get();
		return -1;
	}
	std::println("m_Engine初始化成功");*/

	if (!InputUtils::InitInputDMA()) {
		std::println("InputDMA初始化失败");
	}
	else {
		std::println("InputDMA初始化成功");
	}

	InitWeaponTranslation();
	InitItemTranslation();

	if (PhysX3::init()) {
		std::println("PhysX3初始化成功");
	};

	dx11::init(0, 0, m_Engine.m_rect.w, m_Engine.m_rect.h);

	std::thread t1(read_data);
	std::thread t2(vehicle_update_thread);
	std::thread t3(item_update_thread); // 物资更新线程
	std::thread read_thread(dma_thread_func);
	read_thread.detach();

	draw();

	Config::Save();

	t1.join();
	t2.join();
	t3.join();




}
