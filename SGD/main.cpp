#include "Game.h"

Game *game = nullptr;

int main(int arg, char *argv[]) {

 	int startLoop=0;

	const int FPS = 60;					//frame rate - fps-y 
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;						//frame rate - fps-y

	game = new Game();
	game->init("Scary Libery", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while (game->running()) {

		frameStart = SDL_GetTicks();		//frame rate - fps-y

		game->handleEvents();

		if (Game::event.type == SDL_KEYDOWN) {
			for (int i = 1; i < 32; i++) {
				game->update();
				game->render(startLoop);
			}
		}

		game->update();
		game->render(startLoop);

			if (startLoop < 4) {
				startLoop++;
			}



			frameTime = SDL_GetTicks() - frameStart;  //frame rate - fps-y

			if (frameDelay > frameTime)						//frame rate - fps-y
			{
				SDL_Delay(frameDelay - frameTime);
			}
		
	}
	game->clean();

	return 0;

}
