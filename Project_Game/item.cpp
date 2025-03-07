#include "item.h"


Item::Item() {
	is_collected = false;
	type = 0;
	type_anim = 0;
	value_item = 0;
	animation = 0;
	texture = NULL;
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = 0;
	rect_.h = 0;
	cur_frame = 0;
	num_frame = 0;
	currentClip = NULL;
	time_anim = 0;

}

Item::~Item() {
	cur_frame = 0;
	is_collected = false;
	type = 0;
	type_anim = 0;
	value_item = 0;
	animation = 0;
	texture = NULL;
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = 0;
	rect_.h = 0;



}