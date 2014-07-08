#include "Cenario.hpp"

Cenario::Cenario(SDL_Surface *screen, int qtd){
	this->screen = screen;
	this->nivel = 1;
	this->qtdInimigo = qtd;

}

Cenario::Cenario(){
	
}

// bool Cenario::carregaImagens(){
// 	this->inimigo = SDL_LoadBMP("img/inimigo.bmp");
// 	if(this->inimigo)
// 		return true;

// 	return false;
// }

void Cenario::setNivel(int nivel){
	this->nivel = nivel;
}

void Cenario::geraInimigos(){
//	std::list<Ponto> ini;
	std::list<Inimigo>::iterator it;
	Ponto p;
	Inimigo *inimigo = NULL;

	srand(time(NULL));
	for(int i = 0; i < this->qtdInimigo; i++){
		p.x = (rand() % 700) + 50;
		p.y = (-rand() % 700);

		inimigo = new Inimigo(this->screen);
			if(!inimigo->carregaImg())
				std::cout << "Imagem carregada!!" << std::endl;
		inimigo->setPonto(p);
		this->ini.push_back(*inimigo);
		// std::cout << this->ini.size() << std::endl;
	}
}

list<Inimigo>::iterator Cenario::removeIni(list<Inimigo>::iterator it){
	std::cout << "Tentanto Remover o inimigo!!" << std::endl;
	std::cout << it->getPonto().x << " - " << it->getPonto().y << std::endl;
	it = this->ini.erase(it);
	std::cout << it->getPonto().x << " - " << it->getPonto().y << std::endl;
	
	return it;
}


void Cenario::mostraInimigos(){
	std::list<Inimigo>::iterator it;
	SDL_Rect destino;
	Ponto p1;
	SDL_Surface *inimigos;
		it = this->ini.begin();
		while(it != this->ini.end()){
			destino.x = it->getPonto().x;
			if(it->getPonto().y < 680){
				p1 = it->getPonto();
				p1.y++;//= it->getVel();
				it->setPonto(p1);
			}
			destino.y = it->getPonto().y;
			inimigos = it->getImg();
			SDL_BlitSurface(inimigos, NULL, this->screen, &destino);
			it++;
		}
	

}

int Cenario::getVitoria(){
	std::list<Inimigo>::iterator it;
	it = this->ini.begin();

	while(it != this->ini.end()){
		if(it->getPonto().y == 660)
			return 0;

		it++;
	}

	if(this->ini.size() == 0)
		return 1;
	

	return 0;
}

bool Cenario::liberaMemoria(){
	SDL_FreeSurface(this->screen);
	return true;
}