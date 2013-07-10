#include "RessourceManager.h"

RessourceManager * RessourceManager::Instance()
{
	static RessourceManager Instance;

	return &Instance;
}

void RessourceManager::LoadImage(PictureNames key, string filename)
{
	SDL_Surface * LoadedImage = NULL;
	SDL_Surface * OptimizedImage = NULL;

	LoadedImage = IMG_Load(filename.c_str());

	assert(LoadedImage != NULL && "<RessourceManager::LoadImage>: wrong file name");

	OptimizedImage = SDL_DisplayFormat(LoadedImage);

	assert(OptimizedImage != NULL && "<RessourceManager::LoadImage>: error optimizing image");

	this->Pictures.insert(make_pair(key, OptimizedImage));
}

void RessourceManager::ApplyPicture(int positionX, int positionY, SDL_Surface* source, SDL_Surface* destination)
{
	SDL_Rect Offset;

	Offset.x = positionX;
	Offset.y = positionY;

	assert(SDL_BlitSurface(source, NULL, destination, &Offset) != -1 && "<RessourceManager::ApplySurface>: error blitting surface");
}

void RessourceManager::ApplyCuboid(const Vector2D<double>& position, const Vector2D<int>& size, Colors Color, SDL_Surface* destination)
{
	int r, g, b;

	switch(Color)
	{
	case red:
		r = 255;
		g = 0;
		b = 0;
		break;
	case green:
		r = 0;
		g = 255;
		b = 0;
		break;
	case blue:
		r = 0;
		g = 0;
		b = 255;
		break;
	case black:
		r = 0;
		g = 0;
		b = 0;
		break;
	case white:
		r = 255;
		g = 255;
		b = 255;
		break;
	}
	boxRGBA(destination, static_cast<int>(position.X), static_cast<int>(position.Y), static_cast<int>(position.X) + size.X, static_cast<int>(position.Y) + size.Y, r, g, b, 255);
}


void RessourceManager::LoadContent()
{
	cout << "Loading images..." << endl;

	LoadImage(pct_background, "background.png");
}