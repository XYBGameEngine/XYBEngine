# Physics — 物理系统

## 用途

提供**刚体动力学、碰撞检测、射线检测、触发器**等物理模拟能力。可封装 Jolt/PhysX 等成熟库，通过 ECS Component 与 System 与游戏逻辑集成。

## 需要实现的类

### 物理世界
| 类名 | 职责 |
|------|------|
| `PhysicsWorld` | 物理模拟世界，步进、重力 |
| `PhysicsSettings` | 固定时间步、求解器迭代次数 |
| `PhysicsSystem` | ECS System，驱动步进与同步 Transform |
| `CollisionLayer` / `CollisionMatrix` | 碰撞层过滤 |

### 刚体与碰撞体
| 类名 | 职责 |
|------|------|
| `RigidBodyComponent` | 质量、阻尼、运动学/动力学 |
| `ColliderComponent` | 碰撞体基类 |
| `BoxCollider` | 盒碰撞体 |
| `SphereCollider` | 球碰撞体 |
| `CapsuleCollider` | 胶囊碰撞体 |
| `MeshCollider` | 网格碰撞（Convex/Concave） |
| `PhysicsMaterial` | 摩擦、弹性 |

### 查询与事件
| 类名 | 职责 |
|------|------|
| `RaycastHit` | 射线检测结果 |
| `PhysicsQuery` | Raycast、Overlap、Sweep |
| `CollisionEvent` | 碰撞开始/持续/结束 |
| `TriggerEvent` | 触发器进入/退出 |

### 实现封装
```
Physics/
├── Public/
└── Impl/
    └── Jolt/        # JoltPhysics 封装
```

## 依赖关系

- 依赖：`Math`、`ECS`、`Scene`（Transform 同步）
- 被依赖：`AI`（NavMesh）、`Runtime`、`Tools/Editor`

## 完成标准

- [ ] 刚体自由落体与碰撞正确
- [ ] 射线检测准确
- [ ] FixedUpdate 与渲染帧解耦
