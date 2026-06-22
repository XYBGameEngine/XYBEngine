# Core — 核心基础库

## 用途

引擎最底层模块，提供**内存管理、基础容器、字符串、日志、断言、时间、线程同步**等基础设施。不依赖引擎任何其他模块，是所有模块的根基。

## 需要实现的类

### 内存管理
| 类名 | 职责 |
|------|------|
| `IAllocator` | 分配器抽象接口 |
| `SystemAllocator` | 默认堆分配（malloc/new） |
| `LinearAllocator` | 线性/帧分配器，支持 Reset |
| `PoolAllocator` | 固定大小对象池 |
| `StackAllocator` | 栈式分配，LIFO 释放 |
| `MemoryTracker` | Debug 模式泄漏检测与统计 |

### 容器与字符串
| 类名 | 职责 |
|------|------|
| `Array<T>` | 动态数组，连续内存 |
| `HashMap<K,V>` | 哈希表 |
| `String` / `StringView` | 引擎字符串，小字符串优化 |
| `UniquePtr<T>` / `SharedPtr<T>` | 智能指针（可包装 std 或自研） |

### 日志与诊断
| 类名 | 职责 |
|------|------|
| `ILogger` | 日志接口 |
| `LogCategory` | 分类日志（Core、Render、Physics…） |
| `LogSink` | 输出目标（Console、File、Editor） |
| `Assert` | `AXYB_CHECK` / `AXYB_ENSURE` 宏 |

### 时间与线程
| 类名 | 职责 |
|------|------|
| `Timer` / `Clock` | 高精度计时 |
| `FrameTimer` | 帧率、DeltaTime 计算 |
| `Thread` | 平台线程封装 |
| `Mutex` / `RWLock` / `ConditionVariable` | 同步原语 |
| `TaskQueue` / `ThreadPool` | 异步任务调度 |

### 基础类型
| 类名 | 职责 |
|------|------|
| `GUID` | 全局唯一标识符 |
| `Result<T,E>` | 错误处理（无异常路径） |
| `Optional<T>` | 可选值 |
| `TypeInfo` | 类型名、大小（反射基础） |

## 子目录建议

```
Core/
├── Memory/
├── Containers/
├── String/
├── Log/
├── Thread/
├── Math/        # 仅基础类型，非完整 Math 模块
└── Public/      # 对外头文件
```

## 依赖关系

- **无上游依赖**
- 被依赖：所有 `Source/` 模块

## 完成标准

- [ ] 单元测试覆盖 Allocator、Array、HashMap
- [ ] 日志可在三平台正常输出
- [ ] 线程池可并行执行任务
