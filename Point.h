#pragma once
class Point
{
private:
	int mX;
	int mY;
	int mZ;

public:
	Point(int, int, int);
	~Point();

	int X();
	int Y();
	int Z();
};

