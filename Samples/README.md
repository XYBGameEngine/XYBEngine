# Samples — 示例项目

## 用途

提供**由浅入深**的示例游戏/演示，帮助新开发者学习引擎 API，并作为回归测试的手动验证场景。

## 示例清单

### 1. HelloTriangle（阶段 3 里程碑）
| 项目 | 说明 |
|------|------|
| 路径 | `Samples/HelloTriangle/` |
| 功能 | 最小 RHI 初始化、着色器、三角形 |
| 学习点 | Window、RHI、Shader 编译 |

### 2. HelloECS（阶段 4 里程碑）
| 项目 | 说明 |
|------|------|
| 路径 | `Samples/HelloECS/` |
| 功能 | 创建实体、System 旋转立方体 |
| 学习点 | ECS、Scene、GameLoop |

### 3. ThirdPerson（阶段 5–6 里程碑）
| 项目 | 说明 |
|------|------|
| 路径 | `Samples/ThirdPerson/` |
| 功能 | 第三人称角色、动画、物理、音频 |
| 学习点 | Animation、Physics、Input、Camera |

### 4. UIDemo（阶段 6 里程碑）
| 项目 | 说明 |
|------|------|
| 路径 | `Samples/UIDemo/` |
| 功能 | HUD、菜单、设置界面 |
| 学习点 | UI Canvas、布局、事件 |

### 5. Networking（阶段 7 里程碑）
| 项目 | 说明 |
|------|------|
| 路径 | `Samples/Networking/` |
| 功能 | 双人联机射击/对战 |
| 学习点 | Network、Replication、RPC |

## 每个 Sample 的标准结构

```
Samples/ThirdPerson/
├── CMakeLists.txt
├── Source/
│   └── Main.cpp
├── Assets/          # 示例专用资源
└── README.md        # 运行说明
```

## 依赖关系

- 依赖：`AXYBEngine_Runtime` 库
- 不依赖：其他 Sample

## 完成标准

- [ ] 新用户按 README 30 分钟内跑通 HelloTriangle
- [ ] 各 Sample 有独立 README 说明操作
- [ ] Sample 可作为 CI Smoke Test
