# Platform — 平台抽象层

## 用途

屏蔽 **Windows / Linux / macOS** 操作系统差异，提供文件系统、动态库、线程、进程、环境查询、**窗口与事件**等统一接口。是连接 OS 与引擎的桥梁。

## 需要实现的类

### 文件与路径
| 类名 | 职责 |
|------|------|
| `IFileSystem` | 读写文件、目录遍历、存在性检查 |
| `FileHandle` | RAII 文件句柄 |
| `Path` | 路径拼接、规范化、扩展名操作 |
| `FileWatcher` | 目录/文件变更监视（热重载用） |

### 动态库与进程
| 类名 | 职责 |
|------|------|
| `IDynamicLibrary` | 加载/卸载 DLL/so/dylib，符号查找 |
| `Process` | 启动子进程、管道通信 |
| `Environment` | 环境变量读写 |

### 系统信息
| 类名 | 职责 |
|------|------|
| `PlatformInfo` | CPU 核心数、物理内存、OS 版本 |
| `CpuFeatures` | SSE/AVX/NEON 特性检测 |

### 窗口子系统 (`Platform/Window/`)
| 类名 | 职责 |
|------|------|
| `IWindow` | 创建、销毁、标题、尺寸、全屏 |
| `WindowEvent` | Resize、Close、Focus、Drop 事件 |
| `WindowEventDispatcher` | 事件泵与回调分发 |
| `Win32Window` / `SDLWindow` | 平台具体实现 |
| `NativeWindowHandle` | 供 RHI SwapChain 使用的 HWND/NSView |

### 实现目录
```
Platform/
├── Public/          # 接口头文件
├── Impl/
│   ├── Windows/
│   ├── Linux/
│   ├── macOS/
│   └── SDL/         # 可选跨平台后端
└── Window/
```

## 依赖关系

- 依赖：`Source/Core/`
- 被依赖：`Input`、`RHI`、`Audio`、`Asset`、`Runtime`、`Tools`

## 完成标准

- [ ] 三平台文件读写一致
- [ ] 窗口可创建并响应关闭事件
- [ ] NativeWindowHandle 可传给 RHI
