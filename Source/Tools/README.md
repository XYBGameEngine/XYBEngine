# Tools — 工具链总览

## 用途

存放引擎**编辑器、资源处理器、调试器**等工具代码。工具链与 Runtime 共享大部分 `Source/` 模块，但以独立可执行文件形式构建。

## 子模块

| 子目录 | 可执行文件 | 职责 |
|--------|-----------|------|
| `Editor/` | `AXYBEditor` | 可视化关卡编辑器 |
| `AssetProcessor/` | `AXYBAssetProcessor` | 命令行资源 Cook |
| `Debugger/` | 内嵌或 `AXYBDebugger` | 运行时调试叠加层 |

## 公共基础设施

| 类名 | 职责 |
|------|------|
| `ToolApplication` | 工具应用基类 |
| `CommandLineParser` | 命令行参数解析 |
| `EditorSettings` | 编辑器偏好持久化 |

## 依赖关系

- 依赖：`Runtime` 及全部游戏模块
- 不依赖：无（顶层工具）

## 构建顺序

1. `AssetProcessor`（仅需 Asset 模块，可最早开发）
2. `Debugger`（ImGui 叠加，依赖 Runtime）
3. `Editor`（最后，依赖全部）

## 完成标准

- [ ] 三个工具均可独立启动
- [ ] Editor Play-In-Editor 可运行游戏
