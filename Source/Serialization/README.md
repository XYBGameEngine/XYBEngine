# Serialization — 序列化与反射

## 用途

提供引擎对象的**持久化、网络传输、编辑器保存**所需的序列化能力。支持二进制（运行时高效）和 JSON（人类可读/编辑器）两种格式，并包含类型注册与版本迁移机制。

## 需要实现的类

### 归档核心
| 类名 | 职责 |
|------|------|
| `IArchive` | 序列化读写抽象接口 |
| `BinaryArchive` | 二进制流读写 |
| `JsonArchive` | JSON 读写（nlohmann/json 或自研） |
| `ArchiveScope` | RAII 对象/数组作用域 |

### 类型系统
| 类名 | 职责 |
|------|------|
| `TypeRegistry` | 类型名 → 序列化函数注册表 |
| `TypeDescriptor` | 字段元数据（名称、偏移、类型） |
| `TypeId` | 编译期或运行期类型 ID |
| `SerializeTraits<T>` | 特化模板，定义类型的序列化行为 |

### 引用与版本
| 类名 | 职责 |
|------|------|
| `ObjectRef<T>` | GUID 引用的弱/强引用 |
| `GuidResolver` | 反序列化时 GUID → 对象指针 |
| `VersionMigrator` | 旧版本数据升级到新版本 |
| `Serializable` | 基类/宏：`SERIALIZE_FIELDS(...)`

### 编辑器支持
| 类名 | 职责 |
|------|------|
| `PropertyDescriptor` | 属性元数据（范围、枚举、工具提示） |
| `EnumReflection` | 枚举名 ↔ 值映射 |

## 依赖关系

- 依赖：`Source/Core/`
- 被依赖：`Asset`、`ECS`、`Scene`、`Network`、`Tools/Editor`

## 完成标准

- [ ] Component、Prefab、Scene 可 JSON 往返
- [ ] 二进制格式比 JSON 体积减少 50%+
- [ ] 版本迁移单元测试覆盖
