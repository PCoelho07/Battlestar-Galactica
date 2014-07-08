#ifndef _INIMIGO_HPP_
#define _INIMIGO_HPP_

#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <iostream>
#include <list>
#include <ctime>
#include <algorithm>
#include "Ponto.cpp"

class Inimigo{
	private:
		Ponto p; //Coordenada do inimigo
		SDL_Surface *screen; //Onde meu inimigo será mostrado;
		SDL_Surface *img; //Imagem do inimigo
		int vel;


	public:
		Inimigo(SDL_Surface*);
		Inimigo();
		~Inimigo();
		bool carregaImg();
		void setPonto(Ponto);
		void setPonto(int, int);
		Ponto getPonto() {return this->p; }	
		SDL_Surface* getImg(){return this->img;}
		void setVel(int);
		int getVel(){return this->vel;}

};

#endif