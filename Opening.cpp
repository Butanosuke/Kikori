#include "Opening.h"


Opening::Opening(void)
{
	apple.Init(330, 200);
}


Opening::~Opening(void)
{
}

void Opening::Draw()
{
	apple.Draw();
}

void Opening::UpDate()
{
	apple.UpDate();
	if(apple.GetExist() == false){
		apple.Init(330, 200);
	}
}

bool Opening::HitJudge()
{
	if(apple.HitJudge() == true){
		apple.Hit();
		return true;
	} else{
		return false;
	}
}