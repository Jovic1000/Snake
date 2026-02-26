#pragma once
#include <list>
#include "Apple.h"

class Grid
{
public:

	void Render();
	void Update();
	void FillApples();
	void Eat();
	void AddApple();
	bool compareAppleLocations(int x, int y);

	Grid();

private:

	std::list<Apple> m_apples;

};

