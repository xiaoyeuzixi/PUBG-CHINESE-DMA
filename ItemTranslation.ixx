module;
#include <string>
#include <unordered_map>

export module ItemTranslation;

import dx11_menu;
import std;

// Internal map storage
using ItemMapType = std::unordered_map<std::string, std::string>;
export ItemMapType ItemMap;
export ItemMapType VehicleMap;

// Helper to convert UTF-8 string literal to std::string
std::string from_u8(const char8_t* str) {
    return std::string(reinterpret_cast<const char*>(str));
}

export void InitItemTranslation() {
    ItemMap.reserve(500); // Pre-allocate

    // --- 武器列表 (Wrapper & Base) ---
    ItemMap["BP_Rifle_M762_Wrapper_C"] = from_u8(u8"M762突击步枪");
    ItemMap["BP_Rifle_M762_C"] = from_u8(u8"M762突击步枪");
    ItemMap["BP_Rifle_Groza_Wrapper_C"] = from_u8(u8"Groza突击步枪");
    ItemMap["BP_Rifle_Groza_C"] = from_u8(u8"Groza突击步枪");
    ItemMap["BP_Rifle_Mk47_Wrapper_C"] = from_u8(u8"MK47突击步枪");
    ItemMap["BP_Rifle_Mk47_C"] = from_u8(u8"MK47突击步枪");
    ItemMap["BP_Rifle_HoneyBadger_Wrapper_C"] = from_u8(u8"蜜獾突击步枪");
    ItemMap["BP_Rifle_HoneyBadger_C"] = from_u8(u8"蜜獾突击步枪");
    ItemMap["BP_Rifle_ACE32_Wrapper_C"] = from_u8(u8"ACE32突击步枪");
    ItemMap["BP_Rifle_ACE32_C"] = from_u8(u8"ACE32突击步枪");
    ItemMap["BP_Rifle_ARX200_Wrapper_C"] = from_u8(u8"ARX突击步枪");
    ItemMap["BP_Rifle_ARX200_C"] = from_u8(u8"ARX突击步枪");
    ItemMap["BP_Rifle_AKM_Wrapper_C"] = from_u8(u8"AKM突击步枪");
    ItemMap["BP_Rifle_AKM_C"] = from_u8(u8"AKM突击步枪");
    ItemMap["BP_Rifle_QBZ_Wrapper_C"] = from_u8(u8"QBZ突击步枪");
    ItemMap["BP_Rifle_QBZ_C"] = from_u8(u8"QBZ突击步枪");
    ItemMap["BP_Rifle_AUG_Wrapper_C"] = from_u8(u8"AUG突击步枪");
    ItemMap["BP_Rifle_AUG_C"] = from_u8(u8"AUG突击步枪");
    ItemMap["BP_Rifle_VAL_Wrapper_C"] = from_u8(u8"AC-VAL突击步枪");
    ItemMap["BP_Rifle_VAL_C"] = from_u8(u8"AC-VAL突击步枪");
    ItemMap["BP_Rifle_Famas_Wrapper_C"] = from_u8(u8"FAMAS突击步枪");
    ItemMap["BP_Rifle_Famas_C"] = from_u8(u8"FAMAS突击步枪");
    ItemMap["BP_Rifle_G36_Wrapper_C"] = from_u8(u8"G36C突击步枪");
    ItemMap["BP_Rifle_G36_C"] = from_u8(u8"G36C突击步枪");
    ItemMap["BP_Rifle_M416_Wrapper_C"] = from_u8(u8"M416突击步枪");
    ItemMap["BP_Rifle_M416_C"] = from_u8(u8"M416突击步枪");
    ItemMap["BP_Rifle_SCAR_Wrapper_C"] = from_u8(u8"SCAR-L突击步枪");
    ItemMap["BP_Rifle_SCAR_C"] = from_u8(u8"SCAR-L突击步枪");
    ItemMap["BP_Rifle_M16A4_Wrapper_C"] = from_u8(u8"M16A4突击步枪");
    ItemMap["BP_Rifle_M16A4_C"] = from_u8(u8"M16A4突击步枪");

    // 射手步枪
    ItemMap["BP_WEP_Mk14_Pickup_C"] = from_u8(u8"MK14射手步枪");
    ItemMap["BP_Sniper_Mk14_Wrapper_C"] = from_u8(u8"MK14射手步枪");
    ItemMap["BP_Sniper_Mk14_C"] = from_u8(u8"MK14射手步枪");
    ItemMap["BP_Sniper_Mini14_Wrapper_C"] = from_u8(u8"Mini14射手步枪");
    ItemMap["BP_Sniper_Mini14_C"] = from_u8(u8"Mini14射手步枪");
    ItemMap["BP_Sniper_M1Garand_Wrapper_C"] = from_u8(u8"M1加兰德射手步枪");
    ItemMap["BP_Sniper_M1Garand_C"] = from_u8(u8"M1加兰德射手步枪");
    ItemMap["BP_Sniper_VSS_Wrapper_C"] = from_u8(u8"VSS射手步枪");
    ItemMap["BP_Sniper_VSS_C"] = from_u8(u8"VSS射手步枪");
    ItemMap["BP_Sniper_SKS_Wrapper_C"] = from_u8(u8"SKS射手步枪");
    ItemMap["BP_Sniper_SKS_C"] = from_u8(u8"SKS射手步枪");
    ItemMap["BP_Sniper_SLR_Wrapper_C"] = from_u8(u8"SLR射手步枪");
    ItemMap["BP_Sniper_SLR_C"] = from_u8(u8"SLR射手步枪");
    ItemMap["BP_Sniper_MK12_Wrapper_C"] = from_u8(u8"MK12射手步枪");
    ItemMap["BP_Sniper_MK12_C"] = from_u8(u8"MK12射手步枪");
    ItemMap["BP_Sniper_QBU_Wrapper_C"] = from_u8(u8"QBU射手步枪");
    ItemMap["BP_Sniper_QBU_C"] = from_u8(u8"QBU射手步枪");
    ItemMap["BP_Sniper_MK20_Wrapper_C"] = from_u8(u8"MK20-H射手步枪");
    ItemMap["BP_Sniper_MK20_C"] = from_u8(u8"MK20-H射手步枪");
    ItemMap["BP_Rifle_M417_Wrapper_C"] = from_u8(u8"M417射手步枪");
    ItemMap["BP_Rifle_M417_C"] = from_u8(u8"M417射手步枪");

    // 狙击枪
    ItemMap["BP_Sniper_AS50_Wrapper_C"] = from_u8(u8"AS50狙击枪");
    ItemMap["BP_Sniper_AS50_C"] = from_u8(u8"AS50狙击枪");
    ItemMap["BP_UGC_Sniper_AS50_C"] = from_u8(u8"AS50狙击枪");
    ItemMap["BP_Sniper_M24_Wrapper_C"] = from_u8(u8"M24狙击枪");
    ItemMap["BP_Sniper_M24_C"] = from_u8(u8"M24狙击枪");
    ItemMap["BP_UGC_Sniper_M24_C"] = from_u8(u8"M24狙击枪");
    ItemMap["BP_Sniper_AMR_Wrapper_C"] = from_u8(u8"AMR狙击枪");
    ItemMap["BP_Sniper_AMR_C"] = from_u8(u8"AMR狙击枪");
    ItemMap["BP_UGC_Sniper_AMR_C"] = from_u8(u8"AMR狙击枪");
    ItemMap["BP_Sniper_M200_Wrapper_C"] = from_u8(u8"M200狙击枪");
    ItemMap["BP_Sniper_M200_C"] = from_u8(u8"M200狙击枪");
    ItemMap["BP_UGC_Sniper_M200_C"] = from_u8(u8"M200狙击枪");
    ItemMap["BP_Sniper_AWM_Wrapper_C"] = from_u8(u8"AWM狙击枪");
    ItemMap["BP_Sniper_AWM_C"] = from_u8(u8"AWM狙击枪");
    ItemMap["BP_UGC_Sniper_AWM_C"] = from_u8(u8"AWM狙击枪");
    ItemMap["BP_Sniper_Kar98k_Wrapper_C"] = from_u8(u8"Kar98k狙击枪");
    ItemMap["BP_Sniper_Kar98K_C"] = from_u8(u8"Kar98k狙击枪");
    ItemMap["BP_UGC_Sniper_Kar98k_C"] = from_u8(u8"Kar98k狙击枪");
    ItemMap["BP_Sniper_Mosin_Wrapper_C"] = from_u8(u8"莫辛纳甘狙击枪");
    ItemMap["BP_Sniper_Mosin_C"] = from_u8(u8"莫辛纳甘狙击枪");
    ItemMap["BP_UGC_Sniper_Mosin_C"] = from_u8(u8"莫辛纳甘狙击枪");
    ItemMap["BP_Sniper_Win94_Wrapper_C"] = from_u8(u8"Win94狙击枪");
    ItemMap["BP_Sniper_Win94_C"] = from_u8(u8"Win94狙击枪");
    ItemMap["BP_UGC_Sniper_Win94_C"] = from_u8(u8"Win94狙击枪");
    ItemMap["BP_Sniper_SVD_Wrapper_C"] = from_u8(u8"SVD狙击枪");
    ItemMap["BP_Sniper_SVD_C"] = from_u8(u8"SVD狙击枪");
    ItemMap["BP_UGC_Sniper_SVD_C"] = from_u8(u8"SVD狙击枪");

    // 冲锋枪
    ItemMap["BP_MachineGun_MP5K_Wrapper_C"] = from_u8(u8"MP5K冲锋枪");
    ItemMap["BP_MachineGun_MP5K_C"] = from_u8(u8"MP5K冲锋枪");
    ItemMap["BP_MachineGun_MP7_Wrapper_C"] = from_u8(u8"MP7-G冲锋枪");
    ItemMap["BP_MachineGun_MP7_C"] = from_u8(u8"MP7-G冲锋枪");
    ItemMap["BP_MachineGun_AKS74U_Wrapper_C"] = from_u8(u8"AKS-74U冲锋枪");
    ItemMap["BP_MachineGun_AKS74U_C"] = from_u8(u8"AKS-74U冲锋枪");
    ItemMap["BP_MachineGun_PP19_Wrapper_C"] = from_u8(u8"野牛冲锋枪");
    ItemMap["BP_MachineGun_PP19_C"] = from_u8(u8"野牛冲锋枪");
    ItemMap["BP_MachineGun_JS9_Wrapper_C"] = from_u8(u8"JS9冲锋枪");
    ItemMap["BP_MachineGun_JS9_C"] = from_u8(u8"JS9冲锋枪");
    ItemMap["BP_MachineGun_P90CG17_Wrapper_C"] = from_u8(u8"P90冲锋枪");
    ItemMap["BP_MachineGun_P90CG17_C"] = from_u8(u8"P90冲锋枪");
    ItemMap["BP_MachineGun_TommyGun_Wrapper_C"] = from_u8(u8"汤姆逊冲锋枪");
    ItemMap["BP_MachineGun_TommyGun_C"] = from_u8(u8"汤姆逊冲锋枪");
    ItemMap["BP_MachineGun_Vector_Wrapper_C"] = from_u8(u8"Vector冲锋枪");
    ItemMap["BP_MachineGun_Vector_C"] = from_u8(u8"Vector冲锋枪");
    ItemMap["BP_MachineGun_UMP9_Wrapper_C"] = from_u8(u8"UMP45冲锋枪");
    ItemMap["BP_MachineGun_UMP9_C"] = from_u8(u8"UMP45冲锋枪");
    ItemMap["BP_MachineGun_Uzi_Wrapper_C"] = from_u8(u8"UZI冲锋枪");
    ItemMap["BP_MachineGun_Uzi_C"] = from_u8(u8"UZI冲锋枪");

    // 霰弹枪
    ItemMap["BP_ShotGun_DP12_Wrapper_C"] = from_u8(u8"DBS霰弹枪");
    ItemMap["BP_ShotGun_DP12_C"] = from_u8(u8"DBS霰弹枪");
    ItemMap["BP_ShotGun_SPAS-12_Wrapper_C"] = from_u8(u8"SPAS-12霰弹枪");
    ItemMap["BP_ShotGun_SPAS-12_C"] = from_u8(u8"SPAS-12霰弹枪");
    ItemMap["BP_ShotGun_S12K_Wrapper_C"] = from_u8(u8"S12K霰弹枪");
    ItemMap["BP_ShotGun_S12K_C"] = from_u8(u8"S12K霰弹枪");
    ItemMap["BP_ShotGun_AA12_Wrapper_C"] = from_u8(u8"AA12-G霰弹枪");
    ItemMap["BP_ShotGun_AA12_C"] = from_u8(u8"AA12-G霰弹枪");
    ItemMap["BP_ShotGun_S1897_Wrapper_C"] = from_u8(u8"S1897霰弹枪");
    ItemMap["BP_ShotGun_S1897_C"] = from_u8(u8"S1897霰弹枪");
    ItemMap["BP_ShotGun_S686_Wrapper_C"] = from_u8(u8"S686霰弹枪");
    ItemMap["BP_ShotGun_S686_C"] = from_u8(u8"S686霰弹枪");
    ItemMap["BP_ShotGun_NS2000_Wrapper_C"] = from_u8(u8"NS2000");
    ItemMap["BP_ShotGun_NS2000_C"] = from_u8(u8"NS2000");
    ItemMap["BP_ShotGun_SawedOff_Wrapper_C"] = from_u8(u8"短管霰弹枪");
    ItemMap["BP_ShotGun_SawedOff_C"] = from_u8(u8"短管霰弹枪");

    // 手枪
    ItemMap["BP_Pistol_DesertEagle_Wrapper_C"] = from_u8(u8"沙漠之鹰");
    ItemMap["BP_Pistol_DesertEagle_C"] = from_u8(u8"沙漠之鹰");
    ItemMap["BP_Pistol_TMP_Wrapper_C"] = from_u8(u8"TMP-9手枪");
    ItemMap["BP_Pistol_TMP_C"] = from_u8(u8"TMP-9手枪");
    ItemMap["BP_Pistol_Vz61_Wrapper_C"] = from_u8(u8"蝎式手枪");
    ItemMap["BP_Pistol_Vz61_C"] = from_u8(u8"蝎式手枪");
    ItemMap["BP_Pistol_R45_Wrapper_C"] = from_u8(u8"R45手枪");
    ItemMap["BP_Pistol_R45_C"] = from_u8(u8"R45手枪");
    ItemMap["BP_Pistol_P18C_Wrapper_C"] = from_u8(u8"P18C手枪");
    ItemMap["BP_Pistol_P18C_C"] = from_u8(u8"P18C手枪");
    ItemMap["BP_Pistol_R1895_Wrapper_C"] = from_u8(u8"R1895手枪");
    ItemMap["BP_Pistol_R1895_C"] = from_u8(u8"R1895手枪");
    ItemMap["BP_Pistol_ColtAnaconda_Wrapper_C"] = from_u8(u8"双持巨蟒手枪");
    ItemMap["BP_Pistol_ColtAnaconda_C"] = from_u8(u8"双持巨蟒手枪");
    ItemMap["BP_Pistol_P1911_Wrapper_C"] = from_u8(u8"P1911手枪");
    ItemMap["BP_Pistol_P1911_C"] = from_u8(u8"P1911手枪");
    ItemMap["BP_Pistol_FN57_Wrapper_C"] = from_u8(u8"F57手枪");
    ItemMap["BP_Pistol_FN57_C"] = from_u8(u8"F57手枪");
    ItemMap["BP_Pistol_P92_Wrapper_C"] = from_u8(u8"P92手枪");
    ItemMap["BP_Pistol_P92_C"] = from_u8(u8"P92手枪");
    ItemMap["BP_UGC_Pistol_P92_C"] = from_u8(u8"P92手枪");
    ItemMap["BP_Pistol_RevivalFlaregun_Wrapper_C"] = from_u8(u8"召回信号枪");
    ItemMap["BP_Pistol_RevivalFlaregun_C"] = from_u8(u8"召回信号枪");
    ItemMap["BP_Pistol_Flaregun_Wrapper_C"] = from_u8(u8"信号枪");
    ItemMap["BP_Pistol_Flaregun_C"] = from_u8(u8"信号枪");

    // 机枪
    ItemMap["BP_Other_MG3_Wrapper_C"] = from_u8(u8"MG3轻机枪");
    ItemMap["BP_Other_MG3_C"] = from_u8(u8"MG3轻机枪");
    ItemMap["BP_Other_PKM_Wrapper_C"] = from_u8(u8"PKM轻机枪");
    ItemMap["BP_Other_PKM_C"] = from_u8(u8"PKM轻机枪");
    ItemMap["BP_Other_SIG_M338_Wrapper_C"] = from_u8(u8"M338轻机枪");
    ItemMap["BP_Other_SIG_M338_C"] = from_u8(u8"M338轻机枪");
    ItemMap["BP_Other_MG36_Wrapper_C"] = from_u8(u8"MG-36轻机枪");
    ItemMap["BP_Other_MG36_C"] = from_u8(u8"MG-36轻机枪");
    ItemMap["BP_Other_M249_Wrapper_C"] = from_u8(u8"M249轻机枪");
    ItemMap["BP_Other_M249_C"] = from_u8(u8"M249轻机枪");
    ItemMap["BP_Other_DP28_Wrapper_C"] = from_u8(u8"DP-28轻机枪");
    ItemMap["BP_Other_DP28_C"] = from_u8(u8"DP-28轻机枪");

    // 其他武器/投掷物/近战
    ItemMap["BP_Other_StunGun_Wrapper_C"] = from_u8(u8"电击枪");
    ItemMap["BP_Other_Shield_Wrapper_C"] = from_u8(u8"突击盾牌");
    ItemMap["BP_Other_Shield_new_C"] = from_u8(u8"突击盾牌");
    ItemMap["BP_Other_Mortar_Wrapper_C"] = from_u8(u8"轻型迫击炮");
    ItemMap["BP_Other_Mortar_C"] = from_u8(u8"轻型迫击炮");
    ItemMap["BP_Other_CrossBow_Wrapper_C"] = from_u8(u8"十字弩");
    ItemMap["BP_Other_CrossBow_C"] = from_u8(u8"十字弩");
    ItemMap["BP_Other_CrossbowBorderland_Wrapper_C"] = from_u8(u8"战术弩");
    ItemMap["BP_Other_CrossbowBorderland_C"] = from_u8(u8"战术弩");
    ItemMap["BP_Other_HuntingBow_Wrapper_C"] = from_u8(u8"爆炸猎弓");
    ItemMap["BP_Other_HuntingBow_C"] = from_u8(u8"爆炸猎弓");
    ItemMap["BP_Other_CompoundBow_Wrapper_C"] = from_u8(u8"燃点复合弓");
    ItemMap["BP_Other_CompoundBow_C"] = from_u8(u8"燃点复合弓");
    
    ItemMap["BP_WEP_Pan_Pickup_C"] = from_u8(u8"平底锅");
    ItemMap["BP_WEP_Pan_C"] = from_u8(u8"平底锅");
    ItemMap["BP_WEP_Sickle_Pickup_C"] = from_u8(u8"镰刀");
    ItemMap["BP_WEP_Sickle_C"] = from_u8(u8"镰刀");
    ItemMap["BP_WEP_Cowbar_Pickup_C"] = from_u8(u8"撬棍");
    ItemMap["BP_WEP_Cowbar_C"] = from_u8(u8"撬棍");
    ItemMap["BP_WEP_Machete_Pickup_C"] = from_u8(u8"大砍刀");
    ItemMap["BP_WEP_Machete_C"] = from_u8(u8"大砍刀");
    ItemMap["BP_WEP_DualBlades_Pickup_C"] = from_u8(u8"大漠双刀");
    ItemMap["BP_WEP_DualBlades_C"] = from_u8(u8"大漠双刀");

    ItemMap["BP_Grenade_Shoulei_Weapon_Wrapper_C"] = from_u8(u8"手雷");
    ItemMap["BP_Grenade_Shoulei_Weapon_C"] = from_u8(u8"手雷");
    ItemMap["BP_Grenade_Stun_Weapon_Wrapper_C"] = from_u8(u8"闪光弹");
    ItemMap["BP_Grenade_Stun_Weapon_C"] = from_u8(u8"闪光弹");
    ItemMap["BP_Grenade_Smoke_Weapon_Wrapper_C"] = from_u8(u8"烟雾弹");
    ItemMap["BP_Grenade_Smoke_Weapon_C"] = from_u8(u8"烟雾弹");
    ItemMap["BP_Grenade_Burn_Weapon_Wrapper_C"] = from_u8(u8"燃烧瓶");
    ItemMap["BP_Grenade_Burn_Weapon_C"] = from_u8(u8"燃烧瓶");
    ItemMap["BP_Grenade_Weapon_Wrapper_Thermite_C"] = from_u8(u8"铝热弹");
    ItemMap["BP_Grenade_Weapon_Wrapper_Thermite_C"] = from_u8(u8"铝热弹");
    ItemMap["BP_Grenade_Weapon_Wrapper_EMP_C"] = from_u8(u8"电磁脉冲手雷");
    ItemMap["BP_Grenade_Weapon_EMP_C"] = from_u8(u8"电磁脉冲手雷");

    // --- 药品 ---
    ItemMap["FirstAidbox_Pickup_C"] = from_u8(u8"医疗箱");
    ItemMap["Firstaid_Pickup_C"] = from_u8(u8"急救包");
    ItemMap["Bandage_Pickup_C"] = from_u8(u8"绷带");
    ItemMap["EnergyDrink_Pickup_C"] = from_u8(u8"能量饮料");
    ItemMap["Drink_Pickup_C"] = from_u8(u8"能量饮料");
    ItemMap["BP_Med_SignalBattery_C"] = from_u8(u8"信号电池");
    ItemMap["IcedTea_Pickup_C"] = from_u8(u8"杏皮茶");
    ItemMap["PainKiller_Pickup_C"] = from_u8(u8"止痛药");
    ItemMap["Pills_Pickup_C"] = from_u8(u8"止痛药");
    ItemMap["MedKit_Pickup_C"] = from_u8(u8"医疗箱");
    ItemMap["Adrenaline_Pickup_C"] = from_u8(u8"肾上腺素");
    ItemMap["Injection_Pickup_C"] = from_u8(u8"除颤器");

    // --- 装备 ---
    ItemMap["PickUp_BP_Helmet_Lv1_C"] = from_u8(u8"一级头");
    ItemMap["PickUp_BP_Helmet_Lv1_B_C"] = from_u8(u8"一级头");
    ItemMap["PickUp_BP_Helmet_Lv2_C"] = from_u8(u8"二级头");
    ItemMap["PickUp_BP_Helmet_Lv2_B_C"] = from_u8(u8"二级头");
    ItemMap["PickUp_BP_Helmet_Lv3_C"] = from_u8(u8"三级头");
    ItemMap["PickUp_BP_Helmet_Lv3_B_C"] = from_u8(u8"三级头");
    ItemMap["PickUp_BP_Armor_Lv1_C"] = from_u8(u8"一级甲");
    ItemMap["PickUp_BP_Armor_Lv1_B_C"] = from_u8(u8"一级甲");
    ItemMap["PickUp_BP_Armor_Lv2_C"] = from_u8(u8"二级甲");
    ItemMap["PickUp_BP_Armor_Lv2_B_C"] = from_u8(u8"二级甲");
    ItemMap["PickUp_BP_Armor_Lv3_C"] = from_u8(u8"三级甲");
    ItemMap["PickUp_BP_Armor_Lv3_B_C"] = from_u8(u8"三级甲");
    ItemMap["PickUp_BP_Bag_Lv1_C"] = from_u8(u8"一级包");
    ItemMap["PickUp_BP_Bag_Lv1_B_C"] = from_u8(u8"一级包");
    ItemMap["PickUp_BP_Bag_Lv2_C"] = from_u8(u8"二级包");
    ItemMap["PickUp_BP_Bag_Lv2_B_C"] = from_u8(u8"二级包");
    ItemMap["PickUp_BP_Bag_Lv3_C"] = from_u8(u8"三级包");
    ItemMap["PickUp_BP_Bag_Lv3_B_C"] = from_u8(u8"三级包");
    
    ItemMap["Ghillie_01_C"] = from_u8(u8"吉利服(林)");
    ItemMap["Ghillie_02_C"] = from_u8(u8"吉利服(荒)");
    ItemMap["Ghillie_03_C"] = from_u8(u8"吉利服(水)");
    ItemMap["Ghillie_04_C"] = from_u8(u8"吉利服(雪)");
    ItemMap["Ghillie_05_C"] = from_u8(u8"吉利服(黑)");
    ItemMap["Ghillie_06_C"] = from_u8(u8"吉利服(雪)");
    ItemMap["Item_Head_Repair_Kit_C"] = from_u8(u8"头盔修理");
    ItemMap["Item_Armor_Repair_Kit_C"] = from_u8(u8"护甲修理");
    ItemMap["JammerPack_C"] = from_u8(u8"干扰包");

    // --- 配件 ---
    ItemMap["BP_MZJ_HD_Pickup_C"] = from_u8(u8"红点瞄准镜");
    ItemMap["BP_MZJ_QX_Pickup_C"] = from_u8(u8"全息瞄准镜");
    ItemMap["BP_MZJ_2X_Pickup_C"] = from_u8(u8"2倍镜");
    ItemMap["BP_MZJ_3X_Pickup_C"] = from_u8(u8"3倍镜");
    ItemMap["BP_MZJ_4X_Pickup_C"] = from_u8(u8"4倍镜");
    ItemMap["BP_MZJ_6X_Pickup_C"] = from_u8(u8"6倍镜");
    ItemMap["BP_MZJ_8X_Pickup_C"] = from_u8(u8"8倍镜");
    ItemMap["BP_MZJ_SideRMR_Pickup_C"] = from_u8(u8"侧面瞄具");
    ItemMap["BP_MZJ_8X_Ballistics_Pickup_C"] = from_u8(u8"8倍镜(弹道)");

    ItemMap["BP_QT_A_Pickup_C"] = from_u8(u8"步枪补偿");
    ItemMap["BP_QT_S_Pickup_C"] = from_u8(u8"步枪消音");
    ItemMap["BP_QT_ZH_Pickup_C"] = from_u8(u8"步枪消焰");
    ItemMap["BP_DJ_Large_EQ_Pickup_C"] = from_u8(u8"步枪快扩");
    ItemMap["BP_DJ_Large_E_Pickup_C"] = from_u8(u8"步枪扩容");
    ItemMap["BP_DJ_Large_Q_Pickup_C"] = from_u8(u8"步枪快速");

    ItemMap["BP_QT_Sniper_Pickup_C"] = from_u8(u8"狙击补偿");
    ItemMap["BP_QK_Sniper_Compensator_Pickup_C"] = from_u8(u8"狙击补偿");
    ItemMap["BP_QK_Sniper_Suppressor_Pickup_C"] = from_u8(u8"狙击消音");
    ItemMap["BP_QK_Sniper_FlashHider_Pickup_C"] = from_u8(u8"狙击消焰");
    ItemMap["BP_DJ_Sniper_EQ_Pickup_C"] = from_u8(u8"狙击快扩");
    ItemMap["BP_DJ_Sniper_E_Pickup_C"] = from_u8(u8"狙击扩容");
    ItemMap["BP_DJ_Sniper_Q_Pickup_C"] = from_u8(u8"狙击快速");
    ItemMap["BP_ZDD_Sniper_Pickup_C"] = from_u8(u8"子弹袋(狙)");
    // BP_QT_Sniper_Pickup_C 重复了，上面已经定义为狙击补偿，这里可能是托腮板？根据 dx11_menu.ixx 里的注释，似乎有重复。
    // 我们保留上面的定义，并添加下面的：
    ItemMap["BP_WB_CheekPad_Pickup_C"] = from_u8(u8"托腮板");
    ItemMap["BP_WB_Fold_Pickup_C"] = from_u8(u8"折叠托");
    ItemMap["BP_WB_L_Pickup_C"] = from_u8(u8"战术托");
    ItemMap["BP_WB_HeavyStock_Pickup_C"] = from_u8(u8"重型枪托");
    
    ItemMap["BP_WB_Lasersight_Pickup_C"] = from_u8(u8"激光瞄准");
    ItemMap["BP_WB_ThumbGrip_Pickup_C"] = from_u8(u8"拇指握把");
    ItemMap["BP_WB_HalfGrip_Pickup_C"] = from_u8(u8"半截握把");
    ItemMap["BP_WB_LightGrip_Pickup_C"] = from_u8(u8"轻型握把");
    ItemMap["BP_WB_Vertical_Pickup_C"] = from_u8(u8"垂直握把");
    ItemMap["BP_WB_Angled_Pickup_C"] = from_u8(u8"直角握把");

    ItemMap["BP_QK_Large_Compensator_Pickup_C"] = from_u8(u8"步枪补偿");
    ItemMap["BP_QK_Large_Suppressor_Pickup_C"] = from_u8(u8"步枪消音");
    ItemMap["BP_QK_Large_FlashHider_Pickup_C"] = from_u8(u8"步枪消焰");
    
    ItemMap["BP_QK_Mid_Compensator_Pickup_C"] = from_u8(u8"冲锋补偿");
    ItemMap["BP_QK_Mid_Suppressor_Pickup_C"] = from_u8(u8"冲锋消音");
    ItemMap["BP_QK_Mid_FlashHider_Pickup_C"] = from_u8(u8"冲锋消焰");
    ItemMap["BP_DJ_Mid_EQ_Pickup_C"] = from_u8(u8"冲锋快扩");
    ItemMap["BP_DJ_Mid_E_Pickup_C"] = from_u8(u8"冲锋扩容");
    ItemMap["BP_DJ_Mid_Q_Pickup_C"] = from_u8(u8"冲锋快速");

    ItemMap["BP_QK_DuckBill_Pickup_C"] = from_u8(u8"鸭嘴枪口");
    ItemMap["BP_QK_Choke_Pickup_C"] = from_u8(u8"收束器");
    ItemMap["BP_DJ_ShotGun_Pickup_C"] = from_u8(u8"霰弹子弹袋");
    ItemMap["BP_ZDD_Crossbow_Q_Pickup_C"] = from_u8(u8"弩箭袋");
    ItemMap["BP_QT_UZI_Pickup_C"] = from_u8(u8"枪托(Micro UZI)");

    ItemMap["Item_Attach_Weapon_Upper_Ext_Pickup_C"] = from_u8(u8"侧瞄");
    ItemMap["Item_Weapon_Magazine_Extended_Large_Pickup_C"] = from_u8(u8"大容量弹夹");

    // --- 投掷物 (Pickup) ---
    ItemMap["ProjGrenade_Pickup_C"] = from_u8(u8"手雷");
    ItemMap["ProjSmokeBomb_Pickup_C"] = from_u8(u8"烟雾弹");
    ItemMap["ProjMolotov_Pickup_C"] = from_u8(u8"燃烧瓶");
    ItemMap["ProjFlashBang_Pickup_C"] = from_u8(u8"闪光弹");
    ItemMap["ProjBlueZone_Pickup_C"] = from_u8(u8"蓝圈雷");
    ItemMap["Item_Weapon_SpikeTrap_Pickup_C"] = from_u8(u8"钉刺陷阱");
    ItemMap["Item_Weapon_C4_Pickup_C"] = from_u8(u8"C4");

    // --- 子弹 ---
    ItemMap["Item_Ammo_762mm_Pickup_C"] = from_u8(u8"7.62mm");
    ItemMap["Item_Ammo_556mm_Pickup_C"] = from_u8(u8"5.56mm");
    ItemMap["Item_Ammo_300Magnum_Pickup_C"] = from_u8(u8"马格南");
    ItemMap["Item_Ammo_45ACP_Pickup_C"] = from_u8(u8".45ACP");
    ItemMap["Item_Ammo_9mm_Pickup_C"] = from_u8(u8"9mm");
    ItemMap["Item_Ammo_12Guage_Pickup_C"] = from_u8(u8"12号");
    ItemMap["Item_Ammo_Bolt_Pickup_C"] = from_u8(u8"弩箭");
    ItemMap["BP_Ammo_762mm_Pickup_C"] = from_u8(u8"7.62mm");
    ItemMap["BP_Ammo_556mm_Pickup_C"] = from_u8(u8"5.56mm");
    ItemMap["BP_Ammo_300Magnum_Pickup_C"] = from_u8(u8"马格南");
    ItemMap["BP_Ammo_45ACP_Pickup_C"] = from_u8(u8".45ACP");
    ItemMap["BP_Ammo_9mm_Pickup_C"] = from_u8(u8"9mm");
    ItemMap["BP_Ammo_12Guage_Pickup_C"] = from_u8(u8"12号");
    ItemMap["BP_Ammo_Bolt_Pickup_C"] = from_u8(u8"弩箭");
    ItemMap["BP_Ammo_50BMG_Pickup_C"] = from_u8(u8"50BMG");
    ItemMap["BP_Ammo_RevivalFlare_Pickup_C"] = from_u8(u8"召回信号弹");
    ItemMap["BP_Ammo_Flare_Pickup_C"] = from_u8(u8"信号弹");
    ItemMap["BP_Ammo_MortarAmmo_HE_Pickup_C"] = from_u8(u8"迫击炮弹");

    // --- 其他 ---
    ItemMap["BP_revivalAED_Pickup_C"] = from_u8(u8"自救型除颤器");
    ItemMap["BP_CG035_WEP_LambLeg_Pickup_C"] = from_u8(u8"烤羊腿");
    ItemMap["BP_PickupWrapper_Naan_C"] = from_u8(u8"馕");
    ItemMap["BP_Pickup_Finger_C"] = from_u8(u8"飞索");
    ItemMap["BP_BrozenHorse_Wrapper_C"] = from_u8(u8"小马神");
    ItemMap["PickUp_BP_FlyHorse_C"] = from_u8(u8"天马口哨");
    ItemMap["BP_NineColoredDeer_PickUpWrapper_C"] = from_u8(u8"九色鹿");
    ItemMap["CG035_SmallRedPacket_Wrapper_C"] = from_u8(u8"小红包");
    ItemMap["BP_CG035_BigGoldWrapper_C"] = from_u8(u8"飞马雕像");
    ItemMap["BP_FeiTian_PickUpWrapper_C"] = from_u8(u8"飞天飘带");
    ItemMap["BP_PickupWrapper_Key_C"] = from_u8(u8"密室钥匙");
    ItemMap["BP_Theme_BlackCardWrapper_C"] = from_u8(u8"主题海岛黑卡");
    ItemMap["MilitarySupplyBoxBase_Baltic_Theme_C"] = from_u8(u8"海岛军事物资箱");
    ItemMap["Item_Weapon_Pan_Pickup_C"] = from_u8(u8"平底锅");
    ItemMap["Item_Key_Pickup_C"] = from_u8(u8"钥匙");
    ItemMap["Item_EmergencyPickup_Pickup_C"] = from_u8(u8"紧急呼救器");

    // --- 盒子 ---
    ItemMap["PickUpListWrapperActor"] = from_u8(u8"骨灰盒");
    ItemMap["CharacterDeadInventoryBox_C"] = from_u8(u8"骨灰盒");
    ItemMap["DeathDropItemPackage_C"] = from_u8(u8"骨灰盒");
    ItemMap["BP_TrainingBoxListWrapper_C"] = from_u8(u8"武器盒子");
    ItemMap["CG30_ActivityCommonTreasureBox_C"] = from_u8(u8"黄色箱子");
    ItemMap["MilitarySupplyBoxBase_Baltic_Classic_C"] = from_u8(u8"海岛铁箱子");
    
    // --- 空投 ---
    ItemMap["Carapackage_RedBox_C"] = from_u8(u8"空投(红)");
    ItemMap["Carapackage_WhiteBox_C"] = from_u8(u8"空投(白)");
    ItemMap["AirDropListWrapperActor"] = from_u8(u8"空投盒子");
    ItemMap["PlayerDeadInventoryBox_C"] = from_u8(u8"空投盒子");
    ItemMap["BP_CG023AirDropBox_C"] = from_u8(u8"空投盒子");
    ItemMap["BP_AirDropBox_C"] = from_u8(u8"空投盒子");
    ItemMap["BP_AirDropBox_BoxingChampion_C"] = from_u8(u8"拳王盒子");
    ItemMap["BP_ZhengDuoBox_C"] = from_u8(u8"争夺盒子");
    ItemMap["AirDropBoxActor"] = from_u8(u8"空投箱");
    ItemMap["DroneAirDropBoxActor"] = from_u8(u8"无人机空投");
    ItemMap["AirDropPlane"] = from_u8(u8"空投飞机");
    ItemMap["BP_Airplane_AlwaysRdevant_C"] = from_u8(u8"空投飞机");
    
    // --- 警告 ---
    ItemMap["ProjGrenade_C"] = from_u8(u8"手雷警告");
    ItemMap["ProjGrenade_Coop_C"] = from_u8(u8"手雷警告");
    ItemMap["BP_Grenade_Shoulei_C"] = from_u8(u8"手雷警告");
    ItemMap["ProjMolotov_C"] = from_u8(u8"燃烧瓶警告");
    ItemMap["BP_Molotov_C"] = from_u8(u8"燃烧瓶警告");
    
    ItemMap["GasCanBattery_Destructible_Pickup_C"] = from_u8(u8"油桶");
    ItemMap["PickUp_BP_Mountainbike1_C"] = from_u8(u8"折叠自行车");

    // --- 载具 ---
    VehicleMap["VH_Blanc_C"] = from_u8(u8"布朗");
    VehicleMap["VH_Picobus_C"] = from_u8(u8"公交车");
    VehicleMap["VH_DesertCar_C"] = from_u8(u8"沙漠赛车");
    VehicleMap["VH_Drift_001_New_C"] = from_u8(u8"漂移车");
    VehicleMap["VH_Horse_1_C"] = from_u8(u8"马化腾");
    VehicleMap["VH_Horse_2_C"] = from_u8(u8"马化腾");
    VehicleMap["VH_Horse_3_C"] = from_u8(u8"马化腾");
    VehicleMap["VH_Horse_4_C"] = from_u8(u8"马化腾");
    VehicleMap["VH_4SportCar_C"] = from_u8(u8"四座跑车");
    VehicleMap["VH_UAZ01_New_C"] = from_u8(u8"吉普车");
    VehicleMap["VH_UAZ02_New_C"] = from_u8(u8"吉普车");
    VehicleMap["VH_UAZ03_New_C"] = from_u8(u8"吉普车");
    VehicleMap["VH_Dacia_New_C"] = from_u8(u8"轿车");
    VehicleMap["VH_Dacia_1_New_C"] = from_u8(u8"轿车");
    VehicleMap["VH_Dacia_2_New_C"] = from_u8(u8"轿车");
    VehicleMap["VH_Dacia_3_New_C"] = from_u8(u8"轿车");
    VehicleMap["BP_VH_Buggy_C"] = from_u8(u8"蹦蹦车");
    VehicleMap["BP_VH_Buggy_2_C"] = from_u8(u8"越野车");
    VehicleMap["VH_CoupeRB_1_C"] = from_u8(u8"双门跑车");
    VehicleMap["VH_Motorcycle_1_C"] = from_u8(u8"摩托车");
    VehicleMap["VH_Motorcycle_C"] = from_u8(u8"摩托车");
    VehicleMap["VH_StationWagon_New_C"] = from_u8(u8"旅行车");
    VehicleMap["BP_VH_Bigfoot_C"] = from_u8(u8"大脚车");
    VehicleMap["VH_ATV1_C"] = from_u8(u8"全地形车");
    VehicleMap["Mirado_close_1_C"] = from_u8(u8"封闭式皮卡");
    VehicleMap["Mirado_open_1_C"] = from_u8(u8"开放式皮卡");
    VehicleMap["PickUp_01_C"] = from_u8(u8"皮卡");
    VehicleMap["PickUp_02_C"] = from_u8(u8"皮卡");
    VehicleMap["PickUp_03_C"] = from_u8(u8"皮卡");
    VehicleMap["PickUp_04_C"] = from_u8(u8"皮卡");
    VehicleMap["PickUp_05_C"] = from_u8(u8"皮卡");
    VehicleMap["PickUp_06_C"] = from_u8(u8"皮卡");
    VehicleMap["PickUp_07_C"] = from_u8(u8"皮卡");
    VehicleMap["PickUp_08_C"] = from_u8(u8"皮卡");
    VehicleMap["Rony_01_C"] = from_u8(u8"罗尼");
    VehicleMap["BP_VH_Tuk_1_C"] = from_u8(u8"三轮车");
    VehicleMap["VH_Snowbike_02_C"] = from_u8(u8"雪地摩托");
    VehicleMap["VH_Snowmobile_C"] = from_u8(u8"雪地车");
    VehicleMap["LadaNiva_01_C"] = from_u8(u8"雪地越野车");
    VehicleMap["VH_Scooter_C"] = from_u8(u8"小绵羊");
    VehicleMap["VH_MotorcycleCart_1_C"] = from_u8(u8"摩托三轮");
    VehicleMap["VH_MiniBus_01_C"] = from_u8(u8"小巴士");
    VehicleMap["VH_BRDM_C"] = from_u8(u8"装甲车");
    VehicleMap["VH_Mountainbike_Training_C"] = from_u8(u8"山地自行车");
    VehicleMap["VH_PG117_C"] = from_u8(u8"快艇");
    VehicleMap["AquaRail_1_C"] = from_u8(u8"水上摩托");
    VehicleMap["VH_BBCar_C"] = from_u8(u8"碰碰车");
}

export std::string GetItemName(const std::string& key) {
    if (dx11_menu::esp::metro_mode) {
        // 传世武器
        if (key == "BP_WEP_HYD_C" || key == "BP_WEP_HYD_Pickup_C") return from_u8(u8"火焰刀·维列");
        if (key == "BP_WEP_HDD_C" || key == "BP_WEP_HDD_Pickup_C") return from_u8(u8"蝴蝶刀·冷锋");
        if (key == "BP_WEP_SJG_C" || key == "BP_WEP_SJG_Pickup_C") return from_u8(u8"双截棍·神龙");
        if (key == "BP_WEP_JXQT_C" || key == "BP_WEP_JXQT_Pickup_C") return from_u8(u8"拳套·破风");
        if (key == "BP_WEP_TitanSword_C") return from_u8(u8"大刀·危");

        // 金品变卖物
        if (key == "Jintoukui_Pickup_C") return from_u8(u8"精英纪念奖杯");
        if (key == "Jinlangquanzhang_Pickup_C") return from_u8(u8"黄金狼头权杖");
        if (key == "Longtenruizhaojindiao_Pickup_C") return from_u8(u8"龙腾瑞兆金雕");
        if (key == "Eagle_Pickup_C") return from_u8(u8"黄金鹰形雕像");
        if (key == "Yushejinghuan_Pickup_C") return from_u8(u8"玉蛇金环");
        if (key == "Qunlangbaoguan_Pickup_C") return from_u8(u8"群狼宝冠");
        if (key == "GoldenHorse_Basic_Pickup_C") return from_u8(u8"马上有金");
        if (key == "Goldpen_Pickup_C") return from_u8(u8"古董钢笔");
        if (key == "GoldLighter_Pickup_C") return from_u8(u8"黄金打火机");

        // 红色物资
        if (key == "VolcanoLaserSystem_Pickup_C") return from_u8(u8"观测激光系统");
        if (key == "Peisongjiqiren_Pickup_C") return from_u8(u8"配送机器人");
        if (key == "Wurenji_Pickup_C") return from_u8(u8"无人机");
        if (key == "Guangzijijiangbei_Pickup_C") return from_u8(u8"光子鸡奖杯");
        if (key == "Yigenjintiao_Pickup_C") return from_u8(u8"一根金条");
        if (key == "Router_Pickup_C") return from_u8(u8"加密路由器");
        if (key == "FrozenMech_Pickup_C") return from_u8(u8"机械原件");
        if (key == "Jingmiyiqilantu_Pickup_C") return from_u8(u8"精密仪器蓝图");
        if (key == "Shejituzhi_Pickup_C") return from_u8(u8"设计图纸");
        if (key == "Zhenxiguqianbi_Pickup_C") return from_u8(u8"珍稀古钱币");
        if (key == "GoodsLv6Test_qingbao_C") return from_u8(u8"勘察情报");
        if (key == "Qiqiaohexing_Pickup_C") return from_u8(u8"奇巧核心");
        if (key == "Xianka_Pickup_C") return from_u8(u8"显卡");
        if (key == "Zhizaotiguanjie_Pickup_C") return from_u8(u8"智造体关节");
        if (key == "Niutouzhixie_Pickup_C") return from_u8(u8"牛头智械");
        if (key == "Jiguanshu_Pickup_C") return from_u8(u8"机关书");
        if (key == "Jingtou_Pickup_C") return from_u8(u8"镜头");
        if (key == "Teqianmiling_Pickup_C") return from_u8(u8"特遣密令");
        if (key == "GPS_Pickup_C") return from_u8(u8"定位装置");
        if (key == "Xiyoubaoshi_Pickup_C") return from_u8(u8"稀有宝石");
        if (key == "Jijiahuolibujian_Pickup_C") return from_u8(u8"爆发部件");
        if (key == "Jijianengyuanbujian_Pickup_C") return from_u8(u8"能源部件");
        if (key == "GoodsLv7Test_dianchi_C") return from_u8(u8"能源电池");
        if (key == "Langyaxianglian_Pickup_C") return from_u8(u8"狼牙项链");
        if (key == "Langyajiezhi_Pickup_C") return from_u8(u8"狼牙戒指");
    }

    auto it = ItemMap.find(key);
    if (it != ItemMap.end()) {
        return it->second;
    }

    auto it_veh = VehicleMap.find(key);
    if (it_veh != VehicleMap.end()) {
        return it_veh->second;
    }

    // Fuzzy matching fallback (based on AActorType.ixx logic)
    if (key.find("PickUpListWrapperActor") != std::string::npos) return from_u8(u8"骨灰盒");
    if (key.find("CharacterDeadInventoryBox_C") != std::string::npos) return from_u8(u8"骨灰盒");
    if (key.find("DeathDropItemPackage_C") != std::string::npos) return from_u8(u8"骨灰盒");
    if (key.find("AirDropListWrapperActor") != std::string::npos) return from_u8(u8"空投盒子");
    if (key.find("PlayerDeadInventoryBox") != std::string::npos) return from_u8(u8"空投盒子");
    if (key.find("BP_AirDropBox_C") != std::string::npos) return from_u8(u8"空投盒子");
    if (key.find("AirDropBoxActor") != std::string::npos) return from_u8(u8"空投箱");
    if (key.find("DroneAirDropBoxActor") != std::string::npos) return from_u8(u8"无人机空投");
    if (key.find("AirDropPlane") != std::string::npos) return from_u8(u8"空投飞机");
    if (key.find("BP_Airplane_AlwaysRdevant_C") != std::string::npos) return from_u8(u8"空投飞机");
    if (key.find("Carapackage") != std::string::npos) return from_u8(u8"空投箱");
    if (key.find("TreasureBox_Sub_Desert_C") != std::string::npos) return from_u8(u8"空投");
    
    if (key.find("ProjGrenade") != std::string::npos) return from_u8(u8"手雷警告");
    if (key.find("ProjMolotov") != std::string::npos) return from_u8(u8"燃烧瓶警告");
    if (key.find("BP_Grenade_Shoulei_C") != std::string::npos) return from_u8(u8"手雷警告");
    if (key.find("BP_Grenade_Burn_C") != std::string::npos) return from_u8(u8"燃烧瓶警告");

    return ""; // Return empty string if not found
}
