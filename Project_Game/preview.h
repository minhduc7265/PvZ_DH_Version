#pragma once
#ifndef PREVIEW_H_
#define PREVIEW_H_
#include "base_func.h"

class Preview {
public:
	Preview();
	~Preview();
	int getPosX() const;
	int getPosY() const;
	void setPos(int posX, int posY);
	void setCurFrame(int cf);
	int getCurFrame() const;
	void setNumFrame(int nf);
	int getNumFrame() const;
	void remoteFrame();
	void Render(SDL_Renderer* render, SDL_Rect* clip, SDL_Texture* texture, int z, int t);

private:
	int posX;
	int posY;
	int cur_frame;
	int num_frame;




};


#endif // !PREVIEW_H_
