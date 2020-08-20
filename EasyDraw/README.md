# EasyDraw开发文档

编译需要第三方库[EasyX](https://easyx.cn/)支持
***

> ## Init
初始化绘图窗口
```Lua
Init(width, height)
```
### 参数
+ ***[number] width***：窗口宽度
+ ***[number] height***：窗口高度
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)    -- 初始化窗口大小为1280x720
```

> ## Clear
使用当前背景色清空绘图窗口
```Lua
Clear()
```
### 参数
无
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.Clear()
```

> ## Close
关闭当前绘图窗口
```Lua
Close()
```
### 参数
无
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.Close()
```

> ## SetTitle
设置绘图窗口标题
```Lua
SetTitle(title)
```
### 参数
+ ***[string] title***：窗口标题
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.SetTitle("HelloWorld")
```

> ## SetBGColor
设置绘图窗口背景颜色
```Lua
SetBGColor(R, G, B)
```
### 参数
+ ***[number] R***：颜色的红色分量
+ ***[number] G***：颜色的绿色分量
+ ***[number] B***：颜色的蓝色分量
### 返回值
无
## 备注
在设置当前绘图窗口背景色后，并不会改变现有的颜色，而是只改变背景色的值，之后执行的绘图语句会使用此背景色，例如在"OPAQUE"的填充模式下执行DrawText()，文本底色便为新设置的窗口背景色；如需立刻修改全部背景色，则需在设置背景色后执行Clear()语句
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.SetBGColor(0, 0, 255)    -- 设置背景色为蓝色
EasyDraw.Clear()    -- 使用当前背景色清空窗口
```

> ## SetBGMode
设置绘图窗口背景颜色填充模式
```Lua
SetBGMode(mode)
```
### 参数
+ ***[string] mode***：背景模式，可以是如下值：

| 值            | 描述                 |
| :------------ | :------------------- |
| "OPAQUE"      | 使用当前背景色填充背景 |
| "TRANSPARENT" | 背景为透明            |

### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.SetBGColor(0, 0, 255)    -- 设置背景颜色为蓝色
```

> ## SetFillColor
设置填充颜色
```Lua
SetFillColor(R, G, B)
```
### 参数
+ ***[number] R***：颜色的红色分量
+ ***[number] G***：颜色的绿色分量
+ ***[number] B***：颜色的蓝色分量
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.SetFillColor(0, 0, 255)    -- 设置填充颜色为蓝色
```

> ## SetLineColor
设置画线颜色
```Lua
SetLineColor(R, G, B)
```
### 参数
+ ***[number] R***：颜色的红色分量
+ ***[number] G***：颜色的绿色分量
+ ***[number] B***：颜色的蓝色分量
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.SetLineColor(0, 0, 255)    -- 设置画线颜色为蓝色
```

> ## SetTextColor
设置文本颜色
```Lua
SetTextColor(R, G, B)
```
### 参数
+ ***[number] R***：颜色的红色分量
+ ***[number] G***：颜色的绿色分量
+ ***[number] B***：颜色的蓝色分量
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.SetTextColor(0, 0, 255)    -- 设置文本颜色为蓝色
```

> ## SetLineStyle
设置画线样式
```Lua
SetLineStyle(style)
```
### 参数
+ ***[string] style***：画线样式，可以是如下值：

| 值            | 描述      |
| :----------- | :-------- |
| "SOLID"      | 实线      |
| "DASH"       | ----      |
| "DOT"        | ····      |
| "DASHDOT"    | -·-·-·-   |
| "DASHDOTDOT" | -··-··-·· |
| "NULL"       | 不可见     |

### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.SetLineStyle("SOLID")    -- 设置画线样式为实线
```

> ## Point
绘制指定颜色的像素点
```Lua
Point(x, y, R, G, B)
```
### 参数
+ ***[number] x***：像素点的x坐标
+ ***[number] y***：像素点的y坐标
+ ***[number] R***：颜色的红色分量
+ ***[number] G***：颜色的绿色分量
+ ***[number] B***：颜色的蓝色分量
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.Point(100, 100, 255, 0, 0)    -- 在(100, 100)位置绘制一个红色像素点
```

> ## Line
绘制直线
```Lua
Line(x1, y1, y1, y2)
```
### 参数
+ ***[number] x1***：直线起始位置的x坐标
+ ***[number] y1***：直线起始位置的y坐标
+ ***[number] x2***：直线结束位置的x坐标
+ ***[number] y2***：直线结束位置的y坐标
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.Line(0, 0, 100, 100)    -- 从(0, 0)位置到(100, 100)位置画一条直线
```

> ## Roundrect
绘制无填充圆角矩形
```Lua
Roundrect(left, top, right, bottom, ellipsewidth, ellipseheight)
```
### 参数
+ ***[number] left***：矩形左边线坐标
+ ***[number] top***：矩形上边线坐标
+ ***[number] right***：矩形右边线坐标
+ ***[number] bottom***：矩形下边线坐标
+ ***[number] ellipsewidth***：圆角椭圆宽度
+ ***[number] ellipseheight***：圆角椭圆高度
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.Roundrect(100, 100, 300, 200, 20, 10)
```

> ## FillRoundrect
绘制有填充圆角矩形
```Lua
FillRoundrect(left, top, right, bottom, ellipsewidth, ellipseheight)
```
### 参数
+ ***[number] left***：矩形左边线坐标
+ ***[number] top***：矩形上边线坐标
+ ***[number] right***：矩形右边线坐标
+ ***[number] bottom***：矩形下边线坐标
+ ***[number] ellipsewidth***：圆角椭圆宽度
+ ***[number] ellipseheight***：圆角椭圆高度
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.FillRoundrect(100, 100, 300, 200, 20, 10)
```

> ## SolidRoundrect
绘制填充无边框圆角矩形
```Lua
SolidRoundrect(left, top, right, bottom, ellipsewidth, ellipseheight)
```
### 参数
+ ***[number] left***：矩形左边线坐标
+ ***[number] top***：矩形上边线坐标
+ ***[number] right***：矩形右边线坐标
+ ***[number] bottom***：矩形下边线坐标
+ ***[number] ellipsewidth***：圆角椭圆宽度
+ ***[number] ellipseheight***：圆角椭圆高度
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.SolidRoundrect(100, 100, 300, 200, 20, 10)
```

> ## Ellipse
绘制无填充椭圆
```Lua
Ellipse(left, top, right, bottom)
```
### 参数
+ ***[number] left***：椭圆外切矩形左上角x坐标
+ ***[number] top***：椭圆外切矩形左上角y坐标
+ ***[number] right***：椭圆外切矩形右下角x坐标
+ ***[number] bottom***：椭圆外切矩形右下角y坐标
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.Ellipse(100, 100, 300, 200)
```

> ## FillEllipse
绘制有填充椭圆
```Lua
FillEllipse(left, top, right, bottom)
```
### 参数
+ ***[number] left***：椭圆外切矩形左上角x坐标
+ ***[number] top***：椭圆外切矩形左上角y坐标
+ ***[number] right***：椭圆外切矩形右下角x坐标
+ ***[number] bottom***：椭圆外切矩形右下角y坐标
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.FillEllipse(100, 100, 300, 200)
```

> ## SolidEllipse
绘制填充无边框椭圆
```Lua
SolidEllipse(left, top, right, bottom)
```
### 参数
+ ***[number] left***：椭圆外切矩形左上角x坐标
+ ***[number] top***：椭圆外切矩形左上角y坐标
+ ***[number] right***：椭圆外切矩形右下角x坐标
+ ***[number] bottom***：椭圆外切矩形右下角y坐标
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.SolidEllipse(100, 100, 300, 200)
```

> ## Circle
绘制无填充圆
```Lua
Circle(x, y, radius)
```
### 参数
+ ***[number] x***：圆心x坐标
+ ***[number] y***：圆心y坐标
+ ***[number] radius***：半径
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.Circle(100, 100, 40)
```

> ## FillCircle
绘制有填充圆
```Lua
FillCircle(x, y, radius)
```
### 参数
+ ***[number] x***：圆心x坐标
+ ***[number] y***：圆心y坐标
+ ***[number] radius***：半径
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.FillCircle(100, 100, 40)
```

> ## SolidCircle
绘制填充无边框圆
```Lua
SolidCircle(x, y, radius)
```
### 参数
+ ***[number] x***：圆心x坐标
+ ***[number] y***：圆心y坐标
+ ***[number] radius***：半径
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.SolidCircle(100, 100, 40)
```

> ## Rectangle
绘制无填充矩形
```Lua
Rectangle(left, top, right, bottom)
```
### 参数
+ ***[number] left***：矩形左边线坐标
+ ***[number] top***：矩形上边线坐标
+ ***[number] right***：矩形右边线坐标
+ ***[number] bottom***：矩形下边线坐标
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.Rectangle(100, 100, 300, 200)
```

> ## FillRectangle
绘制有填充矩形
```Lua
FillRectangle(left, top, right, bottom)
```
### 参数
+ ***[number] left***：矩形左边线坐标
+ ***[number] top***：矩形上边线坐标
+ ***[number] right***：矩形右边线坐标
+ ***[number] bottom***：矩形下边线坐标
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.FillRectangle(100, 100, 300, 200)
```

> ## SolidRectangle
绘制填充无边框矩形
```Lua
SolidRectangle(left, top, right, bottom)
```
### 参数
+ ***[number] left***：矩形左边线坐标
+ ***[number] top***：矩形上边线坐标
+ ***[number] right***：矩形右边线坐标
+ ***[number] bottom***：矩形下边线坐标
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.SolidRectangle(100, 100, 300, 200)
```

> ## SetTextStyle
设置文本字体样式
```Lua
SetTextStyle(height, width, font)
```
### 参数
+ ***[number] height***：字体高度
+ ***[number] width***：字体宽度，0为自适应
+ ***[string] font***：字体名称
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.SetTextStyle(25, 0, "隶书")
```

> ## DrawText
在指定位置绘制文本
```Lua
DrawText(x, y, content)
```
### 参数
+ ***[number] x***：x坐标
+ ***[number] y***：y坐标
+ ***[string] content***：文本内容
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.DrawText(100, 100, "你好，世界！")
```

> ## DrawImage
在指定位置绘制不带透明度图片
```Lua
DrawImage(x, y, width, height, filepath)
```
### 参数
+ ***[number] x***：x坐标
+ ***[number] y***：y坐标
+ ***[number] width***：图片缩放宽度
+ ***[number] height***：图片缩放高度
+ ***[string] filepath***：图片文件路径
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.DrawImage(0, 0, 1280, 720, "./Background.jpg")
```

> ## DrawTransImage
在指定位置绘制带透明度的图片
```Lua
DrawTransImage(x, y, width, height, filepath)
```
### 参数
+ ***[number] x***：x坐标
+ ***[number] y***：y坐标
+ ***[number] width***：图片缩放宽度
+ ***[number] height***：图片缩放高度
+ ***[string] filepath***：图片文件路径
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.DrawTransImage(0, 0, 1280, 720, "./Background.jpg")
```

> ## FloodFill
填充指定区域
```Lua
FloodFill(x, y, R, G, B, filltype)
```
### 参数
+ ***[number] x***：填充起点x坐标
+ ***[number] y***：填充起点y坐标
+ ***[number] R***：颜色的红色分量
+ ***[number] G***：颜色的绿色分量
+ ***[number] B***：颜色的蓝色分量
+ ***[string] style***：填充类型，可以是如下值：

| 值        | 描述                              |
| :-------- | :-------------------------------- |
| "BORDER"  | 填充动作发生在指定颜色围成的封闭区域 |
| "SURFACE" | 填充动作发生在指定颜色的连续表面     |

### 返回值
无
### 备注
+ 对于 BORDER 填充类型，填充动作以指定坐标为起点，向周围扩散，直到指定的颜色才会终止，指定的区域必须是封闭的，故适用于填充具有固定颜色边界的区域
+ 对于 SURFACE 填充类型，填充动作以指定坐标为起点，只要邻接的颜色为指定颜色，填充就会延伸，故适用于填充具有多种颜色边界的区域
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.SetBGColor(0, 255, 0)    -- 设置当前绘图窗口背景色为绿色
EasyDraw.Clear()    -- 使用当前背景色清空整个绘图窗口
EasyDraw.FloodFill(0, 0, 0, 255, 0, "SURFACE")    -- 从(0, 0)点开始使用默认白色填充邻接的绿色区域
```

> ## CaptureEvent
捕获缓冲区的鼠标及部分键盘事件，并更新EasyDraw内部事件变量
```Lua
CaptureEvent()
```
### 参数
无
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
while (true)
do
    EasyDraw.CaptureEvent()
    -- 处理捕获到的事件 --
end
```

> ## CheckEventType
判断当前事件类型是否为指定事件
```Lua
result = CheckEventType(eventtype)
```
### 参数
+ ***[string] eventtype***：事件类型，可以是如下值：

| 值              | 描述        |
| :-------------- | :---------- |
| "MOUSEMOVE"     | 鼠标移动     |
| "MOUSEWHELL"    | 鼠标滚轮移动 |
| "LBUTTONDOWN"   | 鼠标左键按下 |
| "LBUTTONUP"     | 鼠标左键抬起 |
| "LBUTTONDBLCLK" | 鼠标左键双击 |
| "MBUTTONDOWN"   | 鼠标中键按下 |
| "MBUTTONUP"     | 鼠标中键抬起 |
| "MBUTTONDBLCLK" | 鼠标中键双击 |
| "RBUTTONDOWN"   | 鼠标右键按下 |
| "RBUTTONUP"     | 鼠标右键抬起 |
| "RBUTTONDBLCLK" | 鼠标右键双击 |
| "CTRLDOWN"      | Ctrl键按下  |
| "SHIFTDOWN"     | Shift键按下 |

### 返回值
+ ***[number] result***：判断结果，可以是如下值：

| 值  | 描述                |
| :-- | :----------------- |
| -1  | 指定事件类型不存在   |
| 0   | 当前事件不是指定事件 |
| 1   | 当前事件是指定事件   |

### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
while (true)
do
    EasyDraw.CaptureEvent()
    if (EasyDraw.CheckEventType("LBUTTONDOWN") == 1)
    then
        -- 处理鼠标左键单击事件 --
    end
end

```

> ## CaptureEvent
捕获缓冲区的鼠标及部分键盘事件，并更新EasyDraw内部事件变量
```Lua
CaptureEvent()
```
### 参数
无
### 返回值
无
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
while (true)
do
    EasyDraw.CaptureEvent()
    -- 处理捕获到的事件 --
end
```

> ## GetMousePosition
获取当前鼠标位置
```Lua
x, y = GetMousePosition()
```
### 参数
无
### 返回值

+ ***[number] x***：当前鼠标位置的x坐标
+  ***[number] y***：当前鼠标位置的y坐标

### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
while (true)
do
    EasyDraw.CaptureEvent()
    if (EasyDraw.CheckEventType("LBUTTONDOWN") == 1)
    then
        x, y = GetMousePosition()
        print(x, y)                -- 当鼠标左键按下时打印当前鼠标所在位置x和y坐标
    end
end
```

> ##  BeginBatchDraw
开始批量绘图任务
```Lua
BeginBatchDraw()
```
### 参数
无
### 返回值
无
### 备注
开始批量绘图后，任何绘图操作都将在缓冲区内完成且不输出到绘图窗口上，直到执行 FlushBatchDraw 或 EndBatchDraw 才将之前的绘图输出，可用于解决快速执行绘图任务时产生的闪屏现象
### 示例
```Lua
EasyDraw = require("EasyDraw")
EasyDraw.Init(1280, 720)
EasyDraw.SetLineColor(255, 255, 255);    -- 设置画线颜色为白色
EasyDraw.SetFillColor(255, 0, 0);        -- 设置填充颜色为红色
EasyDraw.BeginBatchDraw()                -- 开始批量绘图任务
for i = 1, 1000 do
    EasyDraw.Circle(i, 360, 50)
    EasyDraw.FloodFill(i, 360, 255, 255, 255, "BORDER")
    EasyDraw.FlushBatchDraw()            -- 执行未完成的绘图任务
    EasyDraw.Sleep(10)
    EasyDraw.Clear()
end
EasyDraw.EndBatchDraw()                  -- 结束批量绘图任务，并执行未完成的绘图任务
EasyDraw.Close()
```

> ##  FlushBatchDraw
执行未完成的绘图任务
```Lua
FlushBatchDraw()
```
### 参数
无
### 返回值
无
### 示例
无（见BeginBatchDraw函数示例）

> ##  EndBatchDraw
结束批量绘制，并执行未完成的绘制任务
```Lua
EndBatchDraw()
```
### 参数
无
### 返回值
无
### 示例
无（见BeginBatchDraw函数示例）

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
