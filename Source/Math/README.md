# Math — 数学库

## 用途

提供游戏引擎所需的**线性代数、几何计算、随机数**工具。设计为 header-heavy，热路径支持 SIMD，矩阵约定与 GPU（列主序）一致。

## 需要实现的类

### 向量与矩阵
| 类名 | 职责 |
|------|------|
| `Vector2` / `Vector3` / `Vector4` | 向量运算、点积、叉积、归一化 |
| `Matrix3x3` / `Matrix4x4` | 矩阵乘法、逆、转置 |
| `Quaternion` | 旋转表示、Slerp、与矩阵互转 |
| `Transform` | TRS 组合、父子变换、世界/局部空间 |

### 几何体
| 类名 | 职责 |
|------|------|
| `AABB` | 轴对齐包围盒，合并、相交检测 |
| `OBB` | 有向包围盒 |
| `Sphere` | 球体相交、包含检测 |
| `Plane` | 平面方程、点到平面距离 |
| `Ray` | 射线，与 AABB/Sphere/Plane 求交 |
| `Frustum` | 视锥体，与 AABB 相交（视锥裁剪） |
| `Capsule` | 胶囊体（角色碰撞常用） |

### 工具函数
| 名称 | 职责 |
|------|------|
| `Math::Lerp` / `Slerp` / `Clamp` | 插值与限制 |
| `Math::LookAt` / `Perspective` / `Orthographic` | 矩阵构建 |
| `Math::Decompose` | 矩阵分解为 TRS |
| `Random` / `RandomStream` | 确定性/非确定性随机数 |

### SIMD（可选）
| 类名 | 职责 |
|------|------|
| `SimdVector4` | SSE/NEON 加速路径 |
| `SimdMatrix4` | 批量矩阵运算 |

## 依赖关系

- 依赖：`Source/Core/`
- 被依赖：`Platform`、`RHI`、`Render`、`Physics`、`ECS`、`Animation`、`AI`

## 完成标准

- [ ] 与 glm 参考实现精度对比测试通过
- [ ] Transform 父子层级正确
- [ ] Frustum-AABB 裁剪测试通过
