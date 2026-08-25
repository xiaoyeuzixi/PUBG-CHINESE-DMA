export module AUAECharacter;
import ACharacter;
import Offsets;
import std;
import dma;
import FString;
import TArray;
import ASTExtraWeapon;

export class AUAECharacter : public ACharacter {
public:
	FString m_PlayerName_FStr{};
	std::wstring m_PlayerName{};
	int32_t m_TeamID{};
	bool m_bIsAI{};
	float m_Health{};
	float m_HealthMax = 100;
	float m_SignalHP{};
	float m_SignalHPMax = 100;
	int m_PawnState{};
	TArray<unsigned char> m_PawnStateRepSyncData_TArray{};
	std::vector<unsigned char> m_PawnStateRepSyncData_Data{};
	FString m_PawnStatesExtend_FStr{};
	std::wstring m_PawnStatesExtend{};
	uint64_t m_PlayerStatePtr{};
	int m_Kills{};
	float m_Energy{};
	float m_EnergyMax_Char{};
	float m_EnergyBuff{};
	float m_SignalHP_State{};
	unsigned char m_HealthStatus{};

	ASTExtraWeapon m_CurrentUsingWeaponSafety{};

public:
	using ACharacter::ACharacter;


	void scatter_PlayerName_FStr(VMMDLL_SCATTER_HANDLE hs);
	void scatter_PlayerName_FFtrToWstr(VMMDLL_SCATTER_HANDLE hs);
	void scatter_TeamID(VMMDLL_SCATTER_HANDLE hs);
	void update_TeamID();
	void scatter_Health(VMMDLL_SCATTER_HANDLE hs);
	void scatter_SignalHP(VMMDLL_SCATTER_HANDLE hs);
	void scatter_PawnState(VMMDLL_SCATTER_HANDLE hs);
	void scatter_PawnStateRepSyncData_TArray(VMMDLL_SCATTER_HANDLE hs);
	void scatter_PawnStateRepSyncData_Content(VMMDLL_SCATTER_HANDLE hs);
	void scatter_PawnStatesExtend_FStr(VMMDLL_SCATTER_HANDLE hs);
	void scatter_PawnStatesExtend_FStrToWstr(VMMDLL_SCATTER_HANDLE hs);
	void scatter_bIsAI(VMMDLL_SCATTER_HANDLE hs);
	void scatter_CurrentUsingWeaponSafety(VMMDLL_SCATTER_HANDLE hs);
	void scatter_PlayerState(VMMDLL_SCATTER_HANDLE hs);
	void scatter_PlayerStateData(VMMDLL_SCATTER_HANDLE hs);
	void scatter_HealthStatus(VMMDLL_SCATTER_HANDLE hs);

};

void AUAECharacter::scatter_PlayerName_FStr(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs , ptr + Offsets::AUAECharacter::PlayerName , &m_PlayerName_FStr, sizeof(FString));
}

void AUAECharacter::scatter_PlayerName_FFtrToWstr(VMMDLL_SCATTER_HANDLE hs)
{
	m_PlayerName.resize(m_PlayerName_FStr.NumElements);
	dma::Scatter_PrepareEx(hs , m_PlayerName_FStr.Data , m_PlayerName.data() , m_PlayerName_FStr.NumElements * 2 );
}

void AUAECharacter::scatter_TeamID(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::AUAECharacter::TeamID, &m_TeamID, sizeof(m_TeamID));
}

void AUAECharacter::update_TeamID()
{
	dma::Read(ptr + Offsets::AUAECharacter::TeamID, &m_TeamID, sizeof(m_TeamID));
}

void AUAECharacter::scatter_Health(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::AUAECharacter::Health, &m_Health, sizeof(m_Health));
	dma::Scatter_PrepareEx(hs, ptr + Offsets::AUAECharacter::Energy, &m_Energy, sizeof(m_Energy));
	dma::Scatter_PrepareEx(hs, ptr + Offsets::AUAECharacter::EnergyMax, &m_EnergyMax_Char, sizeof(m_EnergyMax_Char));
}

void AUAECharacter::scatter_SignalHP(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::AUAECharacter::SignalHP, &m_SignalHP, sizeof(m_SignalHP));
	dma::Scatter_PrepareEx(hs, ptr + Offsets::AUAECharacter::SignalHPMax, &m_SignalHPMax, sizeof(m_SignalHPMax));
}

void AUAECharacter::scatter_PawnState(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::AUAECharacter::PawnState, &m_PawnState, sizeof(int));
}

void AUAECharacter::scatter_PawnStateRepSyncData_TArray(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::AUAECharacter::PawnStateRepSyncData, &m_PawnStateRepSyncData_TArray, sizeof(TArray<unsigned char>));
}

void AUAECharacter::scatter_PawnStateRepSyncData_Content(VMMDLL_SCATTER_HANDLE hs)
{
	if (m_PawnStateRepSyncData_TArray.NumElements > 0 && m_PawnStateRepSyncData_TArray.NumElements < 100) {
		m_PawnStateRepSyncData_Data.resize(m_PawnStateRepSyncData_TArray.NumElements);
		dma::Scatter_PrepareEx(hs, m_PawnStateRepSyncData_TArray.Data, m_PawnStateRepSyncData_Data.data(), m_PawnStateRepSyncData_TArray.NumElements * sizeof(unsigned char));
	}
}

void AUAECharacter::scatter_PawnStatesExtend_FStr(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::AUAECharacter::PawnStatesExtend, &m_PawnStatesExtend_FStr, sizeof(FString));
}

void AUAECharacter::scatter_PawnStatesExtend_FStrToWstr(VMMDLL_SCATTER_HANDLE hs)
{
	m_PawnStatesExtend.resize(m_PawnStatesExtend_FStr.NumElements);
	dma::Scatter_PrepareEx(hs, m_PawnStatesExtend_FStr.Data, m_PawnStatesExtend.data(), m_PawnStatesExtend_FStr.NumElements * 2);
}

void AUAECharacter::scatter_bIsAI(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::AUAECharacter::bIsAI, &m_bIsAI, sizeof(m_bIsAI));
}

void AUAECharacter::scatter_CurrentUsingWeaponSafety(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::AUAECharacter::CurrentUsingWeaponSafety, m_CurrentUsingWeaponSafety.get_ptr_data(), sizeof(uint64_t));
}

void AUAECharacter::scatter_PlayerState(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::AUAECharacter::PlayerState, &m_PlayerStatePtr, sizeof(m_PlayerStatePtr));
}

void AUAECharacter::scatter_PlayerStateData(VMMDLL_SCATTER_HANDLE hs)
{
	if (m_PlayerStatePtr) {
		dma::Scatter_PrepareEx(hs, m_PlayerStatePtr + Offsets::ASTExtraPlayerState::Kills, &m_Kills, sizeof(m_Kills));
		dma::Scatter_PrepareEx(hs, m_PlayerStatePtr + Offsets::ASTExtraPlayerState::CurEnegyBuff, &m_EnergyBuff, sizeof(m_EnergyBuff));
		dma::Scatter_PrepareEx(hs, m_PlayerStatePtr + Offsets::ASTExtraPlayerState::SignalHP, &m_SignalHP_State, sizeof(m_SignalHP_State));
	}
}

void AUAECharacter::scatter_HealthStatus(VMMDLL_SCATTER_HANDLE hs)
{
	dma::Scatter_PrepareEx(hs, ptr + Offsets::AUAECharacter::HealthStatus, &m_HealthStatus, sizeof(m_HealthStatus));
}
