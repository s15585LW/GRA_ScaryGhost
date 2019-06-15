#pragma once
#include "Game.h"
#include <vector>

class Map
{
public:
	
	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();
	void DrawMapWithGhost();

	//SDL_Rect GetPositionOfBarrier();
	std::vector<SDL_Rect> FillVector();

	SDL_Rect GetPositionOfBarrier(int vectorDestId,int vectorSrcId);
	SDL_Rect GetPositionOfGhost(int vectorDestId, int vectorSrcId);
	SDL_Rect GetPositionOfWin(int vectorDestId, int vectorSrcId);

	int GetSizeOfVectorMap();
	int GetsizeOfVectorGhost();
	int GetSizeOfVectorWin();
	
private:

	SDL_Rect src, dest;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;
	SDL_Texture* grassGhost;
	SDL_Texture* dirtGhost;
	SDL_Texture* rock;
	SDL_Texture* win;
	SDL_Texture* book;
	SDL_Texture* piec;


	int map[20][25];
	std::vector<SDL_Rect> vectorMap;
	std::vector<SDL_Rect> vectorGhost;
	std::vector<SDL_Rect> vectorWin;
};