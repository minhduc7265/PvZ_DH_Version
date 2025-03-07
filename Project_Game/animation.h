#pragma once
#ifndef ANIMATION_H_
#define ANIMATION_H_
#include "base_func.h"
const int NUM_FRAME_PER_ROW_PLANT = 5;
const int NUM_FRAME_PER_ROW_ZOMBIE = 10;
class Animation {
private:
	SDL_Rect* gSpriteClips = NULL;//chứa frame

public:
	Animation();
	int num_frame;
	SDL_Rect* get_clip() const {
		return gSpriteClips;
	}
	void set_clip(int _num_frame, int wid, int hei) {
		num_frame = _num_frame;
		gSpriteClips = new SDL_Rect[_num_frame];
		for (int i = 0; i < _num_frame; i++) {
			gSpriteClips[i] = { (i % NUM_FRAME_PER_ROW_PLANT) * wid,(i / NUM_FRAME_PER_ROW_PLANT) * hei,wid,hei };
		}

	}
	void set_clip_bonus(int _num_frame, int wid, int hei) {
		num_frame = _num_frame;
		gSpriteClips = new SDL_Rect[_num_frame];
		for (int i = 0; i < _num_frame; i++) {
			gSpriteClips[i] = { (i % NUM_FRAME_PER_ROW_ZOMBIE) * wid,(i / NUM_FRAME_PER_ROW_ZOMBIE) * hei,wid,hei };
		}

	}





};





#endif // !ANIMATION_H_
