#pragma once
#include "DxLib.h"

class Score
{
private:
	int score;
	int combo;
	int color;
	int MaxCombo;
public:
	Score(void);
	~Score(void);
	
	void SetCombo(int com){ combo = com;}
	void Draw();
	void Hit();
	int GetScore(){ return score;}
	int GetMaxCombo(){ return combo;}
};

