# Animation — 动画系统

## 用途

管理**骨骼动画、动画状态机、蒙皮网格渲染**，支持动画混合、根运动、动画事件。将美术制作的动画资源驱动到 ECS 实体上。

## 需要实现的类

### 骨架与剪辑
| 类名 | 职责 |
|------|------|
| `Skeleton` | 骨骼层级、Bind Pose |
| `Bone` | 单根骨骼，索引、父节点 |
| `AnimationClip` | 关键帧曲线（位置/旋转/缩放） |
| `AnimationAsset` | 动画资源包装 |

### 蒙皮
| 类名 | 职责 |
|------|------|
| `SkinWeights` | 顶点骨骼权重 |
| `SkinnedMesh` | 蒙皮网格数据 |
| `SkinnedMeshRendererComponent` | ECS 蒙皮渲染组件 |
| `SkinningSystem` | CPU/GPU 蒙皮矩阵计算 |

### 状态机
| 类名 | 职责 |
|------|------|
| `Animator` | 动画播放器 |
| `AnimatorComponent` | ECS 组件 |
| `AnimationStateMachine` | 状态机定义 |
| `AnimationState` | 单状态，关联 Clip |
| `AnimationTransition` | 状态过渡条件与时长 |
| `BlendTree` | 1D/2D 混合树 |
| `AnimationParameter` | Bool/Float/Int 参数 |

### 高级
| 类名 | 职责 |
|------|------|
| `RootMotion` | 根骨骼运动提取 |
| `AnimationEvent` | 动画帧事件回调 |
| `AnimationSystem` | ECS 每帧更新 Animator |

## 依赖关系

- 依赖：`ECS`、`Asset`、`Math`、`Render`
- 被依赖：`Runtime`、`Tools/Editor`

## 完成标准

- [ ] 状态机过渡平滑
- [ ] GPU 蒙皮性能达标（1k 角色基准）
- [ ] 动画事件可触发脚本回调
