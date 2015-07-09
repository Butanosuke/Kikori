#include "Score.h"


Score::Score(void)
{
	color = GetColor(0, 0, 0);
	score = 0;
	combo = 0;
}


Score::~Score(void)
{
}

void Score::Draw()
{
	DrawFormatString(300, 400, color, "スコア：%d", score);
	DrawFormatString(300, 450, color, "コンボ：%d", combo);
}

void Score::Hit()
{
	combo++;
	score+=(10*combo);
}
