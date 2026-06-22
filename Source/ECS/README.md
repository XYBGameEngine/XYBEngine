# ECS — 实体组件系统

## 用途

引擎的**核心数据模型**，用 Entity-Component-System 架构组织游戏对象。追求缓存友好的 SoA 布局、灵活的 Query 以及可并行的 System 调度。

## 需要实现的类

### 核心
| 类名 | 职责 |
|------|------|
| `Entity` | 轻量 ID（index + generation） |
| `EntityManager` | 实体创建/销毁/有效性检查 |
| `ComponentPool<T>` | 某类型组件的 SoA 存储 |
| `World` | 实体 + 组件 + 系统的容器 |
| `IComponent` | 组件标记接口（可选） |

### 查询与系统
| 类名 | 职责 |
|------|------|
| `Query` | 按 Component 签名筛选实体 |
| `QueryBuilder` | 构建 Query（With/Without/Optional） |
| `ISystem` | 系统接口：`OnCreate/OnUpdate/OnDestroy` |
| `SystemScheduler` | System 依赖排序、并行执行 |
| `SystemGroup` | System 分组（FixedUpdate、Render） |

### 常用内置组件（示例）
| 类名 | 职责 |
|------|------|
| `TransformComponent` | 位置、旋转、缩放 |
| `NameComponent` | 调试名称 |
| `TagComponent` | 标签过滤 |
| `ActiveComponent` | 启用/禁用 |

### 序列化
| 类名 | 职责 |
|------|------|
| `ComponentRegistry` | 组件类型注册与序列化 |
| `WorldSerializer` | World ↔ JSON/Binary |

## 依赖关系

- 依赖：`Core`、`Math`、`Serialization`
- 被依赖：`Scene`、`Render`、`Physics`、`Animation`、`AI`、`Scripting`、`Network`

## 完成标准

- [ ] 10 万实体 Query 耗时 < 1ms
- [ ] System 并行无数据竞争
- [ ] 组件可序列化/反序列化
