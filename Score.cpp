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
	DrawFormatString(300, 400, color, "�X�R�A�F%d", score);
	DrawFormatString(300, 450, color, "�R���{�F%d", combo);
}

void Score::Hit()
{
	combo++;
	score+=(10*combo);
}
