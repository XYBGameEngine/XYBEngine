# Audio — 音频系统

## 用途

提供**2D/3D 音效播放、背景音乐、混音、音频监听器**功能。将音频资源与 ECS 实体绑定，支持空间音频衰减和多声道管理。

## 需要实现的类

### 设备与混音
| 类名 | 职责 |
|------|------|
| `IAudioDevice` | 音频设备初始化与销毁 |
| `AudioEngine` | 全局音频引擎入口 |
| `AudioMixer` | 混音总线、音量、效果器链 |
| `AudioBus` | 分类总线（SFX、Music、Voice） |

### 播放
| 类名 | 职责 |
|------|------|
| `AudioClip` | 音频数据资源 |
| `Sound` | 可播放的声音对象 |
| `SoundInstance` | 运行时播放实例 |
| `AudioSourceComponent` | ECS 音源组件（位置、音量、循环） |
| `AudioListenerComponent` | ECS 监听器（通常挂相机） |

### 3D 音频
| 类名 | 职责 |
|------|------|
| `AttenuationModel` | 距离衰减曲线 |
| `AudioSpatializer` | HRTF 或 Panning 空间化 |

### 系统
| 类名 | 职责 |
|------|------|
| `AudioSystem` | ECS 每帧同步 3D 音源位置 |
| `AudioImporter` | 音频导入（或在 Asset 模块） |

### 实现
```
Audio/
├── Public/
└── Impl/
    └── Miniaudio/   # 或 FMOD/Wwise 封装
```

## 依赖关系

- 依赖：`Core`、`Platform`、`Asset`、`ECS`
- 被依赖：`Runtime`、`Tools/Editor`

## 完成标准

- [ ] 2D/3D 音效播放正常
- [ ] 多音源混音无爆音
- [ ] 监听器跟随相机移动
