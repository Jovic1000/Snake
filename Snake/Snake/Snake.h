#pragma once
#include "SnakeHead.h"
#include <stack>


enum SECTION_TYPE
{
	HEAD,
	BODY
};

class Snake
{
public:

	void SetUp();
	void Render();

	Snake(SHAPE shape);

private:

	int m_snakeLength;
	SnakeHead* m_head;
	std::stack<SnakeSection>* m_snakeSections;

};

