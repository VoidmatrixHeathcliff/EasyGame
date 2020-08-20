#include <lua.hpp>
#include <SDL.h>
#include <SDL_mixer.h>

// 初始化声音库，2参数：采样频率（常见的有22050、44100）、声道数（仅作用于音乐播放）
extern "C" int init(lua_State * L)
{
	int frequency = lua_tonumber(L, 1);
	int channels = lua_tonumber(L, 2);
	Mix_Init(MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG);
	Mix_OpenAudio(frequency, MIX_DEFAULT_FORMAT, channels, 2048);
	return 0;
}

// 退出声音库，无参数
extern "C" int quit(lua_State * L)
{
	Mix_CloseAudio();
	Mix_Quit();
	return 0;
}

// 播放音乐，2参数：音乐文件路径、音乐播放的次数（-1为循环播放）
extern "C" int playMusic(lua_State * L)
{
	const char* path = lua_tostring(L, 1);
	int loops = lua_tonumber(L, 2);
	Mix_PlayMusic(Mix_LoadMUS(path), loops);
	return 0;
}

// 播放淡入音乐，3参数：音乐文件路径、音乐播放的次数、淡入音效持续时间（ms）
extern "C" int playFadeInMusic(lua_State * L)
{
	const char* path = lua_tostring(L, 1);
	int loops = lua_tonumber(L, 2);
	int delay = lua_tonumber(L, 3);
	Mix_FadeInMusic(Mix_LoadMUS(path), loops, delay);
	return 0;
}

// 设置音乐音量，1参数：音量大小（0-128）
extern "C" int setMusicVolume(lua_State * L)
{
	int value = lua_tonumber(L, 1);
	Mix_VolumeMusic(value);
	return 0;
}

// 获取当前音乐音量，无参数
// 返回值：当前音乐音量大小
extern "C" int getMusicVolume(lua_State * L)
{
	int value = Mix_VolumeMusic(-1);
	lua_pushnumber(L, value);
	return 1;
}

// 暂停当前正在播放的音乐，无参数
extern "C" int pauseMusic(lua_State * L)
{
	Mix_PauseMusic();
	return 0;
}

// 恢复当前暂停状态的音乐，无参数
extern "C" int resumeMusic(lua_State * L)
{
	Mix_ResumeMusic();
	return 0;
}

// 播放音效，2参数：音效文件路径、音乐播放的次数（-1为循环播放）
// 备注：音效文件支持以下格式：WAVE, AIFF, RIFF, OGG, VOC
extern "C" int playSound(lua_State * L)
{
	const char* path = lua_tostring(L, 1);
	int loops = lua_tonumber(L, 2);
	if (loops > 0)
	{
		Mix_PlayChannel(-1, Mix_LoadWAV(path), loops - 1);
	}
	else
	{
		Mix_PlayChannel(-1, Mix_LoadWAV(path), loops);
	}
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
	SDL_Delay(delay);
	return 0;
}

static luaL_Reg cMethods[] = {
    { "Init", init },
	{ "Quit", quit },
	{ "PlayMusic", playMusic },
	{ "PlayFadeInMusic", playFadeInMusic },
	{ "SetMusicVolume", setMusicVolume },
	{ "GetMusicVolume", getMusicVolume },
	{ "PauseMusic", pauseMusic },
	{ "ResumeMusic", resumeMusic },
	{ "PlaySound", playSound },
	{ "Pause", pause },
	{ "Sleep", sleep },
    { NULL, NULL }
};

extern "C" __declspec(dllexport)
int luaopen_EasyAudio(lua_State * L)
{
    luaL_newlib(L, cMethods);
    return 1;
}
