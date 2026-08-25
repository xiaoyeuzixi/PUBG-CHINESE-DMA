## 项目简介

基于 DMA 硬件（FPGA 采集卡）的《和平精英》外部内存读取研究项目。

- **技术栈**: C++20 Modules (.ixx)、DMA (MemProcFS / VMMDLL / leechcore / FTD3XX)、DirectX 11 Overlay、ImGui、PhysX 3
- **目标进程**: `wgprojectm.exe`
- **构建**: Visual Studio 打开 `game.sln`，配置 `x64 / Release`

## 目录结构

| 目录 / 文件 | 说明 |
|------|------|
| `game.cpp` | 主入口与核心逻辑 (~4700 行)：数据线程、ESP 绘制、菜单 |
| `Offsets.ixx` / `Struct.ixx` | 内存偏移量与核心结构体定义 |
| `Engine/` | UE4 引擎抽象层 (UWorld / AActor / PlayerController 等) |
| `gameixx/` | 游戏特定类 (角色 / 武器 / 载具) |
| `PhysX3/` | 从内存重建物理场景，用于可见性射线检测 |
| `dma/` | DMA 驱动封装 (vmm.dll / leechcore.dll) |
| `Esp/` | DX11 渲染封装 |
| `NetConfig/` | 硬件盒子驱动 (KmBox / KmBoxNet / Lurker / MoBox) |
| `imgui/` / `ThirdParty/` | UI 库与 freetype |
| `DEVELOPMENT_DOC.md` | 详细开发文档 (含全部函数索引与算法说明) |

## 数据流

```
FPGA DMA 卡 → VMMDLL 散装读取 → UWorld → ULevel → Actor 数组分类
    → 多线程缓存 (atomic<shared_ptr> + mutex)
    → WorldToScreen 投影 → DX11 + ImGui 覆盖窗口绘制
```

## 注意事项

- `model/model.bin` (约 925MB) 与 `PhysxLib/*.lib` 不入库：前者超过 GitHub 单文件限制，后者可由 `PhysxLib.7z` 解压恢复。
- 编译依赖的 DLL (`vmm.dll` / `leechcore.dll` / `FTD3XX.dll`) 已随仓库保存。

---

## ⚠️ 免责声明 (Disclaimer)

1. **本仓库及其全部内容仅供个人学习、研究与技术研究用途**，任何人不得将其用于任何违法违规活动。
2. 使用此类技术可能违反游戏用户协议，并可能导致游戏账号封禁及其他后果。**使用者的一切行为及后果由其本人自行承担**，与本项目作者无关。
3. **严禁将本项目或其衍生内容用于商业用途，严禁二次分发、转售、公开传播**（包括但不限于公开网盘、公开代码托管平台、社群渠道发布）。
4. 本项目不提供任何形式的技术支持与使用担保，按"现状"提供 (AS IS)，作者不对因使用或滥用本项目造成的任何直接或间接损失负责。
5. 如本项目的存在违反了您所在地区的法律法规或相关平台条款，请立即停止访问与使用。
6. 一经下载、克隆或浏览本仓库内容，即视为已完整阅读、理解并同意上述全部条款。

## 交流群

- QQ 群：`835775657`

> 再次提醒：本群与本仓库均仅限技术交流，禁止在群内及任何渠道传播、贩卖本仓库内容。
