#pragma once


enum SHAPE
{
	CIRCLE = 0,
	SQUARE = 1
};

class SnakeSection
{
public:

	void Render();
	SHAPE GetShape();
	void SetLocation(int x, int y);
	int GetLocationX();
	int GetLocationY();
	

	SnakeSection(SHAPE shape);

private:

	int m_locationX;
	int m_locationY;
	SHAPE m_shape;
};

