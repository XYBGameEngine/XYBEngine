# Tests — 自动化测试

## 用途

存放引擎各模块的**单元测试、集成测试、性能基准测试**，通过 GoogleTest + CTest 在 CI 中自动运行，保障重构安全。

## 目录结构

```
Tests/
├── Core/           # Allocator、Container、Log
├── Math/           # Vector、Matrix、Quaternion
├── Serialization/  # JSON/Binary 往返
├── ECS/            # Query、System
├── Asset/          # 导入器、Cook
├── RHI/            # Headless 渲染测试
├── Render/         # 截图对比（可选）
├── Physics/        # 碰撞、射线
├── Integration/    # 跨模块集成
└── Benchmarks/     # 性能基准
```

## 需要实现的类 / 文件

| 名称 | 职责 |
|------|------|
| `TestMain.cpp` | GoogleTest 入口 |
| `TestUtils.h` | 公共测试工具（临时目录、Mock） |
| `MockFileSystem` | Platform 层 Mock |
| `NullRHI` | 无 GPU 的 RHI 后端 |
| `TestFixtures/` | 共享测试夹具 |

## 测试原则

- 每个 `Source/` 模块至少有一个对应测试目录
- 核心路径覆盖率目标：**80%+**
- 集成测试覆盖：场景加载 → 渲染一帧 → 关闭

## 依赖关系

- 依赖：被测模块 + GoogleTest
- 被依赖：`Build/CI`

## 完成标准

- [ ] `ctest` 全部通过
- [ ] CI 每次 PR 自动运行
- [ ] Benchmark 可检测性能回退
