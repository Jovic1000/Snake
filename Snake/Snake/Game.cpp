#include "Game.h"
#include <iostream>
#include <string>
#include <raylib.h>

// Window Dimensions
int GRID_HIGHT = 600;
int GRID_WIDTH = 500;

void Game::StartUp()
{

	// makes the window resizable
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);

	// create main window & Set FPS to 60
	InitWindow(GRID_WIDTH, GRID_HIGHT, " ('TEST') Snake Game! ");
	SetTargetFPS(60);
	m_grid->FillApples();


}

void Game::Update(char input)
{
	Render();

	switch (toupper(input))
	{
	case('W'):
		std::cout << "TESTER OUTPUT: <Snake Move UP>" << std::endl;
		break;

	case('S'):
		std::cout << "TESTER OUTPUT: <Snake Move DOWN>" << std::endl;
		break;

	case('A'):
		std::cout << "TESTER OUTPUT: <Snake Move LEFT>" << std::endl;
		break;

	case('D'):
		std::cout << "TESTER OUTPUT: <Snake Move RIGHT>" << std::endl;
		break;

	default:
		break;
	}
}
void Game::Render()
{

	BeginDrawing();

	DrawRectangle(0, 500, 500, 100, BLACK);

	m_grid->Render();
	
	DrawFPS(50,550);
	
	DrawText(TextFormat("Score:%03i", m_score), 370, 550, 20, WHITE);
	DrawText(TextFormat("SNAKE"), 220, 550, 20, WHITE);

	EndDrawing();
	
}

Game::Game(SHAPE snakeShape) : m_snake(new Snake(snakeShape)), m_grid(new Grid()), m_score(1)
{
}
