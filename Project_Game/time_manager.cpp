#include "time_manager.h"
#include "base_func.h"
TimeManager::TimeManager() {
	start_time = 0;
	pause_time = 0;
	is_pause = false;
	is_start = false;
}


TimeManager::~TimeManager() {

}
void TimeManager::start() {
	is_start = true;
	is_pause = false;
	start_time = SDL_GetTicks();
}

void TimeManager::stop() {
	is_pause = false;
	is_start = false;

}

void TimeManager::pause() {
	if (is_start == true && is_pause == false) {
		is_pause = true;
		pause_time = SDL_GetTicks() - start_time;
	}
}

void TimeManager::resume() {
	if (is_pause = true) {
		is_pause = false;
		start_time = SDL_GetTicks() - pause_time;
		pause_time = 0;
	}
}


int TimeManager::get_time() {
	if (is_start == true) {
		if (is_pause == true) {
			return pause_time;
		}
		else {
			return SDL_GetTicks() - start_time;
		}
	}
	return 0;
}
bool TimeManager::is_paused() {
	return is_pause;
}
bool TimeManager::is_started() {
	return is_start;
}