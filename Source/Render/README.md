# Render — 高层渲染系统

## 用途

在 RHI 之上构建完整的**渲染管线**，包括 RenderGraph、材质系统、网格绘制、光照、相机管理。负责将 ECS 中的可视组件转化为 GPU DrawCall。

## 需要实现的类

### 渲染图
| 类名 | 职责 |
|------|------|
| `RenderGraph` | Pass 依赖 DAG、资源屏障自动插入 |
| `RenderGraphBuilder` | 声明 Pass 输入/输出资源 |
| `RenderPass` | 单个渲染 Pass 基类 |
| `RenderGraphExecutor` | 编译并执行 RenderGraph |

### 场景渲染
| 类名 | 职责 |
|------|------|
| `SceneRenderer` | 收集可见物体、排序、提交绘制 |
| `RenderQueue` | 不透明/透明/Overlay 排序 |
| `Camera` | 视图/投影矩阵、视锥 |
| `CameraComponent` | ECS 相机组件 |
| `Light` / `LightComponent` | 平行光/点光/聚光 |

### 材质与网格
| 类名 | 职责 |
|------|------|
| `Material` | Shader 变体 + 参数块 |
| `MaterialInstance` | 材质实例，覆盖部分参数 |
| `Shader` / `ShaderVariant` | Shader 源码管理与宏变体 |
| `Mesh` | 顶点/索引缓冲、SubMesh |
| `MeshComponent` / `MeshRendererComponent` | ECS 网格渲染组件 |

### 高级特性（可分期）
| 类名 | 职责 |
|------|------|
| `ShadowPass` | 阴影贴图 |
| `PostProcessStack` | 后处理链（Bloom、ToneMap） |
| `Skybox` | 天空盒渲染 |
| `DebugRenderer` | 线框、AABB、射线调试绘制 |

## 依赖关系

- 依赖：`RHI`、`Math`、`Asset`、`ECS`（组件）
- 被依赖：`Runtime`、`UI`、`Tools/Editor`

## 完成标准

- [ ] PBR 材质正确渲染
- [ ] 多光源场景帧率稳定
- [ ] RenderGraph 资源屏障无 GPU 验证层错误
