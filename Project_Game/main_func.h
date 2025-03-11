#pragma once
#ifndef MAIN_FUNC_H_
#define MAIN_FUNC_H_
#include "load_pic.h"
#include "lawn.h"
#include "base_func.h"
#include "element.h"
#include "music.h"
#include "animation.h"
#include "time_manager.h"
#include <xmp.h>
#include "game_status.h"

#include "json.hpp"//Thư viện
#include <fstream>//Dùng đọc file
using json = nlohmann::json;
using std::fstream;
extern std::vector<json> level_list;
extern const std::vector<std::string> list_file;

extern std::vector<json> minigame_list;
extern const std::vector<std::string> listminigame_file;

extern const std::map<std::string, int> list_f_frame;
extern game_status status_manager;
extern Animation card_plant;
extern Element texture_reanim;
extern int count_zombie;
//Các biến dùng trong game
extern int pos_bg;//tọa độ bg
extern xmp_context ctx;
extern bool is_load_texture;
extern bool running;
extern int is_music;
extern Music click;
extern TimeManager timeGame;
extern bool is_remix;
extern int CARD_LOCATE;
extern int CARD_LOCATE_C;
extern std::string plant_m_hold;
extern SDL_Rect PLANT_HOLD;
extern int mouseX;
extern int mouseY;
extern TTF_Font* font;
extern Music esdp_c;
extern Music esdp;
extern SDL_Texture* textTexture;
extern SDL_Rect renderquad_2;
extern Element plant_manager;
extern Element zombie_manager;
extern Element item_manager;
extern Element all_game;
extern Music game_music;
extern Music cherry_sound;
extern Music planted;
extern Music reverse_explos;
extern Music hit;
extern Music sun_collected;
extern Music huge_wave_sound;
extern Music sound_melon;
extern Music win_sound;
extern Music lightfill;
extern Animation pea_idle;
extern Animation pea_shoot;
extern Animation snow_idle;
extern Animation snow_shoot;
extern Animation sunf_idle;
extern Animation sunf_product;
extern Animation explosion;
extern Animation zom_fire;
extern Animation cherry_idle;
extern Animation cherry_bomb;
extern Animation banana_tree;
extern Animation oxy_algae;
extern Animation light_red;
extern Animation shiliu_idle;
extern Animation shiliu_shoot;
extern LoadPIC star;

//Zombie
extern Animation normal_non;
extern Animation normal_walk_1;
extern Animation normal_walk_2;
extern Animation normal_eat_1;
extern Animation normal_eat_2;
extern Animation normal_dead;

extern Animation cnon;
extern Animation cwalk1;
extern Animation cwalk2;
extern Animation cwalk3;
extern Animation ceat1;
extern Animation ceat2;
extern Animation ceat3;

extern Animation sfnon;
extern Animation sfwalk;
extern Animation sfeat;
extern Animation sfdead;


extern Animation peazombieidle;
extern Animation peazombiewalk1;
extern Animation peazombiewalk2;
extern Animation peazombieeat;


extern Animation potatoplant;
extern Animation potatoup;
extern Animation potatoidle;
extern Animation potatoattack;
extern Animation potatoboom;

extern Animation level;
extern Animation level2;
extern Animation minigame1;
extern Animation minigame2;
extern Animation zomboni;
extern Music zomboni_sound;
//Item
extern Animation sun;
extern Animation melon_pro;
extern Animation miniGame;
extern LoadPIC outlevel;
extern LoadPIC pause1;
extern LoadPIC pause2;
extern LoadPIC reset1;
extern LoadPIC reset2;
extern Music mg_background;
extern Music potato_sound;
extern LoadPIC bg_background;
extern LoadPIC bg_seed_bank;
extern LoadPIC bg_sea;
extern LoadPIC huge_wave;
extern LoadPIC huge_wave_black;
extern LoadPIC shadow;
extern LoadPIC bg_seed_packet;
extern LoadPIC pro_flag;
extern LoadPIC pro_green;
extern LoadPIC pro_zom;
extern LoadPIC pro_non;
extern LoadPIC loadgame;
extern LoadPIC but1;
extern LoadPIC but2;
extern LoadPIC adventure1;
extern LoadPIC adventure2;
extern LoadPIC bgnormal;
extern LoadPIC challengebg;
extern LoadPIC challengemg;
extern LoadPIC back1;
extern LoadPIC back2;
extern LoadPIC cyp;
extern Animation fire;
extern Animation exnon;
extern Animation exwalk1;
extern Animation exwalk2;
extern Animation exdead;
extern LoadPIC play_but1;
extern LoadPIC play_but2;
extern std::string mouse_status;
extern const std::string WINDOW_NAME_N;
extern const std::string WINDOW_NAME_H;
extern const std::map<int, std::string> plant_num_list;

extern const std::map<std::string, int> plant_frame_list;
extern const std::map<std::string, int> sun_value_p;
extern const std::map<std::string, int> sun_value_cd;
extern const std::map<std::string, int> plant_wid;
extern const std::map<std::string, int> plant_hei;
void loadFileLevel();
int sound_init(xmp_context ctx, int sampling_rate, int channels);
void set_order();

void play_mainmusic(xmp_context ctx, int pattern);
void off_mainmusic(xmp_context ctx);
void set_channel_off(xmp_context ctx, int c1, int c2, int c3, int c4);
void set_channel_on(xmp_context ctx, int c1, int c2, int c3, int c4);

void render_card(SDL_Renderer* render);

void load_sound();

void load_anim();

bool LoadBG();
void load_texture_element();
int get_pos_card(int mouseX, int mouseY);
void remote_bullet(std::vector<Zombie*>& zombie_vector, std::vector<Bullet*>& bullet_vector);
void remote_anim_(std::vector<Plant*>& plant_vector);

void remote_instakill(std::vector<Zombie*>& zombie_vector, std::vector<Plant*>& plant_vector);
void remote_eat(std::vector<Zombie*>& zombie_vector, std::vector<Plant*>& plant_vector);
void remote_shoot(std::vector<Zombie*>& zombie_vector, std::vector<Plant*>& plant_vector);
void remote_anim_zombie(std::vector<Zombie*>& zombie_vector);
void remote_anim_item(std::vector<Item*>item_vector, int mX, int mY);
std::pair<int, int> get_location(int mouseX, int mouseY);
int get_cardlocatec(int mouseX, int mouseY);
void reset_level();
int get_sun_init(int level);
int getSunInit(int level);
int getWave(int level);
std::string getNameLevel(int level);
int getDelayTime(int level, int wave);
void spwanZombie(int level, int wave);
void loadFileMiniGame();
#endif // !MAIN_FUNC_H_
