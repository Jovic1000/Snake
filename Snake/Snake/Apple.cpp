#include "Apple.h"
#include "Grid.h"
#include <iostream>
#include <raylib.h>

void Apple::Generate(Grid &grid)
{
	DrawCircle(m_LocationX, m_LocationY, 50, RED);
	DrawCircle(m_LocationX + 20, m_LocationY + 20, 10, PINK);
	DrawRectangle(m_LocationX - 5, m_LocationY - 60, 10, 20, BROWN);
	DrawCircle(m_LocationX - 5, m_LocationY - 40, 7.5f, GREEN);

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