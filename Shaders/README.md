# Shaders — 着色器库

## 用途

存放引擎所有 **GPU Shader 源码**（HLSL/GLSL），按功能分类。由 `RHI/ShaderCompiler` 编译为后端字节码，由 `Render` 模块在运行时加载。

## 目录结构

```
Shaders/
├── Common/              # 公共 include
│   ├── Common.hlsl
│   ├── Math.hlsl
│   ├── Lighting.hlsl
│   └── BRDF.hlsl
├── PBR/                 # PBR 光照
│   ├── PBR_Forward.vert
│   ├── PBR_Forward.frag
│   └── PBR_Deferred.frag
├── Shadow/
│   └── ShadowDepth.vert
├── PostProcess/
│   ├── Bloom.frag
│   ├── ToneMapping.frag
│   └── FXAA.frag
├── UI/
│   ├── UI.vert
│   └── UI.frag
├── Compute/
│   ├── FrustumCull.comp
│   └── ParticleUpdate.comp
└── Debug/
    └── DebugLine.vert
```

## 命名规范

| 规则 | 示例 |
|------|------|
| 阶段后缀 | `.vert` `.frag` `.comp` |
| 材质变体宏 | `PBR_Forward.frag` + `#define USE_NORMAL_MAP` |
| Include 路径 | `#include "Common/Math.hlsl"` |
| 常量缓冲 | `cbuffer PerFrame : register(b0)` |

## 需要实现的配套（在 RHI/Render 中）

| 类名 | 职责 |
|------|------|
| `ShaderIncludeResolver` | 解析 #include 路径 |
| `ShaderPreprocessor` | 宏定义与变体生成 |
| `ShaderCache` | 编译结果磁盘缓存 |

## 依赖关系

- 被依赖：`RHI`、`Render`、`UI`
- 编译：由 `Build/` 或 `AssetProcessor` 在 Cook 时处理

## 完成标准

- [ ] 所有 Shader 在三后端可编译（或定义支持矩阵）
- [ ] Include 无循环依赖
- [ ] 变体数量可控（材质实例化宏）
