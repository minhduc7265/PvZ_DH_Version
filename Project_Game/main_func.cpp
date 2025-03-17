#include "main_func.h"
std::vector<json> level_list(11);
std::vector<json> minigame_list(4);
const std::vector<std::string> listminigame_file{
	"",
	"level/mini1.json",
	"level/mini2.json",
	"level/mini3.json"
};
const std::vector<std::string> list_file{
	"",
	"level/level1.json",
	"level/level2.json",
	"level/level3.json",
	"level/level4.json",
	"level/level5.json",
	"level/level6.json",
	"level/level7.json",
	"level/level8.json",
	"level/level9.json",
	"level/level10.json"

};
const std::map<std::string, int> list_f_frame{
	{"zombie",89},
	{"conezombie",90},
	{"zomboni",12},
	{"seafzombie",59},
	{"exzombie",60},
	{"pea_zombie",90},
	{"ball_zombie",90},
	{"sky_zombie",61}


};
TimeManager timeGame;
Animation peazombieidle;
Animation peazombiewalk1;
Animation peazombiewalk2;
Animation peazombieeat;
Animation pea_idle;
Animation pea_shoot;
Animation snow_idle;
Animation snow_shoot;
Animation sunf_idle;
Animation sunf_product;
Animation explosion;
Animation zom_fire;
Animation cherry_idle;
Animation cherry_bomb;
Animation banana_tree;
Animation oxy_algae;
Animation light_red;
Animation melon_pro;
Animation shiliu_idle;
Music potato_sound;
Animation shiliu_shoot;
Animation normal_non;
Animation normal_walk_1;
Animation normal_walk_2;
Animation normal_eat_1;
Animation normal_eat_2;
Animation normal_dead;
Animation cnon;
Animation cwalk1;
Animation cwalk2;
Animation cwalk3;
Animation ceat1;
Animation ceat2;
Animation ceat3;
Animation level;
Animation level2;
Animation sfnon;
Animation sfwalk;
Animation sfeat;
Animation sfdead;
Animation exnon;
Animation exwalk1;
Animation exwalk2;
Animation exdead;
Animation fire;
Animation sun;
Animation zomboni;
Animation potatoplant;
Animation potatoup;
Animation potatoidle;
Animation potatoattack;
Animation potatoboom;

Animation ballidle;
Animation ballwalk;
Animation balldead;

Animation skyidle;
Animation skywalk;
Animation skydead;

Music lightfill;
LoadPIC huge_wave;
LoadPIC huge_wave_black;
LoadPIC bg_background;
LoadPIC bg_seed_bank;
LoadPIC shadow;
Music click;
Music mg_background;
LoadPIC bg_seed_packet;
LoadPIC pro_flag;
LoadPIC pro_green;
LoadPIC pro_zom;
LoadPIC pro_non;
LoadPIC loadgame;
LoadPIC bg_sea;
LoadPIC but1;
LoadPIC but2;
LoadPIC adventure1;
LoadPIC adventure2;
LoadPIC bgnormal;
LoadPIC challengebg;
LoadPIC challengemg;
LoadPIC background3;
LoadPIC background2;
LoadPIC back1;
LoadPIC back2;
LoadPIC cyp;
LoadPIC star;
LoadPIC play_but1;
LoadPIC play_but2;
LoadPIC tiankong;
Animation minigame1;
Animation minigame2;
LoadPIC outlevel;
LoadPIC pause1;
LoadPIC pause2;
LoadPIC reset1;
LoadPIC reset2;
Animation miniGame;
const std::string WINDOW_NAME_N = "Plants vs. Zombies DH Version - Normal Mode";
const std::string WINDOW_NAME_H = "Plants vs. Zombies DH Version - Hard Mode";
int pos_bg = 0;
xmp_context ctx;
bool is_load_texture = false;
bool running = true;
int is_music = 0;
int CARD_LOCATE_C;
bool is_remix = false;
int CARD_LOCATE;
std::string plant_m_hold = "";
SDL_Rect PLANT_HOLD = { 0,0,0,0 };
int mouseX = 0;
int mouseY = 0;
TTF_Font* font;
SDL_Texture* textTexture;
SDL_Rect renderquad_2;
Music win_sound;
Element texture_reanim;
Animation card_plant;
Music esdp_c;
Music esdp;
Music game_music;
Music cherry_sound;
Music zomboni_sound;
Music planted;
Music reverse_explos;
Music hit;
Music huge_wave_sound;
Music sun_collected;
Music sound_melon;
int count_zombie = 0;
Element plant_manager;
Element zombie_manager;
Element item_manager;
Element all_game;
game_status status_manager;
std::string mouse_status = "";
const std::map<int, std::string> plant_num_list = {
	{0,"sunflower"},
	{1,"potato_mine"},
	{2,"peashooter"},
	{3,"cherrybomb"},
	{4,"snowpea"},
	{5,"wallnut"},
	{6,"oxygen_algae"},
	{7,"banana_tree"},
	{8,"shiliu"},
};
const std::map<std::string, int> plant_frame_list = {
	{"sunflower",60},
	{"potato_mine",0},
	{"peashooter",31},
	{"cherrybomb",21},
	{"snowpea",144},
	{"wallnut",0},
	{"oxygen_algae",60},
	{"banana_tree",191},
	{"shiliu",76}
};
const std::map<std::string, int> plant_wid = {
	{"sunflower",176},
	{"potato_mine",205},
	{"peashooter",266},
	{"cherrybomb",262},
	{"snowpea",176},
	{"wallnut",0},
	{"oxygen_algae",77},
	{"banana_tree",237},
	{"shiliu",181},
};
const std::map<std::string, int> plant_hei = {
	{"sunflower",209},
	{"potato_mine",205},
	{"peashooter",245},
	{"cherrybomb",249},
	{"snowpea",209},
	{"wallnut",0},
	{"oxygen_algae",106},
	{"banana_tree",173},
	{"shiliu",213},
};
const std::map<std::string, int> sun_value_p = {
	{"sunflower",50},
	{"potato_mine",25},
	{"peashooter",100},
	{"cherrybomb",150},
	{"snowpea",175},
	{"wallnut",50},
	{"oxygen_algae",50},
	{"banana_tree",175},
	{"shiliu",225},
};
const std::map<std::string, int> sun_value_cd = {
	{"sunflower",235},
	{"potato_mine",20},//625
	{"peashooter",235},
	{"cherrybomb",1560},
	{"snowpea",235},
	{"wallnut",938},
	{"oxygen_algae",235},
	{"banana_tree",235},
	{"shiliu",470},
};
void play_mainmusic(xmp_context ctx, int pattern) {//pattern xem trong OpenMPT
	xmp_start_player(ctx, 44100, 0);
	xmp_set_position(ctx, pattern);
	SDL_PauseAudio(0);
}
void off_mainmusic(xmp_context ctx) {
	SDL_PauseAudio(1);
	xmp_end_player(ctx);
}
void set_channel_off(xmp_context ctx, int c1, int c2, int c3, int c4) {
	xmp_channel_mute(ctx, c1, 1);
	xmp_channel_mute(ctx, c2, 1);
	xmp_channel_mute(ctx, c3, 1);
	xmp_channel_mute(ctx, c4, 1);
}
void set_channel_on(xmp_context ctx, int c1, int c2, int c3, int c4) {
	xmp_channel_mute(ctx, c1, 0);
	xmp_channel_mute(ctx, c2, 0);
	xmp_channel_mute(ctx, c3, 0);
	xmp_channel_mute(ctx, c4, 0);
}
static void fill_audio(void* udata, unsigned char* stream, int len)
{
	xmp_play_buffer((xmp_context)udata, stream, len, 0);
}
int sound_init(xmp_context ctx, int sampling_rate, int channels)
{
	SDL_AudioSpec a;
	a.freq = sampling_rate;
	a.format = (AUDIO_S16);
	a.channels = channels;
	a.samples = 2048;
	a.callback = fill_audio;
	a.userdata = ctx;
	if (SDL_OpenAudio(&a, NULL) < 0) {
		cout << SDL_GetError() << endl;
		return -1;
	}
}
void render_card(SDL_Renderer* render) {
	SDL_Rect* currentClip = NULL;
	for (int i = 0; i < 7; i++) {
		if (card[i].get_is_allow() == true&& card[i].status_c == 1) {
			currentClip = &card_plant.get_clip()[card[i].type];
			texture_reanim.Render(render, currentClip, "card_plant", card[i].card_x, card[i].card_y, 50, 70);
		}
		else {
			currentClip = &card_plant.get_clip()[19];
			texture_reanim.Render(render, currentClip, "card_plant", card[i].card_x, card[i].card_y, 50, 70);
		}
	}
}
void set_order() {
	for (int i = 0; i < 7; i++) {
		card[i].card_order = i;
		card[i].card_x = 90 + 50 * i;
		card[i].card_y = 5;
	}
}
void load_sound() {
	esdp.Load_Music("music/ESDP.mp3");
	esdp_c.Load_Music("music/ESDP-S.mp3");
	cherry_sound.Load_Sound_Effect("music/cherrybomb.ogg");
	planted.Load_Sound_Effect("music/plant.ogg");
	reverse_explos.Load_Sound_Effect("music/reverse_explosion.ogg");
	hit.Load_Sound_Effect("music/splat.ogg");
	sun_collected.Load_Sound_Effect("music/sun_collected.ogg");
	huge_wave_sound.Load_Sound_Effect("music/hugewave.ogg");
	sound_melon.Load_Sound_Effect("music/melonimpact.ogg");
	zomboni_sound.Load_Sound_Effect("music/zomboni.ogg");
	win_sound.Load_Sound_Effect("music/winsound.ogg");
	lightfill.Load_Sound_Effect("music/lightfill.ogg");
	click.Load_Sound_Effect("music/click.ogg");
	mg_background.Load_Music("music/cyp2.mp3");
	potato_sound.Load_Sound_Effect("music/potato_mine.ogg");
}
void load_anim() {
	level.set_clip(5, 118, 120);
	level2.set_clip(5, 118, 120);
	minigame1.set_clip(5, 118, 120);
	minigame2.set_clip(5, 118, 120);
	pea_idle.set_clip(31, 266, 245);
	pea_shoot.set_clip(31, 269, 244);
	snow_idle.set_clip(144, 176, 209);
	snow_shoot.set_clip(48, 200, 232);
	sunf_idle.set_clip(60, 176, 209);
	sunf_product.set_clip(60, 176, 209);
	explosion.set_clip(21, 574, 546);
	zom_fire.set_clip(45, 426, 250);
	cherry_idle.set_clip(30, 262, 249);
	cherry_bomb.set_clip(21, 275, 264);
	banana_tree.set_clip(191, 237, 173);
	light_red.set_clip(20, 576, 564);
	oxy_algae.set_clip(60, 77, 106);
	card_plant.set_clip(20, 50, 70);
	normal_non.set_clip_bonus(63, 175, 206);
	normal_walk_1.set_clip_bonus(89, 173, 211);
	normal_walk_2.set_clip_bonus(89, 175, 211);
	normal_eat_1.set_clip_bonus(259, 135, 199);
	normal_eat_2.set_clip_bonus(259, 156, 204);
	normal_dead.set_clip_bonus(55, 237, 193);
	sun.set_clip(30, 200, 200);
	melon_pro.set_clip(10, 80, 67);
	shiliu_idle.set_clip(76, 181, 213);
	shiliu_shoot.set_clip(50, 249, 225);
	cnon.set_clip_bonus(63, 278, 265);;
	cwalk1.set_clip_bonus(90, 278, 265);
	cwalk2.set_clip_bonus(90, 278, 265);
	cwalk3.set_clip_bonus(90, 278, 265);
	ceat1.set_clip_bonus(259, 278, 265);
	ceat2.set_clip_bonus(259, 278, 265);
	ceat3.set_clip_bonus(259, 278, 265);
	zomboni.set_clip(12, 376, 361);
	sfnon.set_clip_bonus(62, 199, 218);
	sfwalk.set_clip_bonus(59, 199, 218);
	sfeat.set_clip_bonus(86, 199, 218);
	sfdead.set_clip_bonus(56, 199, 218);
	exnon.set_clip_bonus(64, 254, 274);
	exwalk1.set_clip_bonus(60, 282, 305);
	exwalk2.set_clip_bonus(60, 282, 305);
	exdead.set_clip_bonus(112, 415, 344);
	fire.set_clip(34, 390, 390);
	miniGame.set_clip(60, 350, 380);
	potatoplant.set_clip_bonus(29, 205, 205);
	potatoup.set_clip_bonus(25, 205, 205);
	potatoidle.set_clip_bonus(61, 205, 205);
	potatoattack.set_clip_bonus(20, 205, 205);
	potatoboom.set_clip_bonus(32, 390, 390);
	peazombieidle.set_clip_bonus(63, 180, 238);
	peazombiewalk1.set_clip_bonus(90, 180, 238);
	peazombiewalk2.set_clip_bonus(90, 180, 238);
	peazombieeat.set_clip_bonus(259, 180, 238);
	ballidle.set_clip_bonus(60, 302, 323);
	ballwalk.set_clip_bonus(90, 407, 515);
	balldead.set_clip_bonus(57, 334, 374);
	skyidle.set_clip_bonus(61, 249, 344);
	skywalk.set_clip_bonus(61, 291, 338);
	skydead.set_clip_bonus(80, 237, 292);
}
bool LoadBG() {
	cyp.Set_Name_Path("images/cyp.png");
	cyp.LoadImg("images/cyp.png",renderer);
	tiankong.Set_Name_Path("images/tiankong.png");
	tiankong.LoadImg("images/tiankong.png", renderer);
	background3.Set_Name_Path("images/background3.png");
	background3.LoadImg("images/background3.png", renderer);
	background2.Set_Name_Path("images/background2.png");
	background2.LoadImg("images/background2.png", renderer);
	back1.Set_Name_Path("images/back1.png");
	back1.LoadImg("images/back1.png", renderer);
	back2.Set_Name_Path("images/back2.png");
	back2.LoadImg("images/back2.png", renderer);
	star.Set_Name_Path("images/star.png");
	star.LoadImg("images/star.png", renderer);
	challengebg.Set_Name_Path("images/challengebg.png");
	challengebg.LoadImg("images/challengebg.png", renderer);
	adventure1.Set_Name_Path("images/adventure1.png");
	adventure1.LoadImg("images/adventure1.png", renderer);
	adventure2.Set_Name_Path("images/adventure2.png");
	adventure2.LoadImg("images/adventure2.png", renderer);
	bgnormal.Set_Name_Path("images/bgnormal.png");
	bgnormal.LoadImg("images/bgnormal.png", renderer);
	loadgame.Set_Name_Path("images/loadgame.png");
	loadgame.LoadImg("images/loadgame.png", renderer);
	but1.Set_Name_Path("images/but1.png");
	but1.LoadImg("images/but1.png", renderer);
	but2.Set_Name_Path("images/but2.png");
	but2.LoadImg("images/but2.png", renderer);
	huge_wave.Set_Name_Path("images/huge_1.png");
	huge_wave.LoadImg("images/huge_1.png",renderer);
	huge_wave_black.Set_Name_Path("images/huge_2.png");
	huge_wave_black.LoadImg("images/huge_2.png", renderer);
	shadow.Set_Name_Path("images/shadow.png");
	shadow.LoadImg("images/shadow.png", renderer);
	pro_flag.Set_Name_Path("images/flag_pro_flag.png");
	pro_flag.LoadImg("images/flag_pro_flag.png", renderer);
	pro_green.Set_Name_Path("images/flag_pro_green.png");
	pro_green.LoadImg("images/flag_pro_green.png", renderer);
	pro_zom.Set_Name_Path("images/flag_pro_zom.png");
	pro_zom.LoadImg("images/flag_pro_zom.png", renderer);
	pro_non.Set_Name_Path("images/flag_pro_non.png");
	pro_non.LoadImg("images/flag_pro_non.png", renderer);
	bg_seed_packet.Set_Name_Path("images/seed_packet.png");
	bg_seed_packet.LoadImg("images/seed_packet.png", renderer);
	bg_seed_bank.Set_Name_Path("images/SeedBank.png");
	bg_seed_bank.LoadImg("images/SeedBank.png", renderer);
	bg_background.Set_Name_Path("images/background1.png");
	bg_sea.LoadImg("images/background7.png", renderer);
	bg_sea.Set_Name_Path("images/background7.png");
	play_but1.LoadImg("images/play_button_1.png", renderer);
	play_but1.Set_Name_Path("images/play_button_1.png");
	play_but2.LoadImg("images/play_button_2.png", renderer);
	play_but2.Set_Name_Path("images/play_button_2.png");

	outlevel.LoadImg("images/outlevel.png", renderer);
	outlevel.Set_Name_Path("images/outlevel.png");
	pause1.LoadImg("images/pause1.png", renderer);
	pause1.Set_Name_Path("images/pause1.png");
	pause2.LoadImg("images/pause2.png", renderer);
	pause2.Set_Name_Path("images/pause2.png");
	reset1.LoadImg("images/reset1.png", renderer);
	reset1.Set_Name_Path("images/reset1.png");
	reset2.LoadImg("images/reset2.png", renderer);
	reset2.Set_Name_Path("images/reset2.png");
	challengemg.Set_Name_Path("images/challengemg.png");
	challengemg.LoadImg("images/challengemg.png", renderer);

	bool ret = bg_background.LoadImg("images/background1.png", renderer);//
	if (ret == false) {
		return false;
	}
	return true;
}
void load_texture_element() {
	texture_reanim.Load_Texture("images/mini-game1.png", renderer, "minigame1", "picture");
	texture_reanim.Load_Texture("images/mini-game2.png", renderer, "minigame2", "picture");
	texture_reanim.Load_Texture("images/level.png", renderer, "level", "picture");
	texture_reanim.Load_Texture("images/level2.png", renderer, "level2", "picture");
	texture_reanim.Load_Texture("spritesheet/peashooter.png", renderer, "peashooter", "plant");
	texture_reanim.Load_Texture("spritesheet/peashooter_shoot.png", renderer, "pea_shoot", "plant");
	texture_reanim.Load_Texture("spritesheet/snowpea.png", renderer, "snowpea", "plant");
	texture_reanim.Load_Texture("spritesheet/snow_shoot.png", renderer, "snow_shoot", "plant");
	texture_reanim.Load_Texture("spritesheet/sunflower.png", renderer, "sunflower", "plant");
	texture_reanim.Load_Texture("spritesheet/sunflower_product.png", renderer, "sunf_product", "plant");
	texture_reanim.Load_Texture("spritesheet/Explosion.png", renderer, "explosion", "plant");//effect not plant
	texture_reanim.Load_Texture("spritesheet/Zombie_fire.png", renderer, "zom_fire", "plant");//effect not plant
	texture_reanim.Load_Texture("spritesheet/cherry.png", renderer, "cherry_idle", "plant");
	texture_reanim.Load_Texture("spritesheet/cherry_bomb.png", renderer, "cherry_bomb", "plant");
	texture_reanim.Load_Texture("spritesheet/banana_tree.png", renderer, "banana_tree", "plant");
	texture_reanim.Load_Texture("spritesheet/normal_non.png", renderer, "normal_non", "zombie");
	texture_reanim.Load_Texture("spritesheet/normal_walk_1.png", renderer, "normal_walk_1", "zombie");
	texture_reanim.Load_Texture("spritesheet/normal_walk_2.png", renderer, "normal_walk_2", "zombie");
	texture_reanim.Load_Texture("spritesheet/normal_eat_1.png", renderer, "normal_eat_1", "zombie");
	texture_reanim.Load_Texture("spritesheet/normal_eat_2.png", renderer, "normal_eat_2", "zombie");
	texture_reanim.Load_Texture("spritesheet/normal_dead.png", renderer, "normal_dead", "zombie");
	texture_reanim.Load_Texture("spritesheet/cnon.png", renderer, "cnon", "zombie");
	texture_reanim.Load_Texture("spritesheet/cwalk1.png", renderer, "cwalk1", "zombie");
	texture_reanim.Load_Texture("spritesheet/cwalk2.png", renderer, "cwalk2", "zombie");
	texture_reanim.Load_Texture("spritesheet/cwalk3.png", renderer, "cwalk3", "zombie");
	texture_reanim.Load_Texture("spritesheet/ceat1.png", renderer, "ceat1", "zombie");
	texture_reanim.Load_Texture("spritesheet/ceat2.png", renderer, "ceat2", "zombie");
	texture_reanim.Load_Texture("spritesheet/ceat3.png", renderer, "ceat3", "zombie");
	texture_reanim.Load_Texture("spritesheet/light_red.png", renderer, "light_red", "plant");//effect not plant
	texture_reanim.Load_Texture("spritesheet/oxygen.png", renderer, "oxygen", "plant");
	texture_reanim.Load_Texture("images/seed_packet.png", renderer, "card_plant", "card_plant");
	texture_reanim.Load_Texture("spritesheet/sun.png", renderer, "sun", "item");
	texture_reanim.Load_Texture("spritesheet/melon_effect.png", renderer, "melon_pro", "plant");
	texture_reanim.Load_Texture("spritesheet/shiliu_idle.png", renderer, "shiliu_idle", "plant");
	texture_reanim.Load_Texture("spritesheet/shiliu_shoot.png", renderer, "shiliu_shoot", "plant");
	texture_reanim.Load_Texture("spritesheet/zomboni.png", renderer, "zomboni", "zombie");
	texture_reanim.Load_Texture("spritesheet/seafidle.png", renderer, "sfnon", "zombie");
	texture_reanim.Load_Texture("spritesheet/seafwalk.png", renderer, "sfwalk", "zombie");
	texture_reanim.Load_Texture("spritesheet/seafeat.png", renderer, "sfeat", "zombie");
	texture_reanim.Load_Texture("spritesheet/seafdead.png", renderer, "sfdead", "zombie");
	texture_reanim.Load_Texture("spritesheet/exnon.png", renderer, "exnon", "zombie");
	texture_reanim.Load_Texture("spritesheet/exwalk1.png", renderer, "exwalk1", "zombie");
	texture_reanim.Load_Texture("spritesheet/exwalk2.png", renderer, "exwalk2", "zombie");
	texture_reanim.Load_Texture("spritesheet/exdead.png", renderer, "exdead", "zombie");
	texture_reanim.Load_Texture("spritesheet/fire.png", renderer, "fire", "plant");//effect
	texture_reanim.Load_Texture("images/mini-game.png", renderer, "minigame", "image");
	texture_reanim.Load_Texture("spritesheet/potato_plant.png", renderer, "potatoplant", "plant");
	texture_reanim.Load_Texture("spritesheet/potato_up.png", renderer, "potatoup", "plant");
	texture_reanim.Load_Texture("spritesheet/potato_idle.png", renderer, "potatoidle", "plant");
	texture_reanim.Load_Texture("spritesheet/potato_attack.png", renderer, "potatoattack", "plant");
	texture_reanim.Load_Texture("spritesheet/potato_boom.png", renderer, "potatoboom", "plant");//effect
	texture_reanim.Load_Texture("spritesheet/peazombieidle.png", renderer, "peazombieidle", "zombie");
	texture_reanim.Load_Texture("spritesheet/peazombiewalk1.png", renderer, "peazombiewalk1", "zombie");
	texture_reanim.Load_Texture("spritesheet/peazombiewalk2.png", renderer, "peazombiewalk2", "zombie");
	texture_reanim.Load_Texture("spritesheet/peazombieeat.png", renderer, "peazombieeat", "zombie");
	texture_reanim.Load_Texture("spritesheet/ballidle.png", renderer, "ballidle", "zombie");
	texture_reanim.Load_Texture("spritesheet/ballwalk.png", renderer, "ballwalk", "zombie");
	texture_reanim.Load_Texture("spritesheet/balldead.png", renderer, "balldead", "zombie");
	texture_reanim.Load_Texture("spritesheet/skyidle.png", renderer, "skyidle", "zombie");
	texture_reanim.Load_Texture("spritesheet/skywalk.png", renderer, "skywalk", "zombie");
	texture_reanim.Load_Texture("spritesheet/skydead.png", renderer, "skydead", "zombie");
}
int get_pos_card(int mouseX, int mouseY) {

	if (mouseX >= 90 && mouseX <= 590 && mouseY >= 5 && mouseY <= 75) {
		return (mouseX - 90) / 50;
	}
	else {
		return -1;
	}
}
void remote_bullet(std::vector<Zombie*>& zombie_vector, std::vector<Bullet*>& bullet_vector) {
	for (Bullet* bullet : bullet_vector) {
		int min_x = 2222;
		int min_y = 0;
		if (bullet != NULL) {
			for (Zombie* zombie : zombie_vector) {
				if (zombie != NULL && bullet->num_row == zombie->num_row && zombie->is_dead == false) {
					if (min_x >= zombie->pos_x) {
						min_x = zombie->pos_x;
						min_y = zombie->pos_y;
					}
					if (bullet->rect_.x >= zombie->pos_x - 5 && bullet->rect_.x <= zombie->pos_x + 5 && bullet->is_hit == false && bullet->get_type()!=5) {
						
						bullet->is_out = true;
						bullet->is_hit = true;
						if (bullet->get_type() == 4) {
							if (zombie->armor_type_1 > 0) {
								zombie->armor_type_1 = zombie->armor_type_1 - 60;
							}
							else {
								zombie->zom_blood = zombie->zom_blood - 60;
							}
							
							sound_melon.Play_Sound();
							plant_manager.call_plant("melon_pro", bullet->num_row, (zombie->pos_x-30)/80, 10);
						}
						else if (bullet->get_type() == 2) {
							if (zombie->armor_type_1 > 0) {
								zombie->armor_type_1 = zombie->armor_type_1 - 20;
							}
							else {
								zombie->zom_blood = zombie->zom_blood - 20;
							}
							zombie->pos_x += 15;
							hit.Play_Sound();
						}
						else {
							if (zombie->armor_type_1 > 0) {
								zombie->armor_type_1 = zombie->armor_type_1 - 20;
							}
							else {
								zombie->zom_blood = zombie->zom_blood - 20;
							}
							
							hit.Play_Sound();
						}
						break;
					}
					else if(bullet->rect_.x >= zombie->pos_x && bullet->is_hit == false && bullet->get_type() == 5) {
						if (zombie->armor_type_1 > 0) {
							zombie->armor_type_1 = zombie->armor_type_1 - 1;
							bullet->rect_.x+=2;
						}
						else {
							zombie->zom_blood = zombie->zom_blood - 1;
							bullet->rect_.x+=4;
						}
						//hit.Play_Sound();
					}
				}
			}
			if (bullet->min_ox == 0) {
				bullet->min_ox = min_y - bullet->oy + 0.5*(min_x - 80 * bullet->num_col) * (min_x - 80 * bullet->num_col) / 100;
				bullet->min_ox = bullet->min_ox / (min_x - 80 * bullet->num_col);
			}
		}
		
		
	}
}
void remote_instakill(std::vector<Zombie*>& zombie_vector, std::vector<Plant*>& plant_vector) {
	for (Plant* plant : plant_vector) {
		if (plant != NULL && plant->name_plant == "cherrybomb" && plant->count_down == 20) {
			for (Zombie* zombie : zombie_vector)
			{
				if (zombie->num_row == plant->num_row ||
					zombie->num_row == plant->num_row + 1 ||
					zombie->num_row == plant->num_row - 1)
				{

					if (zombie->pos_x >= (plant->num_col - 1) * 80 - 80 && zombie->pos_x <= (plant->num_col + 1) * 80 + 80) {
						zombie->name_zombie = "zombie";
						zombie->zom_blood -= (1800 - zombie->armor_type_1);
						zombie->armor_type_1 = -1;
						
					}
				}


			}

		}
		else if (plant != NULL && plant->name_plant == "potato_mine"  && plant->status == "attack" && plant->cur_frame >= 18) {
			for (Zombie* zombie : zombie_vector)
			{
				if (zombie->num_row == plant->num_row)
				{

					if (zombie->pos_x >= (plant->num_col - 1) * 80 && zombie->pos_x <= (plant->num_col + 1) * 80 + 20) {
						zombie->name_zombie = "zombie";
						zombie->zom_blood -= (1800 - zombie->armor_type_1);
						zombie->armor_type_1 = -1;
						plant->set_is_dead(true);
						plant_manager.call_plant("potatoboom", plant->get_num_row(), plant->get_num_col(), 32);
						potato_sound.Play_Sound();

					}
				}


			}
		}
	}
}
void remote_eat(std::vector<Zombie*>& zombie_vector, std::vector<Plant*>& plant_vector) {
	for (Zombie* zombie : zombie_vector) {
		if (zombie != NULL && zombie->status != "dead") {
			zombie->status = "walk";
			for (Plant* plant : plant_vector) {
				if (plant != NULL && zombie->num_row == plant->num_row && plant->get_is_dead() == false && plant->if_effect == false) {
					if (zombie->pos_x >= plant->num_col * 80 && zombie->pos_x <= (plant->num_col + 1) * 80) {
						if (zombie->name_zombie == "zomboni") {
							//plant_manager.call_plant("zom_fire", plant->num_row, plant->num_col, 45);//push_back gây cấp phát lại và lỗi con trỏ
							plant->set_cur_blood(plant->get_cur_blood() - 90);
						}
						else if (zombie->name_zombie == "exzombie") {
							plant_manager.call_plant("fire", plant->num_row, plant->num_col, 45);
							plant->set_cur_blood(plant->get_cur_blood() - 400);
						}
						plant->set_cur_blood(plant->get_cur_blood() - 2);
						zombie->status = "eat";
						if (plant->name_plant == "potato_mine" && plant->count_down > 480) {
							plant->status = "attack";
						}
						
					}
				}


			}
		}

	}

}
void remote_shoot(std::vector<Zombie*>& zombie_vector, std::vector<Plant*>& plant_vector) {
	for (Plant* plant : plant_vector) {
		if (plant != NULL&&plant->name_plant!="potato_mine") {
			plant->if_shoot = false;
			for (Zombie* zombie : zombie_vector) {
				if (zombie !=NULL && plant->num_row == zombie->num_row && zombie->is_dead == false) {
					plant->if_shoot = true;
				}

			}

		}
		
	}
}
void remote_anim_zombie(std::vector<Zombie*>& zombie_vector) {
	std::string name_anim;
	Animation anim_change;
	int const_;
	int const_x;
	for (int i = 0; i < zombie_vector.size(); i++) {
		if (zombie_vector.at(i) != NULL) {
			Zombie* cur_zombie = zombie_vector.at(i);
			shadow.SetRect(cur_zombie->pos_x, cur_zombie->pos_y + 100);
			shadow.Render(renderer, NULL);
			if (cur_zombie->name_zombie == "zombie") {
				if (cur_zombie->status == "idle") {
					anim_change = normal_non;
					const_ = 0;
					name_anim = "normal_non";

				}
				else if (cur_zombie->status == "walk") {
					cur_zombie->num_frame = 89;
					if (cur_zombie->zom_blood <= 110) {
						anim_change = normal_walk_2;
						name_anim = "normal_walk_2";
						const_ = 0;
					}
					else {
						anim_change = normal_walk_1;
						name_anim = "normal_walk_1";
						const_ = 0;
					}

				}
				else if (cur_zombie->status == "eat") {
					cur_zombie->num_frame = 259;
					if (cur_zombie->zom_blood <= 110) {
						anim_change = normal_eat_2;
						name_anim = "normal_eat_2";
						const_ = 5;
					}
					else {
						anim_change = normal_eat_1;
						name_anim = "normal_eat_1";
						const_ = 5;
					}

				}
				else {
					cur_zombie->num_frame = 55;
					anim_change = normal_dead;
					name_anim = "normal_dead";
					const_ = 20;

				}
				cur_zombie->currentClip = &anim_change.get_clip()[cur_zombie->cur_frame];
				texture_reanim.Render(renderer, cur_zombie->currentClip, name_anim,
					cur_zombie->pos_x, cur_zombie->pos_y + const_,
					3 * cur_zombie->currentClip->w / 5,
					3 * cur_zombie->currentClip->h / 5);



			}
			else if (cur_zombie->name_zombie == "conezombie") {
				if (cur_zombie->armor_type_1 <= 0) {
					cur_zombie->name_zombie = "zombie";
				}
				if (cur_zombie->status == "idle") {
					anim_change = cnon;
					const_ = 0;
					name_anim = "cnon";

				}
				else if (cur_zombie->status == "walk") {
					cur_zombie->num_frame = 90;
					if (cur_zombie->armor_type_1 <= 250 && cur_zombie->armor_type_1 > 130) {
						anim_change = cwalk2;
						name_anim = "cwalk2";
						const_ = -30;
					}
					else if (cur_zombie->armor_type_1 <= 130 && cur_zombie->armor_type_1 >0) {
						anim_change = cwalk3;
						name_anim = "cwalk3";
						const_ = -30;
					}
					else {
						anim_change = cwalk1;
						name_anim = "cwalk1";
						const_ = -30;
					}

				}
				else if (cur_zombie->status == "eat") {
					cur_zombie->num_frame = 259;

					if (cur_zombie->armor_type_1 <= 250 && cur_zombie->armor_type_1 > 130) {
						anim_change = ceat2;
						name_anim = "ceat2";
						const_ = -30;
					}
					else if (cur_zombie->armor_type_1 <= 130 && cur_zombie->armor_type_1 > 0) {
						anim_change = ceat3;
						name_anim = "ceat3";
						const_ = -30;
					}
					else {
						anim_change = ceat1;
						name_anim = "ceat1";
						const_ = -30;
					}

				}
				cur_zombie->currentClip = &anim_change.get_clip()[cur_zombie->cur_frame];
				texture_reanim.Render(renderer, cur_zombie->currentClip, name_anim,
					cur_zombie->pos_x-60, cur_zombie->pos_y + const_,
					3 * cur_zombie->currentClip->w / 5,
					3 * cur_zombie->currentClip->h / 5);



			}

			else if (cur_zombie->name_zombie == "zomboni") {
				cur_zombie->num_frame = 12;
				anim_change = zomboni;
				name_anim = "zomboni";
				const_ = -50;
				cur_zombie->currentClip = &anim_change.get_clip()[cur_zombie->cur_frame];
				texture_reanim.Render(renderer, cur_zombie->currentClip, name_anim,
					cur_zombie->pos_x, cur_zombie->pos_y + const_,
					cur_zombie->currentClip->w / 2,
				cur_zombie->currentClip->h / 2);



			}
			else if (cur_zombie->name_zombie == "seafzombie") {

				if (cur_zombie->status == "idle") {
					anim_change = sfnon;
					const_ = 0;
					name_anim = "sfnon";

				}
				else if (cur_zombie->status == "walk") {
					cur_zombie->num_frame = 59;
					anim_change = sfwalk;
					name_anim = "sfwalk";
					const_ = -60;

				}
				else if (cur_zombie->status == "eat") {
					cur_zombie->num_frame = 86;
					anim_change = sfeat;
					name_anim = "sfeat";
					const_ = -60;

				}
				else {
					cur_zombie->num_frame = 56;
					anim_change = sfdead;
					name_anim = "sfdead";
					const_ = -60;

				}
				cur_zombie->currentClip = &anim_change.get_clip()[cur_zombie->cur_frame];
				texture_reanim.Render(renderer, cur_zombie->currentClip, name_anim,
					cur_zombie->pos_x - 60, cur_zombie->pos_y + const_,
					cur_zombie->currentClip->w,
					cur_zombie->currentClip->h);



			}
			else if (cur_zombie->name_zombie == "exzombie") {
				if (cur_zombie->status == "idle") {
					anim_change = exnon;
					const_ = 0;
					const_x = -60; const_x = -60;
					name_anim = "exnon";

				}
				else if (cur_zombie->status == "walk") {
					cur_zombie->num_frame = 60;
					if (cur_zombie->zom_blood <= 150) {
						anim_change = exwalk2;
						name_anim = "exwalk2";
						const_ = -60;
						const_x = -60;
					}
					else {
						anim_change = exwalk1;
						name_anim = "exwalk1";
						const_ = -60;
						const_x = -60;
					}

				}
				else {
					cur_zombie->num_frame = 112;
					anim_change = exdead;
					name_anim = "exdead";
					const_ = -60;
					const_x = -140;

				}
				
				cur_zombie->currentClip = &anim_change.get_clip()[cur_zombie->cur_frame];
				texture_reanim.Render(renderer, cur_zombie->currentClip, name_anim,
					cur_zombie->pos_x +const_x, cur_zombie->pos_y + const_,
					3 * cur_zombie->currentClip->w / 5,
					3 * cur_zombie->currentClip->h / 5);



			}
			else if (cur_zombie->name_zombie == "pea_zombie") {
				if (cur_zombie->status == "idle") {
					cur_zombie->num_frame = 63;
					anim_change = peazombieidle;
					const_ = 0;
					name_anim = "peazombieidle";

				}
				else if (cur_zombie->status == "walk") {
					cur_zombie->num_frame = 90;
					if (cur_zombie->zom_blood <= 130) {
						anim_change = peazombiewalk2;
						name_anim = "peazombiewalk2";
						const_ = -10;
					}
					
					else {
						anim_change = peazombiewalk1;
						name_anim = "peazombiewalk1";
						const_ = -10;
					}

				}
				else if (cur_zombie->status == "eat") {
					cur_zombie->num_frame = 259;
					anim_change = peazombieeat;
					name_anim = "peazombieeat";
					const_ = -10;

				}
				else {
					cur_zombie->num_frame = 55;
					anim_change = normal_dead;
					name_anim = "normal_dead";
					const_ = 20;
				}
				cur_zombie->currentClip = &anim_change.get_clip()[cur_zombie->cur_frame];
				texture_reanim.Render(renderer, cur_zombie->currentClip, name_anim,
					cur_zombie->pos_x - 40, cur_zombie->pos_y + const_,
					126,
					166);



			}
			else if (cur_zombie->name_zombie == "ball_zombie") {

				if (cur_zombie->status == "idle") {
					anim_change = ballidle;
					const_ = 0;
					name_anim = "ballidle";

				}
				else if (cur_zombie->status == "walk") {
					cur_zombie->num_frame = 90;
					anim_change = ballwalk;
					name_anim = "ballwalk";
					const_ = -60;

				}
				else {
					cur_zombie->num_frame = 57;
					anim_change = balldead;
					name_anim = "balldead";
					const_ = -60;

				}
				cur_zombie->currentClip = &anim_change.get_clip()[cur_zombie->cur_frame];
				texture_reanim.Render(renderer, cur_zombie->currentClip, name_anim,
					cur_zombie->pos_x - 60, cur_zombie->pos_y + const_,
					cur_zombie->currentClip->w/2,
					cur_zombie->currentClip->h/2);



			}
			else if (cur_zombie->name_zombie == "sky_zombie") {

				if (cur_zombie->status == "idle") {
					anim_change = skyidle;
					const_ = 0;
					name_anim = "skyidle";

				}
				else if (cur_zombie->status == "walk") {
					cur_zombie->num_frame = 61;
					anim_change = skywalk;
					name_anim = "skywalk";
					const_ = -60;

				}
				else {
					cur_zombie->num_frame = 80;
					anim_change = skydead;
					name_anim = "skydead";
					const_ = -60;

				}
				cur_zombie->currentClip = &anim_change.get_clip()[cur_zombie->cur_frame];
				texture_reanim.Render(renderer, cur_zombie->currentClip, name_anim,
					cur_zombie->pos_x - 60, cur_zombie->pos_y + const_,
					cur_zombie->currentClip->w / 2,
					cur_zombie->currentClip->h / 2);



			}

		}
		


	}



}
void remote_anim_(std::vector<Plant*>& plant_vector) {
	for (int i = 0; i < plant_vector.size(); i++) {
		if (plant_vector.size() != NULL) {
			Plant* cur_plant = plant_vector.at(i);
			if (cur_plant->if_effect == false) {
				shadow.SetRect((cur_plant->get_num_col()) * 80 + 30, (cur_plant->get_num_row()) * 100 + 140);
				shadow.Render(renderer, NULL);
			}
			if (cur_plant->name_plant == "peashooter") {
				if (cur_plant->count_down == 85 && cur_plant->if_shoot == true) {
					all_game.call_bullet(renderer, 1, (cur_plant->get_num_col() + 1) * 80 + 40, (cur_plant->get_num_row()) * 100 + 100, cur_plant->get_num_row(), cur_plant->get_num_col());
				}
				if (cur_plant->status == "idle") {
					cur_plant->currentClip = &pea_idle.get_clip()[cur_plant->cur_frame];
					texture_reanim.Render(renderer, cur_plant->currentClip, "peashooter", (cur_plant->get_num_col() + 1) * 80 - 50 - 40, (cur_plant->get_num_row()) * 100 - 50 + 90, 5 * cur_plant->currentClip->w / 8, 5 * cur_plant->currentClip->h / 8);
				}
				else if (cur_plant->status == "shoot") {
					cur_plant->currentClip = &pea_shoot.get_clip()[cur_plant->cur_frame];
					texture_reanim.Render(renderer, cur_plant->currentClip, "pea_shoot", (cur_plant->get_num_col() + 1) * 80 - 53 - 40, (cur_plant->get_num_row()) * 100 - 51 + 90, 5 * cur_plant->currentClip->w / 8, 5 * cur_plant->currentClip->h / 8);
				}
			}
			else if (cur_plant->name_plant == "snowpea") {
				if (cur_plant->count_down == 80 && cur_plant->if_shoot == true) {
					all_game.call_bullet(renderer, 2, (cur_plant->get_num_col() + 1) * 80, (cur_plant->get_num_row()) * 100 + 100, cur_plant->get_num_row(), cur_plant->get_num_col());
				}
				if (cur_plant->status == "idle") {
					cur_plant->num_frame = 144;
					cur_plant->currentClip = &snow_idle.get_clip()[cur_plant->cur_frame];
					texture_reanim.Render(renderer, cur_plant->currentClip, "snowpea", (cur_plant->get_num_col() + 1) * 80 - 50, (cur_plant->get_num_row()) * 100 + 80-23, 5 * cur_plant->currentClip->w / 8, 5 * cur_plant->currentClip->h / 8);
				}
				else if (cur_plant->status == "shoot") {
					cur_plant->num_frame = 48;
					cur_plant->currentClip = &snow_shoot.get_clip()[cur_plant->cur_frame];
					texture_reanim.Render(renderer, cur_plant->currentClip, "snow_shoot", (cur_plant->get_num_col() + 1) * 80 - 50, (cur_plant->get_num_row()) * 100 - 51 + 15 + 80, 5 * cur_plant->currentClip->w / 8, 5 * cur_plant->currentClip->h / 8);
				}
			}
			else if (cur_plant->name_plant == "sunflower") {
				if (cur_plant->count_down == 610) {
					item_manager.call_item(0, (cur_plant->get_num_col() + 1) * 80 - 50 - 40, (cur_plant->get_num_row()) * 100 - 50 + 10 + 70, 30);
				}
				if (cur_plant->status == "idle") {
					cur_plant->num_frame = 59;
					cur_plant->currentClip = &sunf_idle.get_clip()[cur_plant->cur_frame];
					texture_reanim.Render(renderer, cur_plant->currentClip, "sunflower", (cur_plant->get_num_col() + 1) * 80 - 60, (cur_plant->get_num_row()) * 100 +60, 5 * cur_plant->currentClip->w / 8, 5 * cur_plant->currentClip->h / 8);
				}
				else if (cur_plant->status == "production") {
					cur_plant->num_frame = 60;
					cur_plant->currentClip = &sunf_product.get_clip()[cur_plant->cur_frame];
					texture_reanim.Render(renderer, cur_plant->currentClip, "sunf_product", (cur_plant->get_num_col() + 1) * 80 - 60 , (cur_plant->get_num_row()) * 100  + 60, 5 * cur_plant->currentClip->w / 8, 5 * cur_plant->currentClip->h / 8);
				}
			}

			else if (cur_plant->name_plant == "explosion") {
				cur_plant->if_effect = true;
				cur_plant->currentClip = &explosion.get_clip()[cur_plant->cur_frame];
				texture_reanim.Render(renderer, cur_plant->currentClip, "explosion", (cur_plant->get_num_col() + 1) * 80 - 53 - 95, (cur_plant->get_num_row()) * 100 - 51 + 20, 4 * cur_plant->currentClip->w / 8, 4 * cur_plant->currentClip->h / 8);
				if (cur_plant->count_down == 20) {
					cur_plant->set_is_dead(true);
				}
			}
			else if (cur_plant->name_plant == "light_red") {
				cur_plant->if_effect = true;
				cur_plant->currentClip = &light_red.get_clip()[cur_plant->cur_frame];
				texture_reanim.Render(renderer, cur_plant->currentClip, "light_red", (cur_plant->get_num_col() + 1) * 80 - 53 - 95, (cur_plant->get_num_row()) * 100 - 51 + 20, 4 * cur_plant->currentClip->w / 8, 4 * cur_plant->currentClip->h / 8);
				if (cur_plant->count_down == 20) {
					cur_plant->set_is_dead(true);
				}
			}
			else if (cur_plant->name_plant == "cherrybomb") {
				cur_plant->currentClip = &cherry_bomb.get_clip()[cur_plant->cur_frame];
				texture_reanim.Render(renderer, cur_plant->currentClip, "cherry_bomb", (cur_plant->get_num_col() + 1) * 80 - 53 - 75, (cur_plant->get_num_row()) * 100 - 51 + 70, 5 * cur_plant->currentClip->w / 8, 5 * cur_plant->currentClip->h / 8);
				if (cur_plant->count_down == 20) {
					cur_plant->set_is_dead(true);
					cherry_sound.Play_Sound();
					plant_manager.call_plant("explosion", cur_plant->get_num_row(), cur_plant->get_num_col(), 21);
					//plant_manager.call_plant("zom_fire", 6, 0, 21);
					plant_manager.call_plant("light_red", cur_plant->get_num_row(), cur_plant->get_num_col(), 21);
				}

			}
			else if (cur_plant->name_plant == "zom_fire") {
				cur_plant->if_effect = true;
				cur_plant->currentClip = &zom_fire.get_clip()[cur_plant->cur_frame];
				texture_reanim.Render(renderer, cur_plant->currentClip, "zom_fire", (cur_plant->get_num_col() + 1) * 80 - 53, (cur_plant->get_num_row() + 1) * 100 - 51, 5 * cur_plant->currentClip->w / 8, 5 * cur_plant->currentClip->h / 8);
				if (cur_plant->count_down == 30) {
					cur_plant->set_is_dead(true);
				}

			}
			else if (cur_plant->name_plant == "fire") {
				cur_plant->if_effect = true;
				cur_plant->currentClip = &fire.get_clip()[cur_plant->cur_frame];
				texture_reanim.Render(renderer, cur_plant->currentClip, "fire", (cur_plant->get_num_col() + 1) * 80 - 110, (cur_plant->get_num_row() + 1) * 100 -90, 5 * cur_plant->currentClip->w / 8, 5 * cur_plant->currentClip->h / 8);
				if (cur_plant->count_down == 34) {
					cur_plant->set_is_dead(true);
				}

			}
			else if (cur_plant->name_plant == "melon_pro") {
				cur_plant->if_effect = true;
				cur_plant->currentClip = &melon_pro.get_clip()[cur_plant->cur_frame];
				texture_reanim.Render(renderer, cur_plant->currentClip, "melon_pro", (cur_plant->get_num_col() + 1) * 80, (cur_plant->get_num_row() + 1) * 100-100, 3*cur_plant->currentClip->w/2, 3*cur_plant->currentClip->h/2 );
				if (cur_plant->count_down == 10) {
					cur_plant->set_is_dead(true);
				}

			}
			else if (cur_plant->name_plant == "potatoboom") {
				cur_plant->if_effect = true;
				cur_plant->currentClip = &potatoboom.get_clip()[cur_plant->cur_frame];
				texture_reanim.Render(renderer, cur_plant->currentClip, "potatoboom", (cur_plant->get_num_col()) * 80, (cur_plant->get_num_row() + 1) * 100-50, 195, 195);
				if (cur_plant->count_down == 16) {
					cur_plant->set_is_dead(true);
				}

			}
			else if (cur_plant->name_plant == "banana_tree") {
				cur_plant->currentClip = &banana_tree.get_clip()[cur_plant->cur_frame];
				texture_reanim.Render(renderer, cur_plant->currentClip, "banana_tree", (cur_plant->get_num_col() + 1) * 80 - 50 - 30, (cur_plant->get_num_row()) * 100 + 70, 5 * cur_plant->currentClip->w / 8, 5 * cur_plant->currentClip->h / 8);
				if ((cur_plant->count_down == 110 || cur_plant->count_down == 120) && cur_plant->if_shoot == true) {
					all_game.call_bullet(renderer, 5, (cur_plant->get_num_col() + 1) * 80, (cur_plant->get_num_row()) * 100 + 100, cur_plant->get_num_row(), cur_plant->get_num_col());
				}
			}
			else if (cur_plant->name_plant == "oxygen_algae") {

				cur_plant->currentClip = &oxy_algae.get_clip()[cur_plant->cur_frame];
				texture_reanim.Render(renderer, cur_plant->currentClip, "oxygen", (cur_plant->get_num_col() + 1) * 80 - 50, (cur_plant->get_num_row()) * 100 + 70, cur_plant->currentClip->w, cur_plant->currentClip->h);
			}
			else if (cur_plant->name_plant == "shiliu") {
				if (cur_plant->count_down == 110 && cur_plant->if_shoot == true) {
					all_game.call_bullet(renderer, 4, (cur_plant->get_num_col() + 1) * 80-100, (cur_plant->get_num_row()) * 100 +50, cur_plant->get_num_row(), cur_plant->get_num_col());
				}
				if (cur_plant->status == "idle") {
					cur_plant->num_frame = 76;
					cur_plant->currentClip = &shiliu_idle.get_clip()[cur_plant->cur_frame];
					texture_reanim.Render(renderer, cur_plant->currentClip, "shiliu_idle", (cur_plant->get_num_col() + 1) * 80 - 50- 35, (cur_plant->get_num_row()) * 100 - 51 + 70+20, 5 * cur_plant->currentClip->w / 8, 5 * cur_plant->currentClip->h / 8);
				}
				else if (cur_plant->status == "shoot") {
					cur_plant->num_frame = 50;
					cur_plant->currentClip = &shiliu_shoot.get_clip()[cur_plant->cur_frame];
					texture_reanim.Render(renderer, cur_plant->currentClip, "shiliu_shoot", (cur_plant->get_num_col() + 1) * 80 - 50 - 17 - 40, (cur_plant->get_num_row()) * 100 - 51 + 15 + 70, 5 * cur_plant->currentClip->w / 8, 5 * cur_plant->currentClip->h / 8);
				}
			}
			else if (cur_plant->name_plant == "potato_mine") {
				if (cur_plant->status == "idle") {
					cur_plant->num_frame = 29;
					cur_plant->currentClip = &potatoplant.get_clip()[cur_plant->cur_frame];
					texture_reanim.Render(renderer, cur_plant->currentClip, "potatoplant", (cur_plant->get_num_col() + 1) * 80 - 70, (cur_plant->get_num_row()) * 100 + 80, 5 * cur_plant->currentClip->w / 8, 5 * cur_plant->currentClip->h / 8);
				}
				else if (cur_plant->status == "upidle2") {
					cur_plant->num_frame = 61;
					cur_plant->currentClip = &potatoidle.get_clip()[cur_plant->cur_frame];
					texture_reanim.Render(renderer, cur_plant->currentClip, "potatoidle", (cur_plant->get_num_col() + 1) * 80 - 70, (cur_plant->get_num_row()) * 100 + 80, 5 * cur_plant->currentClip->w / 8, 5 * cur_plant->currentClip->h / 8);
				}
				else if (cur_plant->status == "up") {
					cur_plant->num_frame = 25;
					cur_plant->currentClip = &potatoup.get_clip()[cur_plant->cur_frame];
					texture_reanim.Render(renderer, cur_plant->currentClip, "potatoup", (cur_plant->get_num_col() + 1) * 80 - 70, (cur_plant->get_num_row()) * 100 + 80, 5 * cur_plant->currentClip->w / 8, 5 * cur_plant->currentClip->h / 8);
				}
				else if (cur_plant->status == "attack") {
					cur_plant->num_frame = 20;
					cur_plant->currentClip = &potatoattack.get_clip()[cur_plant->cur_frame];
					texture_reanim.Render(renderer, cur_plant->currentClip, "potatoattack", (cur_plant->get_num_col() + 1) * 80 - 70, (cur_plant->get_num_row()) * 100 + 80, 5 * cur_plant->currentClip->w / 8, 5 * cur_plant->currentClip->h / 8);
				}
			}
		}
	


	}
}
void remote_anim_item(std::vector<Item*>item_vector, int mX, int mY) {
	for (Item* item : item_vector) {
		if (item !=NULL && item->get_type() == 0) {
			item->currentClip = &sun.get_clip()[item->cur_frame];
			texture_reanim.Render(renderer, item->currentClip, "sun", item->rect_.x, item->rect_.y, 3 * item->currentClip->w / 5, 3 * item->currentClip->h / 5);
			if (mX >= item->rect_.x + 25 && mX <= item->rect_.x + 80 && mY >= item->rect_.y + 25 && mY <= item->rect_.y + 80) {
				item->animation = 1;
				sun_collected.Play_Sound();
			}



		}

	}
}
std::pair<int, int> get_location(int mouseX, int mouseY) {
	std::pair<int, int> mouse;
	if (mouseX >= FIRST_X && mouseY >= FIRST_Y) {
		mouse.second = (mouseX - FIRST_X) / DISTANCE_X;//cột
		mouse.first = (mouseY - FIRST_Y) / DISTANCE_Y;//hàng
	}
	else {
		mouse.first = -1;
		mouse.second = -1;
	}

	return mouse;
}
int get_cardlocatec(int mouseX, int mouseY) {
	int a = 0;
	int b = 0;
	a = (mouseX - 25) / 60;
	b = (mouseY - 110) / 70;
	if (b == 0 && a <= 6) {
		return a;
	}
	else if (b == 1 && (a + 7) <= 9) {
		return a + 7;
	}
	else {
		return -1;
	}
}
void reset_level(int parameter) {
	if (parameter == 0) {
		cur_imformation.reset_process();
	}
	else if (parameter == 1) {
		cur_imformation.cur_sun = getSunInit(cur_imformation.cur_td_adventure != 0 ? cur_imformation.cur_td_adventure : cur_imformation.cur_mini_game);//test thôi
		cur_imformation.delay_time = 0;
		cur_imformation.cur_sence = 0;
		cur_imformation.flag_process = 0;
		cur_imformation.flag1x = 0;
		cur_imformation.flag1y = 567;
		cur_imformation.flag2x = 0;
		cur_imformation.flag2y = 567;
		cur_imformation.flag3x = 0;
		cur_imformation.flag3y = 567;
		cur_imformation.wintime = 0;
		cur_imformation.time_delay = 600;
		cur_imformation.wave = 0;
		cur_imformation.type_flag = getWave(cur_imformation.cur_td_adventure != 0 ? cur_imformation.cur_td_adventure : cur_imformation.cur_mini_game);
	}
	plant_manager.reset_list_plant();
	zombie_manager.reset_list_zombie();
	game_lawn.Lawn_Set();
}
void loadFileLevel() {
	for (int i = 1; i <= 10; i++) {
		fstream file;
		file.open(list_file.at(i));
		if (!file.is_open()) {
			cout << "File của tao đâu" << endl;
			return;
		}
		else {
			level_list[i] = json::parse(file);
			file.close();
		}
	}
}
void loadFileMiniGame() {
	for (int i = 1; i <= 3; i++) {
		fstream file;
		file.open(listminigame_file.at(i));
		if (!file.is_open()) {
			cout << "File của tao đâu" << endl;
			return;
		}
		else {
			minigame_list[i] = json::parse(file);
			file.close();
		}
	}
}
int getSunInit(int level) {
	if (cur_imformation.cur_td_adventure != 0) {
		return level_list[level]["sun_init"];
	}
	else {
		return minigame_list[level]["sun_init"];
	}
	
}
int getWave(int level) {
	if (cur_imformation.cur_td_adventure != 0) {
		return level_list[level]["num_wave"];
	}
	else {
		return minigame_list[level]["num_wave"];
	}
	
}
std::string getNameLevel(int level) {
	if (cur_imformation.cur_td_adventure != 0) {
		return level_list[level]["name_level"].template get<std::string>();
	}
	else {
		return minigame_list[level]["name_level"].template get<std::string>();
	}
	
}
int getDelayTime(int level, int wave) {
	if (cur_imformation.cur_td_adventure != 0) {
		return level_list[level]["wave"][wave - 1]["delay_time"];
	}
	else {
		return minigame_list[level]["wave"][wave - 1]["delay_time"];
	}
	
}
void spwanZombie(int level, int wave) {
	if (cur_imformation.cur_td_adventure != 0) {
		for (auto& enemy : level_list[level]["wave"][wave - 1]["enemies"]) {
			std::string temp = enemy.template get<std::string>();
			zombie_manager.call_zombie(temp, rand() % 5, rand() % 3 + 9, list_f_frame.at(temp));

		}
	}
	else {
		for (auto& enemy : minigame_list[level]["wave"][wave - 1]["enemies"]) {
			std::string temp = enemy.template get<std::string>();
			zombie_manager.call_zombie(temp, rand() % 5, rand() % 3 + 9, list_f_frame.at(temp));

		}
	}
	
}
