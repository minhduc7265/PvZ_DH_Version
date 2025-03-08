#pragma once
#ifndef CARD_PLANT_H_
#define CARD_PLANT_H_
class PlantCard {


public:
	PlantCard();
	~PlantCard();
	void set_CD() {
		if (status == 3) {
			CD = 4000;
		}
	}
	bool get_is_allow()const {
		return is_allow;
	}
	int get_type() const {
		return type;
	}
	int get_x() const {
		return card_x;
	}
	int get_y() const {
		return card_y;
	}
	int CD;
	int card_order;
	int type;
	int card_x;
	int card_y;
	int card_xc;
	int card_yc;
	int card_xce;
	int card_yce;
	int status;//0 là hồi xong//1 là bị bấm vào//2 là hủy k trồng, nếu trồng chuyển sang 3 là count down
	int status_c;//0 là ở bảng// 1 là lên bảng
	bool is_allow;

protected:
	









};



#endif // !CARD_PLANT_H
