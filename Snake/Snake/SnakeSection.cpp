#include "SnakeSection.h"
#include "raylib.h"
#include <iostream>



void SnakeSection::Render()
{
	switch (GetShape())
	{
	case(CIRCLE):
		DrawCircle(m_locationX, m_locationY, 50, DARKBLUE);
		break;

	case(SQUARE):
		DrawRectangle(m_locationX - 50, m_locationY - 50, 100, 100, DARKBLUE);
		break;

	default:
		std::cout << std::endl << "!!Shape ERROR - Check SnakeSection.h / SnakeSection.cpp!!" << std::endl << std::endl;
		break;
	}
}

SHAPE SnakeSection::GetShape()
{
	return m_shape;
}

int SnakeSection::GetLocationX()
{
	return m_locationX;
}

int SnakeSection::GetLocationY()
{
	return m_locationY;
}

int SnakeSection::GetPreLocationX()
{
	return m_preLocationX;
}

int SnakeSection::GetPreLocationY()
{
	return m_preLocationY;
}

void SnakeSection::SetLocation(int x, int y)
{
	m_locationX = x;
	m_locationY = y;
}

void SnakeSection::SetPreLocation(int x, int y)
{
	m_preLocationX = x;
	m_preLocationY = y;
}

SnakeSection::SnakeSection(SHAPE shape) : m_shape(shape), m_locationX(), m_locationY(), m_preLocationX(), m_preLocationY()
{
}
