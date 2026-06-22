# BuildTool — 构建系统

## 用途

本目录存放引擎的**编译、打包、CI/CD** 相关脚本与配置，是整个项目的工程入口。不包含任何游戏逻辑代码。

## 需要实现的类 / 文件

| 名称 | 类型 | 职责 |
|------|------|------|
| `CMakeLists.txt` | 构建脚本 | 根工程定义、子目录 add_subdirectory |
| `AXYBConfig.cmake` | CMake 模块 | 引擎安装后的 find_package 支持 |
| `CompilerFlags.cmake` | CMake 模块 | 平台编译器警告、优化、SAN 选项 |
| `PlatformDetection.cmake` | CMake 模块 | 检测 Windows/Linux/macOS、架构 |
| `Dependencies.cmake` | CMake 模块 | ThirdParty 引入与链接 |
| `PackageEngine.cmake` | CMake 模块 | 安装规则、SDK 打包 |
| `build.bat` / `build.sh` | 脚本 | 一键编译快捷入口 |
| `.github/workflows/ci.yml` | CI | 多平台自动编译与测试 |

## 子目录建议

```
BuildTool/
├── CMake/           # 模块化 CMake 片段
├── Scripts/         # Python/PowerShell 辅助脚本
└── CI/              # Jenkins/GitHub Actions 配置
```

## 依赖关系

- **无代码依赖**，但被所有 `Source/` 模块通过 CMake 引用

## 完成标准

- [ ] 三平台 Debug/Release 可编译
- [ ] `ctest` 可运行 Tests/
- [ ] `cmake --install` 输出可用 SDK 目录
