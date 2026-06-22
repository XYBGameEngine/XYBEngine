# AI — 人工智能系统

## 用途

提供**导航网格寻路、行为树、黑板、感知系统**等游戏 AI 基础设施，驱动 NPC 巡逻、追击、决策等行为。

## 需要实现的类

### 导航
| 类名 | 职责 |
|------|------|
| `NavMesh` | 导航网格数据 |
| `NavMeshBuilder` | 从场景几何烘焙 NavMesh |
| `NavMeshAgent` | 寻路代理，速度、半径 |
| `NavMeshAgentComponent` | ECS 组件 |
| `PathFinder` | A* / JPS 寻路 |
| `NavMeshObstacle` | 动态障碍雕刻 |

### 行为树
| 类名 | 职责 |
|------|------|
| `BehaviorTree` | 行为树资产 |
| `BTNode` | 节点基类 |
| `BTSelector` | 选择节点 |
| `BTSequence` | 顺序节点 |
| `BTDecorator` | 装饰器（Inverter、Cooldown） |
| `BTTask` | 叶子任务（MoveTo、Wait、Attack） |
| `BTBlackboard` | 黑板键值存储 |
| `BehaviorTreeComponent` | ECS 组件 |

### 感知
| 类名 | 职责 |
|------|------|
| `AIPerceptionComponent` | 视觉/听觉感知 |
| `AISense_Sight` | 视野锥检测 |
| `AISense_Hearing` | 声音感知 |
| `AIStimulus` | 刺激事件 |

### 控制
| 类名 | 职责 |
|------|------|
| `AIController` | AI 控制器逻辑 |
| `AIControllerComponent` | ECS 组件 |
| `AISystem` | 每帧更新 AI |

## 依赖关系

- 依赖：`ECS`、`Physics`（NavMesh 烘焙）、`Math`、`Scene`
- 被依赖：`Runtime`、`Tools/Editor`

## 完成标准

- [ ] NavMesh 烘焙与寻路正确
- [ ] 行为树 JSON 可配置
- [ ] 感知触发行为切换
