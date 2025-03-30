#pragma once
#ifndef TEXTURE_STORAGE_
#define TEXTURE_STORAGE_
#include "base_func.h"
class Texture_Storage {
public:
	Texture_Storage();
	~Texture_Storage();
	void Free_Storage();
	
	SDL_Texture* get_ptr_texture() const {
		return _texture_st;
	}
	std::string get_type() const {
		return type;
	}
	void set_type(std::string name) {
		type = name;
	}
	std::string get_name()const {
		return name_texture;
	}
	void set_name(std::string name_) {
		name_texture = name_;

	}
	void set_ptr(SDL_Texture* texture) {
		_texture_st = texture;
	}
	int getLength() const {
		return numLength;
	}
	void setLength(int length) {
		numLength = length;
	}
	int mW;
	int mH;
protected:
	SDL_Texture* _texture_st;
	std::string type;
	std::string name_texture;
	int numLength;

};


#endif