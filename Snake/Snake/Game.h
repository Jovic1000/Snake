#pragma once
#include "Snake.h"
#include "Grid.h"

class Game
{
public:

	void StartUp();
	void Update(char input);
	void Render();


	Game(SHAPE snakeShape);

private:

	int m_score;
	Snake* m_snake;
	Grid* m_grid;

};

