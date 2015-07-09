#include "Result.h"
#include "Score.h"

Result::Result(void)
{ 
	score=0;
	MaxCombo=0;
	a = LoadGraph("picture/a.jpg");
	b = LoadGraph("picture/b.jpg");
	c = LoadGraph("picture/c.jpg");

	apple.Init(500, 200);
}

Result::~Result(void)
{
}

void Result::Update(){
	if(score<HighScore){
		score=score+10;
	}
	apple.UpDate();
	if(apple.GetExist() == false){
		apple.Init(500, 200);
	}
}

void Result::Draw(){
	if(HighScore<3000){
		DrawGraph(100, 100, c, 0);
	}else if(HighScore<5000){
		DrawGraph(100, 100, b, 0);
	}else{
		DrawGraph(100, 100, a, 0);
	}
	DrawFormatString(100, 200, GetColor( 255, 255, 255 ), "�X�R�A�F%d", score);
	DrawFormatString(100, 250, GetColor( 255, 255, 255 ),"�R���{�F%d", MaxCombo);
	DrawFormatString(100, 300, GetColor( 255, 255, 255 ), "Perfect�F%d", HighScore);
	DrawFormatString(100, 350, GetColor( 255, 255, 255 ),"Good�F%d", MaxCombo);
	DrawFormatString(100, 400, GetColor( 255, 255, 255 ), "Bad�F%d", HighScore);
	apple.Draw();
}


bool Result::HitJudge()
{
	if(apple.HitJudge() == true){
		apple.Hit();
		return true;
	} else{
		return false;
	}
}