# Asset — 资源管理系统

## 用途

管理引擎所有**外部资源**（模型、纹理、音频、Shader、Prefab）的导入、Cook、运行时加载、卸载与热重载。是内容管线与运行时的枢纽。

## 需要实现的类

### 运行时管理
| 类名 | 职责 |
|------|------|
| `AssetManager` | 全局资源加载/卸载调度 |
| `AssetHandle<T>` | 类型安全资源句柄 |
| `AssetDatabase` | GUID → 路径映射 |
| `AssetReference` | 资源间依赖引用 |
| `AsyncAssetLoader` | 后台线程异步加载 |
| `AssetStreaming` | 流式加载与优先级 |

### 导入与 Cook
| 类名 | 职责 |
|------|------|
| `IAssetImporter` | 导入器接口 |
| `TextureImporter` | PNG/JPG/HDR → 引擎纹理格式 |
| `MeshImporter` | glTF/FBX/OBJ → MeshAsset |
| `AudioImporter` | WAV/OGG → AudioClip |
| `ShaderImporter` | HLSL/GLSL 编译缓存 |
| `AssetCooker` | 开发资源 → `.axpak` 运行时包 |
| `CookManifest` | Cook 结果清单与哈希 |

### 资源类型
| 类名 | 职责 |
|------|------|
| `Asset` | 资源基类 |
| `TextureAsset` | 纹理数据 |
| `MeshAsset` | 网格数据 |
| `MaterialAsset` | 材质定义 |
| `AudioClip` | 音频数据 |
| `PrefabAsset` | 实体模板 |

### 元数据
| 类名 | 职责 |
|------|------|
| `AssetMetadata` | `.axmeta` sidecar 元信息 |
| `ImportSettings` | 每资源导入参数 |

## 目录约定

```
项目根/
├── Assets/          # 美术源文件（开发期）
├── Cooked/          # Cook 输出（运行时加载）
└── Library/         # 导入缓存
```

## 依赖关系

- 依赖：`Core`、`Platform`、`Serialization`
- 被依赖：`Render`、`Audio`、`Animation`、`Scene`、`Tools`

## 完成标准

- [ ] 异步加载不阻塞主线程
- [ ] 引用计数正确，无泄漏
- [ ] 修改源文件触发热重载
