// 大佬QQ:2396031563
// ScriptStruct CoreUObject.JoinabilitySettings
// 0x0018
struct FJoinabilitySettings
{
struct FName                                       SessionName                                               // 0x0000(0x0008)
Bool                                               bPublicSearchable                                         // 0x0008(0x0001)
Bool                                               bAllowInvites                                             // 0x0009(0x0001)
Bool                                               bJoinViaPresence                                          // 0x000A(0x0001)
Bool                                               bJoinViaPresenceFriendsOnly                               // 0x000B(0x0001)
int                                                MaxPlayers                                                // 0x000C(0x0004)
int                                                MaxPartySize                                              // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.Guid
// 0x0010
struct FGuid
{
int                                                A                                                         // 0x0000(0x0004)
int                                                B                                                         // 0x0004(0x0004)
int                                                C                                                         // 0x0008(0x0004)
int                                                D                                                         // 0x000C(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.Vector
// 0x000C
struct FVector
{
float                                              X                                                         // 0x0000(0x0004)
float                                              Y                                                         // 0x0004(0x0004)
float                                              Z                                                         // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.Vector4
// 0x0010
struct FVector4
{
float                                              X                                                         // 0x0000(0x0004)
float                                              Y                                                         // 0x0004(0x0004)
float                                              Z                                                         // 0x0008(0x0004)
float                                              W                                                         // 0x000C(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.Vector2D
// 0x0008
struct FVector2D
{
float                                              X                                                         // 0x0000(0x0004)
float                                              Y                                                         // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.TwoVectors
// 0x0018
struct FTwoVectors
{
struct FVector                                     v1                                                        // 0x0000(0x000C)
struct FVector                                     v2                                                        // 0x000C(0x000C)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.Plane
// 0x0004 (0x0010 - 0x000C)
struct FPlane : public FVector
{
float                                              W                                                         // 0x000C(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.Rotator
// 0x000C
struct FRotator
{
float                                              Pitch                                                     // 0x0000(0x0004)
float                                              Yaw                                                       // 0x0004(0x0004)
float                                              Roll                                                      // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.Quat
// 0x0010
struct FQuat
{
float                                              X                                                         // 0x0000(0x0004)
float                                              Y                                                         // 0x0004(0x0004)
float                                              Z                                                         // 0x0008(0x0004)
float                                              W                                                         // 0x000C(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.PackedNormal
// 0x0004
struct FPackedNormal
{
unsigned char                                      X                                                         // 0x0000(0x0001)
unsigned char                                      Y                                                         // 0x0001(0x0001)
unsigned char                                      Z                                                         // 0x0002(0x0001)
unsigned char                                      W                                                         // 0x0003(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.PackedRGB10A2N
// 0x0004
struct FPackedRGB10A2N
{
int                                                Packed                                                    // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.PackedRGBA16N
// 0x0008
struct FPackedRGBA16N
{
int                                                XY                                                        // 0x0000(0x0004)
int                                                ZW                                                        // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.IntPoint
// 0x0008
struct FIntPoint
{
int                                                X                                                         // 0x0000(0x0004)
int                                                Y                                                         // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.IntVector
// 0x000C
struct FIntVector
{
int                                                X                                                         // 0x0000(0x0004)
int                                                Y                                                         // 0x0004(0x0004)
int                                                Z                                                         // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.Color
// 0x0004
struct FColor
{
unsigned char                                      B                                                         // 0x0000(0x0001)
unsigned char                                      G                                                         // 0x0001(0x0001)
unsigned char                                      R                                                         // 0x0002(0x0001)
unsigned char                                      A                                                         // 0x0003(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.LinearColor
// 0x0010
struct FLinearColor
{
float                                              R                                                         // 0x0000(0x0004)
float                                              G                                                         // 0x0004(0x0004)
float                                              B                                                         // 0x0008(0x0004)
float                                              A                                                         // 0x000C(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.Box
// 0x001C
struct FBox
{
struct FVector                                     Min                                                       // 0x0000(0x000C)
struct FVector                                     Max                                                       // 0x000C(0x000C)
unsigned char                                      IsValid                                                   // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.Box2D
// 0x0014
struct FBox2D
{
struct FVector2D                                   Min                                                       // 0x0000(0x0008)
struct FVector2D                                   Max                                                       // 0x0008(0x0008)
unsigned char                                      bIsValid                                                  // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.BoxSphereBounds
// 0x001C
struct FBoxSphereBounds
{
struct FVector                                     Origin                                                    // 0x0000(0x000C)
struct FVector                                     BoxExtent                                                 // 0x000C(0x000C)
float                                              SphereRadius                                              // 0x0018(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.OrientedBox
// 0x003C
struct FOrientedBox
{
struct FVector                                     Center                                                    // 0x0000(0x000C)
struct FVector                                     AxisX                                                     // 0x000C(0x000C)
struct FVector                                     AxisY                                                     // 0x0018(0x000C)
struct FVector                                     AxisZ                                                     // 0x0024(0x000C)
float                                              ExtentX                                                   // 0x0030(0x0004)
float                                              ExtentY                                                   // 0x0034(0x0004)
float                                              ExtentZ                                                   // 0x0038(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.Matrix
// 0x0040
struct FMatrix
{
struct FPlane                                      XPlane                                                    // 0x0000(0x0010)
struct FPlane                                      YPlane                                                    // 0x0010(0x0010)
struct FPlane                                      ZPlane                                                    // 0x0020(0x0010)
struct FPlane                                      WPlane                                                    // 0x0030(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.InterpCurvePointFloat
// 0x0014
struct FInterpCurvePointFloat
{
float                                              InVal                                                     // 0x0000(0x0004)
float                                              OutVal                                                    // 0x0004(0x0004)
float                                              ArriveTangent                                             // 0x0008(0x0004)
float                                              LeaveTangent                                              // 0x000C(0x0004)
unsigned char                                      InterpMode                                                // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.InterpCurveFloat
// 0x0018
struct FInterpCurveFloat
{
TArray<struct FInterpCurvePointFloat>              Points                                                    // 0x0000(0x0010)
Bool                                               bIsLooped                                                 // 0x0010(0x0001)
float                                              LoopKeyOffset                                             // 0x0014(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.InterpCurvePointVector2D
// 0x0020
struct FInterpCurvePointVector2D
{
float                                              InVal                                                     // 0x0000(0x0004)
struct FVector2D                                   OutVal                                                    // 0x0004(0x0008)
struct FVector2D                                   ArriveTangent                                             // 0x000C(0x0008)
struct FVector2D                                   LeaveTangent                                              // 0x0014(0x0008)
unsigned char                                      InterpMode                                                // 0x001C(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.InterpCurveVector2D
// 0x0018
struct FInterpCurveVector2D
{
TArray<struct FInterpCurvePointVector2D>           Points                                                    // 0x0000(0x0010)
Bool                                               bIsLooped                                                 // 0x0010(0x0001)
float                                              LoopKeyOffset                                             // 0x0014(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.InterpCurvePointVector
// 0x002C
struct FInterpCurvePointVector
{
float                                              InVal                                                     // 0x0000(0x0004)
struct FVector                                     OutVal                                                    // 0x0004(0x000C)
struct FVector                                     ArriveTangent                                             // 0x0010(0x000C)
struct FVector                                     LeaveTangent                                              // 0x001C(0x000C)
unsigned char                                      InterpMode                                                // 0x0028(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.InterpCurveVector
// 0x0018
struct FInterpCurveVector
{
TArray<struct FInterpCurvePointVector>             Points                                                    // 0x0000(0x0010)
Bool                                               bIsLooped                                                 // 0x0010(0x0001)
float                                              LoopKeyOffset                                             // 0x0014(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.InterpCurvePointQuat
// 0x0050
struct FInterpCurvePointQuat
{
float                                              InVal                                                     // 0x0000(0x0004)
struct FQuat                                       OutVal                                                    // 0x0010(0x0010)
struct FQuat                                       ArriveTangent                                             // 0x0020(0x0010)
struct FQuat                                       LeaveTangent                                              // 0x0030(0x0010)
unsigned char                                      InterpMode                                                // 0x0040(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.InterpCurveQuat
// 0x0018
struct FInterpCurveQuat
{
TArray<struct FInterpCurvePointQuat>               Points                                                    // 0x0000(0x0010)
Bool                                               bIsLooped                                                 // 0x0010(0x0001)
float                                              LoopKeyOffset                                             // 0x0014(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.InterpCurvePointTwoVectors
// 0x0050
struct FInterpCurvePointTwoVectors
{
float                                              InVal                                                     // 0x0000(0x0004)
struct FTwoVectors                                 OutVal                                                    // 0x0004(0x0018)
struct FTwoVectors                                 ArriveTangent                                             // 0x001C(0x0018)
struct FTwoVectors                                 LeaveTangent                                              // 0x0034(0x0018)
unsigned char                                      InterpMode                                                // 0x004C(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.InterpCurveTwoVectors
// 0x0018
struct FInterpCurveTwoVectors
{
TArray<struct FInterpCurvePointTwoVectors>         Points                                                    // 0x0000(0x0010)
Bool                                               bIsLooped                                                 // 0x0010(0x0001)
float                                              LoopKeyOffset                                             // 0x0014(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.InterpCurvePointLinearColor
// 0x0038
struct FInterpCurvePointLinearColor
{
float                                              InVal                                                     // 0x0000(0x0004)
struct FLinearColor                                OutVal                                                    // 0x0004(0x0010)
struct FLinearColor                                ArriveTangent                                             // 0x0014(0x0010)
struct FLinearColor                                LeaveTangent                                              // 0x0024(0x0010)
unsigned char                                      InterpMode                                                // 0x0034(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.InterpCurveLinearColor
// 0x0018
struct FInterpCurveLinearColor
{
TArray<struct FInterpCurvePointLinearColor>        Points                                                    // 0x0000(0x0010)
Bool                                               bIsLooped                                                 // 0x0010(0x0001)
float                                              LoopKeyOffset                                             // 0x0014(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.Transform
// 0x0030
struct FTransform
{
struct FQuat                                       Rotation                                                  // 0x0000(0x0010)
struct FVector                                     Translation                                               // 0x0010(0x000C)
struct FVector                                     Scale3D                                                   // 0x0020(0x000C)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.RandomStream
// 0x0008
struct FRandomStream
{
int                                                InitialSeed                                               // 0x0000(0x0004)
int                                                Seed                                                      // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.SoftObjectPath
// 0x0018
struct FSoftObjectPath
{
struct FName                                       AssetPathName                                             // 0x0000(0x0008)
struct FString                                     SubPathString                                             // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.PrimaryAssetType
// 0x0008
struct FPrimaryAssetType
{
struct FName                                       Name                                                      // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.PrimaryAssetId
// 0x0010
struct FPrimaryAssetId
{
struct FPrimaryAssetType                           PrimaryAssetType                                          // 0x0000(0x0008)
struct FName                                       PrimaryAssetName                                          // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.FloatRangeBound
// 0x0008
struct FFloatRangeBound
{
unsigned char                                      Type                                                      // 0x0000(0x0001)
float                                              Value                                                     // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.FloatRange
// 0x0010
struct FFloatRange
{
struct FFloatRangeBound                            LowerBound                                                // 0x0000(0x0008)
struct FFloatRangeBound                            UpperBound                                                // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.Int32RangeBound
// 0x0008
struct FInt32RangeBound
{
unsigned char                                      Type                                                      // 0x0000(0x0001)
int                                                Value                                                     // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.Int32Range
// 0x0010
struct FInt32Range
{
struct FInt32RangeBound                            LowerBound                                                // 0x0000(0x0008)
struct FInt32RangeBound                            UpperBound                                                // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.FloatInterval
// 0x0008
struct FFloatInterval
{
float                                              Min                                                       // 0x0000(0x0004)
float                                              Max                                                       // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.Int32Interval
// 0x0008
struct FInt32Interval
{
int                                                Min                                                       // 0x0000(0x0004)
int                                                Max                                                       // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct CoreUObject.AutomationEvent
// 0x0048
struct FAutomationEvent
{
EAutomationEventType                               Type                                                      // 0x0000(0x0001)
struct FString                                     Message                                                   // 0x0008(0x0010)
struct FString                                     Context                                                   // 0x0018(0x0010)
struct FString                                     Filename                                                  // 0x0028(0x0010)
int                                                LineNumber                                                // 0x0038(0x0004)
struct FDateTime                                   TimeStamp                                                 // 0x0040(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.ExpressionInput
// 0x0038
struct FExpressionInput
{
int                                                OutputIndex                                               // 0x0000(0x0004)
struct FString                                     InputName                                                 // 0x0008(0x0010)
int                                                Mask                                                      // 0x0018(0x0004)
int                                                MaskR                                                     // 0x001C(0x0004)
int                                                MaskG                                                     // 0x0020(0x0004)
int                                                MaskB                                                     // 0x0024(0x0004)
int                                                MaskA                                                     // 0x0028(0x0004)
struct FName                                       ExpressionName                                            // 0x0030(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.MaterialAttributesInput
// 0x0008 (0x0040 - 0x0038)
struct FMaterialAttributesInput : public FExpressionInput
{
int                                                PropertyConnectedBitmask                                  // 0x0038(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.ExpressionOutput
// 0x0028
struct FExpressionOutput
{
struct FString                                     OutputName                                                // 0x0000(0x0010)
int                                                Mask                                                      // 0x0010(0x0004)
int                                                MaskR                                                     // 0x0014(0x0004)
int                                                MaskG                                                     // 0x0018(0x0004)
int                                                MaskB                                                     // 0x001C(0x0004)
int                                                MaskA                                                     // 0x0020(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.MaterialInput
// 0x0038
struct FMaterialInput
{
int                                                OutputIndex                                               // 0x0000(0x0004)
struct FString                                     InputName                                                 // 0x0008(0x0010)
int                                                Mask                                                      // 0x0018(0x0004)
int                                                MaskR                                                     // 0x001C(0x0004)
int                                                MaskG                                                     // 0x0020(0x0004)
int                                                MaskB                                                     // 0x0024(0x0004)
int                                                MaskA                                                     // 0x0028(0x0004)
struct FName                                       ExpressionName                                            // 0x0030(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.ColorMaterialInput
// 0x0008 (0x0040 - 0x0038)
struct FColorMaterialInput : public FMaterialInput
{
Bool                                               UseConstant                                               // 0x0038(0x0001)
struct FColor                                      Constant                                                  // 0x003C(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.ScalarMaterialInput
// 0x0008 (0x0040 - 0x0038)
struct FScalarMaterialInput : public FMaterialInput
{
Bool                                               UseConstant                                               // 0x0038(0x0001)
float                                              Constant                                                  // 0x003C(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.VectorMaterialInput
// 0x0010 (0x0048 - 0x0038)
struct FVectorMaterialInput : public FMaterialInput
{
Bool                                               UseConstant                                               // 0x0038(0x0001)
struct FVector                                     Constant                                                  // 0x003C(0x000C)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.Vector4MaterialInput
// 0x0018 (0x0050 - 0x0038)
struct FVector4MaterialInput : public FMaterialInput
{
Bool                                               UseConstant                                               // 0x0038(0x0001)
struct FVector4                                    Constant                                                  // 0x0040(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.Vector2MaterialInput
// 0x0010 (0x0048 - 0x0038)
struct FVector2MaterialInput : public FMaterialInput
{
Bool                                               UseConstant                                               // 0x0038(0x0001)
float                                              ConstantX                                                 // 0x003C(0x0004)
float                                              ConstantY                                                 // 0x0040(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.DistributionLookupTable
// 0x0028
struct FDistributionLookupTable
{
unsigned char                                      Op                                                        // 0x0000(0x0001)
unsigned char                                      EntryCount                                                // 0x0001(0x0001)
unsigned char                                      EntryStride                                               // 0x0002(0x0001)
unsigned char                                      SubEntryStride                                            // 0x0003(0x0001)
float                                              TimeScale                                                 // 0x0004(0x0004)
float                                              TimeBias                                                  // 0x0008(0x0004)
TArray<float>                                      Values                                                    // 0x0010(0x0010)
unsigned char                                      LockFlag                                                  // 0x0020(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.RawDistribution
// 0x0028
struct FRawDistribution
{
struct FDistributionLookupTable                    Table                                                     // 0x0000(0x0028)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.FloatDistribution
// 0x0028
struct FFloatDistribution
{
struct FDistributionLookupTable                    Table                                                     // 0x0000(0x0028)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.VectorDistribution
// 0x0028
struct FVectorDistribution
{
struct FDistributionLookupTable                    Table                                                     // 0x0000(0x0028)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.Vector4Distribution
// 0x0028
struct FVector4Distribution
{
struct FDistributionLookupTable                    Table                                                     // 0x0000(0x0028)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.FloatRK4SpringInterpolator
// 0x0008
struct FFloatRK4SpringInterpolator
{
float                                              StiffnessConstant                                         // 0x0000(0x0004)
float                                              DampeningRatio                                            // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.VectorRK4SpringInterpolator
// 0x0008
struct FVectorRK4SpringInterpolator
{
float                                              StiffnessConstant                                         // 0x0000(0x0004)
float                                              DampeningRatio                                            // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.FormatArgumentData
// 0x0040
struct FFormatArgumentData
{
struct FString                                     ArgumentName                                              // 0x0000(0x0010)
unsigned char                                      ArgumentValueType                                         // 0x0010(0x0001)
struct FText                                       ArgumentValue                                             // 0x0018(0x0018)
int                                                ArgumentValueInt                                          // 0x0030(0x0004)
float                                              ArgumentValueFloat                                        // 0x0034(0x0004)
ETextGender                                        ArgumentValueGender                                       // 0x0038(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.HitResult
// 0x0088
struct FHitResult
{
Bool                                               bBlockingHit                                              // 0x0000(0x0001)
Bool                                               bStartPenetrating                                         // 0x0000(0x0001)
float                                              Time                                                      // 0x0004(0x0004)
float                                              Distance                                                  // 0x0008(0x0004)
struct FVector_NetQuantize                         Location                                                  // 0x000C(0x000C)
struct FVector_NetQuantize                         ImpactPoint                                               // 0x0018(0x000C)
struct FVector_NetQuantizeNormal                   Normal                                                    // 0x0024(0x000C)
struct FVector_NetQuantizeNormal                   ImpactNormal                                              // 0x0030(0x000C)
struct FVector_NetQuantize                         TraceStart                                                // 0x003C(0x000C)
struct FVector_NetQuantize                         TraceEnd                                                  // 0x0048(0x000C)
float                                              PenetrationDepth                                          // 0x0054(0x0004)
int                                                Item                                                      // 0x0058(0x0004)
TWeakObjectPtr<class UPhysicalMaterial>            PhysMaterial                                              // 0x005C(0x0008)
TWeakObjectPtr<class AActor>                       Actor                                                     // 0x0064(0x0008)
TWeakObjectPtr<class UPrimitiveComponent>          Component                                                 // 0x006C(0x0008)
struct FName                                       BoneName                                                  // 0x0078(0x0008)
int                                                FaceIndex                                                 // 0x0080(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct InputCore.Key
// 0x0018
struct FKey
{
struct FName                                       KeyName                                                   // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.ScriptNetworkRemoteContent
// 0x0018
struct FScriptNetworkRemoteContent
{
TArray<unsigned char>                              Content                                                   // 0x0000(0x0010)
int                                                ContentNumBits                                            // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.SimpleMemberReference
// 0x0020
struct FSimpleMemberReference
{
class UObject*                                     MemberParent                                              // 0x0000(0x0008)
struct FName                                       MemberName                                                // 0x0008(0x0008)
struct FGuid                                       MemberGuid                                                // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.TickFunction
// 0x0058
struct FTickFunction
{
unsigned char                                      TickGroup                                                 // 0x0008(0x0001)
unsigned char                                      EndTickGroup                                              // 0x0009(0x0001)
Bool                                               bTickEvenWhenPaused                                       // 0x0014(0x0001)
Bool                                               bCanEverTick                                              // 0x0014(0x0001)
Bool                                               bStartWithTickEnabled                                     // 0x0014(0x0001)
Bool                                               bAllowTickOnDedicatedServer                               // 0x0014(0x0001)
Bool                                               bPureLogicTick                                            // 0x0014(0x0001)
float                                              TickInterval                                              // 0x0048(0x0004)
float                                              TickIntervalStartTime                                     // 0x004C(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.WalkableSlopeOverride
// 0x0010
struct FWalkableSlopeOverride
{
unsigned char                                      WalkableSlopeBehavior                                     // 0x0000(0x0001)
float                                              WalkableSlopeAngle                                        // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.BodyInstance
// 0x01E0
struct FBodyInstance
{
ESleepFamily                                       SleepFamily                                               // 0x0021(0x0001)
unsigned char                                      DOFMode                                                   // 0x0022(0x0001)
unsigned char                                      CollisionEnabled                                          // 0x0023(0x0001)
struct FName                                       CollisionProfileName                                      // 0x0028(0x0008)
struct FCollisionResponse                          CollisionResponses                                        // 0x0030(0x0038)
Bool                                               bUseCCD                                                   // 0x0069(0x0001)
Bool                                               bNotifyRigidBodyCollision                                 // 0x0069(0x0001)
Bool                                               bUseShapeCollisionOverride                                // 0x0069(0x0001)
Bool                                               bSimulatePhysics                                          // 0x0069(0x0001)
Bool                                               bOverrideMass                                             // 0x0069(0x0001)
Bool                                               bEnableGravity                                            // 0x0069(0x0001)
Bool                                               bAutoWeld                                                 // 0x0069(0x0001)
Bool                                               bStartAwake                                               // 0x0069(0x0001)
Bool                                               bGenerateWakeEvents                                       // 0x006A(0x0001)
Bool                                               bUpdateMassWhenScaleChanges                               // 0x006A(0x0001)
Bool                                               bLockTranslation                                          // 0x006A(0x0001)
Bool                                               bLockRotation                                             // 0x006A(0x0001)
Bool                                               bLockXTranslation                                         // 0x006A(0x0001)
Bool                                               bLockYTranslation                                         // 0x006A(0x0001)
Bool                                               bLockZTranslation                                         // 0x006A(0x0001)
Bool                                               bLockXRotation                                            // 0x006A(0x0001)
Bool                                               bLockYRotation                                            // 0x006B(0x0001)
Bool                                               bLockZRotation                                            // 0x006B(0x0001)
Bool                                               bOverrideMaxAngularVelocity                               // 0x006B(0x0001)
Bool                                               bUseAsyncScene                                            // 0x006B(0x0001)
Bool                                               bOverrideMaxDepenetrationVelocity                         // 0x006B(0x0001)
Bool                                               bOverrideWalkableSlopeOnInstance                          // 0x006B(0x0001)
float                                              MaxDepenetrationVelocity                                  // 0x006C(0x0004)
float                                              MassInKgOverride                                          // 0x0078(0x0004)
float                                              LinearDamping                                             // 0x007C(0x0004)
float                                              AngularDamping                                            // 0x0080(0x0004)
struct FVector                                     CustomDOFPlaneNormal                                      // 0x0084(0x000C)
struct FVector                                     COMNudge                                                  // 0x0090(0x000C)
Bool                                               bUseOverrideCOM                                           // 0x009C(0x0001)
struct FVector                                     OverrideCOM                                               // 0x00A0(0x000C)
float                                              MassScale                                                 // 0x00AC(0x0004)
struct FVector                                     InertiaTensorScale                                        // 0x00B0(0x000C)
Bool                                               bUsedPhysSimpleStaticMesh                                 // 0x00BC(0x0001)
unsigned char                                      ObjectType                                                // 0x00BD(0x0001)
struct FWalkableSlopeOverride                      WalkableSlopeOverride                                     // 0x00D0(0x0010)
class UPhysicalMaterial*                           PhysMaterialOverride                                      // 0x00E0(0x0008)
float                                              MaxAngularVelocity                                        // 0x00E8(0x0004)
float                                              CustomSleepThresholdMultiplier                            // 0x00EC(0x0004)
float                                              StabilizationThresholdMultiplier                          // 0x00F0(0x0004)
float                                              PhysicsBlendWeight                                        // 0x00F4(0x0004)
int                                                PositionSolverIterationCount                              // 0x00F8(0x0004)
int                                                VelocitySolverIterationCount                              // 0x0148(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.CollisionResponse
// 0x0038
struct FCollisionResponse
{
struct FCollisionResponseContainer                 ResponseToChannels                                        // 0x0001(0x0020)
TArray<struct FResponseChannel>                    ResponseArray                                             // 0x0028(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.ResponseChannel
// 0x0010
struct FResponseChannel
{
struct FName                                       Channel                                                   // 0x0000(0x0008)
unsigned char                                      Response                                                  // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.CollisionResponseContainer
// 0x0020
struct FCollisionResponseContainer
{
unsigned char                                      WorldStatic                                               // 0x0000(0x0001)
unsigned char                                      WorldDynamic                                              // 0x0001(0x0001)
unsigned char                                      Pawn                                                      // 0x0002(0x0001)
unsigned char                                      Visibility                                                // 0x0003(0x0001)
unsigned char                                      Camera                                                    // 0x0004(0x0001)
unsigned char                                      PhysicsBody                                               // 0x0005(0x0001)
unsigned char                                      Vehicle                                                   // 0x0006(0x0001)
unsigned char                                      Destructible                                              // 0x0007(0x0001)
unsigned char                                      EngineTraceChannel1                                       // 0x0008(0x0001)
unsigned char                                      EngineTraceChannel2                                       // 0x0009(0x0001)
unsigned char                                      EngineTraceChannel3                                       // 0x000A(0x0001)
unsigned char                                      EngineTraceChannel4                                       // 0x000B(0x0001)
unsigned char                                      EngineTraceChannel5                                       // 0x000C(0x0001)
unsigned char                                      EngineTraceChannel6                                       // 0x000D(0x0001)
unsigned char                                      GameTraceChannel1                                         // 0x000E(0x0001)
unsigned char                                      GameTraceChannel2                                         // 0x000F(0x0001)
unsigned char                                      GameTraceChannel3                                         // 0x0010(0x0001)
unsigned char                                      GameTraceChannel4                                         // 0x0011(0x0001)
unsigned char                                      GameTraceChannel5                                         // 0x0012(0x0001)
unsigned char                                      GameTraceChannel6                                         // 0x0013(0x0001)
unsigned char                                      GameTraceChannel7                                         // 0x0014(0x0001)
unsigned char                                      GameTraceChannel8                                         // 0x0015(0x0001)
unsigned char                                      GameTraceChannel9                                         // 0x0016(0x0001)
unsigned char                                      GameTraceChannel10                                        // 0x0017(0x0001)
unsigned char                                      GameTraceChannel11                                        // 0x0018(0x0001)
unsigned char                                      GameTraceChannel12                                        // 0x0019(0x0001)
unsigned char                                      GameTraceChannel13                                        // 0x001A(0x0001)
unsigned char                                      GameTraceChannel14                                        // 0x001B(0x0001)
unsigned char                                      GameTraceChannel15                                        // 0x001C(0x0001)
unsigned char                                      GameTraceChannel16                                        // 0x001D(0x0001)
unsigned char                                      GameTraceChannel17                                        // 0x001E(0x0001)
unsigned char                                      GameTraceChannel18                                        // 0x001F(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.LightingChannels
// 0x0001
struct FLightingChannels
{
Bool                                               bChannel0                                                 // 0x0000(0x0001)
Bool                                               bChannel1                                                 // 0x0000(0x0001)
Bool                                               bChannel2                                                 // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.ExpectedQuality
// 0x0005
struct FExpectedQuality
{
EEQCompareOp                                       CompareOp                                                 // 0x0000(0x0001)
ERenderQualityEngine                               ExpectedRenderQuality                                     // 0x0001(0x0001)
unsigned char                                      ExpectedDeviceQuality                                     // 0x0002(0x0001)
Bool                                               bUseRenderQualityControl                                  // 0x0003(0x0001)
Bool                                               bUseDeviceQualityControl                                  // 0x0003(0x0001)
Bool                                               bRequireAllConditionMeet                                  // 0x0003(0x0001)
ERenderQualityEngine_PC                            PCExpectedRenderQuality                                   // 0x0004(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.SkelMeshSkinWeightInfo
// 0x0028
struct FSkelMeshSkinWeightInfo
{
int                                                Bones                                                     // 0x0000(0x0004)
unsigned char                                      Weights                                                   // 0x0020(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.SkinWeightInfoForFPP
// 0x0018
struct FSkinWeightInfoForFPP
{
struct FName                                       SourceBoneName                                            // 0x0000(0x0008)
struct FName                                       TargetBoneName                                            // 0x0008(0x0008)
int                                                WeightScale                                               // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.AnimUpdateRateParameters
// 0x00A8
struct FAnimUpdateRateParameters
{
int                                                UpdateRate                                                // 0x0004(0x0004)
int                                                EvaluationRate                                            // 0x0008(0x0004)
Bool                                               bInterpolateSkippedFrames                                 // 0x000C(0x0001)
Bool                                               bShouldUseLodMap                                          // 0x000C(0x0001)
Bool                                               bShouldUseMinLod                                          // 0x000C(0x0001)
Bool                                               bSkipUpdate                                               // 0x000C(0x0001)
Bool                                               bSkipEvaluation                                           // 0x000C(0x0001)
float                                              TickedPoseOffestTime                                      // 0x0010(0x0004)
float                                              AdditionalTime                                            // 0x0014(0x0004)
int                                                BaseNonRenderedUpdateRate                                 // 0x001C(0x0004)
int                                                BaseNonRenderedUpdateRateHigh                             // 0x0020(0x0004)
float                                              MaxDistFromMainChar                                       // 0x0024(0x0004)
TArray<float>                                      BaseVisibleDistanceFactorThesholds                        // 0x0028(0x0010)
int                                                BaseVisibleDistanceFactorSkipNum                          // 0x0038(0x0004)
int                                                MinEvaluationRate                                         // 0x003C(0x0004)
int                                                LockAnimUpdateRate                                        // 0x0040(0x0004)
Bool                                               EnableUROInterpolation                                    // 0x0044(0x0001)
TMap<int, int>                                     LODToFrameSkipMap                                         // 0x0048(0x0050)
int                                                MaxEvalRateForInterpolation                               // 0x0098(0x0004)
EUpdateRateShiftBucket                             ShiftBucket                                               // 0x009C(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.SkelMeshComponentLODInfo
// 0x0098
struct FSkelMeshComponentLODInfo
{
TArray<Bool>                                       HiddenMaterials                                           // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.SubtitleCue
// 0x0020
struct FSubtitleCue
{
struct FText                                       Text                                                      // 0x0000(0x0018)
float                                              Time                                                      // 0x0018(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.InterpControlPoint
// 0x001C
struct FInterpControlPoint
{
struct FVector                                     PositionControlPoint                                      // 0x0000(0x000C)
Bool                                               bPositionIsRelative                                       // 0x000C(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.PlatformInterfaceDelegateResult
// 0x0038
struct FPlatformInterfaceDelegateResult
{
Bool                                               bSuccessful                                               // 0x0000(0x0001)
struct FPlatformInterfaceData                      Data                                                      // 0x0008(0x0030)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.PlatformInterfaceData
// 0x0030
struct FPlatformInterfaceData
{
struct FName                                       DataName                                                  // 0x0000(0x0008)
unsigned char                                      Type                                                      // 0x0008(0x0001)
int                                                IntValue                                                  // 0x000C(0x0004)
float                                              FloatValue                                                // 0x0010(0x0004)
struct FString                                     StringValue                                               // 0x0018(0x0010)
class UObject*                                     ObjectValue                                               // 0x0028(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.RepAttachment
// 0x0050
struct FRepAttachment
{
class AActor*                                      AttachParent                                              // 0x0000(0x0008)
struct FVector_NetQuantize100                      LocationOffset                                            // 0x0008(0x000C)
struct FVector_NetQuantize100                      RelativeScale3D                                           // 0x0014(0x000C)
struct FRotator                                    RotationOffset                                            // 0x0020(0x000C)
struct FName                                       AttachSocket                                              // 0x0030(0x0008)
class USceneComponent*                             AttachComponent                                           // 0x0038(0x0008)
class AActor*                                      AttachParent_Direct                                       // 0x0040(0x0008)
Bool                                               bHasValidParent                                           // 0x0048(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.RepMovement
// 0x0034
struct FRepMovement
{
struct FVector                                     LinearVelocity                                            // 0x0000(0x000C)
struct FVector                                     AngularVelocity                                           // 0x000C(0x000C)
struct FVector                                     Location                                                  // 0x0018(0x000C)
struct FRotator                                    Rotation                                                  // 0x0024(0x000C)
Bool                                               bSimulatedPhysicSleep                                     // 0x0030(0x0001)
Bool                                               bRepPhysics                                               // 0x0030(0x0001)
Bool                                               bPredictionLocation                                       // 0x0030(0x0001)
EVectorQuantization                                LocationQuantizationLevel                                 // 0x0031(0x0001)
EVectorQuantization                                VelocityQuantizationLevel                                 // 0x0032(0x0001)
ERotatorQuantization                               RotationQuantizationLevel                                 // 0x0033(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.DebugFloatHistory
// 0x0020
struct FDebugFloatHistory
{
TArray<float>                                      Samples                                                   // 0x0000(0x0010)
float                                              MaxSamples                                                // 0x0010(0x0004)
float                                              MinValue                                                  // 0x0014(0x0004)
float                                              MaxValue                                                  // 0x0018(0x0004)
Bool                                               bAutoAdjustMinMax                                         // 0x001C(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.LatentActionInfo
// 0x0018
struct FLatentActionInfo
{
int                                                Linkage                                                   // 0x0000(0x0004)
int                                                UUID                                                      // 0x0004(0x0004)
struct FName                                       ExecutionFunction                                         // 0x0008(0x0008)
class UObject*                                     CallbackTarget                                            // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.TimerHandle
// 0x0008
struct FTimerHandle
{
uint64_t                                           Handle                                                    // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.CollisionProfileName
// 0x0008
struct FCollisionProfileName
{
struct FName                                       Name                                                      // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.GenericStruct
// 0x0004
struct FGenericStruct
{
int                                                Data                                                      // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.UserActivity
// 0x0018
struct FUserActivity
{
struct FString                                     ActionName                                                // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.DPProfileMatch
// 0x0020
struct FDPProfileMatch
{
struct FString                                     Profile                                                   // 0x0000(0x0010)
TArray<struct FDPProfileMatchItem>                 Match                                                     // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.DPProfileMatchItem
// 0x0018
struct FDPProfileMatchItem
{
unsigned char                                      SourceType                                                // 0x0000(0x0001)
unsigned char                                      CompareType                                               // 0x0001(0x0001)
struct FString                                     MatchString                                               // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.DamageInfoCollection
// 0x00B0
struct FDamageInfoCollection
{
class UClass*                                      DamageTypeClass                                           // 0x0000(0x0008)
int                                                DamageType                                                // 0x0008(0x0004)
int                                                CauserItemID                                              // 0x000C(0x0004)
float                                              Damage                                                    // 0x0010(0x0004)
struct FHitResult                                  Hit                                                       // 0x0018(0x0088)
class AActor*                                      DamageCauser                                              // 0x00A0(0x0008)
class AController*                                 Instigator                                                // 0x00A8(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct GameplayTags.GameplayTag
// 0x0010
struct FGameplayTag
{
struct FName                                       TagName                                                   // 0x0000(0x0008)
Bool                                               bUseSlowReplication                                       // 0x0008(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.ItemSpecialData_BloodDiamondData
// 0x0018
struct FItemSpecialData_BloodDiamondData
{
int                                                Inlay_times                                               // 0x0000(0x0004)
int                                                ItemID                                                    // 0x0004(0x0004)
TArray<struct FItemSpecialData_BloodDiamondPosData> PosDataArray                                              // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.ItemSpecialData_BloodDiamondPosData
// 0x0008
struct FItemSpecialData_BloodDiamondPosData
{
int                                                Position                                                  // 0x0000(0x0004)
int                                                ColorID                                                   // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.ItemSpecialData_EscapeMechaItemData
// 0x0020
struct FItemSpecialData_EscapeMechaItemData
{
int                                                ItemID                                                    // 0x0000(0x0004)
int                                                Grade                                                     // 0x0004(0x0004)
int                                                Wearout                                                   // 0x0008(0x0004)
TArray<struct FItemSpecialData_EscapeMechaItemColorData> Colors                                                    // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.ItemSpecialData_EscapeMechaItemColorData
// 0x0008
struct FItemSpecialData_EscapeMechaItemColorData
{
int                                                ColorNameID                                               // 0x0000(0x0004)
int                                                ColorID                                                   // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.ItemSpecialData_EscapeMechaData
// 0x0010
struct FItemSpecialData_EscapeMechaData
{
TArray<struct FItemSpecialData_EscapeMechaItemData> MechaDataItemList                                         // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.AttrModifyItemSimple
// 0x0038
struct FAttrModifyItemSimple
{
struct FGameAttributeContainer                     GameAttribute                                             // 0x0000(0x0028)
EAttrOperator                                      ModifierOp                                                // 0x0028(0x0001)
float                                              ModifierValue                                             // 0x002C(0x0004)
Bool                                               bRepAttrModify                                            // 0x0030(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct GameAttributeExtend.GameAttributeContainer
// 0x0028
struct FGameAttributeContainer
{
struct FString                                     AttributeName                                             // 0x0000(0x0010)
struct FString                                     DefinitionText                                            // 0x0010(0x0010)
struct FName                                       NameCache                                                 // 0x0020(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct GameAttributeExtend.GameMagnitudeContext
// 0x0068
struct FGameMagnitudeContext
{
class UObject*                                     SourceObject                                              // 0x0000(0x0008)
class AController*                                 Instigator                                                // 0x0008(0x0008)
class AActor*                                      Causer                                                    // 0x0010(0x0008)
class AActor*                                      TargetActor                                               // 0x0018(0x0008)
float                                              SrcMagnitude                                              // 0x0020(0x0004)
unsigned char                                      RestrictedDamageType                                      // 0x0024(0x0001)
TArray<struct FName>                               DamageTypeTags                                            // 0x0028(0x0010)
struct FAdditionalDamageCalculationData            AdditionalDamageData                                      // 0x0038(0x0001)
TArray<struct FName>                               ResultTags                                                // 0x0040(0x0010)
Bool                                               IsFatal                                                   // 0x0050(0x0001)
TArray<struct FGameplayTag>                        RecoverTags                                               // 0x0058(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct GameAttributeExtend.AdditionalDamageCalculationData
// 0x0001
struct FAdditionalDamageCalculationData
{
unsigned char                                      DamagePositionType                                        // 0x0000(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.AttrModifyItem
// 0x00D0
struct FAttrModifyItem
{
TArray<struct FCacheAffactTargetInfo>              AffectTargetsCachInfo                                     // 0x0000(0x0010)
struct FName                                       OptionalAttrFName                                         // 0x0010(0x0008)
int                                                AttrModifyUniqueID                                        // 0x0018(0x0004)
struct FString                                     AttrModifyItemName                                        // 0x0020(0x0010)
struct FString                                     AttrName                                                  // 0x0030(0x0010)
Bool                                               bReplicated                                               // 0x0040(0x0001)
struct FString                                     ComponentClassName                                        // 0x0048(0x0010)
struct FName                                       ComponentTag                                              // 0x0058(0x0008)
EAttrOperator                                      ModifierOp                                                // 0x0060(0x0001)
Bool                                               bIsResource                                               // 0x0061(0x0001)
Bool                                               bIsBool                                                   // 0x0062(0x0001)
float                                              ModifierValue                                             // 0x0064(0x0004)
EAttrIntConvertType                                IntConvertType                                            // 0x0068(0x0001)
unsigned char                                      LifetimeCondition                                         // 0x0069(0x0001)
float                                              InMinValue                                                // 0x006C(0x0004)
float                                              InMaxValue                                                // 0x0070(0x0004)
struct FSoftObjectPath                             ModifierResValue                                          // 0x0078(0x0018)
Bool                                               ModifierBoolValue                                         // 0x0090(0x0001)
struct FAttrModifyItemResourceClientData           ModifierResValueClientModeOverride                        // 0x0098(0x0030)
Bool                                               ClientSimulate                                            // 0x00C8(0x0001)
Bool                                               IsEnable                                                  // 0x00C9(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.AttrModifyItemResourceClientData
// 0x0030
struct FAttrModifyItemResourceClientData
{
Bool                                               bUseClientOverride                                        // 0x0000(0x0001)
EAttrClientShowMode                                ClientShowMode                                            // 0x0001(0x0001)
struct FString                                     OwnerPlayerKey                                            // 0x0008(0x0010)
struct FSoftObjectPath                             ModifierResourcePath                                      // 0x0018(0x0018)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.CacheAffactTargetInfo
// 0x0030
struct FCacheAffactTargetInfo
{
TWeakObjectPtr<class AActor>                       AffectTarget                                              // 0x0000(0x0008)
Bool                                               bIsResource                                               // 0x0008(0x0001)
float                                              FinalAddValue                                             // 0x000C(0x0004)
struct FSoftObjectPath                             ResValue                                                  // 0x0010(0x0018)
Bool                                               bIsBool                                                   // 0x0028(0x0001)
Bool                                               bFinalBoolValue                                           // 0x0029(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.AttrModifyGroupItem
// 0x0010
struct FAttrModifyGroupItem
{
TArray<struct FAttrModifyItem>                     AttrModifyItem                                            // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.AttrAffected
// 0x0020
struct FAttrAffected
{
struct FString                                     AttrName                                                  // 0x0000(0x0010)
struct FName                                       PropertyName                                              // 0x0010(0x0008)
class AActor*                                      AffectedActor                                             // 0x0018(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.AttrRegisterItem
// 0x00B8
struct FAttrRegisterItem
{
struct FName                                       AttrName                                                  // 0x0000(0x0008)
struct FName                                       PropertyName                                              // 0x0008(0x0008)
EAttrVariableType                                  AttrVariableType                                          // 0x0010(0x0001)
Bool                                               HasReplicatedTag                                          // 0x0011(0x0001)
class UObject*                                     OriginalRes                                               // 0x0080(0x0008)
class UObject*                                     Owner                                                     // 0x0088(0x0008)
class UProperty*                                   CachedProperty                                            // 0x0090(0x0008)
class UProperty*                                   CachedRepProperty                                         // 0x0098(0x0008)
class UFunction*                                   NotifyFunction                                            // 0x00A0(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct GameAttributeExtend.GameAttributeValueConfig
// 0x0030
struct FGameAttributeValueConfig
{
struct FGameAttributeContainer                     GameAttribute                                             // 0x0000(0x0028)
float                                              InitialValue                                              // 0x0028(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct GameAttributeExtend.GameAttributeDefinition
// 0x0048
struct FGameAttributeDefinition
{
struct FString                                     AttributeName                                             // 0x0000(0x0010)
float                                              DefaultValue                                              // 0x0010(0x0004)
float                                              MinValue                                                  // 0x0014(0x0004)
float                                              MaxValue                                                  // 0x0018(0x0004)
struct FString                                     MaxAttributeName                                          // 0x0020(0x0010)
struct FString                                     Comment                                                   // 0x0030(0x0010)
EGameAttributeValueType                            ValueType                                                 // 0x0040(0x0001)
Bool                                               bEnableReplicate                                          // 0x0041(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.AttrMetaData
// 0x0030
struct FAttrMetaData
{
struct FString                                     AttrMin                                                   // 0x0000(0x0010)
struct FString                                     AttrMax                                                   // 0x0010(0x0010)
struct FString                                     AttrFunc                                                  // 0x0020(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.AttrModifyItem_ID
// 0x0018
struct FAttrModifyItem_ID
{
int                                                ModifyItemID                                              // 0x0000(0x0004)
TArray<struct FAttrModifyItem_ID_CacheAffactTargetInfo> AttrModifyItem_ID_CacheAffactTargetInfo                   // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.AttrModifyItem_ID_CacheAffactTargetInfo
// 0x0010
struct FAttrModifyItem_ID_CacheAffactTargetInfo
{
TArray<struct FCacheAffactTargetInfo>              AffactTargetInfo                                          // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.AttrKey
// 0x0010
struct FAttrKey
{
struct FName                                       AttrName                                                  // 0x0000(0x0008)
class UObject*                                     Owner                                                     // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.AttrModifyItemArray
// 0x0010
struct FAttrModifyItemArray
{
TArray<struct FAttrModifyItem>                     AttrModifyItemArray                                       // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.ItemAssociation
// 0x0030
struct FItemAssociation
{
struct FName                                       AssociationName                                           // 0x0000(0x0008)
struct FItemDefineID                               AssociationTargetDefineID                                 // 0x0008(0x0018)
class UItemHandleBase*                             AssociationTargetHandle                                   // 0x0020(0x0008)
Bool                                               bSkipParentAssociationUse                                 // 0x0028(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.ItemDefineID
// 0x0018
struct FItemDefineID
{
int                                                Type                                                      // 0x0000(0x0004)
int                                                TypeSpecificID                                            // 0x0004(0x0004)
Bool                                               bValidItem                                                // 0x0008(0x0001)
Bool                                               bValidInstance                                            // 0x0009(0x0001)
uint64_t                                           InstanceID                                                // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.PickUpGenerationDetail
// 0x0038
struct FPickUpGenerationDetail
{
EPickUpGenerationReason                            Reason                                                    // 0x0000(0x0001)
int64_t                                            TimeStamp                                                 // 0x0008(0x0008)
struct FName                                       InitiatorName                                             // 0x0010(0x0008)
struct FString                                     StackMessage                                              // 0x0018(0x0010)
struct FString                                     ExtraMessage                                              // 0x0028(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.BattleItemPickupInfo
// 0x0058
struct FBattleItemPickupInfo
{
class UObject*                                     Source                                                    // 0x0000(0x0008)
Bool                                               bSourceDropedByPlayer                                     // 0x0008(0x0001)
Bool                                               bNotAutoEquipAndUse                                       // 0x0009(0x0001)
int                                                Count                                                     // 0x000C(0x0004)
TArray<struct FBattleItemAdditionalData>           AdditionalData                                            // 0x0010(0x0010)
Bool                                               bAutoEquip                                                // 0x0020(0x0001)
struct FBattleItemUseTarget                        AutoEquipTarget                                           // 0x0028(0x0028)
Bool                                               bTriggerEvent                                             // 0x0050(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.BattleItemUseTarget
// 0x0028
struct FBattleItemUseTarget
{
struct FItemDefineID                               TargetDefineID                                            // 0x0000(0x0018)
struct FName                                       TargetAssociationName                                     // 0x0018(0x0008)
Bool                                               FilterTargetWhenPickup                                    // 0x0020(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.BattleItemAdditionalData
// 0x0030
struct FBattleItemAdditionalData
{
struct FName                                       Name                                                      // 0x0000(0x0008)
float                                              FloatData                                                 // 0x0008(0x0004)
struct FString                                     StringData                                                // 0x0010(0x0010)
int                                                IntData                                                   // 0x0020(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.EffectModifierDebugDisplayData
// 0x0038
struct FEffectModifierDebugDisplayData
{
struct FString                                     RelatedAssetPath                                          // 0x0000(0x0010)
int                                                IndexInRelatedAsset                                       // 0x0010(0x0004)
struct FString                                     RelatedAssetDescription                                   // 0x0018(0x0010)
struct FString                                     EffectModifierDescription                                 // 0x0028(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.SlotUpdate
// 0x0008
struct FSlotUpdate
{
struct FName                                       SlotSocketName                                            // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.SlotSocket
// 0x0008
struct FSlotSocket
{
struct FName                                       SlotSocketName                                            // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.ClientBaseInfo
// 0x0128
struct FClientBaseInfo
{
struct FString                                     OpenID                                                    // 0x0000(0x0010)
uint64_t                                           RoleID                                                    // 0x0010(0x0008)
struct FString                                     GameSvrId                                                 // 0x0018(0x0010)
struct FString                                     GameAppID                                                 // 0x0028(0x0010)
int8_t                                             AreaID                                                    // 0x0038(0x0001)
int8_t                                             PlatID                                                    // 0x0039(0x0001)
struct FString                                     ZoneID                                                    // 0x0040(0x0010)
uint64_t                                           BattleID                                                  // 0x0050(0x0008)
uint64_t                                           GameID                                                    // 0x0058(0x0008)
struct FString                                     BattleServerIP                                            // 0x0060(0x0010)
uint32_t                                           BattleServerPort                                          // 0x0070(0x0004)
struct FString                                     UserName                                                  // 0x0078(0x0010)
struct FString                                     PicUrl                                                    // 0x0088(0x0010)
uint32_t                                           PlayerKey                                                 // 0x0098(0x0004)
struct FString                                     PlayerName                                                // 0x00A0(0x0010)
int64_t                                            SubModeId                                                 // 0x00B0(0x0008)
struct FString                                     PacketKey                                                 // 0x00B8(0x0010)
struct FString                                     AuthKey                                                   // 0x00C8(0x0010)
int8_t                                             WeatherID                                                 // 0x00DC(0x0001)
struct FString                                     WeatherLevelName                                          // 0x00E0(0x0010)
int8_t                                             PCWeatherID                                               // 0x00F0(0x0001)
struct FString                                     PCWeatherLevelName                                        // 0x00F8(0x0010)
float                                              WeatherTime                                               // 0x0108(0x0004)
TArray<int>                                        MrpcsData                                                 // 0x0110(0x0010)
uint32_t                                           loginChannel                                              // 0x0124(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.DrawTextToTextureRenderTarget2DParams
// 0x0120
struct FDrawTextToTextureRenderTarget2DParams
{
struct FText                                       Text                                                      // 0x0000(0x0018)
struct FOtherParams                                OtherParams                                               // 0x0018(0x0098)
struct FName                                       WidgetName                                                // 0x00B0(0x0008)
int                                                DrawWidth                                                 // 0x00B8(0x0004)
int                                                DrawHeight                                                // 0x00BC(0x0004)
class UTextureRenderTarget2D*                      OptionalInOutTextureRenderTarget2D                        // 0x00C0(0x0008)
Bool                                               bMaterialInstanceDynamicCreated                           // 0x00C8(0x0001)
unsigned char                                      ParentMaterial                                            // 0x00D0(0x0028)
struct FName                                       TextureParameterName                                      // 0x00F8(0x0008)
class UMaterialInstanceDynamic*                    OptionalInOutMaterialInstanceDynamic                      // 0x0100(0x0008)
struct FString                                     Payload                                                   // 0x0108(0x0010)
Bool                                               bParamsCached                                             // 0x0118(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.OtherParams
// 0x0098
struct FOtherParams
{
struct FText                                       Text                                                      // 0x0000(0x0018)
struct FSlateColor                                 TextColor                                                 // 0x0018(0x0028)
struct FSlateFontInfo                              TextFontInfo                                              // 0x0040(0x0058)
};

// 大佬QQ:2396031563
// ScriptStruct SlateCore.SlateFontInfo
// 0x0058
struct FSlateFontInfo
{
class UObject*                                     FontObject                                                // 0x0000(0x0008)
class UObject*                                     FontMaterial                                              // 0x0008(0x0008)
struct FFontOutlineSettings                        OutlineSettings                                           // 0x0010(0x0028)
struct FName                                       TypefaceFontName                                          // 0x0048(0x0008)
int                                                Size                                                      // 0x0050(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct SlateCore.FontOutlineSettings
// 0x0028
struct FFontOutlineSettings
{
int                                                OutlineSize                                               // 0x0000(0x0004)
class UObject*                                     OutlineMaterial                                           // 0x0008(0x0008)
struct FLinearColor                                OutlineColor                                              // 0x0010(0x0010)
Bool                                               bSeparateFillAlpha                                        // 0x0020(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct SlateCore.SlateColor
// 0x0028
struct FSlateColor
{
struct FLinearColor                                SpecifiedColor                                            // 0x0000(0x0010)
unsigned char                                      ColorUseRule                                              // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.BuffInstancedItem
// 0x00B8
struct FBuffInstancedItem
{
struct FName                                       BuffName                                                  // 0x0000(0x0008)
int                                                BuffID                                                    // 0x0008(0x0004)
class USTBaseBuff*                                 Buff                                                      // 0x0010(0x0008)
int                                                LayerCount                                                // 0x0018(0x0004)
TWeakObjectPtr<class AController>                  CauserPawnController                                      // 0x001C(0x0008)
TWeakObjectPtr<class AActor>                       CauserActor                                               // 0x0024(0x0008)
Bool                                               PendingRemove                                             // 0x002C(0x0001)
float                                              Expiry                                                    // 0x0030(0x0004)
TWeakObjectPtr<class AActor>                       Target                                                    // 0x0034(0x0008)
TWeakObjectPtr<class AActor>                       BuffApplier                                               // 0x003C(0x0008)
int                                                BuffInstanceID                                            // 0x0044(0x0004)
unsigned char                                      AttachCounter                                             // 0x0048(0x0001)
class UUAEBlackboard*                              UAEBlackboard                                             // 0x00A8(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.UTBuffSyncData
// 0x0050
struct FUTBuffSyncData
{
struct FName                                       BuffName                                                  // 0x0000(0x0008)
int                                                BuffID                                                    // 0x0008(0x0004)
int                                                BuffInstanceID                                            // 0x000C(0x0004)
class AController*                                 BuffCauser                                                // 0x0010(0x0008)
int                                                LayerCount                                                // 0x0018(0x0004)
class AActor*                                      BuffApplierActor                                          // 0x0020(0x0008)
class AActor*                                      CauserActor                                               // 0x0028(0x0008)
float                                              RemainingTime                                             // 0x0030(0x0004)
float                                              ExpireTime                                                // 0x0034(0x0004)
unsigned char                                      AttachCounter                                             // 0x0038(0x0001)
struct FBlackBoardSyncDataArrayWrapper             BlackBoardSyncData                                        // 0x0040(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct UAESharedModule.BlackBoardSyncDataArrayWrapper
// 0x0010
struct FBlackBoardSyncDataArrayWrapper
{
TArray<struct FBlackBoardSyncData>                 Array                                                     // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct UAESharedModule.BlackBoardSyncData
// 0x0058
struct FBlackBoardSyncData
{
int                                                IntValue                                                  // 0x0000(0x0004)
float                                              FloatValue                                                // 0x0004(0x0004)
Bool                                               BoolValue                                                 // 0x0008(0x0001)
struct FName                                       NameValue                                                 // 0x0010(0x0008)
struct FString                                     StringValue                                               // 0x0018(0x0010)
struct FVector                                     VectorValue                                               // 0x0028(0x000C)
struct FRotator                                    RotatorValue                                              // 0x0034(0x000C)
class AActor*                                      ReplicatedActorPointer                                    // 0x0040(0x0008)
struct FName                                       Name                                                      // 0x0048(0x0008)
unsigned char                                      Type                                                      // 0x0050(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.ItemDataBaseStruct
// 0x0010
struct FItemDataBaseStruct
{
TArray<struct FAdditionProperty>                   AdditionProperties                                        // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.AdditionProperty
// 0x0010
struct FAdditionProperty
{
struct FName                                       PropertyName                                              // 0x0000(0x0008)
EAdditionPropertyType                              PropertyType                                              // 0x0008(0x0001)
float                                              FloatValue                                                // 0x000C(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.ItemData
// 0x0040 (0x0050 - 0x0010)
struct FItemData : public FItemDataBaseStruct
{
struct FItemDefineID                               DefineID                                                  // 0x0010(0x0018)
struct FString                                     Name                                                      // 0x0028(0x0010)
struct FString                                     Icon                                                      // 0x0038(0x0010)
class UItemHandleBase*                             ItemHandle                                                // 0x0048(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.BattleItemData
// 0x0050 (0x00A0 - 0x0050)
struct FBattleItemData : public FItemData
{
int                                                Count                                                     // 0x0050(0x0004)
Bool                                               bEquipping                                                // 0x0054(0x0001)
Bool                                               bCanBeClientHandle                                        // 0x0055(0x0001)
TArray<struct FBattleItemAdditionalData>           AdditionalData                                            // 0x0058(0x0010)
struct FBattleItemFeatureData                      FeatureData                                               // 0x0068(0x0018)
struct FBattleItemTimeLimitData                    TimeLimitData                                             // 0x0080(0x0008)
TArray<struct FItemAssociation>                    Associations                                              // 0x0088(0x0010)
int                                                ExpireTime                                                // 0x0098(0x0004)
unsigned char                                      IsNew                                                     // 0x009C(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.BattleItemTimeLimitData
// 0x0008
struct FBattleItemTimeLimitData
{
float                                              TimeStart                                                 // 0x0000(0x0004)
float                                              TimeEnd                                                   // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.BattleItemFeatureData
// 0x0018
struct FBattleItemFeatureData
{
float                                              UnitWeight                                                // 0x0000(0x0004)
int                                                MaxCount                                                  // 0x0004(0x0004)
Bool                                               bUnique                                                   // 0x0008(0x0001)
Bool                                               bStackable                                                // 0x0009(0x0001)
Bool                                               bEquippable                                               // 0x000A(0x0001)
Bool                                               bConsumable                                               // 0x000B(0x0001)
Bool                                               bAutoEquipAndDrop                                         // 0x000C(0x0001)
int                                                SortingPriority                                           // 0x0010(0x0004)
int                                                ItemType                                                  // 0x0014(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.BattleItemAssociationTarget
// 0x0030
struct FBattleItemAssociationTarget
{
struct FItemDefineID                               TargetDefineID                                            // 0x0000(0x0018)
struct FItemDefineID                               TargetAssociationDefineID                                 // 0x0018(0x0018)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.CommonBackpackInfo
// 0x0020
struct FCommonBackpackInfo
{
TScriptInterface<class UCommonBackpackInterface>   ClassicBackpackInterface                                  // 0x0000(0x0010)
TScriptInterface<class UCommonBackpackInterface>   CommonBackpackInterface                                   // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.BattleItemDropInfo
// 0x0010
struct FBattleItemDropInfo
{
TArray<struct FBattleItemAdditionalData>           AdditionalData                                            // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.ItemHandleAttrModifyConfig
// 0x0050
struct FItemHandleAttrModifyConfig
{
EItemGAActiveCondition                             AttrModifyActiveCondition                                 // 0x0000(0x0001)
struct FAttrModifyItemSimple                       AttrModifyItemSimple                                      // 0x0008(0x0038)
struct FString                                     AttrModifyItemUniqueID                                    // 0x0040(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.SkillV2Config
// 0x0038
struct FSkillV2Config
{
unsigned char                                      SkillTemplateClass                                        // 0x0000(0x0028)
EItemGAActiveCondition                             SkillActiveCondition                                      // 0x0028(0x0001)
float                                              OverrideApplyTime                                         // 0x002C(0x0004)
class UBasicPersistEffect*                         ItemSkillInstance                                         // 0x0030(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.SkillV1Config
// 0x0060
struct FSkillV1Config
{
unsigned char                                      SkillTemplateClass                                        // 0x0000(0x0028)
EItemGAActiveCondition                             SkillActiveCondition                                      // 0x0028(0x0001)
Bool                                               bDefaultActive                                            // 0x0029(0x0001)
Bool                                               bCoverSkill                                               // 0x002A(0x0001)
unsigned char                                      SkillCoveredTemplateClass                                 // 0x0030(0x0028)
Bool                                               bSkillAdded                                               // 0x0058(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.GenericAbilityKey
// 0x0018
struct FGenericAbilityKey
{
int                                                GAID                                                      // 0x0000(0x0004)
uint64_t                                           GAInstanceID                                              // 0x0008(0x0008)
float                                              RandomBaseValue                                           // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.BattleItemTimeLimitInfo
// 0x0014
struct FBattleItemTimeLimitInfo
{
ETimeLimitType                                     TimeLimitType                                             // 0x0000(0x0001)
float                                              TimeStart                                                 // 0x0004(0x0004)
float                                              TimeEnd                                                   // 0x0008(0x0004)
int                                                CircleStart                                               // 0x000C(0x0004)
int                                                CircleEnd                                                 // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.WeaponAttachmentConfig
// 0x05D0
struct FWeaponAttachmentConfig
{
struct FText                                       AttachmentName                                            // 0x0000(0x0018)
EWeaponAttachmentSocketType                        AttachmentSocketType                                      // 0x0018(0x0001)
EWeaponSubSlotType                                 SubSlot                                                   // 0x0019(0x0001)
Bool                                               IsExtendMaxBulletNumInOneClip                             // 0x001A(0x0001)
int                                                ExtendMaxBulletNumInOneClipID                             // 0x001C(0x0004)
Bool                                               IsSilencer                                                // 0x0020(0x0001)
Bool                                               IsFireSuppressor                                          // 0x0021(0x0001)
Bool                                               IsCompensator                                             // 0x0022(0x0001)
Bool                                               IsSightDefaultColor                                       // 0x0023(0x0001)
TArray<struct FWeaponAttachmentAttrModify>         WeaponAttachmentAttrModifys                               // 0x0028(0x0010)
TMap<int, struct FWeaponAttachmentAttrListModifyWrapper> SpecialWeaponAttachmentAttrModifysMap                     // 0x0038(0x0050)
TArray<struct FWeaponAttachmentDesc>               WeaponAttachmentDescs                                     // 0x0088(0x0010)
TMap<int, struct FName>                            socketTypeToName                                          // 0x0098(0x0050)
struct FWeaponMeshCfg                              MeshPackage                                               // 0x00F0(0x0480)
TArray<struct FReplacedAttament>                   replacementWeapon                                         // 0x0570(0x0010)
TArray<class UAnimationAsset*>                     AttachmentAnimList                                        // 0x0580(0x0010)
TArray<unsigned char>                              AttachmentAnimListClass                                   // 0x0590(0x0010)
struct FItemDefineID                               ParentID                                                  // 0x05A0(0x0018)
Bool                                               UseSightCrossHairDistance                                 // 0x05B8(0x0001)
float                                              SightMaterialCrossHairDistance                            // 0x05BC(0x0004)
float                                              SightCircleRadius                                         // 0x05C0(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.ReplacedAttament
// 0x04B0
struct FReplacedAttament
{
TArray<struct FItemDefineID>                       targetWeaponIDList                                        // 0x0000(0x0010)
struct FWeaponMeshCfg                              replacedAttachmentCfg                                     // 0x0010(0x0480)
TArray<unsigned char>                              AttachmentAnimListClass                                   // 0x0490(0x0010)
int                                                replacedAttachmentMatIndex                                // 0x04A0(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.WeaponMeshCfg
// 0x0480
struct FWeaponMeshCfg
{
Bool                                               bUseMeshConfigCollection                                  // 0x0000(0x0001)
struct FWeaponAvatarMeshConfigCollection           MeshConfigCollection                                      // 0x0008(0x0018)
Bool                                               bUsePCMeshConfigCollection                                // 0x0020(0x0001)
struct FWeaponAvatarMeshConfigCollection           MeshConfigCollection_PC                                   // 0x0028(0x0018)
unsigned char                                      STMesh                                                    // 0x0040(0x0028)
unsigned char                                      SKMesh                                                    // 0x0068(0x0028)
unsigned char                                      stMeshLod                                                 // 0x0090(0x0028)
unsigned char                                      skMeshLod                                                 // 0x00B8(0x0028)
unsigned char                                      stMeshLod00                                               // 0x00E0(0x0028)
unsigned char                                      skMeshLod00                                               // 0x0108(0x0028)
unsigned char                                      BackOptStaticMesh_Autonomous                              // 0x0130(0x0028)
unsigned char                                      BackOptMat_Autonomous                                     // 0x0158(0x0028)
unsigned char                                      BackOptStaticMesh_Simulate                                // 0x0180(0x0028)
unsigned char                                      BackOptMat_Simulate                                       // 0x01A8(0x0028)
struct FTransform                                  MeshOffsetAdaptation                                      // 0x01D0(0x0030)
struct FTransform                                  MeshOffsetAdaptationForNewFPP                             // 0x0200(0x0030)
int                                                EnableLod00MinTCQuality                                   // 0x0230(0x0004)
TArray<struct FSpecialMachineLobbyConfig>          SpecialMachineLobbyConfig                                 // 0x0238(0x0010)
TArray<struct FSpecialMachineConfig>               SpecialMachineConfig                                      // 0x0248(0x0010)
struct FSpecialConfigForFPP                        NewFPPConfig                                              // 0x0258(0x0028)
Bool                                               bForceUseNewFPP                                           // 0x0280(0x0001)
Bool                                               bNewSkeleton                                              // 0x0281(0x0001)
Bool                                               bOpUpdateTramsform                                        // 0x0282(0x0001)
unsigned char                                      MeshMat                                                   // 0x0288(0x0028)
struct FWeaponMatParamList                         MeshMatList                                               // 0x02B0(0x0010)
unsigned char                                      Lod00MeshMat                                              // 0x02C0(0x0028)
TMap<struct FName, float>                          MeshMatParams                                             // 0x02E8(0x0050)
class UMaterialInterface*                          baseMat                                                   // 0x0338(0x0008)
unsigned char                                      baseMatClass                                              // 0x0340(0x0028)
unsigned char                                      baseMatClass_FPP                                          // 0x0368(0x0028)
Bool                                               UseHighQualityMatMapping                                  // 0x0390(0x0001)
Bool                                               UserHighQualityUseIBL                                     // 0x0391(0x0001)
Bool                                               HighDeviceUseIBL                                          // 0x0392(0x0001)
TArray<struct FParticleRes>                        ParticleEffects                                           // 0x0398(0x0010)
TArray<struct FUIWidgetRes>                        WidgetList                                                // 0x03A8(0x0010)
Bool                                               bForceLODInLobby                                          // 0x03B8(0x0001)
EMeshType                                          meshType                                                  // 0x03B9(0x0001)
unsigned char                                      IdleAnim                                                  // 0x03C0(0x0028)
TArray<struct FLobbyWeaponIdleState>               LobbyWeaponIdleStateArray                                 // 0x03E8(0x0010)
struct FName                                       BackAttachSocketName                                      // 0x03F8(0x0008)
struct FName                                       BagAttachSocketName                                       // 0x0400(0x0008)
TArray<struct FLiquidMaterialAnimatorConfig>       LiquidMaterialAnimatorConfigList                          // 0x0408(0x0010)
struct FVector                                     ReloadOffsetLeftHandLocation                              // 0x0418(0x000C)
struct FRotator                                    ReloadOffsetLeftHandRotation                              // 0x0424(0x000C)
Bool                                               ReloadOffsetUseRelative                                   // 0x0430(0x0001)
struct FVector                                     TPPReloadOffsetLeftHandLocation                           // 0x0434(0x000C)
struct FRotator                                    TPPReloadOffsetLeftHandRotation                           // 0x0440(0x000C)
Bool                                               TPPReloadOffsetUseRelative                                // 0x044C(0x0001)
unsigned char                                      animBPClass_FPP                                           // 0x0450(0x0028)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.LiquidMaterialAnimatorConfig
// 0x0048
struct FLiquidMaterialAnimatorConfig
{
struct FName                                       DynamicPositionParameterName                              // 0x0000(0x0008)
struct FName                                       DynamicDirectionParameterName                             // 0x0008(0x0008)
struct FName                                       MaterialSlotName                                          // 0x0010(0x0008)
struct FName                                       MaterialSocketName                                        // 0x0018(0x0008)
float                                              VelocityScale                                             // 0x0020(0x0004)
float                                              AngularVelocityScale                                      // 0x0024(0x0004)
float                                              Period                                                    // 0x0028(0x0004)
float                                              MaxAmplitude                                              // 0x002C(0x0004)
float                                              AmplitudeLerpAlphaUp                                      // 0x0030(0x0004)
float                                              AmplitudeLerpAlphaDown                                    // 0x0034(0x0004)
struct FRoleAndQualityLobbySelector                LobbySpecialMachineCondition                              // 0x0038(0x000C)
struct FNetRoleAndQualitySelector                  SpecialMachineCondition                                   // 0x0044(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.NetRoleAndQualitySelector
// 0x0004
struct FNetRoleAndQualitySelector
{
int                                                RoleAndQualityConfig                                      // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.RoleAndQualityLobbySelector
// 0x000C
struct FRoleAndQualityLobbySelector
{
int                                                RoleAndQualityConfig                                      // 0x0000(0x0004)
Bool                                               bUltraHighSuitHighQuality                                 // 0x0004(0x0001)
int                                                EnableLod00MinTCQuality                                   // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.LobbyWeaponIdleState
// 0x0030
struct FLobbyWeaponIdleState
{
unsigned char                                      StateAnim                                                 // 0x0000(0x0028)
float                                              StateLength                                               // 0x0028(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.UIWidgetRes
// 0x0080
struct FUIWidgetRes
{
class UClass*                                      UserWidget                                                // 0x0000(0x0008)
unsigned char                                      UserWidgetSoft                                            // 0x0008(0x0028)
struct FName                                       AttachSocket                                              // 0x0030(0x0008)
struct FTransform                                  Trans                                                     // 0x0040(0x0030)
struct FVector2D                                   DrawSize                                                  // 0x0070(0x0008)
Bool                                               bShowDefault                                              // 0x0078(0x0001)
Bool                                               bUseScreenSpace                                           // 0x0079(0x0001)
Bool                                               bShowOnSimulated                                          // 0x007A(0x0001)
Bool                                               bDisableDepthTest                                         // 0x007B(0x0001)
Bool                                               bIsSightUI                                                // 0x007C(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.ParticleRes
// 0x0050
struct FParticleRes
{
class UParticleSystem*                             ParticleRes                                               // 0x0000(0x0008)
struct FName                                       AttachSocket                                              // 0x0008(0x0008)
Bool                                               bEnableAttachTransform                                    // 0x0010(0x0001)
Bool                                               bEnableInGame                                             // 0x0011(0x0001)
struct FTransform                                  AttachTransform                                           // 0x0020(0x0030)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.WeaponMatParamList
// 0x0010
struct FWeaponMatParamList
{
TArray<struct FWeaponMatParam>                     MatParamList                                              // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.WeaponMatParam
// 0x0058
struct FWeaponMatParam
{
struct FName                                       MatSlot                                                   // 0x0000(0x0008)
unsigned char                                      MatSoftRef                                                // 0x0008(0x0028)
unsigned char                                      BastMatSoftRef                                            // 0x0030(0x0028)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.SpecialConfigForFPP
// 0x0028
struct FSpecialConfigForFPP
{
TArray<struct FSpecialMachineConfig>               SpecialMachineConfig                                      // 0x0000(0x0010)
Bool                                               bUsePCMeshConfigCollection                                // 0x0010(0x0001)
TArray<struct FSpecialMachineConfig>               SpecialMachineConfigForPC                                 // 0x0018(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.SpecialMachineConfig
// 0x0090
struct FSpecialMachineConfig
{
unsigned char                                      Material                                                  // 0x0000(0x0028)
struct FWeaponMatParamList                         MeshMatList                                               // 0x0028(0x0010)
unsigned char                                      STMesh                                                    // 0x0038(0x0028)
unsigned char                                      SKMesh                                                    // 0x0060(0x0028)
struct FNetRoleAndQualitySelector                  SpecialMachineCondition                                   // 0x0088(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.SpecialMachineLobbyConfig
// 0x0020
struct FSpecialMachineLobbyConfig
{
TArray<struct FLobbyWeaponMaterialConfig>          MaterialSettingArray                                      // 0x0000(0x0010)
struct FRoleAndQualityLobbySelector                SpecialMachineCondition                                   // 0x0010(0x000C)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.LobbyWeaponMaterialConfig
// 0x00E8
struct FLobbyWeaponMaterialConfig
{
struct FName                                       SlotName                                                  // 0x0000(0x0008)
unsigned char                                      Material                                                  // 0x0008(0x0028)
Bool                                               bEnableBaseMatReplace                                     // 0x0030(0x0001)
unsigned char                                      BaseMaterial                                              // 0x0038(0x0028)
struct FSoftObjectPath                             MaterialPath                                              // 0x0060(0x0018)
struct FSoftObjectPath                             OldMaterialPath                                           // 0x0078(0x0018)
struct FSoftObjectPath                             BaseMaterialPath                                          // 0x0090(0x0018)
struct FSoftObjectPath                             OldBaseMaterialInsPath                                    // 0x00A8(0x0018)
Bool                                               bUseOldConfig                                             // 0x00C0(0x0001)
class UMaterialInterface*                          MaterialIns                                               // 0x00C8(0x0008)
class UMaterialInterface*                          OldMaterialIns                                            // 0x00D0(0x0008)
class UMaterialInterface*                          BaseMaterialIns                                           // 0x00D8(0x0008)
class UMaterialInterface*                          OldBaseMaterialIns                                        // 0x00E0(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.WeaponAvatarMeshConfigCollection
// 0x0018
struct FWeaponAvatarMeshConfigCollection
{
Bool                                               bUseDeviceLevelNumberSelector                             // 0x0000(0x0001)
Bool                                               bUseRoleAndQualityAsAssistSelector                        // 0x0001(0x0001)
TArray<struct FWeaponAvatarMeshConfig>             MeshConfigList                                            // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.WeaponAvatarMeshConfig
// 0x0080
struct FWeaponAvatarMeshConfig
{
int                                                DeviceLevelNumber                                         // 0x0000(0x0004)
struct FRoleAndQualitySelector                     RoleAndQualitySelector                                    // 0x0004(0x0004)
struct FWeaponAvatarSkeletalMeshConfig             SkeletalMeshConfig                                        // 0x0008(0x0050)
struct FWeaponAvatarStaticMeshConfig               StaticMeshConfig                                          // 0x0058(0x0028)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.WeaponAvatarStaticMeshConfig
// 0x0028
struct FWeaponAvatarStaticMeshConfig
{
unsigned char                                      StaticMeshRef                                             // 0x0000(0x0028)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.WeaponAvatarSkeletalMeshConfig
// 0x0050
struct FWeaponAvatarSkeletalMeshConfig
{
unsigned char                                      SkeletalMeshRef                                           // 0x0000(0x0028)
unsigned char                                      AnimBPClass                                               // 0x0028(0x0028)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.RoleAndQualitySelector
// 0x0004
struct FRoleAndQualitySelector
{
int                                                RoleAndQualityConfig                                      // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.WeaponAttachmentDesc
// 0x0030
struct FWeaponAttachmentDesc
{
struct FText                                       Desc                                                      // 0x0000(0x0018)
struct FText                                       DescValue                                                 // 0x0018(0x0018)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.WeaponAttachmentAttrListModifyWrapper
// 0x0018
struct FWeaponAttachmentAttrListModifyWrapper
{
int                                                PreSaveGroupID                                            // 0x0000(0x0004)
TArray<struct FWeaponAttachmentAttrModify>         WeaponAttachmentAttrModifys                               // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.WeaponAttachmentAttrModify
// 0x0050
struct FWeaponAttachmentAttrModify
{
struct FString                                     ModifyAttr                                                // 0x0000(0x0010)
struct FString                                     ComponentClassName                                        // 0x0010(0x0010)
EAttrOperator                                      Op                                                        // 0x0020(0x0001)
Bool                                               bModifyResource                                           // 0x0021(0x0001)
float                                              ModifyValue                                               // 0x0024(0x0004)
unsigned char                                      ModifyResValue                                            // 0x0028(0x0028)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.WeaponAvatarBehaviorFeatureParam
// 0x0120
struct FWeaponAvatarBehaviorFeatureParam
{
class UClass*                                      BehaviorFeatureClass                                      // 0x0000(0x0008)
struct FMatWeaponStateBehaviorParam                MatWeaponStateBehaviorParam                               // 0x0008(0x0018)
struct FWeaponParticleHiddenBehaviorParam          WeaponParticleHiddenBehaviorParam                         // 0x0020(0x0018)
struct FParticleReplaceDeviceRoleBehaviorParam     ParticleReplaceDeviceRoleBehaviorParam                    // 0x0038(0x0010)
struct FWeaponTranslucentBehaviorParam             WeaponTranslucentBehaviorParam                            // 0x0048(0x00C0)
struct FWeaponAddAvatarSubSystemBehaviorFeatureParam WeaponAddAvatarSubSystemParam                             // 0x0108(0x0018)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.WeaponAddAvatarSubSystemBehaviorFeatureParam
// 0x0018
struct FWeaponAddAvatarSubSystemBehaviorFeatureParam
{
TArray<class UClass*>                              SubsystemList                                             // 0x0000(0x0010)
int                                                CreateConfig                                              // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.WeaponTranslucentBehaviorParam
// 0x00C0
struct FWeaponTranslucentBehaviorParam
{
struct FWeaponTranslucentConfig                    AvatarTranslucentConfig                                   // 0x0000(0x00C0)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.WeaponTranslucentConfig
// 0x00C0
struct FWeaponTranslucentConfig
{
TMap<unsigned char, struct FTranslucentDetailConfig> SkeletalMeshTranslucentMap                                // 0x0000(0x0050)
TMap<unsigned char, struct FTranslucentDetailConfig> StaticMeshTranslucentMap                                  // 0x0050(0x0050)
TWeakObjectPtr<class UMeshComponent>               SetTranslucentDepthWriteMeshObj                           // 0x00A0(0x0008)
TWeakObjectPtr<class UMeshComponent>               SetTwoPassTranslucentMeshObj                              // 0x00A8(0x0008)
TWeakObjectPtr<class UMeshComponent>               SetTwoPassMeshObj                                         // 0x00B0(0x0008)
TWeakObjectPtr<class UMeshComponent>               SetTwoPassTranslucentDepthWriteMeshObj                    // 0x00B8(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.TranslucentDetailConfig
// 0x0030
struct FTranslucentDetailConfig
{
struct FFeatureUsageScene                          TranslucentDepthWriteConfig                               // 0x0000(0x000C)
struct FFeatureUsageScene                          TwoPassTranslucentConfig                                  // 0x000C(0x000C)
struct FFeatureUsageScene                          TwoPassTranslucentepthWriteConfig                         // 0x0018(0x000C)
struct FFeatureUsageScene                          TwoPassConfig                                             // 0x0024(0x000C)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.FeatureUsageScene
// 0x000C
struct FFeatureUsageScene
{
struct FRoleAndQualitySelector                     CurSelector                                               // 0x0000(0x0004)
Bool                                               bLod00Type                                                // 0x0004(0x0001)
int                                                EnableLod00MinTCQuality                                   // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.ParticleReplaceDeviceRoleBehaviorParam
// 0x0010
struct FParticleReplaceDeviceRoleBehaviorParam
{
TArray<struct FParticleReplaceDeviceRoleSelector>  ParticleReplaceSelectorList                               // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.ParticleReplaceDeviceRoleSelector
// 0x0100
struct FParticleReplaceDeviceRoleSelector
{
unsigned char                                      FromParticleResRef                                        // 0x0000(0x0028)
struct FName                                       ParticleSlotName                                          // 0x0028(0x0008)
struct FRoleAndQualitySelector                     RoleAndQualitySelector                                    // 0x0030(0x0004)
unsigned char                                      ToParticleResRef                                          // 0x0038(0x0028)
TMap<unsigned char, unsigned char>                 MatchCameraModeList                                       // 0x0060(0x0050)
TMap<EPawnState, unsigned char>                    MatchStateList                                            // 0x00B0(0x0050)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.WeaponParticleHiddenBehaviorParam
// 0x0018
struct FWeaponParticleHiddenBehaviorParam
{
int                                                TickInterval                                              // 0x0000(0x0004)
TArray<struct FParticleHiddenWeaponStateSelector>  ParticleHiddenWeaponStateSelectorList                     // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.ParticleHiddenWeaponStateSelector
// 0x00C8
struct FParticleHiddenWeaponStateSelector
{
unsigned char                                      ParticleResourceReference                                 // 0x0000(0x0028)
struct FName                                       ParticleSocketName                                        // 0x0028(0x0008)
struct FRoleAndQualitySelector                     RoleAndQualitySelector                                    // 0x0030(0x0004)
Bool                                               bOnlyMatchRoleAndQuality                                  // 0x0034(0x0001)
Bool                                               bMatchAllCondition                                        // 0x0035(0x0001)
Bool                                               bMatchCameraMode                                          // 0x0036(0x0001)
TArray<unsigned char>                              MatchCameraModeList                                       // 0x0038(0x0010)
Bool                                               bHiddenByCameraMode                                       // 0x0048(0x0001)
Bool                                               bMatchState                                               // 0x0049(0x0001)
TArray<EPawnState>                                 MatchStateList                                            // 0x0050(0x0010)
Bool                                               bMatchBuff                                                // 0x0060(0x0001)
TArray<struct FName>                               MatchBuffList                                             // 0x0068(0x0010)
TMap<struct FName, struct FAvatarFastShapeParam>   BuffFastShapeParamMap                                     // 0x0078(0x0050)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.AvatarFastShapeParam
// 0x0028
struct FAvatarFastShapeParam
{
class UClass*                                      ShapeTargetClass                                          // 0x0000(0x0008)
Bool                                               bUseGameConcernObjFeature                                 // 0x0008(0x0001)
float                                              AxisRelevantRange                                         // 0x000C(0x0004)
unsigned char                                      ShapeType                                                 // 0x0010(0x0001)
float                                              Radius                                                    // 0x0014(0x0004)
struct FVector                                     BoxExtent                                                 // 0x0018(0x000C)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.MatWeaponStateBehaviorParam
// 0x0018
struct FMatWeaponStateBehaviorParam
{
int                                                TickInterval                                              // 0x0000(0x0004)
Bool                                               bMeltToShareBuffCheckResult                               // 0x0004(0x0001)
TArray<struct FMatSelector_WeaponStateMatch>       WeaponStateMatSelectorList                                // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.MatSelector_WeaponStateMatch
// 0x0090
struct FMatSelector_WeaponStateMatch
{
struct FName                                       MatSlotName                                               // 0x0000(0x0008)
struct FRoleAndQualitySelector                     RoleAndQualitySelector                                    // 0x0008(0x0004)
unsigned char                                      NormalMatResourceReference                                // 0x0010(0x0028)
unsigned char                                      StateMatResourceReference                                 // 0x0038(0x0028)
Bool                                               bMatchAllCondition                                        // 0x0060(0x0001)
TArray<struct FAvatarBuffParam_Weapon>             MatchBuffList                                             // 0x0068(0x0010)
TArray<EPawnState>                                 MatchStateList                                            // 0x0078(0x0010)
Bool                                               bIsEnterWater                                             // 0x0088(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.AvatarBuffParam
// 0x0038
struct FAvatarBuffParam
{
struct FName                                       BuffName                                                  // 0x0000(0x0008)
Bool                                               bUseBuffFastShape                                         // 0x0008(0x0001)
struct FAvatarFastShapeParam                       BuffFastShapeParam                                        // 0x0010(0x0028)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.MeshSocketInfo
// 0x0018
struct FMeshSocketInfo
{
struct FNetRoleAndQualitySelector                  SpecialMachineCondition                                   // 0x0000(0x0004)
Bool                                               bUsePCMeshConfigCollection                                // 0x0004(0x0001)
TArray<struct FSingleMeshSocketInfo>               MeshSocketInfoArray                                       // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.SingleMeshSocketInfo
// 0x0058
struct FSingleMeshSocketInfo
{
Bool                                               bSk                                                       // 0x0000(0x0001)
struct FName                                       SocketName                                                // 0x0008(0x0008)
struct FName                                       BoneName                                                  // 0x0010(0x0008)
struct FVector                                     RelativeLocation                                          // 0x0018(0x000C)
struct FRotator                                    RelativeRotation                                          // 0x0024(0x000C)
struct FVector                                     RelativeScale                                             // 0x0030(0x000C)
struct FString                                     Tag                                                       // 0x0040(0x0010)
Bool                                               bForceAlwaysAnimated                                      // 0x0050(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.WeaponAttachmentConfigWrapper
// 0x0010
struct FWeaponAttachmentConfigWrapper
{
TArray<struct FPESkillAttributeItem>               WeaponAttachmentAttrList                                  // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.PESkillAttributeItem
// 0x0180
struct FPESkillAttributeItem
{
EFPESkillAttributeModifyMethod                     Method                                                    // 0x0000(0x0001)
struct FString                                     OptionalModifyItemNameID                                  // 0x0008(0x0010)
struct FGameAttributeContainer                     GameAttribute                                             // 0x0018(0x0028)
EAttrOperator                                      ModifierOp                                                // 0x0040(0x0001)
EAttrOperator_DoChange                             ModifierOp_DoChange                                       // 0x0041(0x0001)
struct FGameMagnitudeWrapper                       ModifierValueWrapper                                      // 0x0048(0x0108)
Bool                                               bModifyForever                                            // 0x0150(0x0001)
int                                                DataVersion                                               // 0x0154(0x0004)
Bool                                               bRepAttrModify                                            // 0x0158(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.GameMagnitudeWrapper
// 0x0108
struct FGameMagnitudeWrapper
{
EPESkillValueCalculatorType                        CalculatorType                                            // 0x0000(0x0001)
float                                              Value                                                     // 0x0004(0x0004)
struct FGameAttributeContainer                     GameAttribute                                             // 0x0008(0x0028)
struct FFloatGetter                                ValueA                                                    // 0x0030(0x0060)
struct FFloatGetter                                ValueB                                                    // 0x0090(0x0060)
struct FBindFunctionSelector                       TriggerFunction                                           // 0x00F8(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.BindFunctionSelector
// 0x0010
struct FBindFunctionSelector
{
class UObject*                                     Object                                                    // 0x0000(0x0008)
struct FName                                       FunctionName                                              // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.PropetyGetter
// 0x0020
struct FPropetyGetter
{
class UObject*                                     BlueprintObject                                           // 0x0008(0x0008)
class UObject*                                     Target                                                    // 0x0010(0x0008)
struct FName                                       PropertyName                                              // 0x0018(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.FloatGetter
// 0x0040 (0x0060 - 0x0020)
struct FFloatGetter : public FPropetyGetter
{
class AActor*                                      TargetActor                                               // 0x0020(0x0008)
EPEGetterType                                      GetterType                                                // 0x0028(0x0001)
float                                              Value                                                     // 0x002C(0x0004)
struct FGameAttributeContainer                     GameAttributeX                                            // 0x0030(0x0028)
float                                              ValueA                                                    // 0x0058(0x0004)
float                                              ValueB                                                    // 0x005C(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.ShootWeaponDataModeConfig
// 0x0018
struct FShootWeaponDataModeConfig
{
TArray<class UClass*>                              WeaponLogicCompTemplateConfigList                         // 0x0000(0x0010)
Bool                                               bDisableScopeIn                                           // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.WeaponPendantMap
// 0x0018
struct FWeaponPendantMap
{
int                                                WeaponID                                                  // 0x0000(0x0004)
TArray<struct FWeaponPendantSocket>                PendantInfoList                                           // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.WeaponPendantSocket
// 0x0090
struct FWeaponPendantSocket
{
EWeaponPendantSocketType                           PendantSocketType                                         // 0x0000(0x0001)
int                                                PendantIndex                                              // 0x0004(0x0004)
Bool                                               IsOpenConstraint                                          // 0x0008(0x0001)
struct FAvatarPendantConfig                        AnimConstraint                                            // 0x0010(0x0060)
Bool                                               OverrideLocalJoinOffset                                   // 0x0070(0x0001)
struct FVector                                     LocalJoinOffset                                           // 0x0074(0x000C)
struct FVector                                     LocalOffset                                               // 0x0080(0x000C)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.AvatarPendantConfig
// 0x0060
struct FAvatarPendantConfig
{
struct FString                                     ConfigName                                                // 0x0000(0x0010)
struct FTransform                                  SocketRelativeTransform                                   // 0x0010(0x0030)
struct FVector                                     AngularLimitsMin                                          // 0x0040(0x000C)
struct FVector                                     AngularLimitsMax                                          // 0x004C(0x000C)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.PickupWrapperProcectBase
// 0x0020
struct FPickupWrapperProcectBase
{
int                                                Power                                                     // 0x0008(0x0004)
int                                                TipsID                                                    // 0x000C(0x0004)
struct FString                                     EXStr                                                     // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.PickUpItemData
// 0x0038
struct FPickUpItemData
{
struct FItemDefineID                               ID                                                        // 0x0000(0x0018)
int                                                Count                                                     // 0x0018(0x0004)
TArray<struct FBattleItemAdditionalData>           AdditionalDataList                                        // 0x0020(0x0010)
int                                                InstanceID                                                // 0x0030(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.PickUpWrapperItem
// 0x0048
struct FPickUpWrapperItem
{
struct FItemDefineID                               DefineID                                                  // 0x0000(0x0018)
int                                                Count                                                     // 0x0018(0x0004)
TArray<struct FBattleItemAdditionalData>           AdditionalData                                            // 0x0020(0x0010)
int                                                ParentIndex                                               // 0x0030(0x0004)
struct FName                                       ParentSideAssociationName                                 // 0x0038(0x0008)
int                                                ItemInstanceID                                            // 0x0040(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.DropGroundEffectInfo
// 0x0080
struct FDropGroundEffectInfo
{
float                                              GroundEffectLifeSpan                                      // 0x0000(0x0004)
struct FTransform                                  EffectTransform                                           // 0x0010(0x0030)
unsigned char                                      GroundEffect                                              // 0x0040(0x0028)
struct FString                                     EffectPath                                                // 0x0068(0x0010)
Bool                                               bShowGroundEffect                                         // 0x0078(0x0001)
Bool                                               bUsePickUpSelfEffect                                      // 0x0079(0x0001)
Bool                                               bEffectActive                                             // 0x007A(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.DropItemPerformanceInfo
// 0x0070
struct FDropItemPerformanceInfo
{
Bool                                               IsPerforming                                              // 0x0000(0x0001)
class AActor*                                      DropItemsProducer                                         // 0x0008(0x0008)
class USceneComponent*                             ProducerComponent                                         // 0x0010(0x0008)
class AActor*                                      ItemActor                                                 // 0x0018(0x0008)
class AActor*                                      AttachActor                                               // 0x0020(0x0008)
TWeakObjectPtr<class UPrimitiveComponent>          AttachComponent                                           // 0x0028(0x0008)
struct FVector                                     SourcePos                                                 // 0x0030(0x000C)
struct FVector                                     TargetPos                                                 // 0x003C(0x000C)
class USceneComponent*                             DropAttachedComponent                                     // 0x0048(0x0008)
struct FSoftObjectPath                             GroundParticle                                            // 0x0050(0x0018)
Bool                                               IsAttached                                                // 0x0068(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.InteractBehaviorWrapper
// 0x0010
struct FInteractBehaviorWrapper
{
TArray<struct FInteractBehaviorList>               BehaviorListPackage                                       // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.InteractBehaviorList
// 0x0068
struct FInteractBehaviorList
{
class UObject*                                     Interactor                                                // 0x0000(0x0008)
class UPrimitiveComponent*                         InteractorPrimitive                                       // 0x0008(0x0008)
Bool                                               bUseVisibilityDetection                                   // 0x0010(0x0001)
unsigned char                                      UIWidget                                                  // 0x0018(0x0028)
TArray<struct FInteractBehavior>                   Behaviors                                                 // 0x0040(0x0010)
EInteractionDataType                               InteractionDataType                                       // 0x0050(0x0001)
class UPreciseInteractionAdapter*                  InteractionAdapter                                        // 0x0058(0x0008)
int                                                UISlot                                                    // 0x0060(0x0004)
int                                                UniqueID                                                  // 0x0064(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.InteractBehavior
// 0x0040
struct FInteractBehavior
{
struct FName                                       BehaviorKey                                               // 0x0000(0x0008)
struct FInteractBehaviorUIInfo                     UIInfo                                                    // 0x0008(0x0018)
class UObject*                                     BehaviorOwner                                             // 0x0020(0x0008)
Bool                                               bHiddenInScopeInteraction                                 // 0x0028(0x0001)
class UObject*                                     RealInteractor                                            // 0x0030(0x0008)
class UPrimitiveComponent*                         RealInteractorPrimitive                                   // 0x0038(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.InteractBehaviorUIInfo
// 0x0018
struct FInteractBehaviorUIInfo
{
struct FName                                       PromptText                                                // 0x0000(0x0008)
class UTexture2D*                                  PromptTexture                                             // 0x0008(0x0008)
float                                              RenderOpacity                                             // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.PickupProtectSetting
// 0x00C0
struct FPickupProtectSetting
{
struct FPickupWrapperProcectBase                   DefaultSetting                                            // 0x0000(0x0020)
struct FPickupWrapperProcectOwnerCheck             OwnerCheckSetting                                         // 0x0020(0x0020)
struct FPickupWrapperProcectNotTeammateCheck       NotTeammateCheckSetting                                   // 0x0040(0x0020)
struct FPickupWrapperProcectNotAllowCheck          NotAllowCheckSetting                                      // 0x0060(0x0020)
struct FPickupWrapperProcectKeyOwnerCheck          KeyOwnerCheckSetting                                      // 0x0080(0x0020)
struct FPickupWrapperProcectOwnerAndTeammatesCheck OwnerAndTeammatesCheckSetting                             // 0x00A0(0x0020)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.AvatarMaterialNamePair
// 0x0018
struct FAvatarMaterialNamePair
{
struct FName                                       SlotName                                                  // 0x0000(0x0008)
struct FName                                       ParamName                                                 // 0x0008(0x0008)
EAvatarMaterialParamType                           AvatarMaterialParamType                                   // 0x0010(0x0001)
EABF_AvatarExtraPartType                           AvatarExtraPartType                                       // 0x0011(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct ShadowTrackerExtra.STExtraVehicleOccupierState
// 0x0020
struct FSTExtraVehicleOccupierState
{
class ASTExtraPlayerCharacter*                     OccupierCharacter                                         // 0x0000(0x0008)
Bool                                               bUsingVehicleAnimIns                                      // 0x0008(0x0001)
TWeakObjectPtr<class UAnimInstance>                FPPAnimVehicleIns                                         // 0x000C(0x0008)
TWeakObjectPtr<class UAnimInstance>                TPPAnimVehicleIns                                         // 0x0014(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.DamageEvent
// 0x0038
struct FDamageEvent
{
class UClass*                                      DamageTypeClass                                           // 0x0008(0x0008)
float                                              DamageImpulseScale                                        // 0x0014(0x0004)
class UObject*                                     DamageSourceObj                                           // 0x0030(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.RequestResponseCanShowKillThanksUIContext
// 0x0040
struct FRequestResponseCanShowKillThanksUIContext
{
Bool                                               bCanShow                                                  // 0x0000(0x0001)
ECanShowKillThanksUIOperation                      CanShowKillThanksUIOperation                              // 0x0001(0x0001)
class AActor*                                      TombBox                                                   // 0x0008(0x0008)
struct FString                                     UID                                                       // 0x0010(0x0010)
struct FString                                     IconURL                                                   // 0x0020(0x0010)
int                                                Gender                                                    // 0x0030(0x0004)
int                                                PlatformGender                                            // 0x0034(0x0004)
int                                                SegmentLevel                                              // 0x0038(0x0004)
int                                                PlayerLevel                                               // 0x003C(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.RequestResponseKillThanksContext
// 0x0020
struct FRequestResponseKillThanksContext
{
int                                                Result                                                    // 0x0000(0x0004)
class AActor*                                      TombBox                                                   // 0x0008(0x0008)
struct FString                                     UID                                                       // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.ItemOperationInfo
// 0x0030
struct FItemOperationInfo
{
struct FItemDefineID                               DefineID                                                  // 0x0000(0x0018)
EBattleItemOperationType                           BattleItemOperationType                                   // 0x0018(0x0001)
unsigned char                                      Reason                                                    // 0x0019(0x0001)
int                                                Count                                                     // 0x001C(0x0004)
class UObject*                                     Source                                                    // 0x0020(0x0008)
Bool                                               bTriggerEvent                                             // 0x0028(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.PlayerStateChangedParams
// 0x0028
struct FPlayerStateChangedParams
{
struct FPlayerID                                   PlayerID                                                  // 0x0000(0x0010)
struct FName                                       PlayerState                                               // 0x0010(0x0008)
struct FString                                     Reason                                                    // 0x0018(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.PlayerID
// 0x0010
struct FPlayerID
{
struct FName                                       PlayerType                                                // 0x0000(0x0008)
uint32_t                                           PlayerKey                                                 // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.GameModeStateChangedParams
// 0x0008
struct FGameModeStateChangedParams
{
struct FName                                       GameModeState                                             // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.BattleMessageInfo
// 0x002C
struct FBattleMessageInfo
{
int                                                GameNum                                                   // 0x0000(0x0004)
int                                                WinNum                                                    // 0x0004(0x0004)
int                                                TeamRank                                                  // 0x0008(0x0004)
int                                                Kill                                                      // 0x000C(0x0004)
float                                              TopTenCount                                               // 0x0010(0x0004)
float                                              KD                                                        // 0x0014(0x0004)
int                                                SeasonID                                                  // 0x0018(0x0004)
int                                                Rank                                                      // 0x001C(0x0004)
int                                                PeakFamousCount                                           // 0x0020(0x0004)
int                                                WarZoneId                                                 // 0x0024(0x0004)
int                                                RankedRank                                                // 0x0028(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.CollectedEventData
// 0x0050
struct FCollectedEventData
{
TMap<struct FString, struct FString>               KeyValueMap                                               // 0x0000(0x0050)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.GameModePlayerParams
// 0x0C58
struct FGameModePlayerParams
{
uint64_t                                           UID                                                       // 0x0000(0x0008)
struct FName                                       PlayerType                                                // 0x0008(0x0008)
struct FString                                     PlayerName                                                // 0x0010(0x0010)
uint32_t                                           PlayerKey                                                 // 0x0020(0x0004)
struct FName                                       PlayerLiteStatsID                                         // 0x0028(0x0008)
uint32_t                                           WorldParallelismID                                        // 0x0030(0x0004)
int                                                TeamID                                                    // 0x0034(0x0004)
uint64_t                                           RoomTeammatesID                                           // 0x0038(0x0008)
Bool                                               bForbidReportTeammate                                     // 0x0040(0x0001)
int                                                RemainTeammateHurtCount                                   // 0x0044(0x0004)
int                                                RemainTeammateKillCount                                   // 0x0048(0x0004)
int                                                RemainTeammateCarInterruptSaveCount                       // 0x004C(0x0004)
int                                                ReportUncivilizedCount                                    // 0x0050(0x0004)
struct FString                                     OpenID                                                    // 0x0058(0x0010)
struct FString                                     RemarkName                                                // 0x0068(0x0010)
Bool                                               ChangedNameByDS                                           // 0x0078(0x0001)
int                                                CountryID                                                 // 0x007C(0x0004)
struct FString                                     Country                                                   // 0x0080(0x0010)
struct FString                                     CountryFullName                                           // 0x0090(0x0010)
struct FString                                     CountryIconURL                                            // 0x00A0(0x0010)
Bool                                               NeedScreenShot                                            // 0x00B0(0x0001)
int                                                PlayerBornPointID                                         // 0x00B4(0x0004)
Bool                                               bTeamLeader                                               // 0x00B8(0x0001)
Bool                                               bIsGM                                                     // 0x00B9(0x0001)
Bool                                               bIsEnableUGCGM                                            // 0x00BA(0x0001)
Bool                                               bUGCGMEnabled                                             // 0x00BB(0x0001)
Bool                                               bIsGMWatcher                                              // 0x00BC(0x0001)
Bool                                               bEagleWatch                                               // 0x00BD(0x0001)
int                                                EagleWatchType                                            // 0x00C0(0x0004)
unsigned char                                      WatchType                                                 // 0x00C4(0x0001)
Bool                                               bHighPriorityRelevancy                                    // 0x00C5(0x0001)
unsigned char                                      SecMarkType                                               // 0x00C6(0x0001)
Bool                                               IsWorkManGetChestLimit                                    // 0x00C7(0x0001)
struct FString                                     WorkManChestLimitStr                                      // 0x00C8(0x0010)
Bool                                               bIsCheatPlayer                                            // 0x00D8(0x0001)
unsigned char                                      Gender                                                    // 0x00D9(0x0001)
struct FString                                     PIC_URL                                                   // 0x00E0(0x0010)
int                                                Level                                                     // 0x00F0(0x0004)
int                                                Segment_Level                                             // 0x00F4(0x0004)
int                                                AvatarBoxId                                               // 0x00F8(0x0004)
int                                                TopSegmentTimes                                           // 0x00FC(0x0004)
int                                                CurModeRating                                             // 0x0100(0x0004)
Bool                                               bAIPlayer                                                 // 0x0104(0x0001)
TArray<struct FGameModePlayerItem>                 ItemList                                                  // 0x0108(0x0010)
TArray<struct FGameModePlayerItem>                 fireworksInfo                                             // 0x0118(0x0010)
TArray<struct FGameModePlayerItem>                 InteractivePropsItemList                                  // 0x0128(0x0010)
struct FSuitSkinData                               SuitSkinData                                              // 0x0138(0x0030)
TArray<struct FWeaponModData>                      WeaponModDatas                                            // 0x0168(0x0010)
TArray<struct FGameModePlayerExpressionItem>       ExpressionItemList                                        // 0x0178(0x0010)
TArray<struct FGameModePlayerDecalItem>            DecalItemList                                             // 0x0188(0x0010)
TArray<struct FGameModePlayerTaskData>             TaskDataList                                              // 0x0198(0x0010)
TArray<struct FGameModePlayerItem>                 WeaponAvatarList                                          // 0x01A8(0x0010)
TArray<struct FGameModePlayerItem>                 VehicleAvatarList                                         // 0x01B8(0x0010)
TArray<struct FString>                             KeepWeaponDataList                                        // 0x01C8(0x0010)
struct FGameModePlayer_WearInfo                    PlayerWearInfo                                            // 0x01D8(0x00F0)
struct FPlayerOBInfo                               PlayerOBInfo                                              // 0x02C8(0x01B8)
TArray<struct FGameModePlayerBanChat>              banList                                                   // 0x0480(0x0010)
TArray<struct FSpecialPickItem>                    SpecialPickItem                                           // 0x0490(0x0010)
TArray<struct FDeadBoxItem>                        deadBoxItemList                                           // 0x04A0(0x0010)
struct FWeaponLobbyInitialData                     WeaponLobbyInitialData                                    // 0x04B0(0x0010)
struct FPlayerTotalWeaponsConfig                   PlayerTotalWeaponsConfig                                  // 0x04C0(0x0018)
struct FThemePlayerWeaponConfig                    ThemePlayerWeaponConfig                                   // 0x04D8(0x0028)
struct FAchievementPrize                           EquippedAchievementPrize                                  // 0x0500(0x0040)
TArray<int>                                        audioChat                                                 // 0x0540(0x0010)
struct FName                                       CurrentPlayerState                                        // 0x0550(0x0008)
struct FName                                       CurrentCharacterState                                     // 0x0558(0x0008)
float                                              SyncedTimestamp                                           // 0x0560(0x0004)
float                                              DestinyValue                                              // 0x0564(0x0004)
float                                              WarmScore                                                 // 0x0568(0x0004)
int                                                LeaderCount                                               // 0x056C(0x0004)
uint64_t                                           LastGameLeaderUID                                         // 0x0570(0x0008)
TArray<uint64_t>                                   LastGameTeammatesUID                                      // 0x0578(0x0010)
int                                                JumpSegmentID                                             // 0x0588(0x0004)
uint64_t                                           LastGameBattleID                                          // 0x0590(0x0008)
int                                                YearBeastWarmScore                                        // 0x0598(0x0004)
float                                              RatingScore                                               // 0x059C(0x0004)
Bool                                               bUseNewVaultComp                                          // 0x05A0(0x0001)
Bool                                               bDoPlayerUseAutoFollow                                    // 0x05A1(0x0001)
Bool                                               bAutoForceOpenParachute                                   // 0x05A2(0x0001)
float                                              MaxRankingScore                                           // 0x05A4(0x0004)
float                                              VSTeamRatingScore                                         // 0x05A8(0x0004)
float                                              BTFRatingScore                                            // 0x05AC(0x0004)
int                                                BucketIdx                                                 // 0x05B0(0x0004)
Bool                                               bIsObserver                                               // 0x05B4(0x0001)
Bool                                               bObserverHost                                             // 0x05B5(0x0001)
int                                                OBGM                                                      // 0x05B8(0x0004)
Bool                                               bHasPausePrivilege                                        // 0x05BC(0x0001)
int                                                ObserverEnemyDist                                         // 0x05C0(0x0004)
uint32_t                                           WatchPlayerKey                                            // 0x05C4(0x0004)
uint64_t                                           WatchPlayerUID                                            // 0x05C8(0x0008)
uint64_t                                           FollowUID                                                 // 0x05D0(0x0008)
unsigned char                                      PlatformGender                                            // 0x05D8(0x0001)
struct FPrivacyProtectDetail                       PrivacyDetail                                             // 0x05E0(0x0020)
Bool                                               bIsFireworksActOpen                                       // 0x0600(0x0001)
int                                                MatchLabel                                                // 0x0604(0x0004)
Bool                                               IsBanPublicMic                                            // 0x0608(0x0001)
int                                                AnchorPlatColorID                                         // 0x060C(0x0004)
int                                                AnchorPlatResID                                           // 0x0610(0x0004)
struct FString                                     MedalClubID                                               // 0x0618(0x0010)
int                                                MedalClubLevel                                            // 0x0628(0x0004)
int                                                PassCardBuyType                                           // 0x062C(0x0004)
int                                                PassCardBuyLevel                                          // 0x0630(0x0004)
Bool                                               IsEnjoyCardOpen                                           // 0x0634(0x0001)
Bool                                               NeedShowEnjoyCard                                         // 0x0635(0x0001)
int                                                Likedlevel                                                // 0x0638(0x0004)
TArray<struct FCommonFlagData>                     CommonFlagData                                            // 0x0640(0x0010)
int64_t                                            LastGameResultTime                                        // 0x0650(0x0008)
int64_t                                            CorpsID                                                   // 0x0658(0x0008)
int                                                PlayerStartSerialNum                                      // 0x0660(0x0004)
Bool                                               bUsedSimulation                                           // 0x0664(0x0001)
int                                                special_ver                                               // 0x0668(0x0004)
Bool                                               allow_watch                                               // 0x066C(0x0001)
Bool                                               allow_like                                                // 0x066D(0x0001)
Bool                                               allow_friend_like                                         // 0x066E(0x0001)
Bool                                               allow_teammate_like                                       // 0x066F(0x0001)
Bool                                               allow_teammate_positive_like                              // 0x0670(0x0001)
Bool                                               bCollectedEventDataReportingEnabled                       // 0x0671(0x0001)
int                                                CollectedEventType                                        // 0x0674(0x0004)
Bool                                               bLiveVideoReplay                                          // 0x0678(0x0001)
Bool                                               bLiveReplay                                               // 0x0679(0x0001)
Bool                                               bConvertibleCarOpen                                       // 0x067A(0x0001)
Bool                                               bCollectedEVLiveEventDataReportingEnabled                 // 0x067B(0x0001)
struct FPlayerCharmInfo                            CharmInfo                                                 // 0x067C(0x0010)
struct FPromotionMatchInfo                         PromotionInfo                                             // 0x068C(0x0018)
struct FPlayerPeakInfo                             PeakInfo                                                  // 0x06A8(0x0048)
struct FWingManInfo                                WingManInfo                                               // 0x06F0(0x0058)
Bool                                               IsInspector                                               // 0x0748(0x0001)
int                                                GlideTypeId                                               // 0x074C(0x0004)
Bool                                               bGlideConfigState                                         // 0x0750(0x0001)
int                                                GlideCount                                                // 0x0754(0x0004)
Bool                                               GlideGlobalVisible                                        // 0x0758(0x0001)
Bool                                               showIslandNickname                                        // 0x0759(0x0001)
int                                                InitDropId                                                // 0x075C(0x0004)
TArray<int>                                        InitDropIdList                                            // 0x0760(0x0010)
int                                                SpecMotionRestCostCount                                   // 0x0770(0x0004)
int                                                SeasonWeekIndex                                           // 0x0774(0x0004)
int                                                JoinSourceType                                            // 0x0778(0x0004)
int8_t                                             is_regress                                                // 0x077C(0x0001)
int8_t                                             not_counter_ai                                            // 0x077D(0x0001)
Bool                                               bCampPrivileges                                           // 0x077E(0x0001)
Bool                                               bShowAirLine                                              // 0x077F(0x0001)
Bool                                               bUseDistanceMeasurement                                   // 0x0780(0x0001)
Bool                                               bShowTeammateKillInfo                                     // 0x0781(0x0001)
Bool                                               bDice                                                     // 0x0782(0x0001)
Bool                                               bShowResPoint                                             // 0x0783(0x0001)
Bool                                               bEnablePointEnhance                                       // 0x0784(0x0001)
Bool                                               bEnableSoundPromptEnhance                                 // 0x0785(0x0001)
Bool                                               bEnableAirPointEnhance                                    // 0x0786(0x0001)
Bool                                               bVoiceChanger                                             // 0x0787(0x0001)
int                                                iCampToolStatusFromServer                                 // 0x0788(0x0004)
Bool                                               bAchieveAce                                               // 0x078C(0x0001)
unsigned char                                      room_team_pos                                             // 0x078D(0x0001)
struct FUGCPlayerInfo                              UGCPlayerInfo                                             // 0x0790(0x0078)
TArray<int>                                        ConfessionMessage                                         // 0x0808(0x0010)
struct FString                                     playerFaceInfo                                            // 0x0818(0x0010)
int                                                playerFaceHandleID                                        // 0x0828(0x0004)
int                                                KillThanksCount                                           // 0x082C(0x0004)
Bool                                               bPartiallyKillThanksToOthersEnabled                       // 0x0830(0x0001)
Bool                                               bPartiallyKillThanksFromOthersEnabled                     // 0x0831(0x0001)
Bool                                               bPlayGunMasterVideo                                       // 0x0832(0x0001)
int                                                imprint_info                                              // 0x0834(0x0004)
Bool                                               bNeedRCR                                                  // 0x0838(0x0001)
Bool                                               bIsSwitchDSPlayer                                         // 0x0839(0x0001)
TArray<uint64_t>                                   LobbyTeammates                                            // 0x0840(0x0010)
struct FPlayerPetInfo                              PlayerPetInfo                                             // 0x0850(0x000C)
struct FPlayerClubTeamInfo                         ClubTeamInfo                                              // 0x0860(0x0028)
TArray<int>                                        InfectPawnIDList                                          // 0x0888(0x0010)
unsigned char                                      CampID                                                    // 0x0898(0x0001)
unsigned char                                      bIsCampModeCaptain                                        // 0x0899(0x0001)
struct FPlayerStageBattleRecord                    StageBattleRecord                                         // 0x08A0(0x0048)
TMap<int, struct FWeaponSkinEffectResearchMisc>    WeaponSkinEffectResearchMiscMap                           // 0x08E8(0x0050)
Bool                                               EnableTombBoxBattleUpgrade                                // 0x0938(0x0001)
TMap<int, int>                                     WeaponUpgradeIdToSkinBaseIDMap                            // 0x0940(0x0050)
struct FConsumeRankPlayerInfo                      ConsumeRankPlayerInfo                                     // 0x0990(0x0068)
struct FLargeAircraftData                          LargeAircraftData                                         // 0x09F8(0x0028)
int                                                curr_cabin_animation                                      // 0x0A20(0x0004)
int                                                BigwarAvatarSettingType                                   // 0x0A24(0x0004)
int                                                patrol_right_cases                                        // 0x0A28(0x0004)
TMap<int, int>                                     parachute_sign_binds                                      // 0x0A30(0x0050)
int                                                fall_land_effect_id                                       // 0x0A80(0x0004)
TMap<int, int>                                     ClothingUpgradeTwinsMap                                   // 0x0A88(0x0050)
TMap<int, int>                                     KillTipsEffectSkinIDMap                                   // 0x0AD8(0x0050)
int                                                BornlandShowCarID                                         // 0x0B28(0x0004)
TArray<int>                                        CustomAvatarAbilityList                                   // 0x0B30(0x0010)
int                                                ShowOtherRingBodyEffects                                  // 0x0B40(0x0004)
int                                                LastRingBodyEffects                                       // 0x0B44(0x0004)
struct FString                                     GalaxyFaceInfoIndex                                       // 0x0B48(0x0010)
Bool                                               bIsClothExtraWingVisible                                  // 0x0B58(0x0001)
Bool                                               bIsClothExtraWingVisible_OnlyTeam                         // 0x0B59(0x0001)
Bool                                               bIsBackpackFightingHide                                   // 0x0B5A(0x0001)
TArray<struct FClothingUpgradeDatas>               ClothingUpgradeDatas                                      // 0x0B60(0x0010)
int                                                ClothingUpgradeShowCondition                              // 0x0B70(0x0004)
TArray<struct FGameModePlayerItem>                 ResearchAbilityList                                       // 0x0B78(0x0010)
TArray<struct FBackpackItemParams>                 BigWorldItemList                                          // 0x0B88(0x0010)
TArray<struct FBackpackItemAdditionPropertiesParams> ItemAdditionPropertiesList                                // 0x0B98(0x0010)
struct FDSBigWorldTaskBaseInfo                     BigWorldTaskInfo                                          // 0x0BA8(0x0018)
TArray<struct FGameModePlayerItem>                 BigWorldToBattleRoyaleItemList                            // 0x0BC0(0x0010)
TMap<int, int>                                     GenItemsTakeOutLimitMap                                   // 0x0BD0(0x0050)
struct FBigWorldTitleInfo                          BigWorldTitleInfo                                         // 0x0C20(0x0004)
Bool                                               bEnableSuperHumanCampSkillMonitor                         // 0x0C24(0x0001)
struct FVector                                     LeaveScenePos                                             // 0x0C28(0x000C)
int                                                HideScore                                                 // 0x0C34(0x0004)
float                                              MilitarySupPoint                                          // 0x0C38(0x0004)
int                                                CombatDroneRewardPoint                                    // 0x0C3C(0x0004)
int                                                CombatDroneRewardPointToday                               // 0x0C40(0x0004)
int                                                CollectScoreLevel                                         // 0x0C44(0x0004)
Bool                                               bCanHost                                                  // 0x0C48(0x0001)
int                                                HostCount                                                 // 0x0C4C(0x0004)
Bool                                               EnableNewFPPMode                                          // 0x0C50(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.BigWorldTitleInfo
// 0x0004
struct FBigWorldTitleInfo
{
int                                                CurTitle                                                  // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.GameModePlayerItem
// 0x000C
struct FGameModePlayerItem
{
int                                                ItemTableID                                               // 0x0000(0x0004)
int                                                Count                                                     // 0x0004(0x0004)
int                                                ParentTableID                                             // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.DSBigWorldTaskBaseInfo
// 0x0018
struct FDSBigWorldTaskBaseInfo
{
TArray<struct FBigWorldTaskBaseParams>             TaskList                                                  // 0x0000(0x0010)
Bool                                               bIsSwitchDS                                               // 0x0010(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.BigWorldTaskBaseParams
// 0x0040
struct FBigWorldTaskBaseParams
{
int64_t                                            TaskID                                                    // 0x0000(0x0008)
Bool                                               IsExpired                                                 // 0x0008(0x0001)
Bool                                               NeedReset                                                 // 0x0009(0x0001)
Bool                                               LobbyCompleted                                            // 0x000A(0x0001)
int64_t                                            Progress                                                  // 0x0010(0x0008)
int                                                Group                                                     // 0x0018(0x0004)
TArray<int>                                        BinData                                                   // 0x0020(0x0010)
TArray<struct FBigWorldCrossDSTaskParams>          CrossDSInfo                                               // 0x0030(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.BigWorldCrossDSTaskParams
// 0x0018
struct FBigWorldCrossDSTaskParams
{
int64_t                                            TaskID                                                    // 0x0000(0x0008)
int64_t                                            Progress                                                  // 0x0008(0x0008)
int64_t                                            TargetProgress                                            // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.BackpackItemAdditionPropertiesParams
// 0x0020
struct FBackpackItemAdditionPropertiesParams
{
uint64_t                                           InstanceID                                                // 0x0000(0x0008)
int                                                ItemID                                                    // 0x0008(0x0004)
struct FName                                       Name                                                      // 0x0010(0x0008)
unsigned char                                      ValueType                                                 // 0x0018(0x0001)
float                                              FloatValue                                                // 0x001C(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.BackpackItemParams
// 0x0020
struct FBackpackItemParams
{
uint64_t                                           InstanceID                                                // 0x0000(0x0008)
int                                                ItemID                                                    // 0x0008(0x0004)
int                                                Count                                                     // 0x000C(0x0004)
int                                                ValidHours                                                // 0x0010(0x0004)
int                                                ExpireTime                                                // 0x0014(0x0004)
unsigned char                                      IsNew                                                     // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.ClothingUpgradeDatas
// 0x0010
struct FClothingUpgradeDatas
{
int                                                ParentID                                                  // 0x0000(0x0004)
int                                                SlotType                                                  // 0x0004(0x0004)
int                                                ID                                                        // 0x0008(0x0004)
int                                                HandleSlotID                                              // 0x000C(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.LargeAircraftData
// 0x0028
struct FLargeAircraftData
{
int                                                BaseID                                                    // 0x0000(0x0004)
int                                                DanceID                                                   // 0x0004(0x0004)
int                                                ColorID                                                   // 0x0008(0x0004)
struct FString                                     PlaneName                                                 // 0x0010(0x0010)
int                                                FuelNum                                                   // 0x0020(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.ConsumeRankPlayerInfo
// 0x0068
struct FConsumeRankPlayerInfo
{
struct FRankPlayerInfo                             my_rank_info                                              // 0x0000(0x0018)
TMap<int64_t, struct FRankPlayerInfo>              my_rank_friends                                           // 0x0018(0x0050)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.RankPlayerInfo
// 0x0018
struct FRankPlayerInfo
{
Bool                                               is_anonymous                                              // 0x0000(0x0001)
Bool                                               is_hide                                                   // 0x0001(0x0001)
int                                                score                                                     // 0x0004(0x0004)
int                                                rank_no                                                   // 0x0008(0x0004)
int                                                province_id                                               // 0x000C(0x0004)
int64_t                                            UID                                                       // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.WeaponSkinEffectResearchMisc
// 0x0004
struct FWeaponSkinEffectResearchMisc
{
int                                                acc_kill_counter                                          // 0x0000(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.PlayerStageBattleRecord
// 0x0048
struct FPlayerStageBattleRecord
{
float                                              TotalHurt                                                 // 0x0000(0x0004)
int                                                MaxSegmentLevel                                           // 0x0004(0x0004)
int                                                TeamLiked                                                 // 0x0008(0x0004)
float                                              TotalKD                                                   // 0x000C(0x0004)
int                                                TotalAssist                                               // 0x0010(0x0004)
int                                                MaxHurt                                                   // 0x0014(0x0004)
int                                                MaxKill                                                   // 0x0018(0x0004)
int                                                TotalKill                                                 // 0x001C(0x0004)
int                                                MaxPeakSegmentLevel                                       // 0x0020(0x0004)
int                                                SeasonSize                                                // 0x0024(0x0004)
int                                                TotalWin                                                  // 0x0028(0x0004)
int                                                TotalPlayTime                                             // 0x002C(0x0004)
int                                                TotalGameNum                                              // 0x0030(0x0004)
int                                                FriendNum                                                 // 0x0034(0x0004)
int64_t                                            FirstKingGetTime                                          // 0x0038(0x0008)
int64_t                                            TimeFromRegister                                          // 0x0040(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.PlayerClubTeamInfo
// 0x0028
struct FPlayerClubTeamInfo
{
int                                                TeamID                                                    // 0x0000(0x0004)
struct FString                                     ClubTeamName                                              // 0x0008(0x0010)
struct FString                                     ClubTeamLogo                                              // 0x0018(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.PlayerPetInfo
// 0x000C
struct FPlayerPetInfo
{
int                                                PetID                                                     // 0x0000(0x0004)
Bool                                               Park_Visible                                              // 0x0004(0x0001)
Bool                                               Park_Teammate_Visible                                     // 0x0005(0x0001)
int                                                PetLevel                                                  // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.UGCPlayerInfo
// 0x0078
struct FUGCPlayerInfo
{
int                                                MatchRank                                                 // 0x0000(0x0004)
int                                                VIPLevel                                                  // 0x0004(0x0004)
struct FUGCSeasonRankInfo                          SeasonRankInfo                                            // 0x0008(0x0010)
TMap<int, struct FUGCPlayerAchievementInfo>        AchievementInfoList                                       // 0x0018(0x0050)
TArray<struct FUGCPlayerCustomInfo>                CustomInfoList                                            // 0x0068(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.UGCPlayerCustomInfo
// 0x0018
struct FUGCPlayerCustomInfo
{
struct FString                                     PropKey                                                   // 0x0000(0x0010)
float                                              PropValue                                                 // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.UGCPlayerAchievementInfo
// 0x0008
struct FUGCPlayerAchievementInfo
{
int                                                AchievementID                                             // 0x0000(0x0004)
int                                                AchievementCount                                          // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.UGCSeasonRankInfo
// 0x0010
struct FUGCSeasonRankInfo
{
int                                                SeasonID                                                  // 0x0000(0x0004)
int                                                RankID                                                    // 0x0004(0x0004)
int                                                LastRankRate                                              // 0x0008(0x0004)
int                                                CurrentRankRate                                           // 0x000C(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.WingManInfo
// 0x0058
struct FWingManInfo
{
int                                                CurrentWingManID                                          // 0x0000(0x0004)
struct FString                                     CurrentWingManName                                        // 0x0008(0x0010)
Bool                                               bFuelNotEnoughHint                                        // 0x0018(0x0001)
Bool                                               bFuelSwitch                                               // 0x0019(0x0001)
TArray<struct FWingManFuelInfo>                    FuelInfoList                                              // 0x0020(0x0010)
Bool                                               bDisplayWingMan                                           // 0x0030(0x0001)
int                                                WingPlaneCallerID                                         // 0x0034(0x0004)
TArray<int>                                        EquippedWingmanEffects                                    // 0x0038(0x0010)
TArray<struct FWingManFuelInfo>                    EffectsFuelInfoList                                       // 0x0048(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.WingManFuelInfo
// 0x0008
struct FWingManFuelInfo
{
int                                                FuelID                                                    // 0x0000(0x0004)
int                                                FuelNum                                                   // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.PlayerPeakInfo
// 0x0048
struct FPlayerPeakInfo
{
int                                                LastPeakMatchScore                                        // 0x0000(0x0004)
int                                                LastPeakKillScore                                         // 0x0004(0x0004)
int                                                LastPeakRankScore                                         // 0x0008(0x0004)
int                                                LastPeakRank                                              // 0x000C(0x0004)
int                                                LastPeakKillNum                                           // 0x0010(0x0004)
int                                                PeakSegmentLevel                                          // 0x0014(0x0004)
struct FString                                     TeamName                                                  // 0x0018(0x0010)
Bool                                               bIsTeamLeader                                             // 0x0028(0x0001)
int64_t                                            JoinTeamTime                                              // 0x0030(0x0008)
struct FString                                     TeamLogoID                                                // 0x0038(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.PromotionMatchInfo
// 0x0018
struct FPromotionMatchInfo
{
int                                                TaskID                                                    // 0x0000(0x0004)
int                                                Status                                                    // 0x0004(0x0004)
int                                                Progress                                                  // 0x0008(0x0004)
int                                                TargetProgress                                            // 0x000C(0x0004)
int                                                CurSegmentLevel                                           // 0x0010(0x0004)
int                                                SegmentLevelNum                                           // 0x0014(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.PlayerCharmInfo
// 0x0010
struct FPlayerCharmInfo
{
int                                                CharmValue                                                // 0x0000(0x0004)
int                                                CharmLevel                                                // 0x0004(0x0004)
int                                                SeasonID                                                  // 0x0008(0x0004)
Bool                                               AllowViewCharmValue                                       // 0x000C(0x0001)
Bool                                               AllowOtherViewCharmValue                                  // 0x000D(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.CommonFlagData
// 0x0018
struct FCommonFlagData
{
struct FName                                       FlagName                                                  // 0x0000(0x0008)
struct FName                                       FlagValue                                                 // 0x0008(0x0008)
int                                                SceneFlagID                                               // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.PrivacyProtectDetail
// 0x0020
struct FPrivacyProtectDetail
{
unsigned char                                      PlatformGenderVisible                                     // 0x0000(0x0001)
unsigned char                                      SegmentTimesVisible                                       // 0x0001(0x0001)
TArray<uint64_t>                                   FriendList                                                // 0x0008(0x0010)
Bool                                               bDataReady                                                // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.AchievementPrize
// 0x0040
struct FAchievementPrize
{
TArray<int>                                        AnimationList                                             // 0x0000(0x0010)
TArray<int>                                        MedalList                                                 // 0x0010(0x0010)
TArray<int>                                        NotifyTitleList                                           // 0x0020(0x0010)
TArray<int>                                        BulleEffectList                                           // 0x0030(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.ThemePlayerWeaponConfig
// 0x0028
struct FThemePlayerWeaponConfig
{
int                                                WeaponSettingKey                                          // 0x0000(0x0004)
struct FPlayerWeaponsConfig                        WeaponsConfig                                             // 0x0008(0x0020)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.PlayerWeaponsConfig
// 0x0020
struct FPlayerWeaponsConfig
{
struct FString                                     ConfigName                                                // 0x0000(0x0010)
TArray<struct FSingleWeaponConfig>                 WeaponDataList                                            // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.SingleWeaponConfig
// 0x0018
struct FSingleWeaponConfig
{
int                                                WeaponID                                                  // 0x0000(0x0004)
TArray<int>                                        AttachmentIDList                                          // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.PlayerTotalWeaponsConfig
// 0x0018
struct FPlayerTotalWeaponsConfig
{
int                                                DefaultSelectedIndex                                      // 0x0000(0x0004)
TArray<struct FPlayerWeaponsConfig>                WeaponsConfigList                                         // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.WeaponLobbyInitialData
// 0x0010
struct FWeaponLobbyInitialData
{
TArray<int>                                        BulletTrackSkinList                                       // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.DeadBoxItem
// 0x0010
struct FDeadBoxItem
{
int                                                item_id                                                   // 0x0000(0x0004)
int                                                cur_count                                                 // 0x0004(0x0004)
int                                                total_count                                               // 0x0008(0x0004)
int                                                weight                                                    // 0x000C(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.SpecialPickItem
// 0x0010
struct FSpecialPickItem
{
int                                                task_id                                                   // 0x0000(0x0004)
int                                                item_id                                                   // 0x0004(0x0004)
int                                                cur_count                                                 // 0x0008(0x0004)
int                                                total_count                                               // 0x000C(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.GameModePlayerBanChat
// 0x0020
struct FGameModePlayerBanChat
{
int                                                end_time                                                  // 0x0000(0x0004)
struct FString                                     Reason                                                    // 0x0008(0x0010)
int                                                ban_type                                                  // 0x0018(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.PlayerOBInfo
// 0x01B8
struct FPlayerOBInfo
{
Bool                                               IsEnableOB                                                // 0x0000(0x0001)
Bool                                               bIsMLAI                                                   // 0x0001(0x0001)
uint64_t                                           UID                                                       // 0x0008(0x0008)
struct FString                                     UIDString                                                 // 0x0010(0x0010)
uint32_t                                           PlayerKey                                                 // 0x0020(0x0004)
int                                                SegmentLevel                                              // 0x0024(0x0004)
int                                                BattleMode                                                // 0x0028(0x0004)
Bool                                               ValidBattleInfo                                           // 0x002C(0x0001)
int                                                GameCount                                                 // 0x0030(0x0004)
int                                                WinCount                                                  // 0x0034(0x0004)
int                                                TopTenCount                                               // 0x0038(0x0004)
int                                                KillNum                                                   // 0x003C(0x0004)
float                                              KDNum                                                     // 0x0040(0x0004)
int                                                Title_Type                                                // 0x0044(0x0004)
int                                                Title_RankID                                              // 0x0048(0x0004)
int                                                Title_RankType                                            // 0x004C(0x0004)
int                                                Title_RankNo                                              // 0x0050(0x0004)
int                                                TopSegmentTime                                            // 0x0054(0x0004)
int                                                TopSegmentShowTag                                         // 0x0058(0x0004)
int                                                SpSegmentLevelNum                                         // 0x005C(0x0004)
int                                                CurModeRating                                             // 0x0060(0x0004)
int                                                RatingScoreDiffID                                         // 0x0064(0x0004)
struct FGameModePlayer_WearInfo                    OBPlayerWearInfo                                          // 0x0068(0x00F0)
struct FGameModePlayer_BattlePrepareDisplayWearInfo OBPlayerBattlePrepareDisplayWearInfo                      // 0x0158(0x0050)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.GameModePlayer_BattlePrepareDisplayWearInfo
// 0x0050
struct FGameModePlayer_BattlePrepareDisplayWearInfo
{
TArray<int>                                        DisplayWearAvatarInfoList                                 // 0x0000(0x0010)
TArray<int>                                        DisplayWearWeaponInfoList                                 // 0x0010(0x0010)
TArray<int>                                        DisplayWearBackpackInfoList                               // 0x0020(0x0010)
TArray<int>                                        DisplayWearHelmetInfoList                                 // 0x0030(0x0010)
TArray<int>                                        DisplayVehicleInfoList                                    // 0x0040(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.GameModePlayer_WearInfo
// 0x00F0
struct FGameModePlayer_WearInfo
{
TArray<struct FGameModePlayer_WearItem>            EquipedSkinList                                           // 0x0000(0x0010)
TArray<struct FGameModePlayer_WearItem>            EquipedPendantList                                        // 0x0010(0x0010)
TArray<struct FGameModePlayer_WearItem>            WeaponPendantList                                         // 0x0020(0x0010)
TArray<struct FGameModePlayer_WearItem>            WingAvatarList                                            // 0x0030(0x0010)
TArray<struct FGameModePlayerItem>                 WeaponSkinAvatarList                                      // 0x0040(0x0010)
TArray<struct FGameModePlayerItem>                 WeaponSkinAbilityList                                     // 0x0050(0x0010)
TArray<struct FGameModePlayerItem>                 WeaponAttachmentAvatarList                                // 0x0060(0x0010)
TArray<struct FGameModePlayerItem>                 VehicleSkinAvatarList                                     // 0x0070(0x0010)
TArray<struct FGameModePlayerItem>                 VehicleSkinAbilityList                                    // 0x0080(0x0010)
TArray<struct FGameModePlayer_ItemExtraInfo>       VehiclePendantInfoList                                    // 0x0090(0x0010)
TArray<struct FGameModePlayer_ItemExtraInfo>       DisplayVehiclePendantInfoList                             // 0x00A0(0x0010)
TArray<struct FGameModePlayerItem>                 DisplayVehicleSkinAbilityList                             // 0x00B0(0x0010)
TArray<struct FGameModePlayerItem>                 CharacterAvatarAbilityList                                // 0x00C0(0x0010)
TArray<struct FGameModePlayer_ItemCustomName>      ItemCustomNameList                                        // 0x00D0(0x0010)
TArray<struct FGameModePlayerItem>                 TombBoxAvatarList                                         // 0x00E0(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.GameModePlayer_ItemCustomName
// 0x0028
struct FGameModePlayer_ItemCustomName
{
int                                                ItemID                                                    // 0x0000(0x0004)
struct FString                                     CustomName                                                // 0x0008(0x0010)
struct FString                                     CustomNum                                                 // 0x0018(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.GameModePlayer_ItemExtraInfo
// 0x0018
struct FGameModePlayer_ItemExtraInfo
{
int                                                ItemID                                                    // 0x0000(0x0004)
TArray<int>                                        ItemPendantList                                           // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.GameModePlayer_WearItem
// 0x0008
struct FGameModePlayer_WearItem
{
int                                                WearPart_ItemID                                           // 0x0000(0x0004)
int                                                WearItemID                                                // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.GameModePlayerTaskData
// 0x0048
struct FGameModePlayerTaskData
{
int                                                task_id                                                   // 0x0000(0x0004)
int                                                process                                                   // 0x0004(0x0004)
int                                                week_index                                                // 0x0008(0x0004)
Bool                                               is_traced                                                 // 0x000C(0x0001)
Bool                                               is_mode_fit                                               // 0x000D(0x0001)
int                                                TaskType                                                  // 0x0010(0x0004)
int                                                TargetProcess                                             // 0x0014(0x0004)
struct FString                                     TaskParam1                                                // 0x0018(0x0010)
struct FString                                     TaskParam2                                                // 0x0028(0x0010)
struct FString                                     ext_info                                                  // 0x0038(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.WeaponModData
// 0x0018
struct FWeaponModData
{
int                                                ModeID                                                    // 0x0000(0x0004)
TArray<struct FWeaponModificationData>             WeaponModificationDataList                                // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.WeaponModificationData
// 0x0018
struct FWeaponModificationData
{
int                                                WeaponID                                                  // 0x0000(0x0004)
TArray<int>                                        ModuleList                                                // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.SuitSkinData
// 0x0030
struct FSuitSkinData
{
Bool                                               Open                                                      // 0x0000(0x0001)
TArray<struct FStyleUnit>                          SuitSkinList                                              // 0x0008(0x0010)
TArray<struct FGlidSkinUnit>                       GlidSkinList                                              // 0x0018(0x0010)
int                                                SuitDefaultHeadID                                         // 0x0028(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.GlidSkinUnit
// 0x0018
struct FGlidSkinUnit
{
int                                                glid_item_id                                              // 0x0000(0x0004)
TArray<struct FGlidCost>                           cost_list                                                 // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.GlidCost
// 0x000C
struct FGlidCost
{
int                                                cost_item_id                                              // 0x0000(0x0004)
int                                                cost_count                                                // 0x0004(0x0004)
int                                                own_count                                                 // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.StyleUnit
// 0x0110
struct FStyleUnit
{
int                                                stype_type                                                // 0x0000(0x0004)
int                                                Slot                                                      // 0x0004(0x0004)
int                                                style_id                                                  // 0x0008(0x0004)
Bool                                               lock                                                      // 0x000C(0x0001)
TArray<struct FGameModePlayerItem>                 ItemList                                                  // 0x0010(0x0010)
struct FGameModePlayer_WearInfo                    wearInfo                                                  // 0x0020(0x00F0)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.DynamicBattleRankInfo
// 0x0030
struct FDynamicBattleRankInfo
{
int                                                BattleRank                                                // 0x0000(0x0004)
uint64_t                                           PlayerUID                                                 // 0x0008(0x0008)
int                                                RevivalTimes                                              // 0x0010(0x0004)
TArray<int64_t>                                    KillerUIDs                                                // 0x0018(0x0010)
int                                                DeadTimes                                                 // 0x0028(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.TrainingStatisticsData
// 0x0030
struct FTrainingStatisticsData
{
TArray<struct FTrainingStatisticsItem>             ItemList                                                  // 0x0000(0x0010)
TArray<struct FTrainingStatisticsItem_Int32>       Int32ItemList                                             // 0x0010(0x0010)
TArray<struct FTrainingStatisticsItem_Int64>       Int64ItemList                                             // 0x0020(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.TrainingStatisticsItem_Int64
// 0x0018
struct FTrainingStatisticsItem_Int64
{
struct FString                                     ItemName                                                  // 0x0000(0x0010)
uint64_t                                           ItemValue                                                 // 0x0010(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.TrainingStatisticsItem_Int32
// 0x0018
struct FTrainingStatisticsItem_Int32
{
struct FString                                     ItemName                                                  // 0x0000(0x0010)
int                                                ItemValue                                                 // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.TrainingStatisticsItem
// 0x0018
struct FTrainingStatisticsItem
{
struct FString                                     ItemName                                                  // 0x0000(0x0010)
float                                              ItemValue                                                 // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct GameAttributeExtend.ExtraDamageCalculationResult
// 0x0010
struct FExtraDamageCalculationResult
{
TArray<struct FGameplayTag>                        ResultTags                                                // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.CollectedEventDataInfo
// 0x0010
struct FCollectedEventDataInfo
{
uint64_t                                           CollectingEventDataRequiredUId                            // 0x0000(0x0008)
int                                                CollectedEventType                                        // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.GameModeCollectedEventTeamParams
// 0x0020
struct FGameModeCollectedEventTeamParams
{
int                                                TeamID                                                    // 0x0000(0x0004)
TArray<int>                                        UIDs                                                      // 0x0008(0x0010)
Bool                                               bCollectedEventDataReportingEnabled                       // 0x0018(0x0001)
int                                                CollectedEventType                                        // 0x001C(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.IDIPStateInfo
// 0x0020
struct FIDIPStateInfo
{
int                                                ActivityActorID                                           // 0x0000(0x0004)
int                                                BeginTime                                                 // 0x0004(0x0004)
int                                                EndTime                                                   // 0x0008(0x0004)
struct FString                                     Params                                                    // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.GameModeMatchGoalAchievedData
// 0x0008
struct FGameModeMatchGoalAchievedData
{
int                                                RemainAlivePlayerCount                                    // 0x0000(0x0004)
int                                                GamePlayingTime                                           // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.GameModeTeamBattleResultData
// 0x0170
struct FGameModeTeamBattleResultData
{
struct FString                                     Reason                                                    // 0x0000(0x0010)
int                                                RemainTeamCount                                           // 0x0010(0x0004)
int                                                RemainAlivePlayerCount                                    // 0x0014(0x0004)
TMap<struct FString, struct FString>               PlayersLogoutTime                                         // 0x0018(0x0050)
TArray<struct FGameModeCorpsDetailData>            RealTimeCorpsRank                                         // 0x0068(0x0010)
Bool                                               bIsGameTerminator                                         // 0x0078(0x0001)
TMap<uint64_t, struct FRevengeEvent>               RevengeEventList                                          // 0x0080(0x0050)
TMap<uint64_t, int>                                type_chat_count                                           // 0x00D0(0x0050)
TMap<uint64_t, struct FBattleResultGenItemData>    GenItems                                                  // 0x0120(0x0050)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.BattleResultGenItemData
// 0x0050
struct FBattleResultGenItemData
{
TMap<int, struct FBackpackLobbyItem>               item_map                                                  // 0x0000(0x0050)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.BackpackLobbyItem
// 0x0058
struct FBackpackLobbyItem
{
int                                                Count                                                     // 0x0000(0x0004)
TMap<uint64_t, struct FBackpackLobbySenderItem>    senders                                                   // 0x0008(0x0050)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.BackpackLobbySenderItem
// 0x0020
struct FBackpackLobbySenderItem
{
int                                                Count                                                     // 0x0000(0x0004)
struct FBackpackLobbySenderItemExtra               extra                                                     // 0x0008(0x0018)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.BackpackLobbySenderItemExtra
// 0x0018
struct FBackpackLobbySenderItemExtra
{
int                                                plane_id                                                  // 0x0000(0x0004)
struct FString                                     plane_name                                                // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.RevengeEvent
// 0x0050
struct FRevengeEvent
{
TMap<uint64_t, uint16_t>                           IRevengedWhom                                             // 0x0000(0x0050)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.GameModeCorpsDetailData
// 0x0030
struct FGameModeCorpsDetailData
{
struct FString                                     Name                                                      // 0x0000(0x0010)
int                                                CorpsHeadIcon                                             // 0x0010(0x0004)
int                                                KilledNum                                                 // 0x0014(0x0004)
int                                                SegmentLevel                                              // 0x0018(0x0004)
int                                                RealtimeRank                                              // 0x001C(0x0004)
int                                                DefeatPlayerNum                                           // 0x0020(0x0004)
float                                              TotalDamage                                               // 0x0024(0x0004)
float                                              SurvivalTime                                              // 0x0028(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.DSCorpsInfo
// 0x0020
struct FDSCorpsInfo
{
uint64_t                                           CorpsID                                                   // 0x0000(0x0008)
struct FString                                     CorpsName                                                 // 0x0008(0x0010)
int                                                Icon                                                      // 0x0018(0x0004)
int                                                SegmentLevel                                              // 0x001C(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.IDIPChildActorConfig
// 0x0018
struct FIDIPChildActorConfig
{
int                                                Tag                                                       // 0x0000(0x0004)
struct FString                                     ClassPath                                                 // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.ObjectPoolReservation
// 0x0018
struct FObjectPoolReservation
{
class UClass*                                      ObjectClass                                               // 0x0000(0x0008)
EFeatureSetType                                    FeatureSetType                                            // 0x0008(0x0001)
int                                                MinNumOverride                                            // 0x000C(0x0004)
int                                                MaxNumOverride                                            // 0x0010(0x0004)
float                                              AllocateObjectGapTimeOverride                             // 0x0014(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.CakeInfo
// 0x0020
struct FCakeInfo
{
struct FString                                     CakeActorPath                                             // 0x0000(0x0010)
struct FString                                     CakeButtonImage                                           // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.CompetitionDisplayLevelCfg
// 0x0018
struct FCompetitionDisplayLevelCfg
{
struct FString                                     LevelPath                                                 // 0x0000(0x0010)
int                                                ID                                                        // 0x0010(0x0004)
Bool                                               bOnlyVisibleToObserver                                    // 0x0014(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.ReplaceTextureURLCfg
// 0x0018
struct FReplaceTextureURLCfg
{
struct FString                                     URL                                                       // 0x0000(0x0010)
int                                                ID                                                        // 0x0010(0x0004)
Bool                                               bOnlyVisibleToObserver                                    // 0x0014(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.AdvertisementActorConfig
// 0x0050
struct FAdvertisementActorConfig
{
int                                                ID                                                        // 0x0000(0x0004)
struct FString                                     resPath                                                   // 0x0008(0x0010)
struct FString                                     HttpImgPath                                               // 0x0018(0x0010)
struct FVector                                     Loc                                                       // 0x0028(0x000C)
struct FRotator                                    Rot                                                       // 0x0034(0x000C)
struct FVector                                     Scale                                                     // 0x0040(0x000C)
Bool                                               HideWhenFighting                                          // 0x004C(0x0001)
Bool                                               bAdvertisementOnlyVisibleToObserver                       // 0x004D(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.PlayerStaticInfoInOB
// 0x0058
struct FPlayerStaticInfoInOB
{
struct FString                                     PlayerName                                                // 0x0000(0x0010)
struct FString                                     PlayerOpenID                                              // 0x0010(0x0010)
struct FString                                     PicUrl                                                    // 0x0020(0x0010)
int                                                TeamID                                                    // 0x0030(0x0004)
unsigned char                                      IdxInTeam                                                 // 0x0034(0x0001)
uint32_t                                           PlayerKey                                                 // 0x0038(0x0004)
struct FString                                     PlayerUID                                                 // 0x0040(0x0010)
int                                                JumpSegmentID                                             // 0x0050(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.DropdownSchemeData
// 0x0028
struct FDropdownSchemeData
{
int                                                SchemeId                                                  // 0x0000(0x0004)
int                                                ItemID                                                    // 0x0004(0x0004)
struct FString                                     ItemName                                                  // 0x0008(0x0010)
int                                                MaxNum                                                    // 0x0018(0x0004)
int                                                MinNum                                                    // 0x001C(0x0004)
int                                                Probability                                               // 0x0020(0x0004)
unsigned char                                      DropType                                                  // 0x0024(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.RouteSegment
// 0x0020
struct FRouteSegment
{
int                                                Index                                                     // 0x0000(0x0004)
struct FString                                     SegmentName                                               // 0x0008(0x0010)
float                                              StartRatio                                                // 0x0018(0x0004)
float                                              EndRatio                                                  // 0x001C(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.SpawnZombieActiveMaxCfg
// 0x0018
struct FSpawnZombieActiveMaxCfg
{
struct FString                                     Name                                                      // 0x0000(0x0010)
int                                                Max                                                       // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.InstanceBaseInfo
// 0x0010
struct FInstanceBaseInfo
{
uint64_t                                           InstanceID                                                // 0x0000(0x0008)
int                                                NumPlayers                                                // 0x0008(0x0004)
float                                              NoPlayerTimer                                             // 0x000C(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.InstancePlayerInfo
// 0x0018
struct FInstancePlayerInfo
{
uint64_t                                           InstanceID                                                // 0x0000(0x0008)
uint64_t                                           UID                                                       // 0x0008(0x0008)
uint32_t                                           PlayerKey                                                 // 0x0010(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.ViewTargetTransitionParams
// 0x0010
struct FViewTargetTransitionParams
{
float                                              BlendTime                                                 // 0x0000(0x0004)
unsigned char                                      BlendFunction                                             // 0x0004(0x0001)
float                                              BlendExp                                                  // 0x0008(0x0004)
Bool                                               bLockOutgoing                                             // 0x000C(0x0001)
Bool                                               bLockLocation                                             // 0x000C(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.LevelIndexVisibilityInfo
// 0x0008
struct FLevelIndexVisibilityInfo
{
Bool                                               Visible                                                   // 0x0000(0x0001)
int                                                MappingIndex                                              // 0x0004(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.LevelVisibilityInfo
// 0x0010
struct FLevelVisibilityInfo
{
Bool                                               Visible                                                   // 0x0000(0x0001)
struct FName                                       PackageName                                               // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.ActionCluster
// 0x0018
struct FActionCluster
{
int                                                ClusterID                                                 // 0x0000(0x0004)
TArray<struct FName>                               ClusterActionNames                                        // 0x0008(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.ActiveForceFeedbackEffect
// 0x0018
struct FActiveForceFeedbackEffect
{
class UForceFeedbackEffect*                        ForceFeedbackEffect                                       // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.FastArraySerializerItem
// 0x000C
struct FFastArraySerializerItem
{
int                                                ReplicationID                                             // 0x0000(0x0004)
int                                                ReplicationKey                                            // 0x0004(0x0004)
int                                                MostRecentArrayReplicationKey                             // 0x0008(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct Basic.FastRemoteReplicationBridge
// 0x00A4 (0x00B0 - 0x000C)
struct FFastRemoteReplicationBridge : public FFastArraySerializerItem
{
TWeakObjectPtr<class UNetDriver>                   NetDriver                                                 // 0x000C(0x0008)
class AActor*                                      TargetActor                                               // 0x0020(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.FastRepRemoteContent
// 0x0040
struct FFastRepRemoteContent
{
uint16_t                                           ContentBlockCount                                         // 0x0000(0x0002)
uint16_t                                           ContentNumBytes                                           // 0x0002(0x0002)
TArray<unsigned char>                              Content                                                   // 0x0008(0x0010)
TArray<class UObject*>                             ObjPtrs                                                   // 0x0018(0x0010)
struct FString                                     DebugInfo                                                 // 0x0028(0x0010)
uint16_t                                           DSFrameCounter                                            // 0x0038(0x0002)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.TestFastRep
// 0x0010
struct FTestFastRep
{
int                                                P1                                                        // 0x0000(0x0004)
float                                              P2                                                        // 0x0004(0x0004)
class AActor*                                      P3                                                        // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.TestFastRep_Custom
// 0x0010
struct FTestFastRep_Custom
{
int                                                P1                                                        // 0x0000(0x0004)
float                                              P2                                                        // 0x0004(0x0004)
class AActor*                                      P3                                                        // 0x0008(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct Engine.TestFastRep_Composite
// 0x0020
struct FTestFastRep_Composite
{
int                                                P1                                                        // 0x0000(0x0004)
float                                              P2                                                        // 0x0004(0x0004)
class AActor*                                      P3                                                        // 0x0008(0x0008)
struct FTestFastRep                                P4                                                        // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.CollectedEventKeysValues
// 0x0020
struct FCollectedEventKeysValues
{
TArray<struct FString>                             Keys                                                      // 0x0000(0x0010)
TArray<struct FString>                             Values                                                    // 0x0010(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.CollectedEventOnlyIntValues
// 0x0010
struct FCollectedEventOnlyIntValues
{
TArray<int>                                        IntValues                                                 // 0x0000(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.DynaConfigInfo
// 0x0020
struct FDynaConfigInfo
{
struct FString                                     ConfigName                                                // 0x0000(0x0010)
int                                                CVarHash                                                  // 0x0010(0x0004)
EDynaConfigEnum                                    Type                                                      // 0x0014(0x0001)
float                                              Value                                                     // 0x0018(0x0004)
EDynaConfigNetExecutionPolicy                      Policy                                                    // 0x001C(0x0001)
EDynaConfigOwner                                   Owner                                                     // 0x001D(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct Gameplay.PlayerOBBattleInfo
// 0x0030
struct FPlayerOBBattleInfo
{
int                                                BattleMode                                                // 0x0000(0x0004)
Bool                                               ValidBattleInfo                                           // 0x0004(0x0001)
int                                                GameCount                                                 // 0x0008(0x0004)
int                                                WinCount                                                  // 0x000C(0x0004)
int                                                TopTenCount                                               // 0x0010(0x0004)
int                                                KillNum                                                   // 0x0014(0x0004)
struct FString                                     KDNum                                                     // 0x0018(0x0010)
int                                                TopSegmentTimes                                           // 0x0028(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct SlateCore.SlateBrush
// 0x0078
struct FSlateBrush
{
struct FVector2D                                   ImageSize                                                 // 0x0008(0x0008)
struct FMargin                                     Margin                                                    // 0x0010(0x0010)
struct FSlateColor                                 TintColor                                                 // 0x0020(0x0028)
class UObject*                                     ResourceObject                                            // 0x0048(0x0008)
struct FName                                       ResourceName                                              // 0x0050(0x0008)
struct FBox2D                                      UVRegion                                                  // 0x0058(0x0014)
unsigned char                                      DrawAs                                                    // 0x006C(0x0001)
unsigned char                                      Tiling                                                    // 0x006D(0x0001)
unsigned char                                      Mirroring                                                 // 0x006E(0x0001)
unsigned char                                      ImageType                                                 // 0x006F(0x0001)
Bool                                               bUseImageSizeAsTextureSize                                // 0x0070(0x0001)
Bool                                               bIsDynamicallyLoaded                                      // 0x0070(0x0001)
Bool                                               bHasUObject                                               // 0x0070(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct SlateCore.Margin
// 0x0010
struct FMargin
{
float                                              Left                                                      // 0x0000(0x0004)
float                                              Top                                                       // 0x0004(0x0004)
float                                              Right                                                     // 0x0008(0x0004)
float                                              Bottom                                                    // 0x000C(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct UMG.WidgetTransform
// 0x001C
struct FWidgetTransform
{
struct FVector2D                                   Translation                                               // 0x0000(0x0008)
struct FVector2D                                   Scale                                                     // 0x0008(0x0008)
struct FVector2D                                   Shear                                                     // 0x0010(0x0008)
float                                              Angle                                                     // 0x0018(0x0004)
};

// 大佬QQ:2396031563
// ScriptStruct AppFramework.ColorGradientCellInfo
// 0x0018
struct FColorGradientCellInfo
{
float                                              Percent                                                   // 0x0000(0x0004)
struct FLinearColor                                ColorRGB                                                  // 0x0004(0x0010)
Bool                                               IsLocked                                                  // 0x0014(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct SlateCore.TableRowStyle
// 0x05F0 (0x05F8 - 0x0008)
struct FTableRowStyle : public FSlateWidgetStyle
{
struct FSlateBrush                                 SelectorFocusedBrush                                      // 0x0008(0x0078)
struct FSlateBrush                                 ActiveHoveredBrush                                        // 0x0080(0x0078)
struct FSlateBrush                                 ActiveBrush                                               // 0x00F8(0x0078)
struct FSlateBrush                                 InactiveHoveredBrush                                      // 0x0170(0x0078)
struct FSlateBrush                                 InactiveBrush                                             // 0x01E8(0x0078)
struct FSlateBrush                                 EvenRowBackgroundHoveredBrush                             // 0x0260(0x0078)
struct FSlateBrush                                 EvenRowBackgroundBrush                                    // 0x02D8(0x0078)
struct FSlateBrush                                 OddRowBackgroundHoveredBrush                              // 0x0350(0x0078)
struct FSlateBrush                                 OddRowBackgroundBrush                                     // 0x03C8(0x0078)
struct FSlateColor                                 TextColor                                                 // 0x0440(0x0028)
struct FSlateColor                                 SelectedTextColor                                         // 0x0468(0x0028)
struct FSlateBrush                                 DropIndicator_Above                                       // 0x0490(0x0078)
struct FSlateBrush                                 DropIndicator_Onto                                        // 0x0508(0x0078)
struct FSlateBrush                                 DropIndicator_Below                                       // 0x0580(0x0078)
};

// 大佬QQ:2396031563
// ScriptStruct SlateCore.ComboBoxStyle
// 0x0330 (0x0338 - 0x0008)
struct FComboBoxStyle : public FSlateWidgetStyle
{
struct FComboButtonStyle                           ComboButtonStyle                                          // 0x0008(0x0320)
struct FSlateSound                                 PressedSlateSound                                         // 0x0328(0x0008)
struct FSlateSound                                 SelectionChangeSlateSound                                 // 0x0330(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct SlateCore.SlateSound
// 0x0008
struct FSlateSound
{
class UObject*                                     ResourceObject                                            // 0x0000(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct SlateCore.ComboButtonStyle
// 0x0318 (0x0320 - 0x0008)
struct FComboButtonStyle : public FSlateWidgetStyle
{
struct FButtonStyle                                ButtonStyle                                               // 0x0008(0x0218)
struct FSlateBrush                                 DownArrowImage                                            // 0x0220(0x0078)
struct FSlateBrush                                 MenuBorderBrush                                           // 0x0298(0x0078)
struct FMargin                                     MenuBorderPadding                                         // 0x0310(0x0010)
};

// 大佬QQ:2396031563
// ScriptStruct SlateCore.ButtonStyle
// 0x0210 (0x0218 - 0x0008)
struct FButtonStyle : public FSlateWidgetStyle
{
struct FSlateBrush                                 Normal                                                    // 0x0008(0x0078)
struct FSlateBrush                                 Hovered                                                   // 0x0080(0x0078)
struct FSlateBrush                                 Pressed                                                   // 0x00F8(0x0078)
struct FSlateBrush                                 Disabled                                                  // 0x0170(0x0078)
struct FMargin                                     NormalPadding                                             // 0x01E8(0x0010)
struct FMargin                                     PressedPadding                                            // 0x01F8(0x0010)
struct FSlateSound                                 PressedSlateSound                                         // 0x0208(0x0008)
struct FSlateSound                                 HoveredSlateSound                                         // 0x0210(0x0008)
};

// 大佬QQ:2396031563
// ScriptStruct UMG.ShapedTextOptions
// 0x0008
struct FShapedTextOptions
{
Bool                                               bOverride_TextShapingMethod                               // 0x0000(0x0001)
Bool                                               bOverride_TextFlowDirection                               // 0x0000(0x0001)
ETextShapingMethod                                 TextShapingMethod                                         // 0x0004(0x0001)
ETextFlowDirection                                 TextFlowDirection                                         // 0x0005(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct SlateCore.EditableTextStyle
// 0x01E8 (0x01F0 - 0x0008)
struct FEditableTextStyle : public FSlateWidgetStyle
{
struct FSlateFontInfo                              Font                                                      // 0x0008(0x0058)
struct FSlateColor                                 ColorAndOpacity                                           // 0x0060(0x0028)
struct FSlateBrush                                 BackgroundImageSelected                                   // 0x0088(0x0078)
struct FSlateBrush                                 BackgroundImageComposing                                  // 0x0100(0x0078)
struct FSlateBrush                                 CaretImage                                                // 0x0178(0x0078)
};

// 大佬QQ:2396031563
// ScriptStruct SlateCore.EditableTextBoxStyle
// 0x0720 (0x0728 - 0x0008)
struct FEditableTextBoxStyle : public FSlateWidgetStyle
{
struct FSlateBrush                                 BackgroundImageNormal                                     // 0x0008(0x0078)
struct FSlateBrush                                 BackgroundImageHovered                                    // 0x0080(0x0078)
struct FSlateBrush                                 BackgroundImageFocused                                    // 0x00F8(0x0078)
struct FSlateBrush                                 BackgroundImageReadOnly                                   // 0x0170(0x0078)
struct FMargin                                     Padding                                                   // 0x01E8(0x0010)
struct FSlateFontInfo                              Font                                                      // 0x01F8(0x0058)
struct FSlateColor                                 ForegroundColor                                           // 0x0250(0x0028)
struct FSlateColor                                 BackgroundColor                                           // 0x0278(0x0028)
struct FSlateColor                                 ReadOnlyForegroundColor                                   // 0x02A0(0x0028)
struct FMargin                                     HScrollBarPadding                                         // 0x02C8(0x0010)
struct FMargin                                     VScrollBarPadding                                         // 0x02D8(0x0010)
struct FScrollBarStyle                             ScrollBarStyle                                            // 0x02E8(0x0440)
};

// 大佬QQ:2396031563
// ScriptStruct SlateCore.ScrollBarStyle
// 0x0438 (0x0440 - 0x0008)
struct FScrollBarStyle : public FSlateWidgetStyle
{
struct FSlateBrush                                 HorizontalBackgroundImage                                 // 0x0008(0x0078)
struct FSlateBrush                                 VerticalBackgroundImage                                   // 0x0080(0x0078)
struct FSlateBrush                                 VerticalTopSlotImage                                      // 0x00F8(0x0078)
struct FSlateBrush                                 HorizontalTopSlotImage                                    // 0x0170(0x0078)
struct FSlateBrush                                 VerticalBottomSlotImage                                   // 0x01E8(0x0078)
struct FSlateBrush                                 HorizontalBottomSlotImage                                 // 0x0260(0x0078)
struct FSlateBrush                                 NormalThumbImage                                          // 0x02D8(0x0078)
struct FSlateBrush                                 HoveredThumbImage                                         // 0x0350(0x0078)
struct FSlateBrush                                 DraggedThumbImage                                         // 0x03C8(0x0078)
};

// 大佬QQ:2396031563
// ScriptStruct Slate.InputChord
// 0x0020
struct FInputChord
{
struct FKey                                        Key                                                       // 0x0000(0x0018)
Bool                                               bShift                                                    // 0x0018(0x0001)
Bool                                               bCtrl                                                     // 0x0018(0x0001)
Bool                                               bAlt                                                      // 0x0018(0x0001)
Bool                                               bCmd                                                      // 0x0018(0x0001)
};

// 大佬QQ:2396031563
// ScriptStruct SlateCore.TextBlockStyle
// 0x01C0 (0x01C8 - 0x0008)
struct FTextBlockStyle : public FSlateWidgetStyle
{
struct FSlateFontInfo                              Font                                                      // 0x0008(0x0058)
struct FSlateColor                                 ColorAndOpacity          