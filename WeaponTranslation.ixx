export module WeaponTranslation;

import std;
import <string>;
import <unordered_map>;

// Define a type for the map to avoid complex template syntax in export
using WeaponMapType = std::unordered_map<std::string, std::string>;

// Internal map storage
static WeaponMapType WeaponMap;

// Helper to convert UTF-8 string literal to std::string
// This handles the C++20 change where u8"" literals are const char8_t*
std::string from_u8(const char8_t* str) {
    return std::string(reinterpret_cast<const char*>(str));
}

export void InitWeaponTranslation() {
    WeaponMap.reserve(100); // Pre-allocate to avoid rehashes

    // 突击步枪 
    WeaponMap["BP_Rifle_AKM_C"] = from_u8(u8"AKM");
    WeaponMap["BP_Rifle_M16A4_C"] = from_u8(u8"M16A4");
    WeaponMap["BP_Rifle_M416_C"] = from_u8(u8"M416");
    WeaponMap["BP_Rifle_SCAR_L_C"] = from_u8(u8"SCAR-L");
    WeaponMap["BP_Rifle_SCARC_C"] = from_u8(u8"SCAR-L");
    WeaponMap["BP_Rifle_SCAR_C"] = from_u8(u8"SCAR");
    WeaponMap["BP_Rifle_Groza_C"] = from_u8(u8"Groza");
    WeaponMap["BP_Rifle_AUG_C"] = from_u8(u8"AUG");
    WeaponMap["BP_Rifle_QBZ_C"] = from_u8(u8"QBZ");
    WeaponMap["BP_Rifle_M762_C"] = from_u8(u8"M762");
    WeaponMap["BP_Rifle_MK47_C"] = from_u8(u8"MK47");
    WeaponMap["BP_Rifle_Mk47_C"] = from_u8(u8"Mk47");
    WeaponMap["BP_Rifle_G36C_C"] = from_u8(u8"G36C");
    WeaponMap["BP_Rifle_G36_C"] = from_u8(u8"G36C");
    WeaponMap["BP_Rifle_ACE32_C"] = from_u8(u8"ACE32");
    WeaponMap["BP_Rifle_FAMAS_C"] = from_u8(u8"FAMAS");
    WeaponMap["BP_Rifle_Famas_C"] = from_u8(u8"FAMAS");
    WeaponMap["BP_Rifle_HoneyBadger_C"] = from_u8(u8"蜜獾");
    WeaponMap["BP_Rifle_ACVal_C"] = from_u8(u8"AC-VAL");
    WeaponMap["BP_Rifle_VAL_C"] = from_u8(u8"AC-VAL");
    WeaponMap["BP_Rifle_ARX200_C"] = from_u8(u8"ARX");

    // 射手步枪 
    WeaponMap["BP_Sniper_VSS_C"] = from_u8(u8"VSS");
    WeaponMap["BP_Sniper_SKS_C"] = from_u8(u8"SKS");
    WeaponMap["BP_Sniper_Mk14_C"] = from_u8(u8"MK14");
    WeaponMap["BP_WEP_Mk14_Pickup_C"] = from_u8(u8"MK14");
    WeaponMap["BP_Sniper_Mini14_C"] = from_u8(u8"Mini14");
    WeaponMap["BP_Sniper_SLR_C"] = from_u8(u8"SLR");
    WeaponMap["BP_Sniper_QBU_C"] = from_u8(u8"QBU");
    WeaponMap["BP_Sniper_MK12_C"] = from_u8(u8"MK12");
    WeaponMap["BP_Sniper_M1Garand_C"] = from_u8(u8"M1加兰德");
    WeaponMap["BP_Sniper_M417_C"] = from_u8(u8"M417");
    WeaponMap["BP_Rifle_M417_C"] = from_u8(u8"M417");
    WeaponMap["BP_Sniper_SVD_C"] = from_u8(u8"SVD");
    WeaponMap["BP_UGC_Sniper_SVD_C"] = from_u8(u8"SVD");
    WeaponMap["BP_Sniper_MK20_C"] = from_u8(u8"MK20-H");

    // 狙击枪 
    WeaponMap["BP_Sniper_AWM_C"] = from_u8(u8"AWM");
    WeaponMap["BP_UGC_Sniper_AWM_C"] = from_u8(u8"AWM");
    WeaponMap["BP_Sniper_Kar98k_C"] = from_u8(u8"Kar98k");
    WeaponMap["BP_Sniper_Kar98K_C"] = from_u8(u8"Kar98K");
    WeaponMap["BP_UGC_Sniper_Kar98k_C"] = from_u8(u8"Kar98k");
    WeaponMap["BP_Sniper_M24_C"] = from_u8(u8"M24");
    WeaponMap["BP_UGC_Sniper_M24_C"] = from_u8(u8"M24");
    WeaponMap["BP_Sniper_Win94_C"] = from_u8(u8"Win94");
    WeaponMap["BP_UGC_Sniper_Win94_C"] = from_u8(u8"Win94");
    WeaponMap["BP_Sniper_MosinNagant_C"] = from_u8(u8"莫辛纳甘");
    WeaponMap["BP_Sniper_Mosin_C"] = from_u8(u8"莫辛纳甘");
    WeaponMap["BP_UGC_Sniper_Mosin_C"] = from_u8(u8"莫辛纳甘");
    WeaponMap["BP_Sniper_AMR_C"] = from_u8(u8"AMR");
    WeaponMap["BP_UGC_Sniper_AMR_C"] = from_u8(u8"AMR");
    WeaponMap["BP_Sniper_M200_C"] = from_u8(u8"M200");
    WeaponMap["BP_UGC_Sniper_M200_C"] = from_u8(u8"M200");
    WeaponMap["BP_Sniper_AS50_C"] = from_u8(u8"AS50");
    WeaponMap["BP_UGC_Sniper_AS50_C"] = from_u8(u8"AS50");

    // 冲锋枪 
    WeaponMap["BP_MachineGun_Uzi_C"] = from_u8(u8"UZI");
    WeaponMap["BP_MachineGun_TommyGun_C"] = from_u8(u8"汤姆逊");
    WeaponMap["BP_MachineGun_UMP45_C"] = from_u8(u8"UMP45");
    WeaponMap["BP_MachineGun_UMP9_C"] = from_u8(u8"UMP45");
    WeaponMap["BP_MachineGun_Vector_C"] = from_u8(u8"Vector");
    WeaponMap["BP_MachineGun_Bizon_C"] = from_u8(u8"野牛");
    WeaponMap["BP_MachineGun_PP19_C"] = from_u8(u8"野牛");
    WeaponMap["BP_MachineGun_MP5K_C"] = from_u8(u8"MP5K");
    WeaponMap["BP_MachineGun_P90_C"] = from_u8(u8"P90");
    WeaponMap["BP_MachineGun_P90CG17_C"] = from_u8(u8"P90");
    WeaponMap["BP_MachineGun_MP7_C"] = from_u8(u8"MP7-G");
    WeaponMap["BP_MachineGun_JS9_C"] = from_u8(u8"JS9");
    WeaponMap["BP_MachineGun_AKS74U_C"] = from_u8(u8"AKS74U");

    // 霰弹枪 
    WeaponMap["BP_ShotGun_SPAS-12_C"] = from_u8(u8"SPAS-12");
    WeaponMap["BP_ShotGun_S12K_C"] = from_u8(u8"S12K");
    WeaponMap["BP_ShotGun_S1897_C"] = from_u8(u8"S1897");
    WeaponMap["BP_ShotGun_S686_C"] = from_u8(u8"S686");
    WeaponMap["BP_ShotGun_DBS_C"] = from_u8(u8"DBS");
    WeaponMap["BP_ShotGun_DP12_C"] = from_u8(u8"DBS");
    WeaponMap["BP_ShotGun_SawedOff_C"] = from_u8(u8"短管霰弹枪");
    WeaponMap["BP_ShotGun_AA12_C"] = from_u8(u8"AA12-G");
    WeaponMap["BP_ShotGun_NS2000_C"] = from_u8(u8"NS2000");

    // 手枪 
    WeaponMap["BP_Pistol_TMP_C"] = from_u8(u8"TMP-9");
    WeaponMap["BP_Pistol_P1911_C"] = from_u8(u8"P1911");
    WeaponMap["BP_Pistol_P92_C"] = from_u8(u8"P92");
    WeaponMap["BP_UGC_Pistol_P92_C"] = from_u8(u8"P92");
    WeaponMap["BP_Pistol_R1895_C"] = from_u8(u8"R1895");
    WeaponMap["BP_Pistol_P18C_C"] = from_u8(u8"P18C");
    WeaponMap["BP_Pistol_R45_C"] = from_u8(u8"R45");
    WeaponMap["BP_Pistol_Skorpion_C"] = from_u8(u8"蝎式手枪");
    WeaponMap["BP_Pistol_Vz61_C"] = from_u8(u8"蝎式手枪");
    WeaponMap["BP_Pistol_Deagle_C"] = from_u8(u8"沙漠之鹰");
    WeaponMap["BP_Pistol_DesertEagle_C"] = from_u8(u8"沙漠之鹰");
    WeaponMap["BP_Pistol_F57_C"] = from_u8(u8"F57");
    WeaponMap["BP_Pistol_FN57_C"] = from_u8(u8"F57");
    WeaponMap["BP_Pistol_Taser_C"] = from_u8(u8"泰瑟枪");
    WeaponMap["BP_Pistol_ColtAnaconda_C"] = from_u8(u8"双持巨蟒");
    WeaponMap["BP_Pistol_RevivalFlaregun_C"] = from_u8(u8"召回信号枪");
    WeaponMap["BP_Pistol_RevivaFlaregun_Wrapper_C"] = from_u8(u8"召回信号枪");
    WeaponMap["BP_Pistol_Flaregun_C"] = from_u8(u8"信号枪");
    WeaponMap["BP_Weapon_FlareGun_C"] = from_u8(u8"信号枪");

    // 机枪 
    WeaponMap["BP_Other_MG3_C"] = from_u8(u8"MG3");
    WeaponMap["BP_Other_M249_C"] = from_u8(u8"M249");
    WeaponMap["BP_Other_DP28_C"] = from_u8(u8"DP-28");
    WeaponMap["BP_Other_MG36_C"] = from_u8(u8"MG-36");
    WeaponMap["BP_Other_PKM_C"] = from_u8(u8"PKM");
    WeaponMap["BP_Other_M338_C"] = from_u8(u8"M338");
    WeaponMap["BP_Other_SIG_M338_C"] = from_u8(u8"M338");

    // 近战 
    WeaponMap["BP_WEP_Machete_C"] = from_u8(u8"大砍刀");
    WeaponMap["BP_WEP_Pan_C"] = from_u8(u8"平底锅");
    WeaponMap["BP_WEP_Crowbar_C"] = from_u8(u8"撬棍");
    WeaponMap["BP_WEP_Cowbar_C"] = from_u8(u8"撬棍");
    WeaponMap["BP_WEP_Sickle_C"] = from_u8(u8"镰刀");
    WeaponMap["BP_Other_CrossBow_C"] = from_u8(u8"十字弩");
    WeaponMap["BP_Other_CrossbowBorderland_C"] = from_u8(u8"战术弩");
    WeaponMap["BP_Other_HuntingBow_C"] = from_u8(u8"爆炸猎弓");
    WeaponMap["BP_Other_CompoundBow_C"] = from_u8(u8"燃点复合弓");
    WeaponMap["BP_Other_Shield_C"] = from_u8(u8"盾牌");
    WeaponMap["BP_Other_Shield_new_C"] = from_u8(u8"突击盾牌");
    WeaponMap["BP_Other_Mortar_C"] = from_u8(u8"迫击炮");
    WeaponMap["BP_Other_Mortar_Wrapper_C"] = from_u8(u8"迫击炮");
    WeaponMap["BP_Grenade_Shoulei_Weapon_Wrapper_C"] = from_u8(u8"手雷");
    WeaponMap["BP_Grenade_Shoulei_Weapon_C"] = from_u8(u8"手雷");
    WeaponMap["BP_Grenade_Stun_Weapon_Wrapper_C"] = from_u8(u8"闪光弹");
    WeaponMap["BP_Grenade_Stun_Weapon_C"] = from_u8(u8"闪光弹");
    WeaponMap["BP_Grenade_Smoke_Weapon_Wrapper_C"] = from_u8(u8"烟雾弹");
    WeaponMap["BP_Grenade_Smoke_Weapon_C"] = from_u8(u8"烟雾弹");
    WeaponMap["BP_Grenade_Burn_Weapon_Wrapper_C"] = from_u8(u8"燃烧瓶");
    WeaponMap["BP_Grenade_Burn_Weapon_C"] = from_u8(u8"燃烧瓶");
    WeaponMap["BP_Grenade_Weapon_Wrapper_Thermite_C"] = from_u8(u8"铝热弹");
    WeaponMap["BP_Grenade_Weapon_Wrapper_EMP_C"] = from_u8(u8"电磁脉冲手雷");
    WeaponMap["BP_Grenade_Weapon_EMP_C"] = from_u8(u8"电磁脉冲手雷");
}

export std::string GetWeaponName(const std::string& key) {
    auto it = WeaponMap.find(key);
    if (it != WeaponMap.end()) {
        return it->second;
    }
    return ""; // Return empty string if not found
}
