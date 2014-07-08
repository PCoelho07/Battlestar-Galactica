#include "Bala.hpp"

Bala::Bala(){
	this->img = SDL_LoadBMP("img/jogador.bmp");
	this->vel = 10;
}

void Bala::setPonto(Ponto p){
	this->p.x = p.x;
	this->p.y = p.y;
}

void Bala::setPonto(int x, int y){
	this->p.x = x;
	this->p.y = y;
}

void Bala::setVel(int vel){
	this->vel = vel;
}

bool Bala::liberaMemoria(){
	SDL_FreeSurface(this->img);
	return true;
}