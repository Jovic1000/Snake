#pragma once

class Grid;
class Apple
{
public:

	void Generate(Grid &grid);
	void SetLcoation(int x, int y);
	int GetLocationX();
	int GetLocationY();

private:

	int m_LocationX;
	int m_LocationY;
};

