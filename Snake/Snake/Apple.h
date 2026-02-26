#pragma once
class Apple
{
public:

	void Generate();
	void SetLcoation(int x, int y);
	int GetLocationX();
	int GetLocationY();

private:

	int m_LocationX;
	int m_LocationY;
};

