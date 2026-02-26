#pragma once
#include "SnakeHead.h"
#include <stack>


enum SECTION_TYPE
{
	HEAD = 0,
	BODY = 1
};

class Snake
{
public:

	void Render();
	void AddToBody();

	Snake(SHAPE shape);

private:

	SHAPE m_currentShape;
	int m_snakeLength;
	SnakeHead* m_head;
	std::stack<SnakeSection>* m_snakeSections;

};

