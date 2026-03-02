#include "Snake.h"
#include <raylib.h>

void Snake::CreateSnake()
{
	m_head->SetLocation(250, 250);
	m_head->SetPreLocation(150, 250);

	SnakeSection newSection(m_currentShape);
	m_snakeSections.push_back(newSection);
	m_snakeLength++;

	m_snakeSections.front().SetLocation(m_head->GetPreLocationX(), m_head->GetPreLocationY());

}

void Snake::Render()
{
	for (SnakeSection section : m_snakeSections)
	{
		section.Render();
	}

	m_head->Render();
}

void Snake::AddToBody()
{
	SnakeSection newSection(m_currentShape);

	for(SnakeSection section : m_snakeSections)
	{
		newSection.SetLocation(section.GetPreLocationX(), section.GetPreLocationY());
	}

	m_snakeSections.push_back(newSection);

	m_snakeLength++;
}

bool Snake::CompareBodyLocations(int x, int y)
{
	for (SnakeSection section : m_snakeSections)
	{
		if (section.GetLocationX() == x && section.GetLocationY() == y)
		{
			return true;
		}
	}

	return false;
}

void Snake::MoveUP()
{
	SnakeSection tempSection(CIRCLE);

	int preX = m_head->GetLocationX();
	int preY = m_head->GetLocationY();

	tempSection.SetLocation(preX, preY);
	m_head->SetPreLocation(preX, preY);
	
	preY = preY - 100;

	m_head->SetLocation(preX, preY);

	for (SnakeSection& section : m_snakeSections)
	{
		section.SetPreLocation(section.GetLocationX(), section.GetLocationY());

		section.SetLocation(tempSection.GetLocationX(), tempSection.GetLocationY());

		tempSection.SetLocation(section.GetPreLocationX(), section.GetPreLocationY());
	}

}

void Snake::MoveDOWN()
{
	SnakeSection tempSection(CIRCLE);

	int preX = m_head->GetLocationX();
	int preY = m_head->GetLocationY();

	tempSection.SetLocation(preX, preY);
	m_head->SetPreLocation(preX, preY);

	preY = preY + 100;

	m_head->SetLocation(preX, preY);

	for (SnakeSection& section : m_snakeSections)
	{
		section.SetPreLocation(section.GetLocationX(), section.GetLocationY());

		section.SetLocation(tempSection.GetLocationX(), tempSection.GetLocationY());

		tempSection.SetLocation(section.GetPreLocationX(), section.GetPreLocationY());
	}
}

void Snake::MoveLEFT()
{
	SnakeSection tempSection(CIRCLE);

	int preX = m_head->GetLocationX();
	int preY = m_head->GetLocationY();

	tempSection.SetLocation(preX, preY);
	m_head->SetPreLocation(preX, preY);

	preX = preX - 100;

	m_head->SetLocation(preX, preY);

	for (SnakeSection& section : m_snakeSections)
	{
		section.SetPreLocation(section.GetLocationX(), section.GetLocationY());

		section.SetLocation(tempSection.GetLocationX(), tempSection.GetLocationY());

		tempSection.SetLocation(section.GetPreLocationX(), section.GetPreLocationY());
	}
}

void Snake::MoveRIGHT()
{
	SnakeSection tempSection(CIRCLE);

	int preX = m_head->GetLocationX();
	int preY = m_head->GetLocationY();

	tempSection.SetLocation(preX, preY);
	m_head->SetPreLocation(preX, preY);

	preX = preX + 100;

	m_head->SetLocation(preX, preY);

	for (SnakeSection& section : m_snakeSections)
	{
		section.SetPreLocation(section.GetLocationX(), section.GetLocationY());

		section.SetLocation(tempSection.GetLocationX(), tempSection.GetLocationY());

		tempSection.SetLocation(section.GetPreLocationX(), section.GetPreLocationY());
	}
}

SnakeHead* Snake::GetHead()
{
	return m_head;
}

std::deque<SnakeSection> Snake::GetBody()
{
	return m_snakeSections;
}

int Snake::GetLength()
{
	return m_snakeLength;
}

Snake::Snake(SHAPE shape) : m_snakeSections(), m_snakeLength(1), m_currentShape(shape), m_head(new SnakeHead(shape))
{
	
}

