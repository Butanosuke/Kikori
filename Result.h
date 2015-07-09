#pragma once
#include "Apple.h"
#include "Hand.h"
#include "Score.h"
class Result
{
private:
	int HighScore;
	int MaxCombo;
	int score;
	int a;
	int b;
	int c;
	Apple apple;
public:
	Result(void);
	~Result(void);
	void Draw();
	void Update();
	bool HitJudge();
};

