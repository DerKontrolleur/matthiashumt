#include "RessourceManager.h"

RessourceManager * RessourceManager::Instance()
{
	static RessourceManager Instance;

	return &Instance;
}

SDL_Surface * RessourceManager::LoadImage(string Filename)
{
	SDL_Surface * LoadedImage = NULL;
	SDL_Surface * OptimizedImage = NULL;

	LoadedImage = IMG_Load(Filename.c_str());
	assert(LoadedImage != NULL);

	OptimizedImage = SDL_DisplayFormat(LoadedImage);
	SDL_FreeSurface(LoadedImage);

	return OptimizedImage;
}

void RessourceManager::ApplySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
	SDL_Rect Offset;

	Offset.x = x;
	Offset.y = y;

	assert(SDL_BlitSurface(source, NULL, destination, &Offset) != -1);
}

void RessourceManager::ApplySurface(int x, int y, Shapes Shape, int Radius, Colors Color, SDL_Surface* destination)
{
	switch(Color)
	{
	case red:
		filledEllipseRGBA(destination, x, y, Radius, Radius, 255, 0, 0, 255);
	break;
	case green:
		filledEllipseRGBA(destination, x, y, Radius, Radius, 0, 255, 0, 255);
	break;
	case blue:
		filledEllipseRGBA(destination, x, y, Radius, Radius, 0, 0, 255, 255);
	break;
	default:
		filledEllipseRGBA(destination, x, y, Radius, Radius, 0, 0, 0, 255);
	break;
	}
}

void RessourceManager::ApplySurface(int x, int y, Shapes Shape, Vector2D * vSize, Colors Color, SDL_Surface* destination)
{
	switch(Color)
	{
	case red:
		boxRGBA(destination, x, y, static_cast<int>(vSize->x), static_cast<int>(vSize->y), 255, 0, 0, 255);
	break;
	case green:
		boxRGBA(destination, x, y, static_cast<int>(vSize->x), static_cast<int>(vSize->y), 0, 255, 0, 255);
	break;
	case blue:
		boxRGBA(destination, x, y, static_cast<int>(vSize->x), static_cast<int>(vSize->y), 0, 0, 255, 255);
	break;
	default:
		boxRGBA(destination, x, y, static_cast<int>(vSize->x), static_cast<int>(vSize->y), 255, 0, 0, 255);
	break;
	}
}

void RessourceManager::LoadContent()
{
	cout << "Loading images..." << endl;

	this->m_SDLBackground = LoadImage("Background.png");
	this->m_SDLSphere = LoadImage("Sphere.png");
	this->m_SDLCuboid = LoadImage("Cuboid.png");

	assert(m_SDLBackground != NULL && m_SDLSphere != NULL && m_SDLCuboid != NULL);
}