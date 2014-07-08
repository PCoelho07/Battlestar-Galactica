#ifndef _Cenario_H_
#define _Cenario_H_

#include "Inimigo.hpp"

using std::list;
class Cenario{
	private:
		SDL_Surface *screen; //Onde meu cenario será mostrado;
		SDL_Surface *inimigo;
		list<Inimigo> ini;
		int nivel;
		int qtdInimigo;

	public:
		Cenario(SDL_Surface*, int);
		Cenario();
		~Cenario();
		std::list<Inimigo> getInimigos(){ return this->ini; }
		int getNivel(){ return this->nivel;}
		void setNivel(int);
		void setInimigos(list<Inimigo> i){ this->ini = i; }
		void mostraInimigos();
		list<Inimigo>::iterator removeIni(list<Inimigo>::iterator it);
		void geraInimigos();//std::list<Ponto> geraInimigos();
		int getVitoria();
		bool liberaMemoria();
	/* data */
};





#endif