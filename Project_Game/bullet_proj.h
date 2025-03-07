#pragma once
#ifndef BULLET_PROJ_H_
#define BULLET_PROJ_H_
#include "base_func.h"
#include "load_pic.h"


//khai báo Bullet <tên biến>
class Bullet : public LoadPIC {

private:
	//vị trí x,y
	//rect_.x và rect_.y
	//vận tốc 
	//phương ox
	int vel_x;
	//phương oy
	int vel_y;
	
	int type;



public:
	double temp;
	int oy;
	double min_ox;
	int delay_time;
	bool is_out;
	Bullet();
	~Bullet();//hàm xóa bỏ
	//hàm get và set
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

	//hàm check sự di chuyển và di chuyển

	void HandleBullet(int limOx, int limOy);
	//hàm set vị trí
	void set_Pos(int x, int y);












};









#endif // !BULLET_PROJ_H_




