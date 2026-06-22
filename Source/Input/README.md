# Input — 输入系统

## 用途

统一管理**键盘、鼠标、手柄**等输入设备，提供高层 **Action 映射**（如 "Jump"、"MoveForward"），支持上下文切换（Gameplay / UI / Menu），并与 GameLoop 帧对齐。

## 需要实现的类

### 设备层
| 类名 | 职责 |
|------|------|
| `IInputDevice` | 输入设备抽象 |
| `Keyboard` | 按键状态、按下/释放/持续 |
| `Mouse` | 位置、Delta、滚轮、按键 |
| `Gamepad` | 摇杆、扳机、按钮（支持多手柄） |
| `InputManager` | 设备注册、每帧 Poll |

### Action 映射
| 类名 | 职责 |
|------|------|
| `InputAction` | 命名动作定义（Digital / Axis1D / Axis2D） |
| `InputBinding` | 动作到设备按键/轴的绑定 |
| `InputActionMap` | 一组动作的集合 |
| `InputContext` | 上下文（Gameplay、UI），可 Push/Pop 切换 |
| `InputConfig` | 从 JSON 加载绑定配置 |

### 消费层
| 类名 | 职责 |
|------|------|
| `InputConsumer` | 查询动作当前值、触发事件 |
| `InputBuffer` | 帧间输入缓冲（格斗游戏连招） |

### ECS 集成
| 类名 | 职责 |
|------|------|
| `InputSystem` | 每帧更新 InputManager，写入组件或事件 |

## 配置示例 (`InputActions.json`)

```json
{
  "actions": [
    { "name": "Move", "type": "Axis2D" },
    { "name": "Jump", "type": "Digital" }
  ],
  "bindings": [
    { "action": "Move", "device": "Keyboard", "keys": ["W","A","S","D"] },
    { "action": "Jump", "device": "Keyboard", "key": "Space" }
  ]
}
```

## 依赖关系

- 依赖：`Source/Core/`、`Source/Platform/`
- 被依赖：`Runtime`、`UI`、`Scripting`

## 完成标准

- [ ] 键盘鼠标手柄均可 Poll
- [ ] Action 上下文切换正确
- [ ] UI 层可拦截输入事件
