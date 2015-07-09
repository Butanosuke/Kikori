#pragma once
#include "Apple.h"
#include "Melon.h"
#include "Tree.h"
#include "Hand.h"
#include "Score.h"
//#include <cmath>
#include <fstream>
#include <vector>

class Play
{
private:
	int id;
	Apple* apple[APPLEMAX];
	Melon* melon[MELONMAX];
	Tree tree;
	Hand hand;
	Score score;
	int MouseInput;
	int mousex;
	int mousey;
	int sound_h;
	int starttime;
	static Play* instance;

	struct Musicfile{
		int id;
		int ms;
		int y;
		int holdtime;
		bool yet;
	};
	std::vector<Musicfile> musicfiles;

public:
	Play(void);
	~Play(void);
	void Init();
	void UpDate();
	void Draw();
	void HitJudge();
	void SoundPlay();
	void SoundStop();
	bool isPlaying();
	void addScore(void);
	void setCombo(int combo);
	void SetMusic(int playsound);
	void Loadfile(char* filename);

	static Play* getInstance(void);
};

