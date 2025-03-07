#pragma once
#ifndef MUSIC_H_
#define MUSIC_H_
#include <SDL_mixer.h>
#include <string>
#include <map>
class Music_Manager {
protected:
	std::map<std::string, Mix_Music*> musics;
};
class Music : public Music_Manager
{
public:
	Mix_Chunk* sound_e;
	Music();
	~Music();

	void Free_Music();//hàm giải phóng music
	bool Load_Music(std::string path);//hàm load music
	void Play_Music(std::string path);//hàm bật nhạc
	void Play_Sound();
	void Load_Sound_Effect(std::string path);

	/*void Set_Name(std::string name) {
		name_music = name;
	}*/


	void End_Music();
	//void Call_Music(std::string path);
	double position;
	double get_position(std::string name);
	void set_position(double pos);
private:
	std::string name_music;

};

#endif // !MUSIC_H_
