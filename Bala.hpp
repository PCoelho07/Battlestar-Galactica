#ifndef _BALA_H
#define _BALA_H

#include "Cenario.hpp"


class Bala{
	private:
		Ponto p;
		SDL_Surface *img;
		int vel;

	public:
		Bala();
		// ~Bala();
		void setPonto(Ponto);
		void setPonto(int, int);
		Ponto getPonto(){ return this->p;}
		SDL_Surface* getImg(){return this->img; }
		bool liberaMemoria();
		void setVel(int);
		int getVel(){return this->vel; }
	/* data */
};

#endif