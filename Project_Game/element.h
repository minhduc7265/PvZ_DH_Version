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
#include "lawn.h"
#include "music.h"
#include "animation.h"
extern Music gulp;
extern Music rip;
extern TTF_Font* font;
extern Lawn_Mana game_lawn;
extern const std::map<std::string, int> body_bl;
extern const std::map<std::string, int> armor1_bl;
extern const std::map<int, std::pair<std::string, int>> rand_zombie;
extern const std::map<std::string, int> armor2_bl;
extern Cur_imf cur_imformation;
class Element : public Bullet, public Texture_Storage, public Plant, public Zombie,public Item {
protected:
private:
	int mWidth;
	int mHeight;
public:
	std::map<std::string, Texture_Storage*> list_texture;
	std::map<std::string, Texture_Storage*> listText;
	std::vector <Plant*> list_plant;
	std::vector <Plant*> list_effect;
	std::vector <Zombie*> list_zombie;
	std::vector <Bullet*> list_of_bullet;
	std::vector <Item*> list_item;
	Element();
	~Element();

	std::vector<Bullet*>& Get_Vector_Bullet() {
		return list_of_bullet;

	}
	std::vector<Plant*>& Get_Vector_Plant() {
		return list_plant;

	}
	std::vector<Zombie*>& Get_Vector_Zombie() {
		return list_zombie;

	}
	void call_bullet(SDL_Renderer* ren, int type, int mx, int my, int row, int col, int vel);
	void check_bullet(SDL_Renderer* ren);
	Plant* call_plant(std::string name, int x, int y, int frame);
	void call_eplant(std::string name, int x, int y, int frame);
	void check_plant();
	void remote_frame_plant();
	void remote_func_plant();
	void call_zombie(std::string name, int x, int y, int frame);
	void check_zombie();
	void remote_frame_zombie();
	void remote_func_zombie();
	void remote_func_bullet(SDL_Renderer* ren);
	void call_item(int type_, int x, int y, int frame);
	void check_item();
	void reset_list_plant();
	void reset_list_zombie();
	void reset_list_bullet();
	void set_color_texture(std::string name, Uint8 r, Uint8 g, Uint8 b);
	bool Load_Texture(std::string path, SDL_Renderer* screen, std::string name, std::string type);
	void loadNameLevel(std::string path, SDL_Renderer* render, std::string name);
	void Render(SDL_Renderer* render, SDL_Rect* clip, std::string name,int x,int y,int z,int t) {
		SDL_Rect renderquad = { x,y,z,t };
		SDL_RenderCopy(render, list_texture[name]->get_ptr_texture(), clip, &renderquad);
	}
	void RenderText(SDL_Renderer* render, SDL_Rect* clip, std::string name) {
		int temp = 0;
		if (cur_imformation.wave == 0) {
			temp = 780;
		}
		else {
			temp = 580;
		}
		SDL_Rect renderquad = { temp - 8 * listText[name]->getLength(),565,listText[name]->mW,listText[name]->mH };
		SDL_RenderCopy(render, listText[name]->get_ptr_texture(), clip, &renderquad);
	}
	void changeColorText(std::string name, Uint8 r, Uint8 g, Uint8 b) {
		SDL_SetTextureColorMod(listText[name]->get_ptr_texture(), r, g, b);
	}
	SDL_Texture* GetTexture(std::string name) {
		return list_texture[name]->get_ptr_texture();
	}
};
//extern Element plant_manager;
//extern Element zombie_manager;
//extern Element item_manager;
//extern Element texture_reanim;
extern Element all_game;


#endif