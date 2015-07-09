#include "MusicSelect.h"


MusicSelect::MusicSelect(void)
{
	ma[0] = new MusicApple(330, 100, 0);
	ma[1] = new MusicApple(200, 150, 1);
	ma[2] = new MusicApple(460, 150, 2);
}


MusicSelect::~MusicSelect(void)
{
	for(int i=0; i<3; i++){
		delete ma[i];
	}
}

void MusicSelect::Init()
{
}

void MusicSelect::UpDate()
{
	for(int i=0; i<3; i++){
		ma[i]->UpDate();
		if(ma[i]->HitJudge() == true){
			this->sound_h = ma[i]->GetMusic();
			this->musicfile = ma[i]->GetMusicfile();
		}
	}

}

void MusicSelect::Draw()
{
	for(int i=0; i<3; i++){
		ma[i]->Draw();
	}
}

bool MusicSelect::HitJudge()
{
	for(int i=0; i<3; i++){
		if(ma[i]->HitJudge() == true){
			return true;
		}
	}
	return false;
}