#pragma once
#ifndef BULLET_PROJ_H_
#define BULLET_PROJ_H_
#include "base_func.h"
#include "load_pic.h"
class Bullet : public LoadPIC {
private:
	int vel_x;
	int vel_y;
	int type;
public:
	double temp;
	int oy;
	double min_ox;
	int delay_time;
	bool is_out;
	Bullet();
	~Bullet();
	int num_row;
	int num_col;
	bool is_hit;
	int get_vel_x() const {
		return vel_x;
	}
	int get_vel_y() const {
		return vel_y;
	}
	int get_type() const {
		return type;
	}
	void set_type(int x) {
		type = x;
	}
	void set_vel(int x, int y) {
		vel_x = x;
		vel_y = y;
	}
	void HandleBullet(int limOx, int limOy);
	void set_Pos(int x, int y);
};
#endif




