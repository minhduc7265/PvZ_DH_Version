#include "base_func.h"


PlantCard card[7];
PlantCard card_[10];
SDL_Renderer* renderer;

Cur_imf::Cur_imf() {
	cur_sun = 2700;//test thôi
	delay_time = 0;
	cur_sence = 0;
	flag_process = 0;
	flag1x = 0;
	flag1y = 0;
	flag2x = 0;
	flag2y = 0;
	flag3x = 0;
	flag3y = 0;
	wintime = 0;
	time_delay = 600;
	wave = 0;
	mouseButton = "";
	frame_mg_image = 0;
	cur_mini_game = 0;
	cur_td_adventure = 0;
	type_flag = 0;
}
Cur_imf::~Cur_imf() {



}

void Cur_imf::reset_process() {
	cur_sun = 2700;//test thôi
	delay_time = 0;
	cur_sence = 0;
	flag_process = 0;
	flag1x = 0;
	flag1y = 567;
	flag2x = 0;
	flag2y = 567;
	flag3x = 0;
	flag3y = 567;
	wintime = 0;
	time_delay = 600;
	wave = 0;
	mouseButton = "";
	cur_mini_game = 0;
	cur_td_adventure = 0;
	type_flag = 0;
	

}
void Cur_imf::set_mg_image() {
	frame_mg_image++;
	if (frame_mg_image >= 59) {
		frame_mg_image = 0;
	}
}