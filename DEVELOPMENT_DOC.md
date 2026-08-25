# PUBG China Special Edition DMA — 完整开发文档

> **项目名称**: VEX和平DMA / PUBG-China-Special-Edition-DMA  
> **目标游戏**: 和平精英 (PUBG China) `wgprojectm.exe`  
> **技术栈**: C++20 Modules, DMA (FPGA/FTD3XX), DirectX 11 Overlay, ImGui  
> **硬件**: DMA卡 (MemProcFS/VMMDLL), KmBox/KmBoxNet/Lurker/MoBox  

---

## 目录

1. [系统架构](#系统架构)
2. [根目录文件](#一根目录核心文件)
3. [Engine模块 (引擎抽象层)](#二engine--引擎抽象层)
4. [gameixx模块 (游戏特定类)](#三gameixx--游戏特定类)
5. [PhysX3模块 (物理引擎)](#四physx3--物理引擎模块)
6. [Esp模块 (渲染)](#五esp--渲染模块)
7. [DMA驱动层](#六dma-驱动层)
8. [NetConfig (硬件盒子)](#七netconfig--硬件盒子驱动)
9. [配置文件](#八配置文件)
10. [自瞄引擎详解](#九自瞄引擎详解)
11. [ESP系统详解](#十esp系统详解)
12. [关键算法与数据流](#十一关键算法与数据流)

---

## 系统架构

```
main() [game.cpp]
  ├── dma::init()                          FPGA DMA卡初始化
  ├── m_Engine.init()                       等待游戏进程→获取基址→初始化GNames
  ├── InputDMA::Init()                      DMA键盘输入监测
  ├── PhysX3::init()                        本地物理引擎(用于可见性检测)
  ├── dx11::init()                          DX11全屏透明覆盖窗口
  ├── [线程1] read_data()                   主数据循环(UWorld→Actor分类)
  ├── [线程2] vehicle_update_thread()       载具数据更新
  ├── [线程3] item_update_thread()          物资数据更新
  ├── [线程4] dma_thread_func()             DMA散读(批量读骨骼/血量等)
  └── draw()                                DX11帧循环(ESP/自瞄/扳机/雷达)
```

**技术键路**:
1. **内存读取**: DMA FPGA卡 → VMMDLL → 游戏进程内存
2. **自瞄**: 骨骼选择 → 弹道预判 → PhysX可见性检测 → WorldToScreen像素计算 → 盒子鼠标移动
3. **压枪**: DMA写入武器实体后坐力字段为0
4. **ESP**: WorldToScreen投影 → ImGui DrawList在DX11透明窗口上绘制
5. **输入检测**: DMA读取主机键盘状态 + 副机GetAsyncKeyState双重检测
6. **配置持久化**: config.ini (INI格式)

---

## 一、根目录核心文件

### 1. `game.cpp` (主文件, ~4600行)

**作用**: 整个项目的入口和核心逻辑文件。包含main()函数、所有线程函数、ESP绘制函数、自瞄逻辑、菜单UI。

**全局变量**:

| 变量 | 类型 | 说明 |
|------|------|------|
| `g_RenderList` | `vector<AUAECharacter>` | 渲染线程共享的玩家列表 |
| `g_DataMutex` | `mutex` | 数据列表互斥锁 |
| `g_hs_esp` | `VMMDLL_SCATTER_HANDLE` | DMA散读句柄 |
| `m_Engine` | `Engine` | 游戏引擎封装(屏幕/坐标转换) |
| `g_running` | `atomic<bool>` | 运行状态标志 |
| `g_uworld` | `atomic<shared_ptr<UWorld>>` | 当前游戏世界 |
| `g_my_player` | `atomic<shared_ptr<AUAECharacter>>` | 本地玩家 |
| `g_playerList` | `atomic<shared_ptr<vector<AUAECharacter>>>` | 玩家列表 |
| `g_item_list` | `atomic<shared_ptr<vector<AActor>>>` | 物资列表 |
| `g_vehicleList` | `atomic<shared_ptr<vector<ASTExtraVehicleBase>>>` | 载具列表 |
| `g_box_type` | `int` | 盒子类型: 0=KmBoxNet, 1=KmBox COM, 2=Lurker, 3=MoBox |
| `g_box_connected` | `bool` | 盒子连接状态 |

**关键函数索引**:

| 行号 | 函数 | 功能 |
|------|------|------|
| 56 | `draw_physx_shape()` | 绘制PhysX物理形状到屏幕 |
| 572 | `read_data()` | **核心数据循环**: 读UWorld→Actors数组→分类 |
| 1058 | `draw_player_box()` | 玩家方框ESP |
| 1226 | `draw_player_info()` | 玩家信息(名字/武器/血量/距离) |
| 1539 | `draw_player_bone()` | 玩家骨骼ESP |
| 1736 | `draw_player()` | 综合玩家ESP绘制入口 |
| 2071 | `Box_Move/Click/Release/Scroll()` | 硬件盒子操作封装 |
| 2118 | `Config::Save/Load()` | INI配置文件读写 |
| 2555 | `draw_menu()` | **菜单UI**: ESP/自瞄/扳机全部设置 |
| 3507 | `draw_radar()` | 小地图雷达 |
| 3652 | `recoil_control()` | 压枪(写后坐力字段为0) |
| 3663 | `draw_trigger()` | 自动扳机(TriggerBot) |
| 3848 | `draw_aim()` | **自瞄核心** (详见第九节) |
| 4497 | `draw_shortcut_menu()` | 快捷键状态显示 |
| 4562 | `draw()` | **主渲染循环** |
| 4678 | `main()` | 程序入口 |

**依赖模块**: kmboxNet, KmBox, MoBox, Lurker, imgui, bm, dma, dx11, Engine, AActor, Struct, AUAECharacter, CanvasMap, UWorld, dx11_menu, render, PhysX3, physxEngine, ASTExtraVehicleBase, UVehicleCommonComponent, InputDMA, InputUtils, WeaponTranslation, ItemTranslation

---

### 2. `Offsets.ixx` (173行)

**作用**: 所有游戏内存偏移量定义，使用静态常量结构体组织。

**关键结构体**:
- `Offsets::Base` — 进程名`wgprojectm.exe`、GWorld/GNames/CanvasMap基址偏移
- `Offsets::UWorld` — UWorld相关偏移(PersistentLevel, NetDriver, GameInstance)
- `Offsets::ULevel` — ULevel Actor数组偏移
- `Offsets::AUAECharacter` — 玩家角色: 名字(wchar_t[])、TeamID、isAI、血量、信号值、武器、击杀数
- `Offsets::ASTExtraWeapon` — 武器: WeaponEntityComp、弹夹子弹数
- `Offsets::UWeaponEntity` — 武器实体: BulletFireSpeed(0x15CC)、重力、后坐力字段
- `Offsets::USkinnedMeshComponent` — 骨骼网格: 骨骼数组(0x9D0/0x9E0)、ComponentToWorld
- `Offsets::ASTExtraVehicleBase` — 载具: VehicleCommon组件
- `Offsets::UVehicleCommonComponent` — 载具: 血量/油量/轮胎血量

---

### 3. `Struct.ixx` (571行)

**作用**: 核心数学结构和UE4游戏结构体。

**关键结构体**:

| 结构体 | 说明 |
|--------|------|
| `FVector2D` | 2D向量(x,y) 含全部运算符重载 |
| `FVector3D` | 3D向量(x,y,z) 含GetAxes/方向轴/万向锁转换/距离 |
| `FVector` | 简化3D向量 |
| `FRotator` | UE旋转(Pitch/Yaw/Roll) |
| `FQuat` | 四元数 |
| `FTransform` | 变换(旋转+平移+缩放3D, 乘法合成) |
| `FMatrix` | 4x4矩阵(ToMatrixWithScale, GetOrigin) |
| `FCameraCacheEntry` | 相机缓存(POV位置+旋转+FOV, GetCameraForwardLocation) |
| `FMinimalViewInfo` | 最小视图信息 |
| `FBoxSphereBounds` | 包围盒(GetBoxCorners) |

---

### 4. `dx11_menu.ixx` (206行)

**作用**: 所有功能的开关和参数配置，使用静态内联变量。

**配置分类**:

| 分类 | 关键参数 |
|------|---------|
| `esp` | 骨骼/方框/名字/武器/距离/血量/能量/击杀数/射线/警告/颜色 |
| `aim` | FOV(fov)/平滑(smooth)/距离(dist)/预测(prediction)/可视检测(vis_check)/模拟真人(humanize)/持续锁定(auto_lock)/开火自瞄(fire_aim)/静默(silent_aim) |
| `trigger` | 自动开火/FOV/延迟/与自瞄联动(aim_sync) |
| `shortcut` | 菜单切换键/融合模式键/自瞄开关键 |

---

### 5. `InputDMA.ixx` (328行)

**作用**: 通过DMA读取主机键盘状态(gafAsyncKeyState数组)，实现双机键盘监测。

**关键类**: `InputDMA` (单例)
- `Init()` — 通过签名扫描定位gafAsyncKeyState: Win11→csrss.exe的win32k.sys, Win10→winlogon.exe内核内存
- `Update()` — 读取主机键盘状态位图
- `IsKeyDown(vk)` — 检测按键是否按下
- `WasKeyPressed(vk)` — 检测按键边沿(用于快捷键防重复触发)

---

### 6. `InputUtils.ixx` (42行)

**作用**: 键盘输入便捷封装，同时检测副机(GetAsyncKeyState)和主机(DMA)按键。

- `check_single_key(vk)` — 双源检测按键是否按住
- `is_key_pressed(vk)` — 双源检测边沿触发
- `InitInputDMA()` / `UpdateInput()` — 初始化和更新DMA键盘

---

### 7. 其他根目录文件

| 文件 | 作用 |
|------|------|
| `bm.ixx` | 宽字符串转ANSI/UTF-8 |
| `Registry.ixx` | DMA读取主机注册表 |
| `WeaponTranslation.ixx` | 武器类名→中文名映射(~100项) |
| `ItemTranslation.ixx` | 物资类名→中文名映射(500+项) + 载具映射(VehicleMap) |

---

## 二、Engine/ — 引擎抽象层

UE4引擎类的DMA封装，继承链:

```
UObject → AActor → APawn → ACharacter → AUAECharacter
        → AController → APlayerController
        → USceneComponent → USkinnedMeshComponent → USkeletalMeshComponent
```

### 核心类说明

| 文件 | 类 | 继承 | 关键方法 |
|------|-----|------|---------|
| `UObject.ixx` | UObject | - | set_ptr_read(), get_FName(), scatter_FName() |
| `FName.ixx` | FName | - | ToString() (GNames解析+LRU缓存) |
| `TArray.ixx` | TArray\<T\> | - | get_vector(), operator[] (自动DMA解引用) |
| `FString.ixx` | FString | TArray\<wchar_t\> | read_string_utf8/ansi/gbk() |
| `Engine.ixx` | Engine | - | **核心**: init(), `WorldToScreen()`, `WorldToScreen1()`, `GetBoneWorldPos()` |
| `UWorld.ixx` | UWorld | UObject | get_PersistentLevel(), get_NetDriver() |
| `ULevel.ixx` | ULevel | UObject | get_Actors()→TArray\<AActor*\> |
| `AActor.ixx` | AActor | UObject | get_type()分类, RootComponent |
| `ACharacter.ixx` | ACharacter | APawn | scatter_Mesh()→USkeletalMeshComponent |
| `APlayerController.ixx` | APlayerController | AController | **write_ControlRotation()** (写旋转自瞄) |
| `APlayerCameraManager.ixx` | APlayerCameraManager | AActor | get_CameraCacheEntry() |
| `CanvasMap.ixx` | CanvasMap | UObject | get_DebugCanvasObject()→ViewProjection矩阵 |
| `USkinnedMeshComponent.ixx` | USkinnedMeshComponent | USceneComponent | 骨骼双TArray、散读骨骼向量 |
| `USkeletalMesh.ixx` | USkeletalMesh | UObject | bone_info_map (骨骼名→索引) |

### Engine核心方法详解

**`Engine::init()`** (Engine.ixx:59-78):
1. `std::println("等待游戏进程...")`
2. 循环 `dma::InitPidGetFromName("wgprojectm.exe")` + Sleep(2000ms)
3. 获取模块基址 `ProcessGetModuleBaseU()`
4. 初始化GNames `FName::m_GNames`

**`Engine::WorldToScreen1()`** (Engine.ixx:119-159):
使用FOV和相机旋转进行世界→屏幕投影(备用方法):
```
delta = worldPos - cameraPos
yaw = atan2(delta.Y, delta.X) * 180/PI - cameraYaw
pitch = atan2(delta.Z, horizontal) * 180/PI - cameraPitch
screenX = centerX + tan(yaw*PI/180) * centerX / tan(FOV/2)
screenY = centerY - tan(pitch*PI/180) * centerX / tan(FOV/2)
```

**`Engine::GetBoneWorldPos()`** (Engine.ixx:90-115):
通过骨骼FTransform和ComponentToWorld矩阵计算世界坐标:
```
worldPos = (boneRotation * bonePosition * boneScale) * ComponentToWorld.Matrix
```

---

## 三、gameixx/ — 游戏特定类

| 文件 | 类 | 说明 |
|------|-----|------|
| `AActorType.ixx` | AActorType | Actor类型分类器: 根据UE类名匹配→EntityType(24种) |
| `AUAECharacter.ixx` | AUAECharacter | 玩家角色: 名字/队伍/血量/信号值/AI/武器/击杀/能量 |
| `ASTExtraWeapon.ixx` | ASTExtraWeapon | 武器: 武器实体组件/弹夹子弹数 |
| `UWeaponEntity.ixx` | UWeaponEntity | **write_NoRecoil()**: 写后坐力字段为0 |
| `ASTExtraVehicleBase.ixx` | ASTExtraVehicleBase | 载具基类 |
| `UVehicleCommonComponent.ixx` | UVehicleCommonComponent | 载具: 血量/油量/轮胎血量 |
| `AUAEPlayerController.ixx` | AUAEPlayerController | 玩家控制器(空壳) |

---

## 四、PhysX3/ — 物理引擎模块

**作用**: 从游戏内存中提取PhysX碰撞数据，在本地重建物理场景，用于射线检测(Raycast)实现自瞄可见性判断。

| 文件 | 类/模块 | 说明 |
|------|---------|------|
| `Offsets_PhysX3.ixx` | Offsets_PhysX3 | PhysX内存偏移: Physics全局指针、NpScene数组、PxActor结构 |
| `Struct_PhysX3.ixx` | physx3::* | PhysX内部结构体: PArray、Box、Shape、ConvexHull等 |
| `physx3Engine.ixx` | physxEngine | **SDK引擎**: createScene(), `LineTraceSingle()`, createBVConvexMesh() |
| `PhysX3.ixx` | PhysX3 | **模块入口**: init(), `runPhysx()`复制游戏碰撞, `loadPhysx()`磁盘加载 |
| `physxLocal.ixx` | BoxInfo等 | 物理网格序列化/反序列化 |

**关键函数**: `physxEngine::LineTraceSingle(origin, target)` → 返回RaycastHit(hasAnyHits, distance, position)

---

## 五、Esp/ — 渲染模块

| 文件 | 说明 |
|------|------|
| `dx11.ixx` | DX11透明覆盖窗口: init()创建窗口+D3D11设备+ImGui, Begin()/End()帧循环, 鼠标穿透切换 |
| `render.ixx` | 渲染辅助: DrawCornerBox()转角方框, AddText()居中文字, DrawHealthBar()血条 |

---

## 六、DMA 驱动层

**文件**: `dma/dma.ixx` (356行)

**关键类**: `dma` (静态方法)
- `init()` — 初始化VMMDLL (`-device fpga`)
- `Read<T>(addr)` — 模板内存读取
- `Write<T>(addr, val)` — 内存写入(用于压枪)
- `InitPidGetFromName(processName)` — 设置目标进程PID
- `ProcessGetModuleBaseU()` — 获取模块基址
- `Scatter_*` — **散读**(Scatter Read)批量DMA读取管理器
- `IsValidPointer()` — 指针有效性验证
- `Refresh_TLB/MEM/MEDIUM()` — DMA缓存刷新

### scatter读（散读）详解

`dma::Scatter_*` 系列函数是性能优化的关键。单次DMA读取延迟约 0.5-2ms，逐条读取100个属性需要 50-200ms（严重掉帧）。散读允许在单次DMA事务中批量读取多个不连续地址，延迟控制在 2-5ms 内。

**使用流程**:
```cpp
// 1. 创建句柄
auto hs = dma::Scatter_Initialize();

// 2. 添加读取请求(立即返回，不阻塞)
dma::Scatter_PrepareEx(hs, addr1, &value1, sizeof(value1));
dma::Scatter_PrepareEx(hs, addr2, &value2, sizeof(value2));
// ...可添加数十个读取项

// 3. 执行批量读取(这才是实际DMA传输)
dma::Scatter_ExecuteRead(hs);

// 4. 读取完成，value1/value2已被填充
// 5. 重用句柄或关闭
dma::Scatter_CloseHandle(hs);
```

**项目中的实际应用**: 每个玩家约需读取30+属性(骨骼×20+血量+队伍+武器+...)，20个玩家 = 600次读取。通过散读，延迟从 ~1000ms 降至 ~5ms。

---

## 七、NetConfig/ — 硬件盒子驱动

| 文件 | 类 | 说明 |
|------|-----|------|
| `kmboxNet.h/cpp` | - | KmBoxNet网络版API: `kmNet_init()`, `kmNet_mouse_move_auto()`, `kmNet_mouse_left()` |
| `KmBox.h/cpp` | KmBox | KmBox COM串口: `Init(com)`, `Move(x,y)`→`km.move(%d,%d)` |
| `MoBox.h/cpp` | MoBox | MoBox DLL: `Init(com)`, `Move(x,y)` |
| `Lurker.h/cpp` | Lurker | Lurker: `Init(com)`, `Move(x,y)` |
| `dma_pic.h` | - | DMA图形显示(Logo) |

**game.cpp中的盒子封装** (Box_Move/Box_Click等):
- 自动检查`g_box_connected`状态
- KmBox COM串口加`Sleep(1)`防缓冲区溢出

---

## 八、配置文件

**文件**: `config.ini`

使用Windows INI API (`WritePrivateProfileStringA`/`GetPrivateProfileStringA`) 读写。

**配置分类**: `[Hardware]`, `[ESP]`, `[Aim]`, `[Trigger]`, `[Shortcut]`, `[Color]`

---

## 九、自瞄引擎详解

**位置**: `draw_aim()` (game.cpp ~3848行)

### 流程图

```
draw_aim()
  │
  ├── 检查 enable / 按键绑定
  │   └── (!is_key_down) → return
  │
  ├── 获取玩家列表 (g_RenderList)
  │   └── 验证 my_player / 空仓 / 弓箭
  │
  ├── for each player:      ← 目标搜索循环
  │   ├── 过滤: 自己/AI/队友/死亡/倒地/距离
  │   ├── 17骨骼优先级扫描 (head→neck→spine→...)
  │   ├── 可选: PhysX射线可视性检测
  │   ├── 弹道预判 (PUBG_DMA移植):
  │   │   ├── GetDragForce 三组武器阻力查表
  │   │   ├── 19种武器子弹速度表
  │   │   └── SimulateWeaponTrajectory 分步积分
  │   ├── 角度FOV过滤 (acosf方向夹角)
  │   └── 按最小角度选择 best_target
  │
  ├── if best_target:
  │   ├── WorldToScreen → screen_dx/dy (用于绘制和鼠标移动)
  │   ├── 可选 humanize: 延迟80-300ms + 偏移 ±5-15px + 过甩
  │   ├── 绘制射线+十字+圆环 (draw_line/draw_target_bone)
  │   └── PUBG_DMA平滑:
  │       speed = 150 / (smooth × 3 + 1)     ← 映射到 px/帧
  │       move = Remain + clamp(speed×dir, -|d|, |d|)
  │       Remain = move - trunc(move)         ← 亚像素余数累积
  │       Box_Move(trunc(move))               ← 硬件盒子移动
  │
  └── else: (无目标) locked_target_ptr = 0
```

### 平滑参数映射

| smooth值 | XS (px/帧) | 手感 |
|----------|-----------|------|
| 0.3 | 79 | 快速跟枪 |
| 0.5 | 68 | 较快 |
| 1.0 | 37.5 | 平滑 |
| 5.0 | 9.4 | 慢速 |
| 10.0 | 4.8 | 很慢 |
| 20.0 | 2.5 | 极慢 |

### 骨骼扫描与"漏打"机制

**四种骨骼模式** (aim_bone_mode):
| 模式 | 值 | 骨骼列表 | 说明 |
|------|---|---------|------|
| 仅头部 | 0 | `{65, 6}` | 头顶(65)优先，回退到头部(6) |
| **漏打扫描** | **1** | `{65, 6, 5, 4, 3, 2, 1}` | 自上而下，见哪打哪 |
| 固定部位 | 2 | `{aim_bone_id}` | 锁定单个骨骼(下拉选择) |
| 随机部位 | 3 | 每帧随机选1个 | 抗检测随机化 |

**"漏打"核心逻辑** (bone_mode=1):

```
for each target player:
  │
  ├── 按优先级遍历骨骼: 头顶(65) → 头(6) → 脖子(5) → 胸(4) → 脊柱(3) → 骨盆(2) → 根(1)
  │
  ├── for bone_id in [65, 6, 5, 4, 3, 2, 1]:
  │   │
  │   ├── 通过 DMA 读取骨骼 worldPos
  │   │   bone_world = Engine::GetBoneWorldPos(bone_FTransform, ComponentToWorld)
  │   │
  │   ├── if vis_check 开启:
  │   │   │
  │   │   ├── physxEngine::LineTraceSingle(cameraPos, bone_world)
  │   │   │   │
  │   │   │   ├── !hasAnyHits() → 骨骼可见!
  │   │   │   │   ├── 选中该骨骼
  │   │   │   │   ├── 标记 found_visible_bone = true
  │   │   │   │   └── break (停止扫描，优先打最高可见部位)
  │   │   │   │
  │   │   │   └── hasAnyHits() → 被遮挡
  │   │   │       └── continue 下一个骨骼
  │   │   │
  │   │   └── else (不检查可见性):
  │   │       ├── 直接选中头部(65)
  │   │       └── break
  │   │
  │   └── if found_visible_bone → 使用该骨骼的 worldPos 计算弹道
  │
  └── if !found_visible_bone:
      └── 整个玩家被遮挡 → continue (跳过该玩家)
```

**"漏打"名称的由来**: 当敌人站在掩体后面只露出头部时，程序从上往下扫描骨骼。头顶(65)可能被头盔遮住，头部(6)暴露在外可见，程序就"漏"过被遮挡的骨骼，打到第一个可见的骨骼。传统自瞄只打头，头被遮住就无效；漏打扫描能"见哪打哪"。

**可见性检测实现**: `physxEngine::LineTraceSingle(origin, target)` 在本地PhysX场景中执行射线检测。PhysX场景由 `PhysX3::runPhysx()` 从游戏内存中复制地形和建筑碰撞网格构建，物理上等同游戏场景。

**骨骼ID对应关系**:
| ID | 名称 | 注释 |
|----|------|------|
| 65 | fore_head | 头顶(发际线) |
| 6 | head | 头部中心 |
| 5 | neck_01 | 脖子 |
| 4 | spine_03 | 上胸 |
| 3 | spine_02 | 中脊柱 |
| 2 | spine_01 | 下脊柱 |
| 1 | pelvis | 骨盆 |

### 弹道预测引擎 (PUBG_DMA移植)

**完整流程图**:
```
predicted_pos = target_bone_worldPos

if prediction 开启:
  │
  ├── Step 1: 获取武器名
  │   weapon_name = my_player->CurrentWeapon->FName.ToString()
  │
  ├── Step 2: GetDragForce 查表
  │   ┌────────────────────────────────────┐
  │   │ 组1 (主武器26种):                    │
  │   │   AK47/M416/Kar98k/AWM/Groza/...    │
  │   │   10m:0.41  50m:0.41  100m:0.42     │
  │   │   300m:0.80  500m:1.05  1000m:1.55   │
  │   │                                     │
  │   │ 组2 (半自动6种):                      │
  │   │   SKS/FNFal/Mk14/Dragunov/...        │
  │   │   10m:0.38  100m:0.39  300m:0.55     │
  │   │   600m:1.02  1000m:1.30              │
  │   │                                     │
  │   │ 默认: drag = min(1.5, 0.37+dist*0.00115) │
  │   └────────────────────────────────────┘
  │
  ├── Step 3: 子弹速度查表 (19种)
  │   AWM=910  Mini14=990  Kar98k=760
  │   HK416=880  AK47=715  Groza=715
  │   SCAR-L=870  AUG=940  M24=790
  │
  ├── Step 4: 分步积分模拟 (dt=10ms, max=300步)
  │   for step in 0..300:
  │     speed = sqrt(vx²+vy²+vz²)
  │     drag_magnitude = speed² × 0.001 × dragForce / speed
  │     v += (gravity + drag) × dt
  │     pos += v × dt
  │     if pos.x >= targetDistance: break
  │
  ├── Step 5: 目标速度外推
  │   predicted_pos += targetVelocity × simTime
  │
  └── Step 6: Z轴下坠修正
      predicted_pos.Z -= abs(simPos.Z)
```

**与简化版对比**:
| 特性 | 旧版(原项目) | 新版(PUBG_DMA移植) |
|------|------------|-----------------|
| 飞行时间 | dist/88000 (固定880m/s) | 19种武器独立速度 |
| 下坠 | 线性: dist×0.11 + 5档固定加值 | 分步积分模拟(重力+阻力) |
| 阻力 | 无 | 三组武器独立阻力查表 |
| 精度 | <150m可用, 远距离偏移显著 | 全距离(<1050m)精确 |

### 平滑算法详解

**算法**: InitialValue渐进累积 (移植自PUBG_DMA AimBotAPI)

```
speed = 150 / (smooth × 3 + 1)     // px/帧，smooth范围0.01~20

RemainX = 上一帧余数
RemainY = 上一帧余数

moveX = RemainX + clamp(speed × sign(dx), -|dx|, |dx|)
moveY = RemainY + clamp(speed × sign(dy), -|dy|, |dy|)

RemainX = moveX - trunc(moveX)      // 保存亚像素余数
RemainY = moveY - trunc(moveY)

Box_Move(trunc(moveX), trunc(moveY)) // 整数像素移动
```

**亚像素余数原理**: 每帧计算出的理想移动量为 4.7 像素，但盒子只能移动整数像素。余数 0.7 积累到下一帧，4帧后积累出 2.8 额外像素，路径更平滑。

**humanize模拟真人** (可选):
- 目标切换: 反应延迟 80~300ms + 瞄准偏移 ±5~15px
- 30%概率过甩: 超出目标 1.3~1.5倍再拉回 (3~8帧)
- 冷却期间: skip_move=true，鼠标不移动

### 扳机(TriggerBot)状态机

```
状态转换图:

  [目标在准星内]        [延迟到期]
  IDLE ──────────→ WAITING_DELAY ──────→ CLICK_DOWN
    ↑                                      │
    │         [松开按键或20ms到期]           │
    └──────────────────────────────────────┘

详细流程:
  1. 遍历所有玩家，对每个骨骼做WorldToScreen
  2. 屏幕坐标在FOV圈内 → 触发PhysX射线检测
  3. 无遮挡 → trigger_active = true
  4. IDLE → WAITING_DELAY (等待用户设定的延迟时间)
  5. 延迟到 → Box_Click() (模拟左键按下)
  6. 20ms后 → Box_Release() (模拟左键释放)
  7. 回到 IDLE

aim_sync模式:
  除了自动开火外，同时执行自瞄:
  - 按距离选择最近目标
  - 执行静默自瞄(write_ControlRotation)或模拟鼠标移动
  - 击中后切换目标
```

### 自瞄像素计算 (draw_aim Step 5 详细)

**当前实现** (屏幕投影 + 平滑):

```
// Step 1: WorldToScreen 投影 (与绘制红点完全一致)
screen_pos = Engine::WorldToScreen1(predicted_bone_world)
screen_dx = screen_pos.x - screen_center_x   // 屏幕像素偏移
screen_dy = screen_pos.y - screen_center_y

// Step 2: PUBG_DMA平滑
speed = 150 / (smooth × 3 + 1)
moveX = RemainX + clamp(speed×sign(screen_dx), -|screen_dx|, |screen_dx|)
moveY = RemainY + clamp(speed×sign(screen_dy), -|screen_dy|, |screen_dy|)

// Step 3: 硬件盒子
Box_Move(trunc(moveX), trunc(moveY))
```

### 视角FOV过滤

使用角度空间FOV (与PUBG_DMA一致):
```
forward = 相机前向向量 (cos(pitch)×cos(yaw), cos(pitch)×sin(yaw), sin(pitch))
dir = (bone_world - camera_pos).normalized()
angle = acos(dot(forward, dir)) × 180/PI   // 角度差(度)
aim_fov = current_fov × 15.0 / 100.0       // fov=100→15°, fov=200→30°
if angle > aim_fov → 跳过该目标
```

---

## 十、ESP系统详解

### 玩家ESP (draw_player → 三个子函数)

| 函数 | 绘制内容 | 颜色配置 |
|------|---------|---------|
| `draw_player_box()` | 2D方框(可见/不可见颜色) | `color_box_visible/invisible` |
| `draw_player_info()` | 名字/武器/距离/血量条/能量/击杀数/队伍ID/动作状态 | 各自独立颜色 |
| `draw_player_bone()` | 骨骼连线(head→neck→spine→pelvis→arms→legs) | `color_bone_visible/invisible` |

### 物资ESP (draw_item)

- 按类型过滤: 药品/弹药/防具/配件/武器/空投/死亡盒子
- 搜索过滤: 输入框实时匹配物品名
- 显示: 名称+距离

### 载具ESP (draw_vehicle)

- 显示: 载具名/血量条+百分比/油量/距离
- 轮胎损坏指示

### 雷达 (draw_radar)

- 两种风格: 军事/电竞
- 可显示: 玩家/载具/物资/名字/距离

---

## 十一、关键算法与数据流

### 主数据循环 (read_data ~572行)

```
while(g_running):
  │
  ├── 1. 读取 UWorld
  │   uworld = m_Engine.get_Uworld()
  │
  ├── 2. 判断游戏状态
  │   if !validPointer(uworld.ptr):
  │     → 清空所有列表, 刷新PhysX, 清TLB缓存
  │     → continue (跳过本帧)
  │   if was_invalid (刚从无效恢复):
  │     → 强制刷新TLB + 强制重新读取Actor数组
  │
  ├── 3. 获取Actor数组
  │   level = uworld.get_PersistentLevel()
  │   actors = level.get_Actors()  // TArray<AActor*>
  │
  ├── 4. 遍历分类 (每11帧读取一次完整数组，中间帧更新坐标)
  │   for actor in actors:
  │     type = AActorType::get_type(actor.FName)
  │     switch(type):
  │       Player/AI:
  │         AUAECharacter player
  │         DMA散读: 骨骼+位置+队伍+血量+武器...
  │         → g_playerList
  │       Vehicle:
  │         ASTExtraVehicleBase vehicle
  │         → g_vehicleList
  │       Item/Drug/Armor/...:
  │         AActor item
  │         → g_item_list
  │
  ├── 5. 更新全局状态
  │   g_uworld.store(uworld)
  │   g_my_player.store(my_player)
  │
  └── 6. 帧率控制
      Sleep(1)  // 限流，防止DMA设备过热
```

### 渲染循环 (draw ~4562行)

每帧顺序调用:
1. `draw_aim()` — 自瞄
2. `draw_trigger()` — 扳机
3. `recoil_control()` — 压枪
4. `draw_physx()` / `draw_all_physx_actors()` — PhysX可视化(可选)
5. `draw_player()` — 玩家ESP
6. `draw_item()` — 物资ESP
7. `draw_vehicle()` — 载具ESP
8. `draw_radar()` — 雷达
9. `draw_shortcut_menu()` — 快捷键状态
10. `draw_menu()` — ImGui菜单

### 压枪实现 (recoil_control ~3652行)

```
void recoil_control():
  获取本地玩家武器指针
  if 武器有效:
    DMA_Write(weapon + VRecoilFactor,   0.0f)   // 垂直后坐力倍率 → 0
    DMA_Write(weapon + VRecoilModifier, 0.0f)   // 垂直修正 → 0
    DMA_Write(weapon + HRecoilFactor,   0.0f)   // 水平后坐力倍率 → 0
    DMA_Write(weapon + HRecoilModifier, 0.0f)   // 水平修正 → 0
    DMA_Write(weapon + RecoveryFactor,  0.0f)   // 恢复速度 → 0
```

**原理**: PUBG的武器后坐力系统通过 `UWeaponEntity` 中的这些浮点数控制。将它们全部写为0后，武器不会产生任何后坐力位移。这与传统压枪(物理上反向移动鼠标抵消后坐力)不同，是直接修改内存的"无反冲"实现。
- 优点: 精准，不依赖鼠标移动速度
- 风险: 内存写入可被反作弊检测(相比纯鼠标模拟)

### AActorType 分类系统

`AActorType::get_type(FName)` 通过三层查找确定Actor类型:

```
Lookup: 获取Actor的FName → ToString()
  │
  ├── Layer 1: EntityPlayerLists 预设集合
  │   包含: "AUAECharacter" 等玩家/AI类名
  │   → 返回 EntityType::Player 或 AI
  │
  ├── Layer 2: EntityItemLists 预设集合 (500+条目)
  │   包含: 药品/弹药/防具/配件/武器的UE类名
  │   → 返回 EntityType::Drug/Armor/Ammo/Weapon/...
  │
  ├── Layer 3: EntityVehicleLists 预设集合
  │   → 返回 EntityType::Vehicle
  │
  └── Layer 4: 字符串匹配兜底
      if contains("DeadBox")  → DeadBox
      if contains("AirDrop")  → AirDrop
      if contains("Projectile") → Project
      if contains("Grenade")     → Grenade
      ...
```

### WorldToScreen 投影算法

**方法1: ViewProjection矩阵 (WorldToScreen)**

使用游戏的CanvasMap→DebugCanvasObject→ViewProjection矩阵(偏移0x270):
```
clip = world × ViewProjection
if clip.w < 0.01 → 在屏幕后面, 返回false
screen.x = centerX + centerX × (clip.x / clip.w)
screen.y = centerY - centerY × (clip.y / clip.w)
```

**方法2: FOV角度投影 (WorldToScreen1)** — 备用方法

```
delta = worldPos - cameraPos
horizontal = sqrt(delta.x² + delta.y²)

// 计算角度偏移
yaw   = atan2(delta.y, delta.x) × 180/PI - camera.yaw
pitch = atan2(-delta.z, horizontal) × 180/PI - camera.pitch

// 角度→像素
scale = centerX / tan(fov/2)
screen.x = centerX + tan(yaw*PI/180)   × scale
screen.y = centerY - tan(pitch*PI/180) × scale
```

**两种方法差异**: 方法1使用游戏自身的ViewProjection矩阵(含镜头畸变等)，更精确。方法2为纯三角函数计算，不含游戏后期处理，在部分模式下可能稍差。

### 静默自瞄 (Silent Aim)

通过 `APlayerController::write_ControlRotation(pitch, yaw)` 直接写入内存修改视角，无需移动鼠标。

---

## 文件清单

| 路径 | 行数 | 类型 |
|------|------|------|
| game.cpp | ~4600 | 主入口+逻辑 |
| Offsets.ixx | 173 | 偏移量定义 |
| Struct.ixx | 571 | 数学/UE结构体 |
| dx11_menu.ixx | 206 | 配置参数 |
| bm.ixx | 40 | 字符串转换 |
| Registry.ixx | 63 | 注册表读取 |
| InputDMA.ixx | 328 | DMA键盘输入 |
| InputUtils.ixx | 42 | 键盘封装 |
| WeaponTranslation.ixx | 171 | 武器名翻译 |
| ItemTranslation.ixx | ~800 | 物资名翻译 |
| Engine/Engine.ixx | 163 | 引擎封装 |
| Engine/UObject.ixx | 41 | 对象基类 |
| Engine/FName.ixx | 54 | FName |
| Engine/TArray.ixx | 82 | TArray |
| Engine/FString.ixx | 88 | FString |
| Engine/UWorld.ixx | ~30 | UWorld |
| Engine/ULevel.ixx | ~20 | ULevel |
| Engine/AActor.ixx | ~50 | AActor |
| Engine/ACharacter.ixx | ~20 | ACharacter |
| Engine/USkinnedMeshComponent.ixx | ~80 | 骨骼网格 |
| Engine/USkeletalMesh.ixx | ~40 | 骨骼网格资源 |
| Engine/APlayerController.ixx | ~40 | 玩家控制器 |
| Engine/APlayerCameraManager.ixx | ~30 | 相机管理 |
| Engine/CanvasMap.ixx | ~20 | CanvasMap |
| Engine/DebugCanvasObject.ixx | ~20 | 调试Canvas |
| Engine/USceneComponent.ixx | ~30 | 场景组件 |
| Engine/UGameInstance.ixx | ~20 | GameInstance |
| gameixx/AActorType.ixx | 562 | Actor分类 |
| gameixx/AUAECharacter.ixx | 149 | 玩家角色 |
| gameixx/ASTExtraWeapon.ixx | 38 | 武器 |
| gameixx/UWeaponEntity.ixx | 22 | 武器实体 |
| gameixx/ASTExtraVehicleBase.ixx | 30 | 载具 |
| gameixx/UVehicleCommonComponent.ixx | 60 | 载具组件 |
| PhysX3/PhysX3.ixx | ~200 | PhysX入口 |
| PhysX3/physx3Engine.ixx | ~300 | PhysX SDK |
| PhysX3/physxLocal.ixx | ~200 | 网格序列化 |
| Esp/dx11.ixx | 366 | DX11窗口 |
| Esp/render.ixx | 166 | 渲染辅助 |
| dma/dma.ixx | 356 | DMA封装 |
| NetConfig/kmboxNet.h | 94 | KmBoxNet API |
| NetConfig/KmBox.h | ~15 | KmBox COM |
| NetConfig/MoBox.h | ~10 | MoBox |
| NetConfig/Lurker.h | ~10 | Lurker |

---

## 十二、本地PhysX建模与遮挡判断系统

### 系统架构

```
游戏内存 (PhysX场景)
    │
    ▼ DMA读取
PhysX3::runPhysx()
    │ 提取: 地形高度场、建筑凸包/三角网格、坐标变换
    ▼
本地 physxEngine SDK
    │ 创建: PxScene + PxRigidStatic + 几何体
    ▼
physxEngine::LineTraceSingle(origin, target)
    │ 在本地场景执行射线检测
    ▼
RaycastHit { hasAnyHits, distance, position }
```

### 地形高度场复制

```
PhysX3::runPhysx():
  for each 游戏 PhysX Scene:
    for each PxActor:
      if 静态刚体:
        switch GeometryType:
          case HeightField:
            读取高度场样本数组(数千个高度值)
            反序列化重建 PxHeightField
            创建 PxHeightFieldGeometry
            → 添加到本地场景

          case TriangleMesh:
            读取三角网格顶点+索引缓冲区
            反序列化重建 PxTriangleMesh
            创建 PxTriangleMeshGeometry
            → 添加到本地场景

          case ConvexMesh:
            读取凸包顶点+面数据
            通过 physxEngine::createBVConvexMesh() 重建
            创建 PxConvexMeshGeometry
            → 添加到本地场景

          case Box:
            从 NpShape 读取半尺寸
            创建 PxBoxGeometry
            → 添加到本地场景
```

### 关键数据结构

游戏中的PhysX对象通过 DMA 读取对应的内存布局:

**PxActor 层次结构**:
```
PhPxBase (ConcreteType: 6=Dynamic, 7=Static)
  └── PhPxActor (ShapeManager, ActorFlags)
        └── PhPxRigidActor
              ├── PhPxRigidDynamic (body2Actor, BufferedBody2World)
              └── PhPxRigidStatic (Body2World, ControlState)
```

**NpShape → Geometry 转化**:
```
PhNpShape:
  FilterData → word3=19 用于碰撞过滤
  Localpos → 形状局部位置
  Geometry:
    mType:
      1 = PxSphereGeometry
      2 = PxPlaneGeometry
      3 = PxCapsuleGeometry
      4 = PxBoxGeometry       → 读半尺寸
      5 = PxConvexMeshGeometry → 读ConvexMesh偏移→反序列化
      6 = PxTriangleMeshGeometry → 读TriangleMesh偏移→反序列化
      7 = PxHeightFieldGeometry → 读HeightField偏移→反序列化
```

### 射线检测流程

```cpp
// 自瞄中通过可见性判断
auto hit = physxEngine::LineTraceSingle(cameraPos, targetBonePos);

// 内部实现
PxRaycastBuffer hit;
PxQueryFilterData filterData;
filterData.data.word0 = 19; // 与游戏相同的碰撞过滤word
scene->raycast(origin, direction, maxDistance, hit,
    PxHitFlag::eDEFAULT, filterData);

return {
    hit.hasBlock,        // hasAnyHits()
    hit.block.distance,  // 命中距离
    hit.block.position   // 命中世界坐标
};
```

### 磁盘缓存优化

`PhysX3::loadPhysx()` 从磁盘加载预序列化的物理模型，避免每次都从游戏内存中重建:

```
第一次启动: runPhysx() → SaveScene()  → 保存到磁盘
后续启动: loadPhysx()  → 加载预构建碰撞  → ~1秒恢复完整场景
```

---

## 十三、菜单UI系统

### ImGui自定义组件

**ToggleButton** (game.cpp:1930): 自定义圆角开关按钮，模拟移动端UI风格:
```cpp
ToggleButton(label, &bool_var, tooltip)
  绘制带阴影的圆角矩形
  根据bool_var绘制绿色(开)/灰色(关)滑块
  hover时显示tooltip
  点击时切换bool_var并保存配置
```

**KeyBind** (game.cpp:2000+): 按键绑定控件，点击后等待按键输入:
```
点击 "自瞄按键#1 [None]" → 进入录制模式
按下键盘任意键 → 绑定成功，显示键名
右键 → 清除绑定
```

**ColorItem**: 颜色选择器，点击弹出ImGui颜色编辑窗口

**ImGui::Combo_popup**: 自定义下拉框，修复了ImGui原生Combo在透明窗口上的焦点问题

### 菜单布局

```
[基础自瞄]  [其他自瞄]  [自瞄参数]
 启用自瞄    静默自瞄    自瞄范围
 自瞄预判    自瞄射线    自瞄平滑
 可视判断    开火自瞄    自瞄距离
 自瞄部位              自瞄X/Y
 压枪/无反冲           自瞄按键#1/#2
 忽略倒地/AI           扳机自瞄
 模拟真人              ...
 持续锁定
 50米增强

[显示]           [颜色]       [地铁]       [雷达]
 玩家骨骼        方框颜色    地铁模式      军事/电竞风格
 玩家方框        骨骼颜色    额外物品      名称/载具显示
 ...             ...        下雪特效      ...
```

### config.ini 配置持久化

```ini
[Hardware]
box_type=1
ip=192.168.2.188
port=6234

[ESP]
player_box=1
player_bone=1
color_box_visible=0.0 1.0 0.0 1.0
color_box_invisible=1.0 1.0 0.0 1.0

[Aim]
enable=1
fov=500.0
smooth=0.56
dist=645.0
prediction=1
vis_check=1
...
```

读写使用 Windows INI API: `GetPrivateProfileStringA`/`WritePrivateProfileStringA`，float/int/bool 均序列化为字符串存储。

---

## 十二、本地PhysX建模与人物遮挡判断

> **核心思路**: 通过DMA从游戏内存中读取PhysX碰撞数据（地形高度场、建筑三角网格、物体凸包），在本地进程内重建完全相同的物理场景，然后用本地PhysX SDK执行射线检测来判断敌人是否被遮挡。

### 12.1 为什么需要本地建模

游戏内部有 PhysX 场景管理碰撞检测，但 DMA 外挂无法直接调用游戏的 SDK API。解决方案是完整"克隆"一份碰撞场景到本地：

```
游戏进程 [DMA读取] → 外挂进程
  PhysX Scene          本地 PhysX Scene (克隆)
  ├─ 地形高度场    →    ├─ 地形高度场
  ├─ 建筑三角网格  →    ├─ 建筑三角网格
  ├─ 岩石凸包      →    ├─ 岩石凸包
  └─ 盒子碰撞体    →    └─ 盒子碰撞体

  游戏Raycast(不可访问)    LineTraceSingle(本地可控)
```

### 12.2 整体数据流

```
DMA读取 PhysX3_x64.dll 基址
  → DLL + 0x1DF698 = Physics全局指针
    → Physics + 0x8 = TArray<NpScene*> 场景数组
      → NpScene + 0x2590 = TArray<PxActor*> Actor数组
        → 遍历每个Actor:
            │
            ├─ ConcreteType=6(动态)
            │   读 body2Actor(+0xB0) + body2World(+0x140)
            │   GlobalPos = body2World × body2Actor⁻¹
            │   → 本地 createRigidDynamic(GlobalPos)
            │
            ├─ ConcreteType=7(静态)  ← 地形/建筑
            │   读 Body2World(+0x90)
            │   → 本地 createRigidStatic(Body2World)
            │
            └─ ShapeManager(+0x28) → PtrTable
                遍历每个Shape:
                  读 FilterData(+0x50) → word3=19才参与碰撞
                  读 Localpos(+0x70) → Shape本地姿态
                  读 Geometry(+0x98) → 几何体类型
                  按类型反序列化:
                    BOX           → PxBoxGeometry(halfExtents)
                    HEIGHTFIELD   → DMA读sample数组→createHeightField
                    TRIANGLEMESH  → DMA读顶点+索引→cookBV34→createMesh
                    CONVEXMESH    → DMA读顶点→createBVConvexMesh
                  创建Shape → 加入Actor → addActor到gScene
```

### 12.3 类继承体系 (19个源文件)

```
PhysX3Object (DMA指针基类)
├── PhPxBase              → mConcreteType (6=动态/7=静态)
│   └── PhPxActor         → ShapeManager / mStreamPtr
│       └── PhPxRigidActor (空壳)
│           ├── PhPxRigidDynamic → body2Actor + body2World
│           └── PhPxRigidStatic  → Body2World
├── PhNpScene             → 获取 PxActors 数组
├── PhNpShape             → FilterData / Localpos / Geometry type
├── PhPxConvexMeshGeometry  → DMA读ConvexMesh → 凸包重建
├── PhPxTriangleMeshGeometry→ DMA读TriangleMesh → 三角网格重建
└── PhPxHeightFieldGeometry → DMA读HeightField → 高度场重建
```

### 12.4 关键DMA偏移

| 偏移地址 | 字段 | 作用 |
|---------|------|------|
| DLL+0x1DF698 | Physics全局指针 | PhysX SDK入口 |
| Physics+0x8 | TArray<NpScene*> | 游戏所有物理场景 |
| NpScene+0x2590 | TArray<PxActor*> | 场景内所有Actor |
| Actor+0x8 | uint16 mConcreteType | 6=动态, 7=静态 |
| Actor+0x28 | ShapeManager | PtrTable(含Shape指针列表) |
| Static+0x90 | PxTransform Body2World | 静态刚体世界变换 |
| Dynamic+0xB0 | PxTransform body2Actor | 动态刚体body→actor偏移 |
| Dynamic+0x140 | PxTransform body2World | 动态刚体世界变换 |
| Shape+0x50 | PxFilterData | word3=19为可碰撞过滤 |
| Shape+0x70 | PxTransform Localpos | Shape本地姿态 |
| Shape+0x98 | PxGeometry | 几何体数据(多态) |

### 12.5 世界变换计算

**静态刚体 (ConcreteType=7)** — 建筑/地形/固定物体:
```
GlobalPos = Body2World (直接DMA读取, 偏移+0x90)
本地创建: createRigidStatic(GlobalPos)
```

**动态刚体 (ConcreteType=6)** — 车辆/可动物体:
```
body2Actor = DMA读(+0xB0): Actor相对于物理体的本地偏移
body2World = DMA读(+0x140): 物理体在世界中的变换
GlobalPos = body2World × body2Actor.getInverse()
含义: 从物理体世界位置→取消Actor偏移→得到Actor世界位置
本地创建: createRigidDynamic(GlobalPos)
```

**Shape最终世界变换**: `ShapeWorld = localpos × ActorWorldTransform`

### 12.6 四种几何体重建

#### 12.6.1 BOX (盒子, 类型4)

```
DMA读: halfExtents (PxVec3 半长宽高)
创建: PxBoxGeometry(halfExtents) → createShape → attachShape
```

#### 12.6.2 HEIGHTFIELD (高度场/地形, 类型7)

```
DMA读:
  1. HeightField指针 → rows × cols → nbSamples
  2. DMA批量读: samples数组 (每个4字节, PxHeightFieldSample)
  3. 安全检查: cols < 1,000,000

本地重建:
  desc.format = eS16_TM (16位有符号高度 + 材质)
  desc.nbRows, desc.nbColumns
  hf = gCooking->createHeightField(desc)
  geo = PxHeightFieldGeometry(hf, flags, scales)
  shape = createShape(geo, *material)
```

每个样本 = 2字节高度(需乘heightScale) + 2字节材质ID(0=无材质,1~=材质索引)。

#### 12.6.3 TRIANGLEMESH (三角网格/建筑, 类型6)

```
DMA读:
  1. meshPtr → mNbVertices, mNbTriangles
  2. 顶点: DMA批量读 mNbVertices × sizeof(PxVec3)
  3. 索引: DMA批量读 (16位或32位)
      bit1 of mFlags决定: 16位→TrisSize=nbTris×3×2, 32位→nbTris×3×4
  4. 索引转换: 16位→32位 (验证每个index < nbVerts)

本地重建 (BVH34加速):
  desc.points = 顶点数组
  desc.triangles = 32位索引数组
  mesh = gCooking->cookTriangleMesh(desc) → cooked二进制
  mesh = gPhysics->createTriangleMesh(cooked)
  geo = PxTriangleMeshGeometry(mesh, scale)
  shape = createShape(geo, *material)
```

#### 12.6.4 CONVEXMESH (凸包/物体, 类型5)

```
DMA读:
  1. meshPtr → mNbHullVertices, mPolygons指针
  2. 顶点缓冲区 = mPolygons + sizeof(PhHullPolygonData) × mNbPolygons
  3. DMA读: mNbHullVertices × sizeof(PxVec3)

本地重建:
  desc.points = 顶点数组, desc.count = nbVerts
  desc.flags = eCOMPUTE_CONVEX
  convMesh = gCooking->createConvexMesh(desc)
  geo = PxConvexMeshGeometry(convMesh, scale)
  shape = createShape(geo, *material)
```

### 12.7 碰撞过滤

```cpp
// 从游戏Shape的FilterData.word3决定是否加入本地场景
PxFilterData fd = read(shape + 0x50);

if (fd.word3 != 19) {        // word3 ≠ 19 → 非碰撞几何体
    if (type != HEIGHTFIELD)  // 地形始终保留
        continue;             // 丢弃! (水面/粒子/装饰)
}
// word3 == 19 → 实体碰撞 → 保留并参与射线检测
shape->setQueryFilterData(fd);
```

### 12.8 射线检测

```cpp
PxRaycastBuffer LineTraceSingle(FVector3D origin, FVector3D dest) {
    PxVec3 dir = (dest - origin).normalized();
    float len = (dest - origin).magnitude();
    
    shared_lock lock(sceneMutex);  // 读锁(允许并发)
    PxRaycastBuffer hit;
    gScene->raycast(origin, dir, len, hit);
    return hit;
}
// hit.hasAnyHits() → true=被遮挡, false=可见
```

### 12.9 遮挡判断在自瞄中的应用

```
骨骼扫描每帧:
  for bone in [头顶65, 头6, 脖子5, 胸4, 脊柱3, 骨盆2, 根1]:
    boneWorld = GetBoneWorldPos(bone_FTransform, ComponentToWorld)
    hit = LineTraceSingle(cameraPos, boneWorld)
    
    if !hit.hasAnyHits():
      射线从摄像机直达到骨骼, 中间无碰撞体
      → 该骨骼可见! 选中并停止扫描
    else:
      射线被墙/建筑/地形挡住
      → 该骨骼被遮挡! 继续下一个骨骼
```

**"漏打"原理**: 当敌人在掩体后只露出头部时，头顶(65)可能被墙遮住→命中→跳过，头部(6)暴露在外→无命中→选中！程序自己找暴露的骨骼。

### 12.12 完整导入流程 (runPhysx 源码级详解)

**Step 0: 初始化** (`PhysX3::init()`)
```cpp
// 1. 获取游戏 PhysX DLL 基址
addr = dma::ProcessGetModuleBaseU("PhysX3_x64.dll");

// 2. 读取 Physics 全局指针 (DLL内部偏移0x1DF698)
ptr = dma::Read<int64_t>(addr + 0x1DF698);   // Physics SDK实例地址

// 3. 初始化本地 PhysX 引擎
physxEngine::InitPhysx();  // 创建Foundation+PxPhysics+PxScene(含GPU)+Material+Cooking
```

**Step 1: 获取场景数组** (`GetNpSencePArray()`)
```cpp
// Physics指针 + 0x8 = TArray<NpScene*>  (PArray结构体)
PhNpSenceArray(ptr + 0x8);
// 内部: dma::Read<PArray> → 得到 Data指针 + NumElements个数
```

**Step 2: 遍历每个NpScene**
```cpp
for (iii = 0; iii < npSencePArray.NumElements; iii++) {
    auto npSence = npSencePArray[iii];  // TArray下标访问 → DMA解引用

    // NpScene + 0x2590 = TArray<PxActor*>
    auto phPxActors = npSence.GetPxActorsPArray();

    // DMA批量读取所有Actor指针 (NumElements × 8字节)
    std::vector<int64_t> ActorsPtrArr(NumElements);
    dma::Read(phPxActors.Data, ActorsPtrArr.data(), NumElements * 8);
```

**Step 3: 遍历每个Actor**
```cpp
for (auto& actorPtr : ActorsPtrArr) {

    // 去重: 用游戏内存地址作键
    if (gLoadSet.count(actorPtr)) continue;

    // 创建Actor包装 (isRaw=true: actorPtr直接是目标地址)
    PhPxActor pxActor(actorPtr, true);

    // 读 ConcreteType (偏移+0x8, uint16_t)
    auto type = pxActor.GetmConcreteType();
    // 6 = 动态刚体(车辆等), 7 = 静态刚体(建筑/地形)
```

**Step 4a: 静态刚体 (ConcreteType=7)** — 建筑/地形/固定物体
```cpp
    PhPxRigidStatic staticActor(actorPtr, true);

    // 读 Body2World (偏移+0x90, PxTransform)
    GlobalPos = staticActor.GetBody2World();
    // 内部: 先读mControlState(+0x68)的bit6判断位置, 再读变换数据

    if (!GlobalPos.isValid()) continue;     // 无效变换 → 跳过
    if (GlobalPos.x==0 && GlobalPos.y==0) continue; // 原点 → 跳过

    // 读ShapeManager (偏移+0x28)
    shapeManager = staticActor.GetmShapeManager();

    // 在本地PhysX创建静态刚体
    tmpActor = gPhysics->createRigidStatic(GlobalPos);
```

**Step 4b: 动态刚体 (ConcreteType=6)** — 车辆/可动物体
```cpp
    PhPxRigidDynamic dynamicActor(actorPtr, true);

    // 读body2Actor (偏移+0xB0) 和 body2World (偏移+0x140)
    // 先检查mBodyBufferFlags(+0x17C) & 0x200 判断数据位置
    body2Actor = dynamicActor.Getbody2Actor();   // Actor相对物理体的偏移
    body2World = dynamicActor.GetmBufferedBody2World(); // 物理体世界变换

    // 计算: body2World × body2Actor.getInverse()
    // 含义: 物理体位置 → 取消Actor偏移 → 得到Actor世界位置
    GlobalPos = body2World * body2Actor.getInverse();

    shapeManager = dynamicActor.GetmShapeManager();

    // 在本地PhysX创建动态刚体
    tmpActor = gPhysics->createRigidDynamic(GlobalPos);
```

**Step 5: 展开ShapeManager → 获取Shape指针列表**
```cpp
    // ShapeManager.mShapes 是一个 PtrTable 结构体
    // PtrTable: { mSingle(指针/数组首地址), mCount(数量), ... }
    // 当mCount==1: mSingle直接是Shape指针
    // 当mCount>1:  mSingle指向数组

    std::vector<int64_t> shapePtrArr(shapeManager.mShapes.mCount);

    if (shapeManager.mShapes.mCount == 1) {
        shapePtrArr.push_back(shapeManager.mShapes.mSingle); // 单Shape
    } else {
        // DMA批量读Shape指针数组 (mCount × 8字节)
        dma::Read(shapeManager.mShapes.mSingle, shapePtrArr.data(),
                  shapeManager.mShapes.mCount * 8);
    }
```

**Step 6: 遍历每个Shape → 按几何体类型重建**
```cpp
for (auto& shapePtr : shapePtrArr) {
    PhNpShape shape(shapePtr, true); // DMA包装

    // 读FilterData (偏移+0x50, PxFilterData 16字节)
    auto filterData = shape.GetmFilterData();

    // === 碰撞过滤 ===
    if (filterData.word3 != 19) {
        // word3 ≠ 19 → 非碰撞体(水面/粒子/装饰)
        auto geo = shape.GetmPxGeometry();     // 读类型标识(偏移+0x98)
        if (geo.type != eHEIGHTFIELD) {
            continue; // 丢弃! 地形永远保留
        }
    }
    // word3 == 19 → 实体碰撞 → 保留

    // 读Localpos (偏移+0x70, PxTransform) — Shape在Actor内的本地姿态
    auto localpos = shape.GetmLocalpos();

    // 读几何体数据 (偏移+0x98起)
    auto geometry = shape.GetmPxGeometry();
```

**Step 7: 按类型分支 → 反序列化 + 本地创建**

```
switch (geometry.type):
```

**7a. BOX (eBOX=4)**:
```cpp
    auto box = shape.GetmPxBoxGeometry(); // 读 halfExtents (3个float)
    PxBoxGeometry boxGeo(box.halfExtents);
    PxShape* s = gPhysics->createShape(boxGeo, *gMaterial);
    s->setQueryFilterData(filterData);
    s->setLocalPose(localpos);
    tmpActor->attachShape(*s);
    s->release(); // Shape加入Actor后释放本地引用

    // 静态刚体: 序列化保存
    if (ConcreteType == 7) {
        BoxInfo info{type, GlobalPos, localpos, box.halfExtents};
        info.serialize(filePath); // 写入 model/*.bin
    }
```

**7b. HEIGHTFIELD (eHEIGHTFIELD=7)**:
```cpp
    auto hfGeom = shape.GetmPxHeightFieldGeometry(); // 读scale+指针
    auto hf = hfGeom.GetHeightField();  // DMA读 HeightField 对象

    // 读取高度场元数据 (偏移+0x20起)
    cols = hf.mData.columns;      // 列数
    rows = hf.mData.rows;         // 行数
    nbVerts = rows × cols;

    if (cols >= 1000000) break;   // 安全检查

    // DMA批量读取全部高度样本
    auto sampleBuf = new PxHeightFieldSample[nbVerts];
    dma::Read(hf.mData.samples, sampleBuf, nbVerts * 4); // 每样本4字节

    // 本地cook
    PxHeightFieldDesc desc;
    desc.format = eS16_TM;     // 16位有符号高度 + 材质
    desc.nbColumns = cols;
    desc.nbRows = rows;
    desc.samples.data = sampleBuf;
    desc.samples.stride = 4;
    auto hfObj = gCooking->createHeightField(desc, callback);

    // 创建Geometry + Shape
    PxHeightFieldGeometry hfGeom2(hfObj, flags, heightScale, rowScale, colScale);
    PxShape* s = gPhysics->createShape(hfGeom2, *gMaterial);
    s->setLocalPose(localpos);
    tmpActor->attachShape(*s);

    // 静态: 序列化(含完整sample数组)
    if (ConcreteType == 7) {
        HeightFieldInfo info{..., nbRows, nbCols, sampleBuf};
        info.serialize(filePath);
    }
```

**7c. TRIANGLEMESH (eTRIANGLEMESH=6)**:
```cpp
    auto triGeom = shape.GetmPxTriangleMeshGeometry();
    auto mesh = triGeom.GetTriangleMesh(); // DMA读 TriangleMesh

    // 读网格元数据 (偏移+0x20起)
    nbVerts = mesh.mNbVertices;       // 顶点数
    nbTris = mesh.mNbTriangles;       // 三角形数
    vertsPtr = mesh.mVertices;        // 顶点数组指针
    trisPtr = mesh.mTriangles;        // 索引数组指针
    flags = mesh.mFlags;              // bit1=使用16位索引

    // DMA批量读顶点
    auto verts = new PxVec3[nbVerts];
    dma::Read(vertsPtr, verts, nbVerts × 12);

    // DMA批量读索引
    bool is16bit = (flags & 2) != 0;
    int trisSize = is16bit ? nbTris × 3 × 2 : nbTris × 3 × 4;
    auto indexBuf = new uint8_t[trisSize];
    dma::Read(trisPtr, indexBuf, trisSize);

    // 索引转换 16→32位
    vector<uint32_t> tris32;
    for each tri:
        if 16bit: i0=((uint16*)buf)[n], i1=..., i2=...  (验证<nbVerts)
        push {i0, i1, i2}

    // Cook with BVH34 acceleration
    PxTriangleMeshDesc desc;
    desc.points.count = nbVerts;
    desc.points.data = verts;
    desc.triangles.count = nbTris;
    desc.triangles.data = tris32.data();
    desc.triangles.stride = 12;
    // BVH34 midphase for fast raycast
    PxTolerancesScale scale;
    PxCookingParams params(scale);
    params.midphaseDesc = PxBVH34MidphaseDesc;
    auto cooked = gCooking->cookTriangleMesh(desc, stream);
    auto meshObj = gPhysics->createTriangleMesh(stream);

    PxTriangleMeshGeometry meshGeo(meshObj, scale);
    PxShape* s = gPhysics->createShape(meshGeo, *gMaterial);
    s->setLocalPose(localpos);
    tmpActor->attachShape(*s);

    // 静态: 序列化(保存cooked二进制, 不是原始顶点)
    if (ConcreteType == 7) {
        TriangleMeshInfo info{..., cookedData, cookedSize};
        info.serialize(filePath);
    }
```

**7d. CONVEXMESH (eCONVEXMESH=5)**:
```cpp
    auto convGeom = shape.GetmPxConvexMeshGeometry();
    auto mesh = convGeom.GetConvexMesh(); // DMA读

    // 读凸包数据 (偏移+0x20起)
    nbVerts = mesh.mHullData.mNbHullVertices;
    nbPolys = mesh.mHullData.mNbPolygons;
    polysPtr = mesh.mHullData.mPolygons;

    // 计算顶点缓冲区: 位置在多边形数据之后
    vertsPtr = polysPtr + sizeof(PhHullPolygonData) × nbPolys;

    // DMA批量读顶点
    auto verts = new PxVec3[nbVerts];
    dma::Read(vertsPtr, verts, nbVerts × 12);

    // Cook
    PxConvexMeshDesc desc;
    desc.points.count = nbVerts;
    desc.points.data = verts;
    desc.flags = eCOMPUTE_CONVEX;
    auto convMesh = gCooking->createConvexMesh(desc);

    PxConvexMeshGeometry convGeo(convMesh, scale);
    PxShape* s = gPhysics->createShape(convGeo, *gMaterial);
    s->setLocalPose(localpos);
    tmpActor->attachShape(*s);

    // 静态: 序列化(保存原始顶点)
    if (ConcreteType == 7) {
        ConvexMeshInfo info{..., nbVerts, verts};
        info.serialize(filePath);
    }
```

**Step 8: 添加到本地场景**
```cpp
    // 检查Actor是否有至少一个Shape
    if (tmpActor->getNbShapes() > 0) {
        unique_lock lock(physxEngine::sceneMutex); // 写锁
        gScene->addActor(*tmpActor);                // 加入本地场景
        gLoadSet.insert(actorPtr);                  // 标记已加载
    } else {
        tmpActor->release(); // 空Actor, 释放
    }
```

**Step 9: 磁盘反序列化** (`loadPhysx`)
```cpp
// 读取 model/filename 二进制文件
auto buf = read_file(filePath);
int pos = 0;

while (pos < buf.size()) {
    int16_t mType = *(int16_t*)(buf + pos);

    switch (mType):
        BOX:         BoxInfo::deserialize() → createBox → createShape → attach
        TRIANGLE:    TriangleMeshInfo::deserialize() → createTriangleMesh(cooked) → createShape
        HEIGHTFIELD: HeightFieldInfo::deserialize() → createHeightField(samples) → createShape
        CONVEX:      ConvexMeshInfo::deserialize() → createConvexMesh(verts) → createShape

    createRigidStatic(GlobalPos) → setLocalPose → attachShape → addActor
}
```

### 12.13 关键代码位置索引

| 步骤 | 文件:行号 | 说明 |
|------|----------|------|
| init() | PhysX3.ixx:82 | 获取Physics指针+本地SDK初始化 |
| runPhysx() 入口 | PhysX3.ixx:103 | 主导入循环 |
| 获取场景数组 | PhysX3.ixx:111 | GetNpSencePArray() |
| 批量读Actor指针 | PhysX3.ixx:120-121 | dma::Read一次性读NumElements×8字节 |
| 去重 | PhysX3.ixx:125 | gLoadSet.count(actorPtr) |
| 动态刚体处理 | PhysX3.ixx:136-151 | body2Actor×body2World |
| 静态刚体处理 | PhysX3.ixx:152-164 | Body2World直读 |
| Shape指针展开 | PhysX3.ixx:189-196 | mCount=1 vs 批量读数组 |
| 碰撞过滤 | PhysX3.ixx:209-214 | word3≠19→跳过 |
| BOX重建 | PhysX3.ixx:224-248 | halfExtents→PxBoxGeometry |
| HEIGHTFIELD重建 | PhysX3.ixx:249-296 | 样本数组→createHeightField |
| TRIANGLEMESH重建 | PhysX3.ixx:312-402 | 顶点+索引→cookBV34→createMesh |
| CONVEXMESH重建 | PhysX3.ixx:404-442 | 顶点→createConvexMesh |
| addActor | PhysX3.ixx:490-500 | 加锁→addActor→标记 |
| loadPhysx | PhysX3.ixx:450-530 | 磁盘反序列化 |
| LineTraceSingle | physxEngine.ixx:426 | 射线检测 |
| 磁盘序列化格式 | physxLocal.ixx | BoxInfo/HeightFieldInfo/TriangleMeshInfo/ConvexMeshInfo |

### 12.10 磁盘缓存

```
首次: runPhysx() → DMA重建 → serialize → 保存 model/*.bin
后续: loadPhysx() → 读bin文件 → 反序列化重建 → ~1秒完成

序列化格式 (每条记录):
  [2B type] [固定header] [可变数据]
  type=BOX:   92B header + 无数据
  type=MESH:  90B header + cooked二进制
  type=HF:   108B header + sample原始数组
  type=CONVEX:91B header + 顶点数组
```

### 12.11 本地场景配置

```
GPU加速: eENABLE_GPU_DYNAMICS | eENABLE_PCM
CPU: 4线程dispatcher
重力: (0, -9.81, 0)
材质: friction=0.5, restitution=0.2
线程安全: shared_mutex (读共享, 写独占)

去重: unordered_set<actorPtr> 防止重复加载
安全: nbVerts/nbTris上限 1,000,000, 坐标非零校验
```

