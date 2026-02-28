#include <iostream>
#include <conio.h>
#include "Game.h"
#include "raylib.h"


int main()
{
	srand(time(NULL));
	Game* game = new Game(CIRCLE);

	game->StartUp();
	
	char input;
	while (!WindowShouldClose())
	{
		input = GetKeyPressed();

		game->Update(input);
	}

	delete game;
	return 0;
}