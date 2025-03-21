#include <iostream>
#include "main_func.h"
#include <string.h>
#include <cstdlib>


std::map<int, int> maxWave = {
	{1,14},
	{2,10},
	{3,17},
	{4,27},
	{5,5}
};
std::map<int, int> flagConst = {
	{1,11},
	{2,15},
	{3,9},
	{4,5},
	{5,31}
};
std::map<int, std::pair<int, int>>  midFlag{
	{1,{-1,11}},
	{2,{-1,-1}},
	{3,{-1,2}},
	{4,{11,13}},
	{5,{-1,-1}}

};


Texture texture_game;



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








static int time_huge = 0;












void set_wave_time() {
	time_huge = 0;
	huge_wave.SetRect(-180, -180);
	huge_wave.rect_.w = 1200;
	huge_wave.rect_.h = 900;
}


void render_huge_wave() {//5 loại cờ
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

void remoteFlagTD() {
	cur_imformation.time_delay--;
	if (cur_imformation.time_delay <= 0) {//bằng 0 thì nhay wave + set time delay mới
		cur_imformation.wave++;

		if (cur_imformation.wave <= maxWave.at(getWave(cur_imformation.cur_td_adventure))) {//nếu set delay thì gọi thêm nếu mà <= max
			cur_imformation.time_delay = getDelayTime(cur_imformation.cur_td_adventure, cur_imformation.wave);
			spwanZombie(cur_imformation.cur_td_adventure, cur_imformation.wave);
		}

		if (cur_imformation.wave == 1 ||
			cur_imformation.wave == 10 ||
			cur_imformation.wave == 12 ||
			cur_imformation.wave == maxWave.at(getWave(cur_imformation.cur_td_adventure)) - 1) {
			set_wave_time();
		}

	}
	//Khi win
	if (cur_imformation.wave >= maxWave.at(getWave(cur_imformation.cur_td_adventure)) && count_zombie == 0)
	{
		if (cur_imformation.wintime < 150) {
			cur_imformation.wintime++;
		}
		star.SetRect(740, -45);
		star.Render(renderer, NULL);
		if (cur_imformation.wintime == 1) {
			win_sound.Play_Sound(30);
			lightfill.Play_Sound(29);
			esdp.End_Music();
			//off_mainmusic(ctx);
		}
		if (cur_imformation.wintime == 148) {
			status_manager.status = 2;
		}

	}
	//chạy cờ
	if (cur_imformation.flag_process <= flagConst.at(getWave(cur_imformation.cur_td_adventure)) * cur_imformation.wave &&
		cur_imformation.wave <= maxWave.at(getWave(cur_imformation.cur_td_adventure)))//nếu hiện tại nhỏ hơn max
	{
		++cur_imformation.delay_time;
		if (cur_imformation.delay_time > 4) {
			cur_imformation.flag_process++;
			cur_imformation.delay_time = 0;

			if (cur_imformation.wave == midFlag.at(getWave(cur_imformation.cur_td_adventure)).second) {
				cur_imformation.flag2y--;
			}
			else if (cur_imformation.wave == midFlag.at(getWave(cur_imformation.cur_td_adventure)).first) {
				cur_imformation.flag3y--;
			}
			else if (cur_imformation.wave == maxWave.at(getWave(cur_imformation.cur_td_adventure))) {
				cur_imformation.flag1y--;
			}

		}

	}
	
}
void remoteFlagMG() {
	cur_imformation.time_delay--;
	if (cur_imformation.time_delay <= 0) {//bằng 0 thì nhay wave + set time delay mới
		cur_imformation.wave++;

		if (cur_imformation.wave <= maxWave.at(getWave(cur_imformation.cur_mini_game))) {//nếu set delay thì gọi thêm nếu mà <= max
			cur_imformation.time_delay = getDelayTime(cur_imformation.cur_mini_game, cur_imformation.wave);
			spwanZombie(cur_imformation.cur_mini_game, cur_imformation.wave);
		}

		if (cur_imformation.wave == 1 ||
			cur_imformation.wave == 10 ||
			cur_imformation.wave == 12 ||
			cur_imformation.wave == maxWave.at(getWave(cur_imformation.cur_mini_game)) - 1) {
			set_wave_time();
		}

	}
	//Khi win
	if (cur_imformation.wave >= maxWave.at(getWave(cur_imformation.cur_mini_game)) && count_zombie == 0)
	{
		if (cur_imformation.wintime < 150) {
			cur_imformation.wintime++;
		}
		star.SetRect(740, -45);
		star.Render(renderer, NULL);
		if (cur_imformation.wintime == 1) {
			win_sound.Play_Sound(30);
			lightfill.Play_Sound(29);
			esdp.End_Music();
			//off_mainmusic(ctx);
		}
		if (cur_imformation.wintime == 148) {
			status_manager.status = 2;
		}

	}
	if (cur_imformation.wave == 6) {
		/*__asm {
			push 0x1B
			push 0x1A
			push 0x19
			push 0x18
			mov eax, [ctx]
			push eax
			call set_channel_on
			add esp, 0x14//5x4=0x14
		}*/
		set_channel_on(ctx, 24, 25, 26, 27);
	}
	if (cur_imformation.wave >= maxWave.at(getWave(cur_imformation.cur_mini_game)) && count_zombie < 3) {
		set_channel_off(ctx, 24, 25, 26, 27);
	}
	//chạy cờ
	if (cur_imformation.flag_process <= flagConst.at(getWave(cur_imformation.cur_mini_game)) * cur_imformation.wave &&
		cur_imformation.wave <= maxWave.at(getWave(cur_imformation.cur_mini_game)))//nếu hiện tại nhỏ hơn max
	{
		++cur_imformation.delay_time;
		if (cur_imformation.delay_time > 4) {
			cur_imformation.flag_process++;
			cur_imformation.delay_time = 0;

			if (cur_imformation.wave == midFlag.at(getWave(cur_imformation.cur_mini_game)).second) {
				cur_imformation.flag2y--;
			}
			else if (cur_imformation.wave == midFlag.at(getWave(cur_imformation.cur_mini_game)).first) {
				cur_imformation.flag3y--;
			}
			else if (cur_imformation.wave == maxWave.at(getWave(cur_imformation.cur_mini_game))) {
				cur_imformation.flag1y--;
			}

		}

	}

}

void button_in_game() {
	//RENDER LIÊN TỤC
	pause1.SetRect(700, 0);
	pause1.Render(renderer, NULL);
	reset1.SetRect(735, 0);
	reset1.Render(renderer, NULL);
	outlevel.SetRect(770, 0);
	outlevel.Render(renderer, NULL);
	//XỬ LÍ CHUỘT
	if (mouseX >= 700 && mouseX <= 734 && mouseY >= 0 && mouseY <= 33) {
		pause2.SetRect(700, 0);
		pause2.Render(renderer, NULL);
		if (cur_imformation.mouseButton == "LEFT") {
			if (timeGame.is_paused() == false) {
				timeGame.pause();
				esdp.Pause();
				std::cout << std::endl;
				std::cout << std::endl;
				std::cout << "PAUSE" << std::endl;
				std::cout << std::endl;
				std::cout << std::endl;
			}
			else {
				timeGame.resume();
				esdp.Resume();
				std::cout << std::endl;
				std::cout << std::endl;
				std::cout << "RESUME" << std::endl;
				std::cout << std::endl;
				std::cout << std::endl;
			}
			click.Play_Sound(28);
		}
	}
	else if (mouseX >= 735 && mouseX <= 769 && mouseY >= 0 && mouseY <= 33) {
		reset2.SetRect(735, 0);
		reset2.Render(renderer, NULL);
		if (cur_imformation.mouseButton == "LEFT") {
			status_manager.status = 3;
			esdp.End_Music();
			click.Play_Sound(28);
		}
	}
	else if (mouseX >= 770 && mouseX <= 800 && mouseY >= 0 && mouseY <= 30) {
		outlevel2.SetRect(770, 0);
		outlevel2.Render(renderer, NULL);
		if (cur_imformation.mouseButton == "LEFT") {
			status_manager.status = 2;
			esdp.End_Music();
			click.Play_Sound(28);
		}
	}

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


	Mix_AllocateChannels(32);//Set 32 kênh

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	window = SDL_CreateWindow(WINDOW_NAME_N.c_str(), SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, 
		SCREEN_WID, 
		SCREEN_HEI,
		SDL_WINDOW_SHOWN);
	if (window == NULL) {
		success = false;
	}
	else {
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);//thêm flag ở cuối
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

void call_flag_paint() {
	pro_flag.SetRect(cur_imformation.flag1x, cur_imformation.flag1y);
	pro_flag.Render(renderer, NULL);
	pro_flag.SetRect(cur_imformation.flag2x, cur_imformation.flag2y);
	pro_flag.Render(renderer, NULL);
	pro_flag.SetRect(cur_imformation.flag3x, cur_imformation.flag3y);
	pro_flag.Render(renderer, NULL);
}


void render_flag_pro() {
	SDL_Rect rect = { 610,570,cur_imformation.flag_process,27 };
	SDL_Rect rect_2 = { 0,0,158,27 };
	SDL_Point center = { 79, 13 };
	pro_green.Render_2(renderer, &rect, &rect_2, &center, 180.0);
	pro_non.SetRect(610, 570);
	pro_non.Render(renderer, NULL);

	if (cur_imformation.type_flag == 1) {//2 flag
		cur_imformation.flag1x = 615;
		cur_imformation.flag2x = 645;
		cur_imformation.flag3x = -100;
		cur_imformation.flag3y = -100;
		call_flag_paint();
		
	}
	else if (cur_imformation.type_flag == 2) {//1 flag
		cur_imformation.flag1x = 615;
		cur_imformation.flag2x = -100;
		cur_imformation.flag2y = -100;
		cur_imformation.flag3x = -100;
		cur_imformation.flag3y = -100;
		call_flag_paint();
	}
	else if (cur_imformation.type_flag == 3) {//2 flag 2
		cur_imformation.flag1x = 615;
		cur_imformation.flag2x = 730;
		cur_imformation.flag3x = -100;
		cur_imformation.flag3y = -100;
		call_flag_paint();
	}
	else if (cur_imformation.type_flag == 4) {//3 flag
		cur_imformation.flag1x = 615;
		cur_imformation.flag2x = 685;
		cur_imformation.flag3x = 700;
		call_flag_paint();

	}
	else if (cur_imformation.type_flag == 5) {//0 flag
		cur_imformation.flag1x = -100;
		cur_imformation.flag1y = -100;
		cur_imformation.flag2x = -100;
		cur_imformation.flag2y = -100;
		cur_imformation.flag3x = -100;
		cur_imformation.flag3y = -100;
		call_flag_paint();

	}
	
	
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
		reset_level(0);
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
				click.Play_Sound(28);
			}
		}
		else {
			but1.SetRect(470, 310);
			but1.Render(renderer, NULL);
			
		}

	}
	else if (status_manager.status == 1) {
		
		reset_level(0);
		if (is_music != 1) {
			mg_background.End_Music();
			play_mainmusic(ctx, 152);
			is_music = 1;
		}

		bgnormal.SetRect(0, 0);
		bgnormal.Render(renderer, NULL);
		cur_imformation.set_mg_image();
		texture_reanim.Render(renderer, &miniGame.get_clip()[cur_imformation.frame_mg_image], "minigame", 10, 370, 234, 254);
		adventure1.SetRect(570, 430);
		adventure1.Render(renderer, NULL);
		if (mouseX >= 570 && mouseX <= 750 && mouseY >= 430 && mouseY <= 590) {
			adventure2.SetRect(570, 430);
			adventure2.Render(renderer, NULL);
			if (SDL_WaitEvent(&event) && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
				status_manager.status = 2;
				status_manager.mg_status = 0;//0-4 là map TD mà chắc quái gì làm hết
				click.Play_Sound(28);
			}
		}
		else if (mouseX >= 10 && mouseX <= 244 && mouseY >= 370 && mouseY <= 600) {
			if (SDL_WaitEvent(&event) && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
				status_manager.status = 2;
				status_manager.mg_status = 5;//Mini-game
				click.Play_Sound(28);
			}
			
		}

	}
	else if (status_manager.status == 2) {
		reset_level(0);

		if (is_music != 2) {
			if (status_manager.mg_status <= 4) {
				play_mainmusic(ctx, 122);
			}
			else {
				off_mainmusic(ctx);
				mg_background.Play_Music("music/cyp2.mp3");
			}
			is_music = 2;
			
		}

		if (status_manager.mg_status <= 4) {
			challengebg.SetRect(0, 0);
			challengebg.Render(renderer, NULL);
			for (int i = 0; i < 5; i++) {
				if (mouseX >= i * 155 + 30 && mouseX <= i * 155 + 30 + 120 && mouseY >= 100 && mouseY <= 215) {
					texture_reanim.Render(renderer, &level2.get_clip()[i], "level", i * 155 + 30, 100, 118, 120);

					if (SDL_WaitEvent(&event) && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
						status_manager.status = 3;
						cur_imformation.cur_mini_game = 0;
						cur_imformation.cur_td_adventure = i + 1;
						click.Play_Sound(28);
					}
				}
				texture_reanim.Render(renderer, &level.get_clip()[i], "level", i * 155 + 30, 100, 118, 120);
			}
		}
		else{
			challengemg.SetRect(0, 0);
			challengemg.Render(renderer, NULL);
			for (int i = 0; i < 5; i++) {
				if (mouseX >= i * 155 + 30 && mouseX <= i * 155 + 30 + 120 && mouseY >= 100 && mouseY <= 215) {
					texture_reanim.Render(renderer, &minigame2.get_clip()[i], "minigame2", i * 155 + 30, 100, 118, 120);

					if (SDL_WaitEvent(&event) && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
						status_manager.status = 3;
						cur_imformation.cur_mini_game = i + 1;
						cur_imformation.cur_td_adventure = 0;
						click.Play_Sound(28);
					}
				}
				texture_reanim.Render(renderer, &minigame1.get_clip()[i], "minigame1", i * 155 + 30, 100, 118, 120);
			}
		}


		//CHUNG
		if (mouseX >= 10 && mouseX <= 100 && mouseY >= 575 && mouseY <= 590) {
			back2.SetRect(10, 575);
			back2.Render(renderer, NULL);

			if (SDL_WaitEvent(&event) && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
				status_manager.status = 1;
				click.Play_Sound(28);
			}
		}
		else {
			back1.SetRect(10, 575);
			back1.Render(renderer, NULL);
		}


	}
	else if (status_manager.status == 3) {
		reset_level(1);//cả load luôn
		if (is_music != 3) {
			off_mainmusic(ctx);
			mg_background.End_Music();
			if (cur_imformation.cur_td_adventure != 0) {
				esdp_c.Play_Music("music/ESDP-S.mp3");
			}
			else {
				mg_background.Play_Music("music/cyp2.mp3");
			}
			/*play_mainmusic(ctx, 122);*/
			is_music = 3;
		}
		if (cur_imformation.cur_td_adventure != 0) {
			bg_sea.SetRect(pos_bg, 0);
			bg_sea.Render(renderer, NULL);
		}
		else {
			bg_background.SetRect(pos_bg, 0);
			bg_background.Render(renderer, NULL);
		}
		
		//status_manager.status = 4;
		if (pos_bg > -550) {
			pos_bg -= 18;
		}
		if (pos_bg < -550) {
			cyp.rect_.y = (cyp.rect_.y >= 90) ? cyp.rect_.y -70: 70;
			cyp.Render(renderer, NULL);
			cyp_remote();
			play_but1.SetRect(150, 530);
			play_but1.Render(renderer, NULL);

		}
		if (mouseX >= 150 && mouseX <= 300 && mouseY >= 530 && mouseY <= 572) {
			play_but2.SetRect(150, 530);
			play_but2.Render(renderer, NULL);
			if (SDL_WaitEvent(&event) && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
				status_manager.status = 4;
				click.Play_Sound(28);
			}
		}


	}
	else if (status_manager.status == 4) {
		if (pos_bg < -215) {
			pos_bg += 18;
		}
		else {
			status_manager.status = 5;
			//ready->set->plant;
		}
		if (cur_imformation.cur_td_adventure != 0) {
			bg_sea.SetRect(pos_bg, 0);
			bg_sea.Render(renderer, NULL);
		}
		else {
			bg_background.SetRect(pos_bg, 0);
			bg_background.Render(renderer, NULL);
			
		}
	}

	else if (status_manager.status == 5) {
		if (is_music != 4) {
			off_mainmusic(ctx);
			esdp_c.End_Music();
			if (cur_imformation.cur_td_adventure != 0) {
				esdp.Play_Music("music/ESDP.mp3");
			}
			else {
				if (cur_imformation.cur_mini_game == 1) {
					play_mainmusic(ctx, 212);
				}
				else {
					play_mainmusic(ctx, 0);
					set_channel_off(ctx, 24, 25, 26, 27);
				}
				

			}
			
			is_music = 4;
		}
		if (cur_imformation.cur_td_adventure != 0) {
			bg_sea.SetRect(-215, 0);
			bg_sea.Render(renderer, NULL);
		}
		else {
			bg_background.SetRect(-215, 0);
			bg_background.Render(renderer, NULL);
			if (cur_imformation.cur_mini_game == 1) {
				cur_imformation.tiankongX -= 8;
				tiankong.SetRect(cur_imformation.tiankongX, 0);
				tiankong.Render(renderer, NULL);
				tiankong.SetRect(800+ cur_imformation.tiankongX, 0);
				tiankong.Render(renderer, NULL);
				if (cur_imformation.tiankongX <= -800) {
					cur_imformation.tiankongX = 0;
				}
			}
			else if (cur_imformation.cur_mini_game == 3) {//Xong viết lại chứ hơi kì kì
				background3.SetRect(-215, 0);
				background3.RenderColor(renderer, NULL, 255);
				cur_imformation.count_time++;
				if (cur_imformation.count_time > 400) {
					if (cur_imformation.color > 80 && cur_imformation.count_time < 1200) {
						background3.SetRect(-215, 0);
						background3.RenderColor(renderer, NULL, cur_imformation.color--);
					}
					else {
						background2.SetRect(-215, 0);
						background2.RenderColor(renderer, NULL, cur_imformation.color);
						if (cur_imformation.count_time > 1200) {
							if (cur_imformation.color < 255) {
								background3.SetRect(-215, 0);
								background3.RenderColor(renderer, NULL, cur_imformation.color++);
							}
							else {
								cur_imformation.count_time = 0;
							}
						}
					}
					
				}
			}
		}
		bg_seed_bank.SetRect(10, 0);
		bg_seed_bank.Render(renderer, NULL);

		sun_value = std::to_string(cur_imformation.cur_sun);
		SDL_Color textColor = { 0, 0, 0 };
		SDL_Surface* sun_surface = TTF_RenderText_Blended(font, sun_value.c_str(), textColor);
		SDL_Texture* sun_text = SDL_CreateTextureFromSurface(renderer, sun_surface);
		SDL_Rect renderquad_3 = { 40,63,3 * sun_surface->w / 4,3 * sun_surface->h / 4 };
		SDL_FreeSurface(sun_surface);
		SDL_RenderCopy(renderer, sun_text, NULL, &renderquad_3);

		SDL_RenderCopy(renderer, textTexture, NULL, &renderquad_2);


		set_order();
		render_card(renderer);

		

		button_in_game();
		if (timeGame.is_paused() == false) {
			
			if (cur_imformation.cur_td_adventure != 0) {
				cur_imformation.type_flag = getWave(cur_imformation.cur_td_adventure);
				remoteFlagTD();
			}
			else {
				cur_imformation.type_flag = getWave(cur_imformation.cur_mini_game);
				remoteFlagMG();
			}
			if (cur_imformation.cur_mini_game == 1) {
				cur_imformation.count_time++;
				if (cur_imformation.count_time > 4) {
					all_game.call_bullet(renderer, 1, mouseX, mouseY, mouse_x_y.first, mouse_x_y.second,15);
					cur_imformation.count_time = 0;
				}
				
			}
			for (int i = 0; i <= 5; i++) {
				if (card[i].CD > 0) {
					card[i].CD--;
				}
			}
			remote_bullet(zombie_manager.list_zombie, all_game.list_of_bullet);
			plant_manager.check_plant();
			zombie_manager.check_zombie();
			item_manager.check_item();

			plant_manager.remote_frame_plant();
			plant_manager.remote_func_plant();
			zombie_manager.remote_frame_zombie();
			zombie_manager.remote_func_zombie();
			all_game.check_bullet(renderer);


			remote_bullet(zombie_manager.list_zombie, all_game.list_of_bullet);
			remote_instakill(zombie_manager.list_zombie, plant_manager.list_plant);
			remote_eat(zombie_manager.list_zombie, plant_manager.list_plant);
			remote_shoot(zombie_manager.list_zombie, plant_manager.list_plant);
			remote_anim_item(item_manager.list_item, mouseX, mouseY);


		}


		if (cur_imformation.cur_td_adventure != 0) {
			if (cur_imformation.wave == midFlag.at(getWave(cur_imformation.cur_td_adventure)).first - 1 ||
				cur_imformation.wave == midFlag.at(getWave(cur_imformation.cur_td_adventure)).second - 1 ||
				cur_imformation.wave == maxWave.at(getWave(cur_imformation.cur_td_adventure)) - 1)
			{
				if (cur_imformation.time_delay < 75) {
					if (cur_imformation.time_delay == 73) {
						huge_wave_sound.Play_Sound(27);
					}
					render_huge_wave();
				}

			}

		}
		else {
			if (cur_imformation.wave == midFlag.at(getWave(cur_imformation.cur_mini_game)).first - 1 ||
				cur_imformation.wave == midFlag.at(getWave(cur_imformation.cur_mini_game)).second - 1 ||
				cur_imformation.wave == maxWave.at(getWave(cur_imformation.cur_mini_game)) - 1)
			{
				if (cur_imformation.time_delay < 75) {
					if (cur_imformation.time_delay == 73) {
						huge_wave_sound.Play_Sound(27);
					}
					render_huge_wave();
				}

			}
		}
		



		render_flag_pro();
		all_game.remote_func_bullet(renderer);
		remote_anim_(plant_manager.list_plant);
		remote_anim_zombie(zombie_manager.list_zombie);

		
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
			else if (plant_m_hold == "sunflower") {
				texture_reanim.Render(renderer, &PLANT_HOLD, plant_m_hold, mouseX - 50, mouseY - 80, 5 * plant_wid.at(plant_m_hold) / 8, 5 * plant_hei.at(plant_m_hold) / 8);
			}
			else if (plant_m_hold == "snowpea") {
				texture_reanim.Render(renderer, &PLANT_HOLD, plant_m_hold, mouseX - 50 + 5, mouseY - 80, 5 * plant_wid.at(plant_m_hold) / 8, 5 * plant_hei.at(plant_m_hold) / 8);
			}
			else if (plant_m_hold == "potato_mine") {
				texture_reanim.Render(renderer, &PLANT_HOLD, "potatoidle", mouseX - 50, mouseY - 60, 5 * plant_wid.at(plant_m_hold) / 8, 5 * plant_hei.at(plant_m_hold) / 8);
			}
			else {
				texture_reanim.Render(renderer, &PLANT_HOLD, plant_m_hold, mouseX - 80, mouseY - 80, 5 * plant_wid.at(plant_m_hold) / 8, 5 * plant_hei.at(plant_m_hold) / 8);
			}


		}




	}
}













int main(int argc, char* args[])
{
	game_lawn.Lawn_Set();
	timeGame.start();
	//test
	int temp = 0;

	//
	loadFileLevel();
	loadFileMiniGame();
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

	SDL_Color textColor = { 255, 131, 54 };

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
	SDL_FreeSurface(textSurface);
	renderquad_2 = { 500,570,textSurface->w,textSurface->h };
	cout << &mouse_x_y.first << ":" << &mouse_x_y.second << endl;
	//Init Vector 
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

		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_GetMouseState(&mouseX, &mouseY);
		mouse_x_y = get_location(mouseX, mouseY);
		SDL_RenderClear(renderer);
		CARD_LOCATE = get_pos_card(mouseX, mouseY);
		CARD_LOCATE_C = get_cardlocatec(mouseX, mouseY);
		cur_imformation.mouseButton = "";
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
			
			if (status_manager.status == 5 && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
				cur_imformation.mouseButton = "LEFT";
				if (mouse_status != "hold_plant" && CARD_LOCATE >= 0 && CARD_LOCATE <= 5 && card[CARD_LOCATE].CD<=1 &&cur_imformation.cur_sun>=sun_value_p.at(plant_num_list.at(card[CARD_LOCATE].type))) {
					mouse_status = "hold_plant";
					plant_m_hold = plant_num_list.at(card[CARD_LOCATE].type);
					temp = CARD_LOCATE;
				}
				if (mouse_status == "hold_plant") {
					if (mouse_x_y.first >= 0 && mouse_x_y.first <= 4 && mouse_x_y.second >= 0 && mouse_x_y.second <= 8) {
						if (game_lawn.Array_Manager[mouse_x_y.first][mouse_x_y.second].getIsPlanted() == false) {
							cout << &mouse_status << endl;
							cout << mouse_x_y.first << " " << mouse_x_y.second << endl;
							planted.Play_Sound(26);
							cur_imformation.cur_sun -= sun_value_p.at(plant_num_list.at(card[temp].type));
							card[temp].CD = sun_value_cd.at(plant_m_hold);
							Plant * newplant = plant_manager.call_plant(plant_m_hold, mouse_x_y.first, mouse_x_y.second, plant_frame_list.at(plant_m_hold));
							mouse_status = "";
							if (plant_m_hold == "cherrybomb") {
								reverse_explos.Play_Sound(25);
							}
							game_lawn.Array_Manager[mouse_x_y.first][mouse_x_y.second].setIsPlanted(true);//Đã trồng
							game_lawn.Array_Manager[mouse_x_y.first][mouse_x_y.second].setPtrPlant(newplant);//Nhét dữ liệu plant vào
						}
						else if (plant_m_hold == "sunflower" && game_lawn.Array_Manager[mouse_x_y.first][mouse_x_y.second].getIsPlanted() == true && game_lawn.Array_Manager[mouse_x_y.first][mouse_x_y.second].getPtrPlant()->name_plant == "sunflower") {
							game_lawn.Array_Manager[mouse_x_y.first][mouse_x_y.second].getPtrPlant()->name_plant = "twinsun";
							planted.Play_Sound(24);
							cur_imformation.cur_sun -= sun_value_p.at(plant_num_list.at(card[temp].type));
							card[temp].CD = sun_value_cd.at(plant_m_hold);
							mouse_status = "";

						}
						else if (plant_m_hold == "peashooter" && game_lawn.Array_Manager[mouse_x_y.first][mouse_x_y.second].getIsPlanted() == true && game_lawn.Array_Manager[mouse_x_y.first][mouse_x_y.second].getPtrPlant()->name_plant == "peashooter") {
							game_lawn.Array_Manager[mouse_x_y.first][mouse_x_y.second].getPtrPlant()->name_plant = "repeater";
							planted.Play_Sound(24);
							cur_imformation.cur_sun -= sun_value_p.at(plant_num_list.at(card[temp].type));
							card[temp].CD = sun_value_cd.at(plant_m_hold);
							mouse_status = "";

						}
					}

				}
				cout << mouseX << " " << mouseY << endl;
				std::cout << "LEFT" << std::endl;
			
			}
			else if (status_manager.status == 5 && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_RIGHT) {
				cur_imformation.mouseButton = "RIGHT";
				cout << mouseX << " " << mouseY << endl;
				mouse_status = "";
				std::cout << "RIGHT" << std::endl;

			}

		}
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