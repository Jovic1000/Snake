#pragma once


enum SHAPE
{
	CIRCLE,
	SQUARE
};

class SnakeSection
{
public:

	void Render();
	SHAPE GetShape();

	SnakeSection(SHAPE shape);

private:

	int m_locationX;
	int m_locationY;
	SHAPE m_shape;
};

