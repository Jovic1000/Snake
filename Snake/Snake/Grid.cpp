#include "Grid.h"
#include "Game.h"
#include <raylib.h>

int numberOfApples = 5;

void Grid::Render()
{
	ClearBackground(GREEN);

	for (Apple apple : m_apples)
	{
		apple.Generate(*this);
	}
}



void Grid::Update()
{
	
}

void Grid::FillApples()
{
	

	for (int i = 0; i < numberOfApples; i++)
	{
		Apple* newApple = new Apple();

		do
		{
			newApple->SetLcoation((((rand() % 5) + 1) * 100) - 50,
				                 (((rand() % 5) + 1) * 100) - 50);

		} while (CompareAppleLocations(newApple->GetLocationX(), newApple->GetLocationY()));

		m_apples.push_back(*newApple);
	}


}

void Grid::Eat(Apple& apple)
{
	
}

void Grid::AddApple()
{
	Apple* newApple = new Apple();

	newApple->SetLcoation((((rand() % 5) + 1) * 100) - 50,
		                 (((rand() % 5) + 1) * 100) - 50);

	m_apples.push_back(*newApple);
}

bool Grid::CompareAppleLocations(int x, int y)
{
	
	for (Apple apple : m_apples)
	{
		if (apple.GetLocationX() == x && apple.GetLocationY() == y)
		{
			return true;
		}
	}

	return false;
}

std::list<Apple> Grid::GetApples()
{
	return m_apples;
}

Grid::Grid() : m_apples()
{
}

