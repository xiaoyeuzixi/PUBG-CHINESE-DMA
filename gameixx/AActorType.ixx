export module AActorType;
import std;

export enum class EntityType
{
	Unknown = 0,// 未知
	Player = 1, // 玩家
	AI = 2, //  AI
	DroppedItem, // 掉落物品
	DroppedItemGroup, // 刷新物品
	Item, // 普通物品
	Vehicle, // 汽车
	Drug, // 药物
	Armor, // 防具
	Accessories, // 配件
	Attached, //装备配件
	Weapon, // 手持武器
	AirDrop,// 空投
	DeadBox, // 死亡盒子
	Grenade, // 投掷物品
	Project, // 投掷物品
	Widget,
	Map,
	Other,
	Wheel,
	key
};


export class AActorType {
public:
	static EntityType get_type(std::string name );
private:

	static inline std::unordered_map<std::string, EntityType> EntityPlayerLists = {

		{ "BP_PlayerPawn_C",  EntityType::Player },
		{ "BP_PlayerPawn_CG35_C",  EntityType::Player },
		{ "BP_PlayerPawn_Chimera_C",  EntityType::Player },
		{ "BP_PlayerPawn_ChimeraC",  EntityType::Player },
		{ "BP_PlaneCharacter_PUBGPlane_CG028C",  EntityType::Player },
		{ "BP_PlaneCharacter_PUBGPlane_CG028_C",  EntityType::Player },
		{ "BP_PlayerPawn_Desert_CG35_C",  EntityType::Player },
		{ "BP_PlayerPawn_Desert_CG35.C",  EntityType::Player },
		{ "PlayerMale_A_C",  EntityType::Player },
		{ "PlayerFemale_A",  EntityType::Player },
		{ "PlayerFemale_A_C",  EntityType::Player},
		{ "BP_TrainPlayerPawn_C",  EntityType::Player},
		{ "AIPawn_Base_C", EntityType::AI},
		{ "AIPawn_Base_Female_C", EntityType::AI},
		{ "AIPawn_Base_Male_C", EntityType::AI},
		{ "AIPawn_Base_Pillar_C", EntityType::AI},
		{ "AIPawn_Base_Female_Pillar_C", EntityType::AI},
		{ "AIPawn_Base_Male_Pillar_C", EntityType::AI},
		{ "UltAIPawn_Base_C", EntityType::AI},
		{ "UltAIPawn_Base_Female_C", EntityType::AI},
		{ "UltAIPawn_Base_Male_C", EntityType::AI},
		{ "ZDF2_NPC_Runner_C", EntityType::AI},
		{ "ZDF2_NPC_Burning_C", EntityType::AI},
		{ "ZDF2_NPC_Tanker_C", EntityType::AI},
		{ "ZDF2_NPC_Female_C", EntityType::AI},
		{ "ZombieNpcNewPawn_Tanker_C", EntityType::AI},
		{ "UltAIPawn_Base_Pillar_C", EntityType::AI},
		{ "UltAIPawn_Base_Female_Pillar_C", EntityType::AI},
		{ "UltAIPawn_Base_Male_Pillar_C", EntityType::AI},
		{ "BP_MarketAI_Pawn_C", EntityType::AI},
		{ "BP_PlayerPawn_TDM_TPP_C", EntityType::Player},
		{ "BP_PlayerPawn_Neon_C", EntityType::Player},
	};

	static inline std::unordered_map<std::string, EntityType> EntityVehicleLists = {
		//车辆
		{"VH_Blanc_C", EntityType::Vehicle},
		{"VH_Picobus_C", EntityType::Vehicle},
		{"VH_DesertCar_C", EntityType::Vehicle},
		{"VH_Drift_001_New_C", EntityType::Vehicle},
		{"VH_Horse_1_C", EntityType::Vehicle},
		{"VH_Horse_2_C", EntityType::Vehicle},
		{"VH_Horse_3_C", EntityType::Vehicle},
		{"VH_Horse_4_C", EntityType::Vehicle},
		{"VH_4SportCar_C", EntityType::Vehicle},
		{"VH_UAZ01_New_C", EntityType::Vehicle},
		{"VH_UAZ02_New_C", EntityType::Vehicle},
		{"VH_UAZ03_New_C", EntityType::Vehicle},
		{"VH_Dacia_New_C", EntityType::Vehicle},
		{"VH_Dacia_1_New_C", EntityType::Vehicle},
		{"VH_Dacia_2_New_C", EntityType::Vehicle},
		{"VH_Dacia_3_New_C", EntityType::Vehicle},
		{"BP_VH_Buggy_C", EntityType::Vehicle},
		{"BP_VH_Buggy_2_C", EntityType::Vehicle},
		{"VH_CoupeRB_1_C", EntityType::Vehicle},
		{"VH_Motorcycle_1_C", EntityType::Vehicle},
		{"VH_Motorcycle_C", EntityType::Vehicle},
		{"VH_StationWagon_New_C", EntityType::Vehicle},
		{"BP_VH_Bigfoot_C", EntityType::Vehicle},
		{"VH_ATV1_C", EntityType::Vehicle},
		{"Mirado_close_1_C", EntityType::Vehicle},
		{"Mirado_open_1_C", EntityType::Vehicle},
		{"PickUp_01_C", EntityType::Vehicle},
		{"PickUp_02_C", EntityType::Vehicle},
		{"PickUp_03_C", EntityType::Vehicle},
		{"PickUp_04_C", EntityType::Vehicle},
		{"PickUp_05_C", EntityType::Vehicle},
		{"PickUp_06_C", EntityType::Vehicle},
		{"PickUp_07_C", EntityType::Vehicle},
		{"PickUp_08_C", EntityType::Vehicle},
		{"Rony_01_C", EntityType::Vehicle},
		{"BP_VH_Tuk_1_C", EntityType::Vehicle},
		{"VH_Snowbike_02_C", EntityType::Vehicle},
		{"VH_Snowmobile_C", EntityType::Vehicle},
		{"LadaNiva_01_C", EntityType::Vehicle},
		{"VH_Scooter_C", EntityType::Vehicle},
		{"VH_MotorcycleCart_1_C", EntityType::Vehicle},
		{"VH_MiniBus_01_C", EntityType::Vehicle},
		{"VH_BRDM_C", EntityType::Vehicle},
		{"VH_Mountainbike_Training_C", EntityType::Vehicle},
		{"VH_PG117_C", EntityType::Vehicle},
		{"AquaRail_1_C", EntityType::Vehicle},
		{"VH_BBCar_C", EntityType::Vehicle},
	};

	static inline std::unordered_map<std::string, EntityType> EntityItemLists = {
	

		//步枪
		{"BP_Rifle_M762_Wrapper_C", EntityType::Item},
		{"BP_TrainingBoxListWrapper_C", EntityType::Item},
		{"BP_Rifle_Groza_Wrapper_C", EntityType::Item},
		{"BP_Rifle_Mk47_Wrapper_C", EntityType::Item},
		{"BP_Rifle_HoneyBadger_Wrapper_C", EntityType::Item},
		{"BP_Rifle_ACE32_Wrapper_C", EntityType::Item},
		{"BP_Rifle_ARX200_Wrapper_C", EntityType::Item},
		{"BP_Rifle_AKM_Wrapper_C", EntityType::Item},

		{"BP_Rifle_QBZ_Wrapper_C", EntityType::Item},
		{"BP_Rifle_AUG_Wrapper_C", EntityType::Item},
		{"BP_Rifle_VAL_Wrapper_C", EntityType::Item},
		{"BP_Rifle_Famas_Wrapper_C", EntityType::Item},
		{"BP_Rifle_G36_Wrapper_C", EntityType::Item},
		{"BP_Rifle_M416_Wrapper_C", EntityType::Item},
		{"BP_Rifle_SCAR_Wrapper_C", EntityType::Item},
		{"BP_Rifle_M16A4_Wrapper_C", EntityType::Item},

		//射手步枪
		{"BP_WEP_Mk14_Pickup_C", EntityType::Item},
		{"BP_Sniper_Mini14_Wrapper_C", EntityType::Item},
		{"BP_Sniper_M1Garand_Wrapper_C", EntityType::Item},
		{"BP_Sniper_VSS_Wrapper_C", EntityType::Item},
		{"BP_Sniper_SKS_Wrapper_C", EntityType::Item},
		{"BP_Sniper_SLR_Wrapper_C", EntityType::Item},
		{"BP_Sniper_MK12_Wrapper_C", EntityType::Item},
		{"BP_Sniper_QBU_Wrapper_C", EntityType::Item},
		{"BP_Sniper_MK20_Wrapper_C", EntityType::Item},
		{"BP_Rifle_M417_Wrapper_C", EntityType::Item},


		//狙击枪
		{"BP_Sniper_AS50_Wrapper_C", EntityType::Item},
		{"BP_Sniper_M24_Wrapper_C", EntityType::Item},
		{"BP_Sniper_AMR_Wrapper_C", EntityType::Item},
		{"BP_Sniper_M200_Wrapper_C", EntityType::Item},
		{"BP_Sniper_AWM_Wrapper_C", EntityType::Item},
		{"BP_Sniper_Kar98k_Wrapper_C", EntityType::Item},
		{"BP_Sniper_Mosin_Wrapper_C", EntityType::Item},
		{"BP_Sniper_Win94_Wrapper_C", EntityType::Item},
		{"BP_Sniper_SVD_Wrapper_C", EntityType::Item},


		//冲锋枪
		{"BP_MachineGun_MP7_Wrapper_C", EntityType::Item},
		{"BP_MachineGun_MP7_C", EntityType::Item},
		{"BP_MachineGun_MP5K_Wrapper_C", EntityType::Item},
		{"BP_MachineGun_AKS74U_Wrapper_C", EntityType::Item},
		{"BP_MachineGun_PP19_Wrapper_C", EntityType::Item},
		{"BP_MachineGun_JS9_Wrapper_C", EntityType::Item},
		{"BP_MachineGun_P90CG17_Wrapper_C", EntityType::Item},
		{"BP_MachineGun_TommyGun_Wrapper_C", EntityType::Item},
		{"BP_MachineGun_Vector_Wrapper_C", EntityType::Item},
		{"BP_MachineGun_UMP9_Wrapper_C", EntityType::Item},
		{"BP_MachineGun_Uzi_Wrapper_C", EntityType::Item},

		//散弹枪
		{"BP_ShotGun_DP12_Wrapper_C", EntityType::Item},
		{"BP_ShotGun_SPAS-12_Wrapper_C", EntityType::Item},
		{"BP_ShotGun_S12K_Wrapper_C", EntityType::Item},
		{"BP_ShotGun_AA12_Wrapper_C", EntityType::Item},
		{"BP_ShotGun_S1897_Wrapper_C", EntityType::Item},
		{"BP_ShotGun_S686_Wrapper_C", EntityType::Item},
		{"BP_ShotGun_SawedOff_Wrapper_C", EntityType::Item},


		//手枪
		{"BP_Pistol_DesertEagle_Wrapper_C", EntityType::Item},
		{"BP_Pistol_TMP_Wrapper_C", EntityType::Item},
		{"BP_Pistol_Vz61_Wrapper_C", EntityType::Item},
		{"BP_Pistol_R45_Wrapper_C", EntityType::Item},
		{"BP_Pistol_P18C_Wrapper_C", EntityType::Item},
		{"BP_Pistol_R1895_Wrapper_C", EntityType::Item},
		{"BP_Pistol_ColtAnaconda_Wrapper_C", EntityType::Item},
		{"BP_Pistol_P1911_Wrapper_C", EntityType::Item},
		{"BP_Pistol_FN57_Wrapper_C", EntityType::Item},
		{"BP_Pistol_P92_Wrapper_C", EntityType::Item},
		{"BP_Pistol_RevivalFlaregun_Wrapper_C", EntityType::Item},
		{"BP_Pistol_Flaregun_Wrapper_C", EntityType::Item},


		//机枪
		{"BP_Other_MG3_Wrapper_C", EntityType::Item},
		{"BP_Other_PKM_Wrapper_C", EntityType::Item},
		{"BP_Other_SIG_M338_Wrapper_C", EntityType::Item},
		{"BP_Other_MG36_Wrapper_C", EntityType::Item},
		{"BP_Other_M249_Wrapper_C", EntityType::Item},
		{"BP_Other_DP28_Wrapper_C", EntityType::Item},

		//其他
		{ "BP_Other_StunGun_Wrapper_C", EntityType::Item },
		{ "BP_Other_Shield_Wrapper_C", EntityType::Item },
		{ "BP_Other_Mortar_Wrapper_C", EntityType::Item },
		{ "BP_Other_Mortar_C", EntityType::Item },
		{ "BP_Other_CrossBow_Wrapper_C", EntityType::Item },
		{ "BP_Other_CrossbowBorderland_Wrapper_C", EntityType::Item },
		{ "BP_Other_HuntingBow_Wrapper_C", EntityType::Item },
		{ "BP_Other_CompoundBow_Wrapper_C", EntityType::Item },
		{ "BP_WEP_Pan_Pickup_C", EntityType::Item },
		{ "BP_WEP_Sickle_Pickup_C", EntityType::Item },
		{ "BP_WEP_Cowbar_Pickup_C", EntityType::Item },
		{ "BP_WEP_Machete_Pickup_C", EntityType::Item },
		{ "BP_WEP_DualBlades_Pickup_C", EntityType::Item },
		{ "BP_revivalAED_Pickup_C", EntityType::Item },
		{ "PickUp_BP_FlyHorse_C", EntityType::Item },
		{ "GasCanBattery_Destructible_Pickup_C", EntityType::Item },
		{ "PickUp_BP_Mountainbike1_C", EntityType::Item },
		{ "MilitarySupplyBoxBase_Baltic_Classic_C", EntityType::Item },
		{ "BP_Grenade_ADS_Weapon_Wrapper_C", EntityType::Item },
		{ "BP_ShotGun_NS2000_Wrapper_C", EntityType::Item },
		{ "BP_Med_SignalBattery_C", EntityType::Item },
		{ "PainKiller_Pickup_C", EntityType::Item },
		{ "MedKit_Pickup_C", EntityType::Item },
		{ "JammerPack_C", EntityType::Item },
		{ "Item_Head_Repair_Kit_C", EntityType::Item },
		{ "Item_Armor_Repair_Kit_C", EntityType::Item },
		{ "Item_EmergencyPickup_Pickup_C", EntityType::Item },
		{ "Ghillie_01_C", EntityType::Item },
		{ "Ghillie_02_C", EntityType::Item },
		{ "Ghillie_03_C", EntityType::Item },
		{ "Ghillie_04_C", EntityType::Item },
		{ "Ghillie_05_C", EntityType::Item },
		{ "Ghillie_06_C", EntityType::Item },
		{ "BP_CG035_WEP_LambLeg_Pickup_C", EntityType::Item },
		{ "BP_PickupWrapper_Naan_C", EntityType::Item },
		{ "BP_BrozenHorse_Wrapper_C", EntityType::Item },
		{ "BP_Pickup_Finger_C", EntityType::Item },
		{ "BP_NineColoredDeer_PickUpWrapper_C", EntityType::Item },
		{ "CG035_SmallRedPacket_Wrapper_C", EntityType::Item },
		{ "BP_CG035_BigGoldWrapper_C", EntityType::Item },
		{ "BP_FeiTian_PickUpWrapper_C", EntityType::Item },
		{ "BP_PickupWrapper_Key_C", EntityType::Item },
		{ "BP_Theme_BlackCardWrapper_C", EntityType::Item },
		{ "MilitarySupplyBoxBase_Baltic_Theme_C", EntityType::Item },
		{ "Item_Key_Pickup_C", EntityType::Item },
		{ "BP_Grenade_Weapon_Wrapper_Thermite_C", EntityType::Item },
		{ "BP_Grenade_Weapon_Wrapper_EMP_C", EntityType::Item },
		
		// 补全缺失物品
		{ "BP_QT_S_Pickup_C", EntityType::Item },
		{ "BP_WB_CheekPad_Pickup_C", EntityType::Item },
		{ "BP_WB_Fold_Pickup_C", EntityType::Item },
		{ "BP_WB_L_Pickup_C", EntityType::Item },
		{ "BP_WB_HeavyStock_Pickup_C", EntityType::Item },
		{ "Item_Attach_Weapon_Upper_Ext_Pickup_C", EntityType::Item },
		{ "Item_Weapon_Magazine_Extended_Large_Pickup_C", EntityType::Item },
		{ "Item_Ammo_762mm_Pickup_C", EntityType::Item },
		{ "Item_Ammo_556mm_Pickup_C", EntityType::Item },
		{ "Item_Ammo_300Magnum_Pickup_C", EntityType::Item },
		{ "Item_Ammo_45ACP_Pickup_C", EntityType::Item },
		{ "Item_Ammo_9mm_Pickup_C", EntityType::Item },
		{ "Item_Ammo_12Guage_Pickup_C", EntityType::Item },
		{ "Item_Ammo_Bolt_Pickup_C", EntityType::Item },
		{ "ProjGrenade_Pickup_C", EntityType::Item },
		{ "ProjSmokeBomb_Pickup_C", EntityType::Item },
		{ "ProjMolotov_Pickup_C", EntityType::Item },
		{ "ProjFlashBang_Pickup_C", EntityType::Item },
		{ "ProjBlueZone_Pickup_C", EntityType::Item },
		{ "Item_Weapon_SpikeTrap_Pickup_C", EntityType::Item },
		{ "Item_Weapon_C4_Pickup_C", EntityType::Item },
		{ "Item_Weapon_Pan_Pickup_C", EntityType::Item },
		{ "CG30_ActivityCommonTreasureBox_C", EntityType::Item },
		{ "Carapackage_RedBox_C", EntityType::AirDrop },
		{ "Carapackage_WhiteBox_C", EntityType::AirDrop },
		{ "BP_CG023AirDropBox_C", EntityType::AirDrop },



		//瞄具
		{ "BP_MZJ_HD_Pickup_C", EntityType::Item },
		{ "BP_MZJ_2X_Pickup_C", EntityType::Item },
		{ "BP_MZJ_3X_Pickup_C", EntityType::Item },
		{ "BP_MZJ_4X_Pickup_C", EntityType::Item },
		{ "BP_MZJ_6X_Pickup_C", EntityType::Item },
		{ "BP_MZJ_8X_Pickup_C", EntityType::Item },
		{ "BP_MZJ_SideRMR_Pickup_C", EntityType::Item },
		{ "BP_MZJ_QX_Pickup_C", EntityType::Item },
		{ "BP_MZJ_8X_Ballistics_Pickup_C", EntityType::Item },

		//弹匣
		{ "BP_DJ_Large_EQ_Pickup_C", EntityType::Item },
		{ "BP_DJ_Large_E_Pickup_C", EntityType::Item },
		{ "BP_DJ_Large_Q_Pickup_C", EntityType::Item },

		{ "BP_DJ_Sniper_EQ_Pickup_C", EntityType::Item },
		{ "BP_DJ_Sniper_Q_Pickup_C", EntityType::Item },
		{ "BP_DJ_Sniper_E_Pickup_C", EntityType::Item },

		{ "BP_DJ_Mid_EQ_Pickup_C", EntityType::Item },
		{ "BP_DJ_Mid_E_Pickup_C", EntityType::Item },
		{ "BP_DJ_Mid_Q_Pickup_C", EntityType::Item },

		{ "BP_DJ_ShotGun_Pickup_C", EntityType::Item },


		//握把
		{ "BP_WB_Lasersight_Pickup_C", EntityType::Item },
		{ "BP_WB_ThumbGrip_Pickup_C", EntityType::Item },
		{ "BP_WB_HalfGrip_Pickup_C", EntityType::Item },
		{ "BP_WB_LightGrip_Pickup_C", EntityType::Item },
		{ "BP_WB_Vertical_Pickup_C", EntityType::Item },
		{ "BP_WB_Angled_Pickup_C", EntityType::Item },


		//枪托
		{ "BP_QT_Sniper_Pickup_C", EntityType::Item },
		{ "BP_ZDD_Sniper_Pickup_C", EntityType::Item },
		{ "BP_QT_A_Pickup_C", EntityType::Item },
		{ "BP_QT_ZH_Pickup_C", EntityType::Item },
		{ "BP_QT_UZI_Pickup_C", EntityType::Item },
		{ "BP_ZDD_Crossbow_Q_Pickup_C", EntityType::Item },

		//枪口
		{ "BP_QK_Large_Compensator_Pickup_C", EntityType::Item },
		{ "BP_QK_Large_Suppressor_Pickup_C", EntityType::Item },
		{ "BP_QK_Large_FlashHider_Pickup_C", EntityType::Item },

		{ "BP_QK_Sniper_Compensator_Pickup_C", EntityType::Item },
		{ "BP_QK_Sniper_Suppressor_Pickup_C", EntityType::Item },
		{ "BP_QK_Sniper_FlashHider_Pickup_C", EntityType::Item },

		{ "BP_QK_Mid_Compensator_Pickup_C", EntityType::Item },
		{ "BP_QK_Mid_Suppressor_Pickup_C", EntityType::Item },
		{ "BP_QK_Mid_FlashHider_Pickup_C", EntityType::Item },

		{ "BP_QK_DuckBill_Pickup_C", EntityType::Item },
		{ "BP_QK_Choke_Pickup_C", EntityType::Item },

		//子弹
		{ "BP_Ammo_9mm_Pickup_C", EntityType::Item },
		{ "BP_Ammo_57mm_Pickup_C", EntityType::Item },
		{ "BP_Ammo_556mm_Pickup_C", EntityType::Item },
		{ "BP_Ammo_762mm_Pickup_C", EntityType::Item },
		{ "BP_Ammo_300Magnum_Pickup_C", EntityType::Item },
		{ "BP_Ammo_12Guage_Pickup_C", EntityType::Item },
		{ "BP_Ammo_Bolt_Pickup_C", EntityType::Item },
		{ "BP_Ammo_50BMG_Pickup_C", EntityType::Item },
		{ "BP_Ammo_45ACP_Pickup_C", EntityType::Item },
		{ "BP_Ammo_RevivalFlare_Pickup_C", EntityType::Item },
		{ "BP_Ammo_Flare_Pickup_C", EntityType::Item },
		{ "BP_Ammo_MortarAmmo_HE_Pickup_C", EntityType::Item },



		//装备
		{ "PickUp_BP_Helmet_Lv1_C", EntityType::Item },
		{ "PickUp_BP_Helmet_Lv1_B_C", EntityType::Item },
		{ "PickUp_BP_Helmet_Lv2_C", EntityType::Item },
		{ "PickUp_BP_Helmet_Lv2_B_C", EntityType::Item },
		{ "PickUp_BP_Helmet_Lv3_C", EntityType::Item },
		{ "PickUp_BP_Helmet_Lv3_B_C", EntityType::Item },

		{ "PickUp_BP_Bag_Lv1_C", EntityType::Item },
		{ "PickUp_BP_Bag_Lv1_B_C", EntityType::Item },
		{ "PickUp_BP_Bag_Lv2_C", EntityType::Item },
		{ "PickUp_BP_Bag_Lv2_B_C", EntityType::Item },
		{ "PickUp_BP_Bag_Lv3_C", EntityType::Item },
		{ "PickUp_BP_Bag_Lv3_B_C", EntityType::Item },

		{ "PickUp_BP_Armor_Lv1_C", EntityType::Item },
		{ "PickUp_BP_Armor_Lv1_B_C", EntityType::Item },
		{ "PickUp_BP_Armor_Lv2_C", EntityType::Item },
		{ "PickUp_BP_Armor_Lv2_B_C", EntityType::Item },
		{ "PickUp_BP_Armor_Lv3_C", EntityType::Item },
		{ "PickUp_BP_Armor_Lv3_B_C", EntityType::Item },


		//投掷物
		{ "BP_Grenade_Shoulei_Weapon_Wrapper_C", EntityType::Item },
		{ "BP_Grenade_Stun_Weapon_Wrapper_C", EntityType::Item },
		{ "BP_Grenade_Smoke_Weapon_Wrapper_C", EntityType::Item },
		{ "BP_Grenade_Burn_Weapon_Wrapper_C", EntityType::Item },
		{ "BP_Grenade_Weapon_Wrapper_EMP_C", EntityType::Item },


		//药品
		{ "Adrenaline_Pickup_C", EntityType::Item },
		{ "FirstAidbox_Pickup_C", EntityType::Item },
		{ "Firstaid_Pickup_C", EntityType::Item },
		{ "Bandage_Pickup_C", EntityType::Item },
		{ "Injection_Pickup_C", EntityType::Item },
		{ "Drink_Pickup_C", EntityType::Item },
		{ "EnergyDrink_Pickup_C", EntityType::Item },
		{ "Pills_Pickup_C", EntityType::Item },
		{ "IcedTea_Pickup_C", EntityType::Item },
	


		////步枪
		//{ "BP_Rifle_M762_C",EntityType::Item},
		//{ "BP_Rifle_Groza_C",EntityType::Item},
		//{ "BP_Rifle_Mk47_C",EntityType::Item},
		//{ "BP_Rifle_HoneyBadger_C",EntityType::Item},
		//{ "BP_Rifle_ACE32_C",EntityType::Item},
		//{ "BP_Rifle_ARX200_C",EntityType::Item},
		//{ "BP_Rifle_AKM_C",EntityType::Item},

		//{ "BP_Rifle_QBZ_C",EntityType::Item},
		//{ "BP_Rifle_AUG_C",EntityType::Item},
		//{ "BP_Rifle_VAL_C",EntityType::Item},
		//{ "BP_Rifle_Famas_C",EntityType::Item},
		//{ "BP_Rifle_G36_C",EntityType::Item},
		//{ "BP_Rifle_M416_C",EntityType::Item},
		//{ "BP_Rifle_SCAR_C",EntityType::Item},
		//{ "BP_Rifle_M16A4_C",EntityType::Item},

		//	//射手步枪
		//{ "BP_Sniper_Mk14_C",EntityType::Item},
		//{ "BP_Sniper_Mini14_C",EntityType::Item},
		//{ "BP_Sniper_M1Garand_C",EntityType::Item},
		//{ "BP_Sniper_VSS_C",EntityType::Item},
		//{ "BP_Sniper_SKS_C",EntityType::Item},
		//{ "BP_Sniper_SLR_C",EntityType::Item},
		//{ "BP_Sniper_MK12_C",EntityType::Item},
		//{ "BP_Sniper_QBU_C",EntityType::Item},
		//{ "BP_Sniper_MK20_C",EntityType::Item},
		//{ "BP_Rifle_M417_C",EntityType::Item},


		//	//狙击枪
		//{ "BP_Sniper_M24_C",EntityType::Item},
		//{ "BP_Sniper_AMR_C",EntityType::Item},
		//{ "BP_Sniper_M200_C",EntityType::Item},
		//{ "BP_Sniper_AWM_C",EntityType::Item},
		//{ "BP_Sniper_Kar98K_C",EntityType::Item},
		//{ "BP_Sniper_Mosin_C",EntityType::Item},
		//{ "BP_Sniper_Win94_C",EntityType::Item},
		//{ "BP_Sniper_SVD_C",EntityType::Item},


		//	//冲锋枪
		//{ "BP_MachineGun_MP5K_C",EntityType::Item},
		//{ "BP_MachineGun_AKS74U_C",EntityType::Item},
		//{ "BP_MachineGun_PP19_C",EntityType::Item},
		//{ "BP_MachineGun_JS9_C",EntityType::Item},
		//{ "BP_MachineGun_P90CG17_C",EntityType::Item},
		//{ "BP_MachineGun_TommyGun_C",EntityType::Item},
		//{ "BP_MachineGun_Vector_C",EntityType::Item},
		//{ "BP_MachineGun_UMP9_C",EntityType::Item},
		//{ "BP_MachineGun_Uzi_C",EntityType::Item},

		//	//散弹枪
		//{ "BP_ShotGun_DP12_C",EntityType::Item},
		//{ "BP_ShotGun_SPAS-12_C",EntityType::Item},
		//{ "BP_ShotGun_S12K_C",EntityType::Item},
		//{ "BP_ShotGun_AA12_C",EntityType::Item},
		//{ "BP_ShotGun_S1897_C",EntityType::Item},
		//{ "BP_ShotGun_S686_C",EntityType::Item},
		//{ "BP_ShotGun_SawedOff_C",EntityType::Item},


		//	//手枪
		//{ "BP_Pistol_DesertEagle_C",EntityType::Item},
		//{ "BP_Pistol_TMP_C",EntityType::Item},
		//{ "BP_Pistol_Vz61_C",EntityType::Item},
		//{ "BP_Pistol_R45_C",EntityType::Item},
		//{ "BP_Pistol_P18C_C",EntityType::Item},
		//{ "BP_Pistol_R1895_C",EntityType::Item},
		//{ "BP_Pistol_ColtAnaconda_C",EntityType::Item},
		//{ "BP_Pistol_P1911_C",EntityType::Item},
		//{ "BP_Pistol_FN57_C",EntityType::Item},
		//{ "BP_Pistol_P92_C",EntityType::Item},
		//{ "BP_Pistol_RevivalFlaregun_C",EntityType::Item},
		//{ "BP_Pistol_Flaregun_C",EntityType::Item},


		//	//机枪
		//{ "BP_Other_MG3_C",EntityType::Item},
		//{ "BP_Other_PKM_C",EntityType::Item},
		//{ "BP_Other_SIG_M338_C",EntityType::Item},
		//{ "BP_Other_MG36_C",EntityType::Item},
		//{ "BP_Other_M249_C",EntityType::Item},
		//{ "BP_Other_DP28_C",EntityType::Item},

		//	//其他
		//{ "BP_Other_Shield_new_C",EntityType::Item},
		//{ "BP_Other_CrossBow_C",EntityType::Item},
		//{ "BP_Other_CrossbowBorderland_C",EntityType::Item},
		//{ "BP_Other_HuntingBow_C",EntityType::Item},
		//{ "BP_Other_CompoundBow_C",EntityType::Item},
		//{ "BP_WEP_Pan_C",EntityType::Item},
		//{ "BP_WEP_Sickle_C",EntityType::Item},
		//{ "BP_WEP_Cowbar_C",EntityType::Item},
		//{ "BP_WEP_Machete_C",EntityType::Item},

		//	//投掷物
		//{ "BP_Grenade_Shoulei_Weapon_C",EntityType::Item},
		//{ "BP_Grenade_Stun_Weapon_C",EntityType::Item},
		//{ "BP_Grenade_Smoke_Weapon_C",EntityType::Item},
		//{ "BP_Grenade_Burn_Weapon_C",EntityType::Item},
		//{ "BP_Grenade_Weapon_EMP_C",EntityType::Item},

	};


};

EntityType AActorType::get_type(std::string name)
{
	auto it = EntityPlayerLists.find(name);
	if (it != EntityPlayerLists.end()) {
		return it->second;
	}

	it = EntityItemLists.find(name);
	if (it != EntityItemLists.end()) {
		return it->second;
	}

	it = EntityVehicleLists.find(name);
	if (it != EntityVehicleLists.end()) {
		return it->second;
	}

	if (name.find("PickUpListWrapperActor") != std::string::npos) return EntityType::DeadBox;
	if (name.find("CharacterDeadInventoryBox_C") != std::string::npos) return EntityType::DeadBox;
	if (name.find("DeathDropItemPackage_C") != std::string::npos) return EntityType::DeadBox;
	if (name.find("AirDropListWrapperActor") != std::string::npos) return EntityType::AirDrop;
	if (name.find("PlayerDeadInventoryBox") != std::string::npos) return EntityType::AirDrop;
	if (name.find("BP_AirDropBox_C") != std::string::npos) return EntityType::AirDrop;
	if (name.find("AirDropBoxActor") != std::string::npos) return EntityType::AirDrop;
	if (name.find("DroneAirDropBoxActor") != std::string::npos) return EntityType::AirDrop;
	if (name.find("AirDropPlane") != std::string::npos) return EntityType::AirDrop;
	if (name.find("BP_AirDropBox_BoxingChampion_C") != std::string::npos) return EntityType::AirDrop;
	if (name.find("BP_ZhengDuoBox_C") != std::string::npos) return EntityType::AirDrop;
	if (name.find("Carapackage") != std::string::npos) return EntityType::AirDrop;
	if (name.find("TreasureBox_Sub_Desert_C") != std::string::npos) return EntityType::AirDrop;
	if (name.find("BP_Airplane_AlwaysRdevant_C") != std::string::npos) return EntityType::AirDrop;

	if (name.find("ProjGrenade") != std::string::npos) return EntityType::Project;
	if (name.find("ProjMolotov") != std::string::npos) return EntityType::Project;
	if (name.find("BP_Grenade_Shoulei_C") != std::string::npos) return EntityType::Project;
	if (name.find("BP_Grenade_Burn_C") != std::string::npos) return EntityType::Project;

	return EntityType::Unknown;
}
