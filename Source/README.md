# Source — 引擎源代码根目录

## 用途

存放 AXYBEngine 所有**运行时与工具** C++ 源代码。按模块划分子目录，每个模块独立 CMake target，依赖关系单向向下。

## 模块一览

| 模块 | 路径 | 层级 |
|------|------|------|
| Core | `Core/` | L0 基础 |
| Math | `Math/` | L0 基础 |
| Platform | `Platform/` | L0 基础 |
| Serialization | `Serialization/` | L0 基础 |
| Input | `Input/` | L1 平台 |
| RHI | `RHI/` | L2 图形底层 |
| Render | `Render/` | L3 图形高层 |
| Asset | `Asset/` | L2 资源 |
| ECS | `ECS/` | L3 游戏数据 |
| Scene | `Scene/` | L4 游戏世界 |
| Physics | `Physics/` | L4 模拟 |
| Animation | `Animation/` | L4 模拟 |
| Audio | `Audio/` | L4 模拟 |
| UI | `UI/` | L4 表现 |
| Scripting | `Scripting/` | L4 逻辑 |
| AI | `AI/` | L5 游戏逻辑 |
| Network | `Network/` | L5 联机 |
| Runtime | `Runtime/` | L6 应用框架 |
| Tools | `Tools/` | L7 工具链 |

## 构建顺序

参见项目根目录 `README.md` 第二节「推荐构建顺序」。

## 模块规范

- 每个模块包含 `Public/`（对外 API）和 `Private/`（内部实现）
- 模块间通过 `Public/` 头文件通信，禁止 include 其他模块 `Private/`
- 每个模块一个 `README.md` 说明职责与类清单
