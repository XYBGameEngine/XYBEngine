# Assets — 引擎内置资源

## 用途

存放引擎自带的**默认资源**（Shader 模板、字体、图标、默认材质、占位纹理），随引擎 SDK 一起分发。不包含项目特定美术资源。

## 目录结构

```
Assets/
├── Shaders/         # 默认 Shader（或与 Shaders/ 符号链接）
├── Materials/       # 默认材质（DefaultPBR.axmat）
├── Textures/        # 占位纹理（Checker、White、Normal）
├── Fonts/           # 默认 UI 字体（Roboto、NotoSansSC）
├── Icons/           # Editor 图标
├── Audio/           # 默认 UI 音效
└── Meshes/          # 基础图元（Cube、Sphere、Plane）
```

## 需要管理的元数据

| 文件 | 职责 |
|------|------|
| `*.axmeta` | 每个资源的导入设置 |
| `EngineContent.manifest` | 内置资源清单与 GUID |

## 版本与分发

| 策略 | 说明 |
|------|------|
| Git LFS | 大二进制资源（纹理、音频）使用 LFS |
| Cook | 发布 SDK 时预 Cook 到 `Cooked/Engine/` |
| 许可证 | `Fonts/` 和第三方图标需保留 LICENSE |

## 依赖关系

- 被 `AssetProcessor` Cook
- 被 `Editor`、`Samples` 引用

## 完成标准

- [ ] 无项目资源时引擎仍可启动（使用内置默认）
- [ ] 许可证文件齐全
- [ ] SDK 打包包含 Cooked 版本
