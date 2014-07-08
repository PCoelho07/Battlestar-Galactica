#include "Inimigo.hpp"

Inimigo::Inimigo(SDL_Surface* screen){
	this->screen = screen;
	this->p.x = 0;
	this->p.y = 0;
	this->vel = 0.2;
}

Inimigo::Inimigo(){
	this->p.x = 0;
	this->p.y = 0;
	this->vel = 1;
}

bool Inimigo::carregaImg(){
	this->img = SDL_LoadBMP("img/inimigo.bmp");
	if(this->img)
		return true;

	return false;
}

void Inimigo::setPonto(Ponto p){
	this->p = p;
}

void Inimigo::setPonto(int x, int y){
	this->p.x = x;
	this->p.y = y;
}

void Inimigo::setVel(int vel){
	this->vel = vel;
}

Inimigo::~Inimigo(){

}