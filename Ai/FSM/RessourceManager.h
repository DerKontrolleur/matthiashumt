#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_gfxPrimitives.h>

#include "Globals.h"
#include "Vector.h"
#include <unordered_map>

class RessourceManager
{
private:
	SDL_Surface * Screen;

	unordered_map<PictureNames, SDL_Surface*> Pictures;

	RessourceManager()
	{
		assert(SDL_Init(SDL_INIT_EVERYTHING) != -1  && "<RessourceManager::Constructor>: error setting up SDL");

		SDL_WM_SetCaption("Physics", NULL);

		this->Screen = SDL_SetVideoMode(0, 0, 32, SDL_SWSURFACE | SDL_RESIZABLE);

		cout << "RessourceManager constructed" << endl;
	}

public:

	~RessourceManager()
	{
		this->Pictures.clear();

		cout << "RessourceManager destroyed" << endl;
	}


	static RessourceManager* Instance();


	void LoadImage(PictureNames key, string filename);
	void ApplyPicture(int positionX, int positionY, SDL_Surface* source, SDL_Surface* destination);
	void ApplyCuboid(const Vector2D<double>& position, const Vector2D<int>& size, Colors Color, SDL_Surface* destination);
	void LoadContent();

	SDL_Surface* GetScreen() const {return this->Screen;}
	void SetScreen(SDL_Surface* Screen) {this->Screen = Screen;}

	SDL_Surface* GetPicture(PictureNames key) {this->Pictures.at(key);}
};