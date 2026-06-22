# Network — 网络联机系统

## 用途

支持**多人联机**游戏，提供会话管理、状态复制、RPC 调用，以及可选的客户端预测与服务器回滚。

## 需要实现的类

### 连接与会话
| 类名 | 职责 |
|------|------|
| `NetworkManager` | 网络子系统入口 |
| `NetworkSession` | 单次联机会话 |
| `NetworkConnection` | 单条连接（Host/Client） |
| `NetworkTransport` | 底层 UDP（ENet/KCP 封装） |
| `NetworkDiscovery` | 局域网房间发现 |

### 复制
| 类名 | 职责 |
|------|------|
| `NetReplication` | 复制管理器 |
| `ReplicatedComponent` | 需同步的组件标记 |
| `ReplicationGraph` | 相关性过滤、优先级 |
| `NetworkProperty<T>` | 自动同步属性 |
| `NetworkSpawn` | 网络实体生成/销毁 |

### RPC
| 类名 | 职责 |
|------|------|
| `RpcRegistry` | RPC 注册表 |
| `ServerRpc` / `ClientRpc` | 远程过程调用宏/属性 |

### 高级（可选）
| 类名 | 职责 |
|------|------|
| `ClientPrediction` | 客户端预测 |
| `ServerReconciliation` | 服务器 reconciliation |
| `LagCompensation` | 延迟补偿 |

### ECS 集成
| 类名 | 职责 |
|------|------|
| `NetworkIdentityComponent` | 网络 ID、所有者 |
| `NetworkSystem` | 每帧发送/接收包 |

## 依赖关系

- 依赖：`Runtime`、`Serialization`、`ECS`
- 被依赖：`Samples/Networking`、`Tools`

## 完成标准

- [ ] Host/Join 可建立连接
- [ ] Transform 自动同步
- [ ] RPC 双向调用延迟 < 100ms（局域网）
