#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_gfxPrimitives.h>

#include "Globals.h"

class RessourceManager
{
private:
	SDL_Surface * m_SDLScreen;
	SDL_Surface * m_SDLBackground;
	SDL_Surface * m_SDLSphere;
	SDL_Surface * m_SDLCuboid;

public:
	RessourceManager() : m_SDLScreen(NULL), m_SDLBackground(NULL), m_SDLSphere(NULL), m_SDLCuboid(NULL)
	{
		assert(SDL_Init(SDL_INIT_EVERYTHING) != -1);

		this->m_SDLScreen = SDL_SetVideoMode(0, 0, 32, SDL_SWSURFACE | SDL_RESIZABLE);

		assert(m_SDLScreen != NULL);

		SDL_WM_SetCaption("Physics", NULL);

		cout << "Constructor RessourceManager called" << endl;
	}

	~RessourceManager()
	{
		SDL_FreeSurface(this->m_SDLBackground);
		SDL_FreeSurface(this->m_SDLSphere);
		SDL_FreeSurface(this->m_SDLCuboid);

		m_SDLBackground = NULL;
		m_SDLSphere = NULL;
		m_SDLCuboid = NULL;

		cout << "Destructor RessourceManager called" << endl;
	}


	static RessourceManager * Instance();


	SDL_Surface * LoadImage(string Filename);

	void ApplySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination);
	void ApplySurface(int x, int y, Shapes Shape, int Radius, Colors Color, SDL_Surface* destination);
	void ApplySurface(int x, int y, Shapes Shape, Vector2D * vSize, Colors Color, SDL_Surface* destination);

	void LoadContent();

	SDL_Surface * GetScreen() {return this->m_SDLScreen;}
	void SetScreen(SDL_Surface * Screen) {this->m_SDLScreen = Screen;}

	SDL_Surface * GetBackground() {return this->m_SDLBackground;}
	SDL_Surface * GetSphere() {return this->m_SDLSphere;}
	SDL_Surface * GetCuboid() {return this->m_SDLCuboid;}
};