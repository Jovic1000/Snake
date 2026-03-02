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
	m_grid->FillApples(m_snake);


}

void Game::Update(char input)
{
	
	if (!IsGameOver())
	{
		// checks if the players input is a direction the snake can go in and then sets the input to stay as that direction
		switch (input)
		{
		case('W'):
			if (m_currentInput != 'S')
			{
				std::cout << "TESTER OUTPUT: <Snake Move UP>" << std::endl;
				m_currentInput = input;
			}
			break;

		case('S'):
			if (m_currentInput != 'W')
			{
				std::cout << "TESTER OUTPUT: <Snake Move DOWN>" << std::endl;
				m_currentInput = input;
			}
			break;

		case('A'):
			if (m_currentInput != 'D')
			{
				std::cout << "TESTER OUTPUT: <Snake Move LEFT>" << std::endl;
				m_currentInput = input;
			}
			break;

		case('D'):
			if (m_currentInput != 'A')
			{
				std::cout << "TESTER OUTPUT: <Snake Move RIGHT>" << std::endl;
				m_currentInput = input;
			}
			break;

		default:
			break;
		}

		// the movement for the snake
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


		// the visuals and checks after the movement
		Render();
		CheckOverlap();
		
	}
	else
	{
		// Game Over Screens
		BeginDrawing();

		if (m_endState == VICTORY)
		{
			ClearBackground(GOLD);
			DrawText(TextFormat("CONGRATULATIONS!\n        YOU WIN\n    Your Score: %02i", m_score), 100, 250, 30, WHITE);
		}
		else if (m_endState == LOSE)
		{
			ClearBackground(RED);
			DrawText(TextFormat("           BOOOO!\n         YOU LOSE\n      Your Score: %02i", m_score), 60, 250, 30, BLACK);
		}
		else
		{
			std::cout << "!END_STATE_ERROR! - CHECK Game.cpp/Game.h" << std::endl;
		}

		EndDrawing();
	}
}
void Game::Render()
{

	BeginDrawing();

	
	// game screen
	m_grid->Render();
	m_snake->Render();
	

	// score board 
	DrawRectangle(0, 500, 500, 100, BLACK);
	DrawFPS(50,550);
	DrawText(TextFormat("Score:%02i", m_score), 370, 550, 20, WHITE);
	DrawText("SNAKE", 220, 550, 20, WHITE);

	EndDrawing();
	
}

bool Game::IsGameOver()
{
	if (m_snake->GetLength() == 24)
	{
		m_endState = VICTORY;
		return true;
	}
	else if (m_snake->GetHead()->GetLocationX() < 50 || m_snake->GetHead()->GetLocationX() > 450)
	{
		m_endState = LOSE;
		return true;
	}
	else if (m_snake->GetHead()->GetLocationY() < 50 || m_snake->GetHead()->GetLocationY() > 450)
	{
		m_endState = LOSE;
		return true;
	}
	else
	{
		// loops through all the sections of the snake to see if they overlap with the head
		for (SnakeSection section : m_snake->GetBody())
		{
			if ((section.GetLocationX() == m_snake->GetHead()->GetLocationX()) && (section.GetLocationY() == m_snake->GetHead()->GetLocationY()))
			{
				m_endState = LOSE;
				return true;
			}
		}


		return false;

	}

}



void Game::CheckOverlap()
{

	int snakeX = m_snake->GetHead()->GetLocationX();
	int snakeY = m_snake->GetHead()->GetLocationY();

	bool loop = true;
	int count = 0;

	while (loop)
	{
		Apple tempApple = m_grid->GetPtrApples()->front();

		// checks if the location of the snakes head is equal to any of the apples
		if (snakeX == tempApple.GetLocationX() && snakeY == tempApple.GetLocationY())
		{
			m_grid->Eat(tempApple);
			m_score++;
			m_snake->AddToBody();
			loop = false;
		}
		else if (count == 5)
		{
			loop = false;
		}
		else
		{
			m_grid->GetPtrApples()->pop_front();

			m_grid->GetPtrApples()->push_back(tempApple);
			
			count++;
		}
	}
	

	if (m_grid->GetPtrApples()->size() != 5)
	{
		m_grid->AddApple(m_snake);
	}

}

Game::Game(SHAPE snakeShape) : m_snake(new Snake(snakeShape)), m_grid(new Grid()), m_score(1), m_currentInput(NULL), m_endState()
{
}
