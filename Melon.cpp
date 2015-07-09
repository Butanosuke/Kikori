#include "Melon.h"


Melon::Melon(void)
{
	this->graphic_h = LoadGraph("picture/melon.bmp");
}

Melon::Melon(int x, int y)
{
	this->graphic_h = LoadGraph("picture/melon.bmp");
}

Melon::~Melon(void)
{
}

//void Melon::UpDate()
//{
//}
//
//void Melon::Draw()
//{
//}