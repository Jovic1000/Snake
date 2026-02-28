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
	bool CompareAppleLocations(int x, int y);
	std::list<Apple> GetApples();

	Grid();

private:

	
	std::list<Apple> m_apples;

};

