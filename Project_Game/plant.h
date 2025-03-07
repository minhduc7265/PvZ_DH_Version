#pragma once
#ifndef PLANT_H_
#define PLANT_H_
#include "load_pic.h"

class Plant {

public:
	Plant();
	~Plant();
	int get_cur_blood() const {
		return current_blood;
	}
	void set_cur_blood(int bl) {
		current_blood = bl;
	}
	/*int get_cd() const {
		return count_down;
	}
	void set_cd(int cd) {
		count_down = cd;
	}*/
	bool get_is_dead() const {
		return is_dead;
	}
	void set_is_dead(bool dead_num) {
		is_dead = dead_num;
	}

	bool get_can_eat() const {
		return if_can_eat;
	}
	void set_can_eat(bool can_eat) {
		if_can_eat = can_eat;
	}

	int get_num_row() const {
		return num_row;
	}
	void set_num_row(int row) {
		num_row = row;
	}
	int get_num_col() const {
		return num_col;
	}
	void set_num_col(int col) {
		num_col = col;
	}

	void set_name(std::string name) {
		name_plant = name;
	}
	std::string get_name() const {
		return name_plant;
	}




	int count_down;
	std::string name_plant;//tên plant
	int num_frame;//số frame max
	int cur_frame;//frame hiện tại
	/*Uint32 lastFrameTime;
	Uint32 currentTime;*/

	SDL_Rect* currentClip;
	std::string status;


	bool if_shoot;
	int num_row;
	int num_col;
	bool if_effect;


private:
	int current_blood;//máu tối đa
	//đếm thời gian CD
	bool is_dead;
	bool if_can_eat;
	
//protected:
	//std::string name_plant;//tên plant
	//int num_frame;//số frame max
	//int cur_frame;//frame hiện tại
	//Uint32 lastFrameTime;
	//Uint32 currentTime;

	//SDL_Rect* currentClip;// = &gSpriteClips[frame / num_frame];





};




#endif // !PLANT_H_
