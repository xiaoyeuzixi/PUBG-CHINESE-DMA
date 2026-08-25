// 大佬QQ:2396031563
// Class Engine.ActorComponent
// 0x0100 (0x0128 - 0x0028)
class UActorComponent : public UObject
{
public:
struct FActorComponentTickFunction                 PrimaryComponentTick                                      // 0x0030(0x0060)
float                                              DSTickInterval                                            // 0x0090(0x0004)
TArray<struct FName>                               ComponentTags                                             // 0x0098(0x0010)
float                                              NetUpdateFrequency                                        // 0x00AC(0x0004)
Bool                                               bAllowBPReceiveTickEvent                                  // 0x00B1(0x0001)
unsigned char                                      TickAdapterIntvlOverride                                  // 0x00B2(0x0001)
Bool                                               bSyncOwnerTickAdapter                                     // 0x00B3(0x0001)
struct FScriptNetworkReplicatedPropertyWrapper     ScriptNetworkReplicatedPropertyWrapper                    // 0x00B8(0x0010)
Bool                                               bSupportSuspendTick                                       // 0x00D8(0x0001)
Bool                                               bDestroyIfOnClientNoLocalControl                          // 0x00D8(0x0001)
Bool                                               bReplicates                                               // 0x00D8(0x0001)
Bool                                               bNetAddressable                                           // 0x00D8(0x0001)
Bool                                               bDeferedConstructComponent                                // 0x00D9(0x0001)
Bool                                               bSkipNewDuplicateComponent                                // 0x00DA(0x0001)
Bool                                               bNameStableForBackupRestore                               // 0x00DA(0x0001)
Bool                                               bNeedBackupRestoreForCustomSerialize                      // 0x00DA(0x0001)
Bool                                               bEnableTickWhenOutOfRegion                                // 0x00DA(0x0001)
Bool                                               bAutoActivate                                             // 0x00DB(0x0001)
Bool                                               bIsActive                                                 // 0x00DB(0x0001)
Bool                                               bEditableWhenInherited                                    // 0x00DB(0x0001)
Bool                                               bCanEverAffectNavigation                                  // 0x00DB(0x0001)
Bool                                               bIsEditorOnly                                             // 0x00DC(0x0001)
Bool                                               bNeedsLoadForClient                                       // 0x00DC(0x0001)
Bool                                               bNeedsLoadForServer                                       // 0x00DC(0x0001)
Bool                                               bAllowRenderDataUpdateLag                                 // 0x00DC(0x0001)
EComponentCreationMethod                           CreationMethod                                            // 0x00DE(0x0001)
TArray<struct FSimpleMemberReference>              UCSModifiedProperties                                     // 0x00E0(0x0010)
struct FScriptMulticastDelegate                    OnComponentActivated                                      // 0x00F8(0x0010)
struct FScriptMulticastDelegate                    OnComponentDeactivated                                    // 0x0108(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AccumulateEnergyByHitComponent
// 0x00D0 (0x01F8 - 0x0128)
class UAccumulateEnergyByHitComponent : public UActorComponent
{
public:
float                                              MaxEnergy                                                 // 0x0128(0x0004)
TMap<EAvatarDamagePosition, float>                 HitEnergyValueConfigs                                     // 0x0130(0x0050)
TArray<int>                                        HitEnergyMonsterID                                        // 0x0180(0x0010)
float                                              TriggerSkillCD                                            // 0x0190(0x0004)
float                                              SkillRemainTime                                           // 0x0194(0x0004)
class UClass*                                      TriggerSkill                                              // 0x0198(0x0008)
float                                              EnergyMaintainTime                                        // 0x01A0(0x0004)
float                                              EnergyDecreaseValue                                       // 0x01A4(0x0004)
class ASTExtraShootWeapon*                         OwnerShootWeapon                                          // 0x01A8(0x0008)
float                                              CurEnergy                                                 // 0x01B0(0x0004)
float                                              LastAddEnergyTime                                         // 0x01B4(0x0004)
unsigned char                                      CurStatus                                                 // 0x01B8(0x0001)
class UPersistEffectBase*                          CurSkill                                                  // 0x01C0(0x0008)
struct FScriptMulticastDelegate                    OnCurStatusChangedDelegate                                // 0x01C8(0x0010)
struct FScriptMulticastDelegate                    OnAddEnergyDelegate                                       // 0x01D8(0x0010)
};

// 大佬QQ:2396031563
// Class Engine.Actor
// 0x05A8 (0x05D0 - 0x0028)
class AActor : public UObject
{
public:
struct FActorTickFunction                          PrimaryActorTick                                          // 0x0028(0x0060)
float                                              CustomTimeDilation                                        // 0x0088(0x0004)
Bool                                               bAllowBPReceiveTickEvent                                  // 0x008C(0x0001)
unsigned char                                      TickAdapterInterval                                       // 0x008D(0x0001)
Bool                                               bTickAdapterRqrMainFrame                                  // 0x008E(0x0001)
Bool                                               bSupportSuspendTick                                       // 0x008E(0x0001)
Bool                                               bHidden                                                   // 0x008E(0x0001)
Bool                                               bConsideredHidden                                         // 0x008E(0x0001)
Bool                                               bNetTemporary                                             // 0x008E(0x0001)
Bool                                               bNetStartup                                               // 0x008E(0x0001)
Bool                                               bOnlyRelevantToOwner                                      // 0x008E(0x0001)
Bool                                               bOwningSpecificNetConsideration                           // 0x008E(0x0001)
Bool                                               bRegionBasedNetConsideration                              // 0x008F(0x0001)
Bool                                               bMRegionBasedNetConsideration                             // 0x008F(0x0001)
Bool                                               bMRegionStatic                                            // 0x008F(0x0001)
Bool                                               bFastDistBasedNetRelevancy                                // 0x008F(0x0001)
Bool                                               bGroupBasedNetRelevancy                                   // 0x008F(0x0001)
Bool                                               bLazyNetReplication                                       // 0x008F(0x0001)
Bool                                               bClientSimulatedRelevancy                                 // 0x008F(0x0001)
Bool                                               bCheckAllRelyOnAttachment                                 // 0x008F(0x0001)
Bool                                               bAlwaysRelevant                                           // 0x0090(0x0001)
Bool                                               bForceOwnedMeshAlwaysRefreshBones                         // 0x0090(0x0001)
Bool                                               bTearOff                                                  // 0x0090(0x0001)
Bool                                               bExchangedRoles                                           // 0x0090(0x0001)
Bool                                               bNetLoadOnClient                                          // 0x0090(0x0001)
Bool                                               bNetUseOwnerRelevancy                                     // 0x0090(0x0001)
Bool                                               bBlockInput                                               // 0x0090(0x0001)
Bool                                               bCanBeBaseForCharacter                                    // 0x0091(0x0001)
Bool                                               bAllowTickBeforeBeginPlay                                 // 0x0091(0x0001)
Bool                                               bCustomHandlingNetworkSubobjectDeletion                   // 0x0091(0x0001)
Bool                                               bReplicates                                               // 0x0091(0x0001)
unsigned char                                      RemoteRole                                                // 0x0092(0x0001)
class AActor*                                      Owner                                                     // 0x0098(0x0008)
Bool                                               bReplicateMovement                                        // 0x00A0(0x0001)
Bool                                               bActorEnableCollision                                     // 0x00B8(0x0001)
Bool                                               bEnableDeferredConstructComponent                         // 0x00B8(0x0001)
Bool                                               bUseSpawnReplicatedActorMaxFrameDelayFromConfig           // 0x00B8(0x0001)
TArray<struct FDeferedComponentUnit>               PendingConstructComponents                                // 0x00C0(0x0010)
TArray<class UActorComponent*>                     PreSCSComponentsBeforeDeferContruction                    // 0x00D0(0x0010)
float                                              AsyncReplicatedActorSpawnDistA                            // 0x00E0(0x0004)
float                                              AsyncReplicatedActorSpawnDistB                            // 0x00E4(0x0004)
int                                                SpawnReplicatedActorMaxFrameDelayFromConfig               // 0x00E8(0x0004)
struct FScriptNetworkReplicatedPropertyWrapper     ScriptNetworkReplicatedPropertyWrapper                    // 0x0148(0x0010)
struct FName                                       NetDriverName                                             // 0x0168(0x0008)
struct FRepMovement                                ReplicatedMovement                                        // 0x0170(0x0034)
float                                              InitialLifeSpan                                           // 0x01A4(0x0004)
struct FRepAttachment                              AttachmentReplication                                     // 0x01A8(0x0050)
unsigned char                                      Role                                                      // 0x01F8(0x0001)
unsigned char                                      NetDormancy                                               // 0x01F9(0x0001)
unsigned char                                      AutoReceiveInput                                          // 0x01FA(0x0001)
int                                                InputPriority                                             // 0x01FC(0x0004)
class UInputComponent*                             InputComponent                                            // 0x0200(0x0008)
float                                              NetCullDistanceSquared                                    // 0x0208(0x0004)
float                                              NetCullFactorSquared                                      // 0x020C(0x0004)
float                                              OBRelevantFactor                                          // 0x0210(0x0004)
int                                                NetTag                                                    // 0x0214(0x0004)
float                                              NetConsiderFrequency                                      // 0x021C(0x0004)
float                                              NetUpdateFrequency                                        // 0x0220(0x0004)
float                                              MinNetUpdateFrequency                                     // 0x0224(0x0004)
int                                                NetUpdateJumpFrame                                        // 0x0228(0x0004)
float                                              NetPriority                                               // 0x0230(0x0004)
Bool                                               bAutoDestroyWhenFinished                                  // 0x023C(0x0001)
Bool                                               bCanBeDamaged                                             // 0x023C(0x0001)
Bool                                               bCanNotifyDamager                                         // 0x023C(0x0001)
Bool                                               bRepParentUpdatePhx                                       // 0x023C(0x0001)
Bool                                               bActorIsBeingDestroyed                                    // 0x023C(0x0001)
Bool                                               bCollideWhenPlacing                                       // 0x023C(0x0001)
Bool                                               bFindCameraComponentWhenViewTarget                        // 0x023D(0x0001)
Bool                                               bRelevantForNetworkReplays                                // 0x023D(0x0001)
Bool                                               bForcedRelevancyCheckForReplay                            // 0x023D(0x0001)
Bool                                               bLowUpdateRateForReplay                                   // 0x023D(0x0001)
Bool                                               bGenerateOverlapEventsDuringLevelStreaming                // 0x023D(0x0001)
Bool                                               bCanCachedInWorldSpecialActorList                         // 0x023D(0x0001)
Bool                                               bShouldDumpCallstackWhenMovingfast                        // 0x023D(0x0001)
Bool                                               bCanBeInCluster                                           // 0x023D(0x0001)
Bool                                               bAllowReceiveTickEventOnDedicatedServer                   // 0x023E(0x0001)
Bool                                               bActorSeamlessTraveled                                    // 0x023E(0x0001)
Bool                                               bIgnoresOriginShifting                                    // 0x023E(0x0001)
Bool                                               bEnableAutoLODGeneration                                  // 0x023E(0x0001)
ESpawnActorCollisionHandlingMethod                 SpawnCollisionHandlingMethod                              // 0x023F(0x0001)
float                                              CollisionCheckMoveDisStep                                 // 0x0240(0x0004)
float                                              CollisionCheckMoveDegreeStep                              // 0x0244(0x0004)
float                                              CollisionCheckCircleRadius                                // 0x0248(0x0004)
class APawn*                                       Instigator                                                // 0x0250(0x0008)
TArray<class AActor*>                              Children                                                  // 0x0258(0x0010)
class USceneComponent*                             RootComponent                                             // 0x0268(0x0008)
TArray<class AMatineeActor*>                       ControllingMatineeActors                                  // 0x0270(0x0010)
TArray<struct FName>                               Layers                                                    // 0x0288(0x0010)
TWeakObjectPtr<class UChildActorComponent>         ParentComponent                                           // 0x0298(0x0008)
TArray<struct FName>                               Tags                                                      // 0x02A0(0x0010)
TArray<struct FName>                               DynamicTags                                               // 0x02B8(0x0010)
struct FScriptMulticastDelegate                    OnTakeAnyDamage                                           // 0x02C8(0x0010)
struct FScriptMulticastDelegate                    OnTakePointDamage                                         // 0x02D8(0x0010)
struct FScriptMulticastDelegate                    OnActorBeginOverlap                                       // 0x02E8(0x0010)
struct FScriptMulticastDelegate                    OnActorEndOverlap                                         // 0x02F8(0x0010)
struct FScriptMulticastDelegate                    OnBeginCursorOver                                         // 0x0308(0x0010)
struct FScriptMulticastDelegate                    OnEndCursorOver                                           // 0x0318(0x0010)
struct FScriptMulticastDelegate                    OnClicked                                                 // 0x0328(0x0010)
struct FScriptMulticastDelegate                    OnReleased                                                // 0x0338(0x0010)
struct FScriptMulticastDelegate                    OnInputTouchBegin                                         // 0x0348(0x0010)
struct FScriptMulticastDelegate                    OnInputTouchEnd                                           // 0x0358(0x0010)
struct FScriptMulticastDelegate                    OnInputTouchEnter                                         // 0x0368(0x0010)
struct FScriptMulticastDelegate                    OnInputTouchLeave                                         // 0x0378(0x0010)
struct FScriptMulticastDelegate                    OnActorHit                                                // 0x0388(0x0010)
struct FScriptMulticastDelegate                    OnActorHitNew                                             // 0x0398(0x0010)
struct FScriptMulticastDelegate                    OnDestroyed                                               // 0x03A8(0x0010)
struct FScriptMulticastDelegate                    OnEndPlay                                                 // 0x03B8(0x0010)
struct FScriptMulticastDelegate                    OnBecomeViewTargetEvent                                   // 0x03F8(0x0010)
struct FScriptMulticastDelegate                    OnEndViewTargetEvent                                      // 0x0408(0x0010)
struct FScriptMulticastDelegate                    OnEndBlendViewTargetEvent                                 // 0x0418(0x0010)
struct FScriptMulticastDelegate                    ActorOnVaultEvent                                         // 0x0428(0x0010)
TArray<class UActorComponent*>                     BlueprintCreatedComponents                                // 0x04D8(0x0010)
TArray<class UActorComponent*>                     InstanceComponents                                        // 0x04E8(0x0010)
int64_t                                            BackupRestoreIdentifier                                   // 0x0520(0x0008)
Bool                                               NeedsBackupStates                                         // 0x0528(0x0001)
Bool                                               bSkipNewDuplicateOwnedComponents                          // 0x0528(0x0001)
Bool                                               bCanBeNetContainer                                        // 0x0528(0x0001)
Bool                                               bDonotAsSubActor                                          // 0x0558(0x0001)
unsigned char                                      DeformEffectType                                          // 0x0570(0x0001)
Bool                                               bBlockLandscapeDeform                                     // 0x0571(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AchievementDisplayActor
// 0x0050 (0x0620 - 0x05D0)
class AAchievementDisplayActor : public AActor
{
public:
class USceneComponent*                             RotatePivot                                               // 0x05C8(0x0008)
class UStaticMeshComponent*                        MeshComp                                                  // 0x05D0(0x0008)
class UParticleSystemComponent*                    EffectComp                                                // 0x05D8(0x0008)
struct FString                                     AchievementID                                             // 0x05E0(0x0010)
float                                              DragRotationSpeed                                         // 0x05F0(0x0004)
float                                              EffectScale                                               // 0x060C(0x0004)
struct FVector                                     EffectOffset                                              // 0x0610(0x000C)
};

// 大佬QQ:2396031563
// Class Gameplay.RacingTrack
// 0x00F0 (0x06C0 - 0x05D0)
class ARacingTrack : public AActor
{
public:
struct FName                                       TrackTag                                                  // 0x05C8(0x0008)
int                                                RaceRounds                                                // 0x05D0(0x0004)
float                                              RaceTotalTime                                             // 0x05D4(0x0004)
class ARacingCheckPoint*                           StartCheckPoint                                           // 0x05D8(0x0008)
class ARacingCheckPoint*                           EndCheckPoint                                             // 0x05E0(0x0008)
class UClass*                                      VehicleClass                                              // 0x05E8(0x0008)
TArray<struct FPlayerRacingRecord>                 PlayerRacingRecords                                       // 0x05F8(0x0010)
TMap<uint32_t, class AController*>                 AllRacingPlayers                                          // 0x0618(0x0050)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AcrobaticsRacingTrack
// 0x0070 (0x0730 - 0x06C0)
class AAcrobaticsRacingTrack : public ARacingTrack
{
public:
int                                                FactorK                                                   // 0x06B8(0x0004)
int                                                MultiDVMax                                                // 0x06BC(0x0004)
int                                                FactorA                                                   // 0x06C0(0x0004)
int                                                FactorB                                                   // 0x06C4(0x0004)
float                                              FactorJ                                                   // 0x06C8(0x0004)
int                                                FactorC                                                   // 0x06CC(0x0004)
float                                              BonusPow                                                  // 0x06D0(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActionConditionContainer
// 0x0130 (0x0158 - 0x0028)
class UActionConditionContainer : public UObject
{
public:
TArray<struct FSkillActionData>                    ActionsList                                               // 0x0038(0x0010)
TArray<struct FSkillConditionData>                 ConditionsList                                            // 0x0048(0x0010)
TMap<class UObject*, int>                          InstancedNodeNameToMemoryMap                              // 0x0058(0x0050)
class AActor*                                      InteractingActor                                          // 0x0150(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.LogicEffectBase
// 0x0028 (0x0050 - 0x0028)
class ULogicEffectBase : public UObject
{
public:
float                                              LoopInterval                                              // 0x0028(0x0004)
struct FLogicEffectSequenceWrapper                 SubEffectListWrapper                                      // 0x0030(0x0010)
class AActor*                                      EffectOwnerActor                                          // 0x0040(0x0008)
struct FTimerHandle                                LoopTimerHandle                                           // 0x0048(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActionEffect_ChangeCameraSpringArmLength
// 0x00F0 (0x0140 - 0x0050)
class UActionEffect_ChangeCameraSpringArmLength : public UActionEffect
{
public:
EPerspectiveMode                                   PerspectiveMode                                           // 0x0050(0x0001)
float                                              NewSpringArmLength                                        // 0x0054(0x0004)
Bool                                               bModifyEnableCameraLag                                    // 0x0058(0x0001)
Bool                                               bEnableCameraLag                                          // 0x0059(0x0001)
Bool                                               bOverrideSocket                                           // 0x005A(0x0001)
Bool                                               bOverrideTarget                                           // 0x005B(0x0001)
struct FVector                                     SocketOffset                                              // 0x005C(0x000C)
struct FVector                                     TargetOffset                                              // 0x0068(0x000C)
Bool                                               bOverrideOperateType                                      // 0x0074(0x0001)
ECameraDataOperateType                             OperateType                                               // 0x0075(0x0001)
struct FName                                       CameraDataName                                            // 0x0078(0x0008)
struct FCameraOffsetData                           CameraData                                                // 0x0080(0x00A0)
Bool                                               bHasApplyed                                               // 0x0120(0x0001)
ELogicEffectOp                                     DelayEffectOp                                             // 0x0121(0x0001)
float                                              CacheOldSpringArmLength                                   // 0x0124(0x0004)
struct FVector                                     CacheOldSocketOffset                                      // 0x0128(0x000C)
struct FVector                                     CacheOldTargetOffset                                      // 0x0134(0x000C)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActionEffect_ChangeFPP
// 0x0008 (0x0058 - 0x0050)
class UActionEffect_ChangeFPP : public UActionEffect
{
public:
Bool                                               bIsFPP                                                    // 0x0050(0x0001)
Bool                                               bCacheIsFPP                                               // 0x0051(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActionEffect_ChangeGameplayState
// 0x0018 (0x0068 - 0x0050)
class UActionEffect_ChangeGameplayState : public UActionEffect
{
public:
struct FGameplayTag                                TargetState                                               // 0x0050(0x0010)
EGameplayStateOp                                   StateOp                                                   // 0x0060(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActionEffect_ChangeOldWeaponState
// 0x0008 (0x0058 - 0x0050)
class UActionEffect_ChangeOldWeaponState : public UActionEffect
{
public:
EFreshWeaponStateType                              ApplyState                                                // 0x0050(0x0001)
EFreshWeaponStateType                              UnApplyState                                              // 0x0051(0x0001)
Bool                                               bAutonomousOnly                                           // 0x0052(0x0001)
Bool                                               bServerOnly                                               // 0x0053(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActionEffect_DisablePawnState
// 0x0020 (0x0070 - 0x0050)
class UActionEffect_DisablePawnState : public UActionEffect
{
public:
TArray<EPawnState>                                 DisablePawnStateList                                      // 0x0050(0x0010)
TArray<struct FGameplayTag>                        DisablePawnDynamicStateList                               // 0x0060(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActionEffect_FireWeaponBegin
// 0x0030 (0x0080 - 0x0050)
class UActionEffect_FireWeaponBegin : public UActionEffect
{
public:
struct FUAEBlackboardKeySelector                   Key_CurCheckShowShootVoiceTime                            // 0x0050(0x0008)
struct FUAEBlackboardKeySelector                   Key_ShootLockThreshold                                    // 0x0058(0x0008)
struct FUAEBlackboardKeySelector                   Key_bIsFirstShot                                          // 0x0060(0x0008)
struct FUAEBlackboardKeySelector                   Key_bNeedStopFire                                         // 0x0068(0x0008)
struct FUAEBlackboardKeySelector                   Key_bSimClientCheckAndStopFire                            // 0x0070(0x0008)
struct FUAEBlackboardKeySelector                   Key_HandledStartTime                                      // 0x0078(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActionEffect_FireWeaponCheckStop
// 0x0010 (0x0060 - 0x0050)
class UActionEffect_FireWeaponCheckStop : public UActionEffect
{
public:
struct FUAEBlackboardKeySelector                   Key_HandledStartTime                                      // 0x0050(0x0008)
struct FUAEBlackboardKeySelector                   Key_bNeedStopFire                                         // 0x0058(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActionEffect_FireWeaponEnd
// 0x0018 (0x0068 - 0x0050)
class UActionEffect_FireWeaponEnd : public UActionEffect
{
public:
struct FUAEBlackboardKeySelector                   Key_ShootLockIndex                                        // 0x0050(0x0008)
struct FUAEBlackboardKeySelector                   Key_ShootLockThreshold                                    // 0x0058(0x0008)
struct FUAEBlackboardKeySelector                   Key_bSimClientCheckAndStopFire                            // 0x0060(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActionEffect_FireWeaponShot
// 0x0040 (0x0090 - 0x0050)
class UActionEffect_FireWeaponShot : public UActionEffect
{
public:
struct FUAEBlackboardKeySelector                   Key_bIsFirstShot                                          // 0x0050(0x0008)
struct FUAEBlackboardKeySelector                   Key_StartFiringLevelTime                                  // 0x0058(0x0008)
struct FUAEBlackboardKeySelector                   Key_LastFireLevelTime                                     // 0x0060(0x0008)
struct FUAEBlackboardKeySelector                   Key_LastBurstFireLevelTime                                // 0x0068(0x0008)
struct FUAEBlackboardKeySelector                   Key_ShootLockIndex                                        // 0x0070(0x0008)
struct FUAEBlackboardKeySelector                   Key_ShootLockThreshold                                    // 0x0078(0x0008)
struct FUAEBlackboardKeySelector                   Key_bInEmptyFireState                                     // 0x0080(0x0008)
struct FUAEBlackboardKeySelector                   Key_bNeedStopFire                                         // 0x0088(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActionEffect_FireWeaponShotVoiceCheck
// 0x0008 (0x0058 - 0x0050)
class UActionEffect_FireWeaponShotVoiceCheck : public UActionEffect
{
public:
struct FUAEBlackboardKeySelector                   Key_CurCheckShowShootVoiceTime                            // 0x0050(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActionEffect_IdleAutoProcess
// 0x0010 (0x0060 - 0x0050)
class UActionEffect_IdleAutoProcess : public UActionEffect
{
public:
float                                              AutoProcessDelayTime                                      // 0x0050(0x0004)
int                                                AmmoCheckFrequency                                        // 0x0054(0x0004)
int                                                CurAmmoCheckFrequency                                     // 0x0058(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActionEffect_IdleWeaponBegin
// 0x0008 (0x0058 - 0x0050)
class UActionEffect_IdleWeaponBegin : public UActionEffect
{
public:
struct FTimerHandle                                IdleHandler                                               // 0x0050(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActionEffect_PlayMontage
// 0x00C8 (0x0118 - 0x0050)
class UActionEffect_PlayMontage : public UActionEffect
{
public:
class UAnimMontage*                                AnimMontage                                               // 0x0050(0x0008)
class UAnimMontage*                                AnimMontageFPP                                            // 0x0058(0x0008)
class UAnimMontage*                                AnimMontageNewFPP                                         // 0x0060(0x0008)
Bool                                               bAnimDiffByVehicle                                        // 0x0068(0x0001)
class UAnimMontage*                                AnimMontageVehicleTPP                                     // 0x0070(0x0008)
class UAnimMontage*                                AnimMontageVehicleFPP                                     // 0x0078(0x0008)
class UAnimMontage*                                AnimMontageVehicleNewFPP                                  // 0x0080(0x0008)
Bool                                               bAnimDiffByPose                                           // 0x0088(0x0001)
struct FActionEffect_PoseMontageData               PoseMontageDataTPP                                        // 0x0090(0x0020)
struct FActionEffect_PoseMontageData               PoseMontageDataFPP                                        // 0x00B0(0x0020)
struct FActionEffect_PoseMontageData               PoseMontageDataNewFPP                                     // 0x00D0(0x0020)
Bool                                               StopPrevMontage                                           // 0x00F0(0x0001)
Bool                                               bUnApplyStopAnim                                          // 0x00F1(0x0001)
Bool                                               bOnlySimulation                                           // 0x00F2(0x0001)
float                                              StartPosition                                             // 0x00F4(0x0004)
struct FName                                       StartSectionName                                          // 0x00F8(0x0008)
class UAnimMontage*                                CachePlayingAnimMontageTPP                                // 0x0100(0x0008)
class UAnimMontage*                                CachePlayingAnimMontageFPP                                // 0x0108(0x0008)
class UAnimMontage*                                CachePlayingAnimMontageNewFPP                             // 0x0110(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActionEffect_PreFireWeaponBegin
// 0x0008 (0x0058 - 0x0050)
class UActionEffect_PreFireWeaponBegin : public UActionEffect
{
public:
struct FUAEBlackboardKeySelector                   Key_CheckEndPreFireState                                  // 0x0050(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActionEffect_PreFireWeaponCheckEnd
// 0x0008 (0x0058 - 0x0050)
class UActionEffect_PreFireWeaponCheckEnd : public UActionEffect
{
public:
struct FUAEBlackboardKeySelector                   Key_CheckEndPreFireState                                  // 0x0050(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActionEffect_SetBlackboardValue
// 0x0010 (0x0060 - 0x0050)
class UActionEffect_SetBlackboardValue : public UActionEffect
{
public:
TArray<struct FUAEBlackboardParameter>             BlackboardParamList                                       // 0x0050(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActionEffect_ShowCDPrompt
// 0x0028 (0x0078 - 0x0050)
class UActionEffect_ShowCDPrompt : public UActionEffect
{
public:
float                                              TotalShowTime                                             // 0x0050(0x0004)
Bool                                               bShowWhenSpectating                                       // 0x0054(0x0001)
struct FString                                     ShowMsgTip                                                // 0x0058(0x0010)
struct FLogicEffectSequenceWrapper                 CancelCDBarEffectConfig                                   // 0x0068(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActionEffect_SpesificFunction
// 0x0040 (0x0090 - 0x0050)
class UActionEffect_SpesificFunction : public UActionEffect
{
public:
struct FName                                       ApplyFuncName                                             // 0x0050(0x0008)
float                                              ApplyDelayTime                                            // 0x0058(0x0004)
struct FName                                       UnApplyFuncName                                           // 0x0060(0x0008)
float                                              UnApplyDelayTime                                          // 0x0068(0x0004)
Bool                                               bServerOnly                                               // 0x006C(0x0001)
struct FTimerHandle                                ApplyHandle                                               // 0x0080(0x0008)
struct FTimerHandle                                UnApplyHandle                                             // 0x0088(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActionEffect_SwitchPoseState
// 0x0008 (0x0058 - 0x0050)
class UActionEffect_SwitchPoseState : public UActionEffect
{
public:
unsigned char                                      ApplyPoseState                                            // 0x0050(0x0001)
unsigned char                                      UnApplyPoseState                                          // 0x0051(0x0001)
Bool                                               bIgnoreCD                                                 // 0x0052(0x0001)
Bool                                               bIgnoreCheck                                              // 0x0053(0x0001)
Bool                                               bShouldShowPrompt                                         // 0x0054(0x0001)
Bool                                               bIsTriggerByPressBtn                                      // 0x0055(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActionEffect_UserWidgetStyle
// 0x0010 (0x0060 - 0x0050)
class UActionEffect_UserWidgetStyle : public UActionEffect
{
public:
class UUserWidgetStyle*                            TargetUserWidgetStyle                                     // 0x0050(0x0008)
Bool                                               bAutonomousOnly                                           // 0x0058(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActionEffect_ViewLimit
// 0x0038 (0x0088 - 0x0050)
class UActionEffect_ViewLimit : public UActionEffect
{
public:
struct FVector2D                                   PitchLimit                                                // 0x0050(0x0008)
Bool                                               bApplyPitchLimit                                          // 0x0058(0x0001)
Bool                                               bApplyRelativePitchLimit                                  // 0x0059(0x0001)
struct FVector2D                                   YawLimit                                                  // 0x005C(0x0008)
Bool                                               bApplyYawLimit                                            // 0x0064(0x0001)
Bool                                               bApplyRelativeYawLimit                                    // 0x0065(0x0001)
class ASTExtraPlayerController*                    cachePC                                                   // 0x0068(0x0008)
Bool                                               bHasApplyPitchLimit                                       // 0x0070(0x0001)
Bool                                               bHasApplyYawLimit                                         // 0x0071(0x0001)
struct FVector2D                                   PreviousPitchLimit                                        // 0x0074(0x0008)
struct FVector2D                                   PreviousYawLimit                                          // 0x007C(0x0008)
};

// 大佬QQ:2396031563
// Class Gameplay.UAERegionActor
// 0x0010 (0x05E0 - 0x05D0)
class AUAERegionActor : public AActor
{
public:
Bool                                               bStatic                                                   // 0x05D0(0x0001)
ERegionSizeIndex                                   RegionSize                                                // 0x05D1(0x0001)
Bool                                               bNeedUpdateNetworkInfo                                    // 0x05D2(0x0001)
Bool                                               bIsPurelyClientObject                                     // 0x05D3(0x0001)
Bool                                               bMRegionEnabled                                           // 0x05D5(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActivityActorForClient
// 0x0180 (0x0760 - 0x05E0)
class AActivityActorForClient : public AUAERegionActor
{
public:
struct FActorPlaybackSetting                       PlaybackSetting                                           // 0x0600(0x0002)
Bool                                               bAutoActiveArm                                            // 0x0602(0x0001)
class UClass*                                      SequenceLoadingAppearance                                 // 0x0608(0x0008)
TArray<struct FActivityState>                      StateMachineInfo                                          // 0x0620(0x0010)
struct FActivityStateRep                           CurrentIndex                                              // 0x0630(0x0014)
struct FActivitySequenceWrapper                    SequenceWrapper                                           // 0x0650(0x00F0)
};

// 大佬QQ:2396031563
// Class Basic.UAENetActor
// 0x0020 (0x05F0 - 0x05D0)
class AUAENetActor : public AActor
{
public:
Bool                                               bForceUseFastRelevancy                                    // 0x05E0(0x0001)
Bool                                               bNeedUpdateNetworkInfo                                    // 0x05E2(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActivityAreaCPP
// 0x0010 (0x0600 - 0x05F0)
class AActivityAreaCPP : public AUAENetActor
{
public:
unsigned char                                      IsDaytime                                                 // 0x05E8(0x0001)
Bool                                               ShowRabbitAnim                                            // 0x05E9(0x0001)
TArray<class APawn*>                               PawnDoneList                                              // 0x05F0(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.PersistEffectBase
// 0x0130 (0x0158 - 0x0028)
class UPersistEffectBase : public UBasicPersistEffect
{
public:
Bool                                               bUseCustomTickFunction                                    // 0x0040(0x0001)
struct FPersistEffectTickFunction                  PersistEffectTickFunction                                 // 0x0048(0x0060)
float                                              ApplyTime                                                 // 0x00AC(0x0004)
struct FGameplayTagContainer                       BuffTags                                                  // 0x00B0(0x0020)
struct FGameplayTagContainer                       PETags                                                    // 0x00D0(0x0020)
Bool                                               bUseApplyWhitelist                                        // 0x00F0(0x0001)
TArray<EPawnState>                                 Whitelist_PawnState                                       // 0x00F8(0x0010)
Bool                                               DelayDestroy                                              // 0x0108(0x0001)
Bool                                               bNetUpdatePostNetReceive                                  // 0x0109(0x0001)
float                                              TargetDuringTime                                          // 0x010C(0x0004)
class UPersistBaseComponent*                       Owner                                                     // 0x0110(0x0008)
class UObject*                                     Source                                                    // 0x0118(0x0008)
float                                              ApplyStartTime                                            // 0x0120(0x0004)
float                                              ApplyVaildTime                                            // 0x0124(0x0004)
struct FScriptMulticastDelegate                    OnCanclePersistEffect                                     // 0x0130(0x0010)
struct FScriptMulticastDelegate                    OnUnApplyPersistEffectEvent                               // 0x0140(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AT_ExampleBase
// 0x0008 (0x0160 - 0x0158)
class UAT_ExampleBase : public UPersistEffectBase
{
public:
class UActorComponent*                             AutoTestComp                                              // 0x0158(0x0008)
};

// 大佬QQ:2396031563
// Class GameplayTasks.GameplayTask
// 0x0040 (0x0068 - 0x0028)
class UGameplayTask : public UObject
{
public:
struct FName                                       InstanceName                                              // 0x0030(0x0008)
ETaskResourceOverlapPolicy                         ResourceOverlapPolicy                                     // 0x003A(0x0001)
class UGameplayTask*                               ChildTask                                                 // 0x0060(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ControllerGetter
// 0x00B0 (0x00D8 - 0x0028)
class UControllerGetter : public UObject
{
public:
TArray<TWeakObjectPtr<class APlayerController>>    ControllerList                                            // 0x0028(0x0010)
TMap<TWeakObjectPtr<class APlayerController>, int> PCToID                                                    // 0x0038(0x0050)
TMap<int, TWeakObjectPtr<class APlayerController>> IDToPC                                                    // 0x0088(0x0050)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActivityAutoTestManager
// 0x0000 (0x05D0 - 0x05D0)
class AActivityAutoTestManager : public AActor
{
public:
class UActivityAutoTestComponent*                  AutoTestComponent                                         // 0x05C8(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActivityAutoTestComponent
// 0x0150 (0x0278 - 0x0128)
class UActivityAutoTestComponent : public UActorComponent
{
public:
TArray<int64_t>                                    TestingPCKey                                              // 0x0128(0x0010)
TArray<struct FAT_TestExampleConfig>               ExampleClassConfigs                                       // 0x0138(0x0010)
TMap<int, struct FAT_RegionalObject>               ActivityList                                              // 0x0148(0x0050)
TArray<struct FAT_RegionalDivision>                AreaListConfig                                            // 0x0198(0x0010)
TArray<struct FAT_RegionalDivision>                AreaListForEditorTest                                     // 0x01A8(0x0010)
TArray<struct FAT_RegionalDivision>                AreaList                                                  // 0x01B8(0x0010)
unsigned char                                      PCManagerType                                             // 0x01C8(0x0001)
float                                              TeleportPcHeight                                          // 0x01CC(0x0004)
TMap<int, struct FAT_RegionalPC>                   RegionalPCList                                            // 0x01D0(0x0050)
TMap<TWeakObjectPtr<class APlayerController>, int> PC2AreaNumber                                             // 0x0220(0x0050)
class UControllerGetter*                           ControllerGetter                                          // 0x0270(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActivityBaseActor
// 0x03E0 (0x09C0 - 0x05E0)
class AActivityBaseActor : public AUAERegionActor
{
public:
Bool                                               bAutoActiveArm                                            // 0x06B8(0x0001)
struct FScriptMulticastDelegate                    OnActivityActorChangeState                                // 0x06C0(0x0010)
struct FActorPlaybackSetting                       PlaybackSetting                                           // 0x06D0(0x0002)
struct FScriptMulticastDelegate                    OnActorCustomStateChange                                  // 0x06D8(0x0010)
TMap<EAvatarSlotType, struct FAvatarAnimAdaptParam> ActivityAvatarAnimAdaptParamMap                           // 0x06E8(0x0050)
Bool                                               bOverrideTransform                                        // 0x0738(0x0001)
TArray<struct FActivityState>                      StateMachineInfo                                          // 0x0740(0x0010)
float                                              RestoreThreshold                                          // 0x0750(0x0004)
Bool                                               bForceAlwaysTick                                          // 0x0754(0x0001)
Bool                                               bUseInstanceTimeRestore                                   // 0x0755(0x0001)
Bool                                               bUseSureTimeRestore                                       // 0x0756(0x0001)
Bool                                               bUseDSTransformOrgin                                      // 0x0757(0x0001)
Bool                                               bAutoBindingSelfLevelSequnce                              // 0x0758(0x0001)
class UClass*                                      SequenceLoadingAppearance                                 // 0x0760(0x0008)
Bool                                               bUsePropertyFilter                                        // 0x0768(0x0001)
Bool                                               bUseCompReplicatorOpt                                     // 0x0769(0x0001)
struct FTransform                                  CurrentTransform                                          // 0x0770(0x0030)
struct FActivityStateRep                           CurrentIndex                                              // 0x07A0(0x0014)
struct FActivitySequenceWrapper                    SequenceWrapper                                           // 0x07C0(0x00F0)
float                                              InstanceServerTime                                        // 0x08B0(0x0004)
class USceneComponent*                             SceneCom                                                  // 0x08B8(0x0008)
class URelativeMoveMgrComponent*                   RelativeMoveMgrComp                                       // 0x08C0(0x0008)
Bool                                               bEnableAttachmentReplication                              // 0x08C8(0x0001)
Bool                                               bMarkClientSequenceTimeDirty                              // 0x08C9(0x0001)
Bool                                               bAsNetContainer                                           // 0x08CA(0x0001)
Bool                                               CorrectPXTransUsingRemovePhysTargetFunction               // 0x08CB(0x0001)
Bool                                               bIsCreateRelativeMoveMgr                                  // 0x08CC(0x0001)
Bool                                               bKeepBase                                                 // 0x08CD(0x0001)
Bool                                               bNeedExitVehicleBeforeAttach                              // 0x08CE(0x0001)
Bool                                               bClientCheckPendingKillWhenPlayerDettached                // 0x08CF(0x0001)
class UUAEBlackboard*                              ActorBlackboard                                           // 0x08E0(0x0008)
TArray<struct FUAEBlackboardParameter>             ActorBlackboardParams                                     // 0x08E8(0x0010)
struct FScriptMulticastDelegate                    OnPlayerAttachedDelegate                                  // 0x08F8(0x0010)
struct FScriptMulticastDelegate                    OnPlayerDettachedDelegate                                 // 0x0908(0x0010)
struct FScriptMulticastDelegate                    OnOBInDelegate                                            // 0x0918(0x0010)
struct FScriptMulticastDelegate                    OnOBOutDelegate                                           // 0x0928(0x0010)
float                                              TlogEnterTime                                             // 0x093C(0x0004)
int                                                InteractObjectID                                          // 0x0940(0x0004)
Bool                                               bNetUpdatePostNetReceive                                  // 0x0944(0x0001)
TScriptInterface<class UCustomNetRelevantInterface> ReplaceCustomNetRelevant                                  // 0x0948(0x0010)
TArray<TScriptInterface<class UCustomNetRelevantInterface>> AddtiveCustomNetRelevant                                  // 0x0958(0x0010)
Bool                                               bNeedParentConsiderRelevant                               // 0x0980(0x0001)
Bool                                               bEnableChangeTickInterval                                 // 0x09B4(0x0001)
Bool                                               bEnableChangeComponentTick                                // 0x09B5(0x0001)
int                                                DefaultObjectPoolSize                                     // 0x09B8(0x0004)
int                                                DefaultObjectPoolCleanupTime                              // 0x09BC(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActivityCondition_TimeLeave
// 0x0008 (0x0038 - 0x0030)
class UActivityCondition_TimeLeave : public UActivityConditionBase
{
public:
float                                              DuringTime                                                // 0x0030(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.NetAlienationData
// 0x0010 (0x0038 - 0x0028)
class UNetAlienationData : public UObject
{
public:
TWeakObjectPtr<class UNetAlienationDataComponent>  Owner                                                     // 0x0028(0x0008)
Bool                                               bUsePC                                                    // 0x0030(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.RepViaPCNetAlienationData
// 0x0068 (0x00A0 - 0x0038)
class URepViaPCNetAlienationData : public UNetAlienationData
{
public:
unsigned char                                      RelevantPCs                                               // 0x0038(0x0050)
class UNetAlienationDataComponent*                 ReplicatedOwner                                           // 0x0088(0x0008)
TArray<class UNetConnection*>                      CacheConnections                                          // 0x0090(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActivityEctypeData
// 0x0180 (0x0220 - 0x00A0)
class UActivityEctypeData : public URepViaPCNetAlienationData
{
public:
struct FFActivityStateEctypeRep                    RepInfo                                                   // 0x00A0(0x0038)
struct FScriptMulticastDelegate                    OnActivityActorChangeState                                // 0x00D8(0x0010)
float                                              ServeEnterSequenceTime                                    // 0x00E8(0x0004)
struct FFActivityStateEctypeRep                    LocalRepInfo                                              // 0x00EC(0x0038)
struct FRegistPossessValue                         Value                                                     // 0x0128(0x00D8)
TWeakObjectPtr<class UActivityEctypeSystemComponent> Master                                                    // 0x0200(0x0008)
TArray<TWeakObjectPtr<class ASTExtraPlayerController>> EctypePCs                                                 // 0x0208(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActivityEctypeSystemComponent
// 0x0070 (0x0198 - 0x0128)
class UActivityEctypeSystemComponent : public UActorComponent
{
public:
class UClass*                                      DataClass                                                 // 0x0128(0x0008)
int                                                MaxCount                                                  // 0x0130(0x0004)
struct FScriptMulticastDelegate                    ClearEctypeDataDelegate                                   // 0x0138(0x0010)
TMap<TWeakObjectPtr<class ASTExtraPlayerController>, class UActivityEctypeData*> EctypeDataMap                                             // 0x0148(0x0050)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActivityEventState_NAD
// 0x00E0 (0x0118 - 0x0038)
class UActivityEventState_NAD : public UNetAlienationData
{
public:
TArray<struct FActivityEventStateData>             StateRep                                                  // 0x0038(0x0010)
struct FActivityEventStateConfig                   ActivityEventStateConfig                                  // 0x0048(0x0060)
struct FScriptMulticastDelegate                    OnActivityEventStateChange                                // 0x00A8(0x0010)
TMap<struct FName, struct FTimerHandle>            StateTHMap                                                // 0x00B8(0x0050)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActivityFactoryBase
// 0x0010 (0x09D0 - 0x09C0)
class AActivityFactoryBase : public AActivityBaseActor
{
public:
Bool                                               bCustomNetZ                                               // 0x09C0(0x0001)
float                                              bNetRelevantZ                                             // 0x09C4(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActivityFakePossessComponent
// 0x0148 (0x0270 - 0x0128)
class UActivityFakePossessComponent : public UActorComponent
{
public:
struct FScriptMulticastDelegate                    PreUnPossess                                              // 0x0130(0x0010)
struct FScriptMulticastDelegate                    OnPossess                                                 // 0x0140(0x0010)
struct FScriptMulticastDelegate                    OnUnpossess                                               // 0x0150(0x0010)
struct FScriptMulticastDelegate                    OnUnPossessWithReason                                     // 0x0160(0x0010)
struct FScriptMulticastDelegate                    OnPossessIncludingAI                                      // 0x0170(0x0010)
struct FScriptMulticastDelegate                    OnUnPossessIncludingAI                                    // 0x0180(0x0010)
struct FScriptMulticastDelegate                    OnRepCurrentPossesser                                     // 0x0190(0x0010)
float                                              DetachSpareOffsetZ                                        // 0x01A0(0x0004)
int                                                Iterations                                                // 0x01A4(0x0004)
Bool                                               bDettachSetMovementMode                                   // 0x01A8(0x0001)
Bool                                               bOnDettachedRecoverMovement                               // 0x01A9(0x0001)
class ASTExtraBaseCharacter*                       CurrentPossessCharacter                                   // 0x01B0(0x0008)
TArray<EPawnState>                                 DisablePawnState                                          // 0x01B8(0x0010)
TArray<struct FGameplayTag>                        DisableDynamicPawnState                                   // 0x01C8(0x0010)
TArray<EPawnState>                                 RejectPawnState                                           // 0x01D8(0x0010)
TArray<struct FGameplayTag>                        RejectDynamicPawnState                                    // 0x01E8(0x0010)
TArray<EPossessClearState>                         ClearPawnState                                            // 0x01F8(0x0010)
TArray<EPawnState>                                 CantPossessState                                          // 0x0208(0x0010)
TArray<struct FGameplayTag>                        CantPossessDynamicState                                   // 0x0218(0x0010)
TArray<EPossessRejectEvent>                        RejectEvent                                               // 0x0228(0x0010)
Bool                                               bSetOwnerToPC                                             // 0x0238(0x0001)
Bool                                               bOpenAfterResult                                          // 0x0239(0x0001)
struct FName                                       SubInstanceSlotName                                       // 0x0240(0x0008)
class UClass*                                      SubInstanceClass                                          // 0x0248(0x0008)
class UActivityFakePossessCore*                    FakePossessCore                                           // 0x0250(0x0008)
class UActionConditionContainer*                   ActionConditionContainer                                  // 0x0260(0x0008)
Bool                                               bIsInitActionContainer                                    // 0x0268(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActivityFakePossessMultiplyComponent
// 0x00C8 (0x01F0 - 0x0128)
class UActivityFakePossessMultiplyComponent : public UActorComponent
{
public:
struct FScriptMulticastDelegate                    OnPossess                                                 // 0x0128(0x0010)
struct FScriptMulticastDelegate                    OnUnpossess                                               // 0x0138(0x0010)
struct FScriptMulticastDelegate                    OnUnPossessWithReason                                     // 0x0148(0x0010)
TArray<class AActor*>                              CurrentPossessHandleActor                                 // 0x0158(0x0010)
TMap<uint32_t, class AActor*>                      PlayerKey2PossessActerCache                               // 0x0168(0x0050)
TArray<class UActivityFakePossessComponent*>       CurrentPossessHandleComp                                  // 0x01B8(0x0010)
int                                                DefaultObjectPool                                         // 0x01C8(0x0004)
EPossessMode                                       PossessMode                                               // 0x01CC(0x0001)
class UClass*                                      PossessHandleActorClass                                   // 0x01D0(0x0008)
Bool                                               bNeedAttachToOwner                                        // 0x01D8(0x0001)
class UClass*                                      PossessHandleCompClass                                    // 0x01E0(0x0008)
class UClass*                                      CustomNetRelevantClass                                    // 0x01E8(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActivityFakePossessOnClientComponent
// 0x00D8 (0x0200 - 0x0128)
class UActivityFakePossessOnClientComponent : public UActorComponent
{
public:
struct FScriptMulticastDelegate                    OnPossess                                                 // 0x0130(0x0010)
struct FScriptMulticastDelegate                    OnUnpossess                                               // 0x0140(0x0010)
struct FScriptMulticastDelegate                    OnUnPossessWithReason                                     // 0x0150(0x0010)
class ASTExtraBaseCharacter*                       CurrentPossessCharacter                                   // 0x0160(0x0008)
TArray<EPawnState>                                 DisablePawnState                                          // 0x0168(0x0010)
TArray<EPawnState>                                 RejectPawnState                                           // 0x0178(0x0010)
TArray<EPossessClearState>                         ClearPawnState                                            // 0x0188(0x0010)
TArray<EPawnState>                                 CantPossessState                                          // 0x0198(0x0010)
struct FGameplayTagContainer                       CantPossessDynamicState                                   // 0x01A8(0x0020)
struct FGameplayTagContainer                       RejectDynamicState                                        // 0x01C8(0x0020)
float                                              DetachSpareOffsetZ                                        // 0x01E8(0x0004)
Bool                                               bDettachSetMovementMode                                   // 0x01EC(0x0001)
Bool                                               bOnDettachedRecoverMovement                               // 0x01ED(0x0001)
class USceneComponent*                             OldSencen                                                 // 0x01F8(0x0008)
};

// 大佬QQ:2396031563
// Class Engine.MovementComponent
// 0x0040 (0x0168 - 0x0128)
class UMovementComponent : public UActorComponent
{
public:
class USceneComponent*                             UpdatedComponent                                          // 0x0128(0x0008)
class UPrimitiveComponent*                         UpdatedPrimitive                                          // 0x0130(0x0008)
struct FVector                                     Velocity                                                  // 0x013C(0x000C)
struct FVector                                     PlaneConstraintNormal                                     // 0x0148(0x000C)
struct FVector                                     PlaneConstraintOrigin                                     // 0x0154(0x000C)
Bool                                               bUpdateOnlyIfRendered                                     // 0x0160(0x0001)
Bool                                               bAutoUpdateTickRegistration                               // 0x0160(0x0001)
Bool                                               bTickBeforeOwner                                          // 0x0160(0x0001)
Bool                                               bAutoRegisterUpdatedComponent                             // 0x0160(0x0001)
Bool                                               bConstrainToPlane                                         // 0x0160(0x0001)
Bool                                               bSnapToPlaneAtStart                                       // 0x0160(0x0001)
Bool                                               bAutoRegisterPhysicsVolumeUpdates                         // 0x0160(0x0001)
Bool                                               bComponentShouldUpdatePhysicsVolume                       // 0x0160(0x0001)
EPlaneConstraintAxisSetting                        PlaneConstraintAxisSetting                                // 0x0163(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActivityFloatingActorMovement
// 0x0138 (0x02A0 - 0x0168)
class UActivityFloatingActorMovement : public UMovementComponent
{
public:
float                                              MaxSpeed                                                  // 0x0168(0x0004)
float                                              Acceleration                                              // 0x016C(0x0004)
float                                              Deceleration                                              // 0x0170(0x0004)
float                                              TurningBoost                                              // 0x0174(0x0004)
float                                              FloatingMoveSpeedScale                                    // 0x0178(0x0004)
float                                              RotatorSpeed                                              // 0x017C(0x0004)
float                                              MovementSmoothAlpha                                       // 0x0180(0x0004)
float                                              MovementSmoothEps                                         // 0x0184(0x0004)
Bool                                               bAllowSlide                                               // 0x0188(0x0001)
struct FVector                                     InputMin                                                  // 0x018C(0x000C)
struct FVector                                     InputMax                                                  // 0x0198(0x000C)
struct FRotator                                    RotateMin                                                 // 0x01A4(0x000C)
struct FRotator                                    RotateMax                                                 // 0x01B0(0x000C)
float                                              MaxPredictTime                                            // 0x01BC(0x0004)
float                                              PredictScale                                              // 0x01C0(0x0004)
float                                              LocationInterpolationCoefficient                          // 0x01C4(0x0004)
float                                              InterpolationAccScale                                     // 0x01C8(0x0004)
float                                              TeleportThreshold                                         // 0x01CC(0x0004)
float                                              RotationInterpolationCoefficient                          // 0x01D0(0x0004)
Bool                                               bDSTickOptimization                                       // 0x01D4(0x0001)
struct FMoveReplicatedData                         LastReplicatedData                                        // 0x01E0(0x0060)
float                                              CachedSpeed                                               // 0x0240(0x0004)
struct FScriptMulticastDelegate                    OnLerp                                                    // 0x0248(0x0010)
struct FScriptMulticastDelegate                    BeforeTick                                                // 0x0258(0x0010)
class AActor*                                      ActorOwner                                                // 0x0280(0x0008)
Bool                                               bPositionCorrected                                        // 0x0288(0x0001)
Bool                                               bUseForceTransform                                        // 0x028C(0x0001)
Bool                                               bHaveFixedTransform                                       // 0x028D(0x0001)
uint16_t                                           TempTeleportCount                                         // 0x028E(0x0002)
float                                              lastActiveTime                                            // 0x0290(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActivityNewYearRocketBase
// 0x0090 (0x0A50 - 0x09C0)
class AActivityNewYearRocketBase : public AActivityBaseActor
{
public:
struct FScriptMulticastDelegate                    OnRocketLaunch                                            // 0x09C0(0x0010)
struct FScriptMulticastDelegate                    OnRocketStop                                              // 0x09D0(0x0010)
struct FScriptMulticastDelegate                    OnCountdownStateChange                                    // 0x09E0(0x0010)
struct FScriptMulticastDelegate                    OnCountdownOver                                           // 0x09F0(0x0010)
Bool                                               bLaunchingRocket                                          // 0x0A00(0x0001)
Bool                                               bUseTheFlyRocket                                          // 0x0A01(0x0001)
struct FVector                                     LaunchingDir                                              // 0x0A04(0x000C)
class ALiftActor*                                  FlyRocket                                                 // 0x0A10(0x0008)
float                                              SyncCountdown                                             // 0x0A18(0x0004)
Bool                                               bStartCountdown                                           // 0x0A1C(0x0001)
float                                              LaunchCountdown                                           // 0x0A20(0x0004)
float                                              CountdownSyncInterval                                     // 0x0A24(0x0004)
Bool                                               bRepCountdown                                             // 0x0A28(0x0001)
float                                              HeightOfOutRocket                                         // 0x0A34(0x0004)
float                                              BlueCircleRadiusPercent                                   // 0x0A38(0x0004)
float                                              PlayerOffset                                              // 0x0A3C(0x0004)
TArray<class AActor*>                              CacheCharacters                                           // 0x0A40(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActivityRocket_Socket
// 0x0010 (0x09D0 - 0x09C0)
class AActivityRocket_Socket : public AActivityBaseActor
{
public:
class AActivityBaseActor*                          RelevantForRocket_C                                       // 0x09C0(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActivityScanTowerActor
// 0x0080 (0x0A40 - 0x09C0)
class AActivityScanTowerActor : public AActivityBaseActor
{
public:
TArray<class ASTExtraPlayerController*>            CachePCList                                               // 0x09C0(0x0010)
float                                              PlayerMarkLifeTime                                        // 0x0A20(0x0004)
struct FVector                                     MinVector                                                 // 0x0A24(0x000C)
struct FVector                                     MaxVector                                                 // 0x0A30(0x000C)
int                                                MaxPlayerMarkNum                                          // 0x0A3C(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActivitySpineActorMovement
// 0x0038 (0x0160 - 0x0128)
class UActivitySpineActorMovement : public UActorComponent
{
public:
float                                              fMoveTime                                                 // 0x0128(0x0004)
class USplineComponent*                            Spline                                                    // 0x0130(0x0008)
class USceneComponent*                             MoveObj                                                   // 0x0138(0x0008)
};

// 大佬QQ:2396031563
// Class Engine.SceneComponent
// 0x01D8 (0x0300 - 0x0128)
class USceneComponent : public UActorComponent
{
public:
struct FScriptMulticastDelegate                    PhysicsVolumeChangedDelegate                              // 0x0130(0x0010)
struct FScriptMulticastDelegate                    TransformUpdatedDynamic                                   // 0x0140(0x0010)
TWeakObjectPtr<class APhysicsVolume>               PhysicsVolume                                             // 0x0150(0x0008)
class USceneComponent*                             AttachParent                                              // 0x0158(0x0008)
struct FName                                       AttachSocketName                                          // 0x0160(0x0008)
TArray<class USceneComponent*>                     AttachChildren                                            // 0x0168(0x0010)
TArray<class USceneComponent*>                     ClientAttachedChildren                                    // 0x0178(0x0010)
struct FVector                                     RelativeLocation                                          // 0x01C4(0x000C)
struct FRotator                                    RelativeRotation                                          // 0x01D0(0x000C)
struct FVector                                     RelativeScale3D                                           // 0x01DC(0x000C)
struct FTransform                                  ComponentToWorld                                          // 0x01F0(0x0030)
struct FVector                                     ComponentVelocity                                         // 0x0250(0x000C)
Bool                                               bComponentToWorldUpdated                                  // 0x025C(0x0001)
Bool                                               bAbsoluteLocation                                         // 0x025C(0x0001)
Bool                                               bAbsoluteRotation                                         // 0x025C(0x0001)
Bool                                               bAbsoluteScale                                            // 0x025C(0x0001)
Bool                                               bVisible                                                  // 0x025C(0x0001)
Bool                                               bHiddenInGame                                             // 0x025C(0x0001)
Bool                                               bShouldUpdatePhysicsVolume                                // 0x025C(0x0001)
Bool                                               bBoundsChangeTriggersStreamingDataRebuild                 // 0x025D(0x0001)
Bool                                               bUseAttachParentBound                                     // 0x025D(0x0001)
Bool                                               bShouldUpdateOverLaps                                     // 0x025D(0x0001)
Bool                                               bForceUpdateChildCompTransform                            // 0x025D(0x0001)
Bool                                               bEnableUpdateTransformOption                              // 0x025D(0x0001)
Bool                                               bUpdateTransformOptionConsiderAbsolute                    // 0x025D(0x0001)
Bool                                               bOpenServerOptLite                                        // 0x025D(0x0001)
Bool                                               bShouldUseTeleportMove                                    // 0x025E(0x0001)
Bool                                               bForceFrameInterpolate                                    // 0x025E(0x0001)
Bool                                               bEnableParallelMove                                       // 0x025E(0x0001)
unsigned char                                      Mobility                                                  // 0x025F(0x0001)
unsigned char                                      DetailMode                                                // 0x0260(0x0001)
EUpdateTransformOption                             UpdateTransformOption                                     // 0x02F0(0x0001)
Bool                                               bIsFppLayerRecursive                                      // 0x02F1(0x0001)
Bool                                               bDisableFppLayerRecursive                                 // 0x02F1(0x0001)
};

// 大佬QQ:2396031563
// Class Engine.SpringArmComponent
// 0x0140 (0x0440 - 0x0300)
class USpringArmComponent : public USceneComponent
{
public:
float                                              TargetArmLength                                           // 0x02F8(0x0004)
struct FVector                                     SocketOffset                                              // 0x02FC(0x000C)
struct FVector                                     TargetOffset                                              // 0x0308(0x000C)
float                                              ProbeSize                                                 // 0x0314(0x0004)
unsigned char                                      ProbeChannel                                              // 0x0318(0x0001)
Bool                                               bDoCollisionTest                                          // 0x031C(0x0001)
Bool                                               bUsePawnControlRotation                                   // 0x031C(0x0001)
Bool                                               bInheritPitch                                             // 0x031C(0x0001)
Bool                                               bInheritYaw                                               // 0x031C(0x0001)
Bool                                               bInheritRoll                                              // 0x031C(0x0001)
Bool                                               bEnableCameraLag                                          // 0x031C(0x0001)
Bool                                               bEnableCameraRotationLag                                  // 0x031C(0x0001)
Bool                                               bUseCameraLagSubstepping                                  // 0x031C(0x0001)
Bool                                               bDrawDebugLagMarkers                                      // 0x031D(0x0001)
float                                              CameraLagSpeed                                            // 0x0320(0x0004)
float                                              CameraRotationLagSpeed                                    // 0x0324(0x0004)
float                                              CameraLagMaxTimeStep                                      // 0x0328(0x0004)
float                                              CameraLagMaxDistance                                      // 0x032C(0x0004)
TArray<class AActor*>                              IgnoredActors                                             // 0x03A8(0x0010)
struct FHitResult                                  CacheHit                                                  // 0x03B8(0x0088)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActivitySpringArmComponent
// 0x00B0 (0x04F0 - 0x0440)
class UActivitySpringArmComponent : public USpringArmComponent
{
public:
Bool                                               bDefaultsView                                             // 0x0440(0x0001)
struct FRotator                                    DefaultViewRotation                                       // 0x0444(0x000C)
Bool                                               VerticalScreenMode                                        // 0x0450(0x0001)
Bool                                               bViewTargetIsAnActor                                      // 0x0451(0x0001)
Bool                                               bRotationLimitSetLimitRotateDirectly                      // 0x0452(0x0001)
Bool                                               UseRotationLimit                                          // 0x0453(0x0001)
Bool                                               bRotationLimitIsRelativeOwnerComp                         // 0x0454(0x0001)
Bool                                               bUseParentRotator                                         // 0x0455(0x0001)
Bool                                               bUsePossessActorForViewSync                               // 0x0456(0x0001)
float                                              YawMin                                                    // 0x0458(0x0004)
float                                              YawMax                                                    // 0x045C(0x0004)
float                                              PitchMin                                                  // 0x0460(0x0004)
float                                              PitchMax                                                  // 0x0464(0x0004)
class APlayerController*                           CachedPC                                                  // 0x0468(0x0008)
struct FScriptMulticastDelegate                    OnControlRotationChangedDelegate                          // 0x0470(0x0010)
Bool                                               bShouldBackRotation                                       // 0x0480(0x0001)
float                                              SmartCameraRotSpeed                                       // 0x0484(0x0004)
float                                              DefaultCameraStayTimer                                    // 0x0488(0x0004)
struct FVehicleSimViewData                         SimulateViewData                                          // 0x048C(0x0004)
Bool                                               bSmartCamAutoReturnEnabled                                // 0x0498(0x0001)
struct FRotator                                    CachedRotation                                            // 0x04B8(0x000C)
TArray<class AActor*>                              CachedIgonreActor                                         // 0x04C8(0x0010)
TArray<class UPrimitiveComponent*>                 CachedIgonrePrimitiveComponent                            // 0x04D8(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActivityUIComponent
// 0x0128 (0x0250 - 0x0128)
class UActivityUIComponent : public UActorComponent
{
public:
struct FScriptMulticastDelegate                    OnActivityUIShow                                          // 0x0128(0x0010)
struct FScriptMulticastDelegate                    OnActivityUIHiden                                         // 0x0138(0x0010)
Bool                                               bUseMinMap                                                // 0x0148(0x0001)
struct FMarkSyncData                               TempAlertData                                             // 0x0150(0x0070)
TMap<int, struct FActivityUIConfig>                PossessUIs                                                // 0x01C0(0x0050)
class UUserWidgetStyle*                            UserWidgetStyle                                           // 0x0210(0x0008)
TArray<class UUserWidgetStyle*>                    ExtraUserWidgetStyles                                     // 0x0218(0x0010)
TArray<struct FActivityUIPlayerInfo>               PlayerInfo                                                // 0x0238(0x0010)
Bool                                               bClientPerLoadUIClass                                     // 0x0248(0x0001)
};

// 大佬QQ:2396031563
// Class UMG.Widget
// 0x0158 (0x0180 - 0x0028)
class UWidget : public UVisual
{
public:
class UPanelSlot*                                  Slot                                                      // 0x0028(0x0008)
class UPanelWidget*                                CachedPanel_ForGC                                         // 0x0030(0x0008)
struct FScriptDelegate                             bIsEnabledDelegate                                        // 0x0038(0x0010)
struct FText                                       ToolTipText                                               // 0x0048(0x0018)
struct FScriptDelegate                             ToolTipTextDelegate                                       // 0x0060(0x0010)
class UWidget*                                     ToolTipWidget                                             // 0x0070(0x0008)
struct FScriptDelegate                             ToolTipWidgetDelegate                                     // 0x0078(0x0010)
struct FScriptDelegate                             VisibilityDelegate                                        // 0x0088(0x0010)
Bool                                               IgnorePixelSnapping                                       // 0x0098(0x0001)
struct FScriptDelegate                             IgnorePixelSnappingDelegate                               // 0x00A0(0x0010)
struct FName                                       RelatedStyleWidgetName                                    // 0x00B0(0x0008)
TWeakObjectPtr<class UWidget>                      RelatedStyleWidget                                        // 0x00B8(0x0008)
struct FWidgetTransform                            RenderTransform                                           // 0x00C0(0x001C)
struct FVector2D                                   RenderTransformPivot                                      // 0x00DC(0x0008)
Bool                                               bIsVariable                                               // 0x00E4(0x0001)
Bool                                               bCreatedByConstructionScript                              // 0x00E4(0x0001)
Bool                                               bIsEnabled                                                // 0x00E4(0x0001)
Bool                                               bOverride_Cursor                                          // 0x00E4(0x0001)
Bool                                               bIsVolatile                                               // 0x00E4(0x0001)
Bool                                               bWriteSceneZBuffer                                        // 0x00E4(0x0001)
unsigned char                                      UsedLayerPolicy                                           // 0x00E5(0x0001)
unsigned char                                      PreservedLayerNum                                         // 0x00E6(0x0001)
unsigned char                                      FixedLayerPolicy                                          // 0x00E7(0x0001)
unsigned char                                      FixedLayerNum                                             // 0x00E8(0x0001)
Bool                                               IngoreRectMove                                            // 0x00E9(0x0001)
Bool                                               CareRectMove                                              // 0x00E9(0x0001)
unsigned char                                      Cursor                                                    // 0x00EA(0x0001)
EWidgetClipping                                    Clipping                                                  // 0x00EB(0x0001)
ESlateVisibility                                   Visibility                                                // 0x00EC(0x0001)
float                                              RenderOpacity                                             // 0x00F0(0x0004)
class UWidgetNavigation*                           Navigation                                                // 0x00F8(0x0008)
Bool                                               bCatchVisibilityChangedEvent                              // 0x0100(0x0001)
TArray<class UPropertyBinding*>                    NativeBindings                                            // 0x0130(0x0010)
struct FScriptMulticastDelegate                    OnWidgetVisibilityChanged                                 // 0x0148(0x0010)
struct FScriptMulticastDelegate                    OnWidgetSlateVisibilityChanged                            // 0x0158(0x0010)
struct FScriptMulticastDelegate                    OnWidgetIsEnabledSet                                      // 0x0168(0x0010)
int                                                AreaTypeFlags                                             // 0x0178(0x0004)
int                                                ZValue                                                    // 0x017C(0x0004)
};

// 大佬QQ:2396031563
// Class UMG.UserWidget
// 0x0130 (0x02B0 - 0x0180)
class UUserWidget : public UWidget
{
public:
struct FLinearColor                                ColorAndOpacity                                           // 0x0188(0x0010)
struct FScriptDelegate                             ColorAndOpacityDelegate                                   // 0x0198(0x0010)
struct FSlateColor                                 ForegroundColor                                           // 0x01A8(0x0028)
struct FScriptDelegate                             ForegroundColorDelegate                                   // 0x01D0(0x0010)
struct FMargin                                     Padding                                                   // 0x01E0(0x0010)
TArray<class UUMGSequencePlayer*>                  ActiveSequencePlayers                                     // 0x01F0(0x0010)
TArray<class UUMGSequencePlayer*>                  StoppedSequencePlayers                                    // 0x0200(0x0010)
TArray<struct FNamedSlotBinding>                   NamedSlotBindings                                         // 0x0210(0x0010)
class UWidgetTree*                                 WidgetTree                                                // 0x0220(0x0008)
Bool                                               bOptimiseAnimation                                        // 0x0228(0x0001)
Bool                                               bNoBubbleUpEvent                                          // 0x0229(0x0001)
int                                                Priority                                                  // 0x022C(0x0004)
Bool                                               bSupportsKeyboardFocus                                    // 0x0230(0x0001)
Bool                                               bIsFocusable                                              // 0x0230(0x0001)
Bool                                               bStopAction                                               // 0x0230(0x0001)
Bool                                               CanDisableDrag                                            // 0x0230(0x0001)
Bool                                               bCanEverTick                                              // 0x0230(0x0001)
Bool                                               bCanEverPaint                                             // 0x0230(0x0001)
Bool                                               bCookedWidgetTree                                         // 0x0231(0x0001)
class UObject*                                     WidgetSkinProxy                                           // 0x0238(0x0008)
class UInputComponent*                             InputComponent                                            // 0x0240(0x0008)
TArray<struct FAnimationEventBinding>              AnimationCallbacks                                        // 0x0248(0x0010)
};

// 大佬QQ:2396031563
// Class UnrealArchExt.UAEUserWidget
// 0x0558 (0x0808 - 0x02B0)
class UUAEUserWidget : public UUserWidget
{
public:
struct FScriptMulticastDelegate                    NotifyDestroyModel                                        // 0x02B0(0x0010)
class UFrontendHUD*                                OwningFrontendHUD                                         // 0x02C0(0x0008)
TArray<class UUAEUserWidget*>                      PopCallbackChildren                                       // 0x02C8(0x0010)
TArray<class UUAEUserWidget*>                      DestroyCallbackChildren                                   // 0x02D8(0x0010)
class ULogicManagerBase*                           OwningLogicManager                                        // 0x02E8(0x0008)
class UUAEWidgetContainer*                         OwningWidgetContainer                                     // 0x02F0(0x0008)
class UUAEUserWidget*                              ParentWidget                                              // 0x02F8(0x0008)
TArray<class UProperty*>                           Params                                                    // 0x03A8(0x0010)
struct FName                                       IndexName                                                 // 0x03C8(0x0008)
struct FUserWidgetState                            DefaultUserWidgetState                                    // 0x03D0(0x0028)
Bool                                               ForceDynamicInit                                          // 0x03F8(0x0001)
int                                                PCWidgetIndex                                             // 0x03FC(0x0004)
struct FScriptMulticastDelegate                    UAEWidgetVisibilityChanged                                // 0x0400(0x0010)
struct FScriptMulticastDelegate                    UAEWidgetDestructDelegate                                 // 0x0410(0x0010)
Bool                                               bBlockInputOnShow                                         // 0x0420(0x0001)
unsigned char                                      InputWhiteListWhenBlocked                                 // 0x0428(0x0050)
TArray<struct FPCWidgetConfig>                     PCWidgetConfigs                                           // 0x0478(0x0010)
TArray<struct FUAEUserWidgetActionInfo>            ActionInfos                                               // 0x0488(0x0010)
TArray<struct FUAEUserWidgetAxisInfo>              AxisInfos                                                 // 0x0498(0x0010)
TArray<class UWidget*>                             MountedHintUIs                                            // 0x04A8(0x0010)
float                                              LuaMessengerFloat                                         // 0x04B8(0x0004)
struct FUserWidgetState                            CurrentUserWidgetState                                    // 0x04D0(0x0028)
Bool                                               bLimitTickRate                                            // 0x04F8(0x0001)
float                                              TickRate                                                  // 0x04FC(0x0004)
Bool                                               bReceiveOnClickedEvent                                    // 0x0500(0x0001)
Bool                                               bReceiveOnRightClickedEvent                               // 0x0501(0x0001)
Bool                                               bReceiveOnDoubleClickedEvent                              // 0x0502(0x0001)
Bool                                               bAutoSetScreenPosOnMouseEnter                             // 0x0503(0x0001)
Bool                                               bConsiderPawnStateChange                                  // 0x0504(0x0001)
Bool                                               needCache                                                 // 0x0505(0x0001)
struct FVector2D                                   ScreenPos                                                 // 0x0510(0x0008)
struct FVector2D                                   LastMouseEventScreenPos                                   // 0x0518(0x0008)
struct FScriptDelegate                             OnMouseButtonDownHandler                                  // 0x0520(0x0010)
struct FScriptDelegate                             OnMouseButtonUpHandler                                    // 0x0530(0x0010)
struct FString                                     WidgetTlogName                                            // 0x0540(0x0010)
Bool                                               bEnableDestroyStrategy                                    // 0x0550(0x0001)
Bool                                               bApplyDestroyStrategyLowDeviceOnly                        // 0x0551(0x0001)
float                                              CheckDestroyTime                                          // 0x0554(0x0004)
Bool                                               bNeedDestroyWhenDestruct                                  // 0x0558(0x0001)
Bool                                               bNeedsShowMouseCursor                                     // 0x0559(0x0001)
int                                                PCCustomMouseEventLayer                                   // 0x055C(0x0004)
struct FScriptDelegate                             PCCustom_OnMouseButtonDownEvent                           // 0x0560(0x0010)
struct FScriptDelegate                             PCCustom_OnMouseButtonUpEvent                             // 0x0570(0x0010)
struct FScriptDelegate                             PCCustom_OnTouchStartedEvent                              // 0x0580(0x0010)
struct FScriptDelegate                             PCCustom_OnTouchMovedEvent                                // 0x0590(0x0010)
struct FScriptDelegate                             PCCustom_OnTouchEndedEvent                                // 0x05A0(0x0010)
struct FScriptDelegate                             PCCustom_OnMouseEnterEvent                                // 0x05B0(0x0010)
struct FScriptDelegate                             PCCustom_OnMouseLeaveEvent                                // 0x05C0(0x0010)
struct FScriptDelegate                             PCCustom_OnDragEnterEvent                                 // 0x05D0(0x0010)
struct FScriptDelegate                             PCCustom_OnDragLeaveEvent                                 // 0x05E0(0x0010)
struct FScriptDelegate                             PCCustom_OnDropEvent                                      // 0x05F0(0x0010)
unsigned char                                      IgnoreKeys_PCCustom_OnTouchStarted                        // 0x0600(0x0050)
Bool                                               bUseCustomDPIScaleCurve                                   // 0x0650(0x0001)
int                                                FixedCustomDPICurveIndex                                  // 0x0654(0x0004)
Bool                                               bApplyCustomDPIScaleCurve                                 // 0x0658(0x0001)
int                                                LastFixedDPICurveIndex                                    // 0x065C(0x0004)
Bool                                               IsMobileTipsUI                                            // 0x0660(0x0001)
EUserWidgetFadingStatus                            FadingStatus                                              // 0x0679(0x0001)
float                                              CurrentOpacity                                            // 0x067C(0x0004)
float                                              FadingInTime                                              // 0x0680(0x0004)
float                                              FadingOutTime                                             // 0x0684(0x0004)
Bool                                               bNoFadeIn                                                 // 0x0688(0x0001)
Bool                                               bNoFadeOut                                                // 0x0689(0x0001)
Bool                                               bShouldCollapse                                           // 0x068A(0x0001)
int                                                StandWidth                                                // 0x068C(0x0004)
int                                                StandHeight                                               // 0x0690(0x0004)
Bool                                               bReceiveOnTouchBeganEvent                                 // 0x0694(0x0001)
Bool                                               bReceiveOnTouchEndedEvent                                 // 0x0695(0x0001)
Bool                                               bLogicVis                                                 // 0x0697(0x0001)
Bool                                               bPawnStateVis                                             // 0x0698(0x0001)
int                                                ChildSkinMatchingKey                                      // 0x069C(0x0004)
class UClass*                                      DefaultSkin                                               // 0x06A0(0x0008)
Bool                                               bFlushLoadSkin                                            // 0x06A8(0x0001)
Bool                                               bHideBeforeLoadSkin                                       // 0x06A9(0x0001)
TMap<int, unsigned char>                           ModeSkinConfig                                            // 0x06B0(0x0050)
TMap<struct FString, unsigned char>                ModeUISkinConfig                                          // 0x0700(0x0050)
unsigned char                                      ForceSkipRevertSkins                                      // 0x0750(0x0050)
struct FScriptMulticastDelegate                    OnApplyWidgetSkinFinished                                 // 0x07A0(0x0010)
struct FScriptMulticastDelegate                    OnRevertWidgetSkinFinished                                // 0x07B0(0x0010)
TArray<class UUserWidgetSkin*>                     ActiveSkins                                               // 0x07D0(0x0010)
TWeakObjectPtr<class UObject>                      AssociatedDataObject                                      // 0x0800(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActivityUIWidget
// 0x0010 (0x0818 - 0x0808)
class UActivityUIWidget : public UUAEUserWidget
{
public:
Bool                                               bShowInPCVer                                              // 0x0808(0x0001)
Bool                                               bShowInPrecise                                            // 0x0809(0x0001)
TWeakObjectPtr<class UObject>                      OwingActor                                                // 0x080C(0x0008)
int                                                UIIndex                                                   // 0x0814(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActivityWormholeActor
// 0x0110 (0x0AD0 - 0x09C0)
class AActivityWormholeActor : public AActivityBaseActor
{
public:
float                                              EndLifeSpan                                               // 0x09C0(0x0004)
float                                              WormholeBoxLocRadio                                       // 0x09C4(0x0004)
TMap<struct FName, struct FWormholeStateConfig>    WormholeStateConfig                                       // 0x09C8(0x0050)
float                                              CanOpenParachuteHeight                                    // 0x0A18(0x0004)
float                                              ForceOpenParachuteHeight                                  // 0x0A1C(0x0004)
float                                              CloseParachuteHeight                                      // 0x0A20(0x0004)
int                                                CurrentStateIndex                                         // 0x0A38(0x0004)
float                                              CurrentStateTime                                          // 0x0A3C(0x0004)
float                                              CurrentTime                                               // 0x0A40(0x0004)
float                                              CurrentTotalTime                                          // 0x0A44(0x0004)
float                                              FreeFlyJoystickSensitivity                                // 0x0A64(0x0004)
float                                              FreeFlyForwardMaxSpeed                                    // 0x0A68(0x0004)
float                                              FreeFlySideMaxSpeed                                       // 0x0A6C(0x0004)
TArray<EPawnState>                                 DisableStateList                                          // 0x0A70(0x0010)
TArray<class ASTExtraPlayerCharacter*>             WormholePlayerList                                        // 0x0A80(0x0010)
Bool                                               bWormholeFlyingStart                                      // 0x0A90(0x0001)
float                                              FlyEndLocationPlayerOffset                                // 0x0A94(0x0004)
float                                              WormholeEndLocRadio                                       // 0x0A98(0x0004)
float                                              WormholeEndLocZOffset                                     // 0x0A9C(0x0004)
float                                              ParachuteJumpRadius                                       // 0x0AA0(0x0004)
float                                              ParachuteJumpPlayerOffset                                 // 0x0AA4(0x0004)
float                                              ParachuteJumpOffsetZ                                      // 0x0AA8(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorAttachUIComp
// 0x0088 (0x01B0 - 0x0128)
class UActorAttachUIComp : public UActorComponent
{
public:
unsigned char                                      UIClass                                                   // 0x0168(0x0028)
Bool                                               BShowMiniMapUI                                            // 0x0190(0x0001)
int                                                MiniMapUIIcon                                             // 0x0194(0x0004)
EMarkDispatchRange                                 RangeType                                                 // 0x0198(0x0001)
float                                              SquredDistanceOfSwitchingVisibility                       // 0x019C(0x0004)
class UActorPositionWidget*                        PositionWidget                                            // 0x01A0(0x0008)
int                                                AlertID                                                   // 0x01A8(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorCacheMgr
// 0x0050 (0x0620 - 0x05D0)
class AActorCacheMgr : public AActor
{
public:
TMap<class UClass*, class UActorCachePool*>        DataMap                                                   // 0x05C8(0x0050)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorFieldSystemComponent
// 0x00F0 (0x0218 - 0x0128)
class UActorFieldSystemComponent : public UActorComponent
{
public:
TArray<class UFieldLogicNodeBase*>                 FieldLogicNodes                                           // 0x0128(0x0010)
struct FActorComponentSelector                     OverlapComponentSelector                                  // 0x0138(0x0008)
class UPrimitiveComponent*                         OverlapComponentCache                                     // 0x0140(0x0008)
Bool                                               bOverlapIgnoreMyOwner                                     // 0x0148(0x0001)
Bool                                               bOpenAIWorldVolumeCheckOverlapActor                       // 0x0149(0x0001)
float                                              AIWorldVolumeCheckOverlapActorTickTime                    // 0x014C(0x0004)
struct FTimerHandle                                AIWorldVolumeCheckOverlapActorTimerHandle                 // 0x0150(0x0008)
Bool                                               bEnabled                                                  // 0x0158(0x0001)
TArray<ESTECharacterType>                          CharacterTypeList                                         // 0x0160(0x0010)
uint32_t                                           CharacterTypesFlag                                        // 0x0170(0x0004)
TArray<struct FName>                               ExcludeActorTags                                          // 0x0178(0x0010)
TArray<TWeakObjectPtr<class AActor>>               AIWorldVolumeOverlapActors                                // 0x01D8(0x0010)
TArray<struct FFieldLogicOverlapActor>             OverlapCharacters                                         // 0x01E8(0x0010)
TArray<struct FFieldLogicOverlapActor>             OverlapPhysicsActors                                      // 0x01F8(0x0010)
TArray<struct FFieldLogicOverlapActor>             OverlapCommonActors                                       // 0x0208(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorFilter
// 0x0008 (0x0030 - 0x0028)
class UActorFilter : public UObject
{
public:
EActorFilterType                                   FilterType                                                // 0x0028(0x0001)
Bool                                               bInvertFilter                                             // 0x0029(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorFilter_ActorClass
// 0x0018 (0x0048 - 0x0030)
class UActorFilter_ActorClass : public UActorFilter
{
public:
Bool                                               bExplicitClass                                            // 0x0030(0x0001)
TArray<unsigned char>                              IncludedActorClasses                                      // 0x0038(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorFilter_ExcludeActorClass
// 0x0010 (0x0058 - 0x0048)
class UActorFilter_ExcludeActorClass : public UActorFilter_ActorClass
{
public:
TArray<unsigned char>                              ExcludedActorClasses                                      // 0x0048(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorFilter_ActorHasTag
// 0x0008 (0x0038 - 0x0030)
class UActorFilter_ActorHasTag : public UActorFilter
{
public:
struct FName                                       Tag                                                       // 0x0030(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorFilter_RemoveSameCamp
// 0x0008 (0x0038 - 0x0030)
class UActorFilter_RemoveSameCamp : public UActorFilter
{
public:
Bool                                               bRemoveSelf                                               // 0x0030(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorFilter_And
// 0x0010 (0x0040 - 0x0030)
class UActorFilter_And : public UActorFilter
{
public:
TArray<class UActorFilter*>                        Filters                                                   // 0x0030(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorFilter_Or
// 0x0010 (0x0040 - 0x0030)
class UActorFilter_Or : public UActorFilter
{
public:
TArray<class UActorFilter*>                        Filters                                                   // 0x0030(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorFilter_XOR
// 0x0010 (0x0040 - 0x0030)
class UActorFilter_XOR : public UActorFilter
{
public:
TArray<class UActorFilter*>                        Filters                                                   // 0x0030(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorFilter_Cone
// 0x0010 (0x0040 - 0x0030)
class UActorFilter_Cone : public UActorFilter
{
public:
Bool                                               b2D                                                       // 0x0030(0x0001)
float                                              ConeAngle                                                 // 0x0034(0x0004)
float                                              ConeRadius                                                // 0x0038(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorFilter_InSight
// 0x0040 (0x0070 - 0x0030)
class UActorFilter_InSight : public UActorFilter
{
public:
float                                              InSightAngle                                              // 0x0030(0x0004)
struct FVisibilityParams                           VisibilityParamsInFilter                                  // 0x0038(0x0028)
Bool                                               bUseCameraEither                                          // 0x0060(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorFilter_ExcludeObjectType
// 0x0008 (0x0038 - 0x0030)
class UActorFilter_ExcludeObjectType : public UActorFilter
{
public:
unsigned char                                      ObjectType                                                // 0x0030(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorFilter_PawnHasState
// 0x0018 (0x0048 - 0x0030)
class UActorFilter_PawnHasState : public UActorFilter
{
public:
TArray<EPawnState>                                 PawnState                                                 // 0x0030(0x0010)
uint64_t                                           MaskPrivate                                               // 0x0040(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorFilter_RemovePawnHasState
// 0x0010 (0x0058 - 0x0048)
class UActorFilter_RemovePawnHasState : public UActorFilter_PawnHasState
{
public:
TArray<EPawnState>                                 RemovePawnState                                           // 0x0048(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorFilter_InnerRange
// 0x0008 (0x0038 - 0x0030)
class UActorFilter_InnerRange : public UActorFilter
{
public:
float                                              InnerRangeDistance                                        // 0x0030(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorFilter_CountLimit
// 0x0020 (0x0050 - 0x0030)
class UActorFilter_CountLimit : public UActorFilter
{
public:
struct FCountLimitActorFilterParams                CountLimitParams                                          // 0x0030(0x0020)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorFilter_RemoveTeammate
// 0x0008 (0x0038 - 0x0030)
class UActorFilter_RemoveTeammate : public UActorFilter
{
public:
Bool                                               SkipModeAndSwitchCheck                                    // 0x0030(0x0001)
Bool                                               bRemoveSelf                                               // 0x0030(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorFilter_RemoveTeammateAnyway
// 0x0008 (0x0038 - 0x0030)
class UActorFilter_RemoveTeammateAnyway : public UActorFilter
{
public:
Bool                                               bRemoveSelf                                               // 0x0030(0x0001)
Bool                                               bUseOwner                                                 // 0x0030(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorFilter_Visibility
// 0x0038 (0x0068 - 0x0030)
class UActorFilter_Visibility : public UActorFilter
{
public:
TArray<unsigned char>                              IgnoreActorClasses                                        // 0x0030(0x0010)
Bool                                               bTraceEyes                                                // 0x0040(0x0001)
Bool                                               bTraceChannel                                             // 0x0040(0x0001)
unsigned char                                      BlockChannel                                              // 0x0041(0x0001)
TArray<unsigned char>                              BlockObjectTypes                                          // 0x0048(0x0010)
struct FIntPoint                                   MultiTestGrid                                             // 0x0058(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorMarkComponent
// 0x02A8 (0x03D0 - 0x0128)
class UActorMarkComponent : public UActorComponent
{
public:
Bool                                               bObjectPoolEnabled                                        // 0x0168(0x0001)
Bool                                               bMarkFromDS                                               // 0x0169(0x0001)
int                                                MarkTemplateID                                            // 0x016C(0x0004)
EMarkDispatchRange                                 SyncRange                                                 // 0x0170(0x0001)
Bool                                               bCreateMarkFromBeginPlay                                  // 0x0171(0x0001)
Bool                                               bTickable                                                 // 0x0172(0x0001)
Bool                                               bTickUpdateLocation                                       // 0x0173(0x0001)
Bool                                               bTickUpdateRotation                                       // 0x0174(0x0001)
float                                              UpdateLocationIntervalSec                                 // 0x0178(0x0004)
Bool                                               bEnablePlayerStateControl                                 // 0x017C(0x0001)
Bool                                               bUseDefaultCustomEvent                                    // 0x017D(0x0001)
float                                              DefaultCustomEventCreateTime                              // 0x0180(0x0004)
int                                                DefaultCustomEventCustomState                             // 0x0184(0x0004)
struct FString                                     DefaultCustomEventCustomString                            // 0x0188(0x0010)
EAddMarkFlag                                       DefaultCustomEventInWhichMap                              // 0x0198(0x0001)
TArray<EPawnState>                                 PawnStatesForNotification                                 // 0x01A0(0x0010)
TArray<EPawnState>                                 PawnStatesForHidden                                       // 0x01B0(0x0010)
int                                                MapMarkInstanceID                                         // 0x01C0(0x0004)
struct FScriptMulticastDelegate                    OnCreateMapMark                                           // 0x01C8(0x0010)
int                                                SceneMarkInstanceID                                       // 0x01D8(0x0004)
Bool                                               bCreateSceneMarkFromBeginPlay                             // 0x01DC(0x0001)
struct FObjectPosUIInfo                            SceneMarkInfo                                             // 0x01E0(0x01B0)
struct FTimerHandle                                SceneMarkTimerHandle                                      // 0x0390(0x0008)
TWeakObjectPtr<class ASTExtraPlayerState>          OwnerPlayerStateRef                                       // 0x0398(0x0008)
struct FCustomMarkEventData                        CustomEventData                                           // 0x03A8(0x0020)
Bool                                               bRegisterReplayEvents                                     // 0x03C9(0x0001)
int                                                TeamID                                                    // 0x03CC(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorPerspectiveVisComp
// 0x0018 (0x0140 - 0x0128)
class UActorPerspectiveVisComp : public UActorComponent
{
public:
Bool                                               bSetOwnerActorHiddenInTPP                                 // 0x0128(0x0001)
Bool                                               bSetOwnerActorHiddenInFPP                                 // 0x0129(0x0001)
Bool                                               bSetOwnerActorHiddenInNewFPP                              // 0x012A(0x0001)
Bool                                               bSetOwnerRealyHide                                        // 0x012B(0x0001)
class ASTExtraBaseCharacter*                       OwnerBSCharacter                                          // 0x0130(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorPositionWidget
// 0x0098 (0x08A0 - 0x0808)
class UActorPositionWidget : public UUAEUserWidget
{
public:
class UCanvasPanelSlot*                            MyCanvasPanelSlot                                         // 0x0808(0x0008)
class UTextBlock*                                  TextBlockDist                                             // 0x0810(0x0008)
class AActor*                                      AttachedActor                                             // 0x0818(0x0008)
struct FVector4                                    Limit                                                     // 0x0820(0x0010)
struct FVector2D                                   UIOffset                                                  // 0x0830(0x0008)
struct FVector                                     LocOffset                                                 // 0x0838(0x000C)
Bool                                               BNeedShowArrow                                            // 0x0844(0x0001)
float                                              AlphaBegin                                                // 0x0848(0x0004)
float                                              AlphaEnd                                                  // 0x084C(0x0004)
float                                              AlphaStep                                                 // 0x0850(0x0004)
float                                              AlphaBeginDistance                                        // 0x0854(0x0004)
float                                              AlphaEndDistance                                          // 0x0858(0x0004)
float                                              ScaleBegin                                                // 0x085C(0x0004)
float                                              ScaleEnd                                                  // 0x0860(0x0004)
float                                              ScaleStep                                                 // 0x0864(0x0004)
float                                              ScaleBeginDistance                                        // 0x0868(0x0004)
float                                              ScaleEndDistance                                          // 0x086C(0x0004)
float                                              MaxShowDistance                                           // 0x0870(0x0004)
int                                                TargetDistance                                            // 0x0874(0x0004)
class ASTExtraPlayerController*                    STExtraPlayerController                                   // 0x0888(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorStateBase
// 0x0030 (0x0058 - 0x0028)
class UActorStateBase : public UObject
{
public:
unsigned char                                      StateOwnerActor                                           // 0x0028(0x0028)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorStateMgr
// 0x00B0 (0x00D8 - 0x0028)
class UActorStateMgr : public UObject
{
public:
struct FScriptMulticastDelegate                    UActorStateEnter                                          // 0x0028(0x0010)
struct FScriptMulticastDelegate                    UActorStateLeave                                          // 0x0038(0x0010)
struct FScriptMulticastDelegate                    UActorStateTransfer                                       // 0x0048(0x0010)
TMap<int, class UActorStateBase*>                  StateMap                                                  // 0x0058(0x0050)
class UActorStateBase*                             CurrentState                                              // 0x00A8(0x0008)
unsigned char                                      StateOwner                                                // 0x00B0(0x0028)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.ActorTreeLinkComponent
// 0x0058 (0x0180 - 0x0128)
class UActorTreeLinkComponent : public UActorComponent
{
public:
int                                                ID                                                        // 0x0128(0x0004)
unsigned char                                      Links                                                     // 0x0130(0x0050)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.PickupAdditionalBackpackSource
// 0x0008 (0x0030 - 0x0028)
class UPickupAdditionalBackpackSource : public UObject
{
public:
Bool                                               bDroppedByPlayer                                          // 0x0028(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AdditionalBackpackComponent
// 0x00B8 (0x01E0 - 0x0128)
class UAdditionalBackpackComponent : public UActorComponent
{
public:
struct FTransform                                  WrapperPutDownTrans                                       // 0x0130(0x0030)
TArray<EPawnState>                                 CannotDropToWorldPawnStates                               // 0x0160(0x0010)
TArray<struct FGameplayTag>                        CannotDropToWorldDynamicPawnStates                        // 0x0170(0x0010)
class UClass*                                      HandleClass                                               // 0x0180(0x0008)
TArray<class UAdditionalBackpackHandleComponent*>  Handles                                                   // 0x0188(0x0010)
TArray<struct FPickUpItemData>                     Items                                                     // 0x0198(0x0010)
int                                                InstanceID                                                // 0x01A8(0x0004)
float                                              Capacity                                                  // 0x01AC(0x0004)
float                                              weight                                                    // 0x01B0(0x0004)
struct FName                                       TombBoxName                                               // 0x01B8(0x0008)
int                                                CannotAddTipsID                                           // 0x01C0(0x0004)
class ACharacter*                                  WarDog                                                    // 0x01C8(0x0008)
Bool                                               bAlreadyPickupFromBox                                     // 0x01D0(0x0001)
float                                              InteractDistance                                          // 0x01D4(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AdditionalBackpackHandleComponent
// 0x0028 (0x0150 - 0x0128)
class UAdditionalBackpackHandleComponent : public UActorComponent
{
public:
TArray<struct FPickUpItemData>                     Items                                                     // 0x0128(0x0010)
float                                              Capacity                                                  // 0x0138(0x0004)
class UAdditionalBackpackComponent*                AdditionalBackpack                                        // 0x0140(0x0008)
int                                                Distance                                                  // 0x0148(0x0004)
Bool                                               bEnable                                                   // 0x014C(0x0001)
};

// 大佬QQ:2396031563
// Class Skill.UTSkillWidget
// 0x0048 (0x0850 - 0x0808)
class UUTSkillWidget : public UUAEUserWidget
{
public:
Bool                                               bConsumeInput                                             // 0x0808(0x0001)
struct FString                                     SkillUIAttachPanelName                                    // 0x0810(0x0010)
class UUAEUserWidget*                              SkillUIRoot                                               // 0x0820(0x0008)
class UPanelWidget*                                SkillUIRootPanel                                          // 0x0828(0x0008)
Bool                                               bHideUnlessSkillActive                                    // 0x0830(0x0001)
class UUTSkillManagerComponent*                    SkillManager                                              // 0x0838(0x0008)
class UClass*                                      skillClass                                                // 0x0840(0x0008)
int                                                SkillUIID                                                 // 0x0848(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.UTSkillIconWidgetTemplate
// 0x0280 (0x0AD0 - 0x0850)
class UUTSkillIconWidgetTemplate : public UUTSkillWidget
{
public:
TMap<ESkillIconStatus, struct FIconStateParam>     SkillIconStateConfigs                                     // 0x0850(0x0050)
ECDType                                            CDType                                                    // 0x08A0(0x0001)
struct FString                                     cdTypeStr                                                 // 0x08A8(0x0010)
struct FString                                     ProgressMaterialParamName                                 // 0x08B8(0x0010)
float                                              pointMaxRate                                              // 0x08C8(0x0004)
struct FString                                     PointMaterialParamName                                    // 0x08D0(0x0010)
struct FString                                     slotName_OnRoot                                           // 0x08E0(0x0010)
unsigned char                                      FunctionBP                                                // 0x08F0(0x0028)
Bool                                               ReCallSkillStartOnConstruct                               // 0x0918(0x0001)
struct FName                                       FunctionBPParamName                                       // 0x0920(0x0008)
class UUTSkillIconWidgetTemplate_Func*             FunctionBPIns                                             // 0x0928(0x0008)
Bool                                               bFunctionBPInit                                           // 0x0930(0x0001)
float                                              UpdateDelta                                               // 0x0934(0x0004)
Bool                                               bRefreshNameText                                          // 0x0938(0x0001)
Bool                                               bRefreshCDTimerText                                       // 0x0939(0x0001)
Bool                                               bRefreshProgress                                          // 0x093A(0x0001)
Bool                                               bRefreshCDProcessAnticlockwise                            // 0x093B(0x0001)
Bool                                               bFlipCDRecovery                                           // 0x093C(0x0001)
Bool                                               bInverseCDByCastingStatsText                              // 0x093D(0x0001)
Bool                                               bUseCountTimeAsCDText                                     // 0x093E(0x0001)
Bool                                               HideProgressImageWhenSkillCDFinish                        // 0x093F(0x0001)
Bool                                               bChangeSkillStateWhenButtonRelease                        // 0x0940(0x0001)
struct FItemDefineID                               SkillBindedItemID                                         // 0x0948(0x0018)
int                                                SkillBindedItemCount                                      // 0x0960(0x0004)
int                                                EventTypeIndex                                            // 0x0964(0x0004)
unsigned char                                      DownEvent                                                 // 0x0968(0x0001)
unsigned char                                      UpEvent                                                   // 0x0969(0x0001)
unsigned char                                      ClickEvent                                                // 0x096A(0x0001)
unsigned char                                      HoveredEvent                                              // 0x096B(0x0001)
unsigned char                                      UnHoveredEvent                                            // 0x096C(0x0001)
struct FString                                     DownEventStr                                              // 0x0970(0x0010)
struct FString                                     UpEventStr                                                // 0x0980(0x0010)
struct FString                                     ClickEventStr                                             // 0x0990(0x0010)
struct FString                                     HoveredEventStr                                           // 0x09A0(0x0010)
struct FString                                     UnHoveredEventStr                                         // 0x09B0(0x0010)
struct FRefreshCDStateParam                        refreshParams                                             // 0x09C0(0x0048)
struct FScriptMulticastDelegate                    OnSkillReadyEvent                                         // 0x0A18(0x0010)
struct FScriptMulticastDelegate                    OnSkillNotReadyEvent                                      // 0x0A28(0x0010)
struct FScriptMulticastDelegate                    OnSkillTickCDEvent                                        // 0x0A38(0x0010)
struct FScriptMulticastDelegate                    OnSkillTickCDFinishEvent                                  // 0x0A48(0x0010)
struct FScriptMulticastDelegate                    OnSkillActiveEvent                                        // 0x0A58(0x0010)
struct FScriptMulticastDelegate                    OnSkillStopEvent                                          // 0x0A68(0x0010)
struct FScriptMulticastDelegate                    OnCDCastigRecovering                                      // 0x0A78(0x0010)
struct FScriptMulticastDelegate                    OnCDCastig                                                // 0x0A88(0x0010)
struct FScriptMulticastDelegate                    OnSetSkillActiveEvent                                     // 0x0A98(0x0010)
struct FScriptMulticastDelegate                    OnSetSkillDeactiveEvent                                   // 0x0AA8(0x0010)
int                                                TipsID                                                    // 0x0AB8(0x0004)
TArray<struct FName>                               ShowStageNames                                            // 0x0AC0(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AddonSkillUITemplate
// 0x0010 (0x0AE0 - 0x0AD0)
class UAddonSkillUITemplate : public UUTSkillIconWidgetTemplate
{
public:
class USPBAddonSkillUIDataAsset*                   AddonSkillUIData                                          // 0x0AD0(0x0008)
Bool                                               HasProgressBar                                            // 0x0AD8(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AdjacentPlayerFinderComponent
// 0x0048 (0x0170 - 0x0128)
class UAdjacentPlayerFinderComponent : public UActorComponent
{
public:
float                                              FinderRadius                                              // 0x0128(0x0004)
Bool                                               bFindByControllerOnServer                                 // 0x012C(0x0001)
struct FScriptMulticastDelegate                    OnPlayerEnter                                             // 0x0130(0x0010)
struct FScriptMulticastDelegate                    OnPlayerLeave                                             // 0x0140(0x0010)
struct FScriptMulticastDelegate                    OnPostHandleFoundPlayersChange                            // 0x0150(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AdvancedGoods
// 0x0030 (0x0600 - 0x05D0)
class AAdvancedGoods : public AActor
{
public:
Bool                                               bEnableLuaRepTest                                         // 0x05C8(0x0001)
float                                              TestRepInterval                                           // 0x05CC(0x0004)
int                                                TestRepArrrayCount                                        // 0x05D0(0x0004)
Bool                                               bNeedCheck                                                // 0x05D4(0x0001)
Bool                                               bStopChangeVal                                            // 0x05D5(0x0001)
Bool                                               bSubToEmpty                                               // 0x05D6(0x0001)
TArray<struct FTestActivityState>                  TestRepData                                               // 0x05E0(0x0010)
TArray<struct FTestActivityLink>                   TestRepDataPool                                           // 0x05F0(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.QuickSignMarkWidget
// 0x0108 (0x0910 - 0x0808)
class UQuickSignMarkWidget : public UUAEUserWidget
{
public:
Bool                                               IsSelfMark                                                // 0x0808(0x0001)
float                                              MaxAlpha                                                  // 0x080C(0x0004)
float                                              MinAlpha                                                  // 0x0810(0x0004)
struct FVector4                                    Limit                                                     // 0x0820(0x0010)
struct FVector4                                    Limit_PC                                                  // 0x0830(0x0010)
float                                              CornerRadius                                              // 0x0840(0x0004)
struct FVector2D                                   UIOffset                                                  // 0x0844(0x0008)
struct FVector4                                    ActiveCenterRect                                          // 0x0850(0x0010)
struct FString                                     DistAppendix                                              // 0x0860(0x0010)
class UCurveFloat*                                 Curve                                                     // 0x0870(0x0008)
Bool                                               IsInActiveCenter                                          // 0x0878(0x0001)
class UTextBlock*                                  TextBlock_Distance                                        // 0x0880(0x0008)
class UCanvasPanelSlot*                            SelfCanvasSlot                                            // 0x0888(0x0008)
class ASTExtraPlayerController*                    STExtraPlayerController                                   // 0x0890(0x0008)
int                                                ProfiledScreenValue                                       // 0x0898(0x0004)
Bool                                               IsUsingNewMarkStyle                                       // 0x089C(0x0001)
float                                              LongMarkLineHeight                                        // 0x08A0(0x0004)
float                                              ShortMarkLineHeight                                       // 0x08A4(0x0004)
float                                              DistanceThreshold                                         // 0x08A8(0x0004)
Bool                                               IsOutScreen                                               // 0x08AC(0x0001)
struct FVector2D                                   EdgeOffset_Top                                            // 0x08B0(0x0008)
struct FVector2D                                   EdgeOffset_Down                                           // 0x08B8(0x0008)
struct FVector2D                                   EdgeOffset_Left                                           // 0x08C0(0x0008)
struct FVector2D                                   EdgeOffset_Right                                          // 0x08C8(0x0008)
float                                              DistanceShowCoolDownTime                                  // 0x08D0(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AdvancedQuickSignMarkWidget
// 0x0080 (0x0990 - 0x0910)
class UAdvancedQuickSignMarkWidget : public UQuickSignMarkWidget
{
public:
Bool                                               bEnableTrans                                              // 0x0908(0x0001)
Bool                                               bCanTrans                                                 // 0x0909(0x0001)
struct FVector2D                                   TransInnerMargins                                         // 0x090C(0x0008)
struct FVector2D                                   TransOuterMagins                                          // 0x0914(0x0008)
class UWidgetAnimation*                            TransAnimation                                            // 0x0920(0x0008)
float                                              TransAnimStartTime                                        // 0x0928(0x0004)
float                                              TransAnimEndTime                                          // 0x092C(0x0004)
float                                              LastTransProgress                                         // 0x0930(0x0004)
class UImage*                                      Image_Line                                                // 0x0938(0x0008)
struct FVector2D                                   TopIconPosition                                           // 0x0940(0x0008)
struct FVector2D                                   BottomPointPosition                                       // 0x0948(0x0008)
float                                              LineHeightInLevel                                         // 0x0950(0x0004)
struct FVector4                                    TopIconLimitAdjust                                        // 0x0960(0x0010)
struct FVector4                                    BottomPointLimitAdjust                                    // 0x0970(0x0010)
Bool                                               bBottomPointOutScreen                                     // 0x0980(0x0001)
Bool                                               bTopIconOutScreen                                         // 0x0981(0x0001)
};

// 大佬QQ:2396031563
// Class UMG.PanelWidget
// 0x0028 (0x01A8 - 0x0180)
class UPanelWidget : public UWidget
{
public:
TArray<class UPanelSlot*>                          Slots                                                     // 0x0180(0x0010)
TArray<class UWidget*>                             CachedContents_ForGC                                      // 0x0190(0x0010)
};

// 大佬QQ:2396031563
// Class Engine.NavMovementComponent
// 0x0040 (0x01A8 - 0x0168)
class UNavMovementComponent : public UMovementComponent
{
public:
struct FNavAgentProperties                         NavAgentProps                                             // 0x0168(0x0028)
float                                              FixedPathBrakingDistance                                  // 0x0190(0x0004)
Bool                                               bUpdateNavAgentWithOwnersCollision                        // 0x0194(0x0001)
Bool                                               bUseAccelerationForPaths                                  // 0x0194(0x0001)
Bool                                               bUseFixedBrakingDistanceForPaths                          // 0x0194(0x0001)
struct FMovementProperties                         MovementState                                             // 0x0198(0x0004)
};

// 大佬QQ:2396031563
// Class Engine.PawnMovementComponent
// 0x0008 (0x01B0 - 0x01A8)
class UPawnMovementComponent : public UNavMovementComponent
{
public:
class APawn*                                       PawnOwner                                                 // 0x01A8(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AerofoilMovementComponent
// 0x0630 (0x07E0 - 0x01B0)
class UAerofoilMovementComponent : public UPawnMovementComponent
{
public:
class USTExtraVehicleMovementComponent4W*          VehicleMovementComponent4W                                // 0x01B0(0x0008)
class ASTExtraAerofoilPlaneVehicle*                OwnerVehicle                                              // 0x01B8(0x0008)
float                                              AngleOfAttack                                             // 0x01C0(0x0004)
struct FVector                                     LocalLinearVelocity                                       // 0x01C4(0x000C)
struct FVector                                     CurLinearVelocity                                         // 0x01D0(0x000C)
float                                              ForwardSpeed                                              // 0x01DC(0x0004)
float                                              ForwardSpeedKmh                                           // 0x01E0(0x0004)
struct FVector                                     VehicleUpAxis                                             // 0x01E4(0x000C)
struct FVector                                     VehicleForwardAxis                                        // 0x01F0(0x000C)
struct FVector                                     VehicleRightAxis                                          // 0x01FC(0x000C)
struct FVector                                     LocalAngularVelocity                                      // 0x0208(0x000C)
struct FVector                                     CurAngularVelocity                                        // 0x0214(0x000C)
struct FVector                                     CurAngularVelocityRadians                                 // 0x0220(0x000C)
struct FTransform                                  CurWorldTransform                                         // 0x0230(0x0030)
struct FRotator                                    CurTargetRot                                              // 0x0260(0x000C)
struct FVector                                     AirflowNormalLocal                                        // 0x026C(0x000C)
struct FAerofoilInput                              LocalInput                                                // 0x0278(0x0044)
struct FVector                                     CurFireBtnInput                                           // 0x02BC(0x000C)
struct FAerofoilInput                              CurrentInput                                              // 0x02C8(0x0044)
struct FHitResult                                  CurHitResult                                              // 0x0310(0x0088)
float                                              CurDistanceToLand                                         // 0x0398(0x0004)
Bool                                               CheckPurePitchInput                                       // 0x039C(0x0001)
Bool                                               bProcessRoll                                              // 0x039D(0x0001)
struct FVector                                     LastCalcUpdateTotalTorque                                 // 0x03A0(0x000C)
Bool                                               bInLostSpeedState                                         // 0x03AC(0x0001)
Bool                                               bInFireControlState                                       // 0x03AD(0x0001)
Bool                                               bOnFire                                                   // 0x03AE(0x0001)
int                                                SyncTag                                                   // 0x03B0(0x0004)
struct FAerofoilInput                              ServerInput                                               // 0x03B4(0x0044)
Bool                                               bUseUnReliableSendClientInputToServer                     // 0x03F8(0x0001)
float                                              ControlValueFastToZeroTimeThreshold                       // 0x03FC(0x0004)
struct FInputInterpSetting                         RollInterpolation                                         // 0x0400(0x000C)
struct FInputInterpSetting                         PitchInterpolation                                        // 0x040C(0x000C)
struct FInputInterpSetting                         YawInterpolation                                          // 0x0418(0x000C)
struct FInputInterpSetting                         ThrottleForwardInterpolation                              // 0x0424(0x000C)
struct FInputInterpSetting                         ThrottleDampingInterpolation                              // 0x0430(0x000C)
float                                              DampingThrottleTarget                                     // 0x043C(0x0004)
class UCurveFloat*                                 ThrottleAccCurve                                          // 0x0440(0x0008)
float                                              LostSpeedAngel                                            // 0x0448(0x0004)
float                                              LostSpeedVelocityThreshold                                // 0x044C(0x0004)
float                                              LostSpeedEngineScalar                                     // 0x0450(0x0004)
class UCurveFloat*                                 ReverseAccCurve                                           // 0x0458(0x0008)
float                                              ComponentLocationOffsetTrace                              // 0x0460(0x0004)
float                                              LandTraceMaxHeight                                        // 0x0464(0x0004)
float                                              MaxDistanceToLand                                         // 0x0468(0x0004)
float                                              MaxAltitudeHeight                                         // 0x046C(0x0004)
float                                              OverMaxAltitudeHeightCanInput                             // 0x0470(0x0004)
float                                              MaxVelocityKmh                                            // 0x0474(0x0004)
float                                              SpeedThresholdLiftForce                                   // 0x0478(0x0004)
float                                              MinSpeedCanDeceleration                                   // 0x047C(0x0004)
float                                              MinHeightCanDeceleration                                  // 0x0480(0x0004)
float                                              DecelerationSpeedStrength                                 // 0x0484(0x0004)
class UCurveFloat*                                 DecelerationSpeedCurve                                    // 0x0488(0x0008)
TArray<struct FVehicleAerofoilConfig>              AerofoilConfig                                            // 0x0490(0x0010)
class UCurveFloat*                                 DragCurve                                                 // 0x04A0(0x0008)
float                                              DragMultiplier                                            // 0x04A8(0x0004)
class UCurveFloat*                                 LiftCurve                                                 // 0x04B0(0x0008)
class UCurveFloat*                                 LiftFactorByAltitude                                      // 0x04B8(0x0008)
float                                              LiftMultiplier                                            // 0x04C0(0x0004)
float                                              Camber                                                    // 0x04C4(0x0004)
float                                              StallAngel                                                // 0x04C8(0x0004)
float                                              AerofoilAreaFactor                                        // 0x04CC(0x0004)
float                                              MinControlSpeed                                           // 0x04D0(0x0004)
float                                              MinControlSpeedInAir                                      // 0x04D4(0x0004)
float                                              MinHeightControlRoll                                      // 0x04D8(0x0004)
float                                              MinHeightControlYaw                                       // 0x04DC(0x0004)
float                                              JustControlYawFactor                                      // 0x04E0(0x0004)
float                                              LockThreshold                                             // 0x04E4(0x0004)
struct FVehicleTorqueControlConfig                 TorqueControl                                             // 0x04E8(0x0058)
struct FVehicleTargetRotationControlConfig         TargetRotationControl                                     // 0x0540(0x0054)
float                                              RollControlSpeed                                          // 0x0594(0x0004)
float                                              EasyModeControlStrength                                   // 0x0598(0x0004)
struct FMappedData                                 EasyModeInputToTorque                                     // 0x059C(0x0010)
float                                              EasyModeValidRollThreshold                                // 0x05AC(0x0004)
float                                              EasyModeTorqueRollThreshold                               // 0x05B0(0x0004)
float                                              EasyModePitchStrength                                     // 0x05B4(0x0004)
float                                              EasyModeRollStrength                                      // 0x05B8(0x0004)
float                                              EasyModeYawStrength                                       // 0x05BC(0x0004)
float                                              FlipStateYawFactor                                        // 0x05C0(0x0004)
float                                              EasyModeValidInputThreshold                               // 0x05C4(0x0004)
float                                              MaxRollAngel                                              // 0x05C8(0x0004)
float                                              MaxRollAngelToDamping                                     // 0x05CC(0x0004)
class UCurveFloat*                                 RollStiffnessDampingCurveByRollAngel                      // 0x05D0(0x0008)
float                                              MaxRollAngelOnWingDamage                                  // 0x05D8(0x0004)
struct FMappedData                                 InputToRollAngelMapData                                   // 0x05DC(0x0010)
Bool                                               bRotateYawWithWorldUp                                     // 0x05EC(0x0001)
Bool                                               bRotateYawUseSelfUp                                       // 0x05ED(0x0001)
struct FMappedData                                 RollStrengthMap                                           // 0x05F0(0x0010)
float                                              MaxDelayRotateBackTime                                    // 0x0600(0x0004)
float                                              RotateBackImmediatelyRollThreshold                        // 0x0604(0x0004)
float                                              RotateBackInputThreshold                                  // 0x0608(0x0004)
Bool                                               bCheckRotateBackFireConditionSelf                         // 0x060C(0x0001)
float                                              DontRotateBackPitchThreshold                              // 0x0610(0x0004)
float                                              RotateBackTimer                                           // 0x0614(0x0004)
class UCurveFloat*                                 IdleForwardTorqueCurveFloat                               // 0x0618(0x0008)
class UCurveFloat*                                 IdleRightTorqueCurveFloat                                 // 0x0620(0x0008)
float                                              IdleCurveTotalTime                                        // 0x0628(0x0004)
float                                              RotateBaseCalcFactor                                      // 0x062C(0x0004)
float                                              FireRotateBaseCalcFactor                                  // 0x0630(0x0004)
float                                              CentreRotateBackBaseCalcFactor                            // 0x0634(0x0004)
float                                              NowIdleTime                                               // 0x0638(0x0004)
float                                              CanPlayIdleCurveHeight                                    // 0x063C(0x0004)
float                                              CanPitchDownDisToLand                                     // 0x0640(0x0004)
class UCurveVector*                                SpeedToControlStiffnessCurve                              // 0x0648(0x0008)
class UCurveVector*                                HeightToControlStiffnessCurve                             // 0x0650(0x0008)
float                                              AirDragCoefficient                                        // 0x0658(0x0004)
float                                              AirDownCoefficient                                        // 0x065C(0x0004)
float                                              DensityOfMedium                                           // 0x0660(0x0004)
class UCurveFloat*                                 AirDragCurve                                              // 0x0668(0x0008)
class UCurveFloat*                                 HeightToMaxSpeed                                          // 0x0670(0x0008)
class UCurveFloat*                                 HeightToMinSpeed                                          // 0x0678(0x0008)
class UCurveFloat*                                 AltitudeToMaxZVelocity                                    // 0x0680(0x0008)
float                                              ClampMaxZVelocityInterpSpeed                              // 0x0688(0x0004)
float                                              AllForceScaleFactor                                       // 0x068C(0x0004)
struct FMappedData                                 MapSpeedInterpData                                        // 0x0690(0x0010)
Bool                                               bFireInputFirstLevel                                      // 0x06A0(0x0001)
Bool                                               bEnablePitchBalance                                       // 0x06A1(0x0001)
float                                              PitchBalanceThreshold                                     // 0x06A4(0x0004)
Bool                                               bUseForceSimulate                                         // 0x06A8(0x0001)
float                                              SingleStepMaxTime                                         // 0x06AC(0x0004)
Bool                                               bAdvanceModePitchReverse                                  // 0x06B0(0x0001)
Bool                                               bUseImpulseDeltaTime                                      // 0x06B1(0x0001)
Bool                                               bForceResetPitch                                          // 0x06B2(0x0001)
float                                              ForceResetPitchThreshold                                  // 0x06B4(0x0004)
Bool                                               bAdvanceModeUseTargetCalc                                 // 0x06B8(0x0001)
Bool                                               bEasyMode                                                 // 0x06B9(0x0001)
Bool                                               bHavePower                                                // 0x06BA(0x0001)
float                                              PowerEfficiency                                           // 0x06BC(0x0004)
Bool                                               bEasyModeAutoCenter                                       // 0x06C0(0x0001)
Bool                                               bUseRollInterpCalc                                        // 0x06C1(0x0001)
Bool                                               bCanControl                                               // 0x06C2(0x0001)
Bool                                               bCanThrust                                                // 0x06C3(0x0001)
Bool                                               bCanLift                                                  // 0x06C4(0x0001)
Bool                                               bCanClampVel                                              // 0x06C5(0x0001)
Bool                                               bAlwaysCalcControlDampingTorque                           // 0x06C6(0x0001)
Bool                                               bForbidReverseVel                                         // 0x06C7(0x0001)
float                                              OnLandSpeedToMergeVelocity                                // 0x06C8(0x0004)
float                                              OnLandSpeedToMergeHeight                                  // 0x06CC(0x0004)
Bool                                               bNotSimulate                                              // 0x06D0(0x0001)
Bool                                               bCanAerodynamicForce                                      // 0x06D1(0x0001)
float                                              Disable4WSimulateDistanceToLand                           // 0x06D4(0x0004)
Bool                                               bEnableFinalSimulateEvent                                 // 0x06D8(0x0001)
Bool                                               bEnableUpdateEngineStateEvent                             // 0x06D9(0x0001)
Bool                                               bEnableUpdateThrustEvent                                  // 0x06DA(0x0001)
Bool                                               bEnableUpdateLiftEvent                                    // 0x06DB(0x0001)
Bool                                               bEnableUpdateControlEvent                                 // 0x06DC(0x0001)
Bool                                               bEnableUpdateControlDeltaTime                             // 0x06DD(0x0001)
float                                              UpdateControlScale                                        // 0x06E0(0x0004)
Bool                                               bUseDamping                                               // 0x06E4(0x0001)
Bool                                               bUseTorqueImpulse                                         // 0x06E5(0x0001)
Bool                                               bUseTorqueCalcDeltaTime                                   // 0x06E6(0x0001)
Bool                                               bEnableProcessLostSpeedEvent                              // 0x06E7(0x0001)
float                                              LostSpeedContinueTimeToRotateBack                         // 0x06E8(0x0004)
int                                                LostSpeedStateTips                                        // 0x06EC(0x0004)
float                                              LostSpeedContinueTimer                                    // 0x06F0(0x0004)
Bool                                               EnterLostSpeedCorrectState                                // 0x06F4(0x0001)
float                                              LostSpeedExtraThrottleConfig                              // 0x06F8(0x0004)
Bool                                               bUseCalculateRotateBackEvent                              // 0x06FC(0x0001)
struct FAirDragConfig                              DragConfig                                                // 0x0700(0x0078)
float                                              EngineOnAirDragCoefficient                                // 0x0778(0x0004)
class UCurveFloat*                                 ReverseThrottleDrag                                       // 0x0780(0x0008)
float                                              MergeDragCoefficient                                      // 0x0788(0x0004)
Bool                                               bEnableMergeSpeed                                         // 0x078C(0x0001)
float                                              MaxForwardSpeed                                           // 0x0790(0x0004)
float                                              MaxVerticalSpeed                                          // 0x0794(0x0004)
float                                              MaxVehicleSpeed                                           // 0x0798(0x0004)
float                                              MaxAngularVelInDegree                                     // 0x079C(0x0004)
float                                              MaxLinearVel                                              // 0x07A0(0x0004)
Bool                                               bEnableGetMergedAndDragVelocityEvent                      // 0x07A4(0x0001)
Bool                                               bInHitState                                               // 0x07A5(0x0001)
float                                              CheckInHitStateTimeThreshold                              // 0x07A8(0x0004)
int                                                LeftWingPartIndex                                         // 0x07AC(0x0004)
int                                                RightWingPartIndex                                        // 0x07B0(0x0004)
Bool                                               bLeftWingDestroy                                          // 0x07B4(0x0001)
Bool                                               bRightWingDestroy                                         // 0x07B5(0x0001)
Bool                                               bEngineDestroy                                            // 0x07B6(0x0001)
float                                              WingExplodeInputOffset                                    // 0x07B8(0x0004)
float                                              SingleWingExplodeControlDamping                           // 0x07BC(0x0004)
float                                              DoubleWingExplodeControlDamping                           // 0x07C0(0x0004)
float                                              WingExplodeControlStiffnessDamping                        // 0x07C4(0x0004)
float                                              DoubleWingExplodeControlStiffnessDamping                  // 0x07C8(0x0004)
float                                              WingExplodeControlStiffnessDampingOnAdvanceMode           // 0x07CC(0x0004)
float                                              DoubleWingExplodeControlStiffnessDampingOnAdvanceMode     // 0x07D0(0x0004)
float                                              FinalMoveRightRateOnWingDamage                            // 0x07D4(0x0004)
};

// 大佬QQ:2396031563
// Class SpawnSystem.STSpawnerBase
// 0x0150 (0x0720 - 0x05D0)
class ASTSpawnerBase : public AActor
{
public:
class USTSpotDataAsset*                            SpotData                                                  // 0x05D0(0x0008)
struct FString                                     LuaFilePath                                               // 0x05D8(0x0010)
Bool                                               bUseSpawnManager                                          // 0x05E8(0x0001)
class USTStrategyTiming*                           SpawnTiming                                               // 0x05F0(0x0008)
class USTStrategyLocation*                         SpawnLocation                                             // 0x05F8(0x0008)
class USTStrategySpecies*                          SpawnSpecies                                              // 0x0600(0x0008)
TArray<class USTStrategyCond*>                     SpawnConditions                                           // 0x0608(0x0010)
Bool                                               bUseRegion                                                // 0x0618(0x0001)
Bool                                               bDebugDraw                                                // 0x0618(0x0001)
Bool                                               bUsable                                                   // 0x0618(0x0001)
int                                                SpawnerCampID                                             // 0x061C(0x0004)
ESTSpawnerVolume                                   VolumeType                                                // 0x0620(0x0001)
float                                              SphereRadius                                              // 0x0624(0x0004)
struct FVector                                     BoxHalfExtent                                             // 0x0628(0x000C)
ESTSpawnerVolume                                   RestrictedAreaVolumeType                                  // 0x0634(0x0001)
float                                              RestrictedAreaSphereRadius                                // 0x0638(0x0004)
struct FVector                                     RestrictedAreaBoxHalfExtent                               // 0x063C(0x000C)
Bool                                               bUseRestrictedArea                                        // 0x0648(0x0001)
class UClass*                                      SpawnSpotClass                                            // 0x0650(0x0008)
struct FScriptMulticastDelegate                    OnSpawnUnitSuccessDelegate                                // 0x0658(0x0010)
struct FScriptMulticastDelegate                    OnSpawnedUnitDeadDelegate                                 // 0x0668(0x0010)
struct FScriptMulticastDelegate                    NotifyStrategyUpdateParam                                 // 0x0678(0x0010)
uint32_t                                           SpawnerID                                                 // 0x0688(0x0004)
int                                                DefaultSpawnerID                                          // 0x068C(0x0004)
int                                                MaxUnitsCount                                             // 0x0690(0x0004)
int                                                MaxAliveCount                                             // 0x0694(0x0004)
struct FString                                     SpawnerDescString                                         // 0x0698(0x0010)
Bool                                               bUseAsTrigger                                             // 0x06A8(0x0001)
Bool                                               bForceSpawn                                               // 0x06A8(0x0001)
Bool                                               bLoadAtClient                                             // 0x06A9(0x0001)
Bool                                               bShouldAlwaysRelevant                                     // 0x06AA(0x0001)
struct FString                                     SpawnerSnapshot                                           // 0x06B0(0x0010)
TArray<class ASTSpawnSpot*>                        SpawnSpots                                                // 0x06C0(0x0010)
TArray<class AActor*>                              AlivePawns                                                // 0x06D0(0x0010)
Bool                                               bActive                                                   // 0x06E0(0x0001)
Bool                                               bInitialized                                              // 0x06E0(0x0001)
Bool                                               bTimeIsRipe                                               // 0x06E0(0x0001)
int                                                TotalSpawnedUnits                                         // 0x06E4(0x0004)
int                                                TotalDeadUnitsNum                                         // 0x06E8(0x0004)
class USTSpawnSubsystem*                           SpawnSubsystem                                            // 0x06F0(0x0008)
int                                                WaitSpawn                                                 // 0x0708(0x0004)
Bool                                               bPlayerEnterRegion                                        // 0x070C(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AESpawner
// 0x0080 (0x07A0 - 0x0720)
class AAESpawner : public ASTSpawnerBase
{
public:
struct FScriptMulticastDelegate                    OnUnitTakeDamage                                          // 0x0720(0x0010)
Bool                                               bUseSphereCollisionTrigger                                // 0x0730(0x0001)
class USceneComponent*                             SceneCom                                                  // 0x0738(0x0008)
Bool                                               bEnableTeamAI                                             // 0x0740(0x0001)
TArray<class UClass*>                              TeamAIClasses                                             // 0x0748(0x0010)
int                                                SpawnerTeamID                                             // 0x0758(0x0004)
unsigned char                                      SpeciesCategory                                           // 0x075C(0x0001)
int                                                SpawnerCampItemID                                         // 0x0760(0x0004)
int                                                GroupID                                                   // 0x0764(0x0004)
struct FString                                     BossTag                                                   // 0x0768(0x0010)
Bool                                               bFastRefillAI                                             // 0x0788(0x0001)
TArray<class UActorComponent*>                     TeamAIComponents                                          // 0x0790(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AESpawner_Group
// 0x0100 (0x0820 - 0x0720)
class AAESpawner_Group : public ASTSpawnerBase
{
public:
class USceneComponent*                             SceneCom                                                  // 0x0720(0x0008)
struct FString                                     AIFeatureInfoTableName                                    // 0x0728(0x0010)
struct FString                                     AIDifficultyInfoTableName                                 // 0x0738(0x0010)
struct FString                                     AITagTableName                                            // 0x0748(0x0010)
class UClass*                                      AttributeGroup                                            // 0x0758(0x0008)
TMap<struct FString, int>                          InitSetAttrMap                                            // 0x0760(0x0050)
TArray<class UActorComponent*>                     TeamAIComponents                                          // 0x07B0(0x0010)
};

// 大佬QQ:2396031563
// Class Engine.GameInstance
// 0x02D8 (0x0300 - 0x0028)
class UGameInstance : public UObject
{
public:
TArray<int64_t>                                    EncryptedLocalPlayers                                     // 0x0038(0x0010)
TArray<class ULocalPlayer*>                        LocalPlayers                                              // 0x0048(0x0010)
class UOnlineSession*                              OnlineSession                                             // 0x0058(0x0008)
Bool                                               bUseEncryptLocalPlayerPtr                                 // 0x0080(0x0001)
class UObject*                                     DSHUD                                                     // 0x0088(0x0008)
TArray<unsigned char>                              CachedConsoleVariableBunch_BigWorld                       // 0x01C0(0x0010)
TArray<unsigned char>                              CachedConsoleVariableBunch_Permanent                      // 0x01D0(0x0010)
struct FScriptMulticastDelegate                    OnPakResStateChanged                                      // 0x01E0(0x0010)
TMap<ESpecialPakID, EPakResState>                  SpecialPakResStates                                       // 0x01F0(0x0050)
};

// 大佬QQ:2396031563
// Class SpawnSystem.STSpawnSubsystem
// 0x0190 (0x01C0 - 0x0030)
class USTSpawnSubsystem : public UGameInstanceSubsystem
{
public:
struct FScriptMulticastDelegate                    OnSpawnSysUnitSpawnedSuc                                  // 0x0040(0x0010)
TMap<uint32_t, class ASTSpawnerBase*>              SpawnersMap                                               // 0x0050(0x0050)
float                                              TickFrequency                                             // 0x0120(0x0004)
int                                                ThinkTimesPerFrame                                        // 0x0124(0x0004)
float                                              ReadySpawnFrequency                                       // 0x0128(0x0004)
int                                                MaxWaitSpawnQueSize                                       // 0x012C(0x0004)
Bool                                               bWaitSpawnInOrder                                         // 0x0130(0x0001)
int                                                RecAliveUnits                                             // 0x0188(0x0004)
int                                                WaitSpawnInOrderIndex                                     // 0x0190(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AESpawnSubsystem
// 0x01A0 (0x0360 - 0x01C0)
class UAESpawnSubsystem : public USTSpawnSubsystem
{
public:
struct FScriptDelegate                             OnCustomSpawnPreCheck                                     // 0x01C0(0x0010)
struct FScriptMulticastDelegate                    EscapeRandomEventDelegate                                 // 0x01D0(0x0010)
Bool                                               bPopQueAfterCustomPreCheckFailed                          // 0x01E0(0x0001)
class AActor*                                      GameModeActor                                             // 0x01E8(0x0008)
TMap<unsigned char, int>                           UnitsNumberThreshold                                      // 0x01F8(0x0050)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AFMUpdateConditionBase
// 0x0008 (0x0030 - 0x0028)
class UAFMUpdateConditionBase : public UObject
{
public:
unsigned char                                      Operator                                                  // 0x0028(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AgentBoundComponent
// 0x0018 (0x0140 - 0x0128)
class UAgentBoundComponent : public UActorComponent
{
public:
struct FVector                                     LocalCenter                                               // 0x0128(0x000C)
struct FVector                                     LocalSize                                                 // 0x0134(0x000C)
};

// 大佬QQ:2396031563
// Class Basic.OnlyActorComponent
// 0x0008 (0x0130 - 0x0128)
class UOnlyActorComponent : public UActorComponent
{
public:
unsigned char                                      bCanEverUpdate                                            // 0x0128(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIActingComponent
// 0x0ED8 (0x1000 - 0x0128)
class UAIActingComponent : public UActorComponent
{
public:
class UFakePlayerHitRateConfig*                    HitRateConfigPtr                                          // 0x0128(0x0008)
Bool                                               bMLAIWeaponEquipConfigInited                              // 0x0130(0x0001)
int                                                PlayersOnSquare                                           // 0x0134(0x0004)
int                                                OriginalTotalAINum                                        // 0x0138(0x0004)
int                                                OriginalTotalCandidateAINum                               // 0x013C(0x0004)
int                                                MaxTeamNum                                                // 0x0140(0x0004)
int                                                MaxPlayerNum                                              // 0x0144(0x0004)
int                                                RecordSecSincePlane                                       // 0x0148(0x0004)
class ASTExtraGameFramework*                       SavedGamemode                                             // 0x0150(0x0008)
TArray<struct FAIActingCandidateData>              CandidateAIList                                           // 0x0158(0x0010)
int                                                MaxActiveAI                                               // 0x023C(0x0004)
int                                                ActiveAI_n                                                // 0x0240(0x0004)
int                                                ActiveAI_m                                                // 0x0244(0x0004)
float                                              AISpawnCircleOriginOffset                                 // 0x0248(0x0004)
float                                              NoWhiteCirclesRadius                                      // 0x024C(0x0004)
struct FBox2D                                      SpawnMapBounds                                            // 0x0250(0x0014)
float                                              SpawnCheckHumanRadiusSquare                               // 0x0264(0x0004)
int                                                TryFindSpawnAILocNum                                      // 0x0268(0x0004)
float                                              SelectActionPeriod                                        // 0x026C(0x0004)
int                                                FakeAISpawnFailedPeriodTime                               // 0x0270(0x0004)
TArray<struct FAIActingItem>                       AIActingItemList                                          // 0x0278(0x0010)
TArray<struct FAIBeginAttackEachOther>             AIAttackEachOtherRatingTimeConfig                         // 0x0288(0x0010)
int                                                FullFeedLimit                                             // 0x0298(0x0004)
TArray<struct FDeliveryRatingConfig>               DeliveryWaveInterval                                      // 0x02A0(0x0010)
float                                              DeliveryBeginTime                                         // 0x02B0(0x0004)
float                                              DeliveryFreq                                              // 0x02B4(0x0004)
int                                                DeliveryAINumEachPeriod                                   // 0x02B8(0x0004)
float                                              MinimumWarmScore                                          // 0x02BC(0x0004)
TArray<struct FAIDeliveryAreaLimit>                AIDeliveryAreaLimit                                       // 0x02C0(0x0010)
TArray<struct FBox>                                AIDeliveryForbiddenAreas                                  // 0x02D0(0x0010)
TArray<struct FBox>                                AIFollowWayPointAreas                                     // 0x02E0(0x0010)
Bool                                               bUseDeliveryPosCheck                                      // 0x0340(0x0001)
int                                                DeliveryPosCheckRange                                     // 0x0344(0x0004)
int                                                DeliveryPosCheckMaxPlayerNum                              // 0x0348(0x0004)
int                                                DeliveryPosCheckMaxTeamNum                                // 0x034C(0x0004)
TArray<struct FDeliveryPolygonPoints>              DeliveryPolygonPointsList                                 // 0x0350(0x0010)
TArray<struct FAIRatingDamage>                     AIRatingDamageConfig                                      // 0x0360(0x0010)
TArray<struct FAIRatingDamage>                     ModelAIRatingDamageConfig                                 // 0x0370(0x0010)
TArray<struct FAIRatingDamage>                     MLAIRatingReductionDamageConfig                           // 0x0380(0x0010)
TArray<struct FAIHPBasedReductionDamage>           MLAIProjectileReductionDamageConfig                       // 0x0390(0x0010)
TArray<struct FAIHPBasedReductionDamage>           MLAIVehicleReductionDamageConfig                          // 0x03A0(0x0010)
TArray<int>                                        MLAIDamageProtectModeIDBlackList                          // 0x03B0(0x0010)
TArray<struct FAIAttackAIRatingDamage>             AIAttackAIRatingDamage                                    // 0x03C0(0x0010)
TArray<struct FAIAttackMORatingDamage>             AIAttackMORatingDamage                                    // 0x03D0(0x0010)
TArray<struct FAIAttackBuildingRatingDamage>       AIAttackBuildingRatingDamage                              // 0x03E0(0x0010)
TArray<struct FDeliveryPlayerConfig>               AIDeliveryPlayerConfig                                    // 0x03F0(0x0010)
TArray<struct FAIAttackAnimalRatingDamage>         AIAttackAnimalRatingDamage                                // 0x0400(0x0010)
Bool                                               bUseFireHitRateForAIShooting                              // 0x0410(0x0001)
float                                              AIAttackNotHitOffsetWidth                                 // 0x0414(0x0004)
float                                              AIAttackNotHitOffsetHeight                                // 0x0418(0x0004)
TArray<struct FAIRatingFireHitRate>                AIRatingFireHitRateConfig                                 // 0x0420(0x0010)
TArray<struct FAIAttackAIRatingFireHitRate>        AIAttackAIRatingFireHitRateConfig                         // 0x0430(0x0010)
Bool                                               bUseAIDynamicDamageBasedHP                                // 0x0440(0x0001)
Bool                                               bUseAIDynamicDamageBasedAILevel                           // 0x0441(0x0001)
Bool                                               bUseAIMobaHeroBasedAILevel                                // 0x0442(0x0001)
TArray<struct FAIShootDamageMobaHeroBasedLevel>    AIMobaHeroBasedAILevelConfig                              // 0x0448(0x0010)
TArray<struct FAIMobaEquipmentScore>               AIMobaEquipmentScoreConfig                                // 0x0458(0x0010)
TArray<struct FAIDynamicDamageBasedHP>             AIAttackPlayerDynamicDamageHPConfig                       // 0x0468(0x0010)
TArray<struct FAIDynamicDamageBasedHP>             AIAttackAIDynamicDamageHPConfig                           // 0x0478(0x0010)
int                                                MaxMoveRequestExecutePerFrame                             // 0x0498(0x0004)
int                                                MaxQueuingMoveRequests                                    // 0x049C(0x0004)
int                                                MaxClearTroubleRequestExecutePerFrame                     // 0x04A0(0x0004)
float                                              PathRecordTimeInterval                                    // 0x04A4(0x0004)
float                                              PathRecordDiffPointDistSq                                 // 0x04A8(0x0004)
float                                              PathRecordSpanTime                                        // 0x04AC(0x0004)
EOverrideQueryMobilityType                         PathRecordTestPointMobilityType                           // 0x04B0(0x0001)
unsigned char                                      PathRecordTestPointChannel                                // 0x04B1(0x0001)
TArray<unsigned char>                              PathRecordTestPointObjectTypes                            // 0x04B8(0x0010)
uint32_t                                           PathRecordQueueSize                                       // 0x04C8(0x0004)
int                                                MaxPathRecordExecutePerFrame                              // 0x04CC(0x0004)
struct FString                                     AIPatrolPathDataFilePath                                  // 0x04D0(0x0010)
class ACirleAreaVolume*                            CircleAreaVolume                                          // 0x0540(0x0008)
class UCircleMgrComponent*                         CircleMgrComponent                                        // 0x0548(0x0008)
TArray<TWeakObjectPtr<class ASTExtraPlayerCharacter>> CachedCandidatePlayers                                    // 0x0550(0x0010)
TArray<TWeakObjectPtr<class AFakePlayerAIController>> CachedCandidateAICs                                       // 0x05B0(0x0010)
Bool                                               HaveTurnedOnAIAttackEachOther                             // 0x05C0(0x0001)
int                                                CurrentActing                                             // 0x05E4(0x0004)
float                                              JumpingTimeElapse                                         // 0x05E8(0x0004)
float                                              Ratio                                                     // 0x05EC(0x0004)
int                                                JumpCount                                                 // 0x05F0(0x0004)
TMap<int, struct FMultiAirlineAISimulateJumpData>  MultiAirlineAISimulateJumpDataMap                         // 0x05F8(0x0050)
float                                              AverageRating                                             // 0x0648(0x0004)
float                                              AIAttackEachOtherBeginTime                                // 0x064C(0x0004)
float                                              AIDeliveryWaveInterval                                    // 0x0650(0x0004)
int                                                CircleIndexFakeAIPoisonDamage                             // 0x0654(0x0004)
int                                                AIAttackMORatingDamageIndex                               // 0x0658(0x0004)
int                                                AIAttackBuildingRatingDamageIndex                         // 0x065C(0x0004)
int                                                AIAttackAnimalRatingDamageIndex                           // 0x0660(0x0004)
TArray<TWeakObjectPtr<class AActor>>               WaterSwimActors                                           // 0x0700(0x0010)
Bool                                               IsCheckVisibilityReverse                                  // 0x0710(0x0001)
Bool                                               IsUseRVOAvoidance                                         // 0x0711(0x0001)
int                                                bEnableAIStrategy                                         // 0x0714(0x0004)
class UAIDropManager*                              AIDropManager                                             // 0x0A10(0x0008)
TArray<uint16_t>                                   AIStrategyRatingConfig                                    // 0x0A38(0x0010)
float                                              AIStrategyInitReadyStateLeftTime                          // 0x0A48(0x0004)
float                                              AIStrategyInitFallbackLeftTime                            // 0x0A4C(0x0004)
float                                              InitMLNetOnlineTimeDelay                                  // 0x0A50(0x0004)
float                                              MidDropMLAIDepositDistance                                // 0x0A54(0x0004)
int                                                InitMLAIPersonalInfoRequestCount                          // 0x0A58(0x0004)
struct FString                                     MLAIWeaponEquipConfigTableName                            // 0x0A60(0x0010)
struct FString                                     MLAIWeaponAttachmentConfigTableName                       // 0x0A70(0x0010)
EInitMLNetOnlineTime                               MLAINetOnlineInitTime                                     // 0x0B20(0x0001)
Bool                                               IsEnablePartner                                           // 0x0CB8(0x0001)
float                                              MLAIMarkPlayerInBattleSearchRadius                        // 0x0CBC(0x0004)
float                                              MLAIMarkPlayerInBattleFirePosDist                         // 0x0CC0(0x0004)
float                                              MLAIMarkPlayerInBattleShootDirDist                        // 0x0CC4(0x0004)
float                                              MLAIMarkPlayerInBattleNearDeathInterval                   // 0x0CC8(0x0004)
float                                              MLAIMarkPlayerInBattleCountDown                           // 0x0CCC(0x0004)
float                                              MLAIMarkPlayerInBattleMarkerTransferDist                  // 0x0CD0(0x0004)
class UGMDataSource_AirRoute*                      AirRouteData                                              // 0x0D78(0x0008)
float                                              DefaultRealtimeStatesSyncInterval                         // 0x0EE8(0x0004)
struct FString                                     BFAIShootConfig                                           // 0x0F60(0x0010)
struct FString                                     MobaAIShootConfig                                         // 0x0FE0(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIActionExecuteComponent
// 0x00D0 (0x01F8 - 0x0128)
class UAIActionExecuteComponent : public UActorComponent
{
public:
float                                              SearchPickupItemRadius                                    // 0x0128(0x0004)
int                                                SearchPickupItemMaxBox                                    // 0x012C(0x0004)
int                                                SearchPickupItemMaxItems                                  // 0x0130(0x0004)
int                                                SearchDoorSwitchRadius                                    // 0x0134(0x0004)
struct FVector2D                                   StandPitchRange                                           // 0x0138(0x0008)
struct FVector2D                                   CrouchPitchRange                                          // 0x0140(0x0008)
struct FVector2D                                   PronePitchRange                                           // 0x0148(0x0008)
struct FVector2D                                   FreeFallPitchRange                                        // 0x0150(0x0008)
Bool                                               bUpdatePitchAfterSwitchPose                               // 0x0158(0x0001)
int                                                SearchUseVehicleRadius                                    // 0x015C(0x0004)
float                                              DriveVehicleStuckSampleInterval                           // 0x0160(0x0004)
int                                                DriveVehicleStuckSampleCount                              // 0x0164(0x0004)
float                                              DriveVehicleStuckCheckDistance                            // 0x0168(0x0004)
float                                              DriveVehicleHitTriggerInterval                            // 0x016C(0x0004)
float                                              DriveVehicleFreqHitStatInterval                           // 0x0170(0x0004)
int                                                DriveVehicleHitStatTimes                                  // 0x0174(0x0004)
class AFakePlayerAIController*                     OwnerAIC                                                  // 0x01A8(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AiAgentComponent
// 0x0450 (0x0578 - 0x0128)
class UAiAgentComponent : public UActorComponent
{
public:
class URespawnItemConfig*                          WeaponConfig                                              // 0x0368(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIBehemothAid
// 0x0068 (0x0090 - 0x0028)
class UAIBehemothAid : public UObject
{
public:
int                                                BehemothAidSkillIndex                                     // 0x0028(0x0004)
float                                              UpdateInterTime                                           // 0x002C(0x0004)
float                                              CoolDownTime                                              // 0x0030(0x0004)
float                                              RangeMin                                                  // 0x0034(0x0004)
float                                              RangeMax                                                  // 0x0038(0x0004)
float                                              AidPlayerHealthPercent                                    // 0x003C(0x0004)
TArray<int>                                        MobAidIdList                                              // 0x0040(0x0010)
int                                                TlogStatisticsID                                          // 0x0050(0x0004)
class UAIBehemothComponent*                        AIBehemothComponent                                       // 0x0058(0x0008)
class UAIOrderComponent*                           AIOrderComponent                                          // 0x0060(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIBehemothComponent
// 0x0050 (0x0178 - 0x0128)
class UAIBehemothComponent : public UActorComponent
{
public:
class UClass*                                      WaypointBehaviorTemplate                                  // 0x0128(0x0008)
class UClass*                                      BehemothSkillDamageToPlayersTemplate                      // 0x0130(0x0008)
class UClass*                                      BehemothAidTemplate                                       // 0x0138(0x0008)
struct FString                                     CastBuffTag                                               // 0x0140(0x0010)
float                                              CastBuffDelayTime                                         // 0x0150(0x0004)
float                                              Idle2AnimTime                                             // 0x0154(0x0004)
class ACharacter*                                  BehemothPawn                                              // 0x0158(0x0008)
class UAIWaypointBehavior*                         WaypointBehavior                                          // 0x0160(0x0008)
class UAIBehemothSkillDamageToPlayers*             BehemothSkillDamageToPlayers                              // 0x0168(0x0008)
class UAIBehemothAid*                              BehemothAid                                               // 0x0170(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIBehemothSkillDamageToPlayers
// 0x0070 (0x0098 - 0x0028)
class UAIBehemothSkillDamageToPlayers : public UObject
{
public:
int                                                DamageToPlayersSkillIndex                                 // 0x0028(0x0004)
float                                              SkillRange                                                // 0x002C(0x0004)
float                                              SkillTipTime                                              // 0x0030(0x0004)
int                                                MsgID                                                     // 0x0034(0x0004)
Bool                                               bCastOnLocation                                           // 0x0038(0x0001)
float                                              UpdateInterTime                                           // 0x003C(0x0004)
float                                              CoolDownTime                                              // 0x0040(0x0004)
float                                              RangeMin                                                  // 0x0044(0x0004)
float                                              RangeMax                                                  // 0x0048(0x0004)
int                                                ConfigMaxEnemiesNum                                       // 0x004C(0x0004)
int                                                ConfigIntervalAngle                                       // 0x0050(0x0004)
class UAIBehemothComponent*                        AIBehemothComponent                                       // 0x0058(0x0008)
class UAIOrderComponent*                           AIOrderComponent                                          // 0x0060(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIBreakWindowComponent
// 0x0070 (0x0198 - 0x0128)
class UAIBreakWindowComponent : public UActorComponent
{
public:
unsigned char                                      OverlapChannel                                            // 0x0160(0x0001)
Bool                                               bCheckWhenMove                                            // 0x0161(0x0001)
Bool                                               bOnlyCheckAbstractPath                                    // 0x0162(0x0001)
float                                              MinCheckDistance                                          // 0x0164(0x0004)
Bool                                               bCheckWhenCastSkill                                       // 0x0168(0x0001)
float                                              AttackAngleOffset                                         // 0x016C(0x0004)
float                                              AttackDistance                                            // 0x0170(0x0004)
Bool                                               bCheckWhenVault                                           // 0x0174(0x0001)
float                                              VaultCheckHorizontalOffset                                // 0x0178(0x0004)
float                                              VaultCheckHeightOffset                                    // 0x017C(0x0004)
float                                              VaultCheckForwardOffset                                   // 0x0180(0x0004)
float                                              VaultCheckInterval                                        // 0x0184(0x0004)
Bool                                               bDrawDebugLine                                            // 0x0188(0x0001)
float                                              DrawDebugLifeTime                                         // 0x018C(0x0004)
Bool                                               bDrawAllWindows                                           // 0x0190(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIBuildingComponent
// 0x0080 (0x01B8 - 0x0138)
class UAIBuildingComponent : public UAIAbilityComponent
{
public:
TMap<int, int>                                     CanBuildActorNums                                         // 0x0158(0x0050)
float                                              TotalCD                                                   // 0x01A8(0x0004)
float                                              SoloCD                                                    // 0x01AC(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AICarryPlayerComp
// 0x0128 (0x0260 - 0x0138)
class UAICarryPlayerComp : public UAIAbilityComponent
{
public:
TArray<struct FCarryReplaceCharAnimData>           ReplaceAnimDataList_BeCarriedPawnByAI_Armed               // 0x0138(0x0010)
TArray<struct FCarryReplaceCharAnimData>           ReplaceAnimDataList_BeCarriedPawnByAI_Unarmed             // 0x0148(0x0010)
unsigned char                                      CarrySomeoneSkillTemplate                                 // 0x0158(0x0028)
unsigned char                                      PutDownSkillTemplate                                      // 0x0180(0x0028)
unsigned char                                      BeCarriedSkillTemplate                                    // 0x01A8(0x0028)
int                                                PutDownPhaseID                                            // 0x01D0(0x0004)
class ASTExtraBaseCharacter*                       CarryWho                                                  // 0x01D8(0x0008)
struct FScriptMulticastDelegate                    OnAICarryPlayerStart                                      // 0x01E0(0x0010)
struct FScriptMulticastDelegate                    OnAICarryPlayerFinish                                     // 0x01F0(0x0010)
TWeakObjectPtr<class ASTExtraCharacter>            SelfPawnPtr                                               // 0x0200(0x0008)
TMap<class ASTExtraBaseCharacter*, float>          TeammateBreakAwayMap                                      // 0x0208(0x0050)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIClientNavigationComponent
// 0x0040 (0x0168 - 0x0128)
class UAIClientNavigationComponent : public UActorComponent
{
public:
struct FString                                     NavDataPathClient                                         // 0x0128(0x0010)
Bool                                               bOpenNavlinkAbilityClient                                 // 0x0138(0x0001)
struct FString                                     NavLinkDataPathClient                                     // 0x0140(0x0010)
class UNavigationSystem*                           ClientNavigationSystem                                    // 0x0150(0x0008)
class AUAERecastNavMesh*                           ClientNavData                                             // 0x0158(0x0008)
float                                              AStarMaxSearchDistanceSqr                                 // 0x0160(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AICustomMovementCurveRootMotion
// 0x01F8 (0x0220 - 0x0028)
class UAICustomMovementCurveRootMotion : public UObject
{
public:
TMap<struct FString, struct FCurveRootMotionAssetConfig> AssetConfigs                                              // 0x0028(0x0050)
unsigned char                                      PreSetMovementMode                                        // 0x0078(0x0001)
struct FCurveRootMotionMoveRequest                 MoveRequest                                               // 0x0080(0x0080)
class ACharacter*                                  CharacterOwner                                            // 0x0100(0x0008)
class USTCharacterMovementComponentBase*           MovementOwner                                             // 0x0108(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AICustomPathActor
// 0x0010 (0x05E0 - 0x05D0)
class AAICustomPathActor : public AActor
{
public:
class UCapsuleComponent*                           CapsuleComponent                                          // 0x05C8(0x0008)
class UAIPathComponent*                            AIPathComp                                                // 0x05D0(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIDebugPanelComponent
// 0x0010 (0x0140 - 0x0130)
class UAIDebugPanelComponent : public UOnlyActorComponent
{
public:
class UAIDebugPanelModeInfoProviderBase*           Provider                                                  // 0x0130(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIDebugPanelModeInfoProviderBase
// 0x00A0 (0x00C8 - 0x0028)
class UAIDebugPanelModeInfoProviderBase : public UObject
{
public:
TMap<int64_t, struct FAIDebugPanelSkillInfo>       SkillInfoMap                                              // 0x0028(0x0050)
TMap<int64_t, struct FString>                      MLBehaviorStrMap                                          // 0x0078(0x0050)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIDebugPanelSingleWidget
// 0x0050 (0x0300 - 0x02B0)
class UAIDebugPanelSingleWidget : public UUserWidget
{
public:
class UTextBlock*                                  BaseInfoText                                              // 0x02B0(0x0008)
float                                              DistanceLimit                                             // 0x02B8(0x0004)
struct FVector4                                    Limit                                                     // 0x02C0(0x0010)
struct FVector2D                                   UIOffset                                                  // 0x02D0(0x0008)
struct FVector2D                                   WidgetAlign                                               // 0x02D8(0x0008)
struct FVector                                     LocationOffset                                            // 0x02E0(0x000C)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIDebugPanelWidget
// 0x0090 (0x0340 - 0x02B0)
class UAIDebugPanelWidget : public UUserWidget
{
public:
class UCanvasPanel*                                HUD                                                       // 0x02B0(0x0008)
class UCanvasPanel*                                Panel                                                     // 0x02B8(0x0008)
class UComboBoxString*                             AISelector                                                // 0x02C0(0x0008)
class UCheckBox*                                   ShowSingleCheckBox                                        // 0x02C8(0x0008)
class UClass*                                      SingleWidgetClass                                         // 0x02D0(0x0008)
class UPanelWidget*                                CurPanel                                                  // 0x02D8(0x0008)
TMap<uint32_t, class UAIDebugPanelSingleWidget*>   SingleWidgets                                             // 0x02F0(0x0050)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIDelaySpawnLocationComponent
// 0x0098 (0x01C0 - 0x0128)
class UAIDelaySpawnLocationComponent : public UActorComponent
{
public:
Bool                                               bOpenAIDelaySpawnLocation                                 // 0x0128(0x0001)
struct FVector2D                                   WorldCenter                                               // 0x012C(0x0008)
struct FVector2D                                   WorldSize                                                 // 0x0134(0x0008)
float                                              GridSize                                                  // 0x013C(0x0004)
int                                                PlayerCoverGridRadius                                     // 0x0140(0x0004)
float                                              RefreshCoverGridInterval                                  // 0x0144(0x0004)
int                                                TryFindSpawnLocTimes                                      // 0x0148(0x0004)
float                                              DebugDrawHeight                                           // 0x014C(0x0004)
float                                              DebugDrawLineWidth                                        // 0x0150(0x0004)
float                                              DebugDrawCircleSize                                       // 0x0154(0x0004)
float                                              DebugDrawInterval                                         // 0x0158(0x0004)
struct FVector                                     DebugCircle                                               // 0x015C(0x000C)
Bool                                               bDebugDraw                                                // 0x0168(0x0001)
TWeakObjectPtr<class ABattleRoyaleGameModeBase>    SavedGamemode                                             // 0x016C(0x0008)
TWeakObjectPtr<class UAIActingComponent>           AIActingComp                                              // 0x0174(0x0008)
TWeakObjectPtr<class UCircleMgrComponent>          CircleMgrComp                                             // 0x017C(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIWayPointActor
// 0x0030 (0x0600 - 0x05D0)
class AAIWayPointActor : public AActor
{
public:
int                                                ID                                                        // 0x05C8(0x0004)
TArray<struct FTeamWayPointLink>                   TeamLinks                                                 // 0x05D0(0x0010)
class UCapsuleComponent*                           CapsuleComponent                                          // 0x05E0(0x0008)
class UBillboardComponent*                         ShowSprite                                                // 0x05E8(0x0008)
class UAIWayPointRenderingComponent*               EdRenderComp                                              // 0x05F0(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIDepthWayPointActor
// 0x0040 (0x0640 - 0x0600)
class AAIDepthWayPointActor : public AAIWayPointActor
{
public:
Bool                                               bSpecialPointType                                         // 0x05F8(0x0001)
unsigned char                                      AIType                                                    // 0x05F9(0x0001)
struct FDepthWayPointLink                          DepthWayPointLink                                         // 0x0600(0x0038)
Bool                                               bIsActive                                                 // 0x0638(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AiGmBtn
// 0x0020 (0x02D0 - 0x02B0)
class UAiGmBtn : public UUserWidget
{
public:
class UTextBlock*                                  MyText                                                    // 0x02B0(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AiGmCategory
// 0x0030 (0x02E0 - 0x02B0)
class UAiGmCategory : public UUserWidget
{
public:
class UTextBlock*                                  MyText                                                    // 0x02B0(0x0008)
Bool                                               bIsSelected                                               // 0x02B8(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AiDevGm
// 0x01D8 (0x0488 - 0x02B0)
class UAiDevGm : public UUserWidget
{
public:
class UTextBlock*                                  GmStr                                                     // 0x02B0(0x0008)
class UMultiLineEditableTextBox*                   Text_GM_Input                                             // 0x02B8(0x0008)
class UVerticalBox*                                CategoryList                                              // 0x02C0(0x0008)
class UButton*                                     BtnPageUp                                                 // 0x02C8(0x0008)
class UButton*                                     BtnPageDown                                               // 0x02D0(0x0008)
class UButton*                                     BtnShowPlayerList                                         // 0x02D8(0x0008)
class UButton*                                     BtnShowPlayerInfo                                         // 0x02E0(0x0008)
class UButton*                                     ButtonHelp                                                // 0x02E8(0x0008)
class UButton*                                     BtnManual                                                 // 0x02F0(0x0008)
class UButton*                                     GmShowDetail                                              // 0x02F8(0x0008)
class UTextBlock*                                  VersionInfos                                              // 0x0300(0x0008)
class UTextBlock*                                  PageInfo                                                  // 0x0308(0x0008)
class UAiGmPlayerPanel*                            PlayerInfos                                               // 0x0310(0x0008)
class UAiGmPlayerInfoPanel*                        CurPlayerInfo                                             // 0x0318(0x0008)
class UMultiLineEditableText*                      LinesFeedBack                                             // 0x0320(0x0008)
class UScrollBox*                                  FeedBackScroll                                            // 0x0328(0x0008)
class UAiGmParamContainer*                         ParamContainer                                            // 0x0330(0x0008)
int                                                PageSize                                                  // 0x0338(0x0004)
class UClass*                                      CategoryWidClass                                          // 0x0340(0x0008)
TArray<struct FAiDevGmConfig>                      ConfigList                                                // 0x0348(0x0010)
TArray<class UAiGmBtn*>                            GmBtns                                                    // 0x0358(0x0010)
TMap<struct FString, class UAiGmCategory*>         CategoryBtns                                              // 0x0368(0x0050)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AiDevSingle
// 0x0060 (0x0310 - 0x02B0)
class UAiDevSingle : public UUserWidget
{
public:
class UTextBlock*                                  MyInfo                                                    // 0x02B0(0x0008)
class UTextBlock*                                  MyTransInfo                                               // 0x02B8(0x0008)
class UTextBlock*                                  MyBuffInfo                                                // 0x02C0(0x0008)
class UTextBlock*                                  MyCustomInfo                                              // 0x02C8(0x0008)
struct FVector4                                    Limit                                                     // 0x02D0(0x0010)
struct FVector2D                                   UIOffset                                                  // 0x02E0(0x0008)
struct FVector2D                                   WidgetAlign                                               // 0x02E8(0x0008)
struct FVector                                     LocationOffset                                            // 0x02F0(0x000C)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AiDevWidget
// 0x00E8 (0x0398 - 0x02B0)
class UAiDevWidget : public UUserWidget
{
public:
class UCanvasPanel*                                InfoPanel                                                 // 0x02B0(0x0008)
class UTextBlock*                                  TimeStr                                                   // 0x02B8(0x0008)
class UAiDevGm*                                    GmPanel                                                   // 0x02C0(0x0008)
class UButton*                                     GmButton                                                  // 0x02C8(0x0008)
class UClass*                                      PawnInfoClass                                             // 0x02D0(0x0008)
TMap<uint32_t, class UAiDevSingle*>                InfoWidgets                                               // 0x02D8(0x0050)
class UGmListFetch*                                FetchAgent                                                // 0x0328(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIDropManager
// 0x0008 (0x0030 - 0x0028)
class UAIDropManager : public UObject
{
public:
float                                              RequestAIDropInfoLeftTime                                 // 0x0028(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIEventWayPointActor
// 0x0010 (0x0610 - 0x0600)
class AAIEventWayPointActor : public AAIWayPointActor
{
public:
struct FWayPointEvents                             Events                                                    // 0x05F8(0x0010)
Bool                                               bRotatePawnOnReached                                      // 0x0608(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.BattleFieldThreatSoure_Player
// 0x0010 (0x0038 - 0x0028)
class UBattleFieldThreatSoure_Player : public UBattleFieldThreatSoure
{
public:
float                                              ChoosePlayerScore                                         // 0x0028(0x0004)
float                                              ChooseNearDeathPlayerScore                                // 0x002C(0x0004)
float                                              ChooseAIScore                                             // 0x0030(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.BattleFieldThreatSoure_Vehicle
// 0x0050 (0x0078 - 0x0028)
class UBattleFieldThreatSoure_Vehicle : public UBattleFieldThreatSoure
{
public:
TMap<ESTExtraVehicleType, float>                   VehicleTypePriorityMap                                    // 0x0028(0x0050)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIFindEnemyBySenseComponent
// 0x0148 (0x0270 - 0x0128)
class UAIFindEnemyBySenseComponent : public UActorComponent
{
public:
int                                                MaxEnemyNumPerPlyer                                       // 0x0128(0x0004)
int                                                MaxFindWayTime                                            // 0x012C(0x0004)
struct FString                                     BFAIShootConfig                                           // 0x0130(0x0010)
Bool                                               bUseDifficultyLevel                                       // 0x0140(0x0001)
Bool                                               bDebugFindFightingPoint                                   // 0x0141(0x0001)
Bool                                               bUseAggressiveness                                        // 0x0142(0x0001)
TMap<int, struct FBattleFieldThreatConfig>         BattleFieldThreatConfigMap                                // 0x0148(0x0050)
struct FVector                                     TraceStartOffset                                          // 0x0198(0x000C)
struct FVector                                     TraceEndOffset                                            // 0x01A4(0x000C)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIFindPathActor
// 0x0000 (0x05D0 - 0x05D0)
class AAIFindPathActor : public AActor
{
public:
class UBillboardComponent*                         BillboardComponent                                        // 0x05C8(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIFollowComp
// 0x0670 (0x0798 - 0x0128)
class UAIFollowComp : public UActorComponent
{
public:
struct FAIFollowDataConfig                         FollowPartnerDataConfig                                   // 0x0128(0x02D8)
struct FName                                       OwnerPlayerBBName                                         // 0x0400(0x0008)
struct FName                                       FollowPawnBBName                                          // 0x0408(0x0008)
struct FName                                       FollowStatusBBName                                        // 0x0410(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIFollowDebugComp
// 0x04C0 (0x05E8 - 0x0128)
class UAIFollowDebugComp : public UActorComponent
{
public:
struct FAIFollowDebugInfo                          DebugInfo                                                 // 0x0128(0x0200)
struct FAnalysisResultDebug                        AnalysisResult                                            // 0x0328(0x0048)
struct FAIFollowDebugInfo                          DebugInfoOther                                            // 0x0370(0x0200)
struct FAnalysisResultDebug                        AnalysisResultOther                                       // 0x0570(0x0048)
Bool                                               bEnableDebug                                              // 0x05B8(0x0001)
Bool                                               bEnableDebugOther                                         // 0x05B9(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIFollowDecisionComp
// 0x1228 (0x1350 - 0x0128)
class UAIFollowDecisionComp : public UActorComponent
{
public:
struct FScriptMulticastDelegate                    OnFollowStatusChanged                                     // 0x0128(0x0010)
int                                                TickFPS                                                   // 0x0138(0x0004)
int                                                UpdateAnalysisFPS                                         // 0x013C(0x0004)
struct FVector                                     EyeLocationOffset                                         // 0x0140(0x000C)
float                                              EyeHalfHorizontalAngles                                   // 0x014C(0x0004)
float                                              EyeHalfVerticalAngle                                      // 0x0150(0x0004)
Bool                                               bSmoothFollowPoint                                        // 0x0154(0x0001)
float                                              SmoothFollowPointTime                                     // 0x0158(0x0004)
float                                              SmoothExitDistance                                        // 0x015C(0x0004)
float                                              StartLerpFactorFromFollowPointToFollowerLocation          // 0x0160(0x0004)
float                                              NoChangeMoveActionNearToNavlink                           // 0x0164(0x0004)
float                                              MaxPIDExitDistance                                        // 0x0168(0x0004)
float                                              MinPIDExitDurationTime                                    // 0x016C(0x0004)
float                                              BlockedTimeLimit                                          // 0x0170(0x0004)
float                                              PoseChangeDelayTime                                       // 0x0174(0x0004)
float                                              AnalysisStopMoveTime                                      // 0x0178(0x0004)
float                                              ForceIdle_DistanceToFollowLocation                        // 0x017C(0x0004)
struct FWarDogStartRootMotionConfig                StartRootMotionConfig                                     // 0x0180(0x00B8)
struct FWarDogStopRootMotionConfig                 StopRootMotionConfig                                      // 0x0238(0x0120)
struct FWarDogTurnRootMotionConfig                 TurnRootMotionConfig                                      // 0x0358(0x01A0)
struct FWarDogFastTurnRootMotionConfig             FastTurnRootMotionConfig                                  // 0x04F8(0x0110)
Bool                                               bDebugSingStepAction                                      // 0x0608(0x0001)
Bool                                               bDebugEnterMoveTurn                                       // 0x0609(0x0001)
Bool                                               bDebugEnterMoveTurnFail                                   // 0x060A(0x0001)
Bool                                               bDebugExecMoveTurn                                        // 0x060B(0x0001)
Bool                                               bDebugRootMotionPath                                      // 0x060C(0x0001)
Bool                                               bPauseWhenVaulting                                        // 0x060D(0x0001)
class UClass*                                      FilterClass                                               // 0x0610(0x0008)
class UAIFollowAction*                             CurrentAction                                             // 0x11E0(0x0008)
class AActor*                                      FollowPointActor                                          // 0x11E8(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIFormationComponent
// 0x0018 (0x0150 - 0x0138)
class UAIFormationComponent : public UAIAbilityComponent
{
public:
float                                              FormationAutoFormedRadius                                 // 0x0138(0x0004)
Bool                                               bReviseWayPointRelativeToFormation                        // 0x013C(0x0001)
Bool                                               bReviseWayPointUse2DRelativeLocation                      // 0x013D(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIFormationReferActor
// 0x0000 (0x05D0 - 0x05D0)
class AAIFormationReferActor : public AActor
{
public:
class UCapsuleComponent*                           CapsuleComponent                                          // 0x05C8(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AiGmParamBase
// 0x0050 (0x0300 - 0x02B0)
class UAiGmParamBase : public UUserWidget
{
public:
class UTextBlock*                                  ParamName                                                 // 0x02B0(0x0008)
class USizeBox*                                    ParamSizeBox                                              // 0x02B8(0x0008)
class UAiGmParamContainer*                         Container                                                 // 0x02C0(0x0008)
class UFunction*                                   Function                                                  // 0x02C8(0x0008)
class UProperty*                                   Property                                                  // 0x02D0(0x0008)
unsigned char                                      Type                                                      // 0x02D8(0x0001)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AiGmParamText
// 0x0008 (0x0308 - 0x0300)
class UAiGmParamText : public UAiGmParamBase
{
public:
class UEditableTextBox*                            ValueText                                                 // 0x0300(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AiGmParamBitEnumItem
// 0x0018 (0x02C8 - 0x02B0)
class UAiGmParamBitEnumItem : public UUserWidget
{
public:
class UTextBlock*                                  ItemName                                                  // 0x02B0(0x0008)
class UCheckBox*                                   ItemCheckBox                                              // 0x02B8(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AiGmBitEnumPanel
// 0x0030 (0x02E0 - 0x02B0)
class UAiGmBitEnumPanel : public UUserWidget
{
public:
class UEnum*                                       Enum                                                      // 0x02B0(0x0008)
class UScrollBox*                                  EnumList                                                  // 0x02B8(0x0008)
class UButton*                                     BtnClose                                                  // 0x02C0(0x0008)
class UClass*                                      ItemClass                                                 // 0x02C8(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AiGmParamBitEnum
// 0x0020 (0x0320 - 0x0300)
class UAiGmParamBitEnum : public UAiGmParamBase
{
public:
class UClass*                                      BitEnumPanelClass                                         // 0x0300(0x0008)
class UButton*                                     ParamButton                                               // 0x0308(0x0008)
class UTextBlock*                                  ButtonText                                                // 0x0310(0x0008)
class UAiGmBitEnumPanel*                           BitEnumPanel                                              // 0x0318(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AiGmParamComboBox
// 0x0018 (0x0318 - 0x0300)
class UAiGmParamComboBox : public UAiGmParamBase
{
public:
class UComboBoxString*                             ComboBoxStr                                               // 0x0300(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AiGmParamCheckBox
// 0x0008 (0x0308 - 0x0300)
class UAiGmParamCheckBox : public UAiGmParamBase
{
public:
class UCheckBox*                                   ParamCheckBox                                             // 0x0300(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AiGmParamMenuItem
// 0x0030 (0x02E0 - 0x02B0)
class UAiGmParamMenuItem : public UUserWidget
{
public:
class UButton*                                     Button                                                    // 0x02B0(0x0008)
class UTextBlock*                                  ButtonText                                                // 0x02B8(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AiGmParamMenuConent
// 0x0020 (0x02D0 - 0x02B0)
class UAiGmParamMenuConent : public UUserWidget
{
public:
class UVerticalBox*                                MenuContainer                                             // 0x02B0(0x0008)
class UClass*                                      MenuItemClass                                             // 0x02B8(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AiGmParamEditableComboBox
// 0x0038 (0x0338 - 0x0300)
class UAiGmParamEditableComboBox : public UAiGmParamBase
{
public:
class UButton*                                     OpenMenuButton                                            // 0x0300(0x0008)
class UEditableTextBox*                            ValueText                                                 // 0x0308(0x0008)
class UMenuAnchor*                                 ParamMenuAnchor                                           // 0x0310(0x0008)
class UClass*                                      MenuContentClass                                          // 0x0318(0x0008)
class UAiGmParamEditableComboBoxValueGetterBase*   ValueGetter                                               // 0x0320(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AiGmParamContainer
// 0x0120 (0x03D0 - 0x02B0)
class UAiGmParamContainer : public UUserWidget
{
public:
TArray<class UAiGmParamBase*>                      ParamWidgets                                              // 0x02B0(0x0010)
class UHorizontalBox*                              Container                                                 // 0x02C0(0x0008)
TMap<unsigned char, class UClass*>                 ParamClsMap                                               // 0x02C8(0x0050)
TMap<struct FString, struct FGMMetaDatas>          FunctionMetaDataMap                                       // 0x0318(0x0050)
TMap<struct FString, struct FGMEnumMetaDatas>      EnumMetaDataMap                                           // 0x0368(0x0050)
class UFunction*                                   Function                                                  // 0x03B8(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AiGmPlayerTransLog
// 0x0060 (0x0310 - 0x02B0)
class UAiGmPlayerTransLog : public UUserWidget
{
public:
class UTextBlock*                                  TextPlayerTrans                                           // 0x02B0(0x0008)
class UButton*                                     BtnPushLoc                                                // 0x02B8(0x0008)
class UButton*                                     BtnPushRot                                                // 0x02C0(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AiGmPlayerInfoPanel
// 0x0070 (0x0320 - 0x02B0)
class UAiGmPlayerInfoPanel : public UUserWidget
{
public:
int                                                MaxLogCnt                                                 // 0x02B0(0x0004)
float                                              AIDeliveryInfoQueryInterval                               // 0x02B4(0x0004)
class UClass*                                      HistLogInfoClass                                          // 0x02B8(0x0008)
class UTextBlock*                                  TxtCurPlayerTrans                                         // 0x02C0(0x0008)
class UTextBlock*                                  TxtAIDeliveryInfo                                         // 0x02C8(0x0008)
class UScrollBox*                                  PlayerInfoList                                            // 0x02D0(0x0008)
class UButton*                                     LogCurrentInfo                                            // 0x02D8(0x0008)
class UButton*                                     BtnClose                                                  // 0x02E0(0x0008)
TArray<class UAiGmPlayerTransLog*>                 HistLogs                                                  // 0x02F8(0x0010)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIGridLocationManagerComponent
// 0x0098 (0x01C0 - 0x0128)
class UAIGridLocationManagerComponent : public UActorComponent
{
public:
Bool                                               bOpenAIAvoidPlayerGrid                                    // 0x0128(0x0001)
struct FAIGridLocationDataAvoidPlayer              AIAvoidPlayerGridData                                     // 0x0130(0x0080)
Bool                                               bGetCharacterFromWorld                                    // 0x01B0(0x0001)
Bool                                               bDrawAIAvoidPlayerGrid                                    // 0x01B1(0x0001)
float                                              DrawAIAvoidPlayerGridInterval                             // 0x01B4(0x0004)
float                                              DrawAIAvoidPlayerGridZOffset                              // 0x01B8(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIGroupManagerComponent
// 0x00B8 (0x01E0 - 0x0128)
class UAIGroupManagerComponent : public UActorComponent
{
public:
TArray<struct FAnimalGroupRespawnConfig>           AnimalGroupRespawnConfig                                  // 0x0128(0x0010)
TWeakObjectPtr<class UAIActingComponent>           AIActingComp                                              // 0x01D8(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIHoleUpComponent
// 0x0068 (0x01A0 - 0x0138)
class UAIHoleUpComponent : public UAIAbilityComponent
{
public:
float                                              OccludeBuildingActorByRemoveTime                          // 0x017C(0x0004)
float                                              OccludeBuildingActorInvalidDis                            // 0x0180(0x0004)
float                                              InvalidOccludeBuildingPosAgainCheckCD                     // 0x0184(0x0004)
float                                              OccludePosInvalidDis                                      // 0x0188(0x0004)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIInitSkillManagerComponent
// 0x0060 (0x0198 - 0x0138)
class UAIInitSkillManagerComponent : public UAIAbilityComponent
{
public:
TMap<EUTSkillEntry, unsigned char>                 InitSkillClassesMap                                       // 0x0138(0x0050)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AIKillingMobShow
// 0x0098 (0x00C0 - 0x0028)
class UAIKillingMobShow : public UObject
{
public:
float                                              RangeMax                                                  // 0x0028(0x0004)
class UClass*                                      KillingMobSpawnerClass                                    // 0x0030(0x0008)
class UClass*                                      MobMoveToTargetClass                                      // 0x0038(0x0008)
class UAIOrderComponent*                           AIOrderComponent                                          // 0x0040(0x0008)
};

// 大佬QQ:2396031563
// Class ShadowTrackerExtra.AILivingRangeLimitComponent
// 0x0040 (0x0178 - 0x0138)
class UAILivingRangeLimitComponent : public UAIAbilityComponent
{
public:
Bool                                               bInLivingRangeByOverlapComp                               // 0x0138(0x0001)
Bool                                               bForceSetToSpawnLocWhenRunFarAway                         // 0x0139(0x0001)
float                                              ForceSetToSpawnLocCheckInterval                           // 0x013C(0x0004)
float                                              ForceSetToSpawnLocXTolerance                              // 0x0140(0x0004)
float                                              ForceSetToSpawnLocYTolerance                              // 0x0144(0x0004)
float                                              ForceSetToSpawnLocZUpTolerance                            // 0x0148(0x0004)
float                                              ForceSetToSpawnLocZDownTolerance                          // 0x014C(0x0004)
};

// 大佬QQ:2396031563
// Class Engine.PrimitiveComponent
// 0x04B0 (0x07B0 - 0x0300)
class UPrimitiveComponent : public USceneComponent
{
public:
struct FExpectedQuality                            ExpectedQualityLimit                                      // 0x0300(0x0005)
Bool                                               bFixedLODDistanceFactorSwitch                             // 0x0305(0x0001)
float                                              CullingScreenSize                                         // 0x0308(0x0004)
float                                              MinDrawDistance                                           // 0x030C(0x0004)
float                                              LDMaxDrawDistance                                         // 0x0310(0x0004)
float                                              CachedMaxDrawDistance                                     // 0x0314(0x0004)
unsigned char                                      DepthPriorityGroup                                        // 0x0318(0x0001)
unsigned char                                      ViewOwnerDepthPriorityGroup                               // 0x0319(0x0001)
ELightmapType                                      LightmapType                                              // 0x031A(0x0001)
EVLMOptimizeType                                   VLMOptimizeType                                           // 0x031B(0x0001)
Bool                                               bInstanceCulling                                          // 0x031C(0x0001)
EOverrideQueryMobilityType                         OverrideQueryMobilityType                                 // 0x031D(0x0001)
Bool                                               bUseAsPVSOC                                               // 0x031E(0x0001)
Bool                                               bUseDynamicPVS                                            // 0x031E(0x0001)
EFPCacheState                                      FramePredictionCacheState                                 // 0x031F(0x0001)
EFPCacheState                                      StaticSceneCacheState                                     // 0x0321(0x0001)
Bool                                               bForceInjectToHierarchicalSurfel                          // 0x0322(0x0001)
Bool                                               bForceUseStaticMovability                                 // 0x0322(0x0001)
Bool                                               bAffectSurfelGIWhenHidden                                 // 0x0322(0x0001)
Bool                                               bBulletCanBreakThrough                                    // 0x0323(0x0001)
Bool                                               bAlwaysCreatePhysicsState                                 // 0x0324(0x0001)
Bool                                               bGenerateOverlapEvents                                    // 0x0324(0x0001)
Bool                                               bUpdateOverlapEventsWhenMove                              // 0x0324(0x0001)
Bool                                               bForceUpdateOverlapEventsWhenMove                         // 0x0324(0x0001)
Bool                                               bUseSingleSweep                                           // 0x0324(0x0001)
Bool                                               bMultiBodyOverlap                                         // 0x0324(0x0001)
Bool                                               bCheckAsyncSceneOnMove                                    // 0x0324(0x0001)
Bool                                               bTraceComplexOnMove                                       // 0x0324(0x0001)
Bool                                               bReturnMaterialOnMove                                     // 0x0325(0x0001)
Bool                                               bUseViewOwnerDepthPriorityGroup                           // 0x0325(0x0001)
Bool                                               bAllowCullDistanceVolume                                  // 0x0325(0x0001)
Bool                                               bHasMotionBlurVelocityMeshes                              // 0x0325(0x0001)
Bool                                               bVisibleInReflectionCaptures                              // 0x0325(0x0001)
Bool                                               bRejectReflectionCapture                                  // 0x0325(0x0001)
Bool                                               bRenderInMainPass                                         // 0x0325(0x0001)
Bool                                               bForceRenderInShadowPass                                  // 0x0325(0x0001)
TArray<struct FName>                               HiddenInMainPassLocks                                     // 0x0328(0x0010)
Bool                                               bRenderInMono                                             // 0x0338(0x0001)
Bool                                               bReceivesDecals                                           // 0x0338(0x0001)
Bool                                               bOwnerNoSee                                               // 0x0338(0x0001)
Bool                                               bOnlyOwnerSee                                             // 0x0338(0x0001)
Bool                                               bTreatAsBackgroundForOcclusion                            // 0x0338(0x0001)
Bool                                               bDrawIdeaOutline                                          // 0x0338(0x0001)
Bool                                               bIdeaOutlineUseNormalInVertexColor                        // 0x0338(0x0001)
Bool                                               bIdeaOutlineUseOutlineMesh                                // 0x0338(0x0001)
Bool                                               bIdeaOutlineNew                                           // 0x0339(0x0001)
Bool                                               bIdeaOutlineOcclusionHighlight                            // 0x0339(0x0001)
Bool                                               bDisableWriteDepthForOcclusionHighlight                   // 0x0339(0x0001)
Bool                                               bIdeaOutlineNewUseBackFace                                // 0x0339(0x0001)
Bool                                               bIdeaOverrideOutlineAndOcclusion                          // 0x0339(0x0001)
Bool                                               bDrawIdeaOutlineInHighlightPass                           // 0x0339(0x0001)
struct FLinearColor                                IdeaOutlineOcclusionColor                                 // 0x033C(0x0010)
Bool                                               bOverrideIdeaOutlineColor                                 // 0x034C(0x0001)
Bool                                               bOverrideIdeaOutlineThickness                             // 0x034C(0x0001)
float                                              IdeaOutlineThickness                                      // 0x0350(0x0004)
struct FLinearColor                                IdeaOutlineColor                                          // 0x0354(0x0010)
Bool                                               bDrawHighlight                                            // 0x0364(0x0001)
Bool                                               bHighlightCanBeOccluded                                   // 0x0364(0x0001)
Bool                                               bOverrideHighlightColor                                   // 0x0364(0x0001)
struct FLinearColor                                HighlightColor                                            // 0x0368(0x0010)
EDrawDyeingMode                                    DrawDyeingMode                                            // 0x0378(0x0001)
struct FLinearColor                                VisibleDyeingColor                                        // 0x037C(0x0010)
struct FLinearColor                                OccludedDyeingColor                                       // 0x038C(0x0010)
Bool                                               bDrawDyeing                                               // 0x039C(0x0001)
Bool                                               bUseAsEarlyZ                                              // 0x039C(0x0001)
Bool                                               bRenderInTwoPass                                          // 0x039C(0x0001)
Bool                                               bTwoPassTranslucent                                       // 0x039C(0x0001)
Bool                                               bTranslucentDepthWrite                                    // 0x039C(0x0001)
Bool                                               bTranslucentDepthWriteInTwoPass                           // 0x039C(0x0001)
Bool                                               bForceIBL                                                 // 0x039C(0x0001)
Bool                                               bForceDisableIBL                                          // 0x039C(0x0001)
Bool                                               bForceDynamic                                             // 0x039D(0x0001)
int                                                ActiveScopeStatus                                         // 0x03A0(0x0004)
struct FVector                                     ScopeLocalTranslation                                     // 0x03A4(0x000C)
struct FRotator                                    ScopeLocalRotation                                        // 0x03B0(0x000C)
float                                              ScopeRadius                                               // 0x03BC(0x0004)
Bool                                               bIsFppLayer                                               // 0x03C0(0x0001)
Bool                                               bIsTppLayer                                               // 0x03C0(0x0001)
Bool                                               bUseAsOccluder                                            // 0x03C0(0x0001)
Bool                                            