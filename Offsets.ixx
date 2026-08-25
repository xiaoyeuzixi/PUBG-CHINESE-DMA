export module Offsets;
import <string>;
import <cstdint>;



export struct Offsets
{
	static constexpr  std::string process_name = "wgprojectm.exe";

	struct Base
	{
		static constexpr int64_t CanvasMap = 0x1666C890;

		static constexpr int64_t GObjects = 0x0;
		static constexpr int64_t GNames = 0x160787F8;
		static constexpr int64_t GWorld = 0x155C4B88;


	};

	struct CanvasMap
	{
		static constexpr int64_t DebugCanvasObject = 0x20;
	};

	struct UObject
	{
		static constexpr int64_t FName = 0x18;
	};

	struct DebugCanvasObject
	{
		static constexpr int64_t Matrix = 0x270;
	};


	struct UWorld
	{
		static constexpr int64_t PersistentLevel = 0xB0; // ULevel*   
		static constexpr int64_t NetDriver = 0xB8; // UGameInstance*   
		static constexpr int64_t OwningGameInstance = 0xB08; // UGameInstance*   
	};


	struct UGameInstance
	{
		static constexpr int64_t LocalPlayers = 0x38; // TArray<ULocalPlayer*>   
	};

	struct UNetDriver
	{
		static constexpr int64_t ServerConnection = 0x88; // UNetConnection*
	};


	struct UPlayer
	{
		static constexpr int64_t PlayerController = 0x30; // APlayerController*   
	};

	struct APlayerController
	{
		static constexpr int64_t AcknowledgedPawn = 0x648; // APawn* 
		static constexpr int64_t PlayerCameraManager = 0x668;//    APlayerCameraManager* 
		static constexpr int64_t ControlRotation = 0x810; // FRotator
	};

	struct APlayerCameraManager
	{
		static constexpr int64_t CameraCache = 0x0640; // FCameraCacheEntry
	};

	struct ULevel
	{
		static constexpr int64_t Actors = 0xA0; // TArray<AActor*>   
	};

	struct AActor
	{
		static constexpr int64_t RootComponent = 0x260; // USceneComponent*  
		static constexpr int64_t ReplicatedMovement = 0x0168; // FRepMovement
	};


	struct ACharacter
	{
		static constexpr int64_t Mesh = 0x0660; //USkeletalMeshComponent*
	};


	struct USkinnedMeshComponent
	{
		static constexpr int64_t SkeletalMesh = 0x808; //USkeletalMesh*
		static constexpr int64_t boneArr1 = 0x828; //TArray<FTransform>
		static constexpr int64_t boneArr2 = 0x838; //TArray<FTransform>
		static constexpr int64_t boneNow = 0x86C; //uint32_t
		static constexpr int64_t CachedLocalBounds = 0x0994; //FBoxSphereBounds
		static constexpr int64_t ComponentToWorld = 0x01F0; //FTransform

	};

	struct USkeletalMesh
	{
		static constexpr int64_t ExtendedBounds = 0x008C; //FBoxSphereBounds
		static constexpr int64_t MeshBoneInfo = 0x220; //TArray<FMeshBoneInfo>  230 240 250 260
	};


	struct USceneComponent
	{
		static constexpr int64_t ComponentToWorld = 0x1F0; //FTransform
	};



	struct AUAECharacter
	{
		static constexpr int64_t PlayerName = 0xAF8; // FString
		static constexpr int64_t PlayerState = 0x5F0; // APlayerState*
		static constexpr int64_t TeamID = 0x0B78; // int32_t
		static constexpr int64_t bIsAI = 0x0B94; // bool
		static constexpr int64_t Health = 0xFF8; // float
		static constexpr int64_t SignalHP = 0x0100C; // float
		static constexpr int64_t SignalHPMax = 0x1020; // float
		static constexpr int64_t HealthStatus = 0x3928; // unsigned char
		static constexpr int64_t PawnStateRepSyncData = 0x1680; // TArray<unsigned char>
		static constexpr int64_t PawnState = 0x2324; // int
		static constexpr int64_t PawnStatesExtend = 0x19D0; // FString
		static constexpr int64_t CurrentUsingWeaponSafety = 0x1108; // ASTExtraWeapon*
		static constexpr int64_t EnergyMax = 0x3AC8; // float (FCharacterEnergyData.EnergyMax)
		static constexpr int64_t Energy = 0x3ADC; // float (FCharacterEnergyData.EnergyCurrent)
	};

	struct ASTExtraPlayerState {
		static constexpr int64_t Kills = 0x0834;
		static constexpr int64_t CurEnegyBuff = 0x1BA4;
		static constexpr int64_t SignalHP = 0x1D40;
	};

	struct ASTExtraWeapon {
		static constexpr int64_t WeaponEntityComp = 0x0C68; // UWeaponEntity*
		static constexpr int64_t CurBulletNumInClip = 0x1F88; // int
		static constexpr int64_t CurMaxBulletNumInOneClip = 0x1F8C; // int
	};

	struct UWeaponEntity {

		static constexpr int64_t BulletFireSpeed = 0x15CC;   // BulletFireSpeed
		static constexpr int64_t BulletGravityModifier = 0x15FC;// BulletGravityModifier
		static constexpr int64_t VRecoilFactor = 0x1E98;         // 垂直后坐力倍率
		static constexpr int64_t VRecoilModifier = 0x1E9C;       // 垂直修正
		static constexpr int64_t HRecoilFactor = 0x1EA4;         // 水平后坐力倍率
		static constexpr int64_t HRecoilModifier = 0x1EA8;       // 水平修正
		static constexpr int64_t RecoveryFactor = 0x1EB4;      // 恢复速度
	};

	struct ASTExtraVehicleBase
	{
		static constexpr int64_t VehicleCommon = 0x0BF0; // UVehicleCommonComponent*
	};

	struct UVehicleCommonComponent
	{
		static constexpr int64_t HPMax = 0x01F4; // float
		static constexpr int64_t HP = 0x01F8; // float
		static constexpr int64_t WheelsCurrentHP = 0x0200; // TArray<float>
		static constexpr int64_t FuelMax = 0x0218; // float
		static constexpr int64_t Fuel = 0x021C; // float
	};


};
