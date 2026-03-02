#pragma once
#include "Snake.h"
#include "Grid.h"

enum END_STATE
{
	VICTORY = 0,
	LOSE = 1
};

class Game
{
public:

	void StartUp();
	void Update(char input);
	void Render();
	bool IsGameOver();

	void CheckOverlap();


	Game(SHAPE snakeShape);

private:

	char m_currentInput;
	int m_score;

	END_STATE m_endState;

	Snake* m_snake;
	Grid* m_grid;

};

