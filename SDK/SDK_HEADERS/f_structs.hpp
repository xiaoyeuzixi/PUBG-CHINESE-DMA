// 大佬QQ:2396031563
// Function CoreUObject.Object.ExecuteUbergraph
// 0x0004
struct FExecuteUbergraph
{
int                                                EntryPoint                                                // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.Activate
// 0x0001
struct FActivate
{
Bool                                               bReset                                                    // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.AddTickPrerequisiteActor
// 0x0008
struct FAddTickPrerequisiteActor
{
class AActor*                                      PrerequisiteActor                                         // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.AddTickPrerequisiteComponent
// 0x0008
struct FAddTickPrerequisiteComponent
{
class UActorComponent*                             PrerequisiteComponent                                     // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.CallSubObjectLuaOnRep
// 0x0008
struct FCallSubObjectLuaOnRep
{
class UObject*                                     InObject                                                  // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.ClientSendScriptNetworkRemoteContent
// 0x0018
struct FClientSendScriptNetworkRemoteContent
{
struct FScriptNetworkRemoteContent                 Content                                                   // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.ClientSendScriptNetworkRemoteContent_Unreliable
// 0x0018
struct FClientSendScriptNetworkRemoteContent_Unreliable
{
struct FScriptNetworkRemoteContent                 Content                                                   // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.ComponentHasTag
// 0x0010
struct FComponentHasTag
{
struct FName                                       Tag                                                       // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.GetComponentTickInterval
// 0x0004
struct FGetComponentTickInterval
{
float                                              ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.GetOwner
// 0x0008
struct FGetOwner
{
class AActor*                                      ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.GetToString
// 0x0010
struct FGetToString
{
struct FString                                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.IsActive
// 0x0001
struct FIsActive
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.IsBeingDestroyed
// 0x0001
struct FIsBeingDestroyed
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.IsComponentTickEnabled
// 0x0001
struct FIsComponentTickEnabled
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.IsComponentTickEnabledByExternal
// 0x0001
struct FIsComponentTickEnabledByExternal
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.K2_DestroyComponent
// 0x0008
struct FK2_DestroyComponent
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.ReceiveEndPlay
// 0x0001
struct FReceiveEndPlay
{
unsigned char                                      EndPlayReason                                             // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.ReceiveScriptNetworkRemoteContent
// 0x0018
struct FReceiveScriptNetworkRemoteContent
{
struct FScriptNetworkRemoteContent                 Content                                                   // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.ReceiveTick
// 0x0004
struct FReceiveTick
{
float                                              DeltaSeconds                                              // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.RemoveTickPrerequisiteActor
// 0x0008
struct FRemoveTickPrerequisiteActor
{
class AActor*                                      PrerequisiteActor                                         // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.RemoveTickPrerequisiteComponent
// 0x0008
struct FRemoveTickPrerequisiteComponent
{
class UActorComponent*                             PrerequisiteComponent                                     // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.ServerSendScriptNetworkRemoteContent
// 0x0018
struct FServerSendScriptNetworkRemoteContent
{
struct FScriptNetworkRemoteContent                 Content                                                   // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.ServerSendScriptNetworkRemoteContent_Unreliable
// 0x0018
struct FServerSendScriptNetworkRemoteContent_Unreliable
{
struct FScriptNetworkRemoteContent                 Content                                                   // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.SetActive
// 0x0002
struct FSetActive
{
Bool                                               bNewActive                                                // 0x0000(0x0001)
Bool                                               bReset                                                    // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.SetAutoActivate
// 0x0001
struct FSetAutoActivate
{
Bool                                               bNewAutoActivate                                          // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.SetComponentTickEnabled
// 0x0001
struct FSetComponentTickEnabled
{
Bool                                               bEnabled                                                  // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.SetComponentTickInterval
// 0x0004
struct FSetComponentTickInterval
{
float                                              TickInterval                                              // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.SetIsReplicated
// 0x0001
struct FSetIsReplicated
{
Bool                                               ShouldReplicate                                           // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.SetTickableWhenPaused
// 0x0001
struct FSetTickableWhenPaused
{
Bool                                               bTickableWhenPaused                                       // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.ActorComponent.SetTickGroup
// 0x0001
struct FSetTickGroup
{
unsigned char                                      NewTickGroup                                              // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.DetachFromParent
// 0x0002
struct FDetachFromParent
{
Bool                                               bMaintainWorldPosition                                    // 0x0000(0x0001)
Bool                                               bCallModify                                               // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.DoesSocketExist
// 0x0010
struct FDoesSocketExist
{
struct FName                                       InSocketName                                              // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.GetAllSocketNames
// 0x0010
struct FGetAllSocketNames
{
TArray<struct FName>                               ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.GetAttachParent
// 0x0008
struct FGetAttachParent
{
class USceneComponent*                             ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.GetAttachSocketName
// 0x0008
struct FGetAttachSocketName
{
struct FName                                       ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.GetBoundsBoxExtent
// 0x000C
struct FGetBoundsBoxExtent
{
struct FVector                                     ReturnValue                                               // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.GetBoundsOirgin
// 0x000C
struct FGetBoundsOirgin
{
struct FVector                                     ReturnValue                                               // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.GetChildComponent
// 0x0010
struct FGetChildComponent
{
int                                                ChildIndex                                                // 0x0000(0x0004)
class USceneComponent*                             ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.GetChildrenComponents
// 0x0018
struct FGetChildrenComponents
{
Bool                                               bIncludeAllDescendants                                    // 0x0000(0x0001)
TArray<class USceneComponent*>                     Children                                                  // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.GetComponentLocal
// 0x0060
struct FGetComponentLocal
{
struct FTransform                                  LocalTransform                                            // 0x0000(0x0030)
struct FTransform                                  ReturnValue                                               // 0x0030(0x0030)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.GetComponentTransformViewTranslatedBP
// 0x0030
struct FGetComponentTransformViewTranslatedBP
{
struct FTransform                                  ReturnValue                                               // 0x0000(0x0030)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.GetComponentVelocity
// 0x000C
struct FGetComponentVelocity
{
struct FVector                                     ReturnValue                                               // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.GetForwardVector
// 0x000C
struct FGetForwardVector
{
struct FVector                                     ReturnValue                                               // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.GetNumChildrenComponents
// 0x0004
struct FGetNumChildrenComponents
{
int                                                ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.GetParentComponents
// 0x0010
struct FGetParentComponents
{
TArray<class USceneComponent*>                     Parents                                                   // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.GetPhysicsVolume
// 0x0008
struct FGetPhysicsVolume
{
class APhysicsVolume*                              ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.GetRelativeTransform
// 0x0030
struct FGetRelativeTransform
{
struct FTransform                                  ReturnValue                                               // 0x0000(0x0030)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.GetRightVector
// 0x000C
struct FGetRightVector
{
struct FVector                                     ReturnValue                                               // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.GetSocketLocation
// 0x0018
struct FGetSocketLocation
{
struct FName                                       InSocketName                                              // 0x0000(0x0008)
struct FVector                                     ReturnValue                                               // 0x0008(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.GetSocketQuaternion
// 0x0020
struct FGetSocketQuaternion
{
struct FName                                       InSocketName                                              // 0x0000(0x0008)
struct FQuat                                       ReturnValue                                               // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.GetSocketRotation
// 0x0018
struct FGetSocketRotation
{
struct FName                                       InSocketName                                              // 0x0000(0x0008)
struct FRotator                                    ReturnValue                                               // 0x0008(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.GetSocketScale
// 0x0018
struct FGetSocketScale
{
struct FName                                       InSocketName                                              // 0x0000(0x0008)
struct FVector                                     ReturnValue                                               // 0x0008(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.GetSocketTransform
// 0x0040
struct FGetSocketTransform
{
struct FName                                       InSocketName                                              // 0x0000(0x0008)
unsigned char                                      TransformSpace                                            // 0x0008(0x0001)
struct FTransform                                  ReturnValue                                               // 0x0010(0x0030)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.GetUpVector
// 0x000C
struct FGetUpVector
{
struct FVector                                     ReturnValue                                               // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.IsAbsoluteLocation
// 0x0002
struct FIsAbsoluteLocation
{
Bool                                               ContainsParent                                            // 0x0000(0x0001)
Bool                                               ReturnValue                                               // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.IsAnySimulatingPhysics
// 0x0001
struct FIsAnySimulatingPhysics
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.IsForceFrameInterpolate
// 0x0001
struct FIsForceFrameInterpolate
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.IsSimulatingPhysics
// 0x0010
struct FIsSimulatingPhysics
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.IsVisible
// 0x0001
struct FIsVisible
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_AddLocalOffset
// 0x00A0
struct FK2_AddLocalOffset
{
struct FVector                                     DeltaLocation                                             // 0x0000(0x000C)
Bool                                               bSweep                                                    // 0x000C(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0010(0x0088)
Bool                                               bTeleport                                                 // 0x0098(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_AddLocalRotation
// 0x00A0
struct FK2_AddLocalRotation
{
struct FRotator                                    DeltaRotation                                             // 0x0000(0x000C)
Bool                                               bSweep                                                    // 0x000C(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0010(0x0088)
Bool                                               bTeleport                                                 // 0x0098(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_AddLocalTransform
// 0x00D0
struct FK2_AddLocalTransform
{
struct FTransform                                  DeltaTransform                                            // 0x0000(0x0030)
Bool                                               bSweep                                                    // 0x0030(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0038(0x0088)
Bool                                               bTeleport                                                 // 0x00C0(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_AddRelativeLocation
// 0x00A0
struct FK2_AddRelativeLocation
{
struct FVector                                     DeltaLocation                                             // 0x0000(0x000C)
Bool                                               bSweep                                                    // 0x000C(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0010(0x0088)
Bool                                               bTeleport                                                 // 0x0098(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_AddRelativeRotation
// 0x00A0
struct FK2_AddRelativeRotation
{
struct FRotator                                    DeltaRotation                                             // 0x0000(0x000C)
Bool                                               bSweep                                                    // 0x000C(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0010(0x0088)
Bool                                               bTeleport                                                 // 0x0098(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_AddWorldOffset
// 0x00A0
struct FK2_AddWorldOffset
{
struct FVector                                     DeltaLocation                                             // 0x0000(0x000C)
Bool                                               bSweep                                                    // 0x000C(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0010(0x0088)
Bool                                               bTeleport                                                 // 0x0098(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_AddWorldRotation
// 0x00A0
struct FK2_AddWorldRotation
{
struct FRotator                                    DeltaRotation                                             // 0x0000(0x000C)
Bool                                               bSweep                                                    // 0x000C(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0010(0x0088)
Bool                                               bTeleport                                                 // 0x0098(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_AddWorldTransform
// 0x00D0
struct FK2_AddWorldTransform
{
struct FTransform                                  DeltaTransform                                            // 0x0000(0x0030)
Bool                                               bSweep                                                    // 0x0030(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0038(0x0088)
Bool                                               bTeleport                                                 // 0x00C0(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_AttachTo
// 0x0018
struct FK2_AttachTo
{
class USceneComponent*                             InParent                                                  // 0x0000(0x0008)
struct FName                                       InSocketName                                              // 0x0008(0x0008)
unsigned char                                      AttachType                                                // 0x0010(0x0001)
Bool                                               bWeldSimulatedBodies                                      // 0x0011(0x0001)
Bool                                               ReturnValue                                               // 0x0012(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_AttachToComponent
// 0x0018
struct FK2_AttachToComponent
{
class USceneComponent*                             Parent                                                    // 0x0000(0x0008)
struct FName                                       SocketName                                                // 0x0008(0x0008)
EAttachmentRule                                    LocationRule                                              // 0x0010(0x0001)
EAttachmentRule                                    RotationRule                                              // 0x0011(0x0001)
EAttachmentRule                                    ScaleRule                                                 // 0x0012(0x0001)
Bool                                               bWeldSimulatedBodies                                      // 0x0013(0x0001)
Bool                                               ReturnValue                                               // 0x0014(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_DetachFromComponent
// 0x0004
struct FK2_DetachFromComponent
{
EDetachmentRule                                    LocationRule                                              // 0x0000(0x0001)
EDetachmentRule                                    RotationRule                                              // 0x0001(0x0001)
EDetachmentRule                                    ScaleRule                                                 // 0x0002(0x0001)
Bool                                               bCallModify                                               // 0x0003(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_GetComponentLocation
// 0x000C
struct FK2_GetComponentLocation
{
struct FVector                                     ReturnValue                                               // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_GetComponentRotation
// 0x000C
struct FK2_GetComponentRotation
{
struct FRotator                                    ReturnValue                                               // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_GetComponentScale
// 0x000C
struct FK2_GetComponentScale
{
struct FVector                                     ReturnValue                                               // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_GetComponentToWorld
// 0x0030
struct FK2_GetComponentToWorld
{
struct FTransform                                  ReturnValue                                               // 0x0000(0x0030)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_SetMobility
// 0x0001
struct FK2_SetMobility
{
unsigned char                                      NewMobility                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_SetRelativeLocation
// 0x00A0
struct FK2_SetRelativeLocation
{
struct FVector                                     NewLocation                                               // 0x0000(0x000C)
Bool                                               bSweep                                                    // 0x000C(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0010(0x0088)
Bool                                               bTeleport                                                 // 0x0098(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_SetRelativeLocationAndRotation
// 0x00B0
struct FK2_SetRelativeLocationAndRotation
{
struct FVector                                     NewLocation                                               // 0x0000(0x000C)
struct FRotator                                    NewRotation                                               // 0x000C(0x000C)
Bool                                               bSweep                                                    // 0x0018(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0020(0x0088)
Bool                                               bTeleport                                                 // 0x00A8(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_SetRelativeRotation
// 0x00A0
struct FK2_SetRelativeRotation
{
struct FRotator                                    NewRotation                                               // 0x0000(0x000C)
Bool                                               bSweep                                                    // 0x000C(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0010(0x0088)
Bool                                               bTeleport                                                 // 0x0098(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_SetRelativeTransform
// 0x00D0
struct FK2_SetRelativeTransform
{
struct FTransform                                  NewTransform                                              // 0x0000(0x0030)
Bool                                               bSweep                                                    // 0x0030(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0038(0x0088)
Bool                                               bTeleport                                                 // 0x00C0(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_SetWorldLocation
// 0x00A0
struct FK2_SetWorldLocation
{
struct FVector                                     NewLocation                                               // 0x0000(0x000C)
Bool                                               bSweep                                                    // 0x000C(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0010(0x0088)
Bool                                               bTeleport                                                 // 0x0098(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_SetWorldLocationAndRotation
// 0x00B0
struct FK2_SetWorldLocationAndRotation
{
struct FVector                                     NewLocation                                               // 0x0000(0x000C)
struct FRotator                                    NewRotation                                               // 0x000C(0x000C)
Bool                                               bSweep                                                    // 0x0018(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0020(0x0088)
Bool                                               bTeleport                                                 // 0x00A8(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_SetWorldRotation
// 0x00A0
struct FK2_SetWorldRotation
{
struct FRotator                                    NewRotation                                               // 0x0000(0x000C)
Bool                                               bSweep                                                    // 0x000C(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0010(0x0088)
Bool                                               bTeleport                                                 // 0x0098(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.K2_SetWorldTransform
// 0x00D0
struct FK2_SetWorldTransform
{
struct FTransform                                  NewTransform                                              // 0x0000(0x0030)
Bool                                               bSweep                                                    // 0x0030(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0038(0x0088)
Bool                                               bTeleport                                                 // 0x00C0(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.OnRep_Visibility
// 0x0001
struct FOnRep_Visibility
{
Bool                                               OldValue                                                  // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.SetAbsolute
// 0x0003
struct FSetAbsolute
{
Bool                                               bNewAbsoluteLocation                                      // 0x0000(0x0001)
Bool                                               bNewAbsoluteRotation                                      // 0x0001(0x0001)
Bool                                               bNewAbsoluteScale                                         // 0x0002(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.SetDisableFppLayerRecursive
// 0x0001
struct FSetDisableFppLayerRecursive
{
Bool                                               bDisable                                                  // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.SetForceFrameInterpolate
// 0x0001
struct FSetForceFrameInterpolate
{
Bool                                               InForceFrameInterpolate                                   // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.SetFppLayerRecursive
// 0x0001
struct FSetFppLayerRecursive
{
Bool                                               InIsFppLayer                                              // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.SetHiddenInGame
// 0x0002
struct FSetHiddenInGame
{
Bool                                               NewHidden                                                 // 0x0000(0x0001)
Bool                                               bPropagateToChildren                                      // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.SetRelativeScale3D
// 0x000C
struct FSetRelativeScale3D
{
struct FVector                                     NewScale3D                                                // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.SetVisibility
// 0x0003
struct FSetVisibility
{
Bool                                               bNewVisibility                                            // 0x0000(0x0001)
Bool                                               bPropagateToChildren                                      // 0x0001(0x0001)
Bool                                               bForceNoPropagate                                         // 0x0002(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.SetWorldScale3D
// 0x000C
struct FSetWorldScale3D
{
struct FVector                                     NewScale                                                  // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.SnapTo
// 0x0018
struct FSnapTo
{
class USceneComponent*                             InParent                                                  // 0x0000(0x0008)
struct FName                                       InSocketName                                              // 0x0008(0x0008)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SceneComponent.ToggleVisibility
// 0x0001
struct FToggleVisibility
{
Bool                                               bPropagateToChildren                                      // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.AddAngularImpulse
// 0x0020
struct FAddAngularImpulse
{
struct FVector                                     Impulse                                                   // 0x0000(0x000C)
struct FName                                       BoneName                                                  // 0x0010(0x0008)
Bool                                               bVelChange                                                // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.AddAngularImpulseInDegrees
// 0x0020
struct FAddAngularImpulseInDegrees
{
struct FVector                                     Impulse                                                   // 0x0000(0x000C)
struct FName                                       BoneName                                                  // 0x0010(0x0008)
Bool                                               bVelChange                                                // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.AddAngularImpulseInRadians
// 0x0020
struct FAddAngularImpulseInRadians
{
struct FVector                                     Impulse                                                   // 0x0000(0x000C)
struct FName                                       BoneName                                                  // 0x0010(0x0008)
Bool                                               bVelChange                                                // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.AddForce
// 0x0020
struct FAddForce
{
struct FVector                                     Force                                                     // 0x0000(0x000C)
struct FName                                       BoneName                                                  // 0x0010(0x0008)
Bool                                               bAccelChange                                              // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.AddForce_AssumesLocked
// 0x0020
struct FAddForce_AssumesLocked
{
struct FVector                                     Force                                                     // 0x0000(0x000C)
struct FName                                       BoneName                                                  // 0x0010(0x0008)
Bool                                               bAccelChange                                              // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.AddForceAtLocation
// 0x0020
struct FAddForceAtLocation
{
struct FVector                                     Force                                                     // 0x0000(0x000C)
struct FVector                                     Location                                                  // 0x000C(0x000C)
struct FName                                       BoneName                                                  // 0x0018(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.AddForceAtLocation_AssumesLocked
// 0x0020
struct FAddForceAtLocation_AssumesLocked
{
struct FVector                                     Force                                                     // 0x0000(0x000C)
struct FVector                                     Location                                                  // 0x000C(0x000C)
struct FName                                       BoneName                                                  // 0x0018(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.AddForceAtLocationLocal
// 0x0020
struct FAddForceAtLocationLocal
{
struct FVector                                     Force                                                     // 0x0000(0x000C)
struct FVector                                     Location                                                  // 0x000C(0x000C)
struct FName                                       BoneName                                                  // 0x0018(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.AddImpulse
// 0x0020
struct FAddImpulse
{
struct FVector                                     Impulse                                                   // 0x0000(0x000C)
struct FName                                       BoneName                                                  // 0x0010(0x0008)
Bool                                               bVelChange                                                // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.AddImpulseAtLocation
// 0x0020
struct FAddImpulseAtLocation
{
struct FVector                                     Impulse                                                   // 0x0000(0x000C)
struct FVector                                     Location                                                  // 0x000C(0x000C)
struct FName                                       BoneName                                                  // 0x0018(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.AddRadialForce
// 0x0018
struct FAddRadialForce
{
struct FVector                                     Origin                                                    // 0x0000(0x000C)
float                                              Radius                                                    // 0x000C(0x0004)
float                                              Strength                                                  // 0x0010(0x0004)
unsigned char                                      Falloff                                                   // 0x0014(0x0001)
Bool                                               bAccelChange                                              // 0x0015(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.AddRadialImpulse
// 0x0018
struct FAddRadialImpulse
{
struct FVector                                     Origin                                                    // 0x0000(0x000C)
float                                              Radius                                                    // 0x000C(0x0004)
float                                              Strength                                                  // 0x0010(0x0004)
unsigned char                                      Falloff                                                   // 0x0014(0x0001)
Bool                                               bVelChange                                                // 0x0015(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.AddTorque
// 0x0020
struct FAddTorque
{
struct FVector                                     Torque                                                    // 0x0000(0x000C)
struct FName                                       BoneName                                                  // 0x0010(0x0008)
Bool                                               bAccelChange                                              // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.AddTorqueInDegrees
// 0x0020
struct FAddTorqueInDegrees
{
struct FVector                                     Torque                                                    // 0x0000(0x000C)
struct FName                                       BoneName                                                  // 0x0010(0x0008)
Bool                                               bAccelChange                                              // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.AddTorqueInDegrees_AssumesLocked
// 0x0020
struct FAddTorqueInDegrees_AssumesLocked
{
struct FVector                                     Torque                                                    // 0x0000(0x000C)
struct FName                                       BoneName                                                  // 0x0010(0x0008)
Bool                                               bAccelChange                                              // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.AddTorqueInRadians
// 0x0020
struct FAddTorqueInRadians
{
struct FVector                                     Torque                                                    // 0x0000(0x000C)
struct FName                                       BoneName                                                  // 0x0010(0x0008)
Bool                                               bAccelChange                                              // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.AddTorqueInRadians_AssumesLocked
// 0x0020
struct FAddTorqueInRadians_AssumesLocked
{
struct FVector                                     Torque                                                    // 0x0000(0x000C)
struct FName                                       BoneName                                                  // 0x0010(0x0008)
Bool                                               bAccelChange                                              // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.CanCharacterStepUp
// 0x0010
struct FCanCharacterStepUp
{
class APawn*                                       Pawn                                                      // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.CopyArrayOfMoveIgnoreActors
// 0x0010
struct FCopyArrayOfMoveIgnoreActors
{
TArray<class AActor*>                              ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.CopyArrayOfMoveIgnoreComponents
// 0x0010
struct FCopyArrayOfMoveIgnoreComponents
{
TArray<class UPrimitiveComponent*>                 ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.CreateAndSetMaterialInstanceDynamic
// 0x0010
struct FCreateAndSetMaterialInstanceDynamic
{
int                                                ElementIndex                                              // 0x0000(0x0004)
class UMaterialInstanceDynamic*                    ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.CreateAndSetMaterialInstanceDynamicFromMaterial
// 0x0018
struct FCreateAndSetMaterialInstanceDynamicFromMaterial
{
int                                                ElementIndex                                              // 0x0000(0x0004)
class UMaterialInterface*                          Parent                                                    // 0x0008(0x0008)
class UMaterialInstanceDynamic*                    ReturnValue                                               // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.CreateDynamicMaterialInstance
// 0x0018
struct FCreateDynamicMaterialInstance
{
int                                                ElementIndex                                              // 0x0000(0x0004)
class UMaterialInterface*                          SourceMaterial                                            // 0x0008(0x0008)
class UMaterialInstanceDynamic*                    ReturnValue                                               // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetAngularDamping
// 0x0004
struct FGetAngularDamping
{
float                                              ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetBoundsScale
// 0x0004
struct FGetBoundsScale
{
float                                              ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetCenterOfMass
// 0x0018
struct FGetCenterOfMass
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
struct FVector                                     ReturnValue                                               // 0x0008(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetClosestPointOnCollision
// 0x0028
struct FGetClosestPointOnCollision
{
struct FVector                                     Point                                                     // 0x0000(0x000C)
struct FVector                                     OutPointOnBody                                            // 0x000C(0x000C)
struct FName                                       BoneName                                                  // 0x0018(0x0008)
float                                              ReturnValue                                               // 0x0020(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetCollisionEnabled
// 0x0001
struct FGetCollisionEnabled
{
unsigned char                                      ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetCollisionObjectType
// 0x0001
struct FGetCollisionObjectType
{
unsigned char                                      ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetCollisionProfileName
// 0x0008
struct FGetCollisionProfileName
{
struct FName                                       ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetCollisionResponseToChannel
// 0x0002
struct FGetCollisionResponseToChannel
{
unsigned char                                      Channel                                                   // 0x0000(0x0001)
unsigned char                                      ReturnValue                                               // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetInertiaTensor
// 0x0018
struct FGetInertiaTensor
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
struct FVector                                     ReturnValue                                               // 0x0008(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetLinearDamping
// 0x0004
struct FGetLinearDamping
{
float                                              ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetMass
// 0x0004
struct FGetMass
{
float                                              ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetMassScale
// 0x0010
struct FGetMassScale
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
float                                              ReturnValue                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetMaterial
// 0x0010
struct FGetMaterial
{
int                                                ElementIndex                                              // 0x0000(0x0004)
class UMaterialInterface*                          ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetMaterialFromCollisionFaceIndex
// 0x0010
struct FGetMaterialFromCollisionFaceIndex
{
int                                                FaceIndex                                                 // 0x0000(0x0004)
int                                                SectionIndex                                              // 0x0004(0x0004)
class UMaterialInterface*                          ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetNumMaterials
// 0x0004
struct FGetNumMaterials
{
int                                                ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetOverlappingActors
// 0x0018
struct FGetOverlappingActors
{
TArray<class AActor*>                              OverlappingActors                                         // 0x0000(0x0010)
class UClass*                                      ClassFilter                                               // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetOverlappingComponents
// 0x0010
struct FGetOverlappingComponents
{
TArray<class UPrimitiveComponent*>                 InOverlappingComponents                                   // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetPhysicsAngularVelocity
// 0x0018
struct FGetPhysicsAngularVelocity
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
struct FVector                                     ReturnValue                                               // 0x0008(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetPhysicsAngularVelocity_AssumesLocked
// 0x0018
struct FGetPhysicsAngularVelocity_AssumesLocked
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
struct FVector                                     ReturnValue                                               // 0x0008(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetPhysicsAngularVelocityInDegrees
// 0x0018
struct FGetPhysicsAngularVelocityInDegrees
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
struct FVector                                     ReturnValue                                               // 0x0008(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetPhysicsAngularVelocityInDegrees_AssumesLocked
// 0x0018
struct FGetPhysicsAngularVelocityInDegrees_AssumesLocked
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
struct FVector                                     ReturnValue                                               // 0x0008(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetPhysicsAngularVelocityInRadians
// 0x0018
struct FGetPhysicsAngularVelocityInRadians
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
struct FVector                                     ReturnValue                                               // 0x0008(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetPhysicsAngularVelocityInRadians_AssumesLocked
// 0x0018
struct FGetPhysicsAngularVelocityInRadians_AssumesLocked
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
struct FVector                                     ReturnValue                                               // 0x0008(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetPhysicsLinearVelocity
// 0x0018
struct FGetPhysicsLinearVelocity
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
struct FVector                                     ReturnValue                                               // 0x0008(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetPhysicsLinearVelocity_AssumesLocked
// 0x0018
struct FGetPhysicsLinearVelocity_AssumesLocked
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
struct FVector                                     ReturnValue                                               // 0x0008(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetPhysicsLinearVelocityAtPoint
// 0x0028
struct FGetPhysicsLinearVelocityAtPoint
{
struct FVector                                     Point                                                     // 0x0000(0x000C)
struct FName                                       BoneName                                                  // 0x0010(0x0008)
struct FVector                                     ReturnValue                                               // 0x0018(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetPhysMaterial
// 0x0010
struct FGetPhysMaterial
{
int                                                Item                                                      // 0x0000(0x0004)
class UPhysicalMaterial*                           ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.GetWalkableSlopeOverride
// 0x0010
struct FGetWalkableSlopeOverride
{
struct FWalkableSlopeOverride                      ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.IgnoreActorWhenMoving
// 0x0010
struct FIgnoreActorWhenMoving
{
class AActor*                                      Actor                                                     // 0x0000(0x0008)
Bool                                               bShouldIgnore                                             // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.IgnoreComponentWhenMoving
// 0x0010
struct FIgnoreComponentWhenMoving
{
class UPrimitiveComponent*                         Component                                                 // 0x0000(0x0008)
Bool                                               bShouldIgnore                                             // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.IsActiveScope
// 0x0001
struct FIsActiveScope
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.IsAnyRigidBodyAwake
// 0x0001
struct FIsAnyRigidBodyAwake
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.IsComponentDeviceQualityEnough
// 0x0001
struct FIsComponentDeviceQualityEnough
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.IsComponentRenderQualityEnough
// 0x0001
struct FIsComponentRenderQualityEnough
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.IsForceDynamic
// 0x0001
struct FIsForceDynamic
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.IsGravityEnabled
// 0x0001
struct FIsGravityEnabled
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.IsOverlappingActor
// 0x0010
struct FIsOverlappingActor
{
class AActor*                                      Other                                                     // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.IsOverlappingComponent
// 0x0010
struct FIsOverlappingComponent
{
class UPrimitiveComponent*                         OtherComp                                                 // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.IsRenderInMainPass
// 0x0001
struct FIsRenderInMainPass
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.K2_IsCollisionEnabled
// 0x0001
struct FK2_IsCollisionEnabled
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.K2_IsPhysicsCollisionEnabled
// 0x0001
struct FK2_IsPhysicsCollisionEnabled
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.K2_IsQueryCollisionEnabled
// 0x0001
struct FK2_IsQueryCollisionEnabled
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.K2_LineTraceComponent
// 0x00D0
struct FK2_LineTraceComponent
{
struct FVector                                     TraceStart                                                // 0x0000(0x000C)
struct FVector                                     TraceEnd                                                  // 0x000C(0x000C)
Bool                                               bTraceComplex                                             // 0x0018(0x0001)
Bool                                               bShowTrace                                                // 0x0019(0x0001)
struct FVector                                     HitLocation                                               // 0x001C(0x000C)
struct FVector                                     HitNormal                                                 // 0x0028(0x000C)
struct FName                                       BoneName                                                  // 0x0038(0x0008)
struct FHitResult                                  OutHit                                                    // 0x0040(0x0088)
Bool                                               ReturnValue                                               // 0x00C8(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.OverrideHighlightColor
// 0x0014
struct FOverrideHighlightColor
{
Bool                                               bOverride                                                 // 0x0000(0x0001)
struct FLinearColor                                InHighlightColor                                          // 0x0004(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.OverrideIdeaOutlineColor
// 0x0014
struct FOverrideIdeaOutlineColor
{
Bool                                               bOverride                                                 // 0x0000(0x0001)
struct FLinearColor                                InOutlineColor                                            // 0x0004(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.OverrideIdeaOutlineThickness
// 0x0008
struct FOverrideIdeaOutlineThickness
{
Bool                                               bOverride                                                 // 0x0000(0x0001)
float                                              InThickness                                               // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.PutRigidBodyToSleep
// 0x0008
struct FPutRigidBodyToSleep
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.ScaleByMomentOfInertia
// 0x0028
struct FScaleByMomentOfInertia
{
struct FVector                                     InputVector                                               // 0x0000(0x000C)
struct FName                                       BoneName                                                  // 0x0010(0x0008)
struct FVector                                     ReturnValue                                               // 0x0018(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetActiveScope
// 0x0001
struct FSetActiveScope
{
Bool                                               InIsActiveScope                                           // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetAllMassScale
// 0x0004
struct FSetAllMassScale
{
float                                              InMassScale                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetAllPhysicsAngularVelocity
// 0x0010
struct FSetAllPhysicsAngularVelocity
{
struct FVector                                     NewAngVel                                                 // 0x0000(0x000C)
Bool                                               bAddToCurrent                                             // 0x000C(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetAllPhysicsAngularVelocityInDegrees
// 0x0010
struct FSetAllPhysicsAngularVelocityInDegrees
{
struct FVector                                     NewAngVel                                                 // 0x0000(0x000C)
Bool                                               bAddToCurrent                                             // 0x000C(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetAllPhysicsAngularVelocityInRadians
// 0x0010
struct FSetAllPhysicsAngularVelocityInRadians
{
struct FVector                                     NewAngVel                                                 // 0x0000(0x000C)
Bool                                               bAddToCurrent                                             // 0x000C(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetAllPhysicsLinearVelocity
// 0x0010
struct FSetAllPhysicsLinearVelocity
{
struct FVector                                     NewVel                                                    // 0x0000(0x000C)
Bool                                               bAddToCurrent                                             // 0x000C(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetAngularDamping
// 0x0004
struct FSetAngularDamping
{
float                                              InDamping                                                 // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetBoundsScale
// 0x0004
struct FSetBoundsScale
{
float                                              NewBoundsScale                                            // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetCastInsetShadow
// 0x0001
struct FSetCastInsetShadow
{
Bool                                               bInCastInsetShadow                                        // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetCastPhotonShadow
// 0x0001
struct FSetCastPhotonShadow
{
Bool                                               bNewCastPhotonShadow                                      // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetCastShadow
// 0x0001
struct FSetCastShadow
{
Bool                                               NewCastShadow                                             // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetCenterOfMass
// 0x0018
struct FSetCenterOfMass
{
struct FVector                                     CenterOfMassOffset                                        // 0x0000(0x000C)
struct FName                                       BoneName                                                  // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetCollisionEnabled
// 0x0001
struct FSetCollisionEnabled
{
unsigned char                                      NewType                                                   // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetCollisionObjectType
// 0x0001
struct FSetCollisionObjectType
{
unsigned char                                      Channel                                                   // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetCollisionProfileName
// 0x0008
struct FSetCollisionProfileName
{
struct FName                                       InCollisionProfileName                                    // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetCollisionResponseToAllChannels
// 0x0001
struct FSetCollisionResponseToAllChannels
{
unsigned char                                      NewResponse                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetCollisionResponseToChannel
// 0x0002
struct FSetCollisionResponseToChannel
{
unsigned char                                      Channel                                                   // 0x0000(0x0001)
unsigned char                                      NewResponse                                               // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetConstraintMode
// 0x0001
struct FSetConstraintMode
{
unsigned char                                      ConstraintMode                                            // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetCullDistance
// 0x0008
struct FSetCullDistance
{
float                                              NewCullDistance                                           // 0x0000(0x0004)
Bool                                               EnableIncrease                                            // 0x0004(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetCustomDepthStencilValue
// 0x0004
struct FSetCustomDepthStencilValue
{
int                                                Value                                                     // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetCustomDepthStencilWriteMask
// 0x0001
struct FSetCustomDepthStencilWriteMask
{
ERendererStencilMask                               WriteMaskBit                                              // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetDisableWriteDepthForOcclusionHighlight
// 0x0001
struct FSetDisableWriteDepthForOcclusionHighlight
{
Bool                                               bDisable                                                  // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetDrawDyeing
// 0x0001
struct FSetDrawDyeing
{
Bool                                               bNewDrawOutline                                           // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetDrawDyeingMode
// 0x0001
struct FSetDrawDyeingMode
{
EDrawDyeingMode                                    InDrawDyeingMode                                          // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetDrawHighlight
// 0x0001
struct FSetDrawHighlight
{
Bool                                               bNewDrawHighlight                                         // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetDrawIdeaOutline
// 0x0001
struct FSetDrawIdeaOutline
{
Bool                                               bNewDrawOutline                                           // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetDrawIdeaOutlineInHighlightPass
// 0x0001
struct FSetDrawIdeaOutlineInHighlightPass
{
Bool                                               bHighlight                                                // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetEnableGravity
// 0x0001
struct FSetEnableGravity
{
Bool                                               bGravityEnabled                                           // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetForceDisableIBL
// 0x0001
struct FSetForceDisableIBL
{
Bool                                               InForceDisableIBL                                         // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetForceDynamic
// 0x0001
struct FSetForceDynamic
{
Bool                                               InForceDynamic                                            // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetForceIBL
// 0x0001
struct FSetForceIBL
{
Bool                                               InForceIBL                                                // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetFppLayer
// 0x0001
struct FSetFppLayer
{
Bool                                               InIsFppLayer                                              // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetHighlightCanBeOccluded
// 0x0001
struct FSetHighlightCanBeOccluded
{
Bool                                               bInCanBeOccluded                                          // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetIdeaOutline_UGC
// 0x0001
struct FSetIdeaOutline_UGC
{
Bool                                               bDrawOutline                                              // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetIdeaOutlineNew
// 0x0001
struct FSetIdeaOutlineNew
{
Bool                                               bNew                                                      // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetIdeaOutlineNewUseBackFace
// 0x0001
struct FSetIdeaOutlineNewUseBackFace
{
Bool                                               bUseBackFace                                              // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetIdeaOutlineOcclusionColor
// 0x0010
struct FSetIdeaOutlineOcclusionColor
{
struct FLinearColor                                InOcclusionColor                                          // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetIdeaOutlineOcclusionHighlight
// 0x0001
struct FSetIdeaOutlineOcclusionHighlight
{
Bool                                               bOcclusionHighlight                                       // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetIdeaOutlineOcclusionHighlight_UGC
// 0x0001
struct FSetIdeaOutlineOcclusionHighlight_UGC
{
Bool                                               bOcclusionHighlight                                       // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetIdeaOutlineUseNormalInVertexColor
// 0x0001
struct FSetIdeaOutlineUseNormalInVertexColor
{
Bool                                               bNewUseNormalInVertexColor                                // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetIdeaOutlineUseOutlineMesh
// 0x0001
struct FSetIdeaOutlineUseOutlineMesh
{
Bool                                               bUseOutlineMesh                                           // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetIdeaOverrideOutlineAndOcclusion
// 0x0001
struct FSetIdeaOverrideOutlineAndOcclusion
{
Bool                                               bOutlineAndOcclusion                                      // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetLightAttachmentsAsGroup
// 0x0001
struct FSetLightAttachmentsAsGroup
{
Bool                                               bInLightAttachmentsAsGroup                                // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetLightingChannels
// 0x0003
struct FSetLightingChannels
{
Bool                                               bChannel0Open                                             // 0x0000(0x0001)
Bool                                               bChannel1Open                                             // 0x0001(0x0001)
Bool                                               bChannel2Open                                             // 0x0002(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetLinearDamping
// 0x0004
struct FSetLinearDamping
{
float                                              InDamping                                                 // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetLockedAxis
// 0x0001
struct FSetLockedAxis
{
unsigned char                                      LockedAxis                                                // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetMassOverrideInKg
// 0x0010
struct FSetMassOverrideInKg
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
float                                              MassInKg                                                  // 0x0008(0x0004)
Bool                                               bOverrideMass                                             // 0x000C(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetMassScale
// 0x0010
struct FSetMassScale
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
float                                              InMassScale                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetMaterial
// 0x0010
struct FSetMaterial
{
int                                                ElementIndex                                              // 0x0000(0x0004)
class UMaterialInterface*                          Material                                                  // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetMaterialByName
// 0x0010
struct FSetMaterialByName
{
struct FName                                       MaterialSlotName                                          // 0x0000(0x0008)
class UMaterialInterface*                          Material                                                  // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetNotifyRigidBodyCollision
// 0x0001
struct FSetNotifyRigidBodyCollision
{
Bool                                               bNewNotifyRigidBodyCollision                              // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetOccludedDyeingColor
// 0x0010
struct FSetOccludedDyeingColor
{
struct FLinearColor                                InColor                                                   // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetOnlyOwnerSee
// 0x0001
struct FSetOnlyOwnerSee
{
Bool                                               bNewOnlyOwnerSee                                          // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetOutlineMesh
// 0x0008
struct FSetOutlineMesh
{
class UStaticMesh*                                 StaticMesh                                                // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetOwnerNoSee
// 0x0001
struct FSetOwnerNoSee
{
Bool                                               bNewOwnerNoSee                                            // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetPhysicsAngularVelocity
// 0x0018
struct FSetPhysicsAngularVelocity
{
struct FVector                                     NewAngVel                                                 // 0x0000(0x000C)
Bool                                               bAddToCurrent                                             // 0x000C(0x0001)
struct FName                                       BoneName                                                  // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetPhysicsAngularVelocityInDegrees
// 0x0018
struct FSetPhysicsAngularVelocityInDegrees
{
struct FVector                                     NewAngVel                                                 // 0x0000(0x000C)
Bool                                               bAddToCurrent                                             // 0x000C(0x0001)
struct FName                                       BoneName                                                  // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetPhysicsAngularVelocityInRadians
// 0x0018
struct FSetPhysicsAngularVelocityInRadians
{
struct FVector                                     NewAngVel                                                 // 0x0000(0x000C)
Bool                                               bAddToCurrent                                             // 0x000C(0x0001)
struct FName                                       BoneName                                                  // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetPhysicsLinearVelocity
// 0x0018
struct FSetPhysicsLinearVelocity
{
struct FVector                                     NewVel                                                    // 0x0000(0x000C)
Bool                                               bAddToCurrent                                             // 0x000C(0x0001)
struct FName                                       BoneName                                                  // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetPhysicsMaxAngularVelocity
// 0x0010
struct FSetPhysicsMaxAngularVelocity
{
float                                              NewMaxAngVel                                              // 0x0000(0x0004)
Bool                                               bAddToCurrent                                             // 0x0004(0x0001)
struct FName                                       BoneName                                                  // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetPhysicsMaxAngularVelocityInDegrees
// 0x0010
struct FSetPhysicsMaxAngularVelocityInDegrees
{
float                                              NewMaxAngVel                                              // 0x0000(0x0004)
Bool                                               bAddToCurrent                                             // 0x0004(0x0001)
struct FName                                       BoneName                                                  // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetPhysicsMaxAngularVelocityInRadians
// 0x0010
struct FSetPhysicsMaxAngularVelocityInRadians
{
float                                              NewMaxAngVel                                              // 0x0000(0x0004)
Bool                                               bAddToCurrent                                             // 0x0004(0x0001)
struct FName                                       BoneName                                                  // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetPhysMaterialOverride
// 0x0008
struct FSetPhysMaterialOverride
{
class UPhysicalMaterial*                           NewPhysMaterial                                           // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetReceivesDecals
// 0x0001
struct FSetReceivesDecals
{
Bool                                               bNewReceivesDecals                                        // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetRenderCustomDepth
// 0x0001
struct FSetRenderCustomDepth
{
Bool                                               bValue                                                    // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetRenderInMainPass
// 0x0010
struct FSetRenderInMainPass
{
Bool                                               bValue                                                    // 0x0000(0x0001)
struct FName                                       LockKey                                                   // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetRenderInMono
// 0x0001
struct FSetRenderInMono
{
Bool                                               bValue                                                    // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetReveiceShadow
// 0x0001
struct FSetReveiceShadow
{
Bool                                               NewReveiceShadow                                          // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetScopeInfoLocal
// 0x001C
struct FSetScopeInfoLocal
{
struct FVector                                     InLocalTranslation                                        // 0x0000(0x000C)
struct FRotator                                    InLocalRotation                                           // 0x000C(0x000C)
float                                              InScopeRadius                                             // 0x0018(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetSimulatePhysics
// 0x0001
struct FSetSimulatePhysics
{
Bool                                               bSimulate                                                 // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetSingleSampleShadowFromStationaryLights
// 0x0001
struct FSetSingleSampleShadowFromStationaryLights
{
Bool                                               bNewSingleSampleShadowFromStationaryLights                // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetTppLayer
// 0x0001
struct FSetTppLayer
{
Bool                                               InIsTppLayer                                              // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetTranslucentDepthWrite
// 0x0001
struct FSetTranslucentDepthWrite
{
Bool                                               bNewTranslucentDepthWrite                                 // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetTranslucentDepthWriteInTwoPass
// 0x0001
struct FSetTranslucentDepthWriteInTwoPass
{
Bool                                               bNewTranslucentDepthWriteInTwoPass                        // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetTranslucentSortPriority
// 0x0004
struct FSetTranslucentSortPriority
{
int                                                NewTranslucentSortPriority                                // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetTwoPassTranslucent
// 0x0001
struct FSetTwoPassTranslucent
{
Bool                                               bNewTwoPassTranslucent                                    // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetVisibleDyeingColor
// 0x0010
struct FSetVisibleDyeingColor
{
struct FLinearColor                                InColor                                                   // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.SetWalkableSlopeOverride
// 0x0010
struct FSetWalkableSlopeOverride
{
struct FWalkableSlopeOverride                      NewOverride                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.PrimitiveComponent.WakeRigidBody
// 0x0008
struct FWakeRigidBody
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.MeshComponent.DisableMeshClipPlane
// 0x0004
struct FDisableMeshClipPlane
{
int                                                PlaneIndex                                                // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.MeshComponent.EnableMeshClip4Planes
// 0x0018
struct FEnableMeshClip4Planes
{
TArray<struct FPlane>                              ClipPlanes                                                // 0x0000(0x0010)
Bool                                               bBox                                                      // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.MeshComponent.EnableMeshClipArc
// 0x0020
struct FEnableMeshClipArc
{
struct FPlane                                      ClipPlane                                                 // 0x0000(0x0010)
struct FVector4                                    ClipSphere                                                // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.MeshComponent.EnableMeshClipPlane
// 0x0020
struct FEnableMeshClipPlane
{
struct FPlane                                      ClipPlane                                                 // 0x0000(0x0010)
int                                                PlaneIndex                                                // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.MeshComponent.GetIndexedOverlayMaterials
// 0x0010
struct FGetIndexedOverlayMaterials
{
TArray<class UMaterialInterface*>                  ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.MeshComponent.GetMaterialIndex
// 0x0010
struct FGetMaterialIndex
{
struct FName                                       MaterialSlotName                                          // 0x0000(0x0008)
int                                                ReturnValue                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.MeshComponent.GetMaterials
// 0x0010
struct FGetMaterials
{
TArray<class UMaterialInterface*>                  ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.MeshComponent.GetMaterialSlotNames
// 0x0010
struct FGetMaterialSlotNames
{
TArray<struct FName>                               ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.MeshComponent.GetOverlayMaterial
// 0x0008
struct FGetOverlayMaterial
{
class UMaterialInterface*                          ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.MeshComponent.GetUseIndexedOverlayMaterials
// 0x0001
struct FGetUseIndexedOverlayMaterials
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.MeshComponent.GetUseOverlayMaterials
// 0x0001
struct FGetUseOverlayMaterials
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.MeshComponent.IsMaterialSlotNameValid
// 0x0010
struct FIsMaterialSlotNameValid
{
struct FName                                       MaterialSlotName                                          // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.MeshComponent.PrestreamTextures
// 0x000C
struct FPrestreamTextures
{
float                                              Seconds                                                   // 0x0000(0x0004)
Bool                                               bPrioritizeCharacterTextures                              // 0x0004(0x0001)
int                                                CinematicTextureGroups                                    // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.MeshComponent.SetIndexedOverlayMaterial
// 0x0010
struct FSetIndexedOverlayMaterial
{
int                                                ElementIndex                                              // 0x0000(0x0004)
class UMaterialInterface*                          Material                                                  // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.MeshComponent.SetOverlayMaterial
// 0x0008
struct FSetOverlayMaterial
{
class UMaterialInterface*                          NewOverlayMaterial                                        // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.MeshComponent.SetOverlayMaterialMaxDrawDistance
// 0x0004
struct FSetOverlayMaterialMaxDrawDistance
{
float                                              InMaxDrawDistance                                         // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.MeshComponent.SetScalarParameterValueOnMaterials
// 0x0010
struct FSetScalarParameterValueOnMaterials
{
struct FName                                       ParameterName                                             // 0x0000(0x0008)
float                                              ParameterValue                                            // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.MeshComponent.SetUseIndexedOverlayMaterials
// 0x0001
struct FSetUseIndexedOverlayMaterials
{
Bool                                               bNewUseIndexedOverlayMaterials                            // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.MeshComponent.SetUseOverlayMaterials
// 0x0001
struct FSetUseOverlayMaterials
{
Bool                                               bNewUseOverlayMaterials                                   // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.MeshComponent.SetVectorParameterValueOnMaterials
// 0x0018
struct FSetVectorParameterValueOnMaterials
{
struct FName                                       ParameterName                                             // 0x0000(0x0008)
struct FVector                                     ParameterValue                                            // 0x0008(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.BoneIsChildOf
// 0x0018
struct FBoneIsChildOf
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
struct FName                                       ParentBoneName                                            // 0x0008(0x0008)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.ClearSkinWeightOverride
// 0x0004
struct FClearSkinWeightOverride
{
int                                                LODIndex                                                  // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.ClearVertexColorOverride
// 0x0004
struct FClearVertexColorOverride
{
int                                                LODIndex                                                  // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.DisableMeshClipPlane
// 0x0004
struct FDisableMeshClipPlane
{
int                                                PlaneIndex                                                // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.EnableMeshClip4Planes
// 0x0018
struct FEnableMeshClip4Planes
{
TArray<struct FPlane>                              ClipPlanes                                                // 0x0000(0x0010)
Bool                                               bBox                                                      // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.EnableMeshClipArc
// 0x0020
struct FEnableMeshClipArc
{
struct FPlane                                      ClipPlane                                                 // 0x0000(0x0010)
struct FVector4                                    ClipSphere                                                // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.EnableMeshClipPlane
// 0x0020
struct FEnableMeshClipPlane
{
struct FPlane                                      ClipPlane                                                 // 0x0000(0x0010)
int                                                PlaneIndex                                                // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.FindClosestBone_K2
// 0x0028
struct FFindClosestBone_K2
{
struct FVector                                     TestLocation                                              // 0x0000(0x000C)
struct FVector                                     BoneLocation                                              // 0x000C(0x000C)
float                                              IgnoreScale                                               // 0x0018(0x0004)
Bool                                               bRequirePhysicsAsset                                      // 0x001C(0x0001)
struct FName                                       ReturnValue                                               // 0x0020(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.FollowBoneHidden
// 0x0018
struct FFollowBoneHidden
{
class USkinnedMeshComponent*                       InHiddenLeaderComp                                        // 0x0000(0x0008)
struct FName                                       BoneName                                                  // 0x0008(0x0008)
unsigned char                                      PhysBodyOption                                            // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.FollowBoneUnHidden
// 0x0010
struct FFollowBoneUnHidden
{
class USkinnedMeshComponent*                       InUnHiddenLeaderComp                                      // 0x0000(0x0008)
struct FName                                       BoneName                                                  // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.GetBoneIndex
// 0x0010
struct FGetBoneIndex
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
int                                                ReturnValue                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.GetBoneLocation
// 0x0018
struct FGetBoneLocation
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
unsigned char                                      Space                                                     // 0x0008(0x0001)
struct FVector                                     ReturnValue                                               // 0x000C(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.GetBoneName
// 0x0010
struct FGetBoneName
{
int                                                BoneIndex                                                 // 0x0000(0x0004)
struct FName                                       ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.GetBoneTransform
// 0x0040
struct FGetBoneTransform
{
int                                                BoneIndex                                                 // 0x0000(0x0004)
struct FTransform                                  ReturnValue                                               // 0x0010(0x0030)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.GetCurrentSkinWeightProfileName
// 0x0008
struct FGetCurrentSkinWeightProfileName
{
struct FName                                       ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.GetNumBones
// 0x0004
struct FGetNumBones
{
int                                                ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.GetNumLODs
// 0x0004
struct FGetNumLODs
{
int                                                ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.GetParentBone
// 0x0010
struct FGetParentBone
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
struct FName                                       ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.GetSkeletalMesh
// 0x0008
struct FGetSkeletalMesh
{
class USkeletalMesh*                               ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.GetSocketBoneName
// 0x0010
struct FGetSocketBoneName
{
struct FName                                       InSocketName                                              // 0x0000(0x0008)
struct FName                                       ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.HasSkinweightProfileByName
// 0x0010
struct FHasSkinweightProfileByName
{
struct FName                                       InProfileName                                             // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.HideBoneByName
// 0x0010
struct FHideBoneByName
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
unsigned char                                      PhysBodyOption                                            // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.IsBoneHiddenByName
// 0x0010
struct FIsBoneHiddenByName
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.IsSectionBatched
// 0x0008
struct FIsSectionBatched
{
int                                                LODIndex                                                  // 0x0000(0x0004)
Bool                                               ReturnValue                                               // 0x0004(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.IsUsingSkinWeightProfile
// 0x0001
struct FIsUsingSkinWeightProfile
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.OffsetBoneExtraOffsprings
// 0x0018
struct FOffsetBoneExtraOffsprings
{
struct FName                                       InputBoneName                                             // 0x0000(0x0008)
struct FVector                                     InputTranslation                                          // 0x0008(0x000C)
int                                                ReturnValue                                               // 0x0014(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.PropagateBoneHidden
// 0x0008
struct FPropagateBoneHidden
{
int                                                BoneIndex                                                 // 0x0000(0x0004)
unsigned char                                      PhysBodyOption                                            // 0x0004(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.PropagateBoneUnHidden
// 0x0004
struct FPropagateBoneUnHidden
{
int                                                BoneIndex                                                 // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.RotateBoneExtraOffsprings
// 0x0018
struct FRotateBoneExtraOffsprings
{
struct FName                                       InputBoneName                                             // 0x0000(0x0008)
struct FRotator                                    InputRotation                                             // 0x0008(0x000C)
int                                                ReturnValue                                               // 0x0014(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.ScaleBoneExtraOffsprings
// 0x0018
struct FScaleBoneExtraOffsprings
{
struct FName                                       InputBoneName                                             // 0x0000(0x0008)
struct FVector                                     InputScale                                                // 0x0008(0x000C)
int                                                ReturnValue                                               // 0x0014(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.SetCapsuleIndirectShadowMinVisibility
// 0x0004
struct FSetCapsuleIndirectShadowMinVisibility
{
float                                              NewValue                                                  // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.SetCastCapsuleDirectShadow
// 0x0001
struct FSetCastCapsuleDirectShadow
{
Bool                                               bNewValue                                                 // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.SetCastCapsuleIndirectShadow
// 0x0001
struct FSetCastCapsuleIndirectShadow
{
Bool                                               bNewValue                                                 // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.SetForcedLOD
// 0x0004
struct FSetForcedLOD
{
int                                                InNewForcedLOD                                            // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.SetMasterPoseComponent
// 0x0010
struct FSetMasterPoseComponent
{
class USkinnedMeshComponent*                       NewMasterBoneComponent                                    // 0x0000(0x0008)
Bool                                               bForceUpdate                                              // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.SetMinLOD
// 0x0004
struct FSetMinLOD
{
int                                                InNewMinLOD                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.SetPhysicsAsset
// 0x0010
struct FSetPhysicsAsset
{
class UPhysicsAsset*                               NewPhysicsAsset                                           // 0x0000(0x0008)
Bool                                               bForceReInit                                              // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.SetRenderStatic
// 0x0001
struct FSetRenderStatic
{
Bool                                               bNewValue                                                 // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.SetSkeletalMesh
// 0x0010
struct FSetSkeletalMesh
{
class USkeletalMesh*                               NewMesh                                                   // 0x0000(0x0008)
Bool                                               bReinitPose                                               // 0x0008(0x0001)
Bool                                               bCheckBoneMap                                             // 0x0009(0x0001)
Bool                                               bTickAnimationNow                                         // 0x000A(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.SetSkinWeightOverride
// 0x0018
struct FSetSkinWeightOverride
{
int                                                LODIndex                                                  // 0x0000(0x0004)
TArray<struct FSkelMeshSkinWeightInfo>             SkinWeights                                               // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.SetSkinWeightProfile
// 0x0010
struct FSetSkinWeightProfile
{
struct FName                                       InProfileName                                             // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.SetVertexColorOverride_LinearColor
// 0x0018
struct FSetVertexColorOverride_LinearColor
{
int                                                LODIndex                                                  // 0x0000(0x0004)
TArray<struct FLinearColor>                        VertexColors                                              // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.SwitchToOverrideSkinWeights
// 0x0004
struct FSwitchToOverrideSkinWeights
{
int                                                LODIndex                                                  // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.TransformFromBoneSpace
// 0x0038
struct FTransformFromBoneSpace
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
struct FVector                                     InPosition                                                // 0x0008(0x000C)
struct FRotator                                    InRotation                                                // 0x0014(0x000C)
struct FVector                                     OutPosition                                               // 0x0020(0x000C)
struct FRotator                                    OutRotation                                               // 0x002C(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.TransformToBoneSpace
// 0x0038
struct FTransformToBoneSpace
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
struct FVector                                     InPosition                                                // 0x0008(0x000C)
struct FRotator                                    InRotation                                                // 0x0014(0x000C)
struct FVector                                     OutPosition                                               // 0x0020(0x000C)
struct FRotator                                    OutRotation                                               // 0x002C(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.UnHideBoneByName
// 0x0008
struct FUnHideBoneByName
{
struct FName                                       BoneName                                                  // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.UnloadSkinWeightProfile
// 0x0008
struct FUnloadSkinWeightProfile
{
struct FName                                       InProfileName                                             // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.SkinnedMeshComponent.UpdateSkinWeightForRemapping
// 0x0018
struct FUpdateSkinWeightForRemapping
{
struct FSkinWeightInfoForFPP                       WeightInfo                                                // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.MovementComponent.ConstrainDirectionToPlane
// 0x0018
struct FConstrainDirectionToPlane
{
struct FVector                                     Direction                                                 // 0x0000(0x000C)
struct FVector                                     ReturnValue                                               // 0x000C(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.MovementComponent.ConstrainLocationToPlane
// 0x0018
struct FConstrainLocationToPlane
{
struct FVector                                     Location                                                  // 0x0000(0x000C)
struct FVector                                     ReturnValue                                               // 0x000C(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.MovementComponent.ConstrainNormalToPlane
// 0x0018
struct FConstrainNormalToPlane
{
struct FVector                                     Normal                                                    // 0x0000(0x000C)
struct FVector                                     ReturnValue                                               // 0x000C(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.MovementComponent.GetGravityZ
// 0x0004
struct FGetGravityZ
{
float                                              ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.MovementComponent.GetMaxSpeed
// 0x0004
struct FGetMaxSpeed
{
float                                              ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.MovementComponent.GetPhysicsVolume
// 0x0008
struct FGetPhysicsVolume
{
class APhysicsVolume*                              ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.MovementComponent.GetPlaneConstraintAxisSetting
// 0x0001
struct FGetPlaneConstraintAxisSetting
{
EPlaneConstraintAxisSetting                        ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.MovementComponent.GetPlaneConstraintNormal
// 0x000C
struct FGetPlaneConstraintNormal
{
struct FVector                                     ReturnValue                                               // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.MovementComponent.GetPlaneConstraintOrigin
// 0x000C
struct FGetPlaneConstraintOrigin
{
struct FVector                                     ReturnValue                                               // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.MovementComponent.IsExceedingMaxSpeed
// 0x0008
struct FIsExceedingMaxSpeed
{
float                                              MaxSpeed                                                  // 0x0000(0x0004)
Bool                                               ReturnValue                                               // 0x0004(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.MovementComponent.K2_GetMaxSpeedModifier
// 0x0004
struct FK2_GetMaxSpeedModifier
{
float                                              ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.MovementComponent.K2_GetModifiedMaxSpeed
// 0x0004
struct FK2_GetModifiedMaxSpeed
{
float                                              ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.MovementComponent.K2_MoveUpdatedComponent
// 0x00A8
struct FK2_MoveUpdatedComponent
{
struct FVector                                     Delta                                                     // 0x0000(0x000C)
struct FRotator                                    NewRotation                                               // 0x000C(0x000C)
struct FHitResult                                  OutHit                                                    // 0x0018(0x0088)
Bool                                               bSweep                                                    // 0x00A0(0x0001)
Bool                                               bTeleport                                                 // 0x00A1(0x0001)
Bool                                               ReturnValue                                               // 0x00A2(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.MovementComponent.PhysicsVolumeChanged
// 0x0008
struct FPhysicsVolumeChanged
{
class APhysicsVolume*                              NewVolume                                                 // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.MovementComponent.SetPlaneConstraintAxisSetting
// 0x0001
struct FSetPlaneConstraintAxisSetting
{
EPlaneConstraintAxisSetting                        NewAxisSetting                                            // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.MovementComponent.SetPlaneConstraintEnabled
// 0x0001
struct FSetPlaneConstraintEnabled
{
Bool                                               bEnabled                                                  // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.MovementComponent.SetPlaneConstraintFromVectors
// 0x0018
struct FSetPlaneConstraintFromVectors
{
struct FVector                                     Forward                                                   // 0x0000(0x000C)
struct FVector                                     Up                                                        // 0x000C(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.MovementComponent.SetPlaneConstraintNormal
// 0x000C
struct FSetPlaneConstraintNormal
{
struct FVector                                     PlaneNormal                                               // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.MovementComponent.SetPlaneConstraintOrigin
// 0x000C
struct FSetPlaneConstraintOrigin
{
struct FVector                                     PlaneOrigin                                               // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.MovementComponent.SetUpdatedComponent
// 0x0008
struct FSetUpdatedComponent
{
class USceneComponent*                             NewUpdatedComponent                                       // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.InterpToMovementComponent.RestartMovement
// 0x0004
struct FRestartMovement
{
float                                              InitialDirection                                          // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.InterpToMovementComponent.StopSimulating
// 0x0088
struct FStopSimulating
{
struct FHitResult                                  HitResult                                                 // 0x0000(0x0088)
};

// 大佬QQ:2396031563
// Function Engine.PlatformEventsComponent.IsInLaptopMode
// 0x0001
struct FIsInLaptopMode
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PlatformEventsComponent.IsInTabletMode
// 0x0001
struct FIsInTabletMode
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.PlatformEventsComponent.SupportsConvertibleLaptops
// 0x0001
struct FSupportsConvertibleLaptops
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.GameInstance.ClearConsoleVariableBunch
// 0x0001
struct FClearConsoleVariableBunch
{
ECVarType                                          CVarType                                                  // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.GameInstance.DebugCreatePlayer
// 0x0004
struct FDebugCreatePlayer
{
int                                                ControllerId                                              // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.GameInstance.DebugRemovePlayer
// 0x0004
struct FDebugRemovePlayer
{
int                                                ControllerId                                              // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.GameInstance.EnableConsoleVariableBunch
// 0x0002
struct FEnableConsoleVariableBunch
{
ECVarType                                          CVarType                                                  // 0x0000(0x0001)
Bool                                               bMapIsBigWorld                                            // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.GameInstance.GetPakResState
// 0x0002
struct FGetPakResState
{
ESpecialPakID                                      InPakID                                                   // 0x0000(0x0001)
EPakResState                                       ReturnValue                                               // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.GameInstance.HandleNetworkError
// 0x0002
struct FHandleNetworkError
{
unsigned char                                      FailureType                                               // 0x0000(0x0001)
Bool                                               bIsServer                                                 // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.GameInstance.HandleTravelError
// 0x0001
struct FHandleTravelError
{
unsigned char                                      FailureType                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.GameInstance.IsPlatformSplitPakRes
// 0x0002
struct FIsPlatformSplitPakRes
{
ESpecialPakID                                      InPakID                                                   // 0x0000(0x0001)
EPakSplitState                                     ReturnValue                                               // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.GameInstance.ReceiveConsoleVariableBunch_BigWorld
// 0x0010
struct FReceiveConsoleVariableBunch_BigWorld
{
TArray<unsigned char>                              InConsoleVariablesBunch                                   // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.GameInstance.ReceiveConsoleVariableBunch_Permanent
// 0x0010
struct FReceiveConsoleVariableBunch_Permanent
{
TArray<unsigned char>                              InConsoleVariablesBunch                                   // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.GameInstance.ResetConsoleVariable
// 0x0001
struct FResetConsoleVariable
{
ECVarType                                          CVarType                                                  // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.GameInstance.SendConsoleVariableBunch
// 0x0010
struct FSendConsoleVariableBunch
{
ECVarType                                          CVarType                                                  // 0x0000(0x0001)
class UNetConnection*                              Connection                                                // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.GameInstance.SetPakResState
// 0x0002
struct FSetPakResState
{
ESpecialPakID                                      InPakID                                                   // 0x0000(0x0001)
EPakResState                                       InPakState                                                // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ActorHasTag
// 0x0010
struct FActorHasTag
{
struct FName                                       Tag                                                       // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.AddComponent
// 0x0050
struct FAddComponent
{
struct FName                                       TemplateName                                              // 0x0000(0x0008)
Bool                                               bManualAttachment                                         // 0x0008(0x0001)
struct FTransform                                  RelativeTransform                                         // 0x0010(0x0030)
class UObject*                                     ComponentTemplateContext                                  // 0x0040(0x0008)
class UActorComponent*                             ReturnValue                                               // 0x0048(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.AddDynamicTag
// 0x0008
struct FAddDynamicTag
{
struct FName                                       Tag                                                       // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.AddTickPrerequisiteActor
// 0x0008
struct FAddTickPrerequisiteActor
{
class AActor*                                      PrerequisiteActor                                         // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.AddTickPrerequisiteComponent
// 0x0008
struct FAddTickPrerequisiteComponent
{
class UActorComponent*                             PrerequisiteComponent                                     // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.AllowTriggerDeformEffect
// 0x0014
struct FAllowTriggerDeformEffect
{
struct FVector                                     Origin                                                    // 0x0000(0x000C)
float                                              EffectRange                                               // 0x000C(0x0004)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.CallSubObjectLuaOnRep
// 0x0008
struct FCallSubObjectLuaOnRep
{
class UObject*                                     InObject                                                  // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.CanBeBaseForCharacter
// 0x0010
struct FCanBeBaseForCharacter
{
class APawn*                                       Pawn                                                      // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ClearAnimNotifyStateBoneRetargetAdaptState
// 0x0008
struct FClearAnimNotifyStateBoneRetargetAdaptState
{
class UObject*                                     InTargetNotifyState                                       // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ClientSendScriptNetworkRemoteContent
// 0x0018
struct FClientSendScriptNetworkRemoteContent
{
struct FScriptNetworkRemoteContent                 Content                                                   // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ClientSendScriptNetworkRemoteContent_Unreliable
// 0x0018
struct FClientSendScriptNetworkRemoteContent_Unreliable
{
struct FScriptNetworkRemoteContent                 Content                                                   // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.Actor.DetachRootComponentFromParent
// 0x0001
struct FDetachRootComponentFromParent
{
Bool                                               bMaintainWorldPosition                                    // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.DisableInput
// 0x0008
struct FDisableInput
{
class APlayerController*                           PlayerController                                          // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.EnableInput
// 0x0008
struct FEnableInput
{
class APlayerController*                           PlayerController                                          // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ForceNetComponentUpdate
// 0x0008
struct FForceNetComponentUpdate
{
class UActorComponent*                             InComponent                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetActorBounds
// 0x001C
struct FGetActorBounds
{
Bool                                               bOnlyCollidingComponents                                  // 0x0000(0x0001)
struct FVector                                     Origin                                                    // 0x0004(0x000C)
struct FVector                                     BoxExtent                                                 // 0x0010(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetActorEnableCollision
// 0x0001
struct FGetActorEnableCollision
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetActorEyesViewPoint
// 0x0018
struct FGetActorEyesViewPoint
{
struct FVector                                     OutLocation                                               // 0x0000(0x000C)
struct FRotator                                    OutRotation                                               // 0x000C(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetActorForwardVector
// 0x000C
struct FGetActorForwardVector
{
struct FVector                                     ReturnValue                                               // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetActorRelativeScale3D
// 0x000C
struct FGetActorRelativeScale3D
{
struct FVector                                     ReturnValue                                               // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetActorRightVector
// 0x000C
struct FGetActorRightVector
{
struct FVector                                     ReturnValue                                               // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetActorScale3D
// 0x000C
struct FGetActorScale3D
{
struct FVector                                     ReturnValue                                               // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetActorTickInterval
// 0x0004
struct FGetActorTickInterval
{
float                                              ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetActorTimeDilation
// 0x0004
struct FGetActorTimeDilation
{
float                                              ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetActorUpVector
// 0x000C
struct FGetActorUpVector
{
struct FVector                                     ReturnValue                                               // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetAllChildActors
// 0x0018
struct FGetAllChildActors
{
TArray<class AActor*>                              ChildActors                                               // 0x0000(0x0010)
Bool                                               bIncludeDescendants                                       // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetAnimNotifyStateBoneRetargetAdaptInfoObj
// 0x0008
struct FGetAnimNotifyStateBoneRetargetAdaptInfoObj
{
class UAnimNotifyStateBoneRetargetAdaptInfoObj*    ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetAttachedActors
// 0x0010
struct FGetAttachedActors
{
TArray<class AActor*>                              OutActors                                                 // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetAttachParentActor
// 0x0008
struct FGetAttachParentActor
{
class AActor*                                      ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetAttachParentSocketName
// 0x0008
struct FGetAttachParentSocketName
{
struct FName                                       ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetComponentByClass
// 0x0010
struct FGetComponentByClass
{
class UClass*                                      ComponentClass                                            // 0x0000(0x0008)
class UActorComponent*                             ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetComponentsByClass
// 0x0018
struct FGetComponentsByClass
{
class UClass*                                      ComponentClass                                            // 0x0000(0x0008)
TArray<class UActorComponent*>                     ReturnValue                                               // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetComponentsByTag
// 0x0020
struct FGetComponentsByTag
{
class UClass*                                      ComponentClass                                            // 0x0000(0x0008)
struct FName                                       Tag                                                       // 0x0008(0x0008)
TArray<class UActorComponent*>                     ReturnValue                                               // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetDistanceTo
// 0x0010
struct FGetDistanceTo
{
class AActor*                                      OtherActor                                                // 0x0000(0x0008)
float                                              ReturnValue                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetDotProductTo
// 0x0010
struct FGetDotProductTo
{
class AActor*                                      OtherActor                                                // 0x0000(0x0008)
float                                              ReturnValue                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetGameTimeSinceCreation
// 0x0004
struct FGetGameTimeSinceCreation
{
float                                              ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetGeneralCampID
// 0x0004
struct FGetGeneralCampID
{
int                                                ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetGeneralCampName
// 0x0010
struct FGetGeneralCampName
{
struct FString                                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetGeneralCampRelationWithActor
// 0x0010
struct FGetGeneralCampRelationWithActor
{
class AActor*                                      Actor                                                     // 0x0000(0x0008)
ECampRelation                                      ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetGeneralCampRelationWithCampID
// 0x0008
struct FGetGeneralCampRelationWithCampID
{
int                                                CampID                                                    // 0x0000(0x0004)
ECampRelation                                      ReturnValue                                               // 0x0004(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetHorizontalDistanceTo
// 0x0010
struct FGetHorizontalDistanceTo
{
class AActor*                                      OtherActor                                                // 0x0000(0x0008)
float                                              ReturnValue                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetHorizontalDotProductTo
// 0x0010
struct FGetHorizontalDotProductTo
{
class AActor*                                      OtherActor                                                // 0x0000(0x0008)
float                                              ReturnValue                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetInputAxisKeyValue
// 0x0020
struct FGetInputAxisKeyValue
{
struct FKey                                        InputAxisKey                                              // 0x0000(0x0018)
float                                              ReturnValue                                               // 0x0018(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetInputAxisValue
// 0x0010
struct FGetInputAxisValue
{
struct FName                                       InputAxisName                                             // 0x0000(0x0008)
float                                              ReturnValue                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetInputVectorAxisValue
// 0x0028
struct FGetInputVectorAxisValue
{
struct FKey                                        InputAxisKey                                              // 0x0000(0x0018)
struct FVector                                     ReturnValue                                               // 0x0018(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetInstigator
// 0x0008
struct FGetInstigator
{
class APawn*                                       ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetInstigatorController
// 0x0008
struct FGetInstigatorController
{
class AController*                                 ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetLevelName
// 0x0010
struct FGetLevelName
{
struct FString                                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetLifeSpan
// 0x0004
struct FGetLifeSpan
{
float                                              ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetLocalRole
// 0x0001
struct FGetLocalRole
{
unsigned char                                      ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetOverlappingActors
// 0x0018
struct FGetOverlappingActors
{
TArray<class AActor*>                              OverlappingActors                                         // 0x0000(0x0010)
class UClass*                                      ClassFilter                                               // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetOverlappingComponents
// 0x0010
struct FGetOverlappingComponents
{
TArray<class UPrimitiveComponent*>                 OverlappingComponents                                     // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetOwner
// 0x0008
struct FGetOwner
{
class AActor*                                      ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetParentActor
// 0x0008
struct FGetParentActor
{
class AActor*                                      ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetParentComponent
// 0x0008
struct FGetParentComponent
{
class UChildActorComponent*                        ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetRemoteRole
// 0x0001
struct FGetRemoteRole
{
unsigned char                                      ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetRole
// 0x0001
struct FGetRole
{
unsigned char                                      ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetSquaredDistanceTo
// 0x0010
struct FGetSquaredDistanceTo
{
class AActor*                                      OtherActor                                                // 0x0000(0x0008)
float                                              ReturnValue                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetTickableWhenPaused
// 0x0001
struct FGetTickableWhenPaused
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetToString
// 0x0010
struct FGetToString
{
struct FString                                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetTransform
// 0x0030
struct FGetTransform
{
struct FTransform                                  ReturnValue                                               // 0x0000(0x0030)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetVelocity
// 0x000C
struct FGetVelocity
{
struct FVector                                     ReturnValue                                               // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.Actor.GetVerticalDistanceTo
// 0x0010
struct FGetVerticalDistanceTo
{
class AActor*                                      OtherActor                                                // 0x0000(0x0008)
float                                              ReturnValue                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.Actor.HasAuthority
// 0x0001
struct FHasAuthority
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.InitAnimNotifyStateBoneRetargetInfo
// 0x0010
struct FInitAnimNotifyStateBoneRetargetInfo
{
class UObject*                                     InTargetNotifyState                                       // 0x0000(0x0008)
class UObject*                                     InBoneRetargetObj                                         // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.IsActorBeingDestroyed
// 0x0001
struct FIsActorBeingDestroyed
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.IsActorTickEnabled
// 0x0001
struct FIsActorTickEnabled
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.IsAnimNotifyStateBoneRetargetAdaptInitDone
// 0x0010
struct FIsAnimNotifyStateBoneRetargetAdaptInitDone
{
class UObject*                                     InTargetNotifyState                                       // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.IsChildActor
// 0x0001
struct FIsChildActor
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.IsOverlappingActor
// 0x0010
struct FIsOverlappingActor
{
class AActor*                                      Other                                                     // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_AddActorLocalOffset
// 0x00A0
struct FK2_AddActorLocalOffset
{
struct FVector                                     DeltaLocation                                             // 0x0000(0x000C)
Bool                                               bSweep                                                    // 0x000C(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0010(0x0088)
Bool                                               bTeleport                                                 // 0x0098(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_AddActorLocalRotation
// 0x00A0
struct FK2_AddActorLocalRotation
{
struct FRotator                                    DeltaRotation                                             // 0x0000(0x000C)
Bool                                               bSweep                                                    // 0x000C(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0010(0x0088)
Bool                                               bTeleport                                                 // 0x0098(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_AddActorLocalTransform
// 0x00D0
struct FK2_AddActorLocalTransform
{
struct FTransform                                  NewTransform                                              // 0x0000(0x0030)
Bool                                               bSweep                                                    // 0x0030(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0038(0x0088)
Bool                                               bTeleport                                                 // 0x00C0(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_AddActorWorldOffset
// 0x00A0
struct FK2_AddActorWorldOffset
{
struct FVector                                     DeltaLocation                                             // 0x0000(0x000C)
Bool                                               bSweep                                                    // 0x000C(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0010(0x0088)
Bool                                               bTeleport                                                 // 0x0098(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_AddActorWorldRotation
// 0x00A0
struct FK2_AddActorWorldRotation
{
struct FRotator                                    DeltaRotation                                             // 0x0000(0x000C)
Bool                                               bSweep                                                    // 0x000C(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0010(0x0088)
Bool                                               bTeleport                                                 // 0x0098(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_AddActorWorldTransform
// 0x00D0
struct FK2_AddActorWorldTransform
{
struct FTransform                                  DeltaTransform                                            // 0x0000(0x0030)
Bool                                               bSweep                                                    // 0x0030(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0038(0x0088)
Bool                                               bTeleport                                                 // 0x00C0(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_AttachRootComponentTo
// 0x0018
struct FK2_AttachRootComponentTo
{
class USceneComponent*                             InParent                                                  // 0x0000(0x0008)
struct FName                                       InSocketName                                              // 0x0008(0x0008)
unsigned char                                      AttachLocationType                                        // 0x0010(0x0001)
Bool                                               bWeldSimulatedBodies                                      // 0x0011(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_AttachRootComponentToActor
// 0x0018
struct FK2_AttachRootComponentToActor
{
class AActor*                                      InParentActor                                             // 0x0000(0x0008)
struct FName                                       InSocketName                                              // 0x0008(0x0008)
unsigned char                                      AttachLocationType                                        // 0x0010(0x0001)
Bool                                               bWeldSimulatedBodies                                      // 0x0011(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_AttachToActor
// 0x0018
struct FK2_AttachToActor
{
class AActor*                                      ParentActor                                               // 0x0000(0x0008)
struct FName                                       SocketName                                                // 0x0008(0x0008)
EAttachmentRule                                    LocationRule                                              // 0x0010(0x0001)
EAttachmentRule                                    RotationRule                                              // 0x0011(0x0001)
EAttachmentRule                                    ScaleRule                                                 // 0x0012(0x0001)
Bool                                               bWeldSimulatedBodies                                      // 0x0013(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_AttachToComponent
// 0x0018
struct FK2_AttachToComponent
{
class USceneComponent*                             Parent                                                    // 0x0000(0x0008)
struct FName                                       SocketName                                                // 0x0008(0x0008)
EAttachmentRule                                    LocationRule                                              // 0x0010(0x0001)
EAttachmentRule                                    RotationRule                                              // 0x0011(0x0001)
EAttachmentRule                                    ScaleRule                                                 // 0x0012(0x0001)
Bool                                               bWeldSimulatedBodies                                      // 0x0013(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_DestroyComponent
// 0x0008
struct FK2_DestroyComponent
{
class UActorComponent*                             Component                                                 // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_DetachFromActor
// 0x0003
struct FK2_DetachFromActor
{
EDetachmentRule                                    LocationRule                                              // 0x0000(0x0001)
EDetachmentRule                                    RotationRule                                              // 0x0001(0x0001)
EDetachmentRule                                    ScaleRule                                                 // 0x0002(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_GetActorLocation
// 0x000C
struct FK2_GetActorLocation
{
struct FVector                                     ReturnValue                                               // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_GetActorRotation
// 0x000C
struct FK2_GetActorRotation
{
struct FRotator                                    ReturnValue                                               // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_GetRootComponent
// 0x0008
struct FK2_GetRootComponent
{
class USceneComponent*                             ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_OnBecomeViewTarget
// 0x0008
struct FK2_OnBecomeViewTarget
{
class APlayerController*                           PC                                                        // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_OnEndViewTarget
// 0x0008
struct FK2_OnEndViewTarget
{
class APlayerController*                           PC                                                        // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_SetActorLocation
// 0x00A0
struct FK2_SetActorLocation
{
struct FVector                                     NewLocation                                               // 0x0000(0x000C)
Bool                                               bSweep                                                    // 0x000C(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0010(0x0088)
Bool                                               bTeleport                                                 // 0x0098(0x0001)
Bool                                               ReturnValue                                               // 0x0099(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_SetActorLocationAndRotation
// 0x00B0
struct FK2_SetActorLocationAndRotation
{
struct FVector                                     NewLocation                                               // 0x0000(0x000C)
struct FRotator                                    NewRotation                                               // 0x000C(0x000C)
Bool                                               bSweep                                                    // 0x0018(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0020(0x0088)
Bool                                               bTeleport                                                 // 0x00A8(0x0001)
Bool                                               ReturnValue                                               // 0x00A9(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_SetActorRelativeLocation
// 0x00A0
struct FK2_SetActorRelativeLocation
{
struct FVector                                     NewRelativeLocation                                       // 0x0000(0x000C)
Bool                                               bSweep                                                    // 0x000C(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0010(0x0088)
Bool                                               bTeleport                                                 // 0x0098(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_SetActorRelativeRotation
// 0x00A0
struct FK2_SetActorRelativeRotation
{
struct FRotator                                    NewRelativeRotation                                       // 0x0000(0x000C)
Bool                                               bSweep                                                    // 0x000C(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0010(0x0088)
Bool                                               bTeleport                                                 // 0x0098(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_SetActorRelativeTransform
// 0x00D0
struct FK2_SetActorRelativeTransform
{
struct FTransform                                  NewRelativeTransform                                      // 0x0000(0x0030)
Bool                                               bSweep                                                    // 0x0030(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0038(0x0088)
Bool                                               bTeleport                                                 // 0x00C0(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_SetActorRotation
// 0x0010
struct FK2_SetActorRotation
{
struct FRotator                                    NewRotation                                               // 0x0000(0x000C)
Bool                                               bTeleportPhysics                                          // 0x000C(0x0001)
Bool                                               ReturnValue                                               // 0x000D(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_SetActorTransform
// 0x00D0
struct FK2_SetActorTransform
{
struct FTransform                                  NewTransform                                              // 0x0000(0x0030)
Bool                                               bSweep                                                    // 0x0030(0x0001)
struct FHitResult                                  SweepHitResult                                            // 0x0038(0x0088)
Bool                                               bTeleport                                                 // 0x00C0(0x0001)
Bool                                               ReturnValue                                               // 0x00C1(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.K2_TeleportTo
// 0x001C
struct FK2_TeleportTo
{
struct FVector                                     DestLocation                                              // 0x0000(0x000C)
struct FRotator                                    DestRotation                                              // 0x000C(0x000C)
Bool                                               ReturnValue                                               // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.MakeMIDForMaterial
// 0x0010
struct FMakeMIDForMaterial
{
class UMaterialInterface*                          Parent                                                    // 0x0000(0x0008)
class UMaterialInstanceDynamic*                    ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.MakeNoise
// 0x0028
struct FMakeNoise
{
float                                              Loudness                                                  // 0x0000(0x0004)
class APawn*                                       NoiseInstigator                                           // 0x0008(0x0008)
struct FVector                                     NoiseLocation                                             // 0x0010(0x000C)
float                                              MaxRange                                                  // 0x001C(0x0004)
struct FName                                       Tag                                                       // 0x0020(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.MarkSubObjectDeleteDirty
// 0x0008
struct FMarkSubObjectDeleteDirty
{
class UObject*                                     SubObject                                                 // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.OnActorSimulatedRelevant
// 0x0002
struct FOnActorSimulatedRelevant
{
Bool                                               bIsRelevant                                               // 0x0000(0x0001)
Bool                                               bConsiderHidden                                           // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.OverrideNotifyAttachMesh
// 0x0020
struct FOverrideNotifyAttachMesh
{
class UObject*                                     InTargetNotifyState                                       // 0x0000(0x0008)
class USkeletalMeshComponent*                      InTargetSkelMeshComp                                      // 0x0008(0x0008)
Bool                                               HasRetarget                                               // 0x0010(0x0001)
Bool                                               IgnoreNewFPPState                                         // 0x0011(0x0001)
class USkeletalMeshComponent*                      ReturnValue                                               // 0x0018(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.PrestreamTextures
// 0x000C
struct FPrestreamTextures
{
float                                              Seconds                                                   // 0x0000(0x0004)
Bool                                               bEnableStreaming                                          // 0x0004(0x0001)
int                                                CinematicTextureGroups                                    // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ReceiveActorBeginOverlap
// 0x0008
struct FReceiveActorBeginOverlap
{
class AActor*                                      OtherActor                                                // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ReceiveActorEndOverlap
// 0x0008
struct FReceiveActorEndOverlap
{
class AActor*                                      OtherActor                                                // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ReceiveActorOnClicked
// 0x0018
struct FReceiveActorOnClicked
{
struct FKey                                        ButtonPressed                                             // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ReceiveActorOnInputTouchBegin
// 0x0001
struct FReceiveActorOnInputTouchBegin
{
unsigned char                                      FingerIndex                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ReceiveActorOnInputTouchEnd
// 0x0001
struct FReceiveActorOnInputTouchEnd
{
unsigned char                                      FingerIndex                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ReceiveActorOnInputTouchEnter
// 0x0001
struct FReceiveActorOnInputTouchEnter
{
unsigned char                                      FingerIndex                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ReceiveActorOnInputTouchLeave
// 0x0001
struct FReceiveActorOnInputTouchLeave
{
unsigned char                                      FingerIndex                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ReceiveActorOnReleased
// 0x0018
struct FReceiveActorOnReleased
{
struct FKey                                        ButtonReleased                                            // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ReceiveActorSimulatedRelevant
// 0x0002
struct FReceiveActorSimulatedRelevant
{
Bool                                               bIsRelevant                                               // 0x0000(0x0001)
Bool                                               bConsiderHidden                                           // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ReceiveAnyDamage
// 0x0020
struct FReceiveAnyDamage
{
float                                              Damage                                                    // 0x0000(0x0004)
class UDamageType*                                 DamageType                                                // 0x0008(0x0008)
class AController*                                 InstigatedBy                                              // 0x0010(0x0008)
class AActor*                                      DamageCauser                                              // 0x0018(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ReceiveEndPlay
// 0x0001
struct FReceiveEndPlay
{
unsigned char                                      EndPlayReason                                             // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ReceiveHit
// 0x00C8
struct FReceiveHit
{
class UPrimitiveComponent*                         MyComp                                                    // 0x0000(0x0008)
class AActor*                                      Other                                                     // 0x0008(0x0008)
class UPrimitiveComponent*                         OtherComp                                                 // 0x0010(0x0008)
Bool                                               bSelfMoved                                                // 0x0018(0x0001)
struct FVector                                     HitLocation                                               // 0x001C(0x000C)
struct FVector                                     HitNormal                                                 // 0x0028(0x000C)
struct FVector                                     NormalImpulse                                             // 0x0034(0x000C)
struct FHitResult                                  Hit                                                       // 0x0040(0x0088)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ReceivePointDamage
// 0x00E0
struct FReceivePointDamage
{
float                                              Damage                                                    // 0x0000(0x0004)
class UDamageType*                                 DamageType                                                // 0x0008(0x0008)
struct FVector                                     HitLocation                                               // 0x0010(0x000C)
struct FVector                                     HitNormal                                                 // 0x001C(0x000C)
class UPrimitiveComponent*                         HitComponent                                              // 0x0028(0x0008)
struct FName                                       BoneName                                                  // 0x0030(0x0008)
struct FVector                                     ShotFromDirection                                         // 0x0038(0x000C)
class AController*                                 InstigatedBy                                              // 0x0048(0x0008)
class AActor*                                      DamageCauser                                              // 0x0050(0x0008)
struct FHitResult                                  HitInfo                                                   // 0x0058(0x0088)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ReceiveRadialDamage
// 0x00B8
struct FReceiveRadialDamage
{
float                                              DamageReceived                                            // 0x0000(0x0004)
class UDamageType*                                 DamageType                                                // 0x0008(0x0008)
struct FVector                                     Origin                                                    // 0x0010(0x000C)
struct FHitResult                                  HitInfo                                                   // 0x0020(0x0088)
class AController*                                 InstigatedBy                                              // 0x00A8(0x0008)
class AActor*                                      DamageCauser                                              // 0x00B0(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ReceiveScriptNetworkRemoteContent
// 0x0018
struct FReceiveScriptNetworkRemoteContent
{
struct FScriptNetworkRemoteContent                 Content                                                   // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ReceiveTick
// 0x0004
struct FReceiveTick
{
float                                              DeltaSeconds                                              // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.Actor.RemoveDynamicTag
// 0x0008
struct FRemoveDynamicTag
{
struct FName                                       Tag                                                       // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.RemoveTickPrerequisiteActor
// 0x0008
struct FRemoveTickPrerequisiteActor
{
class AActor*                                      PrerequisiteActor                                         // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.RemoveTickPrerequisiteComponent
// 0x0008
struct FRemoveTickPrerequisiteComponent
{
class UActorComponent*                             PrerequisiteComponent                                     // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ServerSendScriptNetworkRemoteContent
// 0x0018
struct FServerSendScriptNetworkRemoteContent
{
struct FScriptNetworkRemoteContent                 Content                                                   // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.Actor.ServerSendScriptNetworkRemoteContent_Unreliable
// 0x0018
struct FServerSendScriptNetworkRemoteContent_Unreliable
{
struct FScriptNetworkRemoteContent                 Content                                                   // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.Actor.SetActorConsideredHidden
// 0x0001
struct FSetActorConsideredHidden
{
Bool                                               bNewHidden                                                // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.SetActorEnableCollision
// 0x0001
struct FSetActorEnableCollision
{
Bool                                               bNewActorEnableCollision                                  // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.SetActorHiddenInGame
// 0x0001
struct FSetActorHiddenInGame
{
Bool                                               bNewHidden                                                // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.SetActorRelativeScale3D
// 0x000C
struct FSetActorRelativeScale3D
{
struct FVector                                     NewRelativeScale                                          // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.Actor.SetActorScale3D
// 0x000C
struct FSetActorScale3D
{
struct FVector                                     NewScale3D                                                // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.Actor.SetActorSimulatedRelevancy
// 0x0001
struct FSetActorSimulatedRelevancy
{
Bool                                               bIsRelevant                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.SetActorTickEnabled
// 0x0001
struct FSetActorTickEnabled
{
Bool                                               bEnabled                                                  // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.SetActorTickInterval
// 0x0004
struct FSetActorTickInterval
{
float                                              TickInterval                                              // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.Actor.SetForceOwnedMeshAlwaysRefreshBones
// 0x0001
struct FSetForceOwnedMeshAlwaysRefreshBones
{
Bool                                               bAlwaysRefreshBones                                       // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.SetGeneralCampID
// 0x0004
struct FSetGeneralCampID
{
int                                                InCampID                                                  // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.Actor.SetLifeSpan
// 0x0004
struct FSetLifeSpan
{
float                                              InLifespan                                                // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.Actor.SetNetDormancy
// 0x0001
struct FSetNetDormancy
{
unsigned char                                      NewDormancy                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.SetOwner
// 0x0008
struct FSetOwner
{
class AActor*                                      NewOwner                                                  // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.SetReplicateMovement
// 0x0001
struct FSetReplicateMovement
{
Bool                                               bInReplicateMovement                                      // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.SetReplicates
// 0x0001
struct FSetReplicates
{
Bool                                               bInReplicates                                             // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.SetTextureForceResidentFlag
// 0x0001
struct FSetTextureForceResidentFlag
{
Bool                                               bForceMiplevelsToBeResident                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.SetTickableWhenPaused
// 0x0001
struct FSetTickableWhenPaused
{
Bool                                               bTickableWhenPaused                                       // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.SetTickGroup
// 0x0001
struct FSetTickGroup
{
unsigned char                                      NewTickGroup                                              // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.Actor.SnapRootComponentTo
// 0x0010
struct FSnapRootComponentTo
{
class AActor*                                      InParentActor                                             // 0x0000(0x0008)
struct FName                                       InSocketName                                              // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.TickConstructComponentWithTime
// 0x000C
struct FTickConstructComponentWithTime
{
float                                              OneFrameConstructTimeMS                                   // 0x0000(0x0004)
Bool                                               bCreateImmediately                                        // 0x0004(0x0001)
float                                              ReturnValue                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.Actor.TriggerDeformEffect
// 0x0010
struct FTriggerDeformEffect
{
struct FVector                                     Origin                                                    // 0x0000(0x000C)
float                                              EffectRange                                               // 0x000C(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.Actor.TryGetBoneRetargetObj
// 0x0010
struct FTryGetBoneRetargetObj
{
class UObject*                                     InSourceObj                                               // 0x0000(0x0008)
class UObject*                                     ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.TryGetBoneRetargetObjForNotifyState
// 0x0010
struct FTryGetBoneRetargetObjForNotifyState
{
class UObject*                                     InTargetNotifyState                                       // 0x0000(0x0008)
class UObject*                                     ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.Actor.WasRecentlyRendered
// 0x0008
struct FWasRecentlyRendered
{
float                                              Tolerance                                                 // 0x0000(0x0004)
Bool                                               ReturnValue                                               // 0x0004(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.GameStateBase.GetPlayerRespawnDelay
// 0x0010
struct FGetPlayerRespawnDelay
{
class AController*                                 Controller                                                // 0x0000(0x0008)
float                                              ReturnValue                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.GameStateBase.GetPlayerStartTime
// 0x0010
struct FGetPlayerStartTime
{
class AController*                                 Controller                                                // 0x0000(0x0008)
float                                              ReturnValue                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.GameStateBase.GetServerWorldTimeSeconds
// 0x0004
struct FGetServerWorldTimeSeconds
{
float                                              ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.GameStateBase.GetServerWorldTimeSecondsForReplay
// 0x0004
struct FGetServerWorldTimeSecondsForReplay
{
float                                              ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.GameStateBase.HasBegunPlay
// 0x0001
struct FHasBegunPlay
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.GameStateBase.HasMatchStarted
// 0x0001
struct FHasMatchStarted
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.GameStateBase.OnRep_ReplicatedWorldTimeSeconds
// 0x0004
struct FOnRep_ReplicatedWorldTimeSeconds
{
float                                              OldValue                                                  // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.ProjectileMovementComponent.IsInterpolationComplete
// 0x0001
struct FIsInterpolationComplete
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.ProjectileMovementComponent.IsVelocityUnderSimulationThreshold
// 0x0001
struct FIsVelocityUnderSimulationThreshold
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.ProjectileMovementComponent.LimitVelocity
// 0x0018
struct FLimitVelocity
{
struct FVector                                     NewVelocity                                               // 0x0000(0x000C)
struct FVector                                     ReturnValue                                               // 0x000C(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.ProjectileMovementComponent.MoveInterpolationTarget
// 0x0018
struct FMoveInterpolationTarget
{
struct FVector                                     NewLocation                                               // 0x0000(0x000C)
struct FRotator                                    NewRotation                                               // 0x000C(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.ProjectileMovementComponent.SetInterpolatedComponent
// 0x0008
struct FSetInterpolatedComponent
{
class USceneComponent*                             Component                                                 // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.ProjectileMovementComponent.SetVelocityInLocalSpace
// 0x000C
struct FSetVelocityInLocalSpace
{
struct FVector                                     NewVelocity                                               // 0x0000(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.ProjectileMovementComponent.StopSimulating
// 0x0088
struct FStopSimulating
{
struct FHitResult                                  HitResult                                                 // 0x0000(0x0088)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.AddBlackResMapping
// 0x0050
struct FAddBlackResMapping
{
unsigned char                                      InPackageNames                                            // 0x0000(0x0050)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.AddFloatHistorySample
// 0x0048
struct FAddFloatHistorySample
{
float                                              Value                                                     // 0x0000(0x0004)
struct FDebugFloatHistory                          FloatHistory                                              // 0x0008(0x0020)
struct FDebugFloatHistory                          ReturnValue                                               // 0x0028(0x0020)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.AddResARMapping
// 0x0050
struct FAddResARMapping
{
unsigned char                                      InARPaths                                                 // 0x0000(0x0050)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.AddResMapping
// 0x0050
struct FAddResMapping
{
TMap<struct FName, struct FName>                   InPackageNameRemap                                        // 0x0000(0x0050)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.AddResPathMapping
// 0x0050
struct FAddResPathMapping
{
TMap<struct FString, struct FString>               InPackagePathRemap                                        // 0x0000(0x0050)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.BoxOverlapActors
// 0x0070
struct FBoxOverlapActors
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     BoxPos                                                    // 0x0008(0x000C)
struct FRotator                                    BoxRotation                                               // 0x0014(0x000C)
struct FVector                                     BoxExtent                                                 // 0x0020(0x000C)
TArray<unsigned char>                              ObjectTypes                                               // 0x0030(0x0010)
class UClass*                                      ActorClassFilter                                          // 0x0040(0x0008)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0048(0x0010)
TArray<class AActor*>                              OutActors                                                 // 0x0058(0x0010)
Bool                                               ReturnValue                                               // 0x0068(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.BoxOverlapAnyTest
// 0x0060
struct FBoxOverlapAnyTest
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     BoxPos                                                    // 0x0008(0x000C)
struct FRotator                                    Rotator                                                   // 0x0014(0x000C)
struct FVector                                     BoxExtent                                                 // 0x0020(0x000C)
TArray<unsigned char>                              ObjectTypes                                               // 0x0030(0x0010)
class UClass*                                      ActorClassFilter                                          // 0x0040(0x0008)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0048(0x0010)
Bool                                               ReturnValue                                               // 0x0058(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.BoxOverlapComponents
// 0x0070
struct FBoxOverlapComponents
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     BoxPos                                                    // 0x0008(0x000C)
struct FRotator                                    BoxRotation                                               // 0x0014(0x000C)
struct FVector                                     Extent                                                    // 0x0020(0x000C)
TArray<unsigned char>                              ObjectTypes                                               // 0x0030(0x0010)
class UClass*                                      ComponentClassFilter                                      // 0x0040(0x0008)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0048(0x0010)
TArray<class UPrimitiveComponent*>                 OutComponents                                             // 0x0058(0x0010)
Bool                                               ReturnValue                                               // 0x0068(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.BoxOverlapOBBActors
// 0x0070
struct FBoxOverlapOBBActors
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     BoxPos                                                    // 0x0008(0x000C)
struct FRotator                                    BoxRot                                                    // 0x0014(0x000C)
struct FVector                                     BoxExtent                                                 // 0x0020(0x000C)
TArray<unsigned char>                              ObjectTypes                                               // 0x0030(0x0010)
class UClass*                                      ActorClassFilter                                          // 0x0040(0x0008)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0048(0x0010)
TArray<class AActor*>                              OutActors                                                 // 0x0058(0x0010)
Bool                                               ReturnValue                                               // 0x0068(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.BoxOverlapOBBComponents
// 0x0070
struct FBoxOverlapOBBComponents
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     BoxPos                                                    // 0x0008(0x000C)
struct FRotator                                    BoxRot                                                    // 0x0014(0x000C)
struct FVector                                     Extent                                                    // 0x0020(0x000C)
TArray<unsigned char>                              ObjectTypes                                               // 0x0030(0x0010)
class UClass*                                      ComponentClassFilter                                      // 0x0040(0x0008)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0048(0x0010)
TArray<class UPrimitiveComponent*>                 OutComponents                                             // 0x0058(0x0010)
Bool                                               ReturnValue                                               // 0x0068(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.BoxTraceMulti
// 0x0098
struct FBoxTraceMulti
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
struct FVector                                     HalfSize                                                  // 0x0020(0x000C)
struct FRotator                                    Orientation                                               // 0x002C(0x000C)
unsigned char                                      TraceChannel                                              // 0x0038(0x0001)
Bool                                               bTraceComplex                                             // 0x0039(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0040(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0050(0x0001)
TArray<struct FHitResult>                          OutHits                                                   // 0x0058(0x0010)
Bool                                               bIgnoreSelf                                               // 0x0068(0x0001)
struct FLinearColor                                TraceColor                                                // 0x006C(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x007C(0x0010)
float                                              DrawTime                                                  // 0x008C(0x0004)
Bool                                               ReturnValue                                               // 0x0090(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.BoxTraceMultiByProfile
// 0x00A0
struct FBoxTraceMultiByProfile
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
struct FVector                                     HalfSize                                                  // 0x0020(0x000C)
struct FRotator                                    Orientation                                               // 0x002C(0x000C)
struct FName                                       ProfileName                                               // 0x0038(0x0008)
Bool                                               bTraceComplex                                             // 0x0040(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0048(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0058(0x0001)
TArray<struct FHitResult>                          OutHits                                                   // 0x0060(0x0010)
Bool                                               bIgnoreSelf                                               // 0x0070(0x0001)
struct FLinearColor                                TraceColor                                                // 0x0074(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x0084(0x0010)
float                                              DrawTime                                                  // 0x0094(0x0004)
Bool                                               ReturnValue                                               // 0x0098(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.BoxTraceMultiForObjects
// 0x00A8
struct FBoxTraceMultiForObjects
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
struct FVector                                     HalfSize                                                  // 0x0020(0x000C)
struct FRotator                                    Orientation                                               // 0x002C(0x000C)
TArray<unsigned char>                              ObjectTypes                                               // 0x0038(0x0010)
Bool                                               bTraceComplex                                             // 0x0048(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0050(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0060(0x0001)
TArray<struct FHitResult>                          OutHits                                                   // 0x0068(0x0010)
Bool                                               bIgnoreSelf                                               // 0x0078(0x0001)
struct FLinearColor                                TraceColor                                                // 0x007C(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x008C(0x0010)
float                                              DrawTime                                                  // 0x009C(0x0004)
Bool                                               ReturnValue                                               // 0x00A0(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.BoxTraceSingle
// 0x0110
struct FBoxTraceSingle
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
struct FVector                                     HalfSize                                                  // 0x0020(0x000C)
struct FRotator                                    Orientation                                               // 0x002C(0x000C)
unsigned char                                      TraceChannel                                              // 0x0038(0x0001)
Bool                                               bTraceComplex                                             // 0x0039(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0040(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0050(0x0001)
struct FHitResult                                  OutHit                                                    // 0x0058(0x0088)
Bool                                               bIgnoreSelf                                               // 0x00E0(0x0001)
struct FLinearColor                                TraceColor                                                // 0x00E4(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x00F4(0x0010)
float                                              DrawTime                                                  // 0x0104(0x0004)
Bool                                               ReturnValue                                               // 0x0108(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.BoxTraceSingleByProfile
// 0x0118
struct FBoxTraceSingleByProfile
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
struct FVector                                     HalfSize                                                  // 0x0020(0x000C)
struct FRotator                                    Orientation                                               // 0x002C(0x000C)
struct FName                                       ProfileName                                               // 0x0038(0x0008)
Bool                                               bTraceComplex                                             // 0x0040(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0048(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0058(0x0001)
struct FHitResult                                  OutHit                                                    // 0x0060(0x0088)
Bool                                               bIgnoreSelf                                               // 0x00E8(0x0001)
struct FLinearColor                                TraceColor                                                // 0x00EC(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x00FC(0x0010)
float                                              DrawTime                                                  // 0x010C(0x0004)
Bool                                               ReturnValue                                               // 0x0110(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.BoxTraceSingleForObjects
// 0x0120
struct FBoxTraceSingleForObjects
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
struct FVector                                     HalfSize                                                  // 0x0020(0x000C)
struct FRotator                                    Orientation                                               // 0x002C(0x000C)
TArray<unsigned char>                              ObjectTypes                                               // 0x0038(0x0010)
Bool                                               bTraceComplex                                             // 0x0048(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0050(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0060(0x0001)
struct FHitResult                                  OutHit                                                    // 0x0068(0x0088)
Bool                                               bIgnoreSelf                                               // 0x00F0(0x0001)
struct FLinearColor                                TraceColor                                                // 0x00F4(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x0104(0x0010)
float                                              DrawTime                                                  // 0x0114(0x0004)
Bool                                               ReturnValue                                               // 0x0118(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.BreakSoftClassPath
// 0x0028
struct FBreakSoftClassPath
{
struct FSoftClassPath                              InSoftClassPath                                           // 0x0000(0x0018)
struct FString                                     PathString                                                // 0x0018(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.BreakSoftObjectPath
// 0x0028
struct FBreakSoftObjectPath
{
struct FSoftObjectPath                             InSoftObjectPath                                          // 0x0000(0x0018)
struct FString                                     PathString                                                // 0x0018(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.CanLaunchURL
// 0x0018
struct FCanLaunchURL
{
struct FString                                     URL                                                       // 0x0000(0x0010)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.CapsuleOverlapActors
// 0x0060
struct FCapsuleOverlapActors
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     CapsulePos                                                // 0x0008(0x000C)
float                                              Radius                                                    // 0x0014(0x0004)
float                                              HalfHeight                                                // 0x0018(0x0004)
TArray<unsigned char>                              ObjectTypes                                               // 0x0020(0x0010)
class UClass*                                      ActorClassFilter                                          // 0x0030(0x0008)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0038(0x0010)
TArray<class AActor*>                              OutActors                                                 // 0x0048(0x0010)
Bool                                               ReturnValue                                               // 0x0058(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.CapsuleOverlapComponents
// 0x0060
struct FCapsuleOverlapComponents
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     CapsulePos                                                // 0x0008(0x000C)
float                                              Radius                                                    // 0x0014(0x0004)
float                                              HalfHeight                                                // 0x0018(0x0004)
TArray<unsigned char>                              ObjectTypes                                               // 0x0020(0x0010)
class UClass*                                      ComponentClassFilter                                      // 0x0030(0x0008)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0038(0x0010)
TArray<class UPrimitiveComponent*>                 OutComponents                                             // 0x0048(0x0010)
Bool                                               ReturnValue                                               // 0x0058(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.CapsuleTraceMulti
// 0x0088
struct FCapsuleTraceMulti
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
float                                              Radius                                                    // 0x0020(0x0004)
float                                              HalfHeight                                                // 0x0024(0x0004)
unsigned char                                      TraceChannel                                              // 0x0028(0x0001)
Bool                                               bTraceComplex                                             // 0x0029(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0030(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0040(0x0001)
TArray<struct FHitResult>                          OutHits                                                   // 0x0048(0x0010)
Bool                                               bIgnoreSelf                                               // 0x0058(0x0001)
struct FLinearColor                                TraceColor                                                // 0x005C(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x006C(0x0010)
float                                              DrawTime                                                  // 0x007C(0x0004)
Bool                                               ReturnValue                                               // 0x0080(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.CapsuleTraceMultiByProfile
// 0x0090
struct FCapsuleTraceMultiByProfile
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
float                                              Radius                                                    // 0x0020(0x0004)
float                                              HalfHeight                                                // 0x0024(0x0004)
struct FName                                       ProfileName                                               // 0x0028(0x0008)
Bool                                               bTraceComplex                                             // 0x0030(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0038(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0048(0x0001)
TArray<struct FHitResult>                          OutHits                                                   // 0x0050(0x0010)
Bool                                               bIgnoreSelf                                               // 0x0060(0x0001)
struct FLinearColor                                TraceColor                                                // 0x0064(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x0074(0x0010)
float                                              DrawTime                                                  // 0x0084(0x0004)
Bool                                               ReturnValue                                               // 0x0088(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.CapsuleTraceMultiForObjects
// 0x0098
struct FCapsuleTraceMultiForObjects
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
float                                              Radius                                                    // 0x0020(0x0004)
float                                              HalfHeight                                                // 0x0024(0x0004)
TArray<unsigned char>                              ObjectTypes                                               // 0x0028(0x0010)
Bool                                               bTraceComplex                                             // 0x0038(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0040(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0050(0x0001)
TArray<struct FHitResult>                          OutHits                                                   // 0x0058(0x0010)
Bool                                               bIgnoreSelf                                               // 0x0068(0x0001)
struct FLinearColor                                TraceColor                                                // 0x006C(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x007C(0x0010)
float                                              DrawTime                                                  // 0x008C(0x0004)
Bool                                               ReturnValue                                               // 0x0090(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.CapsuleTraceSingle
// 0x0100
struct FCapsuleTraceSingle
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
float                                              Radius                                                    // 0x0020(0x0004)
float                                              HalfHeight                                                // 0x0024(0x0004)
unsigned char                                      TraceChannel                                              // 0x0028(0x0001)
Bool                                               bTraceComplex                                             // 0x0029(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0030(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0040(0x0001)
struct FHitResult                                  OutHit                                                    // 0x0048(0x0088)
Bool                                               bIgnoreSelf                                               // 0x00D0(0x0001)
struct FLinearColor                                TraceColor                                                // 0x00D4(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x00E4(0x0010)
float                                              DrawTime                                                  // 0x00F4(0x0004)
Bool                                               ReturnValue                                               // 0x00F8(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.CapsuleTraceSingleByProfile
// 0x0108
struct FCapsuleTraceSingleByProfile
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
float                                              Radius                                                    // 0x0020(0x0004)
float                                              HalfHeight                                                // 0x0024(0x0004)
struct FName                                       ProfileName                                               // 0x0028(0x0008)
Bool                                               bTraceComplex                                             // 0x0030(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0038(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0048(0x0001)
struct FHitResult                                  OutHit                                                    // 0x0050(0x0088)
Bool                                               bIgnoreSelf                                               // 0x00D8(0x0001)
struct FLinearColor                                TraceColor                                                // 0x00DC(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x00EC(0x0010)
float                                              DrawTime                                                  // 0x00FC(0x0004)
Bool                                               ReturnValue                                               // 0x0100(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.CapsuleTraceSingleForObjects
// 0x0110
struct FCapsuleTraceSingleForObjects
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
float                                              Radius                                                    // 0x0020(0x0004)
float                                              HalfHeight                                                // 0x0024(0x0004)
TArray<unsigned char>                              ObjectTypes                                               // 0x0028(0x0010)
Bool                                               bTraceComplex                                             // 0x0038(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0040(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0050(0x0001)
struct FHitResult                                  OutHit                                                    // 0x0058(0x0088)
Bool                                               bIgnoreSelf                                               // 0x00E0(0x0001)
struct FLinearColor                                TraceColor                                                // 0x00E4(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x00F4(0x0010)
float                                              DrawTime                                                  // 0x0104(0x0004)
Bool                                               ReturnValue                                               // 0x0108(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.CollectGarbage
// 0x0001
struct FCollectGarbage
{
Bool                                               bFullPurge                                                // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.ComponentOverlapActors
// 0x0080
struct FComponentOverlapActors
{
class UPrimitiveComponent*                         Component                                                 // 0x0000(0x0008)
struct FTransform                                  ComponentTransform                                        // 0x0010(0x0030)
TArray<unsigned char>                              ObjectTypes                                               // 0x0040(0x0010)
class UClass*                                      ActorClassFilter                                          // 0x0050(0x0008)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0058(0x0010)
TArray<class AActor*>                              OutActors                                                 // 0x0068(0x0010)
Bool                                               ReturnValue                                               // 0x0078(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.ComponentOverlapComponents
// 0x0080
struct FComponentOverlapComponents
{
class UPrimitiveComponent*                         Component                                                 // 0x0000(0x0008)
struct FTransform                                  ComponentTransform                                        // 0x0010(0x0030)
TArray<unsigned char>                              ObjectTypes                                               // 0x0040(0x0010)
class UClass*                                      ComponentClassFilter                                      // 0x0050(0x0008)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0058(0x0010)
TArray<class UPrimitiveComponent*>                 OutComponents                                             // 0x0068(0x0010)
Bool                                               ReturnValue                                               // 0x0078(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.ControlScreensaver
// 0x0001
struct FControlScreensaver
{
Bool                                               bAllowScreenSaver                                         // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.Conv_ClassToSoftClassReference
// 0x0030
struct FConv_ClassToSoftClassReference
{
class UClass*                                      Class                                                     // 0x0000(0x0008)
unsigned char                                      ReturnValue                                               // 0x0008(0x0028)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.Conv_InterfaceToObject
// 0x0018
struct FConv_InterfaceToObject
{
TScriptInterface<class UInterface>                 Interface                                                 // 0x0000(0x0010)
class UObject*                                     ReturnValue                                               // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.Conv_ObjectToSoftObjectReference
// 0x0030
struct FConv_ObjectToSoftObjectReference
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
unsigned char                                      ReturnValue                                               // 0x0008(0x0028)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.Conv_PrimaryAssetIdToString
// 0x0020
struct FConv_PrimaryAssetIdToString
{
struct FPrimaryAssetId                             PrimaryAssetId                                            // 0x0000(0x0010)
struct FString                                     ReturnValue                                               // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.Conv_PrimaryAssetTypeToString
// 0x0018
struct FConv_PrimaryAssetTypeToString
{
struct FPrimaryAssetType                           PrimaryAssetType                                          // 0x0000(0x0008)
struct FString                                     ReturnValue                                               // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.Conv_SoftClassReferenceToClass
// 0x0030
struct FConv_SoftClassReferenceToClass
{
unsigned char                                      SoftClass                                                 // 0x0000(0x0028)
class UClass*                                      ReturnValue                                               // 0x0028(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.Conv_SoftClassReferenceToString
// 0x0038
struct FConv_SoftClassReferenceToString
{
unsigned char                                      SoftClassReference                                        // 0x0000(0x0028)
struct FString                                     ReturnValue                                               // 0x0028(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.Conv_SoftObjectReferenceToObject
// 0x0030
struct FConv_SoftObjectReferenceToObject
{
unsigned char                                      SoftObject                                                // 0x0000(0x0028)
class UObject*                                     ReturnValue                                               // 0x0028(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.Conv_SoftObjectReferenceToString
// 0x0038
struct FConv_SoftObjectReferenceToString
{
unsigned char                                      SoftObjectReference                                       // 0x0000(0x0028)
struct FString                                     ReturnValue                                               // 0x0028(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.CreateCopyForUndoBuffer
// 0x0008
struct FCreateCopyForUndoBuffer
{
class UObject*                                     ObjectToModify                                            // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.Delay
// 0x0028
struct FDelay
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
float                                              Duration                                                  // 0x0008(0x0004)
struct FLatentActionInfo                           LatentInfo                                                // 0x0010(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DelayReplacePreDuration
// 0x0028
struct FDelayReplacePreDuration
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
float                                              Duration                                                  // 0x0008(0x0004)
Bool                                               IsReplacePreDuration                                      // 0x000C(0x0001)
struct FLatentActionInfo                           LatentInfo                                                // 0x0010(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DelayUntilNextTick
// 0x0020
struct FDelayUntilNextTick
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FLatentActionInfo                           LatentInfo                                                // 0x0008(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DoesImplementInterface
// 0x0018
struct FDoesImplementInterface
{
class UObject*                                     TestObject                                                // 0x0000(0x0008)
class UClass*                                      Interface                                                 // 0x0008(0x0008)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugActorBounds
// 0x0020
struct FDrawDebugActorBounds
{
class AActor*                                      Actor                                                     // 0x0000(0x0008)
struct FLinearColor                                LinearColor                                               // 0x0008(0x0010)
float                                              Duration                                                  // 0x0018(0x0004)
float                                              Thickness                                                 // 0x001C(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugActorCollision
// 0x0020
struct FDrawDebugActorCollision
{
class AActor*                                      Actor                                                     // 0x0000(0x0008)
struct FLinearColor                                LinearColor                                               // 0x0008(0x0010)
float                                              Duration                                                  // 0x0018(0x0004)
float                                              Thickness                                                 // 0x001C(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugActorMoveTrack
// 0x0020
struct FDrawDebugActorMoveTrack
{
class AActor*                                      Actor                                                     // 0x0000(0x0008)
struct FLinearColor                                LinearColor                                               // 0x0008(0x0010)
float                                              Duration                                                  // 0x0018(0x0004)
float                                              Thickness                                                 // 0x001C(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugActorName
// 0x0028
struct FDrawDebugActorName
{
class AActor*                                      Actor                                                     // 0x0000(0x0008)
struct FVector                                     Offset                                                    // 0x0008(0x000C)
struct FLinearColor                                LinearColor                                               // 0x0014(0x0010)
float                                              Duration                                                  // 0x0024(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugArrow
// 0x0040
struct FDrawDebugArrow
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     LineStart                                                 // 0x0008(0x000C)
struct FVector                                     LineEnd                                                   // 0x0014(0x000C)
float                                              ArrowSize                                                 // 0x0020(0x0004)
struct FLinearColor                                LineColor                                                 // 0x0024(0x0010)
float                                              Duration                                                  // 0x0034(0x0004)
float                                              Thickness                                                 // 0x0038(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugBox
// 0x0048
struct FDrawDebugBox
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Center                                                    // 0x0008(0x000C)
struct FVector                                     Extent                                                    // 0x0014(0x000C)
struct FLinearColor                                LineColor                                                 // 0x0020(0x0010)
struct FRotator                                    Rotation                                                  // 0x0030(0x000C)
float                                              Duration                                                  // 0x003C(0x0004)
float                                              Thickness                                                 // 0x0040(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugCamera
// 0x0020
struct FDrawDebugCamera
{
class ACameraActor*                                CameraActor                                               // 0x0000(0x0008)
struct FLinearColor                                CameraColor                                               // 0x0008(0x0010)
float                                              Duration                                                  // 0x0018(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugCapsule
// 0x0040
struct FDrawDebugCapsule
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Center                                                    // 0x0008(0x000C)
float                                              HalfHeight                                                // 0x0014(0x0004)
float                                              Radius                                                    // 0x0018(0x0004)
struct FRotator                                    Rotation                                                  // 0x001C(0x000C)
struct FLinearColor                                LineColor                                                 // 0x0028(0x0010)
float                                              Duration                                                  // 0x0038(0x0004)
float                                              Thickness                                                 // 0x003C(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugCircle
// 0x0050
struct FDrawDebugCircle
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Center                                                    // 0x0008(0x000C)
float                                              Radius                                                    // 0x0014(0x0004)
int                                                NumSegments                                               // 0x0018(0x0004)
struct FLinearColor                                LineColor                                                 // 0x001C(0x0010)
float                                              Duration                                                  // 0x002C(0x0004)
float                                              Thickness                                                 // 0x0030(0x0004)
struct FVector                                     YAxis                                                     // 0x0034(0x000C)
struct FVector                                     ZAxis                                                     // 0x0040(0x000C)
Bool                                               bDrawAxis                                                 // 0x004C(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugCone
// 0x0048
struct FDrawDebugCone
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Origin                                                    // 0x0008(0x000C)
struct FVector                                     Direction                                                 // 0x0014(0x000C)
float                                              Length                                                    // 0x0020(0x0004)
float                                              AngleWidth                                                // 0x0024(0x0004)
float                                              AngleHeight                                               // 0x0028(0x0004)
int                                                NumSides                                                  // 0x002C(0x0004)
struct FLinearColor                                LineColor                                                 // 0x0030(0x0010)
float                                              Duration                                                  // 0x0040(0x0004)
float                                              Thickness                                                 // 0x0044(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugConeInDegrees
// 0x0048
struct FDrawDebugConeInDegrees
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Origin                                                    // 0x0008(0x000C)
struct FVector                                     Direction                                                 // 0x0014(0x000C)
float                                              Length                                                    // 0x0020(0x0004)
float                                              AngleWidth                                                // 0x0024(0x0004)
float                                              AngleHeight                                               // 0x0028(0x0004)
int                                                NumSides                                                  // 0x002C(0x0004)
struct FLinearColor                                LineColor                                                 // 0x0030(0x0010)
float                                              Duration                                                  // 0x0040(0x0004)
float                                              Thickness                                                 // 0x0044(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugCoordinateSystem
// 0x0030
struct FDrawDebugCoordinateSystem
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     AxisLoc                                                   // 0x0008(0x000C)
struct FRotator                                    AxisRot                                                   // 0x0014(0x000C)
float                                              Scale                                                     // 0x0020(0x0004)
float                                              Duration                                                  // 0x0024(0x0004)
float                                              Thickness                                                 // 0x0028(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugCylinder
// 0x0040
struct FDrawDebugCylinder
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
float                                              Radius                                                    // 0x0020(0x0004)
int                                                Segments                                                  // 0x0024(0x0004)
struct FLinearColor                                LineColor                                                 // 0x0028(0x0010)
float                                              Duration                                                  // 0x0038(0x0004)
float                                              Thickness                                                 // 0x003C(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugDistance
// 0x0038
struct FDrawDebugDistance
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Self                                                      // 0x0008(0x000C)
struct FVector                                     Target                                                    // 0x0014(0x000C)
struct FLinearColor                                LinearColor                                               // 0x0020(0x0010)
float                                              Duration                                                  // 0x0030(0x0004)
float                                              Thickness                                                 // 0x0034(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugFloatHistoryLocation
// 0x0050
struct FDrawDebugFloatHistoryLocation
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FDebugFloatHistory                          FloatHistory                                              // 0x0008(0x0020)
struct FVector                                     DrawLocation                                              // 0x0028(0x000C)
struct FVector2D                                   DrawSize                                                  // 0x0034(0x0008)
struct FLinearColor                                DrawColor                                                 // 0x003C(0x0010)
float                                              Duration                                                  // 0x004C(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugFloatHistoryTransform
// 0x0080
struct FDrawDebugFloatHistoryTransform
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FDebugFloatHistory                          FloatHistory                                              // 0x0008(0x0020)
struct FTransform                                  DrawTransform                                             // 0x0030(0x0030)
struct FVector2D                                   DrawSize                                                  // 0x0060(0x0008)
struct FLinearColor                                DrawColor                                                 // 0x0068(0x0010)
float                                              Duration                                                  // 0x0078(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugFrustum
// 0x0060
struct FDrawDebugFrustum
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FTransform                                  FrustumTransform                                          // 0x0010(0x0030)
struct FLinearColor                                FrustumColor                                              // 0x0040(0x0010)
float                                              Duration                                                  // 0x0050(0x0004)
float                                              Thickness                                                 // 0x0054(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugLine
// 0x0038
struct FDrawDebugLine
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     LineStart                                                 // 0x0008(0x000C)
struct FVector                                     LineEnd                                                   // 0x0014(0x000C)
struct FLinearColor                                LineColor                                                 // 0x0020(0x0010)
float                                              Duration                                                  // 0x0030(0x0004)
float                                              Thickness                                                 // 0x0034(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugPlane
// 0x0050
struct FDrawDebugPlane
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FPlane                                      PlaneCoordinates                                          // 0x0010(0x0010)
struct FVector                                     Location                                                  // 0x0020(0x000C)
float                                              Size                                                      // 0x002C(0x0004)
struct FLinearColor                                PlaneColor                                                // 0x0030(0x0010)
float                                              Duration                                                  // 0x0040(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugPoint
// 0x0030
struct FDrawDebugPoint
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Position                                                  // 0x0008(0x000C)
float                                              Size                                                      // 0x0014(0x0004)
struct FLinearColor                                PointColor                                                // 0x0018(0x0010)
float                                              Duration                                                  // 0x0028(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugSphere
// 0x0038
struct FDrawDebugSphere
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Center                                                    // 0x0008(0x000C)
float                                              Radius                                                    // 0x0014(0x0004)
int                                                Segments                                                  // 0x0018(0x0004)
struct FLinearColor                                LineColor                                                 // 0x001C(0x0010)
float                                              Duration                                                  // 0x002C(0x0004)
float                                              Thickness                                                 // 0x0030(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugString
// 0x0048
struct FDrawDebugString
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     TextLocation                                              // 0x0008(0x000C)
struct FString                                     Text                                                      // 0x0018(0x0010)
class AActor*                                      TestBaseActor                                             // 0x0028(0x0008)
struct FLinearColor                                TextColor                                                 // 0x0030(0x0010)
float                                              Duration                                                  // 0x0040(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.DrawDebugTargetAimedAt
// 0x0010
struct FDrawDebugTargetAimedAt
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
float                                              Length                                                    // 0x0008(0x0004)
float                                              DrawTime                                                  // 0x000C(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.EqualEqual_PrimaryAssetId
// 0x0028
struct FEqualEqual_PrimaryAssetId
{
struct FPrimaryAssetId                             A                                                         // 0x0000(0x0010)
struct FPrimaryAssetId                             B                                                         // 0x0010(0x0010)
Bool                                               ReturnValue                                               // 0x0020(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.EqualEqual_PrimaryAssetType
// 0x0018
struct FEqualEqual_PrimaryAssetType
{
struct FPrimaryAssetType                           A                                                         // 0x0000(0x0008)
struct FPrimaryAssetType                           B                                                         // 0x0008(0x0008)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.EqualEqual_SoftClassReference
// 0x0058
struct FEqualEqual_SoftClassReference
{
unsigned char                                      A                                                         // 0x0000(0x0028)
unsigned char                                      B                                                         // 0x0028(0x0028)
Bool                                               ReturnValue                                               // 0x0050(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.EqualEqual_SoftObjectReference
// 0x0058
struct FEqualEqual_SoftObjectReference
{
unsigned char                                      A                                                         // 0x0000(0x0028)
unsigned char                                      B                                                         // 0x0028(0x0028)
Bool                                               ReturnValue                                               // 0x0050(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.ExecuteConsoleCommand
// 0x0028
struct FExecuteConsoleCommand
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FString                                     Command                                                   // 0x0008(0x0010)
class APlayerController*                           SpecificPlayer                                            // 0x0018(0x0008)
Bool                                               bDisableCheck                                             // 0x0020(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.ExecuteConsoleCommandDisableCheck
// 0x0020
struct FExecuteConsoleCommandDisableCheck
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FString                                     Command                                                   // 0x0008(0x0010)
class APlayerController*                           SpecificPlayer                                            // 0x0018(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.FlushDebugStrings
// 0x0008
struct FFlushDebugStrings
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.FlushPersistentDebugLines
// 0x0008
struct FFlushPersistentDebugLines
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetActorBounds
// 0x0020
struct FGetActorBounds
{
class AActor*                                      Actor                                                     // 0x0000(0x0008)
struct FVector                                     Origin                                                    // 0x0008(0x000C)
struct FVector                                     BoxExtent                                                 // 0x0014(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetActorListFromComponentList
// 0x0028
struct FGetActorListFromComponentList
{
TArray<class UPrimitiveComponent*>                 ComponentList                                             // 0x0000(0x0010)
class UClass*                                      ActorClassFilter                                          // 0x0010(0x0008)
TArray<class AActor*>                              OutActorList                                              // 0x0018(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetAdIDCount
// 0x0004
struct FGetAdIDCount
{
int                                                ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetClassDisplayName
// 0x0018
struct FGetClassDisplayName
{
class UClass*                                      Class                                                     // 0x0000(0x0008)
struct FString                                     ReturnValue                                               // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetClassFromPrimaryAssetId
// 0x0018
struct FGetClassFromPrimaryAssetId
{
struct FPrimaryAssetId                             PrimaryAssetId                                            // 0x0000(0x0010)
class UClass*                                      ReturnValue                                               // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetCommandLine
// 0x0010
struct FGetCommandLine
{
struct FString                                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetComponentBounds
// 0x0028
struct FGetComponentBounds
{
class USceneComponent*                             Component                                                 // 0x0000(0x0008)
struct FVector                                     Origin                                                    // 0x0008(0x000C)
struct FVector                                     BoxExtent                                                 // 0x0014(0x000C)
float                                              SphereRadius                                              // 0x0020(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetConsoleVariableBoolValue
// 0x0018
struct FGetConsoleVariableBoolValue
{
struct FString                                     VariableName                                              // 0x0000(0x0010)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetConsoleVariableFloatValue
// 0x0018
struct FGetConsoleVariableFloatValue
{
struct FString                                     VariableName                                              // 0x0000(0x0010)
float                                              ReturnValue                                               // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetConsoleVariableIntValue
// 0x0018
struct FGetConsoleVariableIntValue
{
struct FString                                     VariableName                                              // 0x0000(0x0010)
int                                                ReturnValue                                               // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetConvenientWindowedResolutions
// 0x0018
struct FGetConvenientWindowedResolutions
{
TArray<struct FIntPoint>                           Resolutions                                               // 0x0000(0x0010)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetCurrentBundleState
// 0x0030
struct FGetCurrentBundleState
{
struct FPrimaryAssetId                             PrimaryAssetId                                            // 0x0000(0x0010)
Bool                                               bForceCurrentState                                        // 0x0010(0x0001)
TArray<struct FName>                               OutBundles                                                // 0x0018(0x0010)
Bool                                               ReturnValue                                               // 0x0028(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetDefaultLanguage
// 0x0010
struct FGetDefaultLanguage
{
struct FString                                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetDefaultLocale
// 0x0010
struct FGetDefaultLocale
{
struct FString                                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetDelegateResolvedPackagePath
// 0x0020
struct FGetDelegateResolvedPackagePath
{
struct FString                                     InSourcePackagePath                                       // 0x0000(0x0010)
struct FString                                     ReturnValue                                               // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetDeviceId
// 0x0010
struct FGetDeviceId
{
struct FString                                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetDisplayName
// 0x0018
struct FGetDisplayName
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FString                                     ReturnValue                                               // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetEngineVersion
// 0x0010
struct FGetEngineVersion
{
struct FString                                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetGameBundleId
// 0x0010
struct FGetGameBundleId
{
struct FString                                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetGameName
// 0x0010
struct FGetGameName
{
struct FString                                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetGameTimeInSeconds
// 0x0010
struct FGetGameTimeInSeconds
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
float                                              ReturnValue                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetLocalCurrencyCode
// 0x0010
struct FGetLocalCurrencyCode
{
struct FString                                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetLocalCurrencySymbol
// 0x0010
struct FGetLocalCurrencySymbol
{
struct FString                                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetMinYResolutionFor3DView
// 0x0004
struct FGetMinYResolutionFor3DView
{
int                                                ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetMinYResolutionForUI
// 0x0004
struct FGetMinYResolutionForUI
{
int                                                ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetObjectFromPrimaryAssetId
// 0x0018
struct FGetObjectFromPrimaryAssetId
{
struct FPrimaryAssetId                             PrimaryAssetId                                            // 0x0000(0x0010)
class UObject*                                     ReturnValue                                               // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetObjectName
// 0x0018
struct FGetObjectName
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FString                                     ReturnValue                                               // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetOriginalPath
// 0x0018
struct FGetOriginalPath
{
struct FName                                       Path                                                      // 0x0000(0x0008)
struct FName                                       OriginalPath                                              // 0x0008(0x0008)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetPathName
// 0x0018
struct FGetPathName
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FString                                     ReturnValue                                               // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetPlatformUserName
// 0x0010
struct FGetPlatformUserName
{
struct FString                                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetPreferredLanguages
// 0x0010
struct FGetPreferredLanguages
{
TArray<struct FString>                             ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetPrimaryAssetIdFromClass
// 0x0018
struct FGetPrimaryAssetIdFromClass
{
class UClass*                                      Class                                                     // 0x0000(0x0008)
struct FPrimaryAssetId                             ReturnValue                                               // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetPrimaryAssetIdFromObject
// 0x0018
struct FGetPrimaryAssetIdFromObject
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FPrimaryAssetId                             ReturnValue                                               // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetPrimaryAssetIdFromSoftClassReference
// 0x0038
struct FGetPrimaryAssetIdFromSoftClassReference
{
unsigned char                                      SoftClassReference                                        // 0x0000(0x0028)
struct FPrimaryAssetId                             ReturnValue                                               // 0x0028(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetPrimaryAssetIdFromSoftObjectReference
// 0x0038
struct FGetPrimaryAssetIdFromSoftObjectReference
{
unsigned char                                      SoftObjectReference                                       // 0x0000(0x0028)
struct FPrimaryAssetId                             ReturnValue                                               // 0x0028(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetPrimaryAssetIdList
// 0x0018
struct FGetPrimaryAssetIdList
{
struct FPrimaryAssetType                           PrimaryAssetType                                          // 0x0000(0x0008)
TArray<struct FPrimaryAssetId>                     OutPrimaryAssetIdList                                     // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetPrimaryAssetsWithBundleState
// 0x0048
struct FGetPrimaryAssetsWithBundleState
{
TArray<struct FName>                               RequiredBundles                                           // 0x0000(0x0010)
TArray<struct FName>                               ExcludedBundles                                           // 0x0010(0x0010)
TArray<struct FPrimaryAssetType>                   ValidTypes                                                // 0x0020(0x0010)
Bool                                               bForceCurrentState                                        // 0x0030(0x0001)
TArray<struct FPrimaryAssetId>                     OutPrimaryAssetIdList                                     // 0x0038(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetRenderingDetailMode
// 0x0004
struct FGetRenderingDetailMode
{
int                                                ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetRenderingMaterialQualityLevel
// 0x0004
struct FGetRenderingMaterialQualityLevel
{
int                                                ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetSoftClassReferenceFromPrimaryAssetId
// 0x0038
struct FGetSoftClassReferenceFromPrimaryAssetId
{
struct FPrimaryAssetId                             PrimaryAssetId                                            // 0x0000(0x0010)
unsigned char                                      ReturnValue                                               // 0x0010(0x0028)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetSoftObjectReferenceFromPrimaryAssetId
// 0x0038
struct FGetSoftObjectReferenceFromPrimaryAssetId
{
struct FPrimaryAssetId                             PrimaryAssetId                                            // 0x0000(0x0010)
unsigned char                                      ReturnValue                                               // 0x0010(0x0028)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetSupportedFullscreenResolutions
// 0x0018
struct FGetSupportedFullscreenResolutions
{
TArray<struct FIntPoint>                           Resolutions                                               // 0x0000(0x0010)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetTimeSinceLastPendingKillPurge
// 0x0004
struct FGetTimeSinceLastPendingKillPurge
{
float                                              ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetUniqueDeviceId
// 0x0010
struct FGetUniqueDeviceId
{
struct FString                                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.GetVolumeButtonsHandledBySystem
// 0x0001
struct FGetVolumeButtonsHandledBySystem
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.IsARPathActivated
// 0x0018
struct FIsARPathActivated
{
struct FString                                     InARPath                                                  // 0x0000(0x0010)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.IsControllerAssignedToGamepad
// 0x0008
struct FIsControllerAssignedToGamepad
{
int                                                ControllerId                                              // 0x0000(0x0004)
Bool                                               ReturnValue                                               // 0x0004(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.IsDedicatedServer
// 0x0010
struct FIsDedicatedServer
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.IsInterstitialAdAvailable
// 0x0001
struct FIsInterstitialAdAvailable
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.IsInterstitialAdRequested
// 0x0001
struct FIsInterstitialAdRequested
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.IsLoggedIn
// 0x0010
struct FIsLoggedIn
{
class APlayerController*                           SpecificPlayer                                            // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.IsPackagedForDistribution
// 0x0001
struct FIsPackagedForDistribution
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.IsPackageNameResolverBinded
// 0x0001
struct FIsPackageNameResolverBinded
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.IsRecycled
// 0x0010
struct FIsRecycled
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.IsResARMapping
// 0x0018
struct FIsResARMapping
{
struct FString                                     InARPath                                                  // 0x0000(0x0010)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.IsServer
// 0x0010
struct FIsServer
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.IsStandalone
// 0x0010
struct FIsStandalone
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.IsValid
// 0x0010
struct FIsValid
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.IsValidClass
// 0x0010
struct FIsValidClass
{
class UClass*                                      Class                                                     // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.IsValidPrimaryAssetId
// 0x0018
struct FIsValidPrimaryAssetId
{
struct FPrimaryAssetId                             PrimaryAssetId                                            // 0x0000(0x0010)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.IsValidPrimaryAssetType
// 0x0010
struct FIsValidPrimaryAssetType
{
struct FPrimaryAssetType                           PrimaryAssetType                                          // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.IsValidSoftClassReference
// 0x0030
struct FIsValidSoftClassReference
{
unsigned char                                      SoftClassReference                                        // 0x0000(0x0028)
Bool                                               ReturnValue                                               // 0x0028(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.IsValidSoftObjectReference
// 0x0030
struct FIsValidSoftObjectReference
{
unsigned char                                      SoftObjectReference                                       // 0x0000(0x0028)
Bool                                               ReturnValue                                               // 0x0028(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.IterateAddResARMapping
// 0x0060
struct FIterateAddResARMapping
{
struct FString                                     InARRoot                                                  // 0x0000(0x0010)
unsigned char                                      InARPaths                                                 // 0x0010(0x0050)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.IterateRemoveResARMapping
// 0x0060
struct FIterateRemoveResARMapping
{
struct FString                                     InARRoot                                                  // 0x0000(0x0010)
unsigned char                                      InARPaths                                                 // 0x0010(0x0050)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_ClearAndInvalidateTimerHandle
// 0x0010
struct FK2_ClearAndInvalidateTimerHandle
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FTimerHandle                                Handle                                                    // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_ClearTimer
// 0x0018
struct FK2_ClearTimer
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FString                                     FunctionName                                              // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_ClearTimerDelegate
// 0x0010
struct FK2_ClearTimerDelegate
{
struct FScriptDelegate                             Delegate                                                  // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_ClearTimerHandle
// 0x0010
struct FK2_ClearTimerHandle
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FTimerHandle                                Handle                                                    // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_GetTimerElapsedTime
// 0x0020
struct FK2_GetTimerElapsedTime
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FString                                     FunctionName                                              // 0x0008(0x0010)
float                                              ReturnValue                                               // 0x0018(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_GetTimerElapsedTimeDelegate
// 0x0018
struct FK2_GetTimerElapsedTimeDelegate
{
struct FScriptDelegate                             Delegate                                                  // 0x0000(0x0010)
float                                              ReturnValue                                               // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_GetTimerElapsedTimeHandle
// 0x0018
struct FK2_GetTimerElapsedTimeHandle
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FTimerHandle                                Handle                                                    // 0x0008(0x0008)
float                                              ReturnValue                                               // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_GetTimerRemainingTime
// 0x0020
struct FK2_GetTimerRemainingTime
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FString                                     FunctionName                                              // 0x0008(0x0010)
float                                              ReturnValue                                               // 0x0018(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_GetTimerRemainingTimeDelegate
// 0x0018
struct FK2_GetTimerRemainingTimeDelegate
{
struct FScriptDelegate                             Delegate                                                  // 0x0000(0x0010)
float                                              ReturnValue                                               // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_GetTimerRemainingTimeHandle
// 0x0018
struct FK2_GetTimerRemainingTimeHandle
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FTimerHandle                                Handle                                                    // 0x0008(0x0008)
float                                              ReturnValue                                               // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_InvalidateTimerHandle
// 0x0010
struct FK2_InvalidateTimerHandle
{
struct FTimerHandle                                Handle                                                    // 0x0000(0x0008)
struct FTimerHandle                                ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_IsTimerActive
// 0x0020
struct FK2_IsTimerActive
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FString                                     FunctionName                                              // 0x0008(0x0010)
Bool                                               ReturnValue                                               // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_IsTimerActiveDelegate
// 0x0018
struct FK2_IsTimerActiveDelegate
{
struct FScriptDelegate                             Delegate                                                  // 0x0000(0x0010)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_IsTimerActiveHandle
// 0x0018
struct FK2_IsTimerActiveHandle
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FTimerHandle                                Handle                                                    // 0x0008(0x0008)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_IsTimerPaused
// 0x0020
struct FK2_IsTimerPaused
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FString                                     FunctionName                                              // 0x0008(0x0010)
Bool                                               ReturnValue                                               // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_IsTimerPausedDelegate
// 0x0018
struct FK2_IsTimerPausedDelegate
{
struct FScriptDelegate                             Delegate                                                  // 0x0000(0x0010)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_IsTimerPausedHandle
// 0x0018
struct FK2_IsTimerPausedHandle
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FTimerHandle                                Handle                                                    // 0x0008(0x0008)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_IsValidTimerHandle
// 0x0010
struct FK2_IsValidTimerHandle
{
struct FTimerHandle                                Handle                                                    // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_PauseTimer
// 0x0018
struct FK2_PauseTimer
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FString                                     FunctionName                                              // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_PauseTimerDelegate
// 0x0010
struct FK2_PauseTimerDelegate
{
struct FScriptDelegate                             Delegate                                                  // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_PauseTimerHandle
// 0x0010
struct FK2_PauseTimerHandle
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FTimerHandle                                Handle                                                    // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_SetTimer
// 0x0028
struct FK2_SetTimer
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FString                                     FunctionName                                              // 0x0008(0x0010)
float                                              Time                                                      // 0x0018(0x0004)
Bool                                               bLooping                                                  // 0x001C(0x0001)
struct FTimerHandle                                ReturnValue                                               // 0x0020(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_SetTimerDelegate
// 0x0020
struct FK2_SetTimerDelegate
{
struct FScriptDelegate                             Delegate                                                  // 0x0000(0x0010)
float                                              Time                                                      // 0x0010(0x0004)
Bool                                               bLooping                                                  // 0x0014(0x0001)
struct FTimerHandle                                ReturnValue                                               // 0x0018(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_SetTimerDelegateForLua
// 0x0028
struct FK2_SetTimerDelegateForLua
{
struct FScriptDelegate                             Delegate                                                  // 0x0000(0x0010)
class UObject*                                     Object                                                    // 0x0010(0x0008)
float                                              Time                                                      // 0x0018(0x0004)
Bool                                               bLooping                                                  // 0x001C(0x0001)
struct FTimerHandle                                ReturnValue                                               // 0x0020(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_SetTimerForNextTick
// 0x0018
struct FK2_SetTimerForNextTick
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FString                                     FunctionName                                              // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_SetTimerForNextTickDelegate
// 0x0010
struct FK2_SetTimerForNextTickDelegate
{
struct FScriptDelegate                             Delegate                                                  // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_SetTimerTickDelegate
// 0x0020
struct FK2_SetTimerTickDelegate
{
struct FScriptDelegate                             Delegate                                                  // 0x0000(0x0010)
float                                              Time                                                      // 0x0010(0x0004)
Bool                                               InExeFirst                                                // 0x0014(0x0001)
struct FTimerHandle                                ReturnValue                                               // 0x0018(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_TimerExists
// 0x0020
struct FK2_TimerExists
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FString                                     FunctionName                                              // 0x0008(0x0010)
Bool                                               ReturnValue                                               // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_TimerExistsDelegate
// 0x0018
struct FK2_TimerExistsDelegate
{
struct FScriptDelegate                             Delegate                                                  // 0x0000(0x0010)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_TimerExistsHandle
// 0x0018
struct FK2_TimerExistsHandle
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FTimerHandle                                Handle                                                    // 0x0008(0x0008)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_UnPauseTimer
// 0x0018
struct FK2_UnPauseTimer
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FString                                     FunctionName                                              // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_UnPauseTimerDelegate
// 0x0010
struct FK2_UnPauseTimerDelegate
{
struct FScriptDelegate                             Delegate                                                  // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.K2_UnPauseTimerHandle
// 0x0010
struct FK2_UnPauseTimerHandle
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FTimerHandle                                Handle                                                    // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.LaunchURL
// 0x0010
struct FLaunchURL
{
struct FString                                     URL                                                       // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.LineTraceMulti
// 0x0080
struct FLineTraceMulti
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
unsigned char                                      TraceChannel                                              // 0x0020(0x0001)
Bool                                               bTraceComplex                                             // 0x0021(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0028(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0038(0x0001)
TArray<struct FHitResult>                          OutHits                                                   // 0x0040(0x0010)
Bool                                               bIgnoreSelf                                               // 0x0050(0x0001)
struct FLinearColor                                TraceColor                                                // 0x0054(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x0064(0x0010)
float                                              DrawTime                                                  // 0x0074(0x0004)
Bool                                               ReturnValue                                               // 0x0078(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.LineTraceMultiByProfile
// 0x0088
struct FLineTraceMultiByProfile
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
struct FName                                       ProfileName                                               // 0x0020(0x0008)
Bool                                               bTraceComplex                                             // 0x0028(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0030(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0040(0x0001)
TArray<struct FHitResult>                          OutHits                                                   // 0x0048(0x0010)
Bool                                               bIgnoreSelf                                               // 0x0058(0x0001)
struct FLinearColor                                TraceColor                                                // 0x005C(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x006C(0x0010)
float                                              DrawTime                                                  // 0x007C(0x0004)
Bool                                               ReturnValue                                               // 0x0080(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.LineTraceMultiForObjects
// 0x0090
struct FLineTraceMultiForObjects
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
TArray<unsigned char>                              ObjectTypes                                               // 0x0020(0x0010)
Bool                                               bTraceComplex                                             // 0x0030(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0038(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0048(0x0001)
TArray<struct FHitResult>                          OutHits                                                   // 0x0050(0x0010)
Bool                                               bIgnoreSelf                                               // 0x0060(0x0001)
struct FLinearColor                                TraceColor                                                // 0x0064(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x0074(0x0010)
float                                              DrawTime                                                  // 0x0084(0x0004)
Bool                                               ReturnValue                                               // 0x0088(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.LineTraceSingle
// 0x00F8
struct FLineTraceSingle
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
unsigned char                                      TraceChannel                                              // 0x0020(0x0001)
Bool                                               bTraceComplex                                             // 0x0021(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0028(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0038(0x0001)
struct FHitResult                                  OutHit                                                    // 0x0040(0x0088)
Bool                                               bIgnoreSelf                                               // 0x00C8(0x0001)
struct FLinearColor                                TraceColor                                                // 0x00CC(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x00DC(0x0010)
float                                              DrawTime                                                  // 0x00EC(0x0004)
Bool                                               ReturnValue                                               // 0x00F0(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.LineTraceSingleByObjectType
// 0x0108
struct FLineTraceSingleByObjectType
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
TArray<unsigned char>                              ObjectTypes                                               // 0x0020(0x0010)
Bool                                               bTraceComplex                                             // 0x0030(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0038(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0048(0x0001)
struct FHitResult                                  OutHit                                                    // 0x0050(0x0088)
Bool                                               bIgnoreSelf                                               // 0x00D8(0x0001)
struct FLinearColor                                TraceColor                                                // 0x00DC(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x00EC(0x0010)
float                                              DrawTime                                                  // 0x00FC(0x0004)
Bool                                               ReturnValue                                               // 0x0100(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.LineTraceSingleByProfile
// 0x0100
struct FLineTraceSingleByProfile
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
struct FName                                       ProfileName                                               // 0x0020(0x0008)
Bool                                               bTraceComplex                                             // 0x0028(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0030(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0040(0x0001)
struct FHitResult                                  OutHit                                                    // 0x0048(0x0088)
Bool                                               bIgnoreSelf                                               // 0x00D0(0x0001)
struct FLinearColor                                TraceColor                                                // 0x00D4(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x00E4(0x0010)
float                                              DrawTime                                                  // 0x00F4(0x0004)
Bool                                               ReturnValue                                               // 0x00F8(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.LineTraceSingleForObjects
// 0x0108
struct FLineTraceSingleForObjects
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
TArray<unsigned char>                              ObjectTypes                                               // 0x0020(0x0010)
Bool                                               bTraceComplex                                             // 0x0030(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0038(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0048(0x0001)
struct FHitResult                                  OutHit                                                    // 0x0050(0x0088)
Bool                                               bIgnoreSelf                                               // 0x00D8(0x0001)
struct FLinearColor                                TraceColor                                                // 0x00DC(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x00EC(0x0010)
float                                              DrawTime                                                  // 0x00FC(0x0004)
Bool                                               ReturnValue                                               // 0x0100(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.LoadAsset
// 0x0058
struct FLoadAsset
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
unsigned char                                      Asset                                                     // 0x0008(0x0028)
struct FScriptDelegate                             OnLoaded                                                  // 0x0030(0x0010)
struct FLatentActionInfo                           LatentInfo                                                // 0x0040(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.LoadAssetClass
// 0x0058
struct FLoadAssetClass
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
unsigned char                                      AssetClass                                                // 0x0008(0x0028)
struct FScriptDelegate                             OnLoaded                                                  // 0x0030(0x0010)
struct FLatentActionInfo                           LatentInfo                                                // 0x0040(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.LoadInterstitialAd
// 0x0004
struct FLoadInterstitialAd
{
int                                                AdIdIndex                                                 // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.MakeLiteralBool
// 0x0002
struct FMakeLiteralBool
{
Bool                                               Value                                                     // 0x0000(0x0001)
Bool                                               ReturnValue                                               // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.MakeLiteralByte
// 0x0002
struct FMakeLiteralByte
{
unsigned char                                      Value                                                     // 0x0000(0x0001)
unsigned char                                      ReturnValue                                               // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.MakeLiteralFloat
// 0x0008
struct FMakeLiteralFloat
{
float                                              Value                                                     // 0x0000(0x0004)
float                                              ReturnValue                                               // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.MakeLiteralInt
// 0x0008
struct FMakeLiteralInt
{
int                                                Value                                                     // 0x0000(0x0004)
int                                                ReturnValue                                               // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.MakeLiteralInt64
// 0x0010
struct FMakeLiteralInt64
{
int64_t                                            Value                                                     // 0x0000(0x0008)
int64_t                                            ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.MakeLiteralName
// 0x0010
struct FMakeLiteralName
{
struct FName                                       Value                                                     // 0x0000(0x0008)
struct FName                                       ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.MakeLiteralString
// 0x0020
struct FMakeLiteralString
{
struct FString                                     Value                                                     // 0x0000(0x0010)
struct FString                                     ReturnValue                                               // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.MakeLiteralText
// 0x0030
struct FMakeLiteralText
{
struct FText                                       Value                                                     // 0x0000(0x0018)
struct FText                                       ReturnValue                                               // 0x0018(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.MakeSoftObjectPath
// 0x0028
struct FMakeSoftObjectPath
{
struct FString                                     PathString                                                // 0x0000(0x0010)
struct FSoftObjectPath                             ReturnValue                                               // 0x0010(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.MoveComponentTo
// 0x0048
struct FMoveComponentTo
{
class USceneComponent*                             Component                                                 // 0x0000(0x0008)
struct FVector                                     TargetRelativeLocation                                    // 0x0008(0x000C)
struct FRotator                                    TargetRelativeRotation                                    // 0x0014(0x000C)
Bool                                               bEaseOut                                                  // 0x0020(0x0001)
Bool                                               bEaseIn                                                   // 0x0021(0x0001)
float                                              OverTime                                                  // 0x0024(0x0004)
Bool                                               bForceShortestRotationPath                                // 0x0028(0x0001)
unsigned char                                      MoveAction                                                // 0x0029(0x0001)
struct FLatentActionInfo                           LatentInfo                                                // 0x0030(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.NotEqual_PrimaryAssetId
// 0x0028
struct FNotEqual_PrimaryAssetId
{
struct FPrimaryAssetId                             A                                                         // 0x0000(0x0010)
struct FPrimaryAssetId                             B                                                         // 0x0010(0x0010)
Bool                                               ReturnValue                                               // 0x0020(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.NotEqual_PrimaryAssetType
// 0x0018
struct FNotEqual_PrimaryAssetType
{
struct FPrimaryAssetType                           A                                                         // 0x0000(0x0008)
struct FPrimaryAssetType                           B                                                         // 0x0008(0x0008)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.NotEqual_SoftClassReference
// 0x0058
struct FNotEqual_SoftClassReference
{
unsigned char                                      A                                                         // 0x0000(0x0028)
unsigned char                                      B                                                         // 0x0028(0x0028)
Bool                                               ReturnValue                                               // 0x0050(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.NotEqual_SoftObjectReference
// 0x0058
struct FNotEqual_SoftObjectReference
{
unsigned char                                      A                                                         // 0x0000(0x0028)
unsigned char                                      B                                                         // 0x0028(0x0028)
Bool                                               ReturnValue                                               // 0x0050(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.PrintString
// 0x0030
struct FPrintString
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FString                                     inString                                                  // 0x0008(0x0010)
Bool                                               bPrintToScreen                                            // 0x0018(0x0001)
Bool                                               bPrintToLog                                               // 0x0019(0x0001)
struct FLinearColor                                TextColor                                                 // 0x001C(0x0010)
float                                              Duration                                                  // 0x002C(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.PrintText
// 0x0038
struct FPrintText
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FText                                       InText                                                    // 0x0008(0x0018)
Bool                                               bPrintToScreen                                            // 0x0020(0x0001)
Bool                                               bPrintToLog                                               // 0x0021(0x0001)
struct FLinearColor                                TextColor                                                 // 0x0024(0x0010)
float                                              Duration                                                  // 0x0034(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.PrintToScreen
// 0x0030
struct FPrintToScreen
{
struct FString                                     inString                                                  // 0x0000(0x0010)
struct FLinearColor                                TextColor                                                 // 0x0010(0x0010)
struct FVector2D                                   TextScale                                                 // 0x0020(0x0008)
float                                              Duration                                                  // 0x0028(0x0004)
Bool                                               bIsUGC                                                    // 0x002C(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.PrintWarning
// 0x0010
struct FPrintWarning
{
struct FString                                     inString                                                  // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.QuitGame
// 0x0018
struct FQuitGame
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
class APlayerController*                           SpecificPlayer                                            // 0x0008(0x0008)
unsigned char                                      QuitPreference                                            // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.RemoveBlackResMapping
// 0x0050
struct FRemoveBlackResMapping
{
unsigned char                                      InPackageNames                                            // 0x0000(0x0050)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.RemoveResMapping
// 0x0010
struct FRemoveResMapping
{
TArray<struct FString>                             PathKeys                                                  // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.ResetGamepadAssignmentToController
// 0x0004
struct FResetGamepadAssignmentToController
{
int                                                ControllerId                                              // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.RetriggerableDelay
// 0x0028
struct FRetriggerableDelay
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
float                                              Duration                                                  // 0x0008(0x0004)
struct FLatentActionInfo                           LatentInfo                                                // 0x0010(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetBoolPropertyByName
// 0x0018
struct FSetBoolPropertyByName
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FName                                       PropertyName                                              // 0x0008(0x0008)
Bool                                               Value                                                     // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetBytePropertyByName
// 0x0018
struct FSetBytePropertyByName
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FName                                       PropertyName                                              // 0x0008(0x0008)
unsigned char                                      Value                                                     // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetClassPropertyByName
// 0x0018
struct FSetClassPropertyByName
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FName                                       PropertyName                                              // 0x0008(0x0008)
class UClass*                                      Value                                                     // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetCollisionProfileNameProperty
// 0x0018
struct FSetCollisionProfileNameProperty
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FName                                       PropertyName                                              // 0x0008(0x0008)
struct FCollisionProfileName                       Value                                                     // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetFloatPropertyByName
// 0x0018
struct FSetFloatPropertyByName
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FName                                       PropertyName                                              // 0x0008(0x0008)
float                                              Value                                                     // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetInt64PropertyByName
// 0x0018
struct FSetInt64PropertyByName
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FName                                       PropertyName                                              // 0x0008(0x0008)
int64_t                                            Value                                                     // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetInterfacePropertyByName
// 0x0020
struct FSetInterfacePropertyByName
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FName                                       PropertyName                                              // 0x0008(0x0008)
TScriptInterface<class UInterface>                 Value                                                     // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetIntPropertyByName
// 0x0018
struct FSetIntPropertyByName
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FName                                       PropertyName                                              // 0x0008(0x0008)
int                                                Value                                                     // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetLinearColorPropertyByName
// 0x0020
struct FSetLinearColorPropertyByName
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FName                                       PropertyName                                              // 0x0008(0x0008)
struct FLinearColor                                Value                                                     // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetNamePropertyByName
// 0x0018
struct FSetNamePropertyByName
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FName                                       PropertyName                                              // 0x0008(0x0008)
struct FName                                       Value                                                     // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetObjectPropertyByName
// 0x0018
struct FSetObjectPropertyByName
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FName                                       PropertyName                                              // 0x0008(0x0008)
class UObject*                                     Value                                                     // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetRotatorPropertyByName
// 0x0020
struct FSetRotatorPropertyByName
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FName                                       PropertyName                                              // 0x0008(0x0008)
struct FRotator                                    Value                                                     // 0x0010(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetSoftClassPropertyByName
// 0x0038
struct FSetSoftClassPropertyByName
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FName                                       PropertyName                                              // 0x0008(0x0008)
unsigned char                                      Value                                                     // 0x0010(0x0028)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetSoftObjectPropertyByName
// 0x0038
struct FSetSoftObjectPropertyByName
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FName                                       PropertyName                                              // 0x0008(0x0008)
unsigned char                                      Value                                                     // 0x0010(0x0028)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetStringPropertyByName
// 0x0020
struct FSetStringPropertyByName
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FName                                       PropertyName                                              // 0x0008(0x0008)
struct FString                                     Value                                                     // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetStructurePropertyByName
// 0x0018
struct FSetStructurePropertyByName
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FName                                       PropertyName                                              // 0x0008(0x0008)
struct FGenericStruct                              Value                                                     // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetSuppressViewportTransitionMessage
// 0x0010
struct FSetSuppressViewportTransitionMessage
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
Bool                                               bState                                                    // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetTextPropertyByName
// 0x0028
struct FSetTextPropertyByName
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FName                                       PropertyName                                              // 0x0008(0x0008)
struct FText                                       Value                                                     // 0x0010(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetTransformPropertyByName
// 0x0040
struct FSetTransformPropertyByName
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FName                                       PropertyName                                              // 0x0008(0x0008)
struct FTransform                                  Value                                                     // 0x0010(0x0030)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetUInt64PropertyByName
// 0x0018
struct FSetUInt64PropertyByName
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FName                                       PropertyName                                              // 0x0008(0x0008)
uint64_t                                           Value                                                     // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetUserActivity
// 0x0018
struct FSetUserActivity
{
struct FUserActivity                               UserActivity                                              // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetVectorPropertyByName
// 0x0020
struct FSetVectorPropertyByName
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FName                                       PropertyName                                              // 0x0008(0x0008)
struct FVector                                     Value                                                     // 0x0010(0x000C)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetVolumeButtonsHandledBySystem
// 0x0001
struct FSetVolumeButtonsHandledBySystem
{
Bool                                               bEnabled                                                  // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SetWindowTitle
// 0x0018
struct FSetWindowTitle
{
struct FText                                       Title                                                     // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.ShowAdBanner
// 0x0008
struct FShowAdBanner
{
int                                                AdIdIndex                                                 // 0x0000(0x0004)
Bool                                               bShowOnBottomOfScreen                                     // 0x0004(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.ShowPlatformSpecificAchievementsScreen
// 0x0008
struct FShowPlatformSpecificAchievementsScreen
{
class APlayerController*                           SpecificPlayer                                            // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.ShowPlatformSpecificLeaderboardScreen
// 0x0010
struct FShowPlatformSpecificLeaderboardScreen
{
struct FString                                     CategoryName                                              // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SphereOverlapActors
// 0x0058
struct FSphereOverlapActors
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     SpherePos                                                 // 0x0008(0x000C)
float                                              SphereRadius                                              // 0x0014(0x0004)
TArray<unsigned char>                              ObjectTypes                                               // 0x0018(0x0010)
class UClass*                                      ActorClassFilter                                          // 0x0028(0x0008)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0030(0x0010)
TArray<class AActor*>                              OutActors                                                 // 0x0040(0x0010)
Bool                                               ReturnValue                                               // 0x0050(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SphereOverlapComponents
// 0x0058
struct FSphereOverlapComponents
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     SpherePos                                                 // 0x0008(0x000C)
float                                              SphereRadius                                              // 0x0014(0x0004)
TArray<unsigned char>                              ObjectTypes                                               // 0x0018(0x0010)
class UClass*                                      ComponentClassFilter                                      // 0x0028(0x0008)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0030(0x0010)
TArray<class UPrimitiveComponent*>                 OutComponents                                             // 0x0040(0x0010)
Bool                                               ReturnValue                                               // 0x0050(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SphereTraceMulti
// 0x0080
struct FSphereTraceMulti
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
float                                              Radius                                                    // 0x0020(0x0004)
unsigned char                                      TraceChannel                                              // 0x0024(0x0001)
Bool                                               bTraceComplex                                             // 0x0025(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0028(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0038(0x0001)
TArray<struct FHitResult>                          OutHits                                                   // 0x0040(0x0010)
Bool                                               bIgnoreSelf                                               // 0x0050(0x0001)
struct FLinearColor                                TraceColor                                                // 0x0054(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x0064(0x0010)
float                                              DrawTime                                                  // 0x0074(0x0004)
Bool                                               ReturnValue                                               // 0x0078(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SphereTraceMultiByProfile
// 0x0090
struct FSphereTraceMultiByProfile
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
float                                              Radius                                                    // 0x0020(0x0004)
struct FName                                       ProfileName                                               // 0x0028(0x0008)
Bool                                               bTraceComplex                                             // 0x0030(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0038(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0048(0x0001)
TArray<struct FHitResult>                          OutHits                                                   // 0x0050(0x0010)
Bool                                               bIgnoreSelf                                               // 0x0060(0x0001)
struct FLinearColor                                TraceColor                                                // 0x0064(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x0074(0x0010)
float                                              DrawTime                                                  // 0x0084(0x0004)
Bool                                               ReturnValue                                               // 0x0088(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SphereTraceMultiForObjects
// 0x0098
struct FSphereTraceMultiForObjects
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
float                                              Radius                                                    // 0x0020(0x0004)
TArray<unsigned char>                              ObjectTypes                                               // 0x0028(0x0010)
Bool                                               bTraceComplex                                             // 0x0038(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0040(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0050(0x0001)
TArray<struct FHitResult>                          OutHits                                                   // 0x0058(0x0010)
Bool                                               bIgnoreSelf                                               // 0x0068(0x0001)
struct FLinearColor                                TraceColor                                                // 0x006C(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x007C(0x0010)
float                                              DrawTime                                                  // 0x008C(0x0004)
Bool                                               ReturnValue                                               // 0x0090(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SphereTraceSingle
// 0x00F8
struct FSphereTraceSingle
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
float                                              Radius                                                    // 0x0020(0x0004)
unsigned char                                      TraceChannel                                              // 0x0024(0x0001)
Bool                                               bTraceComplex                                             // 0x0025(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0028(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0038(0x0001)
struct FHitResult                                  OutHit                                                    // 0x0040(0x0088)
Bool                                               bIgnoreSelf                                               // 0x00C8(0x0001)
struct FLinearColor                                TraceColor                                                // 0x00CC(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x00DC(0x0010)
float                                              DrawTime                                                  // 0x00EC(0x0004)
Bool                                               ReturnValue                                               // 0x00F0(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SphereTraceSingleByProfile
// 0x0108
struct FSphereTraceSingleByProfile
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
float                                              Radius                                                    // 0x0020(0x0004)
struct FName                                       ProfileName                                               // 0x0028(0x0008)
Bool                                               bTraceComplex                                             // 0x0030(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0038(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0048(0x0001)
struct FHitResult                                  OutHit                                                    // 0x0050(0x0088)
Bool                                               bIgnoreSelf                                               // 0x00D8(0x0001)
struct FLinearColor                                TraceColor                                                // 0x00DC(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x00EC(0x0010)
float                                              DrawTime                                                  // 0x00FC(0x0004)
Bool                                               ReturnValue                                               // 0x0100(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.SphereTraceSingleForObjects
// 0x0110
struct FSphereTraceSingleForObjects
{
class UObject*                                     WorldContextObject                                        // 0x0000(0x0008)
struct FVector                                     Start                                                     // 0x0008(0x000C)
struct FVector                                     End                                                       // 0x0014(0x000C)
float                                              Radius                                                    // 0x0020(0x0004)
TArray<unsigned char>                              ObjectTypes                                               // 0x0028(0x0010)
Bool                                               bTraceComplex                                             // 0x0038(0x0001)
TArray<class AActor*>                              ActorsToIgnore                                            // 0x0040(0x0010)
unsigned char                                      DrawDebugType                                             // 0x0050(0x0001)
struct FHitResult                                  OutHit                                                    // 0x0058(0x0088)
Bool                                               bIgnoreSelf                                               // 0x00E0(0x0001)
struct FLinearColor                                TraceColor                                                // 0x00E4(0x0010)
struct FLinearColor                                TraceHitColor                                             // 0x00F4(0x0010)
float                                              DrawTime                                                  // 0x0104(0x0004)
Bool                                               ReturnValue                                               // 0x0108(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.StripObjectClass
// 0x0028
struct FStripObjectClass
{
struct FString                                     PathName                                                  // 0x0000(0x0010)
Bool                                               bAssertOnBadPath                                          // 0x0010(0x0001)
struct FString                                     ReturnValue                                               // 0x0018(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.UnloadPrimaryAsset
// 0x0010
struct FUnloadPrimaryAsset
{
struct FPrimaryAssetId                             PrimaryAssetId                                            // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetSystemLibrary.UnloadPrimaryAssetList
// 0x0010
struct FUnloadPrimaryAssetList
{
TArray<struct FPrimaryAssetId>                     PrimaryAssetIdList                                        // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetMetaDataLibrary.GetClassOfObjectPropertyBase
// 0x0010
struct FGetClassOfObjectPropertyBase
{
class UObjectPropertyBase*                         ObjectPropertyBase                                        // 0x0000(0x0008)
class UClass*                                      ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetMetaDataLibrary.GetEnum
// 0x0010
struct FGetEnum
{
class UEnumProperty*                               EnumProperty                                              // 0x0000(0x0008)
class UEnum*                                       ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetMetaDataLibrary.GetEnumFromByte
// 0x0010
struct FGetEnumFromByte
{
class UByteProperty*                               ByteProperty                                              // 0x0000(0x0008)
class UEnum*                                       ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetMetaDataLibrary.GetEnumIndexByValue
// 0x0018
struct FGetEnumIndexByValue
{
class UEnum*                                       Enum                                                      // 0x0000(0x0008)
int64_t                                            Value                                                     // 0x0008(0x0008)
int                                                ReturnValue                                               // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetMetaDataLibrary.GetEnumName
// 0x0018
struct FGetEnumName
{
class UEnum*                                       Enum                                                      // 0x0000(0x0008)
int                                                NameIndex                                                 // 0x0008(0x0004)
struct FName                                       ReturnValue                                               // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetMetaDataLibrary.GetEnumValue
// 0x0018
struct FGetEnumValue
{
class UEnum*                                       Enum                                                      // 0x0000(0x0008)
int                                                NameIndex                                                 // 0x0008(0x0004)
int64_t                                            ReturnValue                                               // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetMetaDataLibrary.GetMetaData
// 0x0028
struct FGetMetaData
{
class UField*                                      Field                                                     // 0x0000(0x0008)
struct FName                                       Key                                                       // 0x0008(0x0008)
int                                                NameIndex                                                 // 0x0010(0x0004)
struct FString                                     ReturnValue                                               // 0x0018(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetMetaDataLibrary.GetNumOfEnum
// 0x0010
struct FGetNumOfEnum
{
class UEnum*                                       Enum                                                      // 0x0000(0x0008)
int                                                ReturnValue                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.KismetMetaDataLibrary.GetObjectsWithOuter
// 0x0028
struct FGetObjectsWithOuter
{
class UObject*                                     Outer                                                     // 0x0000(0x0008)
Bool                                               bIncludeNestedObjects                                     // 0x0008(0x0001)
int                                                ExclusionFlags                                            // 0x000C(0x0004)
int                                                ExclusionInternalFlags                                    // 0x0010(0x0004)
TArray<class UObject*>                             ReturnValue                                               // 0x0018(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.KismetMetaDataLibrary.GetScriptStructOfStructProperty
// 0x0010
struct FGetScriptStructOfStructProperty
{
class UStructProperty*                             StructProperty                                            // 0x0000(0x0008)
class UScriptStruct*                               ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.KismetMetaDataLibrary.HasMetaData
// 0x0018
struct FHasMetaData
{
class UField*                                      Field                                                     // 0x0000(0x0008)
struct FName                                       Key                                                       // 0x0008(0x0008)
int                                                NameIndex                                                 // 0x0010(0x0004)
Bool                                               ReturnValue                                               // 0x0014(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.ItemSpecialDataManager.AddOrUpdateBloodDiamondDataAndBroadCast
// 0x0020
struct FAddOrUpdateBloodDiamondDataAndBroadCast
{
uint64_t                                           Key                                                       // 0x0000(0x0008)
struct FItemSpecialData_BloodDiamondData           NewData                                                   // 0x0008(0x0018)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.ItemSpecialDataManager.AddOrUpdateMechaSkinDataAndBroadCast
// 0x0028
struct FAddOrUpdateMechaSkinDataAndBroadCast
{
int64_t                                            Key                                                       // 0x0000(0x0008)
struct FItemSpecialData_EscapeMechaItemData        NewData                                                   // 0x0008(0x0020)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.ItemSpecialDataManager.GetInstance
// 0x0008
struct FGetInstance
{
class UItemSpecialDataManager*                     ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.AddAttrValueChangedDelegate
// 0x0018
struct FAddAttrValueChangedDelegate
{
struct FName                                       AttrName                                                  // 0x0000(0x0008)
struct FScriptDelegate                             Delegate                                                  // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.AddConfigAttrModifyItem
// 0x00D0
struct FAddConfigAttrModifyItem
{
struct FAttrModifyItem                             NewItem                                                   // 0x0000(0x00D0)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.AddDynamicModifier
// 0x00D0
struct FAddDynamicModifier
{
struct FAttrModifyItem                             AttrModifyItem                                            // 0x0000(0x00D0)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.AddDynamicModifierBySimpleConfig
// 0x0058
struct FAddDynamicModifierBySimpleConfig
{
struct FAttrModifyItemSimple                       ModifyConfig                                              // 0x0000(0x0038)
struct FString                                     OptionalModifyItemNameID                                  // 0x0038(0x0010)
struct FString                                     ReturnValue                                               // 0x0048(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.AddDynamicModifierBySimpleData
// 0x0040
struct FAddDynamicModifierBySimpleData
{
struct FString                                     AttrName                                                  // 0x0000(0x0010)
EAttrOperator                                      ModifierOp                                                // 0x0010(0x0001)
float                                              ModifierValue                                             // 0x0014(0x0004)
struct FString                                     OptionalModifyItemNameID                                  // 0x0018(0x0010)
Bool                                               bRepAttrModify                                            // 0x0028(0x0001)
struct FString                                     ReturnValue                                               // 0x0030(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.AddNewGameAttributeGroupByClass
// 0x0010
struct FAddNewGameAttributeGroupByClass
{
class UClass*                                      InClass                                                   // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.AddValueToAttribute
// 0x0018
struct FAddValueToAttribute
{
struct FString                                     AttrName                                                  // 0x0000(0x0010)
float                                              Value                                                     // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.AttributeHasReplicated
// 0x0018
struct FAttributeHasReplicated
{
struct FString                                     AttrName                                                  // 0x0000(0x0010)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.ClientDisableDynimacModifierToActor
// 0x0010
struct FClientDisableDynimacModifierToActor
{
class AActor*                                      TargetActor                                               // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.DisableAllAttrModifier
// 0x0002
struct FDisableAllAttrModifier
{
Bool                                               bRecycled                                                 // 0x0000(0x0001)
Bool                                               ReturnValue                                               // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.DisableAttrModifier
// 0x0018
struct FDisableAttrModifier
{
struct FString                                     AttrModifyItemName                                        // 0x0000(0x0010)
Bool                                               bForceNetUpdate                                           // 0x0010(0x0001)
Bool                                               ReturnValue                                               // 0x0011(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.DisableAttrModifierByIndex
// 0x0008
struct FDisableAttrModifierByIndex
{
int                                                ModifyConfigIndex                                         // 0x0000(0x0004)
Bool                                               bForceNetUpdate                                           // 0x0004(0x0001)
Bool                                               bRecycled                                                 // 0x0005(0x0001)
Bool                                               ReturnValue                                               // 0x0006(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.DisableAttrModifierGroupByIndex
// 0x0008
struct FDisableAttrModifierGroupByIndex
{
int                                                GroupIndex                                                // 0x0000(0x0004)
Bool                                               ReturnValue                                               // 0x0004(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.DisableAttrModifiers
// 0x0028
struct FDisableAttrModifiers
{
TArray<struct FString>                             AttrModifyItemNames                                       // 0x0000(0x0010)
Bool                                               bForceNetUpdate                                           // 0x0010(0x0001)
struct FString                                     ModifierSuffix                                            // 0x0018(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.DisableModifierToActor
// 0x0010
struct FDisableModifierToActor
{
class AActor*                                      TargetActor                                               // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.EnableAllAttrModifier
// 0x0001
struct FEnableAllAttrModifier
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.EnableAttrModifier
// 0x0018
struct FEnableAttrModifier
{
struct FString                                     AttrModifyItemName                                        // 0x0000(0x0010)
Bool                                               bForceNetUpdate                                           // 0x0010(0x0001)
Bool                                               ReturnValue                                               // 0x0011(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.EnableAttrModifierByIndex
// 0x0008
struct FEnableAttrModifierByIndex
{
int                                                ModifyConfigIndex                                         // 0x0000(0x0004)
Bool                                               bForceNetUpdate                                           // 0x0004(0x0001)
Bool                                               ReturnValue                                               // 0x0005(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.EnableAttrModifierGroupByIndex
// 0x0008
struct FEnableAttrModifierGroupByIndex
{
int                                                GroupIndex                                                // 0x0000(0x0004)
Bool                                               ReturnValue                                               // 0x0004(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.EnableAttrModifiers
// 0x0028
struct FEnableAttrModifiers
{
TArray<struct FString>                             AttrModifyItemNames                                       // 0x0000(0x0010)
Bool                                               bForceNetUpdate                                           // 0x0010(0x0001)
struct FString                                     ModifierSuffix                                            // 0x0018(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.GetAffectedInfosByAttrName
// 0x0060
struct FGetAffectedInfosByAttrName
{
struct FString                                     AttrName                                                  // 0x0000(0x0010)
TMap<struct FName, float>                          ModifyItemNameToAddedValue                                // 0x0010(0x0050)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.GetAttributeInitialValue
// 0x0018
struct FGetAttributeInitialValue
{
struct FString                                     AttrName                                                  // 0x0000(0x0010)
float                                              ReturnValue                                               // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.GetAttributeOriginValue
// 0x0018
struct FGetAttributeOriginValue
{
struct FString                                     AttrName                                                  // 0x0000(0x0010)
float                                              ReturnValue                                               // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.GetAttributeValue
// 0x0018
struct FGetAttributeValue
{
struct FString                                     AttrName                                                  // 0x0000(0x0010)
float                                              ReturnValue                                               // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.GetAttributeValueByContainerRef
// 0x0030
struct FGetAttributeValueByContainerRef
{
struct FGameAttributeContainer                     AttrContainer                                             // 0x0000(0x0028)
float                                              ReturnValue                                               // 0x0028(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.GetAttributeValueMax
// 0x0018
struct FGetAttributeValueMax
{
struct FString                                     AttrName                                                  // 0x0000(0x0010)
float                                              ReturnValue                                               // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.GetAttributeValueMin
// 0x0018
struct FGetAttributeValueMin
{
struct FString                                     AttrName                                                  // 0x0000(0x0010)
float                                              ReturnValue                                               // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.GetAttrModifyItemByItemName
// 0x00E8
struct FGetAttrModifyItemByItemName
{
struct FString                                     AttrModifyItemName                                        // 0x0000(0x0010)
struct FAttrModifyItem                             OutItem                                                   // 0x0010(0x00D0)
Bool                                               ReturnValue                                               // 0x00E0(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.GetConfigAttrModifyGroupList
// 0x0010
struct FGetConfigAttrModifyGroupList
{
TArray<struct FAttrModifyGroupItem>                ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.GetDynamicModifierRepList
// 0x0010
struct FGetDynamicModifierRepList
{
TArray<struct FAttrModifyItem>                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.GetLocalCalculationVariableExecutor
// 0x0010
struct FGetLocalCalculationVariableExecutor
{
int                                                ExecutorUniqueID                                          // 0x0000(0x0004)
class ULocalCalculationVariableExecutor*           ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.GetNewGameAttributeGroupInstances
// 0x0010
struct FGetNewGameAttributeGroupInstances
{
TArray<class UGameAttributeGroup*>                 ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.HasDynamicModifier
// 0x0018
struct FHasDynamicModifier
{
struct FString                                     AttrModifyId                                              // 0x0000(0x0010)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.HasNewGameAttributeGroupByClass
// 0x0010
struct FHasNewGameAttributeGroupByClass
{
class UClass*                                      InClass                                                   // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.HasRegisterAttr
// 0x0018
struct FHasRegisterAttr
{
struct FString                                     AttrName                                                  // 0x0000(0x0010)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.OnMaxAttributeValueChanged
// 0x0010
struct FOnMaxAttributeValueChanged
{
struct FName                                       InAttrName                                                // 0x0000(0x0008)
float                                              CurValue                                                  // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.OnOwnerPreRecycled
// 0x0010
struct FOnOwnerPreRecycled
{
class AActor*                                      InRecycledActor                                           // 0x0000(0x0008)
Bool                                               bPersistentPool                                           // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.OnRep_AttrModifyStateList
// 0x0010
struct FOnRep_AttrModifyStateList
{
TArray<unsigned char>                              PrevStateList                                             // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.OnSwitchingDS
// 0x0008
struct FOnSwitchingDS
{
class APlayerController*                           InPC                                                      // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.RegisterAttributesFromTable
// 0x0008
struct FRegisterAttributesFromTable
{
int                                                InGroup                                                   // 0x0000(0x0004)
Bool                                               ReturnValue                                               // 0x0004(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.RegisterBPModifyAbleAttr
// 0x0030
struct FRegisterBPModifyAbleAttr
{
class UObject*                                     InOwner                                                   // 0x0000(0x0008)
struct FString                                     RegistName                                                // 0x0008(0x0010)
struct FName                                       ValueName                                                 // 0x0018(0x0008)
EAttrVariableType                                  ValueType                                                 // 0x0020(0x0001)
Bool                                               InHasReplicatedTag                                        // 0x0021(0x0001)
float                                              InMaxValue                                                // 0x0024(0x0004)
float                                              InMinValue                                                // 0x0028(0x0004)
Bool                                               ReturnValue                                               // 0x002C(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.RegisterLocalCalculationVariableExecutorByClass
// 0x0018
struct FRegisterLocalCalculationVariableExecutorByClass
{
class UClass*                                      CalculationClass                                          // 0x0000(0x0008)
class UClass*                                      ExecutorClass                                             // 0x0008(0x0008)
int                                                ReturnValue                                               // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.RegisterLocalCalculationVariableExecutorByDelegate
// 0x0020
struct FRegisterLocalCalculationVariableExecutorByDelegate
{
class UClass*                                      CalculationClass                                          // 0x0000(0x0008)
struct FScriptDelegate                             Delegate                                                  // 0x0008(0x0010)
int                                                ReturnValue                                               // 0x0018(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.RegisterLocalCalculationVariableExecutorByObject
// 0x0018
struct FRegisterLocalCalculationVariableExecutorByObject
{
class UClass*                                      CalculationClass                                          // 0x0000(0x0008)
class UObject*                                     InterfaceObj                                              // 0x0008(0x0008)
int                                                ReturnValue                                               // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.RegisterModifyAbleAttr
// 0x0018
struct FRegisterModifyAbleAttr
{
TArray<struct FAttrRegisterItem>                   AttrRegists                                               // 0x0000(0x0010)
Bool                                               bSetAttrByOrigin                                          // 0x0010(0x0001)
Bool                                               ReturnValue                                               // 0x0011(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.RemoveAttrValueChangedDelegate
// 0x0018
struct FRemoveAttrValueChangedDelegate
{
struct FName                                       AttrName                                                  // 0x0000(0x0008)
struct FScriptDelegate                             Delegate                                                  // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.RemoveDynamicModifier
// 0x0018
struct FRemoveDynamicModifier
{
struct FString                                     AttrModifyId                                              // 0x0000(0x0010)
int                                                IntAttrModifyID                                           // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.RemoveNewGameAttributeGroupByClass
// 0x0008
struct FRemoveNewGameAttributeGroupByClass
{
class UClass*                                      InClass                                                   // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.ReplaceModifyAbleAttr
// 0x00C0
struct FReplaceModifyAbleAttr
{
struct FAttrRegisterItem                           AttrRegist                                                // 0x0000(0x00B8)
Bool                                               ReturnValue                                               // 0x00B8(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.ServerSetAttributeInitialValueSimple
// 0x0018
struct FServerSetAttributeInitialValueSimple
{
struct FString                                     AttrName                                                  // 0x0000(0x0010)
float                                              NewValue                                                  // 0x0010(0x0004)
Bool                                               ReturnValue                                               // 0x0014(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.SetAttributeGroup
// 0x0008
struct FSetAttributeGroup
{
int                                                InGroup                                                   // 0x0000(0x0004)
Bool                                               InRegister                                                // 0x0004(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.SetAttributeInitialValue
// 0x0018
struct FSetAttributeInitialValue
{
struct FString                                     AttrName                                                  // 0x0000(0x0010)
float                                              NewValue                                                  // 0x0010(0x0004)
Bool                                               ReturnValue                                               // 0x0014(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.SetAttributeValueRange
// 0x0018
struct FSetAttributeValueRange
{
struct FString                                     Name                                                      // 0x0000(0x0010)
float                                              InMinValue                                                // 0x0010(0x0004)
float                                              InMaxValue                                                // 0x0014(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.SetValueToAttributeSafety
// 0x0018
struct FSetValueToAttributeSafety
{
struct FString                                     AttrName                                                  // 0x0000(0x0010)
float                                              Value                                                     // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.UnregisterLocalCalculationVariableExecutor
// 0x0004
struct FUnregisterLocalCalculationVariableExecutor
{
int                                                ExecutorUniqueID                                          // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.UnregisterModifyAbleAttr
// 0x0018
struct FUnregisterModifyAbleAttr
{
TArray<struct FString>                             AttrRegists                                               // 0x0000(0x0010)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.UpdateCurClientModifierResValue
// 0x00D8
struct FUpdateCurClientModifierResValue
{
struct FAttrModifyItem                             ConfigAttrModifier                                        // 0x0000(0x00D0)
Bool                                               ReturnValue                                               // 0x00D0(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.UpdateModifyAbleAttrMaxValue
// 0x0018
struct FUpdateModifyAbleAttrMaxValue
{
struct FString                                     Name                                                      // 0x0000(0x0010)
float                                              Value                                                     // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.AttrModifyComponent.UpdateRegisteredModifyAbleAttr
// 0x00C0
struct FUpdateRegisteredModifyAbleAttr
{
struct FAttrRegisterItem                           AttrRegistItem                                            // 0x0000(0x00B8)
Bool                                               ReturnValue                                               // 0x00B8(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.UAEGameInstance.AddCmd
// 0x0010
struct FAddCmd
{
struct FString                                     InCmd                                                     // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.UAEGameInstance.GetAssociatedFrontendHUD
// 0x0008
struct FGetAssociatedFrontendHUD
{
class UFrontendHUD*                                ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Basic.UAEGameInstance.GetDeviceLevel
// 0x0004
struct FGetDeviceLevel
{
int                                                ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.UAEGameInstance.GetGameID
// 0x0010
struct FGetGameID
{
struct FString                                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.UAEGameInstance.GetWeatherID
// 0x0004
struct FGetWeatherID
{
int                                                ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.UAEGameInstance.GetWeatherTime
// 0x0004
struct FGetWeatherTime
{
float                                              ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.UAEGameInstance.LocalReplayPlaying
// 0x0010
struct FLocalReplayPlaying
{
struct FString                                     ReplayFile                                                // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.UAEGameInstance.LocalReplayRecording
// 0x0010
struct FLocalReplayRecording
{
struct FString                                     ReplayFile                                                // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.UAEGameInstance.PostFileToTGPA
// 0x0020
struct FPostFileToTGPA
{
struct FString                                     ExtraStr                                                  // 0x0000(0x0010)
struct FString                                     FilePath                                                  // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.UAEGameInstance.StartRecordingReplayByType
// 0x0020
struct FStartRecordingReplayByType
{
EPlaybackType                                      ReplayType                                                // 0x0000(0x0001)
Bool                                               bSkipConditionCheck                                       // 0x0001(0x0001)
EPBRecordCond                                      RecordCondition                                           // 0x0002(0x0001)
struct FString                                     TargetName                                                // 0x0008(0x0010)
Bool                                               ReturnValue                                               // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.UAEGameInstance.StopRecordingReplayByType
// 0x0002
struct FStopRecordingReplayByType
{
EPlaybackType                                      ReplayType                                                // 0x0000(0x0001)
Bool                                               ReturnValue                                               // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.AddBuff
// 0x0030
struct FAddBuff
{
struct FName                                       BuffName                                                  // 0x0000(0x0008)
class AController*                                 BuffCauser                                                // 0x0008(0x0008)
int                                                LayerCount                                                // 0x0010(0x0004)
class AActor*                                      BuffApplierActor                                          // 0x0018(0x0008)
class AActor*                                      CauserActor                                               // 0x0020(0x0008)
int                                                ReturnValue                                               // 0x0028(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.GetActorOwner
// 0x0008
struct FGetActorOwner
{
class AActor*                                      ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.GetBuffByName
// 0x0010
struct FGetBuffByName
{
struct FName                                       BuffName                                                  // 0x0000(0x0008)
class USTBaseBuff*                                 ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.GetBuffExpiry
// 0x0008
struct FGetBuffExpiry
{
int                                                InstanceID                                                // 0x0000(0x0004)
float                                              ReturnValue                                               // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.GetBuffIDByName
// 0x0010
struct FGetBuffIDByName
{
struct FName                                       BuffName                                                  // 0x0000(0x0008)
int                                                ReturnValue                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.GetBuffInstanceByName
// 0x00C8
struct FGetBuffInstanceByName
{
struct FName                                       BuffName                                                  // 0x0000(0x0008)
struct FBuffInstancedItem                          BuffInstance                                              // 0x0008(0x00B8)
Bool                                               ReturnValue                                               // 0x00C0(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.GetBuffInstanceIDByName
// 0x0010
struct FGetBuffInstanceIDByName
{
struct FName                                       BuffName                                                  // 0x0000(0x0008)
int                                                ReturnValue                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.GetBuffInstanceIDWithApplier
// 0x0018
struct FGetBuffInstanceIDWithApplier
{
struct FName                                       BuffName                                                  // 0x0000(0x0008)
class AActor*                                      BuffApplierActor                                          // 0x0008(0x0008)
int                                                ReturnValue                                               // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.GetBuffMaxLayer
// 0x0010
struct FGetBuffMaxLayer
{
struct FName                                       BuffName                                                  // 0x0000(0x0008)
int                                                ReturnValue                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.GetBuffName
// 0x0010
struct FGetBuffName
{
int                                                BuffID                                                    // 0x0000(0x0004)
struct FName                                       ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.GetPawnOwner
// 0x0008
struct FGetPawnOwner
{
class APawn*                                       ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.GetUAEBlackboard
// 0x0010
struct FGetUAEBlackboard
{
int                                                BuffInstanceID                                            // 0x0000(0x0004)
class UUAEBlackboard*                              ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.HasBuff
// 0x0010
struct FHasBuff
{
struct FName                                       BuffName                                                  // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.HasBuffByTag
// 0x0018
struct FHasBuffByTag
{
struct FGameplayTag                                BuffTag                                                   // 0x0000(0x0010)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.IsBufferMutexed
// 0x0010
struct FIsBufferMutexed
{
struct FName                                       NewBuffName                                               // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.IsBuffPendingRemove
// 0x0010
struct FIsBuffPendingRemove
{
struct FName                                       BuffName                                                  // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.IsInstanceValid
// 0x0008
struct FIsInstanceValid
{
int                                                InstanceID                                                // 0x0000(0x0004)
Bool                                               ReturnValue                                               // 0x0004(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.K2_GetBuffInstanceByInstanceID
// 0x00C0
struct FK2_GetBuffInstanceByInstanceID
{
int                                                InstanceID                                                // 0x0000(0x0004)
struct FBuffInstancedItem                          ReturnValue                                               // 0x0008(0x00B8)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.K2_GetBuffInstanceByName
// 0x00C0
struct FK2_GetBuffInstanceByName
{
struct FName                                       BuffName                                                  // 0x0000(0x0008)
struct FBuffInstancedItem                          ReturnValue                                               // 0x0008(0x00B8)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.OnSwitchedDS
// 0x0008
struct FOnSwitchedDS
{
class APlayerController*                           PC                                                        // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.RemoveBuff
// 0x0028
struct FRemoveBuff
{
struct FName                                       BuffName                                                  // 0x0000(0x0008)
Bool                                               bRemoveLayerOnly                                          // 0x0008(0x0001)
class AActor*                                      BuffApplierActor                                          // 0x0010(0x0008)
class AController*                                 pCauser                                                   // 0x0018(0x0008)
Bool                                               ReturnValue                                               // 0x0020(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.RemoveBuffByInstanceID
// 0x0008
struct FRemoveBuffByInstanceID
{
int                                                BuffInstanceID                                            // 0x0000(0x0004)
Bool                                               bRemoveLayerOnly                                          // 0x0004(0x0001)
Bool                                               ReturnValue                                               // 0x0005(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.RemoveBuffsByGameplayTag
// 0x0018
struct FRemoveBuffsByGameplayTag
{
struct FGameplayTag                                BuffTag                                                   // 0x0000(0x0010)
Bool                                               bRemoveLayerOnly                                          // 0x0010(0x0001)
Bool                                               ReturnValue                                               // 0x0011(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.ReplicateAllBlackboard
// 0x0004
struct FReplicateAllBlackboard
{
int                                                InstanceID                                                // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.ReplicateBlackboard
// 0x0018
struct FReplicateBlackboard
{
int                                                BuffInstanceID                                            // 0x0000(0x0004)
struct FName                                       Name                                                      // 0x0008(0x0008)
unsigned char                                      Type                                                      // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.STBaseBuffSystemComponent.SetBuffExpiry
// 0x000C
struct FSetBuffExpiry
{
int                                                BuffInstanceID                                            // 0x0000(0x0004)
float                                              ExpirySeconds                                             // 0x0004(0x0004)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.ItemHandleBase.AddAssociation
// 0x0038
struct FAddAssociation
{
struct FName                                       Name                                                      // 0x0000(0x0008)
struct FItemAssociation                            Association                                               // 0x0008(0x0030)
};

// 大佬QQ:2396031563
// Function Basic.ItemHandleBase.AddWeakAssociation
// 0x0030
struct FAddWeakAssociation
{
struct FItemAssociation                            Association                                               // 0x0000(0x0030)
};

// 大佬QQ:2396031563
// Function Basic.ItemHandleBase.GetAssociation
// 0x0038
struct FGetAssociation
{
struct FName                                       Name                                                      // 0x0000(0x0008)
struct FItemAssociation                            ReturnValue                                               // 0x0008(0x0030)
};

// 大佬QQ:2396031563
// Function Basic.ItemHandleBase.GetAssociationByTargetDefineID
// 0x0048
struct FGetAssociationByTargetDefineID
{
struct FItemDefineID                               TargetDefineID                                            // 0x0000(0x0018)
struct FItemAssociation                            ReturnValue                                               // 0x0018(0x0030)
};

// 大佬QQ:2396031563
// Function Basic.ItemHandleBase.GetAssociationListByTargetType
// 0x0018
struct FGetAssociationListByTargetType
{
int                                                Type                                                      // 0x0000(0x0004)
TArray<struct FItemAssociation>                    ReturnValue                                               // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.ItemHandleBase.GetAssociationMap
// 0x0050
struct FGetAssociationMap
{
TMap<struct FName, struct FItemAssociation>        ReturnValue                                               // 0x0000(0x0050)
};

// 大佬QQ:2396031563
// Function Basic.ItemHandleBase.GetContainer
// 0x0010
struct FGetContainer
{
TScriptInterface<class UItemContainerInterface>    ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.ItemHandleBase.GetDefineID
// 0x0018
struct FGetDefineID
{
struct FItemDefineID                               ReturnValue                                               // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function Basic.ItemHandleBase.GetDefineIDTypeSpecificID
// 0x0004
struct FGetDefineIDTypeSpecificID
{
int                                                ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.ItemHandleBase.GetWeakAssociation
// 0x0038
struct FGetWeakAssociation
{
int                                                AssIdx                                                    // 0x0000(0x0004)
struct FItemAssociation                            ReturnValue                                               // 0x0008(0x0030)
};

// 大佬QQ:2396031563
// Function Basic.ItemHandleBase.GetWeakAssociationList
// 0x0010
struct FGetWeakAssociationList
{
TArray<struct FItemAssociation>                    ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.ItemHandleBase.Init
// 0x0018
struct FInit
{
struct FItemDefineID                               InDefineID                                                // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function Basic.ItemHandleBase.RemoveAssociation
// 0x0008
struct FRemoveAssociation
{
struct FName                                       Name                                                      // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Basic.ItemHandleBase.RemoveWeakAssociation
// 0x0030
struct FRemoveWeakAssociation
{
struct FItemAssociation                            ItemAss                                                   // 0x0000(0x0030)
};

// 大佬QQ:2396031563
// Function Basic.ItemHandleBase.SetAssociation
// 0x0038
struct FSetAssociation
{
struct FName                                       Name                                                      // 0x0000(0x0008)
struct FItemAssociation                            Association                                               // 0x0008(0x0030)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.AddOrSetAdditionalData
// 0x0030
struct FAddOrSetAdditionalData
{
struct FBattleItemAdditionalData                   InData                                                    // 0x0000(0x0030)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.AddOrSetAdditionalFloatData
// 0x0010
struct FAddOrSetAdditionalFloatData
{
struct FName                                       InName                                                    // 0x0000(0x0008)
float                                              InValue                                                   // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.AddOrSetAdditionalIntData
// 0x0010
struct FAddOrSetAdditionalIntData
{
struct FName                                       InName                                                    // 0x0000(0x0008)
int                                                InValue                                                   // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.AddOrSetAdditionalStringData
// 0x0018
struct FAddOrSetAdditionalStringData
{
struct FName                                       InName                                                    // 0x0000(0x0008)
struct FString                                     InValue                                                   // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.CanDealyUse
// 0x0001
struct FCanDealyUse
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.CanPickUpHandle
// 0x0018
struct FCanPickUpHandle
{
TScriptInterface<class UItemContainerInterface>    ItemContainer                                             // 0x0000(0x0010)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.CheckIsUnique
// 0x0010
struct FCheckIsUnique
{
class UObject*                                     WorldContextObj                                           // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.ClientHandleCreated
// 0x0018
struct FClientHandleCreated
{
struct FItemDefineID                               ItemDefineID                                              // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.ClientHandleDeleted
// 0x0018
struct FClientHandleDeleted
{
struct FItemDefineID                               ItemDefineID                                              // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.ClientHandleUpdated
// 0x0018
struct FClientHandleUpdated
{
struct FItemDefineID                               ItemDefineID                                              // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.ClientHandleUse
// 0x0030
struct FClientHandleUse
{
struct FBattleItemUseTarget                        Target                                                    // 0x0000(0x0028)
EBattleItemUseReason                               Reason                                                    // 0x0028(0x0001)
Bool                                               ReturnValue                                               // 0x0029(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.ConditionDropCheck
// 0x0008
struct FConditionDropCheck
{
int                                                InCount                                                   // 0x0000(0x0004)
EBattleItemDropReason                              Reason                                                    // 0x0004(0x0001)
Bool                                               ReturnValue                                               // 0x0005(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.ConstructBattleItemDataByDefineID
// 0x00B8
struct FConstructBattleItemDataByDefineID
{
struct FItemDefineID                               ItemDefineID                                              // 0x0000(0x0018)
struct FBattleItemData                             ReturnValue                                               // 0x0018(0x00A0)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.DoSomethingAfterPickup
// 0x0002
struct FDoSomethingAfterPickup
{
EBattleItemUseReason                               Reason                                                    // 0x0000(0x0001)
Bool                                               ToBackpack                                                // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.DoSomethingBeforeDrop
// 0x0001
struct FDoSomethingBeforeDrop
{
EBattleItemDropReason                              Reason                                                    // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.ExtractItemData
// 0x00A0
struct FExtractItemData
{
struct FBattleItemData                             ReturnValue                                               // 0x0000(0x00A0)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.ExtractItemDataOpt
// 0x00A0
struct FExtractItemDataOpt
{
struct FBattleItemData                             ReturnValue                                               // 0x0000(0x00A0)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.GetAdditionalDataAsFloat
// 0x0010
struct FGetAdditionalDataAsFloat
{
struct FName                                       Name                                                      // 0x0000(0x0008)
float                                              OutValue                                                  // 0x0008(0x0004)
Bool                                               ReturnValue                                               // 0x000C(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.GetAdditionalDataAsInt
// 0x0010
struct FGetAdditionalDataAsInt
{
struct FName                                       Name                                                      // 0x0000(0x0008)
int                                                OutValue                                                  // 0x0008(0x0004)
Bool                                               ReturnValue                                               // 0x000C(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.GetAdditionalDataAsString
// 0x0020
struct FGetAdditionalDataAsString
{
struct FName                                       Name                                                      // 0x0000(0x0008)
struct FString                                     OutValue                                                  // 0x0008(0x0010)
Bool                                               ReturnValue                                               // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.GetCharacterAttrModifyComp
// 0x0008
struct FGetCharacterAttrModifyComp
{
class UAttrModifyComponent*                        ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.GetCommonBackpackInterface
// 0x0010
struct FGetCommonBackpackInterface
{
TScriptInterface<class UCommonBackpackInterface>   ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.GetCustomizeTargetAttrModifyComp
// 0x0008
struct FGetCustomizeTargetAttrModifyComp
{
class UAttrModifyComponent*                        ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.GetGenericAbilityTypesFilter
// 0x0010
struct FGetGenericAbilityTypesFilter
{
TArray<int>                                        ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.GetInBackpackVersion
// 0x0001
struct FGetInBackpackVersion
{
EItemInBackpackVersion                             ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.GetItemDetailInfo
// 0x0010
struct FGetItemDetailInfo
{
struct FString                                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.GetItemStoreArea
// 0x0001
struct FGetItemStoreArea
{
EItemStoreArea                                     ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.GetReadyPakItemDefineID
// 0x0020
struct FGetReadyPakItemDefineID
{
class UObject*                                     WorldContextObj                                           // 0x0000(0x0008)
struct FItemDefineID                               ReturnValue                                               // 0x0008(0x0018)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.GetReloadDefineID
// 0x0010
struct FGetReloadDefineID
{
class UObject*                                     WorldContextObj                                           // 0x0000(0x0008)
int                                                ReturnValue                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.GetTargetCarrier
// 0x0010
struct FGetTargetCarrier
{
TScriptInterface<class UGenericAbilityCarrierInterface> ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.GetWeaponAttrModifyComp
// 0x0008
struct FGetWeaponAttrModifyComp
{
class UAttrModifyComponent*                        ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.GetWorldInternal
// 0x0008
struct FGetWorldInternal
{
class UWorld*                                      ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.HandleAddAssociation
// 0x0038
struct FHandleAddAssociation
{
struct FBattleItemAssociationTarget                Target                                                    // 0x0000(0x0030)
Bool                                               ReturnValue                                               // 0x0030(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.HandleBuildGenericAbilities
// 0x0058
struct FHandleBuildGenericAbilities
{
struct FBattleItemPickupInfo                       PickupInfo                                                // 0x0000(0x0058)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.HandleChangeItemStoreArea
// 0x0001
struct FHandleChangeItemStoreArea
{
EItemStoreArea                                     InItemStoreArea                                           // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.HandleCommonBackpackInit
// 0x0020
struct FHandleCommonBackpackInit
{
struct FCommonBackpackInfo                         InInitInfo                                                // 0x0000(0x0020)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.HandleDisuse
// 0x0002
struct FHandleDisuse
{
EBattleItemDisuseReason                            Reason                                                    // 0x0000(0x0001)
Bool                                               ReturnValue                                               // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.HandleDrop
// 0x0008
struct FHandleDrop
{
int                                                InCount                                                   // 0x0000(0x0004)
EBattleItemDropReason                              Reason                                                    // 0x0004(0x0001)
Bool                                               ReturnValue                                               // 0x0005(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.HandleEnable
// 0x0002
struct FHandleEnable
{
Bool                                               bEnable                                                   // 0x0000(0x0001)
Bool                                               ReturnValue                                               // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.HandleFinishPickup
// 0x0070
struct FHandleFinishPickup
{
TScriptInterface<class UItemContainerInterface>    ItemContainer                                             // 0x0000(0x0010)
struct FBattleItemPickupInfo                       PickupInfo                                                // 0x0010(0x0058)
EBattleItemPickupReason                            Reason                                                    // 0x0068(0x0001)
Bool                                               ReturnValue                                               // 0x0069(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.HandlePickup
// 0x0070
struct FHandlePickup
{
TScriptInterface<class UItemContainerInterface>    ItemContainer                                             // 0x0000(0x0010)
struct FBattleItemPickupInfo                       PickupInfo                                                // 0x0010(0x0058)
EBattleItemPickupReason                            Reason                                                    // 0x0068(0x0001)
Bool                                               ReturnValue                                               // 0x0069(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.HandlePostPickup
// 0x0070
struct FHandlePostPickup
{
TScriptInterface<class UItemContainerInterface>    ItemContainer                                             // 0x0000(0x0010)
struct FBattleItemPickupInfo                       PickupInfo                                                // 0x0010(0x0058)
EBattleItemPickupReason                            Reason                                                    // 0x0068(0x0001)
Bool                                               ReturnValue                                               // 0x0069(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.HandlePreDrop
// 0x0020
struct FHandlePreDrop
{
int                                                InCount                                                   // 0x0000(0x0004)
EBattleItemDropReason                              Reason                                                    // 0x0004(0x0001)
struct FBattleItemDropInfo                         DropInfo                                                  // 0x0008(0x0010)
Bool                                               ReturnValue                                               // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.HandleTake
// 0x000C
struct FHandleTake
{
int                                                TakeCount                                                 // 0x0000(0x0004)
int                                                TotalCount                                                // 0x0004(0x0004)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.HandleTryDisuse
// 0x0002
struct FHandleTryDisuse
{
EBattleItemDisuseReason                            Reason                                                    // 0x0000(0x0001)
Bool                                               ReturnValue                                               // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.HandleUse
// 0x0030
struct FHandleUse
{
struct FBattleItemUseTarget                        Target                                                    // 0x0000(0x0028)
EBattleItemUseReason                               Reason                                                    // 0x0028(0x0001)
Bool                                               ReturnValue                                               // 0x0029(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.HanldeCleared
// 0x0001
struct FHanldeCleared
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.IsNeedRepDefinedID
// 0x0001
struct FIsNeedRepDefinedID
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.IsRestoreEquippingOnSwitchDS
// 0x0001
struct FIsRestoreEquippingOnSwitchDS
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.IsUGCAvatarHandle
// 0x0001
struct FIsUGCAvatarHandle
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.IsUseOnServer
// 0x0001
struct FIsUseOnServer
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.MarkItemHandleEnabled
// 0x0001
struct FMarkItemHandleEnabled
{
Bool                                               bNewEnable                                                // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.PreGroupHandleDisuse
// 0x0002
struct FPreGroupHandleDisuse
{
EBattleItemDisuseReason                            Reason                                                    // 0x0000(0x0001)
Bool                                               ReturnValue                                               // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.SetClientItemContainer
// 0x0010
struct FSetClientItemContainer
{
TScriptInterface<class UItemContainerInterface>    ItemContainer                                             // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.ShouldBuildGenericAbilities
// 0x0001
struct FShouldBuildGenericAbilities
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.ToString
// 0x0010
struct FToString
{
struct FString                                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.UpdateItemAttrModifyActivities
// 0x0001
struct FUpdateItemAttrModifyActivities
{
EItemOperationType                                 InOperType                                                // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.UpdateItemFeatureActivities
// 0x0001
struct FUpdateItemFeatureActivities
{
EItemOperationType                                 InOperType                                                // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Basic.BattleItemHandleBase.UpdateItemSkillActivities
// 0x0001
struct FUpdateItemSkillActivities
{
EItemOperationType                                 InOperType                                                // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.ApplyAttrModifySpecialById
// 0x0058
struct FApplyAttrModifySpecialById
{
class ASTExtraShootWeapon*                         InWeapon                                                  // 0x0000(0x0008)
unsigned char                                      OutModifyAttrNameSet                                      // 0x0008(0x0050)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.ApplyFPPDynamicSocketInfo
// 0x0018
struct FApplyFPPDynamicSocketInfo
{
class USkeletalMesh*                               SKMesh                                                    // 0x0000(0x0008)
class UStaticMesh*                                 STMesh                                                    // 0x0008(0x0008)
class UWeaponAvatarComponent*                      WeaponAvatarComp                                          // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.EquipOrUnEuipAttachment
// 0x0010
struct FEquipOrUnEuipAttachment
{
class ASTExtraShootWeapon*                         InWeapon                                                  // 0x0000(0x0008)
Bool                                               IsEquip                                                   // 0x0008(0x0001)
EBattleItemDisuseReason                            Reason                                                    // 0x0009(0x0001)
Bool                                               ReturnValue                                               // 0x000A(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.FindReplacedAttachIndex
// 0x0040
struct FFindReplacedAttachIndex
{
struct FItemDefineID                               ParentWeaponDefineID                                      // 0x0000(0x0018)
struct FItemDefineID                               ParentWeaponSkinID                                        // 0x0018(0x0018)
class UObject*                                     WorldContext                                              // 0x0030(0x0008)
int                                                ReturnValue                                               // 0x0038(0x0004)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.GetAnimationBP
// 0x0008
struct FGetAnimationBP
{
class UClass*                                      ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.GetAnimationBPAsset
// 0x0018
struct FGetAnimationBPAsset
{
struct FSoftObjectPath                             ReturnValue                                               // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.GetAnimationBPAsset_FPP
// 0x0018
struct FGetAnimationBPAsset_FPP
{
struct FSoftObjectPath                             ReturnValue                                               // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.GetAnimationBPAsset_OldWithFPP
// 0x0018
struct FGetAnimationBPAsset_OldWithFPP
{
struct FSoftObjectPath                             ReturnValue                                               // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.GetAnimationBPAssetLobby
// 0x0018
struct FGetAnimationBPAssetLobby
{
struct FSoftObjectPath                             ReturnValue                                               // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.GetAnimationBPLobby
// 0x0008
struct FGetAnimationBPLobby
{
class UClass*                                      ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.GetAttachmentConfig
// 0x05D0
struct FGetAttachmentConfig
{
struct FWeaponAttachmentConfig                     ReturnValue                                               // 0x0000(0x05D0)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.GetMeshPackCfg
// 0x0480
struct FGetMeshPackCfg
{
struct FWeaponMeshCfg                              MeshCfg                                                   // 0x0000(0x0480)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.GetMeshPackCfgCopy
// 0x0490
struct FGetMeshPackCfgCopy
{
Bool                                               bExtra                                                    // 0x0000(0x0001)
struct FWeaponMeshCfg                              ReturnValue                                               // 0x0010(0x0480)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.GetReadyPakItemDefineID
// 0x0020
struct FGetReadyPakItemDefineID
{
class UObject*                                     WorldContextObj                                           // 0x0000(0x0008)
struct FItemDefineID                               ReturnValue                                               // 0x0008(0x0018)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.GetReloadDefineID
// 0x0010
struct FGetReloadDefineID
{
class UObject*                                     WorldContextObj                                           // 0x0000(0x0008)
int                                                ReturnValue                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.GetReplacedMeshPackCfg
// 0x04C0
struct FGetReplacedMeshPackCfg
{
struct FWeaponMeshCfg                              MeshCfg                                                   // 0x0000(0x0480)
struct FItemDefineID                               ParentWeaponDefineID                                      // 0x0480(0x0018)
struct FItemDefineID                               ParentWeaponSkinID                                        // 0x0498(0x0018)
class UObject*                                     WorldContext                                              // 0x04B0(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.GetReplacedMeshPackCfgCopy
// 0x04C0
struct FGetReplacedMeshPackCfgCopy
{
struct FItemDefineID                               ParentWeaponDefineID                                      // 0x0000(0x0018)
struct FItemDefineID                               ParentWeaponSkinID                                        // 0x0018(0x0018)
class UObject*                                     WorldContext                                              // 0x0030(0x0008)
struct FWeaponMeshCfg                              ReturnValue                                               // 0x0040(0x0480)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.GetSKMeshPath
// 0x0010
struct FGetSKMeshPath
{
struct FString                                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.GetSlotID
// 0x0004
struct FGetSlotID
{
int                                                ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.GetSTMeshPath
// 0x0010
struct FGetSTMeshPath
{
struct FString                                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.GetSubSlotID
// 0x0008
struct FGetSubSlotID
{
Bool                                               InIsMale                                                  // 0x0000(0x0001)
int                                                ReturnValue                                               // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.GetWidgetList
// 0x0010
struct FGetWidgetList
{
TArray<struct FUIWidgetRes>                        UIList                                                    // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.HandleAvatarEntityApplyParticles
// 0x0010
struct FHandleAvatarEntityApplyParticles
{
class UWeaponAvatarEntity*                         AvatarEntity                                              // 0x0000(0x0008)
int                                                SlotID                                                    // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.HandleAvatarEntityRemoveParticles
// 0x0010
struct FHandleAvatarEntityRemoveParticles
{
class UWeaponAvatarEntity*                         AvatarEntity                                              // 0x0000(0x0008)
int                                                SlotID                                                    // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.HandleDisuseReplaceByNew
// 0x0008
struct FHandleDisuseReplaceByNew
{
class UBackpackWeaponAttachHandle*                 NewHandle                                                 // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.HandleEquipOrUnEquipToWeaponDelegate
// 0x0010
struct FHandleEquipOrUnEquipToWeaponDelegate
{
class ASTExtraWeapon*                              Weapon                                                    // 0x0000(0x0008)
Bool                                               bIsEquip                                                  // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.IsAvatarOf
// 0x0008
struct FIsAvatarOf
{
int                                                resID                                                     // 0x0000(0x0004)
Bool                                               ReturnValue                                               // 0x0004(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.IsAvatarWeapon_Interface
// 0x0010
struct FIsAvatarWeapon_Interface
{
class UObject*                                     WorldContextObj                                           // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.IsAvatarWeaponAttachment
// 0x0010
struct FIsAvatarWeaponAttachment
{
class UObject*                                     WorldContextObj                                           // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.IsVirtualAvatarHandle
// 0x0010
struct FIsVirtualAvatarHandle
{
class UObject*                                     WorldContextObj                                           // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.NeedTransAdditionalData
// 0x0001
struct FNeedTransAdditionalData
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.RecordNewFPPSocketInfo
// 0x0068
struct FRecordNewFPPSocketInfo
{
TArray<struct FSpecialMachineConfig>               SpecialMachineConfigFPP                                   // 0x0000(0x0010)
Bool                                               bUsePCMeshConfigCollection                                // 0x0010(0x0001)
unsigned char                                      InOldSKMesh                                               // 0x0018(0x0028)
unsigned char                                      InOldSTMesh                                               // 0x0040(0x0028)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.ReturnWeaponAdditionalBulletsToBackpack
// 0x0010
struct FReturnWeaponAdditionalBulletsToBackpack
{
class ASTExtraShootWeapon*                         Weapon                                                    // 0x0000(0x0008)
int                                                BulletNum                                                 // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.BackpackWeaponAttachHandle.SetParentWeaponHandle
// 0x0008
struct FSetParentWeaponHandle
{
class UItemHandleBase*                             InParentWeaponHandle                                      // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.AddAdditionalDataListOnServerAfterSpawn
// 0x0010
struct FAddAdditionalDataListOnServerAfterSpawn
{
TArray<struct FBattleItemAdditionalData>           DataList                                                  // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.AddProtectType
// 0x0001
struct FAddProtectType
{
EPickupWrapperProtectType                          Type                                                      // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.AddProtectTypeWithTimer
// 0x000C
struct FAddProtectTypeWithTimer
{
EPickupWrapperProtectType                          Type                                                      // 0x0000(0x0001)
float                                              Duration                                                  // 0x0004(0x0004)
Bool                                               bForceOverride                                            // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.BPDoPickUp
// 0x0010
struct FBPDoPickUp
{
class AActor*                                      PickUpOwner                                               // 0x0000(0x0008)
int                                                AdditionalParam                                           // 0x0008(0x0004)
int                                                pickCount                                                 // 0x000C(0x0004)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.CanBePickedUp
// 0x0010
struct FCanBePickedUp
{
class AActor*                                      Picker                                                    // 0x0000(0x0008)
int                                                AdditionalParam                                           // 0x0008(0x0004)
Bool                                               ReturnValue                                               // 0x000C(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.CheckCanBePickedUp
// 0x0010
struct FCheckCanBePickedUp
{
class AActor*                                      Picker                                                    // 0x0000(0x0008)
int                                                AdditionalParam                                           // 0x0008(0x0004)
Bool                                               ReturnValue                                               // 0x000C(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.CheckPickUpDataIsWeapon
// 0x0001
struct FCheckPickUpDataIsWeapon
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.CheckPickUpDataIsWeaponAccessory
// 0x0001
struct FCheckPickUpDataIsWeaponAccessory
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.CheckProtectType
// 0x0038
struct FCheckProtectType
{
EPickupWrapperProtectType                          Type                                                      // 0x0000(0x0001)
class ASTExtraBaseCharacter*                       Character                                                 // 0x0008(0x0008)
struct FPickupWrapperProcectBase                   PickupWrapperProcect                                      // 0x0010(0x0020)
Bool                                               ReturnValue                                               // 0x0030(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.ClearRareLevelEffect
// 0x0010
struct FClearRareLevelEffect
{
TArray<struct FItemDefineID>                       InDefineIds                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.DoPickUp
// 0x0010
struct FDoPickUp
{
class AActor*                                      PickUpOwner                                               // 0x0000(0x0008)
int                                                AdditionalParam                                           // 0x0008(0x0004)
int                                                pickCount                                                 // 0x000C(0x0004)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.EscapeForbidTeammatePickup
// 0x0008
struct FEscapeForbidTeammatePickup
{
int64_t                                            InPlayerKey                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.FinishedPickUpOnServer_BP
// 0x0010
struct FFinishedPickUpOnServer_BP
{
class UBackpackComponent*                          BackpackComp                                              // 0x0000(0x0008)
int                                                PickupCount                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.FinishPickedUp
// 0x0018
struct FFinishPickedUp
{
class AActor*                                      OwnerTarget                                               // 0x0000(0x0008)
int                                                AdditionalParam                                           // 0x0008(0x0004)
int                                                pickCount                                                 // 0x000C(0x0004)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.GetDataList
// 0x0010
struct FGetDataList
{
TArray<struct FPickUpItemData>                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.GetFinalPickUpData
// 0x0048
struct FGetFinalPickUpData
{
struct FPickUpWrapperItem                          ReturnValue                                               // 0x0000(0x0048)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.GetHasBeenPickedUp
// 0x0001
struct FGetHasBeenPickedUp
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.GetKeyProtectEndTime
// 0x0004
struct FGetKeyProtectEndTime
{
float                                              ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.GetLuaModule
// 0x0010
struct FGetLuaModule
{
struct FString                                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.GetNetGUIDOffsetValue
// 0x0004
struct FGetNetGUIDOffsetValue
{
int                                                ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.GetNewGroundEffect
// 0x0010
struct FGetNewGroundEffect
{
Bool                                               bTryLoad                                                  // 0x0000(0x0001)
class UParticleSystem*                             ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.GetNewTrailEffect
// 0x0010
struct FGetNewTrailEffect
{
Bool                                               bTryLoad                                                  // 0x0000(0x0001)
class UParticleSystem*                             ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.GetWrapperDefineID
// 0x0020
struct FGetWrapperDefineID
{
int                                                AdditionalParam                                           // 0x0000(0x0004)
struct FItemDefineID                               ReturnValue                                               // 0x0008(0x0018)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.InitDataNew
// 0x0030
struct FInitDataNew
{
int                                                ItemCount                                                 // 0x0000(0x0004)
struct FString                                     Value                                                     // 0x0008(0x0010)
struct FString                                     Category                                                  // 0x0018(0x0010)
Bool                                               RepeatGenerateItem                                        // 0x0028(0x0001)
int                                                SpotDataIndex                                             // 0x002C(0x0004)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.IsLifeSpanBlackListItem
// 0x0001
struct FIsLifeSpanBlackListItem
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.IsProtectTypeActive
// 0x000C
struct FIsProtectTypeActive
{
EPickupWrapperProtectType                          Type                                                      // 0x0000(0x0001)
float                                              OutRemainingTime                                          // 0x0004(0x0004)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.LoadLightBeam
// 0x0002
struct FLoadLightBeam
{
Bool                                               bShowParticle                                             // 0x0000(0x0001)
Bool                                               bForceLight                                               // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.MarkDroppedPlayer
// 0x0008
struct FMarkDroppedPlayer
{
class AUAEPlayerController*                        PC                                                        // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.MarkIsDropedByPlayerOnServer
// 0x0018
struct FMarkIsDropedByPlayerOnServer
{
Bool                                               Ret                                                       // 0x0000(0x0001)
class AActor*                                      AttachTarget                                              // 0x0008(0x0008)
class UPrimitiveComponent*                         AttachComponent                                           // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.ModifyData
// 0x0004
struct FModifyData
{
int                                                _Count                                                    // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.OnAsyncLoadLightBeam
// 0x0020
struct FOnAsyncLoadLightBeam
{
struct FSoftObjectPath                             _softPath                                                 // 0x0000(0x0018)
Bool                                               bShowParticle                                             // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.OnForceHideRareLevelEffectChange
// 0x0001
struct FOnForceHideRareLevelEffectChange
{
Bool                                               NewValue                                                  // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.OnGroundActorDestroyed
// 0x0008
struct FOnGroundActorDestroyed
{
class AActor*                                      TargetActor                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.OnLoadDropEffectFinish
// 0x0080
struct FOnLoadDropEffectFinish
{
struct FDropGroundEffectInfo                       effectInfo                                                // 0x0000(0x0080)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.OnLoadNewGroundEffect
// 0x0018
struct FOnLoadNewGroundEffect
{
struct FSoftObjectPath                             GroundEffectPath                                          // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.OnLoadNewTrailEffect
// 0x0018
struct FOnLoadNewTrailEffect
{
struct FSoftObjectPath                             TrailEffectPath                                           // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.OnLoadRarelevelEffect
// 0x0018
struct FOnLoadRarelevelEffect
{
struct FSoftObjectPath                             InRarelevelEffectPath                                     // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.OnPostSetActorHiddenInGame
// 0x0001
struct FOnPostSetActorHiddenInGame
{
Bool                                               bNewHidden                                                // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.OnProtectTypeTimerExpired
// 0x0001
struct FOnProtectTypeTimerExpired
{
EPickupWrapperProtectType                          Type                                                      // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.OnRep_Count
// 0x0004
struct FOnRep_Count
{
int                                                OldCount                                                  // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.OnRep_HiddenByPickUp
// 0x0001
struct FOnRep_HiddenByPickUp
{
Bool                                               bOldVal                                                   // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.RemoveProtectType
// 0x0001
struct FRemoveProtectType
{
EPickupWrapperProtectType                          Type                                                      // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.RemoveProtectTypeWithTimer
// 0x0001
struct FRemoveProtectTypeWithTimer
{
EPickupWrapperProtectType                          Type                                                      // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.RPC_Broadcast_NotifyAllClientsHideActorForSomeTime
// 0x0008
struct FRPC_Broadcast_NotifyAllClientsHideActorForSomeTime
{
float                                              Time                                                      // 0x0000(0x0004)
Bool                                               bPendingDestroy                                           // 0x0004(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.RPC_Broadcast_NotifyAllClientsModifySavedAdditionalDataList
// 0x0010
struct FRPC_Broadcast_NotifyAllClientsModifySavedAdditionalDataList
{
TArray<struct FBattleItemAdditionalData>           DataList                                                  // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.ServerSetOpenProtect
// 0x0008
struct FServerSetOpenProtect
{
class AUAEPlayerController*                        PlayerController                                          // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.SetActorAttachTo
// 0x0018
struct FSetActorAttachTo
{
class AActor*                                      TargetActor                                               // 0x0000(0x0008)
EAttachmentRule                                    LocationRule                                              // 0x0008(0x0001)
EAttachmentRule                                    RotationRule                                              // 0x0009(0x0001)
EAttachmentRule                                    ScaleRule                                                 // 0x000A(0x0001)
Bool                                               bWeldSimulatedBodies                                      // 0x000B(0x0001)
struct FName                                       SocketName                                                // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.SetActorToGround
// 0x0008
struct FSetActorToGround
{
class AActor*                                      ignoreActor                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.SetAttachedInfo
// 0x0020
struct FSetAttachedInfo
{
class AActor*                                      TargetActor                                               // 0x0000(0x0008)
struct FVector                                     DetachLocation                                            // 0x0008(0x000C)
EAttachmentRule                                    LocationRule                                              // 0x0014(0x0001)
EAttachmentRule                                    RotationRule                                              // 0x0015(0x0001)
EAttachmentRule                                    ScaleRule                                                 // 0x0016(0x0001)
Bool                                               bWeldSimulatedBodies                                      // 0x0017(0x0001)
struct FName                                       SocketName                                                // 0x0018(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.SetBeenCarried
// 0x0001
struct FSetBeenCarried
{
Bool                                               bInBeenCarried                                            // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.SetCountOnServerAfterSpawn
// 0x0004
struct FSetCountOnServerAfterSpawn
{
int                                                _Count                                                    // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.SetDefineID
// 0x0018
struct FSetDefineID
{
struct FItemDefineID                               DID                                                       // 0x0000(0x0018)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.SetDropLocation
// 0x0020
struct FSetDropLocation
{
Bool                                               bUseCurve                                                 // 0x0000(0x0001)
int                                                GroupID                                                   // 0x0004(0x0004)
struct FVector                                     StartLoc                                                  // 0x0008(0x000C)
struct FVector                                     EndLoc                                                    // 0x0014(0x000C)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.SetForceHideRareLevelEffect
// 0x0001
struct FSetForceHideRareLevelEffect
{
Bool                                               NewValue                                                  // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.SetKeyProtectEndTime
// 0x0004
struct FSetKeyProtectEndTime
{
float                                              ProtectTime                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.SetNotAllowPlayerKey
// 0x0010
struct FSetNotAllowPlayerKey
{
TArray<int64_t>                                    InNotAllowPlayerKey                                       // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.SetOwnerPlayerKey
// 0x0008
struct FSetOwnerPlayerKey
{
int64_t                                            InPlayerKey                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.SetOwnerTeamID
// 0x0004
struct FSetOwnerTeamID
{
int                                                InTeamID                                                  // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.SetPerformanceInfo
// 0x0070
struct FSetPerformanceInfo
{
struct FDropItemPerformanceInfo                    InPerformanceInfo                                         // 0x0000(0x0070)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.ShowMesh
// 0x0001
struct FShowMesh
{
Bool                                               bShow                                                     // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.ShowRareLevelEffect
// 0x0010
struct FShowRareLevelEffect
{
TArray<struct FItemDefineID>                       InDefineIds                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.ToDetailString
// 0x0010
struct FToDetailString
{
struct FString                                     ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.ToggoleGroundEffectOnServer
// 0x000C
struct FToggoleGroundEffectOnServer
{
Bool                                               bShow                                                     // 0x0000(0x0001)
float                                              Time                                                      // 0x0004(0x0004)
Bool                                               bUseDefaultGroundEffect                                   // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.PickUpWrapperActor.UpdateAdditionalDataListOnServerAfterSpawn
// 0x0010
struct FUpdateAdditionalDataListOnServerAfterSpawn
{
TArray<struct FBattleItemAdditionalData>           DataList                                                  // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.WeaponOwnerProxy.GetOwnerActor
// 0x0008
struct FGetOwnerActor
{
class AActor*                                      ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.WeaponOwnerProxy.GetOwnerController
// 0x0008
struct FGetOwnerController
{
class AController*                                 ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.WeaponOwnerProxy.GetOwnerPawn
// 0x0008
struct FGetOwnerPawn
{
class APawn*                                       ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.WeaponOwnerProxy.GetOwnerPlayerController
// 0x0008
struct FGetOwnerPlayerController
{
class APlayerController*                           ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.WeaponOwnerProxy.GetOwnerSTExtraPlayerCharacter
// 0x0008
struct FGetOwnerSTExtraPlayerCharacter
{
class ASTExtraBaseCharacter*                       ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.WeaponOwnerProxy.GetOwnerSTExtraPlayerController
// 0x0008
struct FGetOwnerSTExtraPlayerController
{
class ASTExtraPlayerController*                    ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.WeaponOwnerProxy.HandlePlayerChangePose
// 0x0002
struct FHandlePlayerChangePose
{
unsigned char                                      LastPose                                                  // 0x0000(0x0001)
unsigned char                                      NewPose                                                   // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.WeaponOwnerProxy.HandlePlayerSwitchCameraMode
// 0x0001
struct FHandlePlayerSwitchCameraMode
{
unsigned char                                      Mode                                                      // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.AddDynamicFunctionModule
// 0x0008
struct FAddDynamicFunctionModule
{
class UClass*                                      ModuleClass                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.AddFunctionModuleInternal
// 0x0010
struct FAddFunctionModuleInternal
{
class UClass*                                      ModuleClass                                               // 0x0000(0x0008)
class UWeaponFunctionModuleBase*                   ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.AllowGameplayState
// 0x0018
struct FAllowGameplayState
{
struct FGameplayTag                                GameplayState                                             // 0x0000(0x0010)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.BlockDamageAmount
// 0x001C
struct FBlockDamageAmount
{
float                                              Damage                                                    // 0x0000(0x0004)
int                                                DamageType                                                // 0x0004(0x0004)
struct FVector                                     DamageApplierLoc                                          // 0x0008(0x000C)
float                                              ValidDis                                                  // 0x0014(0x0004)
float                                              ReturnValue                                               // 0x0018(0x0004)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.BlueprintClearWeaponAttrModifier
// 0x0001
struct FBlueprintClearWeaponAttrModifier
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.BlueprintSetWeaponAttrModifierEnable
// 0x0018
struct FBlueprintSetWeaponAttrModifierEnable
{
struct FString                                     AttrModifierID                                            // 0x0000(0x0010)
Bool                                               bNewEnable                                                // 0x0010(0x0001)
Bool                                               ReturnValue                                               // 0x0011(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.BP_IsNeedBeHitFeedback
// 0x0010
struct FBP_IsNeedBeHitFeedback
{
class AActor*                                      InHitTriggerActor                                         // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.BP_TriggerBeHitFeedback
// 0x0010
struct FBP_TriggerBeHitFeedback
{
class AActor*                                      InHitTriggerActor                                         // 0x0000(0x0008)
int                                                InFeedbackItemID                                          // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.BPAttachMeshToSocket
// 0x0008
struct FBPAttachMeshToSocket
{
class UMeshComponent*                              AttachMesh                                                // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.CanBlockDamage
// 0x0001
struct FCanBlockDamage
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.CanSwitchToThisWeapon
// 0x0002
struct FCanSwitchToThisWeapon
{
ESwitchWeaponFlag                                  flag                                                      // 0x0000(0x0001)
Bool                                               ReturnValue                                               // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.CanUsingOnOwnerPawnDying
// 0x0001
struct FCanUsingOnOwnerPawnDying
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.CanUsingOnOwnerPawnSwimming
// 0x0001
struct FCanUsingOnOwnerPawnSwimming
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.ChangeSequenceState
// 0x0002
struct FChangeSequenceState
{
EFreshWeaponStateType                              StateType                                                 // 0x0000(0x0001)
Bool                                               ReturnValue                                               // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.ChangeSequenceStateInner
// 0x0001
struct FChangeSequenceStateInner
{
EFreshWeaponStateType                              LastStateType                                             // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.CheckAttachSocketAndReattach
// 0x0001
struct FCheckAttachSocketAndReattach
{
Bool                                               bOnlyAttach                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.CheckCanCooperateAsAdditionalWeaponWithTargetWeapon
// 0x0010
struct FCheckCanCooperateAsAdditionalWeaponWithTargetWeapon
{
class ASTExtraWeapon*                              TargetWeapon                                              // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.CheckCanCooperateAsFastDrawWeaponWithTargetWeapon
// 0x0010
struct FCheckCanCooperateAsFastDrawWeaponWithTargetWeapon
{
class ASTExtraWeapon*                              TargetWeapon                                              // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.CheckCanSwitchOnOwnerPawnDying
// 0x0001
struct FCheckCanSwitchOnOwnerPawnDying
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.CheckEnableOnSwitch
// 0x0002
struct FCheckEnableOnSwitch
{
Bool                                               bCallFromDSOnly                                           // 0x0000(0x0001)
Bool                                               ReturnValue                                               // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.CheckNeedDestroyWeaponWhenDisuseOnServer
// 0x0001
struct FCheckNeedDestroyWeaponWhenDisuseOnServer
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.CheckStateSync
// 0x0008
struct FCheckStateSync
{
float                                              DeltaTime                                                 // 0x0000(0x0004)
Bool                                               ForceSync                                                 // 0x0004(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.CheckStateSyncAvailable
// 0x0001
struct FCheckStateSyncAvailable
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.CheckWeaponMainMeshLoadFinished
// 0x0001
struct FCheckWeaponMainMeshLoadFinished
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.CreateSkillHandleCompAfterCreateWeaponHandleCallback
// 0x0020
struct FCreateSkillHandleCompAfterCreateWeaponHandleCallback
{
struct FItemDefineID                               DefineID                                                  // 0x0000(0x0018)
class UBattleItemHandleBase*                       BattleItemHandle                                          // 0x0018(0x0008)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.DisuseAllWeaponAttachmentsOnServer
// 0x0001
struct FDisuseAllWeaponAttachmentsOnServer
{
EBattleItemDisuseReason                            Reason                                                    // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.DSNotifyClientCorrectStateLeak
// 0x0001
struct FDSNotifyClientCorrectStateLeak
{
EFreshWeaponStateType                              RightState                                                // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.EnterGameplayState
// 0x0018
struct FEnterGameplayState
{
struct FGameplayTag                                GameplayState                                             // 0x0000(0x0010)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.ExclusiveHold
// 0x0001
struct FExclusiveHold
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.ForceChangeAllClientWeaponStateOnServer
// 0x0001
struct FForceChangeAllClientWeaponStateOnServer
{
EFreshWeaponStateType                              StateType                                                 // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function ShadowTrackerExtra.STExtraWeapon.ForceOverrideCharacterAnim
// 0x0018
struct FForceOverrideCharacterAnim
{
class UAnimationAsset*                             InAnimAsset                                               // 0x0000(0x0008)
unsigned char                                      AnimType                                                  // 0x0008(0x0001)
unsigned char                                      PoseType                                                  // 0x0009(0x0001)
class UAnimationAsset*                             ReturnValue                                               // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.CanSpectate
// 0x0018
struct FCanSpectate
{
class APlayerController*                           Viewer                                                    // 0x0000(0x0008)
class APlayerState*                                ViewTarget                                                // 0x0008(0x0008)
Bool                                               ReturnValue                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.ChangeName
// 0x0020
struct FChangeName
{
class AController*                                 Controller                                                // 0x0000(0x0008)
struct FString                                     NewName                                                   // 0x0008(0x0010)
Bool                                               bNameChange                                               // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.ChoosePlayerStart
// 0x0010
struct FChoosePlayerStart
{
class AController*                                 Player                                                    // 0x0000(0x0008)
class AActor*                                      ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.FindPlayerStart
// 0x0020
struct FFindPlayerStart
{
class AController*                                 Player                                                    // 0x0000(0x0008)
struct FString                                     IncomingName                                              // 0x0008(0x0010)
class AActor*                                      ReturnValue                                               // 0x0018(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.GetDefaultPawnClassForController
// 0x0010
struct FGetDefaultPawnClassForController
{
class AController*                                 InController                                              // 0x0000(0x0008)
class UClass*                                      ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.GetNumPlayers
// 0x0004
struct FGetNumPlayers
{
int                                                ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.GetNumSpectators
// 0x0004
struct FGetNumSpectators
{
int                                                ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.HandleStartingNewPlayer
// 0x0008
struct FHandleStartingNewPlayer
{
class APlayerController*                           NewPlayer                                                 // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.HasMatchStarted
// 0x0001
struct FHasMatchStarted
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.InitializeHUDForPlayer
// 0x0008
struct FInitializeHUDForPlayer
{
class APlayerController*                           NewPlayer                                                 // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.InitStartSpot
// 0x0010
struct FInitStartSpot
{
class AActor*                                      StartSpot                                                 // 0x0000(0x0008)
class AController*                                 NewPlayer                                                 // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.K2_FindPlayerStart
// 0x0020
struct FK2_FindPlayerStart
{
class AController*                                 Player                                                    // 0x0000(0x0008)
struct FString                                     IncomingName                                              // 0x0008(0x0010)
class AActor*                                      ReturnValue                                               // 0x0018(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.K2_OnChangeName
// 0x0020
struct FK2_OnChangeName
{
class AController*                                 Other                                                     // 0x0000(0x0008)
struct FString                                     NewName                                                   // 0x0008(0x0010)
Bool                                               bNameChange                                               // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.K2_OnLogout
// 0x0008
struct FK2_OnLogout
{
class AController*                                 ExitingController                                         // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.K2_OnRestartPlayer
// 0x0008
struct FK2_OnRestartPlayer
{
class AController*                                 NewPlayer                                                 // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.K2_OnSwapPlayerControllers
// 0x0010
struct FK2_OnSwapPlayerControllers
{
class APlayerController*                           OldPC                                                     // 0x0000(0x0008)
class APlayerController*                           NewPC                                                     // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.K2_PostLogin
// 0x0008
struct FK2_PostLogin
{
class APlayerController*                           NewPlayer                                                 // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.MustSpectate
// 0x0010
struct FMustSpectate
{
class APlayerController*                           NewPlayerController                                       // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.PlayerCanRestart
// 0x0010
struct FPlayerCanRestart
{
class APlayerController*                           Player                                                    // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.RestartPlayer
// 0x0008
struct FRestartPlayer
{
class AController*                                 NewPlayer                                                 // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.RestartPlayerAtPlayerStart
// 0x0010
struct FRestartPlayerAtPlayerStart
{
class AController*                                 NewPlayer                                                 // 0x0000(0x0008)
class AActor*                                      StartSpot                                                 // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.RestartPlayerAtTransform
// 0x0040
struct FRestartPlayerAtTransform
{
class AController*                                 NewPlayer                                                 // 0x0000(0x0008)
struct FTransform                                  SpawnTransform                                            // 0x0010(0x0030)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.ShouldReset
// 0x0010
struct FShouldReset
{
class AActor*                                      ActorToReset                                              // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.SpawnDefaultPawnAtTransform
// 0x0050
struct FSpawnDefaultPawnAtTransform
{
class AController*                                 NewPlayer                                                 // 0x0000(0x0008)
struct FTransform                                  SpawnTransform                                            // 0x0010(0x0030)
class APawn*                                       ReturnValue                                               // 0x0040(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.GameModeBase.SpawnDefaultPawnFor
// 0x0018
struct FSpawnDefaultPawnFor
{
class AController*                                 NewPlayer                                                 // 0x0000(0x0008)
class AActor*                                      StartSpot                                                 // 0x0008(0x0008)
class APawn*                                       ReturnValue                                               // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.GameMode.GetMatchState
// 0x0008
struct FGetMatchState
{
struct FName                                       ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.GameMode.HasMatchEnded
// 0x0001
struct FHasMatchEnded
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.GameMode.IsMatchInProgress
// 0x0001
struct FIsMatchInProgress
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.GameMode.K2_OnSetMatchState
// 0x0008
struct FK2_OnSetMatchState
{
struct FName                                       NewState                                                  // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Engine.GameMode.ReadyToEndMatch
// 0x0001
struct FReadyToEndMatch
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.GameMode.ReadyToStartMatch
// 0x0001
struct FReadyToStartMatch
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Engine.GameMode.Say
// 0x0010
struct FSay
{
struct FString                                     Msg                                                       // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Engine.GameMode.SetBandwidthLimit
// 0x0004
struct FSetBandwidthLimit
{
float                                              AsyncIOBandwidthLimit                                     // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Basic.BasicGameMode.GetGameModeGenericAbilityTypes
// 0x0010
struct FGetGameModeGenericAbilityTypes
{
TArray<int>                                        ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Basic.BasicGameMode.IsGameModeEnableGenericAbility
// 0x0001
struct FIsGameModeEnableGenericAbility
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.AllowReconnectionWhenDead
// 0x0001
struct FAllowReconnectionWhenDead
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.BPFindPlayerControllerWithPlayerKey
// 0x0018
struct FBPFindPlayerControllerWithPlayerKey
{
struct FString                                     PlayerKey                                                 // 0x0000(0x0010)
class AUAEPlayerController*                        ReturnValue                                               // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.BPFindPlayerStateWithPlayerKey
// 0x0018
struct FBPFindPlayerStateWithPlayerKey
{
struct FString                                     PlayerKey                                                 // 0x0000(0x0010)
class AUAEPlayerState*                             ReturnValue                                               // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.ChangeAdvertisementURL
// 0x0018
struct FChangeAdvertisementURL
{
int                                                AdvID                                                     // 0x0000(0x0004)
struct FString                                     URL                                                       // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.ChangeName
// 0x0020
struct FChangeName
{
class AController*                                 Controller                                                // 0x0000(0x0008)
struct FString                                     NewName                                                   // 0x0008(0x0010)
Bool                                               bNameChange                                               // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.CheckFeatureSupported
// 0x0002
struct FCheckFeatureSupported
{
unsigned char                                      SubSystemId                                               // 0x0000(0x0001)
Bool                                               ReturnValue                                               // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.CheckOverrideRestartPlayer
// 0x0001
struct FCheckOverrideRestartPlayer
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.CheckPickupItemLimitedCount
// 0x0030
struct FCheckPickupItemLimitedCount
{
struct FItemDefineID                               InTargetItem                                              // 0x0000(0x0018)
class UBackpackComponent*                          InTargetBackpack                                          // 0x0018(0x0008)
int                                                InTargetPickupCount                                       // 0x0020(0x0004)
int                                                OutLimitedItemCount                                       // 0x0024(0x0004)
Bool                                               ReturnValue                                               // 0x0028(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.CheckRevivalSaveItemLimit
// 0x0018
struct FCheckRevivalSaveItemLimit
{
class UItemHandleBase*                             InTargetItem                                              // 0x0000(0x0008)
class UBackpackComponent*                          InTargetBackpack                                          // 0x0008(0x0008)
int                                                OutLimitedItemCount                                       // 0x0010(0x0004)
Bool                                               ReturnValue                                               // 0x0014(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.CreateDynamicComponentForCharacter
// 0x0008
struct FCreateDynamicComponentForCharacter
{
class APawn*                                       NewPawn                                                   // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.CreateDynamicComponentForPlayerController
// 0x0008
struct FCreateDynamicComponentForPlayerController
{
class APlayerController*                           NewPlayer                                                 // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.CustomFilterNeedSaveBattleItem
// 0x0010
struct FCustomFilterNeedSaveBattleItem
{
class UItemHandleBase*                             ItemHandle                                                // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.DebugEnterFriendObserver
// 0x0008
struct FDebugEnterFriendObserver
{
class AUAEPlayerController*                        InController                                              // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.demo_net_callback
// 0x0018
struct Fdemo_net_callback
{
uint64_t                                           UID                                                       // 0x0000(0x0008)
struct FString                                     Msg                                                       // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.DestroyCharacterForPlayerController
// 0x0008
struct FDestroyCharacterForPlayerController
{
class APlayerController*                           PC                                                        // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.DoSomethingAfterPickup
// 0x0010
struct FDoSomethingAfterPickup
{
class UBattleItemHandleBase*                       Handle                                                    // 0x0000(0x0008)
EBattleItemUseReason                               Reason                                                    // 0x0008(0x0001)
Bool                                               ToBackpack                                                // 0x0009(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.DoSomethingBeforeDrop
// 0x0010
struct FDoSomethingBeforeDrop
{
class UBattleItemHandleBase*                       Handle                                                    // 0x0000(0x0008)
EBattleItemDropReason                              Reason                                                    // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.EnsureEscapeReason
// 0x0008
struct FEnsureEscapeReason
{
class APlayerController*                           Exiting                                                   // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.FindAllIDIPHandleByClass
// 0x0018
struct FFindAllIDIPHandleByClass
{
class UClass*                                      InputClass                                                // 0x0000(0x0008)
TArray<class UIDIPHandle*>                         ReturnValue                                               // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.FindIDIPHandleByClass
// 0x0010
struct FFindIDIPHandleByClass
{
class UClass*                                      InputClass                                                // 0x0000(0x0008)
class UIDIPHandle*                                 ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.FindPlayerControllerWithInt64PlayerKey
// 0x0010
struct FFindPlayerControllerWithInt64PlayerKey
{
int64_t                                            PlayerKey                                                 // 0x0000(0x0008)
class AUAEPlayerController*                        ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.FindPlayerControllerWithPlayerKey
// 0x0018
struct FFindPlayerControllerWithPlayerKey
{
uint32_t                                           PlayerKey                                                 // 0x0000(0x0004)
struct FName                                       PlayerType                                                // 0x0008(0x0008)
class AUAEPlayerController*                        ReturnValue                                               // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.FindPlayerStateWithPlayerKey
// 0x0018
struct FFindPlayerStateWithPlayerKey
{
uint32_t                                           PlayerKey                                                 // 0x0000(0x0004)
struct FName                                       PlayerType                                                // 0x0008(0x0008)
class AUAEPlayerState*                             ReturnValue                                               // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.GetCircleConfigNum
// 0x0004
struct FGetCircleConfigNum
{
int                                                ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.GetCircleEndTime
// 0x0008
struct FGetCircleEndTime
{
int                                                CircleIndex                                               // 0x0000(0x0004)
float                                              ReturnValue                                               // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.GetCircleStartTime
// 0x0008
struct FGetCircleStartTime
{
int                                                CircleIndex                                               // 0x0000(0x0004)
float                                              ReturnValue                                               // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.GetCurrentLobbyTime
// 0x0008
struct FGetCurrentLobbyTime
{
struct FDateTime                                   ReturnValue                                               // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.GetDeviceType
// 0x0010
struct FGetDeviceType
{
class AUAEPlayerController*                        PC                                                        // 0x0000(0x0008)
int                                                ReturnValue                                               // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.GetDSPlayerList
// 0x0010
struct FGetDSPlayerList
{
TArray<struct FGameModePlayerParams>               ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.GetDynamicBattleRankInfoList
// 0x0010
struct FGetDynamicBattleRankInfoList
{
TArray<struct FDynamicBattleRankInfo>              ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.GetNewAddPath
// 0x0020
struct FGetNewAddPath
{
int                                                ID                                                        // 0x0000(0x0004)
struct FString                                     OutPath                                                   // 0x0008(0x0010)
Bool                                               bOutOnlyVisibleToObserver                                 // 0x0018(0x0001)
Bool                                               ReturnValue                                               // 0x0019(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.GetObserverControllerList
// 0x0010
struct FGetObserverControllerList
{
TArray<class AUAEPlayerController*>                ReturnValue                                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.GetPlayerAddress
// 0x0018
struct FGetPlayerAddress
{
uint32_t                                           PlayerKey                                                 // 0x0000(0x0004)
struct FString                                     ReturnValue                                               // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.GetPlayerAndRealAiNum
// 0x0008
struct FGetPlayerAndRealAiNum
{
int                                                OutPlayerNum                                              // 0x0000(0x0004)
int                                                OutRealAiNum                                              // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.GetPlayerControllerListWithTeamID
// 0x0020
struct FGetPlayerControllerListWithTeamID
{
int                                                TeamID                                                    // 0x0000(0x0004)
struct FName                                       PlayerType                                                // 0x0008(0x0008)
TArray<class AUAEPlayerController*>                ReturnValue                                               // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.GetPlayerStateByUID
// 0x0018
struct FGetPlayerStateByUID
{
struct FString                                     UID                                                       // 0x0000(0x0010)
class AUAEPlayerState*                             ReturnValue                                               // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.GetPlayerStateIncludeAIByUID
// 0x0018
struct FGetPlayerStateIncludeAIByUID
{
struct FString                                     UID                                                       // 0x0000(0x0010)
class AUAEPlayerState*                             ReturnValue                                               // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.GetPlayerStateListWithTeamID
// 0x0020
struct FGetPlayerStateListWithTeamID
{
int                                                TeamID                                                    // 0x0000(0x0004)
struct FName                                       PlayerType                                                // 0x0008(0x0008)
TArray<class AUAEPlayerState*>                     ReturnValue                                               // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.GetSpawnSpot
// 0x0040
struct FGetSpawnSpot
{
class AActor*                                      Actor                                                     // 0x0000(0x0008)
struct FVector                                     StartLocation                                             // 0x0008(0x000C)
struct FRotator                                    StartRotation                                             // 0x0014(0x000C)
Bool                                               OnlyZ                                                     // 0x0020(0x0001)
float                                              PawnRadius                                                // 0x0024(0x0004)
float                                              PawnHeight                                                // 0x0028(0x0004)
struct FVector                                     OutSpawnSpot                                              // 0x002C(0x000C)
Bool                                               ReturnValue                                               // 0x0038(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.GetSurvivingCharacterCount
// 0x0004
struct FGetSurvivingCharacterCount
{
int                                                ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.GetSurvivingTeamCount
// 0x0004
struct FGetSurvivingTeamCount
{
int                                                ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.GetTrainingStatisticsDataByUID
// 0x0038
struct FGetTrainingStatisticsDataByUID
{
uint64_t                                           UID                                                       // 0x0000(0x0008)
struct FTrainingStatisticsData                     ReturnValue                                               // 0x0008(0x0030)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.GetUniqueLogicID
// 0x0004
struct FGetUniqueLogicID
{
int                                                ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.GotoNearDeath
// 0x0010
struct FGotoNearDeath
{
class AController*                                 DamageInstigator                                          // 0x0000(0x0008)
class APawn*                                       VictimPawn                                                // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.HandlePlayerExit
// 0x0010
struct FHandlePlayerExit
{
class AUAEPlayerController*                        ExitPC                                                    // 0x0000(0x0008)
Bool                                               ReturnValue                                               // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.HandlePlayerGiftItemResponse
// 0x0020
struct FHandlePlayerGiftItemResponse
{
uint32_t                                           PlayerKey                                                 // 0x0000(0x0004)
struct FName                                       PlayerType                                                // 0x0008(0x0008)
int                                                Result                                                    // 0x0010(0x0004)
int                                                GiftResID                                                 // 0x0014(0x0004)
int                                                Count                                                     // 0x0018(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.HandlePlayerPaintDecalResponse
// 0x0020
struct FHandlePlayerPaintDecalResponse
{
uint32_t                                           PlayerKey                                                 // 0x0000(0x0004)
struct FName                                       PlayerType                                                // 0x0008(0x0008)
int                                                Result                                                    // 0x0010(0x0004)
int                                                DecalId                                                   // 0x0014(0x0004)
int                                                Count                                                     // 0x0018(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.HasMatchGoalAchieved
// 0x0001
struct FHasMatchGoalAchieved
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.IsCollectedEventEnabled
// 0x0002
struct FIsCollectedEventEnabled
{
unsigned char                                      EventId                                                   // 0x0000(0x0001)
Bool                                               ReturnValue                                               // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.IsFeatureSupported
// 0x0002
struct FIsFeatureSupported
{
ESubSystemType                                     SubSystemType                                             // 0x0000(0x0001)
Bool                                               ReturnValue                                               // 0x0001(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.IsPCDS
// 0x0001
struct FIsPCDS
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.IsPlayerCollectedEventDataReportingEnabled
// 0x0010
struct FIsPlayerCollectedEventDataReportingEnabled
{
class AUAEPlayerController*                        UAEPlayerController                                       // 0x0000(0x0008)
unsigned char                                      EventId                                                   // 0x0008(0x0001)
Bool                                               ReturnValue                                               // 0x0009(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.KillCharacterOnPlayerExit
// 0x0008
struct FKillCharacterOnPlayerExit
{
class APlayerController*                           PC                                                        // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.Killed
// 0x0050
struct FKilled
{
class AController*                                 Killer                                                    // 0x0000(0x0008)
class AController*                                 VictimPlayer                                              // 0x0008(0x0008)
class APawn*                                       VictimPawn                                                // 0x0010(0x0008)
struct FDamageEvent                                DamageEvent                                               // 0x0018(0x0038)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.ModifyDamage
// 0x0060
struct FModifyDamage
{
float                                              Damage                                                    // 0x0000(0x0004)
struct FDamageEvent                                DamageEvent                                               // 0x0008(0x0038)
class AController*                                 EventInstigator                                           // 0x0040(0x0008)
class AController*                                 VictimController                                          // 0x0048(0x0008)
class AActor*                                      DamageCauser                                              // 0x0050(0x0008)
float                                              ReturnValue                                               // 0x0058(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.ModifyDecalDyeCountResponse
// 0x0020
struct FModifyDecalDyeCountResponse
{
uint32_t                                           PlayerKey                                                 // 0x0000(0x0004)
struct FName                                       PlayerType                                                // 0x0008(0x0008)
int                                                Result                                                    // 0x0010(0x0004)
int                                                ItemID                                                    // 0x0014(0x0004)
int                                                Count                                                     // 0x0018(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.ModifyFinalDamage
// 0x0078
struct FModifyFinalDamage
{
float                                              Damage                                                    // 0x0000(0x0004)
struct FDamageEvent                                DamageEvent                                               // 0x0008(0x0038)
class AController*                                 EventInstigator                                           // 0x0040(0x0008)
class AController*                                 VictimController                                          // 0x0048(0x0008)
class AActor*                                      DamageCauser                                              // 0x0050(0x0008)
class AActor*                                      VictimActor                                               // 0x0058(0x0008)
struct FExtraDamageCalculationResult               ExtraResult                                               // 0x0060(0x0010)
float                                              ReturnValue                                               // 0x0070(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.ModifyFinalRecoverHealth
// 0x0050
struct FModifyFinalRecoverHealth
{
float                                              RecoverValue                                              // 0x0000(0x0004)
class AController*                                 CauserInstigator                                          // 0x0008(0x0008)
class AController*                                 TargetController                                          // 0x0010(0x0008)
class AActor*                                      RecoveryCauser                                            // 0x0018(0x0008)
class AActor*                                      TargetActor                                               // 0x0020(0x0008)
TArray<struct FGameplayTag>                        ExtraRecoverTags                                          // 0x0028(0x0010)
struct FExtraDamageCalculationResult               ExtraResult                                               // 0x0038(0x0010)
float                                              ReturnValue                                               // 0x0048(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.ModifyGlideCountResponse
// 0x0020
struct FModifyGlideCountResponse
{
uint32_t                                           PlayerKey                                                 // 0x0000(0x0004)
struct FName                                       PlayerType                                                // 0x0008(0x0008)
int                                                Result                                                    // 0x0010(0x0004)
int                                                ItemID                                                    // 0x0014(0x0004)
int                                                Count                                                     // 0x0018(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.ModifyReductionDamage
// 0x0060
struct FModifyReductionDamage
{
float                                              Damage                                                    // 0x0000(0x0004)
struct FDamageEvent                                DamageEvent                                               // 0x0008(0x0038)
class AController*                                 EventInstigator                                           // 0x0040(0x0008)
class AController*                                 VictimController                                          // 0x0048(0x0008)
class AActor*                                      DamageCauser                                              // 0x0050(0x0008)
float                                              ReturnValue                                               // 0x0058(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.ModifySpecMotionRestCostCountResponse
// 0x0020
struct FModifySpecMotionRestCostCountResponse
{
uint32_t                                           PlayerKey                                                 // 0x0000(0x0004)
struct FName                                       PlayerType                                                // 0x0008(0x0008)
int                                                Result                                                    // 0x0010(0x0004)
int                                                ItemID                                                    // 0x0014(0x0004)
int                                                Count                                                     // 0x0018(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.ModifyVehicleDamage
// 0x0060
struct FModifyVehicleDamage
{
float                                              Damage                                                    // 0x0000(0x0004)
struct FDamageEvent                                DamageEvent                                               // 0x0008(0x0038)
class AController*                                 EventInstigator                                           // 0x0040(0x0008)
class AController*                                 VictimController                                          // 0x0048(0x0008)
class AActor*                                      DamageCauser                                              // 0x0050(0x0008)
float                                              ReturnValue                                               // 0x0058(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.NotifyCollectedEventDatasInfoSynced
// 0x0010
struct FNotifyCollectedEventDatasInfoSynced
{
TArray<struct FCollectedEventDataInfo>             InCollectedEventDatasInfo                                 // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.NotifyPlayerAbleToExitSafely
// 0x0010
struct FNotifyPlayerAbleToExitSafely
{
uint32_t                                           PlayerKey                                                 // 0x0000(0x0004)
struct FName                                       PlayerType                                                // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.NotifyPlayerEnterInstance
// 0x0010
struct FNotifyPlayerEnterInstance
{
uint64_t                                           InstanceID                                                // 0x0000(0x0008)
uint64_t                                           UID                                                       // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.NotifyPlayerExit
// 0x0028
struct FNotifyPlayerExit
{
uint32_t                                           PlayerKey                                                 // 0x0000(0x0004)
struct FName                                       PlayerType                                                // 0x0008(0x0008)
Bool                                               bDestroyPlayerController                                  // 0x0010(0x0001)
Bool                                               bDestroyCharacter                                         // 0x0011(0x0001)
Bool                                               bSendFailure                                              // 0x0012(0x0001)
struct FString                                     FailureMessage                                            // 0x0018(0x0010)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.NotifyPlayerExitInstance
// 0x0010
struct FNotifyPlayerExitInstance
{
uint64_t                                           InstanceID                                                // 0x0000(0x0008)
uint64_t                                           UID                                                       // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.NotifyPlayerPrompt
// 0x0020
struct FNotifyPlayerPrompt
{
uint32_t                                           PlayerKey                                                 // 0x0000(0x0004)
int                                                TeamID                                                    // 0x0004(0x0004)
int                                                PromptType                                                // 0x0008(0x0004)
struct FString                                     Msg                                                       // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.NotifyPlayerReenter
// 0x0010
struct FNotifyPlayerReenter
{
uint32_t                                           PlayerKey                                                 // 0x0000(0x0004)
struct FName                                       PlayerType                                                // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.NotifyPrePlayerExit
// 0x0010
struct FNotifyPrePlayerExit
{
uint32_t                                           PlayerKey                                                 // 0x0000(0x0004)
struct FName                                       PlayerType                                                // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.NotifyTeamParamsSynced
// 0x0010
struct FNotifyTeamParamsSynced
{
TArray<struct FGameModeCollectedEventTeamParams>   TeamParams                                                // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.OnMsg
// 0x0010
struct FOnMsg
{
struct FString                                     Msg                                                       // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.OnNormalPlayerLogin
// 0x0008
struct FOnNormalPlayerLogin
{
class AUAEPlayerController*                        InController                                              // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.OnNotifyPlayerExit
// 0x0018
struct FOnNotifyPlayerExit
{
class AUAEPlayerController*                        ExitPlayer                                                // 0x0000(0x0008)
struct FString                                     Message                                                   // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.OnObserverLogin
// 0x0008
struct FOnObserverLogin
{
class AUAEPlayerController*                        InController                                              // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.OnObserverLogout
// 0x0008
struct FOnObserverLogout
{
class AUAEPlayerController*                        InController                                              // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.OnPlayerRealExit
// 0x0008
struct FOnPlayerRealExit
{
class APlayerController*                           Exiting                                                   // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.OnPlayerStartFire
// 0x0004
struct FOnPlayerStartFire
{
uint32_t                                           InPlayerKey                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.OnPlayerStopFire
// 0x0004
struct FOnPlayerStopFire
{
uint32_t                                           InPlayerKey                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.PreCreatePlayerController
// 0x0010
struct FPreCreatePlayerController
{
uint32_t                                           PlayerKey                                                 // 0x0000(0x0004)
class APlayerController*                           ReturnValue                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.PreCreatePlayerPawn
// 0x0018
struct FPreCreatePlayerPawn
{
uint64_t                                           UID                                                       // 0x0000(0x0008)
class AController*                                 NewPlayer                                                 // 0x0008(0x0008)
class AUAECharacter*                               ReturnValue                                               // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.PreRestartPlayer
// 0x0008
struct FPreRestartPlayer
{
class AController*                                 NewPlayer                                                 // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.QuitGameIsNotEscape
// 0x0001
struct FQuitGameIsNotEscape
{
Bool                                               ReturnValue                                               // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.ReceivedIDIPStates
// 0x0050
struct FReceivedIDIPStates
{
TMap<int, struct FIDIPStateInfo>                   IDIPStateInfos                                            // 0x0000(0x0050)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.RecoardAlivePlayerNum
// 0x0004
struct FRecoardAlivePlayerNum
{
int                                                ReturnValue                                               // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.RefreshPlayerStaticInfo
// 0x0038
struct FRefreshPlayerStaticInfo
{
uint32_t                                           InPlayerKey                                               // 0x0000(0x0004)
struct FString                                     InPlayerName                                              // 0x0008(0x0010)
struct FString                                     PlayerUID                                                 // 0x0018(0x0010)
int                                                TeamID                                                    // 0x0028(0x0004)
unsigned char                                      IdxInTeam                                                 // 0x002C(0x0001)
int                                                JumpSegmentID                                             // 0x0030(0x0004)
Bool                                               IsLogin                                                   // 0x0034(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.RefreshWatchTeammates
// 0x0010
struct FRefreshWatchTeammates
{
class AUAEPlayerController*                        InController                                              // 0x0000(0x0008)
int                                                InTeamID                                                  // 0x0008(0x0004)
Bool                                               IsAITeam                                                  // 0x000C(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.RegisterItemGroupSpots
// 0x0008
struct FRegisterItemGroupSpots
{
class UGroupSpotSceneComponent*                    GroupSpotComponent                                        // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.RegisterItemGroupSpotsByTag
// 0x0010
struct FRegisterItemGroupSpotsByTag
{
struct FName                                       Tag                                                       // 0x0000(0x0008)
class UGroupSpotSceneComponent*                    GroupSpotComponent                                        // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.RemoveLocationFromExcludeSpot
// 0x0010
struct FRemoveLocationFromExcludeSpot
{
struct FVector                                     Location                                                  // 0x0000(0x000C)
int                                                ReturnValue                                               // 0x000C(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.RemoveUnuseComponentInternal
// 0x0008
struct FRemoveUnuseComponentInternal
{
class UActorComponent*                             CompToRemove                                              // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.ReportCollectedEventData
// 0x0070
struct FReportCollectedEventData
{
struct FString                                     UID                                                       // 0x0000(0x0010)
unsigned char                                      EventId                                                   // 0x0010(0x0001)
struct FCollectedEventData                         Data                                                      // 0x0018(0x0050)
Bool                                               ReturnValue                                               // 0x0068(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.ReportCollectedEventDataGlobal
// 0x0020
struct FReportCollectedEventDataGlobal
{
unsigned char                                      EventId                                                   // 0x0000(0x0001)
struct FScriptDelegate                             CollectReportedEventDataCallback                          // 0x0008(0x0010)
Bool                                               ReturnValue                                               // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.ReportCollectedEventDataWithPlayersValidation
// 0x0020
struct FReportCollectedEventDataWithPlayersValidation
{
unsigned char                                      EventId                                                   // 0x0000(0x0001)
struct FScriptDelegate                             CollectReportedEventDataCallback                          // 0x0008(0x0010)
Bool                                               ReturnValue                                               // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.ReportCollectedEventDataWithPlayerValidation
// 0x0028
struct FReportCollectedEventDataWithPlayerValidation
{
class AUAEPlayerController*                        UAEPlayerController                                       // 0x0000(0x0008)
unsigned char                                      EventId                                                   // 0x0008(0x0001)
struct FScriptDelegate                             CollectReportedEventDataCallback                          // 0x0010(0x0010)
Bool                                               ReturnValue                                               // 0x0020(0x0001)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.Rescue
// 0x0008
struct FRescue
{
int                                                RescuerKey                                                // 0x0000(0x0004)
uint32_t                                           SavorKey                                                  // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// Function Gameplay.UAEGameMode.RestartPlayerAtPlayerStart
// 0x0010
struct FRestartPlayerAtPlayerStart
{
class AController*                                 NewPlayer                        