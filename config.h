#pragma once

//��Ļ����
constexpr auto SCR_WIDTH = 1280;
constexpr auto SCR_HEIGHT = 760;

//�����ж�
constexpr auto FORWARD = 0;
constexpr auto BACKWARD = 1;
constexpr auto LEFT = 2;
constexpr auto RIGHT = 3;
constexpr auto SPACE = 4;
constexpr auto LCTRL = 5;
constexpr auto LSHIFT = 6;


//Chunk����
constexpr auto CHUNK_SIZE = 16;
constexpr auto CHUNK_AREA = 256;
constexpr auto CHUNK_VOLUME = 4096;

//World����
constexpr auto WATER_LEVEL = 64;	 //ˮƽ��;
constexpr auto AIR_SPACE = 30;		//Ԥ���Ŀ����߶�;
constexpr auto MAXIMUM_HEIGHT = 128;