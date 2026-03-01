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

	void SetPreLocation(int x, int y);
	int GetPreLocationX();
	int GetPreLocationY();

	SnakeSection(SHAPE shape);

private:

	int m_locationX;
	int m_locationY;
	int m_preLocationX;
	int m_preLocationY;
	SHAPE m_shape;
};

