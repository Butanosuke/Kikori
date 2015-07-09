#include "FallingObject.h"


FallingObject::FallingObject(void)
{
	this->speed = SPEED;
	this->starttime = GetNowCount();
	this->sound_h = LoadSoundMem("music/bomb.mp3");
	this->hit_area = HIT_AREA;
	this->color = GetColor(0, 255, 0);
	SetMouseDispFlag( TRUE );
	exist=true;
	once=false;
}


FallingObject::~FallingObject(void)
{
}

void FallingObject::Init(int x, int y)
{
	this->x = x;
	this->y = y;
	this->starttime = GetNowCount();
	exist=true;
	once=false;
}

void FallingObject::UpDate()
{
	if(exist){
		this->y+=speed;
		if(GetNowCount() - starttime > 3000){
			exist = false;
			once = false;
			score.SetCombo(0);
			/*Play* play = Play::getInstance();
			play->setCombo(0);*/
		}
	}
}

void FallingObject::Draw()
{
	if(exist == true){
		DrawGraph(this->x-33, this->y-37, graphic_h, true);
		
	}
}

void FallingObject::Hit()
{
	if(!once){
		PlaySoundMem(sound_h, DX_PLAYTYPE_BACK, true);
		exist = false;
		once = true;
		//score.Hit();
	}
}

bool FallingObject::HitJudge()
{
    MouseInput = GetMouseInput();
    if(( MouseInput & MOUSE_INPUT_LEFT ) == 1 ){
		GetMousePoint(&mousex, &mousey);
		if(sqrt(pow(((double)mousex-x), 2)+pow(((double)mousey-y), 2)) <= 30){
			return true;
		}else{
			return false;
		}
	}
}
