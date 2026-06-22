# Runtime — 运行时框架

## 用途

引擎的**应用入口与主循环**，管理模块生命周期、帧调度、全局服务定位。是连接所有子系统、启动游戏或编辑器的核心框架。

## 需要实现的类

### 应用
| 类名 | 职责 |
|------|------|
| `Application` | Init / Run / Shutdown 入口 |
| `ApplicationSettings` | 命令行参数、启动配置 |
| `Engine` | 全局单例，子系统访问点 |

### 模块管理
| 类名 | 职责 |
|------|------|
| `IModule` | 模块接口：Startup/Shutdown |
| `ModuleManager` | 注册、依赖排序、生命周期 |
| `ModuleDescriptor` | 模块元数据（名称、依赖列表） |

### 主循环
| 类名 | 职责 |
|------|------|
| `GameLoop` | 主循环驱动 |
| `TickPhase` | 阶段枚举：Input/FixedUpdate/Update/Render |
| `FrameAllocator` | 每帧 Reset 的临时内存 |
| `DeltaTime` | 帧时间、时间缩放、暂停 |

### 服务定位
| 类名 | 职责 |
|------|------|
| `ServiceLocator` | 全局服务注册与获取 |
| `EngineContext` | 持有 AssetManager、World 等指针 |

### 启动流程（顺序）
```
1. ParseCommandLine
2. LoadConfig
3. InitCore (Log, Memory)
4. InitPlatform (Window)
5. InitModules (按依赖拓扑排序)
6. LoadStartupScene
7. GameLoop
8. ShutdownModules (逆序)
```

## 依赖关系

- 依赖：几乎所有 `Source/` 模块（顶层聚合）
- 被依赖：`Samples/`、`Tools/Editor`

## 完成标准

- [ ] 模块依赖循环检测
- [ ] 主循环各阶段耗时可 Profile
- [ ] 优雅关闭，无资源泄漏
