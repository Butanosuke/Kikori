#pragma once
#include "Apple.h"

class Opening
{
private:
	int sound_h;
	Apple apple;
public:
	Opening(void);
	~Opening(void);

	void Draw();
	void UpDate();
	bool HitJudge();
};

