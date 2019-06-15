#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Player.h"
#include "Collision.h"

GameObject* one;
GameObject* two;
GameObject* three;
GameObject* start;

Player* player;
Collision* collision;

GameObject* end;
GameObject* win;
GameObject* explosion;

Map* map;

SDL_Event Game::event;
SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags=0;
	if (fullscreen) 
	{ 
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem Initialised! ..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) 
		{
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window,-1,0);
		if (renderer) 
		{
			SDL_SetRenderDrawColor(renderer,255,255,255,255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}


	three = new GameObject("assets/3.png", 300, 220);
	two = new GameObject("assets/2.png", 300, 220);
	one = new GameObject("assets/1.png", 300, 220);
	start = new GameObject("assets/bggame.png", 300, 220);
	end = new GameObject("assets/game_over.png", 300, 220);
	win = new GameObject("assets/game_win.png", 300, 220);
	explosion = new GameObject("assets/rip.png", 300, 220);

	player = new Player("assets/1_bob.ico", 32, 288);
	
	map = new Map();

	collision = new Collision();
}

void Game::handleEvents()
{
	//SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::update()
{
		SDL_Rect  dstRect;


		three->Update();
		two->Update();
		one->Update();
		start->Update();
		win->Update();
		end->Update();
		explosion->Update();
	

			dstRect = player->GetRec();
			dstX = player->GetDestX();
			dstY = player->GetDestY();

			player->Update();


			sizeOfVectorMap = map->GetSizeOfVectorMap();

			sizeOfVectorGhost = map->GetsizeOfVectorGhost();

			sizeOfVectorWin = map->GetSizeOfVectorWin();

			for (int i = 0, z = 1; i < (sizeOfVectorWin - 1), z < sizeOfVectorWin; i++, z++) {

				if (collision->AABB(player->GetRec(), map->GetPositionOfWin(i, z))) {
					//std::cout << "WIN" << std::endl;
					gameWin = true;
				}
			}

			for (int i = 0, z = 1; i < (sizeOfVectorGhost - 1), z < sizeOfVectorGhost; i++, z++) {

				if (collision->AABB(player->GetRec(), map->GetPositionOfGhost(i, z))) {
					//std::cout << "BUM" <<std::endl;
					gameWin = false;
					explosion->SetRec(dstRect);
					explosion->SetDestX(dstX);
					explosion->SetDestY(dstY);
				}
			}

			for (int i = 0, z = 1; i < (sizeOfVectorMap - 1), z < sizeOfVectorMap; i++, z++) {

				if (collision->AABB(player->GetRec(), map->GetPositionOfBarrier(i, z))) {
					player->SetRec(dstRect);
					player->SetDestX(dstX);
					player->SetDestY(dstY);
				}
			}
		

	
}

void Game::render(int startLoop)
{
	// tu mo¿emy dodwaæ rzyczy do renderowania
	int timeOfDealy = 2000;

	switch (startLoop)
	{
	case 0:
		SDL_RenderClear(renderer);
			map->DrawMapWithGhost();
			three->Render();
		SDL_RenderPresent(renderer);
		SDL_Delay(timeOfDealy);
		break;
	case 1:
		SDL_RenderClear(renderer);
			map->DrawMapWithGhost();
			two->Render();
		SDL_RenderPresent(renderer);
		SDL_Delay(timeOfDealy);
		break;
	case 2:
		SDL_RenderClear(renderer);
			map->DrawMapWithGhost();
			one->Render();
		SDL_RenderPresent(renderer);
		SDL_Delay(timeOfDealy);
		break;
	case 3:	
		SDL_RenderClear(renderer);
			map->DrawMapWithGhost();
			start->Render();
		SDL_RenderPresent(renderer);
		SDL_Delay(timeOfDealy);
		break;
	default:
		 timeOfDealy = 0;
			SDL_RenderClear(renderer);
			map->DrawMap();
			player->Render();
			SDL_RenderPresent(renderer);
		
		break;
	}
	
	if (gameWin == false) {
		
			if (showOnlyOneExplosion == 0) {
				showOnlyOneExplosion++;
				SDL_RenderClear(renderer);
				map->DrawMapWithGhost();
				explosion->Render();
				SDL_RenderPresent(renderer);
				SDL_Delay(timeOfDealy);
				SDL_Delay(1500);
			}


			SDL_RenderClear(renderer);
			map->DrawMapWithGhost();
			end->Render();
			SDL_RenderPresent(renderer);
			SDL_Delay(timeOfDealy);
			SDL_Delay(1000);
		}
	
	if(gameWin == true) {
		SDL_RenderClear(renderer);
			map->DrawMapWithGhost();
			win->Render();
		SDL_RenderPresent(renderer);
		SDL_Delay(timeOfDealy);
		SDL_Delay(1000);
	}
	
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned !" << std::endl;
}