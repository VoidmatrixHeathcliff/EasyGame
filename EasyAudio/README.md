# EasyAudio开发文档

编译需要第三方库[SDL2.0](http://www.libsdl.org/)和[SDL_mixer2.0](http://www.libsdl.org/projects/SDL_mixer/)支持
***

> ## Init
初始化声音库
```Lua
Init(frequency, channels)
```
### 参数
+ ***[number] frequency***：声音的采样频率，常见频率为22050或44100
+ ***[number] channels***：声道数（仅作用于音乐播放），可以是如下值：

| 值  | 描述   |
| :-- | :---- |
| 1   | 单声道 |
| 2   | 双声道 |

### 返回值
无
### 示例
```Lua
EasyAudio = require("EasyAudio")
EasyAudio.Init(44100, 2)    -- 初始化声音库为44.1KHz、双声道
```

> ## Quit
关闭并退出声音库
```Lua
Quit()
```
### 参数
无
### 返回值
无
### 示例
```Lua
EasyAudio = require("EasyAudio")
EasyAudio.Init(44100, 2)
EasyAudio.Quit()
```

> ## PlayMusic
播放指定音乐文件
```Lua
PlayMusic(filepath, loops)
```
### 参数
+ ***[string] filepaths***：音乐文件路径
+ ***[number] loops***：音乐文件播放次数，-1为循环播放
### 返回值
无
### 备注
支持的编码格式有：FLAC、MOD、MP3、OGG
### 示例
```Lua
EasyAudio = require("EasyAudio")
EasyAudio.Init(44100, 2)
EasyAudio.PlayMusic("bgm.mp3", -1)
```

> ## PlayFadeInMusic
使用淡入效果播放指定音乐文件
```Lua
PlayFadeInMusic(filepath, loops, ms)
```
### 参数
+ ***[string] filepaths***：音乐文件路径
+ ***[number] loops***：音乐文件播放次数，-1为循环播放
+ ***[number] ms***：淡入效果持续时间，单位为毫秒
### 返回值
无
### 备注
支持的编码格式有：FLAC、MOD、MP3、OGG
### 示例
```Lua
EasyAudio = require("EasyAudio")
EasyAudio.Init(44100, 2)
EasyAudio.PlayFadeInMusic("bgm.mp3", -1)
```

> ## SetMusicVolume
设置音乐播放的音量
```Lua
SetMusicVolume(value)
```
### 参数
+ ***[number] value***：音乐播放的音量，为0-128之间整数
### 返回值
无
### 示例
```Lua
EasyAudio = require("EasyAudio")
EasyAudio.Init(44100, 2)
EasyAudio.SetMusicVolume(50)
```

> ## GetMusicVolume
获取当前音乐播放的音量
```Lua
GetMusicVolume()
```
### 参数
无
### 返回值
+ ***[number] value***：当前音乐播放的音量
### 示例
```Lua
EasyAudio = require("EasyAudio")
EasyAudio.Init(44100, 2)
volume = EasyAudio.GetMusicVolume()
```

> ## PauseMusic
暂停当前正在播放的音乐
```Lua
PauseMusic()
```
### 参数
无
### 返回值
无
### 示例
```Lua
EasyAudio = require("EasyAudio")
EasyAudio.Init(44100, 2)
EasyAudio.PlayFadeInMusic("bgm.mp3", -1)
EasyAudio.Sleep(5000)    -- 播放音乐五秒后暂停
EasyAudio.PauseMusics()
```

> ## ResumeMusic
恢复当前暂停状态的音乐
```Lua
ResumeMusic()
```
### 参数
无
### 返回值
无
### 示例
```Lua
EasyAudio = require("EasyAudio")
EasyAudio.Init(44100, 2)
EasyAudio.PlayFadeInMusic("bgm.mp3", -1)
EasyAudio.Sleep(5000)    -- 播放音乐五秒后暂停
EasyAudio.PauseMusics()
EasyAudio.Sleep(5000)    -- 暂停音乐五秒后恢复
EasyAudio.ResumeMusic()
```

> ## PlaySound
播放指定的音效文件
```Lua
PlaySound(filepath, loops)
```
### 参数
+ ***[string] filepaths***：音效文件路径
+ ***[number] loops***：音效文件播放次数，-1为循环播放
### 返回值
无
### 备注
支持的编码格式有：WAVE、AIFF、RIFF、OGG、VOC
### 示例
```Lua
EasyAudio = require("EasyAudio")
EasyAudio.Init(44100, 2)
EasyAudio.PlaySound("boom.wav", 1)
```

> ##  Pause
暂停程序
```Lua
Pause()
```
### 参数
无
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.Circle(400, 400, 150)
EasyDraw.Pause()    -- 暂停程序，防止窗口在绘制完成后立刻退出
EasyDraw.Close()
```

> ##  Sleep
挂起程序指定时间
```Lua
Sleep(ms)
```
### 参数
+ ***[number] ms***：程序挂起时间，单位为毫秒
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.Circle(400, 400, 150)
EasyDraw.Sleep(5000)    -- 挂起程序5秒，防止窗口在绘制完成后立刻退出
EasyDraw.Close()
```
