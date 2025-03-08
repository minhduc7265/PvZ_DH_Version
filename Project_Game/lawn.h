#pragma once
#ifndef LAWN_H_
#define LAWN_H_
//Quản lí ô đất trồng
#include "base_func.h"
#include <iostream>

const int MAX_X = 5;
const int MAX_Y = 9;



class Lawn {
public:

	Lawn();



	int get_x_first() const {
		return x_first;
	}
	
	int get_x_second() const {
		return x_second;
	}
	
	int get_y_first() const {
		return y_first;
	}
	
	int get_y_second() const {
		return y_second;
	}
	
	void set_x_fi(int x) {
		x_first = x;
	}
	void set_x_se(int x) {
		x_second = x;
	}
	void set_y_fi(int x) {
		y_first = x;
	}
	void set_y_se(int x) {
		y_second = x;
	}


protected:
	int x_first;
	int x_second;
	int y_first;
	int y_second;
	bool is_planted;


};


class Lawn_Mana : public Lawn {

public:
	Lawn Array_Manager[5][9];
	void Lawn_Set() {
		for (int i = 0; i < MAX_X; i++) {
			for (int j = 0; j < MAX_Y; j++) {
				Array_Manager[i][j].set_x_fi(FIRST_X + DISTANCE_X * j);
				Array_Manager[i][j].set_x_se(SECOND_X + DISTANCE_X * j);
				Array_Manager[i][j].set_y_fi(FIRST_Y + DISTANCE_Y * i);
				Array_Manager[i][j].set_y_se(SECOND_Y + DISTANCE_Y * i);
			}
		}
	}


};


#endif // !LAWN_H_
