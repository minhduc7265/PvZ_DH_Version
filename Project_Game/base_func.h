#pragma once
#ifndef BASE_FUNC_H_
#define BASE_FUNC_H_

#include <iostream>
#include <string>
#include <SDL.h>
#include <map>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdlib.h>
#include <utility>
#include "card_plant.h"
using std::cout;
using std::endl;
static SDL_Window* window = NULL;
extern SDL_Renderer* renderer;
static SDL_Event event;
static std::pair<int, int> mouse_x_y;
extern PlantCard card[7];
extern PlantCard card_[10];
const int FIRST_X = 30;
const int SECOND_X = 110;
const int FIRST_Y = 80;
const int SECOND_Y = 180;
const int DISTANCE_X = 80;
const int DISTANCE_Y = 100;

const int SCREEN_WID = 800;
const int SCREEN_HEI = 600;
const int SCREEN_BFF = 32;

const int COLOR_R = 255;
const int COLOR_G = 255;
const int COLOR_B = 255;

const int FPS = 30;
class Cur_imf {//Thông tin hiện tại

public:
	int cur_sun;//max is 22500
	int cur_sence;//0 is day, 1 is night, 2 is zengarden, 3 is dragon place
	int flag_process;
	int delay_time;
	int flag1x;
	int flag1y;
	int flag2x;
	int flag2y;
	int flag3x;
	int flag3y;
	int wintime;
	int wave;
	int time_delay;
	int frame_mg_image;
	int cur_mini_game;
	int cur_td_adventure;
	int type_flag;
	int tiankongX;
	int count_time;
	Uint8 color;//0->255
	std::string mouseButton;
	Cur_imf();
	~Cur_imf();
	void reset_process();
	void set_mg_image();
	


};



#endif // !BASE_FUNC_H_
