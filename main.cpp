#include <iostream>
#include "Jogador.hpp"
#include "Cenario.hpp"
#include "unistd.h"

void controla_fps(int t_i);
int selNivel(int nivel);

int largura = 800, altura = 700;

int main(int argc, char const *argv[]){
	SDL_Surface *screen;
	
	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "Erro: " << SDL_GetError() << std::endl;
		exit(-1);
	}	
	screen = SDL_SetVideoMode(largura, altura, 16, SDL_DOUBLEBUF | SDL_SWSURFACE);
	if(screen == NULL){
		return 1;
	}
	SDL_WM_SetCaption("Battlestar Galactica", NULL);

	SDL_Event evento; //Captura os eventos do teclado
	int t_i;
	bool controle = true; //Controla o loop do jogo
	bool teclas = true; //Liberam ou travam os movimentos
	bool dir = false; // Movimento á direita
	bool esq = false; // Movimento à esquerda
	bool cima = false;
	bool baixo = false;

	Cenario *cenario = new Cenario(screen, 10);
	Jogador *jogador = new Jogador(screen);

	cenario->geraInimigos();

	bool tiro = false;
	Bala *b = NULL;

	while(controle){
		t_i = SDL_GetTicks();

			while(SDL_PollEvent(&evento)){
				switch(evento.type){
					case SDL_QUIT:
						controle = false;
						break;
					case SDL_KEYDOWN:
						if(teclas){
							if(evento.key.keysym.sym == SDLK_SPACE){
								jogador->prepAtira(); //Prepara o canhão para atirar!!
							}
							else if(evento.key.keysym.sym == SDLK_LEFT)
								esq = true;
							else if(evento.key.keysym.sym == SDLK_RIGHT){
								dir = true;
							}
							else if(evento.key.keysym.sym == SDLK_UP){
								cima = true;
							}
							else if(evento.key.keysym.sym == SDLK_DOWN){
								baixo = true;
							}
						}
						break;
					case SDL_KEYUP:
						if(evento.key.keysym.sym == SDLK_LEFT)
								esq = false;
						else if(evento.key.keysym.sym == SDLK_RIGHT){
								dir = false;
						}
						else if(evento.key.keysym.sym == SDLK_UP){
								cima = false;
						}
						else if(evento.key.keysym.sym == SDLK_DOWN){
								baixo = false;
						}					
				}
			}

		if(esq)
			jogador->moveEsq();
		else if(dir)
			jogador->moveDir();
		else if(cima)
			jogador->moveUp();
		else if(baixo)
			jogador->moveDown();


		cenario->mostraInimigos();
		jogador->mostraJogador();
		jogador->atira(); // Atira a bala assim que for preparada quando se aperta a SPACE BAR
		
		/*
		GAMBIARRA!!...
		Mas funcionou!! hehe
		*/
		std::list<Inimigo> i = cenario->getInimigos();
		jogador->checkColisao(&i);
		cenario->setInimigos(i);

		if(cenario->getVitoria() == 1){
			SDL_Surface *vitoria = SDL_LoadBMP("img/vitoria.bmp");
			teclas = false;
			SDL_Rect destino;
			destino.x = 300;
			destino.y = 250;
			SDL_BlitSurface(vitoria, NULL, screen, &destino);
		}
		else{
			// Derrota! 
		}

		SDL_Flip(screen);
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
	}

	/*
		Desaloca memória dos objetos do jogo!
	*/
	jogador->liberaMemoria(); 
	cenario->liberaMemoria();

	SDL_Quit(); /*Encerra o SDL */
	return 0;
}

void controla_fps(int t_i){
	int fps = 1000/60;
	int t_a = SDL_GetTicks() - t_i;

	if(t_a < fps)
		SDL_Delay(fps - t_a);
}

int selNivel(int nivel){
	int res;
	switch(nivel){
		case 1:
			res = 10;
			break;
		case 2:
			res = 20;
			break;
		case 3:
			res = 30;
			break;
		default:
			res = 10;
	}

	return res;
}
