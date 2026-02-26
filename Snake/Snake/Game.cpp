#include "Game.h"
#include <raylib.h>

// Window Dimensions
int GRID_HIGHT = 1000;
int GRID_WIDTH = 1000;

void Game::StartUp()
{

	// create main window & Set FPS to 60
	InitWindow(GRID_WIDTH, GRID_HIGHT, " ('TEST') Snake Game! ");
	SetTargetFPS(60);
	m_grid->FillApples();


}

void Game::Update()
{
	Render();
}
void Game::Render()
{
	m_grid->Render();
}

Game::Game(SHAPE snakeShape) : m_snake(new Snake(snakeShape)), m_grid(new Grid())
{
}
