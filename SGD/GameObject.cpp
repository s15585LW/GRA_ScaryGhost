#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y) 
{
	objTexture = TextureManager::LoadTexture(texturesheet);

	xpos = x;
	ypos = y;
}

void GameObject::Update() 
{


	srcRect.h = 100;
	srcRect.w = 100;
	srcRect.x = 0;
	srcRect.y = 0;
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w *2; // * 2
	destRect.h = srcRect.h *2; // * 2
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

void GameObject::SetRec(SDL_Rect v_destRect) {
	destRect = v_destRect;
}
void GameObject::SetDestX(int setX) {
	xpos = setX;
}
void GameObject::SetDestY(int setY) {
	ypos = setY;
}