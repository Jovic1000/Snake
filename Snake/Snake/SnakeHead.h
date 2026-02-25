#pragma once
#include "SnakeSection.h"

class SnakeHead : public SnakeSection
{
public:

	void Render();
	int GetLocationX();
	int GetLocationY();

private:

	int m_locationX;
	int m_locationY;
};

