#include "lawn.h"


Lawn::Lawn() {
	x_first = 0;
	x_second = 0;
	y_first = 0;
	y_second = 0;
	is_planted = false;
	ptr_plant = NULL;
}
bool Lawn::getIsPlanted() const {
	return is_planted;
}
void Lawn::setIsPlanted(bool plant) {
	is_planted = plant;
}

void Lawn::setPtrPlant(Plant* plant) {
	ptr_plant = plant;
}
Plant* Lawn::getPtrPlant() const {
	return ptr_plant;
}