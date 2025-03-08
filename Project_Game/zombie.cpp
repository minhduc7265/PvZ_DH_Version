#include "zombie.h"



Zombie::Zombie() {
	name_zombie = "";
	zom_blood = 0;
	armor_type_1 = 0;//bucket;
	armor_typr_2 = 0;//door;
	is_dead = false;
	name_zombie = "";
	is_eat = false;
	status = "idle";
	currentClip = NULL;
	num_row = 0;
	num_col = 0;
	pos_x = 0;
	pos_y = 0;
	num_frame = 0;
	cur_frame = 0;
	count_down = 0;
	slow_time = 0;
}

Zombie::~Zombie() {

	name_zombie = "";
	zom_blood = 0;
	armor_type_1 = 0;//bucket;
	armor_typr_2 = 0;//door;
	is_dead = true;
	name_zombie = "";
	is_eat = false;
	status = "";
	currentClip = NULL;
	num_row = 0;
	num_col = 0;
	pos_x = 0;
	pos_y = 0;
	num_frame = 0;
	cur_frame = 0;
	count_down = 0;
	slow_time = 0;





}