# RHI — Render Hardware Interface（渲染硬件抽象）

## 用途

对 **Vulkan / D3D12 / Metal** 等图形 API 进行后端无关的抽象，向上层 `Render` 模块提供统一的 GPU 资源与命令录制接口。是图形管线的核心基础设施。

## 需要实现的类

### 设备与队列
| 类名 | 职责 |
|------|------|
| `IRHIDevice` | GPU 设备创建、能力查询 |
| `IRHICommandQueue` | 图形/计算/拷贝队列 |
| `IRHICommandBuffer` | 命令录制、Submit |
| `RHIFence` / `RHISemaphore` | GPU 同步 |

### 资源
| 类名 | 职责 |
|------|------|
| `IRHIBuffer` | Vertex/Index/Uniform/Storage Buffer |
| `IRHITexture` | 2D/3D/Cube 纹理 |
| `IRHISampler` | 采样器状态 |
| `IRHIView` | Buffer/Texture 视图（SRV/UAV/RTV/DSV） |
| `IRHIFramebuffer` | 渲染目标集合 |
| `IRHIRenderPass` | RenderPass 描述（Vulkan 风格） |

### 管线与着色器
| 类名 | 职责 |
|------|------|
| `IRHIShader` | 顶点/片段/计算 Shader 模块 |
| `IRHIPipelineState` | 图形/计算管线状态对象 |
| `IRHIDescriptorSetLayout` | 描述符集布局 |
| `IRHIDescriptorSet` | 描述符集绑定 |
| `RHIShaderCompiler` | HLSL/GLSL → SPIR-V/DXIL 编译 |

### 呈现
| 类名 | 职责 |
|------|------|
| `IRHISwapChain` | 交换链、Present、Resize |
| `RHIResourceManager` | 资源分配、延迟销毁、内存统计 |

### 后端实现
```
RHI/
├── Public/
└── Impl/
    ├── Vulkan/     # VulkanRenderDevice, VulkanBuffer...
    ├── D3D12/      # D3D12RenderDevice...
    └── Null/       # Headless 测试后端
```

## 依赖关系

- 依赖：`Source/Core/`、`Source/Math/`、`Source/Platform/`（窗口句柄）
- 被依赖：`Source/Render/`、`Source/UI/`

## 完成标准

- [ ] 清屏 + Present 可运行
- [ ] 创建 Buffer/Texture 并上传数据
- [ ] 录制 DrawCall 并正确同步
