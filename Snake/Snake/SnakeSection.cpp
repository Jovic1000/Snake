#include "SnakeSection.h"
#include "raylib.h"
#include <iostream>



void SnakeSection::Render()
{
	switch (GetShape())
	{
	case(CIRCLE):
		DrawCircle(m_locationX, m_locationY, 50, RED);
		break;

	case(SQUARE):
		DrawRectangle(m_locationX, m_locationX, 50, 50, RED);
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

void SnakeSection::SetLocation(int x, int y)
{
	m_locationX = x;
	m_locationY = y;
}

SnakeSection::SnakeSection(SHAPE shape) : m_shape(shape), m_locationX(), m_locationY()
{
}
