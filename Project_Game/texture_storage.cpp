#include "texture_storage.h"



Texture_Storage::Texture_Storage() {
	numLength = 0;
	_texture_st = NULL;
	type = "";
	mW = 0;
	mH = 0;
	name_texture = "";

}
Texture_Storage::~Texture_Storage() {


	Free_Storage();
}



void Texture_Storage::Free_Storage() {
	if (_texture_st != NULL) {
		SDL_DestroyTexture(_texture_st);
		_texture_st = NULL;
		type = "";
		numLength = 0;
		mW = 0;
		mH = 0;
		name_texture = "";
	}
}