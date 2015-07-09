#pragma once
#include "MusicApple.h"

class MusicSelect
{
private:
	MusicApple* ma[3];
	int sound_h;
	char* musicfile;
public:
	MusicSelect(void);
	~MusicSelect(void);
	void Init();
	void UpDate();
	void Draw();

	int GetMusic(){ return sound_h;}
	char* GetMusicfile(){ return musicfile;}
	bool HitJudge();
};

