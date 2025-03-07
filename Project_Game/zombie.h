#pragma once
#ifndef ZOMBIE_H_
#define ZOMBIE_H_





#include "base_func.h"


class Zombie {

public:
	Zombie();
	~Zombie();
	std::string name_zombie;
	int zom_blood;
	int armor_type_1;//bucket;
	int armor_typr_2;//door;
	bool is_dead;
	bool is_eat;
	std::string status;
	SDL_Rect* currentClip;
	int num_row;
	int num_col;
	int pos_x;
	int pos_y;
	int num_frame;//số frame max
	int cur_frame;//frame hiện tại
	int count_down;
	int slow_time;

protected:
	
	



};

#endif // !ZOMBIE_H_