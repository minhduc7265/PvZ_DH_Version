#include "element.h"

const int BLOOD_DEAD = 50;
Cur_imf cur_imformation;
Element::Element() {
	mHeight = 0;
	mWidth = 0;
	
}
Element::~Element() {
	//giải phóng texture 
	for (std::map<std::string, Texture_Storage*>::iterator it = list_texture.begin(); it!=list_texture.end(); ) {
		delete it->second;
		it = list_texture.erase(it);
	}

}


void Element::call_bullet(SDL_Renderer *ren, int type, int mx, int my, int row,int col) {
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
		cre_bull->set_vel(10, 0);
		list_of_bullet.push_back(cre_bull);
		std::cout << "Bullet created! Current count: " << std::endl;


}


void Element::check_bullet(SDL_Renderer* ren) {
	for (int i = list_of_bullet.size() - 1; i >= 0; i--) {
		Bullet* bull_ = list_of_bullet.at(i);
		if (bull_ != NULL) {
			if (bull_->is_out == false) {//bull_->is_out == false
				bull_->HandleBullet(SCREEN_WID, SCREEN_HEI);
				bull_->Render(ren, NULL);
			}
			else {
				list_of_bullet.erase(list_of_bullet.begin() + i);
				if (bull_ != NULL) {
					delete bull_;
					bull_ = NULL;
				}
			}
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
		//Load image at specified path
		SDL_Surface* loadedSurface = IMG_Load(path.c_str());
		if (loadedSurface == NULL)
		{
			cout << "Khong load duoc: " << path << " " << IMG_GetError() << std::endl;
			return false;
		}
		else
		{
			//Color key image
			SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

			//Create texture from surface pixels
			newTexture = SDL_CreateTextureFromSurface(screen, loadedSurface);
			if (newTexture == NULL)
			{
				cout << "Khong tao duoc texture: " << name << " " << SDL_GetError() << std::endl;
			}
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
			//Get rid of old loaded surface
			SDL_FreeSurface(loadedSurface);
		}

		new_->set_ptr(newTexture);
		new_->set_name(name);
		new_->set_type(type);

		//Return success
		list_texture[name] = new_;
		return list_texture[name] != NULL;

	}



}
void Element::call_plant(std::string name, int x, int y,int frame) {
	Plant* new_plant = new Plant();//con trỏ plant
	new_plant->set_num_row(x);//hàng
	new_plant->set_num_col(y);//cột
	new_plant->name_plant = name;
	new_plant->set_can_eat(true);
	new_plant->set_cur_blood(400);
	new_plant->status = "idle";
	new_plant->num_frame = frame;
	if (new_plant->name_plant == "fire" || new_plant->name_plant == "zom_fire" || new_plant->name_plant == "explosion" || new_plant->name_plant == "light_red" || new_plant->name_plant == "melon_pro") {
		new_plant->if_effect = true;
	}
	list_plant.push_back(new_plant);

	std::cout << "Created: " << name << std::endl;
	std::cout << new_plant->get_num_col() << std::endl;
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
	for (int i = list_item.size() - 1; i >= 0; i--) {
		if (list_item.at(i) != NULL) {
			Item* cur_item = list_item.at(i);
			cur_item->cur_frame++;
			if (cur_item->type_anim == 1) {
				cur_item->time_anim++;
				cur_item->rect_.y-=8;
				if (cur_item->time_anim > 10 && cur_item->time_anim <=30) {
					cur_item->rect_.y+=16;
				}
				else if (cur_item->time_anim > 30) {
					cur_item->type_anim = 0;
				}
			}
			if ((cur_item->cur_frame) >= (cur_item->num_frame - 1)) {
				cur_item->cur_frame = 0;

			}
			if (cur_item->rect_.x >= -20 && cur_item->rect_.x <= 10 && cur_item->rect_.y >= -20 && cur_item->rect_.y <= 15 && cur_item->get_collected() != true) {
				cur_imformation.cur_sun += 25;
				cur_item->set_collected(true);
			}
			
			if (cur_item->animation == 1) {
				if (cur_item->rect_.x >= 1) {
					cur_item->rect_.x -= cur_item->rect_.x / 5;

				}
				if (cur_item->rect_.y >= 1) {
					cur_item->rect_.y -= cur_item->rect_.y / 5;
				}
			}
			if (cur_item->get_collected() == true) {
				delete cur_item;
				cur_item = NULL;
				list_item.erase(list_item.begin() + i);
				
			}


		}
	}



}

void Element::call_zombie(std::string name, int x, int y, int armor_type_1_,int armor_typr_2_, int frame) {
	Zombie* new_zombie = new Zombie();//con trỏ zombie
	new_zombie->num_row = x;
	new_zombie->num_col = y;
	new_zombie->pos_x = new_zombie->num_col * 45 + 400;
	new_zombie->pos_y = new_zombie->num_row * 100 + 45;
	new_zombie->name_zombie = name;
	new_zombie->zom_blood = 270;//270
	new_zombie->status = "walk";
	new_zombie->num_frame = frame;
	new_zombie->armor_type_1 = armor_type_1_;
	new_zombie->armor_typr_2 = armor_typr_2_;
	list_zombie.push_back(new_zombie);

	std::cout << "Created: " << name << std::endl;
}


void Element::check_plant() {
	for (int i = list_plant.size() - 1; i >= 0; i--) {
		if (list_plant.at(i) != NULL) {
			Plant* cur_plant = list_plant.at(i);
			if (cur_plant->get_cur_blood() < 20) {
				cur_plant->set_is_dead(true);
			}
			if (cur_plant->get_is_dead() == true) {
				delete cur_plant;
				cur_plant = NULL;
				list_plant.erase(list_plant.begin() + i);
				
			}
		}

	}

}
void Element::check_zombie() {
	for (int i = list_zombie.size() - 1; i >= 0; i--) {
		if (list_zombie.at(i) != NULL) {
			Zombie* cur_zombie = list_zombie.at(i);
			if (cur_zombie->zom_blood <= BLOOD_DEAD) {
				cur_zombie->zom_blood--;
				cur_zombie->status = "dead";
				if (cur_zombie->is_dead != true) {
					cur_zombie->cur_frame = 0;
					cur_zombie->zom_blood = BLOOD_DEAD;
					cur_zombie->is_dead = true;
				}
			}
			if (cur_zombie->is_dead == true && cur_zombie->zom_blood<=2) {
				delete cur_zombie;
				cur_zombie = NULL;
				list_zombie.erase(list_zombie.begin() + i);
				
			}
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
			if (cur_plant->name_plant == "sunflower" && cur_plant->status == "production") {
				cur_plant->cur_frame += 1;
			}
			/*if (cur_plant->name_plant == "peashooter" && cur_plant->status == "shoot") {
				cur_plant->cur_frame += 1;
			}
			if (cur_plant->name_plant == "snowpea" && cur_plant->status == "shoot") {
				cur_plant->cur_frame += 1;
			}*/
			/*if (cur_plant->name_plant == "zom_fire") {
				cur_plant->cur_frame += 2;
			}*/
			if (cur_plant->name_plant == "banana_tree") {
				//cur_plant->cur_frame += 1;
			}
			if (cur_plant->name_plant == "oxygen_algae") {
				cur_plant->cur_frame += 1;
			}
			if (cur_plant->name_plant == "cherrybomb") {
				//cur_plant->cur_frame += 1;
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
			else if (cur_plant->name_plant == "banana_tree") {
				if (cur_plant->count_down == 100) {
					cur_plant->cur_frame = 100;
					cur_plant->status = "attack";
				}
				if (cur_plant->count_down >= 130) {
					cur_plant->cur_frame = 0;
					cur_plant->status = "idle";
					cur_plant->count_down = 0;
				}

			}
			else if (cur_plant->name_plant == "oxygen_algae") {
				if (cur_plant->count_down == 0) {
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

			if (cur_plant->if_shoot == false && cur_plant->name_plant != "sunflower") {
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