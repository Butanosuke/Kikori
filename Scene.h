#pragma once
#include "Opening.h"
#include "Play.h"
#include "MusicSelect.h"
#include "Result.h"

class Scene
{
private:
	Opening Scene_op;
	Play Scene_play;
	MusicSelect Scene_select;
	Result Scene_result;

public:
	Scene(void);
	virtual ~Scene(void);
};

