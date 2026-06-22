# Editor — 关卡编辑器

## 用途

提供**可视化开发环境**，包括场景视口、层级面板、属性检视器、资源浏览器、控制台。支持编辑模式与 Play-In-Editor（PIE）。

## 需要实现的类

### 编辑器应用
| 类名 | 职责 |
|------|------|
| `EditorApplication` | 继承 Application，增加编辑模式 |
| `EditorEngine` | 编辑器专用 Engine 子类 |
| `EditorMode` | 编辑 / 播放 / 暂停 模式切换 |
| `PlayMode` | PIE 运行时隔离 |

### 视口
| 类名 | 职责 |
|------|------|
| `EditorViewport` | 场景 3D 视口 |
| `EditorCamera` | 飞行相机控制 |
| `Gizmo` | 移动/旋转/缩放 Gizmo |
| `GridRenderer` | 地面网格 |
| `Picking` | 鼠标点选实体 |

### 面板
| 类名 | 职责 |
|------|------|
| `EditorPanel` | 面板基类 |
| `HierarchyPanel` | 实体层级树 |
| `InspectorPanel` | 属性编辑（反射驱动） |
| `AssetBrowserPanel` | 资源浏览与导入 |
| `ConsolePanel` | 日志过滤与命令 |
| `ViewportPanel` | 视口容器 |

### 命令系统
| 类名 | 职责 |
|------|------|
| `Command` | 命令基类 |
| `UndoStack` | 撤销/重做栈 |
| `CopyPasteManager` | 实体复制粘贴 |
| `SelectionManager` | 当前选中对象 |

### 菜单与工具栏
| 类名 | 职责 |
|------|------|
| `MainMenuBar` | 文件/编辑/窗口菜单 |
| `Toolbar` | 播放/暂停/停止按钮 |

## 技术选型建议

- **UI 框架**：Qt 6（专业编辑器）或 Dear ImGui（轻量快速）
- **与 Runtime 共享**：ECS、Render、Scene 代码直接链接

## 依赖关系

- 依赖：全部 `Source/` 模块
- 被依赖：无

## 完成标准

- [ ] 可搭建场景并保存
- [ ] Inspector 可编辑 Component 属性
- [ ] PIE 可运行并返回编辑模式
