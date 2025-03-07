#include <iostream>
#include "main_func.h"
#include <string.h>
#include <cstdlib>
Texture texture_game;

Lawn_Mana game_lawn;
static int wintime = 0;

std::string sun_value = "";

//hàm chạy nhạc toàn game

std::map<int, int> set_game =
{
	{0,900},
	{1,500},
	{2,400},
	{3,500},
	{4,500},
	{5,400},
	{6,500},
	{7,500},
	{8,400},
	{9,500},
	{10,500},
	{11,400},//huge wave
	{12,500},
	{13,500},
	{14,400},//huge wave

};



static int wave = 0;
static int time_delay = 900;



static int time_huge = 0;












void set_wave_time() {
	time_huge = 0;
	huge_wave.SetRect(-180, -180);
	huge_wave.rect_.w = 1200;
	huge_wave.rect_.h = 900;
}


void render_huge_wave() {
	if (huge_wave.rect_.x < 0) {
		huge_wave.rect_.x+=18;
		huge_wave.rect_.y+=18;
	}
	if (huge_wave.rect_.w > 800) {
		huge_wave.rect_.w-=40;
	}
	if (huge_wave.rect_.h > 600) {
		huge_wave.rect_.h-=30;
	}
	huge_wave.Render(renderer, NULL);
}









bool InitData() {

	


	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cout << "Khong the khoi tao SDL_Mixer: " << Mix_GetError() << std::endl;
		success = false;
	}




	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	window = SDL_CreateWindow("Plants vs. Zombies DH Version - Normal Mode", SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 
		SCREEN_WID, 
		SCREEN_HEI, 
		SDL_WINDOW_SHOWN);
	if (window == NULL) {
		success = false;
	}
	else {
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == NULL) {
			success = false;

		}
		else {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) && imgFlags)) {
				success = false;
			}

		}
	}
	return success;
}

void render_flag_pro() {
	
	SDL_Rect rect = { 610,570,cur_imformation.flag_process,27 };
	//cout << &cur_imformation.flag_process << endl;
	SDL_Rect rect_2 = { 0,0,158,27 };
	SDL_Point center = { 79, 13 };
	pro_green.Render_2(renderer, &rect, &rect_2, &center, 180.0);
	
	pro_non.SetRect(610, 570);
	pro_non.Render(renderer, NULL);
	pro_flag.SetRect(cur_imformation.flag1x, cur_imformation.flag1y);
	pro_flag.Render(renderer, NULL);
	pro_flag.SetRect(cur_imformation.flag2x, cur_imformation.flag2y);
	pro_flag.Render(renderer, NULL);
	pro_zom.SetRect(760 - cur_imformation.flag_process, 567);
	pro_zom.Render(renderer, NULL);
}


void close() {

	bg_background.Free();
	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	SDL_DestroyWindow(window);
	window = NULL;
	IMG_Quit();
	SDL_Quit();
}
void cyp_remote() {
	card_[0].type = 2;
	card_[1].type = 0;
	card_[2].type = 3;
	card_[3].type = 5;
	card_[4].type = 1;
	card_[5].type = 4;
	card_[6].type = 6;
	card_[7].type = 7;
	card_[8].type = 8;
	card_[9].type = 14;
	for (int i = 0; i < 7; i++) {
		SDL_Rect* currentClip = NULL;
		if (card_[i].is_allow == true) {
			currentClip = &card_plant.get_clip()[card_[i].type];
			card_[i].card_xc = 25 + 60 * i;
			card_[i].card_xce = 25 + 60 * i + 50;
			card_[i].card_yc = 110;
			card_[i].card_yce = 180;
			texture_reanim.Render(renderer, currentClip, "card_plant", card_[i].card_xc, card_[i].card_yc, 50, 70);
		}
	}
	for (int i = 0; i < 3; i++) {
		SDL_Rect* currentClip = NULL;
		if (card_[i + 7].is_allow == true) {
			currentClip = &card_plant.get_clip()[card_[i + 7].type];
			card_[i + 7].card_xc = 25 + 60 * i;
			card_[i + 7].card_xce = 25 + 60 * i + 50;
			card_[i + 7].card_yc = 180;
			card_[i + 7].card_yce = 250;
			texture_reanim.Render(renderer, currentClip, "card_plant", card_[i + 7].card_xc, card_[i + 7].card_yc, 50, 70);
		}
		
	}
	set_order();
	render_card(renderer);
	//xác định giá trị nhỏ nhất của thẻ 
	int mini_ = 6;
	for (int i = 0; i <= 6; i++) {
		if (i <= mini_ && card[i].status_c == 0) {
			mini_ = i;
		}
	}
	//sự kiện khi bấm thẻ
	if (mini_ !=6 && CARD_LOCATE_C != -1 && card_[CARD_LOCATE_C].is_allow == true) {
		
		if (SDL_WaitEvent(&event) == 1 && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
			card[mini_].type = card_[CARD_LOCATE_C].type;
			card[mini_].status_c = 1;
			card_[CARD_LOCATE_C].is_allow = false;
		}

	}
	//khi thả thẻ ra
	if (CARD_LOCATE >= 0 && CARD_LOCATE <= 5 && card[CARD_LOCATE].status_c == 1) {
		if (SDL_WaitEvent(&event) == 1 && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
			//card[0].type = card_[i].type;
			//do xếp card loạn nên phải dùng if else để ép
			if (card[CARD_LOCATE].type == 2) {
				card_[0].is_allow = true;
			}
			else if (card[CARD_LOCATE].type == 0) {
				card_[1].is_allow = true;
			}
			else if (card[CARD_LOCATE].type == 3) {
				card_[2].is_allow = true;
			}
			else if (card[CARD_LOCATE].type == 5) {
				card_[3].is_allow = true;
			}
			else if (card[CARD_LOCATE].type == 1) {
				card_[4].is_allow = true;
			}
			else if (card[CARD_LOCATE].type == 4) {
				card_[5].is_allow = true;
			}
			/*else if (card[CARD_LOCATE].type == 14) {
				card_[9].is_allow = true;
			}*/
			else {
				card_[card[CARD_LOCATE].type].is_allow = true;
			}
			card[CARD_LOCATE].status_c = 0;
			
		}
	}
	
	


}


void status_process() {
	if (status_manager.status == 0) {
		if (is_music != 1) {
			play_mainmusic(ctx, 152);
			is_music = 1;
		}

		loadgame.SetRect(0, 0);
		loadgame.Render(renderer, NULL);
		if (mouseX >= 470 && mouseX <= 650 && mouseY >= 310 && mouseY <= 470) {

			but2.SetRect(470, 310);
			but2.Render(renderer, NULL);

			if (SDL_WaitEvent(&event) && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
				status_manager.status = 1;
			}
		}
		else {
			but1.SetRect(470, 310);
			but1.Render(renderer, NULL);
			
		}

	}
	else if (status_manager.status == 1) {
		if (is_music != 1) {
			play_mainmusic(ctx, 152);
			is_music = 1;
		}

		bgnormal.SetRect(0, 0);
		bgnormal.Render(renderer, NULL);
		if (mouseX >= 570 && mouseX <= 750 && mouseY >= 430 && mouseY <= 590) {
			adventure2.SetRect(570, 430);
			adventure2.Render(renderer, NULL);
			if (SDL_WaitEvent(&event) && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
				status_manager.status = 2;
			}
		}
		else {
			adventure1.SetRect(570, 430);
			adventure1.Render(renderer, NULL);
		}

	}
	else if (status_manager.status == 2) {
		if (is_music != 2) {
			play_mainmusic(ctx, 122);
			is_music = 2;
		}

		challengebg.SetRect(0, 0);
		challengebg.Render(renderer, NULL);
		for (int i = 0; i < 5; i++) {
			if (mouseX >= i * 155 + 30 && mouseX <= i * 155 + 30 + 120 && mouseY >= 100 && mouseY <= 215) {
				texture_reanim.Render(renderer, &level2.get_clip()[i], "level", i * 155 + 30, 100, 118, 120);

				if (SDL_WaitEvent(&event) && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
					status_manager.status = 3;
				}
			}
			texture_reanim.Render(renderer, &level.get_clip()[i], "level", i * 155 + 30, 100, 118, 120);
		}
		if (mouseX >= 10 && mouseX <= 100 && mouseY >= 575 && mouseY <= 590) {
			back2.SetRect(10, 575);
			back2.Render(renderer, NULL);

			if (SDL_WaitEvent(&event) && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
				status_manager.status = 1;
			}
		}
		else {
			back1.SetRect(10, 575);
			back1.Render(renderer, NULL);
		}


	}
	else if (status_manager.status == 3) {
		if (is_music != 3) {
			off_mainmusic(ctx);
			esdp_c.Play_Music("music/ESDP-S.mp3");
			/*play_mainmusic(ctx, 122);*/
			is_music = 3;
		}
		
		bg_sea.SetRect(pos_bg, 0);
		bg_sea.Render(renderer, NULL);
		//status_manager.status = 4;
		if (pos_bg > -550) {
			pos_bg -= 18;
		}
		if (pos_bg < -550) {
			cyp.rect_.y = (cyp.rect_.y >= 90) ? cyp.rect_.y -70: 70;
			
			cyp.Render(renderer, NULL);
			cyp_remote();

		}
		if (mouseX >= 690 && mouseX <= 780 && mouseY >= 5 && mouseY <= 40) {

			if (SDL_WaitEvent(&event) && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
				status_manager.status = 4;
			}
		}


	}


	else if (status_manager.status == 4) {
		if (is_music != 4) {
			off_mainmusic(ctx);
			esdp_c.End_Music();
			esdp.Play_Music("music/ESDP.mp3");
			/*set_channel_off(ctx, 18, 19, 20, 21);
			play_mainmusic(ctx, 184);*/
			is_music = 4;
		}
		bg_sea.SetRect(-215, 0);
		bg_sea.Render(renderer, NULL);

		bg_seed_bank.SetRect(10, 0);
		bg_seed_bank.Render(renderer, NULL);

		sun_value = std::to_string(cur_imformation.cur_sun);
		// Render văn bản
		SDL_Color textColor = { 0, 0, 0 }; // Màu đen
		SDL_Surface* sun_surface = TTF_RenderText_Blended(font, sun_value.c_str(), textColor);
		SDL_Texture* sun_text = SDL_CreateTextureFromSurface(renderer, sun_surface);
		SDL_Rect renderquad_3 = { 40,63,3 * sun_surface->w / 4,3 * sun_surface->h / 4 };
		SDL_FreeSurface(sun_surface); // Giải phóng surface sau khi tạo texture
		SDL_RenderCopy(renderer, sun_text, NULL, &renderquad_3);

		render_flag_pro();

		/*bg_seed_packet.SetRect(90, 10);
		bg_seed_packet.Render(renderer, NULL);*/
		////texture_reanim.Render(renderer, NULL, "sunflower", 100, 100);
		

		




		//test




		// Chuyển surface thành texture


		// Vẽ văn bản lên màn hình
		//SDL_RenderClear(renderer); // Xóa màn hình


		SDL_RenderCopy(renderer, textTexture, NULL, &renderquad_2);// Vẽ texture
		//SDL_RenderPresent(renderer); // Cập nhật màn hình

		//test



		remote_bullet(zombie_manager.list_zombie, all_game.list_of_bullet);


		//PLANT
		plant_manager.check_plant();
		zombie_manager.check_zombie();
		plant_manager.remote_frame_plant();

		plant_manager.remote_func_plant();
		remote_anim_(plant_manager.list_plant);
		//ZOMBIE

		zombie_manager.remote_frame_zombie();

		zombie_manager.remote_func_zombie();
		remote_anim_zombie(zombie_manager.list_zombie);
		//CARD
		set_order();
		render_card(renderer);

		for (int i = 0; i <= 5; i++) {
			if (card[i].CD > 0) {
				card[i].CD--;
			}
		}



		//




		/*Uint32 currentTime = SDL_GetTicks();

		frame += 2;
		if (frame / 31 >= 30) frame = 0;*/




		//tes
		//SDL_Rect* currentClip = &pea_shoot.get_clip()[frame / pea_shoot.num_frame];
		//SDL_Rect* currentClip2 = &pea_idle.get_clip()[frame / pea_idle.num_frame];

		//texture_reanim.Render(renderer, currentClip, "pea_shoot", -10, 40, 5 * currentClip->w / 8, 5 * currentClip->h / 8);
		//texture_reanim.Render(renderer, currentClip2, "peashooter", -10, 140, 5 * currentClip->w / 8, 5 * currentClip->h / 8);
		//texture_reanim.Render(renderer, currentClip2, "peashooter", -10, 240, 5 * currentClip->w / 8, 5 * currentClip->h / 8);
		//texture_reanim.Render(renderer, currentClip2, "peashooter", -10, 340, 5 * currentClip->w / 8, 5 * currentClip->h / 8);
		//texture_reanim.Render(renderer, currentClip2, "peashooter", -10, 440, 5 * currentClip->w / 8, 5 * currentClip->h / 8);
		////texture_reanim.Render(0, 0, &gSpriteClips[0]);
		//if (frame == 24) {
		//	all_game.call_bullet(renderer, 0, 80, 100);

		//}

		all_game.check_bullet(renderer);

		remote_bullet(zombie_manager.list_zombie, all_game.list_of_bullet);
		remote_instakill(zombie_manager.list_zombie, plant_manager.list_plant);
		remote_eat(zombie_manager.list_zombie, plant_manager.list_plant);
		remote_shoot(zombie_manager.list_zombie, plant_manager.list_plant);
		remote_anim_item(item_manager.list_item, mouseX, mouseY);
		item_manager.check_item();
		if (mouse_status == "hold_plant") {
			PLANT_HOLD = { 0 ,0, plant_wid.at(plant_m_hold), plant_hei.at(plant_m_hold) };
			if (plant_m_hold == "cherrybomb") {
				texture_reanim.Render(renderer, &PLANT_HOLD, "cherry_bomb", mouseX - 130, mouseY - 125, 5 * plant_wid.at(plant_m_hold) / 8, 5 * plant_hei.at(plant_m_hold) / 8);
			}
			else if (plant_m_hold == "oxygen_algae") {
				texture_reanim.Render(renderer, &PLANT_HOLD, "oxygen", mouseX - 40, mouseY - 90, plant_wid.at(plant_m_hold), plant_hei.at(plant_m_hold));
			}
			else if (plant_m_hold == "shiliu") {
				texture_reanim.Render(renderer, &PLANT_HOLD, "shiliu_idle", mouseX - 70, mouseY - 90, 5 * plant_wid.at(plant_m_hold) / 8, 5 * plant_hei.at(plant_m_hold) / 8);
			}
			else {
				texture_reanim.Render(renderer, &PLANT_HOLD, plant_m_hold, mouseX - 80, mouseY - 80, 5 * plant_wid.at(plant_m_hold) / 8, 5 * plant_hei.at(plant_m_hold) / 8);
			}


		}



		time_delay--;
		if (time_delay <= 0) {//bằng 0 thì nhay wave + set time delay mới
			wave++;
			if (wave <= 14) {
				time_delay = set_game.at(wave);
				zombie_manager.call_zombie("zombie", rand() % 5, rand() % 3 + 8, 0, 0, 89);
				zombie_manager.call_zombie("zombie", rand() % 5, rand() % 3 + 8, 0, 0, 89);
				zombie_manager.call_zombie("conezombie", rand() % 5, rand() % 3 + 8, 370, 0, 89);
				zombie_manager.call_zombie("zombie", rand() % 5, rand() % 3 + 8, 0, 0, 89);
				zombie_manager.call_zombie("conezombie", rand() % 5, rand() % 3 + 8, 370, 0, 89);
				zombie_manager.call_zombie("zombie", rand() % 5, rand() % 3 + 8, 0, 0, 89);
				zombie_manager.call_zombie("zombie", rand() % 5, rand() % 3 + 8, 0, 0, 89);
				zombie_manager.call_zombie("seafzombie", rand() % 5, rand() % 3 + 8, 0, 0, 59);
			}
			if (wave == 10 || wave == 13) {
				set_wave_time();
			}
			if (wave == 5) {
				//set_channel_on(ctx, 18, 19, 20, 21);
			}

		}
		if (wave >= 14 && count_zombie == 0) {
			if (wintime < 150) {
				wintime++;
			}
			star.SetRect(740, -45);
			star.Render(renderer, NULL);
			if (wintime == 1) {
				win_sound.Play_Sound();
				lightfill.Play_Sound();
				esdp.End_Music();
				//off_mainmusic(ctx);
			}
			if (wintime == 148) {
				status_manager.status = 2;
			}
			
		}


		if (wave == 10 || wave == 13) {
			if (time_delay < 75) {
				if (time_delay == 73) {
					huge_wave_sound.Play_Sound();
				}
				render_huge_wave();
			}

		}
		if (cur_imformation.flag_process <= 11 * wave && wave <=14) {
			++cur_imformation.delay_time;
			if (cur_imformation.delay_time > 4) {
				cur_imformation.flag_process++;
				cur_imformation.delay_time = 0;
				if (wave == 11) {
					cur_imformation.flag2y--;
				}
				if (wave == 14) {
					cur_imformation.flag1y--;
				}
				
			}
			
		}


	}
}













int main(int argc, char* args[])
{
	//test
	int temp = 0;

	//
	cyp.SetRect(0, 630);
	if ((ctx = xmp_create_context()) == NULL) {
		cout << "Không tạo được context" << endl;
		return -1;

	}
	sound_init(ctx, 44100, 2);
	xmp_load_module(ctx, "music/mainmusic.xm");
	TimeManager fps_time;

	if (TTF_Init() == -1) {
		std::cout << "TTF_Init Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		return -1;
	}
	if (InitData() == false) {
		cout << "Loi khoi tao" << endl;
		return -1;
	}
	if (LoadBG() == false) {
		cout << "Loi load background" << endl;
		return -1;
	}

	
	//test



	font = TTF_OpenFont("font/font_a.ttf", 24);
	if (font == NULL) {
		std::cout << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		TTF_Quit();
		SDL_Quit();
		return 1;
	}

	SDL_Color textColor = { 255, 131, 54 }; // Màu text

	// Render văn bản
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, "Test Stage", textColor);
	if (textSurface == NULL) {
		std::cout << "TTF_RenderText_Solid Error: " << TTF_GetError() << std::endl;
		TTF_CloseFont(font);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		TTF_Quit();
		SDL_Quit();
		return 1;
	}
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface); // Giải phóng surface sau khi tạo texture
	renderquad_2 = { 500,570,textSurface->w,textSurface->h };
	//test

	

	
	cout << &mouse_x_y.first << ":" << &mouse_x_y.second << endl;
	//Cấp phát trước
	plant_manager.list_plant.reserve(7265);
	zombie_manager.list_zombie.reserve(7265);
	all_game.list_of_bullet.reserve(7265);
	while (running) {
		count_zombie = zombie_manager.list_zombie.size();

		fps_time.start();
		if (is_load_texture == false) {
			is_load_texture = true;
			load_sound();
			load_texture_element();
			load_anim();
			set_wave_time();
			//gọi hàm load vào đây
		}
		//
		
	
		
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		//
		
		SDL_GetMouseState(&mouseX, &mouseY);
		mouse_x_y = get_location(mouseX, mouseY);
		SDL_RenderClear(renderer);
		CARD_LOCATE = get_pos_card(mouseX, mouseY);

		CARD_LOCATE_C = get_cardlocatec(mouseX, mouseY);
		
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
			
			if (status_manager.status == 4 && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
				if (mouse_status != "hold_plant" && CARD_LOCATE >= 0 && CARD_LOCATE <= 9 && card[CARD_LOCATE].CD<=1 &&cur_imformation.cur_sun>=sun_value_p.at(plant_num_list.at(card[CARD_LOCATE].type))) {
					mouse_status = "hold_plant";//chuột cầm plant
					plant_m_hold = plant_num_list.at(card[CARD_LOCATE].type);
					temp = CARD_LOCATE;
				}
				if (mouse_status == "hold_plant") {
					if (mouse_x_y.first >= 0 && mouse_x_y.first <= 4 && mouse_x_y.second >= 0 && mouse_x_y.second <= 8) {
						cout << &mouse_status << endl;
						cout << mouse_x_y.first << " " << mouse_x_y.second << endl;
						planted.Play_Sound();
						cur_imformation.cur_sun -= sun_value_p.at(plant_num_list.at(card[temp].type));
						card[temp].CD = sun_value_cd.at(plant_m_hold);
						plant_manager.call_plant(plant_m_hold, mouse_x_y.first, mouse_x_y.second, plant_frame_list.at(plant_m_hold));
						mouse_status = "";//không cầm
						if (plant_m_hold == "cherrybomb") {
							reverse_explos.Play_Sound();
						}
					}

				}
				cout << mouseX << " " << mouseY << endl;
				//plant_manager.call_plant("peashooter", mouse_x_y.first, mouse_x_y.second, 31);//have test
				//plant_manager.call_plant("snowpea", mouse_x_y.first, mouse_x_y.second, 30);//have test
				//plant_manager.call_plant("sunflower", mouse_x_y.first, mouse_x_y.second, 59);//have test
				//plant_manager.call_plant("explosion", mouse_x_y.first, mouse_x_y.second, 21);//have test
				//plant_manager.call_plant("zom_fire", mouse_x_y.first, mouse_x_y.second, 44);//have test
				//plant_manager.call_plant("cherrybomb", mouse_x_y.first, mouse_x_y.second, 21);//have test
				//all_game.call_bullet(renderer, 0, mouseX, mouseY);

				//plant_manager.call_plant("oxygen_algae", mouse_x_y.first, mouse_x_y.second, 60);
				std::cout << "LEFT" << std::endl;
			
			}
			else if (status_manager.status == 4 && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_RIGHT) {
				cout << mouseX << " " << mouseY << endl;
				//plant_manager.call_plant("peashooter", u, v, 31);//have test
				//plant_manager.call_plant("snowpea", 0, 1, 30);//have test
				//plant_manager.call_plant("sunflower", 0, 2, 59);//have test
				//plant_manager.call_plant("explosion", 6, 0, 21);//have test
				//plant_manager.call_plant("zom_fire", 7, 4, 44);//have test
				//plant_manager.call_plant("cherrybomb", 1, 2, 21);//have test
				//all_game.call_bullet(renderer, 0, mouseX, mouseY);
				//zombie_manager.call_zombie("zomboni", 0, 9, 0, 0, 12);
				zombie_manager.call_zombie("seafzombie", 0, 9, 0, 0, 59);
				zombie_manager.call_zombie("exzombie", 3, 9, 0, 0, 60);
				//zomboni_sound.Play_Sound();
				//plant_manager.call_plant("banana_tree", 2, 2, 191);

				mouse_status = "";

				std::cout << "RIGHT" << std::endl;

			}

		}




		
		//Render top right sprite
		///texture_reanim.Render(SCREEN_WID - gSpriteClips[1].w, 0, &gSpriteClips[1]);

		//Render bottom left sprite
		///texture_reanim.Render(0, SCREEN_HEI - gSpriteClips[2].h, &gSpriteClips[2]);

		//Render bottom right sprite
		//texture_reanim.Render(SCREEN_WID- gSpriteClips[3].w, SCREEN_HEI - gSpriteClips[3].h, &gSpriteClips[3]);

		
		
		

		status_process();

		
		
	
		
	
		SDL_RenderPresent(renderer);
		int real_time = fps_time.get_time();
		int time_of = 1000 / FPS;
		if (real_time < time_of) {
			int delay_time = time_of - real_time;
			SDL_Delay(delay_time);
	
		
		}
		
		
	}

	xmp_release_module(ctx);
	xmp_free_context(ctx);

	SDL_CloseAudio();
	close();

	return 0;

}