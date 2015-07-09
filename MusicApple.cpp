#include "MusicApple.h"


MusicApple::MusicApple(int x, int y, int num)
{
	this->x = x;
	this->y = y;
	this->num = num;
	if(this->num == 0){
		this->graphic_h_s = LoadGraph("picture/small_onestar.bmp");
		this->graphic_h_b = LoadGraph("picture/ultrasoul_apple2.bmp");
		this->sound_h = LoadSoundMem("music/ultrasoul.mp3");
		this->sound_h_demo = LoadSoundMem("music/ultrasoul_mini.mp3");
		this->musicfile = "ultrasoul_score.txt";
	}
	else if(this->num == 1){
		this->graphic_h_s = LoadGraph("picture/small_twostar.bmp");
		this->graphic_h_b = LoadGraph("picture/koi_apple.bmp");
		this->sound_h = LoadSoundMem("music/koi.mp3");
		this->sound_h_demo = LoadSoundMem("music/koi_mini.mp3");
		this->musicfile = "koi_score.txt";
	}
	else if(this->num == 2){
		this->graphic_h_s = LoadGraph("picture/small_threestar.bmp");
		this->graphic_h_b = LoadGraph("picture/johnetsu_apple.bmp");
		this->sound_h = LoadSoundMem("music/johnetsu.mp3");
		this->sound_h_demo = LoadSoundMem("music/johnetsu_mini.mp3");
		this->musicfile = "johnetsu_score.txt";
	}
	this->hit_area = MUSICAPPLE_HIT_AREA;
	SetMouseDispFlag( TRUE );

	this->color = GetColor(0, 0, 255);

	once = false;
}


MusicApple::~MusicApple(void)
{
}

void MusicApple::Draw()
{
	GetMousePoint(&mousex, &mousey);
	if(sqrt(pow(((double)mousex-x), 2)+pow(((double)mousey-y), 2)) <= hit_area){
		hit_area = 90;
		//DrawCircle(this->x, this->y, hit_area, this->color, true);
		DrawGraph(this->x-100, this->y-108, graphic_h_b, true);
	}else{
		hit_area = 30;
		//DrawCircle(this->x, this->y, MUSICAPPLE_HIT_AREA, this->color, true);
		DrawGraph(this->x-34, this->y-37, graphic_h_s, true);
	}
	
	//DrawCircle(this->x, this->y, 30, this->color, true);
}

void MusicApple::UpDate()
{
	if(sqrt(pow(((double)mousex-x), 2)+pow(((double)mousey-y), 2)) <= hit_area){
		if(!once){
			PlaySoundMem(sound_h_demo, DX_PLAYTYPE_LOOP);
			once = true;
		}
	}else{
		once = false;
		StopSoundMem(sound_h_demo);
	}
}

void MusicApple::Hit()
{
}

bool MusicApple::HitJudge()
{
	 MouseInput = GetMouseInput();
    if(( MouseInput & MOUSE_INPUT_LEFT ) == 1 ){
		GetMousePoint(&mousex, &mousey);
		if(sqrt(pow(((double)mousex-x), 2)+pow(((double)mousey-y), 2)) <= hit_area){
			StopSoundMem(sound_h_demo);
			return true;
		}else{
			return false;
		}
	}
}