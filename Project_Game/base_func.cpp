#include "base_func.h"


PlantCard card[7];
PlantCard card_[10];
SDL_Renderer* renderer;

Cur_imf::Cur_imf() {
	cur_sun = 2700;//test thôi
	delay_time = 0;
	cur_sence = 0;
	flag_process = 0;
	flag1x = 615;
	flag1y = 567;
	flag2x = 645;
	flag2y = 567;


}
Cur_imf::~Cur_imf() {



}

void Cur_imf::reset_flag_process() {
	flag_process = 0;
}