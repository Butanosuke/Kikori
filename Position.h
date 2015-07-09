#pragma once
class Position
{
private:
	int x;
	int y;
public:
	Position(void);
	Position(int x, int y);
	~Position(void);
	int getX(){	return x; }
	int getY(){ return y; }
	int setX(int x){
		this->x = x;
	}
	int setY(int y){
		this->y = y;
	}
};