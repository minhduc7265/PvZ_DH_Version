#include "music.h"
#include <iostream>

Music::Music() {
	position = 0;
	name_music = "";
	sound_e = NULL;
}
Music::~Music() {


	Free_Music();
}


double Music::get_position(std::string name) {
	return Mix_GetMusicPosition(musics[name]);
}
void Music::set_position(double pos) {
	Mix_SetMusicPosition(pos);

}
//hàm này xem lại nha, vì game_music lvà 1 đối tượng chứa map
void Music::Free_Music() {

	Mix_FreeMusic(musics[name_music]);
	musics[name_music] = NULL;

	Mix_CloseAudio();


}
bool Music::Load_Music(std::string path) {
	if (musics.find(path) != musics.end()) {
		return true;//có tìm thấy nhạc
	}
	Mix_Music* backgroundMusic = Mix_LoadMUS(path.c_str());
	if (backgroundMusic == NULL) {
		std::cout << "Loi load nhac " << Mix_GetError() << std::endl;
		return false;
	}
	musics[path] = backgroundMusic;
	return true;

}
void Music::Play_Music(std::string path) {
	Mix_Music* play_mus = musics[path];
	Mix_PlayMusic(play_mus, -1);
}
void Music::Pause() {
	Mix_PauseMusic();
}
void Music::Resume() {
	Mix_ResumeMusic();
}
void Music::Load_Sound_Effect(std::string path) {
	sound_e = Mix_LoadWAV(path.c_str());
}
void Music::Play_Sound() {
	Mix_PlayChannel(-1, sound_e, 0);
}
void Music::End_Music() {
	Mix_HaltMusic();

}
