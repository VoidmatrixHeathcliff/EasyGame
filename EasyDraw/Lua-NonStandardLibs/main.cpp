#include <lua.hpp>
#include <graphics.h>
#include <Windows.h>

HWND hwnd;      // 窗口句柄

MOUSEMSG msg;   // 鼠标消息

// 初始化窗口，2参数：窗口宽度、窗口高度
extern "C" int init(lua_State * L)
{
    int width = lua_tonumber(L, 1);
    int height = lua_tonumber(L, 2);
    hwnd = initgraph(width, height, EW_DBLCLKS);
    return 0;
}

// 使用当前背景色清空屏幕，无参数
extern "C" int clear(lua_State * L)
{
    cleardevice();
    return 0;
}

// 关闭当前窗口，无参数
extern "C" int close(lua_State * L)
{
    closegraph();
    return 0;
}

// 设置窗口标题，1参数：标题字符串
extern "C" int setTitle(lua_State * L)
{
    const char* title = lua_tostring(L, 1);
    SetWindowTextA(hwnd, title);
    return 0;
}

// 设置背景颜色，3参数：R、G、B
extern "C" int setBGColor(lua_State * L)
{
    int R = lua_tonumber(L, 1);
    int G = lua_tonumber(L, 2);
    int B = lua_tonumber(L, 3);
    setbkcolor(RGB(R, G, B));
    return 0;
}

// 设置背景颜色填充模式，1参数：模式名
// 可选值为：OPAQUE（背景用当前背景色填充），TRANSPARENT（透明背景）
extern "C" int setBGMode(lua_State * L)
{
    const char* mode = lua_tostring(L, 1);
    if (!strcmp(mode, "TRANSPARENT"))
    {
        setbkmode(TRANSPARENT);
    }
    else if (!strcmp(mode, "OPAQUE"))
    {
        setbkmode(OPAQUE);
    }
    return 0;
}

// 设置填充颜色，3参数：R、G、B
extern "C" int setFillColor(lua_State * L)
{
    int R = lua_tonumber(L, 1);
    int G = lua_tonumber(L, 2);
    int B = lua_tonumber(L, 3);
    setfillcolor(RGB(R, G, B));
    return 0;
}

// 设置画线颜色，3参数：R、G、B
extern "C" int setLineColor(lua_State * L)
{
    int R = lua_tonumber(L, 1);
    int G = lua_tonumber(L, 2);
    int B = lua_tonumber(L, 3);
    setlinecolor(RGB(R, G, B));
    return 0;
}

// 设置字体颜色，3参数：R、G、B
extern "C" int setTextColor(lua_State * L)
{
    int R = lua_tonumber(L, 1);
    int G = lua_tonumber(L, 2);
    int B = lua_tonumber(L, 3);
    settextcolor(RGB(R, G, B));
    return 0;
}

// 设置填充颜色，1参数：类型名
// 可选值为："SOLID"（实线），"DASH"（----），"DOT"（····），"DASHDOT"（-·-·-·-），"DASHDOTDOT"（-··-··-··），"NULL"（不可见）
extern "C" int setLineStyle(lua_State * L)
{
    const char* style = lua_tostring(L, 1);
    if (!strcmp(style, "SOLID"))
    {
        setlinestyle(PS_SOLID);
    }
    else if (!strcmp(style, "DASH"))
    {
        setlinestyle(PS_DASH);
    }
    else if (!strcmp(style, "DOT"))
    {
        setlinestyle(PS_DOT);
    }
    else if (!strcmp(style, "DASHDOT"))
    {
        setlinestyle(PS_DASHDOT);
    }
    else if (!strcmp(style, "DASHDOTDOT"))
    {
        setlinestyle(PS_DASHDOTDOT);
    }
    else if (!strcmp(style, "NULL"))
    {
        setlinestyle(PS_NULL);
    }
    return 0;
}

// 绘制像素点，5参数：x坐标、y坐标、R、G、B
extern "C" int drawPixel(lua_State * L)
{
    int x = lua_tonumber(L, 1);
    int y = lua_tonumber(L, 2);
    int R = lua_tonumber(L, 3);
    int G = lua_tonumber(L, 4);
    int B = lua_tonumber(L, 5);
    putpixel(x, y, RGB(R, G, B));
    return 0;
}

// 绘制直线，4参数：起始位置x坐标、起始位置y坐标、终止位置x坐标、终止位置y坐标
extern "C" int drawLine(lua_State * L)
{
    int x1 = lua_tonumber(L, 1);
    int y1 = lua_tonumber(L, 2);
    int x2 = lua_tonumber(L, 3);
    int y2 = lua_tonumber(L, 4);
    line(x1, y1, x2, y2);
    return 0;
}

// 绘制无填充圆角矩形，6参数：矩形左边线坐标、矩形上边线坐标、矩形右边线坐标、矩形下边线坐标、圆角椭圆宽度、圆角椭圆高度
extern "C" int drawRoundrect(lua_State * L)
{
    int left = lua_tonumber(L, 1);
    int top = lua_tonumber(L, 2);
    int right = lua_tonumber(L, 3);
    int bottom = lua_tonumber(L, 4);
    int ellipsewidth = lua_tonumber(L, 5);
    int ellipseheight = lua_tonumber(L, 6);
    roundrect(left, top, right, bottom, ellipsewidth, ellipseheight);
    return 0;
}

// 绘制有填充圆角矩形，6参数：矩形左边线坐标、矩形上边线坐标、矩形右边线坐标、矩形下边线坐标、圆角椭圆宽度、圆角椭圆高度
extern "C" int drawFillRoundrect(lua_State * L)
{
    int left = lua_tonumber(L, 1);
    int top = lua_tonumber(L, 2);
    int right = lua_tonumber(L, 3);
    int bottom = lua_tonumber(L, 4);
    int ellipsewidth = lua_tonumber(L, 5);
    int ellipseheight = lua_tonumber(L, 6);
    fillroundrect(left, top, right, bottom, ellipsewidth, ellipseheight);
    return 0;
}

// 绘制填充无边框圆角矩形，6参数：矩形左边线坐标、矩形上边线坐标、矩形右边线坐标、矩形下边线坐标、圆角椭圆宽度、圆角椭圆高度
extern "C" int drawSolidRoundrect(lua_State * L)
{
    int left = lua_tonumber(L, 1);
    int top = lua_tonumber(L, 2);
    int right = lua_tonumber(L, 3);
    int bottom = lua_tonumber(L, 4);
    int ellipsewidth = lua_tonumber(L, 5);
    int ellipseheight = lua_tonumber(L, 6);
    solidroundrect(left, top, right, bottom, ellipsewidth, ellipseheight);
    return 0;
}

// 绘制无填充椭圆，4参数：椭圆外切矩形左上角x坐标、椭圆外切矩形左上角y坐标、椭圆外切矩形右下角x坐标、椭圆外切矩形右下角y坐标
extern "C" int drawEllipse(lua_State * L)
{
    int left = lua_tonumber(L, 1);
    int top = lua_tonumber(L, 2);
    int right = lua_tonumber(L, 3);
    int bottom = lua_tonumber(L, 4);
    ellipse(left, top, right, bottom);
    return 0;
}

// 绘制无填充椭圆，4参数：椭圆外切矩形左上角x坐标、椭圆外切矩形左上角y坐标、椭圆外切矩形右下角x坐标、椭圆外切矩形右下角y坐标
extern "C" int drawFillEllipse(lua_State * L)
{
    int left = lua_tonumber(L, 1);
    int top = lua_tonumber(L, 2);
    int right = lua_tonumber(L, 3);
    int bottom = lua_tonumber(L, 4);
    fillellipse(left, top, right, bottom);
    return 0;
}

// 绘制填充无边框椭圆，4参数：椭圆外切矩形左上角x坐标、椭圆外切矩形左上角y坐标、椭圆外切矩形右下角x坐标、椭圆外切矩形右下角y坐标
extern "C" int drawSolidEllipse(lua_State * L)
{
    int left = lua_tonumber(L, 1);
    int top = lua_tonumber(L, 2);
    int right = lua_tonumber(L, 3);
    int bottom = lua_tonumber(L, 4);
    solidellipse(left, top, right, bottom);
    return 0;
}

// 绘制无填充圆，3参数：圆心x坐标、圆心y坐标、半径
extern "C" int drawCircle(lua_State * L)
{
    int x = lua_tonumber(L, 1);
    int y = lua_tonumber(L, 2);
    int radius = lua_tonumber(L, 3);
    circle(x, y, radius);
    return 0;
}

// 绘制有填充圆，3参数：圆心x坐标、圆心y坐标、半径
extern "C" int drawFillCircle(lua_State * L)
{
    int x = lua_tonumber(L, 1);
    int y = lua_tonumber(L, 2);
    int radius = lua_tonumber(L, 3);
    fillcircle(x, y, radius);
    return 0;
}

// 绘制填充无边框圆，3参数：圆心x坐标、圆心y坐标、半径
extern "C" int drawSolidCircle(lua_State * L)
{
    int x = lua_tonumber(L, 1);
    int y = lua_tonumber(L, 2);
    int radius = lua_tonumber(L, 3);
    solidcircle(x, y, radius);
    return 0;
}

// 绘制无填充矩形，4参数：矩形左边线坐标、矩形上边线坐标、矩形右边线坐标、矩形下边线坐标
extern "C" int drawRectangle(lua_State * L)
{
    int left = lua_tonumber(L, 1);
    int top = lua_tonumber(L, 2);
    int right = lua_tonumber(L, 3);
    int bottom = lua_tonumber(L, 4);
    rectangle(left, top, right, bottom);
    return 0;
}

// 绘制有填充矩形，4参数：矩形左边线坐标、矩形上边线坐标、矩形右边线坐标、矩形下边线坐标
extern "C" int drawFillRectangle(lua_State * L)
{
    int left = lua_tonumber(L, 1);
    int top = lua_tonumber(L, 2);
    int right = lua_tonumber(L, 3);
    int bottom = lua_tonumber(L, 4);
    fillrectangle(left, top, right, bottom);
    return 0;
}

// 绘制有填充无边框矩形，4参数：矩形左边线坐标、矩形上边线坐标、矩形右边线坐标、矩形下边线坐标
extern "C" int drawSolidRectangle(lua_State * L)
{
    int left = lua_tonumber(L, 1);
    int top = lua_tonumber(L, 2);
    int right = lua_tonumber(L, 3);
    int bottom = lua_tonumber(L, 4);
    solidrectangle(left, top, right, bottom);
    return 0;
}

// 设置当前字体样式，3参数：字体高度、字体宽度（0为自适应）、字体名称
extern "C" int setTextStyle(lua_State * L)
{
    int height = lua_tonumber(L, 1);
    int width = lua_tonumber(L, 2);
    const char* name = lua_tostring(L, 3);
    int num = MultiByteToWideChar(0, 0, name, -1, NULL, 0);
    wchar_t* w_name = new wchar_t[num];
    MultiByteToWideChar(0, 0, name, -1, w_name, num);
    settextstyle(height, width, w_name);
    return 0;
}

// 在指定位置输出字符串，3参数：x坐标、y坐标、字符串内容
extern "C" int drawText(lua_State * L)
{
    int x = lua_tonumber(L, 1);
    int y = lua_tonumber(L, 2);
    const char* content = lua_tostring(L, 3);
    int num = MultiByteToWideChar(0, 0, content, -1, NULL, 0);
    wchar_t* w_content = new wchar_t[num];
    MultiByteToWideChar(0, 0, content, -1, w_content, num);
    outtextxy(x, y, w_content);
    return 0;
}

// 在指定位置绘制图片，5参数：x坐标、y坐标、图片宽度、图片高度、图片路径
extern "C" int drawImage(lua_State * L)
{
    int x = lua_tonumber(L, 1);
    int y = lua_tonumber(L, 2);
    int width = lua_tonumber(L, 3);
    int height = lua_tonumber(L, 4);
    const char* path = lua_tostring(L, 5);
    int num = MultiByteToWideChar(0, 0, path, -1, NULL, 0);
    wchar_t* w_path = new wchar_t[num];
    MultiByteToWideChar(0, 0, path, -1, w_path, num);
    IMAGE image;
    loadimage(&image, w_path, width, height);
    putimage(x, y, &image);
    return 0;
}

// 在指定位置绘制透明图片，5参数：x坐标、y坐标、图片宽度、图片高度、图片路径
extern "C" int drawTransImage(lua_State * L)
{
    int x = lua_tonumber(L, 1);
    int y = lua_tonumber(L, 2);
    int width = lua_tonumber(L, 3);
    int height = lua_tonumber(L, 4);
    const char* path = lua_tostring(L, 5);
    int num = MultiByteToWideChar(0, 0, path, -1, NULL, 0);
    wchar_t* w_path = new wchar_t[num];
    MultiByteToWideChar(0, 0, path, -1, w_path, num);
    IMAGE srcimg;
    loadimage(&srcimg, w_path, width, height);

    DWORD* dst = GetImageBuffer(NULL);
    DWORD* src = GetImageBuffer(&srcimg);
    int src_width = (&srcimg)->getwidth();
    int src_height = (&srcimg)->getheight();
    int dst_width = getwidth();
    int dst_height = getheight();

    int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width;
    int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;
    if (x < 0) { src += -x;				iwidth -= -x;	x = 0; }
    if (y < 0) { src += src_width * -y;	iheight -= -y;	y = 0; }
    
    dst += dst_width * y + x;

    for (int iy = 0; iy < iheight; iy++)
    {
        for (int ix = 0; ix < iwidth; ix++)
        {
            int sa = ((src[ix] & 0xff000000) >> 24);
            int sr = ((src[ix] & 0xff0000) >> 16);
            int sg = ((src[ix] & 0xff00) >> 8);	
            int sb = src[ix] & 0xff;			
            int dr = ((dst[ix] & 0xff0000) >> 16);
            int dg = ((dst[ix] & 0xff00) >> 8);
            int db = dst[ix] & 0xff;

            dst[ix] = ((sr + dr * (255 - sa) / 255) << 16)
                | ((sg + dg * (255 - sa) / 255) << 8)
                | (sb + db * (255 - sa) / 255);
        }
        dst += dst_width;
        src += src_width;
    }

    return 0;
}

// 填充指定区域，6参数：起点x坐标、起点y坐标、R、G、B、填充类型
// 填充类型可选值为："BORDER"（填充动作发生在指定颜色围成的封闭区域），"SURFACE"（填充动作发生在指定颜色的连续表面）
extern "C" int floodFill(lua_State * L)
{
    int x = lua_tonumber(L, 1);
    int y = lua_tonumber(L, 2);
    int R = lua_tonumber(L, 3);
    int G = lua_tonumber(L, 4);
    int B = lua_tonumber(L, 5);
    const char* fillType = lua_tostring(L, 6);
    if (!strcmp(fillType, "SURFACE"))
    {
        floodfill(x, y, RGB(R, G, B), FLOODFILLSURFACE);
    }
    else
    {
        floodfill(x, y, RGB(R, G, B), FLOODFILLBORDER);
    }
    return 0;
}

// 捕获事件，无参数
extern "C" int captureEvent(lua_State * L)
{
    msg = GetMouseMsg();
    return 0;
}

// 判断交互事件类型，1参数：类型名
// 可选值为："MOUSEMOVE"（鼠标移动），"MOUSEWHELL"（鼠标滚轮移动），"LBUTTONDOWN"（鼠标左键按下），"LBUTTONUP"（鼠标左键抬起），"LBUTTONDBLCLK"（鼠标左键双击），"MBUTTONDOWN"（鼠标中键按下），"MBUTTONUP"（鼠标中键抬起），"MBUTTONDBLCLK"（鼠标中键双击），"RBUTTONDOWN"（鼠标右键按下），"RBUTTONUP"（鼠标右键抬起），"RBUTTONDBLCLK"（鼠标右键双击），"CTRLDOWN"（Ctrl键按下），"SHIFTDOWN"（Shift键按下）
// 1个返回值：0 - 不是当前事件，1 - 是当前事件，-1 - 不存在当前事件
extern "C" int checkEventType(lua_State * L)
{
    const char* eventType = lua_tostring(L, 1);
    int result = -1;
    if (!strcmp(eventType, "MOUSEMOVE"))
    {
        if (msg.uMsg == WM_MOUSEMOVE)
            result = 1;
        else
            result = 0;
    }
    else if (!strcmp(eventType, "MOUSEWHELL"))
    {
        if (msg.uMsg == WM_MOUSEWHEEL)
            result = 1;
        else
            result = 0;
    }
    else if (!strcmp(eventType, "LBUTTONDOWN"))
    {
        if (msg.uMsg == WM_LBUTTONDOWN)
            result = 1;
        else
            result = 0;
    }
    else if (!strcmp(eventType, "LBUTTONDBLCLK"))
    {
        if (msg.uMsg == WM_LBUTTONDBLCLK)
            result = 1;
        else
            result = 0;
    }
    else if (!strcmp(eventType, "MBUTTONDOWN"))
    {
        if (msg.uMsg == WM_MBUTTONDOWN)
            result = 1;
        else
            result = 0;
    }
    else if (!strcmp(eventType, "MBUTTONUP"))
    {
        if (msg.uMsg == WM_MBUTTONUP)
            result = 1;
        else
            result = 0;
    }
    else if (!strcmp(eventType, "MBUTTONDBLCLK"))
    {
        if (msg.uMsg == WM_MBUTTONDBLCLK)
            result = 1;
        else
            result = 0;
    }
    else if (!strcmp(eventType, "RBUTTONDOWN"))
    {
        if (msg.uMsg == WM_RBUTTONDOWN)
            result = 1;
        else
            result = 0;
    }
    else if (!strcmp(eventType, "RBUTTONUP"))
    {
        if (msg.uMsg == WM_RBUTTONUP)
            result = 1;
        else
            result = 0;
    }
    else if (!strcmp(eventType, "RBUTTONDBLCLK"))
    {
        if (msg.uMsg == WM_RBUTTONDBLCLK)
            result = 1;
        else
            result = 0;
    }
    else if (!strcmp(eventType, "CTRLDOWN"))
    {
        if (msg.mkCtrl)
            result = 1;
        else
            result = 0;
    }
    else if (!strcmp(eventType, "SHIFTDOWN"))
    {
        if (msg.mkShift)
            result = 1;
        else
            result = 0;
    }
    lua_pushnumber(L, result);
    return 1;
}

// 获取当前鼠标位置，无参数
// 2个返回值：x坐标、y坐标
extern "C" int getMousePosition(lua_State * L)
{
    MOUSEMSG msg = GetMouseMsg();
    lua_pushnumber(L, msg.x);
    lua_pushnumber(L, msg.y);
    return 2;
}

// 开始批量绘图，无参数
extern "C" int beginBatchDraw(lua_State * L)
{
    BeginBatchDraw();
    return 0;
}

// 执行未完成绘图任务，无参数
extern "C" int flushBatchDraw(lua_State * L)
{
    FlushBatchDraw();
    return 0;
}

// 结束批量绘图，无参数
extern "C" int endBatchDraw(lua_State * L)
{
    EndBatchDraw();
    return 0;
}

// 暂停程序，无参数
extern "C" int pause(lua_State * L)
{
    system("pause");
    return 0;
}

// 挂起程序指定时间，1参数：挂起时间（单位：毫秒）
extern "C" int sleep(lua_State * L)
{
    int delay = lua_tonumber(L, 1);
    Sleep(delay);
    return 0;
}



static luaL_Reg cMethods[] = {
    { "Init", init },
    { "Clear", clear },
    { "Close", close },
    { "SetTitle", setTitle },
    { "SetBGColor", setBGColor },
    { "SetBGMode", setBGMode },
    { "SetFillColor", setFillColor },
    { "SetLineColor", setLineColor },
    { "SetTextColor", setTextColor },
    { "SetLineStyle", setLineStyle },
    { "Point", drawPixel},
    { "Line", drawLine },
    { "Roundrect" , drawRoundrect },
    { "FillRoundrect" , drawFillRoundrect },
    { "SolidRoundrect", drawSolidRoundrect },
    { "Ellipse", drawEllipse },
    { "FillEllipse", drawFillEllipse },
    { "SolidEllipse", drawSolidEllipse},
    { "Circle", drawCircle },
    { "FillCircle", drawFillCircle },
    { "SolidCircle", drawSolidCircle },
    { "Rectangle", drawRectangle },
    { "FillRectangle", drawFillRectangle },
    { "SolidRectangle", drawSolidRectangle },
    { "SetTextStyle", setTextStyle },
    { "DrawText", drawText },
    { "DrawImage", drawImage },
    { "DrawTransImage", drawTransImage },
    { "FloodFill", floodFill },
    { "CaptureEvent", captureEvent},
    { "CheckEventType", checkEventType},
    { "GetMousePosition", getMousePosition},
    { "BeginBatchDraw", beginBatchDraw },
    { "FlushBatchDraw", flushBatchDraw },
    { "EndBatchDraw", endBatchDraw },
    { "Pause", pause },
    { "Sleep", sleep },
    { NULL, NULL }
};

extern "C" __declspec(dllexport)
int luaopen_EasyDraw(lua_State * L)
{
    luaL_newlib(L, cMethods);
    return 1;
}
