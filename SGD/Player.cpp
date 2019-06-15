#include "Player.h"
#include "TextureManager.h"
#include "Collision.h"

Player::Player(const char* texturesheet, int x, int y) {
	objTexture = TextureManager::LoadTexture(texturesheet);

	xpos = x;
	ypos = y;
}

void Player::Update()
{

	if (Game::event.type == SDL_KEYDOWN) {
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			ypos = (ypos - 1);
			break;
		case SDLK_a:
			xpos = (xpos-1);
			break;
		case SDLK_d:
			xpos = (xpos+1);
			break;
		case SDLK_s:
			ypos = (ypos+1);
			break;
		default:
			break; 
		}
	}
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;
	SDL_Delay(10);
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
	
}

void Player::Render()
{

		SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	
}


SDL_Rect Player::GetRec() {
	return srcRect, destRect;
}
int Player::GetDestX()
{
	return xpos;
}
int Player::GetDestY()
{
	return ypos;
}

void Player::SetRec(SDL_Rect v_destRect) {
	//srcRect = v_srcRect;
	destRect = v_destRect;
}
void Player::SetDestX(int setX) {
	xpos = setX;
}
void Player::SetDestY(int setY) {
	ypos = setY;
}
