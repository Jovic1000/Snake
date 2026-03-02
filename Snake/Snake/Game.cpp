#include "Game.h"
#include <iostream>
#include <raylib.h>

// Window Dimensions
int GRID_HIGHT = 600;
int GRID_WIDTH = 500;

void Game::StartUp()
{

	// makes the window resizable
	/*SetConfigFlags(FLAG_WINDOW_RESIZABLE);*/

	// create main window & Set FPS to 60
	InitWindow(GRID_WIDTH, GRID_HIGHT, " ('TEST') Snake Game! ");
	SetTargetFPS(3);
	m_snake->CreateSnake();
	m_grid->FillApples();


}

void Game::Update(char input)
{

	switch (input)
	{
	case('W'):
		std::cout << "TESTER OUTPUT: <Snake Move UP>" << std::endl;
		m_currentInput = input;
		break;

	case('S'):
		std::cout << "TESTER OUTPUT: <Snake Move DOWN>" << std::endl;
		m_currentInput = input;
		break;

	case('A'):
		std::cout << "TESTER OUTPUT: <Snake Move LEFT>" << std::endl;
		m_currentInput = input;
		break;

	case('D'):
		std::cout << "TESTER OUTPUT: <Snake Move RIGHT>" << std::endl;
		m_currentInput = input;
		break;

	default:
		break;
	}

	switch (m_currentInput)
	{
	case('W'):
		std::cout << "SYSTEM INFO: <Snake has moved UP>" << std::endl;
		m_snake->MoveUP();
		break;

	case('S'):
		std::cout << "SYSTEM INFO: <Snake has moved DOWN>" << std::endl;
		m_snake->MoveDOWN();
		break;

	case('A'):
		std::cout << "SYSTEM INFO: <Snake has moved LEFT>" << std::endl;
		m_snake->MoveLEFT();
		break;

	case('D'):
		std::cout << "SYSTEM INFO: <Snake has moved RIGHT>" << std::endl;
		m_snake->MoveRIGHT();
		break;

	default:
		break;
	}

	CheckOverlap();
	Render();
}
void Game::Render()
{

	BeginDrawing();

	DrawRectangle(0, 500, 500, 100, BLACK);

	m_grid->Render();
	m_snake->Render();
	
	DrawFPS(50,550);
	
	DrawText(TextFormat("Score:%03i", m_score), 370, 550, 20, WHITE);
	DrawText(TextFormat("SNAKE"), 220, 550, 20, WHITE);

	EndDrawing();
	
}

void Game::CheckOverlap()
{
	for (Apple apple : m_grid->GetApples())
	{
		// checks if the location of the snakes head is equal to any of the apples
		if (m_snake->GetHead()->GetLocationX() == apple.GetLocationX() && m_snake->GetHead()->GetLocationY() == apple.GetLocationY())
		{
			m_grid->Eat(apple);
		}
	}

	if (m_grid->GetApples().size() != 5)
	{
		m_grid->AddApple();
	}

}

Game::Game(SHAPE snakeShape) : m_snake(new Snake(snakeShape)), m_grid(new Grid()), m_score(1), m_currentInput(NULL)
{
}
