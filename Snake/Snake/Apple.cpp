#include "Apple.h"
#include "Grid.h"
#include <iostream>
#include <raylib.h>

void Apple::Generate()
{
	Grid tempGrid;
	do
	{
		m_LocationX = (((rand() % 10) + 1) * 10) - 50;
		m_LocationY = (((rand() % 10) + 1) * 10) - 50;

	} while (tempGrid.compareAppleLocations(m_LocationX, m_LocationY));
	
	


	DrawCircle(m_LocationX, m_LocationY, 100, RED);
	DrawCircle(m_LocationX + 20, m_LocationY + 20, 60, PINK);
}

void Apple::SetLcoation(int x, int y)
{
	m_LocationX = x;
	m_LocationY = y;
}

int Apple::GetLocationX()
{
	return m_LocationX;
}

int Apple::GetLocationY()
{
	return m_LocationY;
}