#include "animation.h"

Animation::Animation() {
	num_frame = 0;
	cur_frame = 0;
	gSpriteClips = NULL;
}

Animation::~Animation() {
	
	/*if (gSpriteClips != NULL) {
		delete[]gSpriteClips;
		gSpriteClips = NULL;
	}*/
	
}