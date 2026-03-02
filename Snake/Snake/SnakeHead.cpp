#include "SnakeHead.h"
#include <raylib.h>
#include <iostream>

void SnakeHead::Render()
{

	switch (m_currentShape)
	{
	case(CIRCLE):
		DrawCircle(m_locationX, m_locationY, 50, DARKBLUE);
		DrawCircle(m_locationX, m_locationY, 20, WHITE);
		DrawCircle(m_locationX, m_locationY, 10, BLACK);
		break;

	case(SQUARE):
		DrawRectangle(m_locationX - 50, m_locationY - 50, 100, 100, DARKBLUE);
		DrawRectangle(m_locationX - 30, m_locationY - 30, 60, 60, WHITE);
		DrawRectangle(m_locationX - 10, m_locationY - 10, 20, 20, BLACK);
		break;

	default:
		std::cout << std::endl << "!!Shape ERROR - Check SnakeHead.h / SnakeHead.cpp!!" << std::endl << std::endl;
		break;
	}
}

SHAPE SnakeHead::GetCurrentShape()
{
	return m_currentShape;
}

int SnakeHead::GetLocationX()
{
	return m_locationX;
}

int SnakeHead::GetLocationY()
{
	return m_locationY;
}

int SnakeHead::GetPreLocationX()
{
	return m_preLocationX;
}

int SnakeHead::GetPreLocationY()
{
	return m_preLocationY;
}

void SnakeHead::SetLocation(int x, int y)
{
	m_locationX = x;
	m_locationY = y;
}

void SnakeHead::SetPreLocation(int x, int y)
{
	m_preLocationX = x;
	m_preLocationY = y;
}

SnakeHead::SnakeHead(SHAPE shape) : m_locationX(), m_locationY(), m_preLocationX(), m_preLocationY(), m_currentShape(shape)
{
}
