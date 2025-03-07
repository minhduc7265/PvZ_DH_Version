#include "texture_storage.h"



Texture_Storage::Texture_Storage() {

	_texture_st = NULL;
	type = "";
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
		name_texture = "";
	}
}