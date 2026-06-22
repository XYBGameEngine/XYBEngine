# Debugger — 运行时调试器

## 用途

在游戏或 Editor 运行时提供**调试叠加层**（Dear ImGui），显示性能数据、内存统计、ECS 检视、控制台命令，辅助开发与性能优化。

## 需要实现的类

### 调试框架
| 类名 | 职责 |
|------|------|
| `DebugOverlay` | ImGui 叠加层管理 |
| `DebugPanel` | 单个调试面板基类 |
| `DebugMenu` | 面板开关菜单 |

### 性能
| 类名 | 职责 |
|------|------|
| `CpuProfiler` | CPU 时间轴标记 |
| `GpuProfiler` | GPU 时间戳查询 |
| `ProfilerPanel` | 火焰图/时间轴 UI |
| `FrameStats` | FPS、DrawCall、三角形数 |

### 检视
| 类名 | 职责 |
|------|------|
| `ECSInspectorPanel` | 实体/组件浏览编辑 |
| `MemoryPanel` | 分配器统计、泄漏列表 |
| `RenderDebugPanel` | 线框、Mip、Overdraw 模式 |

### 控制台
| 类名 | 职责 |
|------|------|
| `DebugConsole` | 命令行输入 |
| `CVarConsole` | 运行时修改 CVar |
| `LogViewer` | 日志过滤显示 |

### 远程（可选）
| 类名 | 职责 |
|------|------|
| `RemoteDebugger` | TCP 连接 PC 调试移动设备 |
| `DebugProtocol` | 序列化调试消息 |

## 依赖关系

- 依赖：`Runtime`、`Render`（ImGui 渲染）、`ECS`
- 被依赖：`Editor`（可嵌入）、`Samples`

## 完成标准

- [ ] F1 切换调试层显示
- [ ] Profiler 可定位热点函数
- [ ] ECS Inspector 可实时改组件
