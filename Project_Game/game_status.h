#pragma once
#ifndef GAME_STATUS_H
#define GAME_STATUS_H
#include "base_func.h"

class game_status {
public:
	game_status();
	int status;
	int cd;
	int mg_status;
	enum class Language {
		ENGLISH,
		CHINESE
	};

	Language cur_language;
};


#endif
