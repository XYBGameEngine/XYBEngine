# Scripting — 脚本系统

## 用途

允许设计师/策划通过**脚本语言**（推荐 Lua）扩展游戏逻辑，无需重新编译引擎。提供实体 API 绑定、热重载、以及与 ECS 的集成。

## 需要实现的类

### 脚本引擎
| 类名 | 职责 |
|------|------|
| `ScriptEngine` | VM 生命周期管理 |
| `ScriptContext` | 独立脚本上下文（隔离） |
| `ScriptModule` | 单个脚本文件模块 |
| `ScriptManager` | 加载、卸载、热重载调度 |

### 绑定
| 类名 | 职责 |
|------|------|
| `ScriptBindings` | 注册 C++ API 到脚本 |
| `EntityScriptApi` | Entity、AddComponent 等 |
| `TransformScriptApi` | 位置、旋转操作 |
| `InputScriptApi` | 输入查询 |
| `TimerScriptApi` | 延迟、定时器 |
| `ScriptCallable` | C++ 函数导出宏 |

### ECS 集成
| 类名 | 职责 |
|------|------|
| `ScriptComponent` | 挂载脚本文件路径 |
| `ScriptSystem` | 调用脚本的 OnStart/OnUpdate/OnDestroy |

### 热重载
| 类名 | 职责 |
|------|------|
| `ScriptHotReloader` | 监视文件变更，重新加载 |
| `ScriptErrorHandler` | 脚本错误报告到 Editor 控制台 |

### 实现
```
Scripting/
├── Public/
└── Impl/
    └── Lua/         # sol2 + Lua 5.4
```

## 依赖关系

- 依赖：`ECS`、`Runtime`、`Core`
- 被依赖：`Tools/Editor`（脚本编辑）

## 完成标准

- [ ] 脚本可驱动实体移动
- [ ] 热重载不崩溃
- [ ] 脚本错误可定位到行号
