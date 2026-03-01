#pragma once
#include "SnakeSection.h"

class SnakeHead
{
public:

	void Render();
	SHAPE GetCurrentShape();

	int GetLocationX();
	int GetLocationY();
	int GetPreLocationX();
	int GetPreLocationY();
	void SetLocation(int x, int y);
	void SetPreLocation(int x, int y);

	SnakeHead(SHAPE shape);

private:

	SHAPE m_currentShape;
	int m_locationX;
	int m_locationY;
	int m_preLocationX;
	int m_preLocationY;
};

