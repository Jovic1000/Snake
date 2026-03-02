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

	void CreateSnake();
	void Render();
	void AddToBody();

	// movement
	void MoveUP();
	void MoveDOWN();
	void MoveLEFT();
	void MoveRIGHT();

	SnakeHead* GetHead();

	Snake(SHAPE shape);

private:

	SHAPE m_currentShape;
	int m_snakeLength;
	SnakeHead* m_head;
	std::deque<SnakeSection> m_snakeSections;

};

