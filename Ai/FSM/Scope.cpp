#include "Scope.h"

void Scope::Render()
{
	SDL_FillRect(RM->GetScreen(), &RM->GetScreen()->clip_rect, SDL_MapRGB(RM->GetScreen()->format, 0xFF, 0xFF, 0xFF));
}
