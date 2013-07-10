#include "World.h"

void World::Render()
{
	//RessourceManager::Instance()->ApplySurface(0, 0, RessourceManager::Instance()->GetBackground(), RessourceManager::Instance()->GetScreen());
    SDL_FillRect(RessourceManager::Instance()->GetScreen(), &RessourceManager::Instance()->GetScreen()->clip_rect, SDL_MapRGB(RessourceManager::Instance()->GetScreen()->format, 0xFF, 0xFF, 0xFF));
}