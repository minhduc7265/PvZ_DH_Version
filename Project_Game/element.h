#pragma once
#ifndef ELEMENT_H_
#define ELEMENT_H_
#include "bullet_proj.h"
#include "plant.h"
#include <vector>
#include <map>
#include "texture_storage.h"
#include "card_plant.h"
#include "zombie.h"
#include "item.h"
extern Cur_imf cur_imformation;
class Element : public Bullet, public Texture_Storage, public Plant, public Zombie,public Item {
protected:
	




private:
	//tạo vector quản lí đạn
	
	//vector quản lí plant
	
	/// <summary>
	/// 
	/// </summary>
	int mWidth;
	int mHeight;
public:
	std::map<std::string, Texture_Storage*> list_texture;
	std::vector <Plant*> list_plant;
	std::vector <Plant*> list_effect;
	std::vector <Zombie*> list_zombie;
	std::vector <Bullet*> list_of_bullet;
	std::vector <Item*> list_item;
	Element();
	~Element();

	//hàm lấy dữ liệu vector ,thừa vkl
	std::vector<Bullet*>& Get_Vector_Bullet() {
		return list_of_bullet;

	}
	std::vector<Plant*>& Get_Vector_Plant() {
		return list_plant;

	}
	std::vector<Zombie*>& Get_Vector_Zombie() {
		return list_zombie;

	}
	//hàm gán dữ liệu//mà chả cần đâu
	//hàm tạo đạn
	void call_bullet(SDL_Renderer* ren, int type, int mx, int my, int row, int col);

	void check_bullet(SDL_Renderer* ren);

	void call_plant(std::string name, int x, int y, int frame);

	void check_plant();

	void remote_frame_plant();

	void remote_func_plant();



	void call_zombie(std::string name, int x, int y, int armor_type_1_, int armor_typr_2_, int frame);

	void check_zombie();

	void remote_frame_zombie();

	void remote_func_zombie();

	void call_item(int type_, int x, int y, int frame);

	void check_item();























	//load texture
	bool Load_Texture(std::string path, SDL_Renderer* screen, std::string name, std::string type);
	/// <summary>
	///
	//render
	void Render(SDL_Renderer* render, SDL_Rect* clip, std::string name,int x,int y,int z,int t) {
		//test
		SDL_Rect renderquad = { x,y,z,t };
		//z = clip->w/2+20
		//t = clip->h/2+20
		/*if (clip != NULL)
		{
			renderquad.w = clip->w;
			renderquad.h = clip->h;
		}*/
		SDL_RenderCopy(render, list_texture[name]->get_ptr_texture(), clip, &renderquad);
	}




	


};








#endif