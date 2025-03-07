#include "base_func.h"
#include "load_pic.h"

LoadPIC::LoadPIC() {
	name_path = "";
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = 0;
	rect_.h = 0;
}
LoadPIC::~LoadPIC() {

	Free();

}

bool LoadPIC::LoadImg(std::string path, SDL_Renderer* screen) {
	if (textures.find(path) != textures.end()) {
		return true;
	}
	SDL_Texture* new_texture = NULL;
	SDL_Surface* load_surface = IMG_Load(path.c_str());
	
	if (load_surface != NULL) {
		//SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, COLOR_R, COLOR_G, COLOR_B));
		new_texture = SDL_CreateTextureFromSurface(screen, load_surface);
		if (new_texture != NULL) {
			rect_.w = load_surface->w;
			rect_.h = load_surface->h;
		}
		SDL_FreeSurface(load_surface);
	
	
	}
	textures[path] = new_texture;
	return textures[name_path] != NULL;
}
void LoadPIC::Render(SDL_Renderer* render, const SDL_Rect* clip) {
	SDL_Rect renderquad = { rect_.x,rect_.y,rect_.w ,rect_.h };
	SDL_RenderCopy(render, textures[name_path], clip, &renderquad);
}
void LoadPIC::Render_2(SDL_Renderer* render, const SDL_Rect* clip, const SDL_Rect* clip_2, const SDL_Point* center, double angle) {
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	SDL_RenderCopyEx(render, textures[name_path], clip_2, clip, angle, center, flip);
}

void LoadPIC::Free() {
	if (textures[name_path] != NULL) {
		SDL_DestroyTexture(textures[name_path]);
		textures[name_path] = NULL;
		rect_.w = 0;
		rect_.h = 0;
	}
}

//khi dùng xx.render thì trong lớp của xx có textures[name_path], ý là nó đc xác định r