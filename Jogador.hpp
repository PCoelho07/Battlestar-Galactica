#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include "Cenario.hpp"
#include "Bala.hpp"

class Jogador{
	private:
		SDL_Surface *screen;//Onde meu jogador será mostrado
		SDL_Surface *img;// Imagem do jogador
		Ponto p; //Coodenada do meu jogador!
		Bala *bala; //Bala que será atirada!
		bool tiro; //Se houve o tiro ou não

	public:
		Jogador(SDL_Surface*);
		bool carregaImagem();
		void moveEsq();
		void moveDir();
		void moveUp();
		void moveDown();
		void mostraJogador();
		void setTiro(Bala*);
		void prepAtira();
		void atira();
		bool colidiu(Ponto, Ponto);
		bool checkColisao(std::list<Inimigo>*);//Cenario*);
		Ponto getPonto(){ return this->p;}
		bool liberaMemoria();
	/* data */
};
#endif