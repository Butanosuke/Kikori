#pragma once
#include "FallingObject.h"
//#include "Score.h"

class Melon :
	public FallingObject
{
private:
	int holdstarttime;
	//int graphic_h;
public:
	Melon(void);
	Melon(int, int);
	~Melon(void);

	//void UpDate();
	//void Draw();
	/*bool HitJudge();*/
	void SetHoldStart(int hs){ holdstarttime = hs;}
	int GetHoldStart(){ return holdstarttime;}
	int SetSpeed(int s){ speed = s;}
};

