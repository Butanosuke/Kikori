#pragma once
#include "Dxlib.h"
#include "define.h"
//#include "Play.h"
#include "Score.h"
#include <cmath>

class FallingObject
{
protected:
	int x;
	int y;
	int id;
	int speed;
	int startx;
	int starty;
	int starttime;
	int graphic_h;
	int sound_h;
	int mousex;
	int mousey;
	int MouseInput;
	int hit_area;
	bool once;
	bool exist;
	Score score;
	int color;

public:
	FallingObject(void);
	~FallingObject(void);
//	virtual void Init(int, int, double)=0;
	//virtual void UpDate()=0;
	//virtual void Draw();
	//virtual void Spawn(int, int, double)=0;

	
	int GetX(){ return x;}
	int GetY(){ return y;}

	void SetExist(bool ex){ exist = ex;}
	int GetStartX(){ return startx;}
	int GetStartY(){ return starty;}
	int GetStartTime(){ return starttime;}
	bool GetExist(){ return exist;}
	void Init(int, int);
	void UpDate();
	void Draw();
	
	void Hit();
	bool HitJudge();
};

