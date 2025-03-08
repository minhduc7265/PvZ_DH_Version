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
	void Free_Music();
	bool Load_Music(std::string path);
	void Play_Music(std::string path);
	void Pause();
	void Resume();
	void Play_Sound();
	void Load_Sound_Effect(std::string path);
	void End_Music();
	double position;
	double get_position(std::string name);
	void set_position(double pos);
private:
	std::string name_music;

};

#endif