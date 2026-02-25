#include "SnakeSection.h"
#include <raylib.h>
#include <iostream>



void SnakeSection::Render()
{
	switch (GetShape())
	{
	case(CIRCLE):
		DrawCircle(m_locationX, m_locationY, 100, RED);
		break;

	case(SQUARE):
		
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

SnakeSection::SnakeSection(SHAPE shape) : m_shape(shape), m_locationX(), m_locationY()
{
}
