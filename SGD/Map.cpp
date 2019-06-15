#include "Map.h"
#include "TextureManager.h"

int lvl1[20][25] = 
{
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,4,1,3,7,7,1,1,1,1,1,3,1,3,7,7,1,1,1,8,1,1,7,7,0 },
	{ 0,1,1,4,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
	{ 0,1,1,1,1,1,1,1,0,0,0,1,1,3,1,4,4,1,1,1,3,3,1,1,0 },
	{ 0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,3,3,1,1,0 },
	{ 0,1,1,4,1,1,1,1,7,7,7,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
	{ 0,1,1,1,1,1,3,2,2,2,2,2,2,2,2,2,2,5,1,1,1,1,1,1,0 },
	{ 0,1,1,1,1,1,3,2,2,2,2,2,5,2,2,2,2,2,1,4,1,1,4,4,0 },
	{ 1,1,1,1,1,1,3,2,2,1,1,1,3,1,1,1,2,2,1,1,1,1,1,1,1 },
	{ 1,2,2,2,5,2,2,2,2,1,1,1,3,1,1,1,2,2,1,1,2,2,2,2,6 },
	{ 1,2,2,2,5,2,2,2,2,1,1,1,4,1,1,1,2,2,1,1,5,2,2,2,6 },
	{ 1,4,1,1,1,1,1,1,1,4,1,1,1,1,1,1,2,2,1,1,2,2,1,1,1 },
	{ 0,1,1,1,1,1,1,1,1,4,1,1,1,1,1,1,5,5,1,1,2,2,1,1,0 },
	{ 0,1,1,1,1,1,4,1,1,1,1,1,1,1,1,4,2,2,1,4,2,2,1,1,0 },
	{ 0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,3,2,2,1,1,2,2,1,1,0 },
	{ 0,7,1,1,1,1,1,1,0,0,0,1,1,1,1,3,2,2,1,1,2,2,4,1,0 },
	{ 0,7,1,1,4,1,1,4,7,8,7,1,1,1,1,4,2,5,1,1,2,2,1,1,0 },
	{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,1,7,0 },
	{ 0,1,1,1,1,1,1,1,1,1,1,1,3,3,1,1,2,2,2,2,2,2,3,7,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};

Map::Map()
{	
	book = TextureManager::LoadTexture("assets/1_book.png");
	piec = TextureManager::LoadTexture("assets/1_piec.png");
	water = TextureManager::LoadTexture("assets/1_brick.png");
	grass = TextureManager::LoadTexture("assets/1_rock.png");
	dirt = TextureManager::LoadTexture("assets/1_dirt.png");
	rock = TextureManager::LoadTexture("assets/1_table.png");
	grassGhost = TextureManager::LoadTexture("assets/1_ghost2.png");
	dirtGhost = TextureManager::LoadTexture("assets/1_ghost.png");
	win = TextureManager::LoadTexture("assets/1_carpet.png");

	LoadMap(lvl1);
	
	src.x = src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;

	dest.x = dest.y = 0;

	FillVector();
}

void Map::LoadMap(int arr[20][25])
{
	for (int row = 0; row < 20; row++) 
	{
		for (int column = 0; column < 25; column++) 
		{
			map[row][column] = arr[row][column];
 		}
	}
}

void Map::DrawMap()
{
	int type = 0;

	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			type = map[row][column];

			dest.x = column * 32;
			dest.y = row * 32;

			switch (type)
			{
			case 0:
				TextureManager::Draw(water, src, dest);
				break;
			case 1:
				TextureManager::Draw(grass, src, dest);
				break;
			case 2:
				TextureManager::Draw(dirt, src, dest);
				break;
			case 3:
				TextureManager::Draw(rock, src, dest);
				break;
			case 4:
				TextureManager::Draw(grass, src, dest);
				break;
			case 5:
				TextureManager::Draw(dirt, src, dest);
				break;
			case 6:
				TextureManager::Draw(win, src, dest);
				break;
			case 7:
				TextureManager::Draw(book, src, dest);
				break;
			case 8:
				TextureManager::Draw(piec, src, dest);
				break;
			default:
				break;
			}
		}
	}
}
void Map::DrawMapWithGhost(){

	int type = 0;

	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			type = map[row][column];

			dest.x = column * 32;
			dest.y = row * 32;

			switch (type)
			{
			case 0:
				TextureManager::Draw(water, src, dest);
				break;
			case 1:
				TextureManager::Draw(grass, src, dest);
				break;
			case 2:
				TextureManager::Draw(dirt, src, dest);
				break;
			case 3:
				TextureManager::Draw(rock, src, dest);
				break;
			case 4:
				TextureManager::Draw(grassGhost, src, dest);
				break;
			case 5:
				TextureManager::Draw(dirtGhost, src, dest);
				break;
			case 6:
				TextureManager::Draw(win, src, dest);
				break;
			case 7:
				TextureManager::Draw(book, src, dest);
				break;
			case 8:
				TextureManager::Draw(piec, src, dest);
				break;
			default:
				break;
			}
		}
	}
}


std::vector<SDL_Rect> Map::FillVector() {
	int type = 0;

	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			type = map[row][column];

			dest.x = column * 32;
			dest.y = row * 32;

			if (type == 0 || type == 3 || type ==7) {
				vectorMap.push_back(src);
				vectorMap.push_back(dest);
			}

			if (type == 4 || type == 5 || type==8) {
				vectorGhost.push_back(src);
				vectorGhost.push_back(dest);
			}
			if (type == 6) {
				vectorWin.push_back(src);
				vectorWin.push_back(dest);
			}
			
		}
	}

	return vectorMap, vectorGhost;
}

SDL_Rect Map::GetPositionOfBarrier(int vectorDestId, int vectorSrcId) {
	return vectorMap[vectorDestId],vectorMap[vectorSrcId];
}

SDL_Rect Map::GetPositionOfGhost(int vectorDestId, int vectorSrcId) {
	return vectorGhost[vectorDestId], vectorGhost[vectorSrcId];
}

SDL_Rect Map::GetPositionOfWin(int vectorDestId, int vectorSrcId) {
	return vectorWin[vectorDestId], vectorWin[vectorSrcId];
}

int Map::GetSizeOfVectorMap() {
	return vectorMap.size();
}

int Map::GetsizeOfVectorGhost() {
	return vectorGhost.size();
}

int Map::GetSizeOfVectorWin() {
	return vectorWin.size();
}