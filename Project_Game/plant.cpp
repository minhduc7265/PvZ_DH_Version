#include "plant.h"


Plant::Plant() {
	name_plant = "";//name plant;
	current_blood = 0;//máu tối đa
	count_down = 0;//đếm thời gian CD
	is_dead = false;
	if_can_eat = true;
	num_row = 0;
	num_col = 0;
	num_frame = 0;//số frame max
	cur_frame = 0;//frame hiện tại
	status = "";
	if_shoot = false;
	currentClip = NULL;// = &gSpriteClips[frame / num_frame];
	if_effect = false;

}

Plant::~Plant() {
	name_plant = "";//name plant;
	current_blood = 0;//máu tối đa
	count_down = 0;//đếm thời gian CD
	is_dead = true;
	if_can_eat = false;
	num_row = 0;
	num_col = 0;
	num_frame = 0;//số frame max
	cur_frame = 0;//frame hiện tại
	status = "";
	if_shoot = false;
	currentClip = NULL;// = &gSpriteClips[frame / num_frame];
	if_effect = false;

}