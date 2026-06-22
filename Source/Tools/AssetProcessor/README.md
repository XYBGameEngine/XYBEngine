# AssetProcessor — 资源处理器

## 用途

**命令行/CI 工具**，批量导入和 Cook 项目 `Assets/` 目录下的资源，输出运行时包。支持增量 Cook、依赖分析和 headless 模式。

## 需要实现的类

| 类名 | 职责 |
|------|------|
| `AssetProcessorApp` | 命令行入口 main |
| `CookPipeline` | Cook 流程编排 |
| `CookJob` | 单个资源的 Cook 任务 |
| `CookScheduler` | 多进程/多线程调度 |
| `DependencyGraph` | 资源依赖图构建 |
| `IncrementalCook` | 基于文件哈希跳过未变更 |
| `CookReporter` | 输出报告（成功/失败/耗时） |
| `FileWatcherMode` | 监视目录自动 Cook |

## CLI 接口

```bash
AXYBAssetProcessor --project <path> --cook-all
AXYBAssetProcessor --project <path> --cook <asset_guid>
AXYBAssetProcessor --project <path> --watch
AXYBAssetProcessor --project <path> --report
```

## 依赖关系

- 依赖：`Asset`、`Platform`、`Serialization`
- 被依赖：CI、`Editor`（可调用）

## 完成标准

- [ ] 全量 Cook 可在 CI headless 运行
- [ ] 增量 Cook 正确跳过未修改资源
- [ ] 失败时返回非零退出码
