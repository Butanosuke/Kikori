#pragma once
#include "FallingObject.h"
//#include "define.h"
//#include "Score.h"

class Apple :
	public FallingObject
{
private:
	/*
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
	Score score;
	bool once;*/

public:
	Apple(void);
	Apple(int, int);
	~Apple(void);
	/*
	void SetStartX(int x){ startx = x;}
	void SetStartY(int y){ starty = y;}
	void SetStartTime(int st){ starttime = st;}
	void SetExist(bool ex){ exist = ex;}
	int GetStartX(){ return startx;}
	int GetStartY(){ return starty;}
	int GetStartTime(){ return GetNowCount();}

	void Init(int, int);
	void UpDate();
	void Draw();
	void Hit();
	*/
	/*bool HitJudge();*/
};

