#include "Snake.h"

void Snake::AddToBody()
{
	SnakeSection* newSection = new SnakeSection(m_currentShape);

	m_snakeSections->push(*newSection);
}

Snake::Snake(SHAPE shape) : m_snakeSections(), m_head(), m_snakeLength(1), m_currentShape(shape)
{
}

