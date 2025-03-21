#include "element.h"



const std::map<std::string, int> body_bl{
	{"zombie",270},
	{"conezombie",270},
	{"zomboni",750},
	{"seafzombie",470},
	{"exzombie",470},
	{"pea_zombie",270},
	{"ball_zombie",270},
	{"sky_zombie",270}


};
const std::map<std::string, int> armor1_bl{
	{"zombie",0},
	{"conezombie",370},
	{"zomboni",0},
	{"seafzombie",0},
	{"exzombie",0},
	{"pea_zombie",0},
	{"ball_zombie",0},
	{"sky_zombie",0}
};
const std::map<std::string, int> armor2_bl{
	{"zombie",0},
	{"conezombie",0},
	{"zomboni",0},
	{"seafzombie",0},
	{"exzombie",0},
	{"pea_zombie",0},
	{"ball_zombie",0},
	{"sky_zombie",0}
};
Music gulp;
const int BLOOD_DEAD = 50;
Lawn_Mana game_lawn;
Cur_imf cur_imformation;
Element::Element() {
	mHeight = 0;
	mWidth = 0;
}
Element::~Element() {
	for (std::map<std::string, Texture_Storage*>::iterator it = list_texture.begin(); it!=list_texture.end(); ) {
		delete it->second;
		it = list_texture.erase(it);
	}
}
void Element::call_bullet(SDL_Renderer *ren, int type, int mx, int my, int row, int col, int vel) {
	//SDL_PollEvent(&event);
	
		Bullet* cre_bull = new Bullet();
		if (type == 1) {
			cre_bull->Set_Name_Path("projectiles/pea.png");
			cre_bull->LoadImg("projectiles/pea.png", ren);
		}
		else if (type == 2) {
			cre_bull->Set_Name_Path("projectiles/frozen_pea.png");
			cre_bull->LoadImg("projectiles/frozen_pea.png", ren);
		}
		else if (type == 3) {
			cre_bull->Set_Name_Path("projectiles/newspaper.png");
			cre_bull->LoadImg("projectiles/newspaper.png", ren);
		}
		else if (type == 4) {
			cre_bull->Set_Name_Path("projectiles/melon.png");
			cre_bull->LoadImg("projectiles/melon.png", ren);
		}
		else if (type == 5) {
			cre_bull->Set_Name_Path("projectiles/leaf.png");
			cre_bull->LoadImg("projectiles/leaf.png", ren);
		}
		else {
			cre_bull->Set_Name_Path("projectiles/pea.png");
			cre_bull->LoadImg("projectiles/pea.png", ren);
		}
		cre_bull->num_row = row;
		cre_bull->num_col = col;
		cre_bull->SetRect(mx, my);
		cre_bull->oy = cre_bull->rect_.y;
		cout << cre_bull->rect_.x << endl;
		cre_bull->set_type(type);
		cre_bull->set_vel(vel, 0);
		list_of_bullet.push_back(cre_bull);
		std::cout << "Bullet created!" << std::endl;


}
void Element::check_bullet(SDL_Renderer* ren) {
	for (std::vector<Bullet*>::iterator it = list_of_bullet.begin(); it != list_of_bullet.end();) {
		if ((*it) != NULL) {
			if ((*it)->is_out == false) {
				(*it)->HandleBullet(SCREEN_WID, SCREEN_HEI);
				it++;
			}
			else {
				delete* it;
				it = list_of_bullet.erase(it);
			}
		}
		else {
			it++;
		}
	}
}
void Element::remote_func_bullet(SDL_Renderer *ren) {//
	for (std::vector<Bullet*>::iterator it = list_of_bullet.begin(); it != list_of_bullet.end(); it++) {
		if ((*it) != NULL) {
			(*it)->Render(ren, NULL);
		}
	}
}
bool Element::Load_Texture(std::string path, SDL_Renderer* screen, std::string name, std::string type) {
	if (list_texture.find(name) != list_texture.end()) {
		std::cout << "Tim thay " << name << " " << std::endl;
		return true;
	}
	else {
		Texture_Storage* new_ = new Texture_Storage();
		SDL_Texture* newTexture = NULL;
		SDL_Surface* loadedSurface = IMG_Load(path.c_str());
		if (loadedSurface == NULL)
		{
			cout << "Khong load duoc: " << path << " " << IMG_GetError() << std::endl;
			cout << SDL_GetError() << endl;
			return false;
		}
		else
		{
			SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
			newTexture = SDL_CreateTextureFromSurface(screen, loadedSurface);
			if (newTexture == NULL)
			{
				cout << "Khong tao duoc texture: " << name << " " << SDL_GetError() << std::endl;
			}
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
			SDL_FreeSurface(loadedSurface);
		}

		new_->set_ptr(newTexture);
		new_->set_name(name);
		new_->set_type(type);
		list_texture[name] = new_;
		return list_texture[name] != NULL;

	}



}
Plant* Element::call_plant(std::string name, int x, int y,int frame) {
	Plant* new_plant = new Plant();//con trỏ plant
	new_plant->set_num_row(x);//hàng
	new_plant->set_num_col(y);//cột
	new_plant->name_plant = name;
	new_plant->set_can_eat(true);
	new_plant->set_cur_blood(400);
	new_plant->status = "idle";
	new_plant->count_down = 0;
	if (new_plant->name_plant == "sunflower" || new_plant->name_plant == "twinsun") {
		new_plant->count_down = 450;
	}
	new_plant->num_frame = frame;
	if (new_plant->name_plant == "fire" || new_plant->name_plant == "zom_fire" || new_plant->name_plant == "explosion" || new_plant->name_plant == "light_red" || new_plant->name_plant == "melon_pro" || new_plant->name_plant == "oxy") {
		new_plant->if_effect = true;
	}
	else {

	}
	list_plant.push_back(new_plant);

	std::cout << "Created: " << name << std::endl;
	return new_plant;

}
void Element::call_item(int type_, int x, int y, int frame) {
	Item* new_item = new Item();
	new_item->rect_.x = x;
	new_item->rect_.y = y;
	new_item->num_frame = frame;
	new_item->set_properties(type_, 1, 0);
	list_item.push_back(new_item);

	std::cout << "created item" << std::endl;
	
}
void Element::check_item() {
	for (std::vector<Item*>::iterator it = list_item.begin(); it != list_item.end();) {
		if ((*it) != NULL) {
			(*it)->cur_frame++;

			if ((*it)->type_anim == 1) {
				(*it)->time_anim++;
				(*it)->rect_.y-=8;
				if ((*it)->time_anim > 10 && (*it)->time_anim <=30) {
					(*it)->rect_.y+=16;
				}
				else if ((*it)->time_anim > 30) {
					(*it)->type_anim = 0;
				}
			}
			if (((*it)->cur_frame) >= ((*it)->num_frame - 1)) {
				(*it)->cur_frame = 0;

			}
			if ((*it)->rect_.x >= -20 && (*it)->rect_.x <= 10 && (*it)->rect_.y >= -20 && (*it)->rect_.y <= 15 && (*it)->get_collected() != true) {
				cur_imformation.cur_sun += 50;
				(*it)->set_collected(true);
			}
			
			if ((*it)->animation == 1) {
				if ((*it)->rect_.x >= 1) {
					(*it)->rect_.x -= (*it)->rect_.x / 5;

				}
				if ((*it)->rect_.y >= 1) {
					(*it)->rect_.y -= (*it)->rect_.y / 5;
				}
			}

			if ((*it)->get_collected() == true) {
				delete *it;
				it = list_item.erase(it);
				
			}
			else {
				it++;
			}


		}

		else {
			it++;
		}
	}



}
void Element::call_zombie(std::string name, int x, int y, int frame) {
	Zombie* new_zombie = new Zombie();//con trỏ zombie
	new_zombie->num_row = x;
	new_zombie->num_col = y;
	new_zombie->pos_x = new_zombie->num_col * 45 + 400;
	new_zombie->pos_y = new_zombie->num_row * 100 + 45;
	new_zombie->name_zombie = name;
	new_zombie->zom_blood = body_bl.at(name);//270
	new_zombie->status = "walk";
	new_zombie->num_frame = frame;
	new_zombie->armor_type_1 = armor1_bl.at(name);
	new_zombie->armor_typr_2 = armor2_bl.at(name);
	list_zombie.push_back(new_zombie);
	std::cout << "Created: " << name << std::endl;
}
void Element::check_plant() {
	for (std::vector<Plant*>::iterator it = list_plant.begin(); it != list_plant.end();) {
		if ((*it) != NULL) 
		{
			if ((*it)->get_cur_blood()<20) {
				(*it)->set_is_dead(true);
			}
			if ((*it)->get_is_dead() == true) {
				if ((*it)->if_effect == false) {
					game_lawn.Array_Manager[(*it)->get_num_row()][(*it)->get_num_col()].setIsPlanted(false);
					game_lawn.Array_Manager[(*it)->get_num_row()][(*it)->get_num_col()].setPtrPlant(NULL);
				}
				
				if (!(*it)->if_effect) {
					gulp.Play_Sound(23);
				}
				
				delete *it;
				it = list_plant.erase(it);
				
			}
			else {
				it++;
			}
		}
		else {
			it++;
		}

	}

}
void Element::check_zombie() {
	for (std::vector<Zombie*>::iterator it = list_zombie.begin(); it != list_zombie.end();) {
		if ((*it) != NULL) {
			if ((*it)->zom_blood <= BLOOD_DEAD) {
				(*it)->zom_blood--;
				(*it)->status = "dead";
				if ((*it)->is_dead != true) {
					(*it)->cur_frame = 0;
					(*it)->zom_blood = BLOOD_DEAD;
					(*it)->is_dead = true;
				}
			}
			if ((*it)->is_dead == true && (*it)->zom_blood<=2) {
				delete *it;
				it = list_zombie.erase(it);
				
			}
			else {
				it++;
			}
		}
		else {
			it++;
		}

	}

}
void Element::remote_frame_zombie() {
	for (std::vector <Zombie*>::iterator it = list_zombie.begin(); it != list_zombie.end(); it++) {
		Zombie* cur_zombie = *it;
		if (cur_zombie != NULL) {		
			int num_frame_ = cur_zombie->num_frame;
			cur_zombie->cur_frame += 1;
			if ((cur_zombie->cur_frame) >= (num_frame_ - 1)) {
				cur_zombie->cur_frame = 0;
			}
		}
		

	}


}
void Element::remote_frame_plant() {
	for (std::vector <Plant*>::iterator it = list_plant.begin(); it != list_plant.end(); it++) {
		Plant* cur_plant = *it;
		if (cur_plant != NULL) {
			int num_frame_ = cur_plant->num_frame;
			cur_plant->cur_frame += 1;
			if ((cur_plant->name_plant == "sunflower" || cur_plant->name_plant == "twinsun") && cur_plant->status == "production") {
				cur_plant->cur_frame += 1;
			}
			if ((cur_plant->cur_frame) >= (num_frame_ - 1)) {
				cur_plant->cur_frame = 0;
			}
		}
		

	}









}
void Element::remote_func_plant() {
	for (std::vector <Plant*>::iterator it = list_plant.begin(); it != list_plant.end(); it++) {//dễ hơn thì dùng auto it nhưng vì mơi học
		Plant* cur_plant = *it;
		if (cur_plant != NULL) {
			cur_plant->count_down++;
			if (cur_imformation.cur_td_adventure != 0) {
				cur_plant->dec_blood--;
				if (cur_plant->dec_blood < 0) {
					cur_plant->set_cur_blood(cur_plant->get_cur_blood() - 40);
					cur_plant->dec_blood = 50;
				}
			}


			if (cur_plant->name_plant == "sunflower") {
				if (cur_plant->count_down == 600) {
					cur_plant->cur_frame = 0;
					cur_plant->status = "production";
				}
				else if (cur_plant->count_down >= 600 && cur_plant->cur_frame >= 58) {
					cur_plant->cur_frame = 0;
					cur_plant->status = "idle";
					cur_plant->count_down = 0;
				}

			}
			else if (cur_plant->name_plant == "twinsun") {
				if (cur_plant->count_down == 600) {
					cur_plant->cur_frame = 0;
					cur_plant->status = "production";
				}
				else if (cur_plant->count_down >= 600 && cur_plant->cur_frame >= 42) {
					cur_plant->cur_frame = 0;
					cur_plant->status = "idle";
					cur_plant->count_down = 0;
				}

			}
			else if (cur_plant->name_plant == "banana_tree") {
				if (cur_plant->count_down == 100 && cur_plant->if_shoot == true) {
					cur_plant->cur_frame = 100;
					cur_plant->num_frame = 191;
					cur_plant->status = "shoot";
				}
				if (cur_plant->count_down >= 130) {
					if (cur_plant->if_shoot == true) {
						cur_plant->cur_frame = 0;
						cur_plant->status = "idle";
						cur_plant->num_frame = 191;
						cur_plant->count_down = 0;
					}
					else {
						cur_plant->cur_frame = 0;
						cur_plant->status = "idle";
						cur_plant->count_down = 0;
						cur_plant->num_frame = 60;
					}
				}

			}
			else if (cur_plant->name_plant == "oxygen_algae") {
				cur_plant->dec_blood = 50;
				for (std::vector <Plant*>::iterator it2 = list_plant.begin(); it2 != list_plant.end(); it2++) {//dễ hơn thì dùng auto it nhưng vì mơi học
					Plant* cur2_plant = *it2;
					if (cur2_plant != NULL && cur2_plant->name_plant != "oxygen_algae") {
						if (cur2_plant->num_col >= cur_plant->num_col - 1 && cur2_plant->num_col <= cur_plant->num_col + 1 && cur2_plant->num_row >= cur_plant->num_row - 1 && cur2_plant->num_row <= cur_plant->num_row + 1) {
							cur2_plant->dec_blood = 50;//3x3->không trừ
						}
					}
				}
			}
			else if (cur_plant->name_plant == "snowpea" || cur_plant->name_plant == "peashooter") {
				if (cur_plant->count_down == 60 && cur_plant->if_shoot == true) {
					cur_plant->cur_frame = 0;
					cur_plant->status = "shoot";
				}
				if (cur_plant->count_down >= 90 && cur_plant->if_shoot == true) {
					cur_plant->cur_frame = 0;
					cur_plant->status = "idle";
					cur_plant->count_down = 41;
				}

			}
			else if (cur_plant->name_plant == "repeater") {
				cur_plant->num_frame = 30;
				if (cur_plant->count_down == 60 && cur_plant->if_shoot == true) {
					cur_plant->cur_frame = 0;
					cur_plant->status = "shoot";
				}
				if (cur_plant->count_down >= 90 && cur_plant->if_shoot == true) {
					cur_plant->cur_frame = 0;
					cur_plant->status = "idle";
					cur_plant->count_down = 41;
				}

			}

			else if (cur_plant->name_plant == "shiliu") {
				if (cur_plant->count_down == 90 && cur_plant->if_shoot == true) {
					cur_plant->cur_frame = 0;
					cur_plant->status = "shoot";
				}
				if (cur_plant->count_down >= 120 && cur_plant->if_shoot == true) {
					cur_plant->cur_frame = 0;
					cur_plant->status = "idle";
					cur_plant->count_down = 0;
				}

			}
			else if (cur_plant->name_plant == "potato_mine") {
				if (cur_plant->count_down == 1) {
					cur_plant->cur_frame = 0;
					cur_plant->status = "idle";
				}
				else if (cur_plant->count_down > 13 && cur_plant->count_down < 469) {
					cur_plant->status = "idle";
					cur_plant->cur_frame = 27;
				}
				else if (cur_plant->count_down == 470) {
					cur_plant->cur_frame = 0;
					cur_plant->status = "up";
				}
				else if (cur_plant->count_down == 480) {
					cur_plant->cur_frame = 0;
					cur_plant->status = "upidle2";
				}

			}
			else {
				if (cur_plant->count_down == 70) {
					cur_plant->cur_frame = 0;
					cur_plant->status = "shoot";
				}
				if (cur_plant->count_down >= 100) {
					cur_plant->cur_frame = 0;
					cur_plant->status = "idle";
					cur_plant->count_down = 0;
				}

			}

			if (cur_plant->if_shoot == false && cur_plant->name_plant != "sunflower"&& cur_plant->name_plant != "twinsun" && cur_plant->name_plant != "potato_mine") {
				cur_plant->status = "idle";
			}


		}
		



	}


}
void Element::remote_func_zombie() {
	for (std::vector <Zombie*>::iterator it = list_zombie.begin(); it != list_zombie.end(); it++) {
		Zombie* cur_zombie = *it;
		if (cur_zombie != NULL) {
			cur_zombie->count_down++;
			if (cur_zombie->count_down >= 2 && cur_zombie->is_dead == false && cur_zombie->status != "eat") {
				cur_zombie->pos_x -= 1;
				cur_zombie->count_down = 0;
			}
			
		}

	}


}
void Element::reset_list_plant() {
	for (std::vector<Plant*>::iterator it = list_plant.begin(); it != list_plant.end(); ) {
		delete* it;
		it = list_plant.erase(it);
	}
	list_plant.clear();
}
void Element::reset_list_zombie() {
	for (std::vector<Zombie*>::iterator it = list_zombie.begin(); it != list_zombie.end(); ) {
		delete* it;
		it = list_zombie.erase(it);
	}
	list_zombie.clear();
}
void Element::reset_list_bullet() {
	for (std::vector<Bullet*>::iterator it = list_of_bullet.begin(); it != list_of_bullet.end(); ) {
		delete* it;
		it = list_of_bullet.erase(it);
	}
	list_of_bullet.clear();
}