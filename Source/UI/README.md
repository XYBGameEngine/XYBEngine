# UI — 用户界面系统

## 用途

提供**游戏内 UI**（HUD、菜单、设置界面）的渲染与交互，支持 Screen Space 与 World Space 两种 Canvas，处理布局、字体、输入路由。

## 需要实现的类

### Canvas 与层级
| 类名 | 职责 |
|------|------|
| `Canvas` | UI 根容器，渲染模式 |
| `CanvasScaler` | 分辨率适配 |
| `UIRenderer` | UI 批处理提交到 Render |
| `UISystem` | ECS 或独立 System 更新 UI |

### Widget 体系
| 类名 | 职责 |
|------|------|
| `Widget` | UI 元素基类 |
| `Panel` | 容器面板 |
| `Text` | 文本显示 |
| `Image` | 图片/九宫格 |
| `Button` | 按钮，点击/悬停状态 |
| `Slider` | 滑动条 |
| `ScrollView` | 滚动列表 |
| `InputField` | 文本输入框 |

### 布局
| 类名 | 职责 |
|------|------|
| `RectTransform` | 锚点、轴心、尺寸 |
| `LayoutGroup` | 水平/垂直/网格布局 |
| `LayoutElement` | 弹性、最小/首选尺寸 |

### 样式与字体
| 类名 | 职责 |
|------|------|
| `UIStyle` | 颜色、字体、边距主题 |
| `Font` / `FontAtlas` | FreeType 栅格化与图集 |
| `TextMeshGenerator` | 文本网格生成 |

### 输入
| 类名 | 职责 |
|------|------|
| `UIInputRouter` | 命中测试、焦点、事件冒泡 |
| `UIEvent` | Click、Hover、Drag 事件 |

## 依赖关系

- 依赖：`Render`、`Input`、`Asset`（字体/图集）
- 被依赖：`Runtime`、`Tools/Editor`（部分面板可复用）

## 完成标准

- [ ] 锚点布局在不同分辨率正确
- [ ] 按钮点击与 Input Context 协作
- [ ] 批处理减少 DrawCall
