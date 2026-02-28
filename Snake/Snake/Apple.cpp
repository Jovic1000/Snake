#include "Apple.h"
#include "Grid.h"
#include <iostream>
#include <raylib.h>

void Apple::Generate(Grid &grid)
{
	DrawCircle(m_LocationX, m_LocationY, 50, RED);
	DrawCircle(m_LocationX + 10, m_LocationY + 10, 30, PINK);


	// debug:
	/*std::cout << "Apple Location  X:" << m_LocationX << " | Y:" << m_LocationY << std::endl;*/
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