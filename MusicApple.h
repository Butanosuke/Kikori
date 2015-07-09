#pragma once
#include "DxLib.h"
#include "define.h"
#include <cmath>

class MusicApple
{
private:
	int x;
	int y;
	int num;
	int graphic_h_s, graphic_h_b;
	int sound_h;
	int sound_h_demo;
	char* musicfile;
	int mousex;
	int mousey;
	int MouseInput;
	double hit_area;

	bool once;

	int color;
public:
	MusicApple(int, int, int);
	~MusicApple(void);

	int GetMusic(){ return sound_h;}
	char* GetMusicfile(){ return musicfile;}
	void Draw();
	void UpDate();
	void Hit();
	bool HitJudge();
	
};

