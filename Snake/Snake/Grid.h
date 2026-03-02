#pragma once
#include <list>
#include "Apple.h"

class Snake;
class Grid
{
public:

	void Render();
	void FillApples(Snake* snake);
	void Eat(Apple apple);
	void AddApple(Snake* snake);
	bool CompareAppleLocations(int x, int y, Snake* snake);
	std::list<Apple>* GetPtrApples();

	Grid();

private:

	
	std::list<Apple> m_apples;

};

