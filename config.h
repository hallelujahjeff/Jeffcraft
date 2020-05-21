#pragma once

//屏幕参数
constexpr auto SCR_WIDTH = 1280;
constexpr auto SCR_HEIGHT = 760;

//人物行动
constexpr auto FORWARD = 0;
constexpr auto BACKWARD = 1;
constexpr auto LEFT = 2;
constexpr auto RIGHT = 3;
constexpr auto SPACE = 4;
constexpr auto LCTRL = 5;
constexpr auto LSHIFT = 6;


//Chunk参数
constexpr auto CHUNK_SIZE = 16;
constexpr auto CHUNK_AREA = 256;
constexpr auto CHUNK_VOLUME = 4096;

//World参数
constexpr auto WATER_LEVEL = 64;	 //水平面;
constexpr auto AIR_SPACE = 30;		//预留的空气高度;
constexpr auto MAXIMUM_HEIGHT = 128;