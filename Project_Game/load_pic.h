#pragma once
#ifndef LOAD_PIC_H_
#define LOAD_PIC_H_
#include "base_func.h"
class Texture {
protected:
	std::map<std::string, SDL_Texture*> textures;
};

class LoadPIC : public Texture {

public:
	LoadPIC();//hàm gốc
	~LoadPIC();//hàm xóa
	void SetRect(const int& x, const int& y) {//hàm set
		rect_.x = x;
		rect_.y = y;
	}
	SDL_Rect GetRect() const {
		return rect_;//định nghĩa hàm GetRect() const ý là k làm thay đổi giá trị
	}
	//SDL_Texture* GetPic() const {
		//return textures[name_path];
	//}
	void Render_2(SDL_Renderer* render, const SDL_Rect* clip, const SDL_Rect* clip_2, const SDL_Point* center, double angle);
	bool LoadImg(std::string path, SDL_Renderer* screen);
	void Render(SDL_Renderer* render, const SDL_Rect* clip = NULL);
	void Free();
	void Free_Texture();
	void Set_Name_Path(std::string name) {
		name_path = name;
	}
	SDL_Rect rect_;
protected:
	std::string name_path;
	//SDL_Texture* temp_pic;
	
};




#endif // !LOAD_PIC_H_
