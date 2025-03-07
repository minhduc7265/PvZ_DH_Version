#pragma once
#ifndef ITEM_H_
#define ITEM_H_
#include "base_func.h"

class Item {


private:
	bool is_collected;
	int type;
	
	int value_item;
	
	SDL_Texture* texture;

public:
	int type_anim;
	int animation;
	int time_anim;
	SDL_Rect rect_;
	SDL_Rect* currentClip;
	int cur_frame;
	int num_frame;
	Item();
	~Item();
	void set_collected(bool is_collect) {
		is_collected = is_collect;
	}
	bool get_collected() const {
		return is_collected;
	}
	int get_type() const {
		return type;
	}
	void set_properties(int type_, int type_anim_, int animation_) {
		type = type_;
		type_anim = type_anim_;
		animation = animation_;

	}
	void set_texture(SDL_Texture* texture_) {
		texture = texture_;

	}

};


#endif // !ITEM_H_
