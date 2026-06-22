# Config — 引擎配置

## 用途

存放引擎**编译期与运行期**的全局配置文件，包括功能开关、默认参数、平台特性表。代码通过 `EngineConfig.h`（生成）或 INI 解析器读取。

## 需要实现的类 / 文件

| 名称 | 类型 | 职责 |
|------|------|------|
| `Engine.ini` | 配置文件 | 运行时默认参数（窗口大小、日志级别） |
| `EngineFeatures.json` | 配置文件 | 功能开关清单及默认值 |
| `PlatformProfiles/` | 目录 | 各平台渲染/音频配置 |
| `ConfigLoader` | C++ 类 | 解析 INI/JSON，提供 `GetBool/GetInt/GetString` |
| `CVar` | C++ 类 | 运行时控制台变量（可调参数） |
| `CVarRegistry` | C++ 类 | 注册与查找 CVar，支持序列化到配置 |
| `FeatureMacros.h.in` | CMake 模板 | 生成 `AXYB_ENABLE_*` 宏头文件 |

## 配置项示例

```ini
[Window]
Width=1280
Height=720
Fullscreen=false

[Render]
Backend=Vulkan
VSync=true
MSAA=4

[Log]
Level=Info
File=logs/engine.log
```

## 依赖关系

- 依赖：`Source/Core/`（字符串、日志）
- 被依赖：`Source/Runtime/`、所有需要功能开关的模块

## 完成标准

- [ ] 编译期宏与运行期配置双层生效
- [ ] Editor 可修改并热重载非编译期配置
