#pragma once
#include "bullet_proj.h"



Bullet::Bullet() {
	num_row = 0;
	vel_x = 0;
	vel_y = 0;
	type = 0;
	delay_time = 0;
	is_out = false;
	is_hit = false;
	temp = 0;
	oy = 0;
	min_ox = 0;
	num_col = 0;
}


Bullet::~Bullet() {

	Free();

}

void Bullet::set_Pos(int x, int y) {
	rect_.x = x;
	rect_.y = y;

}
//int 
void Bullet::HandleBullet(int lim_Ox, int lim_Oy) {
	delay_time++;
	if (delay_time > 0) {
		rect_.x += Bullet::get_vel_x();
		delay_time = 0;
		if (type == 4) {

			double temp = oy + (0.5*(rect_.x - 80 * num_col) * (rect_.x - 80*num_col)) / (Bullet::get_vel_x() * Bullet::get_vel_x()) - min_ox * (rect_.x - 80 * num_col);
			rect_.y = int(temp);

		}
	}
	
	//cout << rect_.x << endl;
	//cout << Bullet::get_vel_x() << endl;
	if (rect_.x > lim_Ox || rect_.y > lim_Oy) {
		is_out = true;
	}
}