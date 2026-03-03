#include <iostream>
#include <conio.h>
#include "Game.h"
#include <string>
#include "raylib.h"


int main()
{
	srand(time(NULL));

	// decides what the shape of the nake will be (CIRCLE or SQUARE)
	//                       ||
	//                       \/
	Game* game = new Game(SQUARE);

	// sets up everthing for the start of the game
	game->StartUp();
	
	char input;
	while (!WindowShouldClose())
	{
		input = GetKeyPressed();
		game->Update(toupper(input));
		
	}

	delete game;
	return 0;
}