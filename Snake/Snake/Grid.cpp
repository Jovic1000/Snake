#include "Grid.h"
#include "Game.h"
#include <raylib.h>

int numberOfApples = 5;

void Grid::Render()
{
	
	BeginDrawing();

	ClearBackground(GREEN);

	m_apples.begin()->Generate();

	EndDrawing();
	
}



void Grid::Update()
{
	
}

void Grid::FillApples()
{
	

	for (int i = 0; i < numberOfApples; i++)
	{
		Apple* newApple = new Apple();

		m_apples.push_back(*newApple);
	}
}

bool Grid::compareAppleLocations(int x, int y)
{
	
	if (m_apples.begin()->GetLocationX() == x && m_apples.begin()->GetLocationY() == y)
	{
		return false;
	}
	return true;
}

Grid::Grid() : m_apples()
{
}

