#pragma once
#ifndef TIME_MANAGER_H_
#define TIME_MANAGER_H_

class TimeManager {

public:
	TimeManager();
	~TimeManager();

	void start();
	void stop();
	void pause();
	void resume();
	int get_time();
	bool is_paused();
	bool is_started();
private:
	int start_time;
	int pause_time;


	bool is_pause;
	bool is_start;


};

#endif