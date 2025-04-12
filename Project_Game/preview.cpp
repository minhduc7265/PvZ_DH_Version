#include "preview.h"

Preview::Preview() {
	posX = 0;
	posY = 0;
	cur_frame = 0;
	num_frame = 0;
}
Preview::~Preview() {
	posX = 0;
	posY = 0;
	cur_frame = 0;
	num_frame = 0;
}
int Preview::getPosX() const {
	return posX;
}
int Preview::getPosY() const {
	return posY;
}
void Preview::setPos(int posX, int posY) {
	this->posX = posX;
	this->posY = posY;
}
void Preview::setCurFrame(int cf) {
	cur_frame = cf;
}
int Preview::getCurFrame() const {
	return cur_frame;
}
void Preview::setNumFrame(int nf) {
	num_frame = nf;
}
int Preview::getNumFrame() const {
	return num_frame;
}
void Preview::remoteFrame() {
	cur_frame++;
	if (cur_frame >= num_frame) {
		cur_frame = 0;
	}
}
void Preview::Render(SDL_Renderer* render, SDL_Rect* clip, SDL_Texture* texture, int z, int t) {
	SDL_Rect renderquad = { posX,posY,z,t };
	SDL_RenderCopy(render, texture, clip, &renderquad);
}