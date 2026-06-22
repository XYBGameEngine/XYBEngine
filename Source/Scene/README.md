# Scene — 场景管理

## 用途

在 ECS 之上提供**场景、关卡、Prefab** 等高层概念，管理实体层级关系、子场景流式加载、以及场景的保存与加载。

## 需要实现的类

### 场景核心
| 类名 | 职责 |
|------|------|
| `Scene` | 一个完整场景，持有 World 子集或引用 |
| `SceneManager` | 多场景加载、激活、卸载 |
| `Level` | 可流式加载的子关卡 |
| `SubScene` | 嵌套场景实例 |
| `SceneSettings` | 环境光、天空盒、物理设置 |

### 层级与 Prefab
| 类名 | 职责 |
|------|------|
| `Hierarchy` | 父子实体关系维护 |
| `Prefab` | 实体模板定义 |
| `PrefabInstance` | Prefab 实例，支持 Override |
| `PrefabOverride` | 记录对实例的属性修改 |

### 序列化
| 类名 | 职责 |
|------|------|
| `SceneSerializer` | `.axscene` 格式读写 |
| `SceneAsset` | 场景资源包装 |

### 流式加载
| 类名 | 职责 |
|------|------|
| `StreamingSource` | 触发加载的区域（玩家位置） |
| `StreamingCell` | 空间网格单元 |
| `AsyncSceneLoader` | 后台加载关卡 |

## 依赖关系

- 依赖：`ECS`、`Asset`、`Serialization`、`Math`
- 被依赖：`Runtime`、`Tools/Editor`、`Network`

## 完成标准

- [ ] 场景 JSON 保存/加载一致
- [ ] Prefab 实例化与 Override 正确
- [ ] 流式加载无明显卡顿
