#include "SnakeHead.h"
#include <raylib.h>
#include <iostream>

void SnakeHead::Render()
{

	switch (GetShape())
	{
	case(CIRCLE):
		DrawCircle(m_locationX, m_locationY, 50, RED);
		DrawCircle(m_locationX, m_locationY, 20, WHITE);
		DrawCircle(m_locationX, m_locationY, 10, BLACK);
		break;

	case(SQUARE):
		DrawRectangle(m_locationX, m_locationX, 50, 50, RED);
		DrawRectangle(m_locationX, m_locationX, 20, 20, WHITE);
		DrawRectangle(m_locationX, m_locationX, 10, 10, BLACK);
		break;

	default:
		std::cout << std::endl << "!!Shape ERROR - Check SnakeHead.h / SnakeHead.cpp!!" << std::endl << std::endl;
		break;
	}
}

int SnakeHead::GetLocationX()
{
	return m_locationX;
}

int SnakeHead::GetLocationY()
{
	return m_locationY;
}

void SnakeHead::SetLocation(int x, int y)
{
	m_locationX = x;
	m_locationY = y;
}
