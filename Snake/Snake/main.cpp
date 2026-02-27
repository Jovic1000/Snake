#include <iostream>
#include "Game.h"
#include <raylib.h>

int main()
{
	Game* game = new Game(CIRCLE);

	game->StartUp();

	while (!WindowShouldClose())
	{
		game->Update();
	}

	system("pause");

	delete game;
	return 0;
}