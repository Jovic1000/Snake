#include "SnakeHead.h"
#include <raylib.h>
#include <iostream>

void SnakeHead::Render()
{

	switch (GetShape())
	{
	case(CIRCLE):
		DrawCircle(m_locationX, m_locationY, 100, RED);
		DrawCircle(m_locationX, m_locationY, 60, WHITE);
		DrawCircle(m_locationX, m_locationY, 30, BLACK);
		break;

	case(SQUARE):
		DrawRectangle(m_locationX, m_locationX, 100, 100, RED);
		DrawRectangle(m_locationX, m_locationX, 60, 60, WHITE);
		DrawRectangle(m_locationX, m_locationX, 30, 30, BLACK);
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
