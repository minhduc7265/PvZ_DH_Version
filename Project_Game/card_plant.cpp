#include "card_plant.h"


PlantCard::PlantCard() {
	CD = 0;
	type = 0;
	card_x = 0;
	card_y = 0;
	status = 0;//0 là hồi xong//1 là bị bấm vào, nếu trồng chuyển sang 2 là count down
	status_c = 0;//0 là ở bảng// 1 là lên bảng
	is_allow = true;
	card_order = 0;
	card_xc = 0;
	card_yc = 0;
	card_xce = 0;
	card_yce = 0;

}
PlantCard::~PlantCard() {



}
