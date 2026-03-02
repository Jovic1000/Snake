#include "Grid.h"
#include "Game.h"
#include "Snake.h"
#include <iostream>
#include <algorithm>
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

void Grid::FillApples(Snake* snake)
{
	

	for (int i = 0; i < numberOfApples; i++)
	{
		Apple* newApple = new Apple();


		do
		{
			newApple->SetLcoation((((rand() % 5) + 1) * 100) - 50,
				                 (((rand() % 5) + 1) * 100) - 50);

		} while (CompareAppleLocations(newApple->GetLocationX(), newApple->GetLocationY(), snake));

		m_apples.push_back(*newApple);
	}


}

void Grid::Eat(Apple apple)
{
	bool loop = true;
	while (loop)
	{
		Apple tempApple = m_apples.front();

		if (tempApple.GetLocationX() == apple.GetLocationX() && tempApple.GetLocationY() == apple.GetLocationY())
		{
			loop = false;
		}
		else
		{
			Apple newApple = m_apples.front();

			m_apples.pop_front();

			m_apples.push_back(newApple);
		}
	}

	m_apples.pop_front();
}

void Grid::AddApple(Snake* snake)
{
	Apple* newApple = new Apple();
	
	do
	{ 
		if (snake->GetLength() == 44)
		{
			std::cout << "hi";
		}
		newApple->SetLcoation((((rand() % 5) + 1) * 100) - 50,
			(((rand() % 5) + 1) * 100) - 50);
		                                                                                                       
	} while (CompareAppleLocations(newApple->GetLocationX(), newApple->GetLocationY(), snake)); // <- max amount of spaces in the grid

	if (snake->GetLength() < 20)
	{
		m_apples.push_back(*newApple);
	}
}

bool Grid::CompareAppleLocations(int x, int y, Snake* snake)
{
	
	for (int i = 50; i < 1000; i += 100)
	{
		for (int j = 50; j < 1000; j += 100)
		{
			for (Apple apple : m_apples)
			{
				if ((apple.GetLocationX() == x && apple.GetLocationY() == y) || (snake->CompareBodyLocations(x,y)) || (snake->GetHead()->GetLocationX() == x && snake->GetHead()->GetLocationY() == y))
				{
					return true;
				}
			}
		}
	}

	return false;
}

std::list<Apple>* Grid::GetPtrApples()
{
	return &m_apples;
}

Grid::Grid() : m_apples()
{
}

