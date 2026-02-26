#pragma once
#include "Snake.h"
#include "Grid.h"

class Game
{
public:

	void StartUp();
	void Update();
	void Render();


	Game(SHAPE snakeShape);

private:

	Snake* m_snake;
	Grid* m_grid;

};

