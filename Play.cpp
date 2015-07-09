#include "Play.h"


Play::Play(void)
{
	for(int i=0; i<APPLEMAX; i++){
		apple[i] = new Apple(partx[(id-1)%4], 20+GetRand(180));
	}

	for(int i=0; i<MELONMAX; i++){
		melon[i] = new Melon(partx[(id-1)%4], 20+GetRand(180));
	}

	instance = this;
}


Play::~Play(void)
{
	for(int i=0; i<APPLEMAX; i++){
		delete apple[i];
	}
	for(int i=0; i<MELONMAX; i++){
		delete melon[i];
	}
}

void Play::Init()
{
	
}

void Play::UpDate()
{
	/*clsDx();
	printfDx("%d\n", GetNowCount()-starttime);*/
	for(int i=0; i<APPLEMAX; i++){
		if(apple[i]->HitJudge() == true){
			if(apple[i]->GetExist() == true){
				score.Hit();
			}
			apple[i]->Hit();
				
		}
	}

	for(int i=0; i<MELONMAX; i++){
		if(melon[i]->HitJudge() == true){
			//melon[i]->SetSpeed(0);
			//melon[i]->SetHoldStart(GetNowCount());
			if(melon[i]->GetExist() == true){
				score.Hit();
			}
			melon[i]->Hit();
				
		}
	}
	/*for(int i=0; i<4; i++){
		if(GetRand(100) == 1 && apple[i]->GetExist() == false){
			apple[i]->Init(partx[i], 20+GetRand(180));
		}
		apple[i]->UpDate();
	}*/
	clsDx();
	printfDx("%d\n", GetNowCount()-starttime);
	for(int i=0;i<musicfiles.size();i++){
		
		if(GetNowCount()-starttime >= musicfiles[i].ms && !musicfiles[i].yet){
			musicfiles[i].yet = true;
			if(musicfiles[i].id <= 4){
				if(apple[i%APPLEMAX]->GetExist() == false){
					apple[i%APPLEMAX]->Init(partx[(musicfiles[i].id-1)%4], musicfiles[i].y);
				}
			} else if(musicfiles[i].id > 4 && musicfiles[i].id <= 8){
				if(melon[i%MELONMAX]->GetExist() == false){
					melon[i%MELONMAX]->Init(partx[(musicfiles[i].id-1)%4], musicfiles[i].y);
				}
			}
		}
	}
	for(int i=0; i<APPLEMAX; i++){
		apple[i]->UpDate();
	}
	for(int i=0; i<MELONMAX; i++){
		melon[i]->UpDate();
	}
}

void Play::Loadfile(char* filename){
	std::ifstream _ifile(filename);
	
	while(!_ifile.eof()){
		Musicfile _musicfile;
		_ifile >> _musicfile.id >> _musicfile.y >> _musicfile.ms >> _musicfile.holdtime;
		_musicfile.yet = false;
		musicfiles.push_back(_musicfile);
	}
	_ifile.close();
	starttime = GetNowCount();
}

void Play::Draw()
{
	for(int i=0; i<APPLEMAX; i++){
		apple[i]->Draw();
	}
	for(int i=0; i<MELONMAX; i++){
		melon[i]->Draw();
	}
	score.Draw();
	//apple[0]->score.Draw();
}

void Play::SoundPlay()
{
	PlaySoundMem(sound_h, DX_PLAYTYPE_BACK);
}


void Play::SoundStop()
{
	StopSoundMem(sound_h);
}

bool Play::isPlaying()
{
	if(CheckSoundMem(sound_h) == 1){
		return true;
	} else{
		return false;
	}
}

void Play::HitJudge()
{


}

void Play::addScore(void)
{
	score.Hit();
}

void Play::setCombo(int combo)
{
	score.SetCombo(combo);
}

void Play::SetMusic(int playsound){
	this->sound_h = playsound;
}

Play* Play::getInstance(void)
{
	return instance;
}

Play* Play::instance = NULL;