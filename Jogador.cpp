#include "Jogador.hpp"


Jogador::Jogador(SDL_Surface *screen){
	this->screen = screen;
	this->p.x = 400;
	this->p.y = 660;
	this->carregaImagem();
	if(!this->carregaImagem()){
		std::cout << "Erro ao carregar a imagem 'img/jogador.bmp'" << std::endl;
		exit(-1);
	}

}

bool Jogador::carregaImagem(){
	this->img = SDL_LoadBMP("img/nave_converted.bmp");
	if(this->img)
		return true;

	return false;
}

void Jogador::moveEsq(){
		if(this->p.x > 0){
			this->p.x -= 10;
		}		
}

void Jogador::moveDir(){
	if(this->p.x < 780){
		this->p.x += 10;
	}
}

void Jogador::moveUp(){
	if(this->p.y > 0)
		this->p.y -= 10;
}

void Jogador::moveDown(){
	if(this->p.y < 660)
		this->p.y += 10;
}

void Jogador::mostraJogador(){
	SDL_Rect destino;
	destino.x = this->p.x;
	destino.y = this->p.y;

	SDL_BlitSurface(this->img, NULL, this->screen, &destino);
}

void Jogador::prepAtira(){
	if(this->bala == NULL){
		this->bala = new Bala();
		Ponto p = this->getPonto();
		p.x += 20;
		this->bala->setPonto(p);
		this->bala->setVel(50);
	}
}

void Jogador::atira(){
	SDL_Rect destino;
	if(this->bala != NULL){
		if(this->bala->getPonto().y > -40){
			this->bala->setPonto(this->bala->getPonto().x, this->bala->getPonto().y - this->bala->getVel());
			destino.x = this->bala->getPonto().x;
			destino.y = this->bala->getPonto().y;
			// std::cout << this->bala->getPonto().x << " - " << this->bala->getPonto().y << std::endl;
			SDL_BlitSurface(this->bala->getImg(), NULL, this->screen, &destino);
		}
		else{
			// std::cout << "PAssou por aqui!" << std::endl;
			delete this->bala;
			this->bala = NULL;
		}
	}
} 

void Jogador::setTiro(Bala *bala){
	this->bala = bala;
}

bool Jogador::colidiu(Ponto p1, Ponto p2){
	double dist = sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
		if(dist < 30){
			return true;
		}

	return false;
}

bool Jogador::checkColisao(std::list<Inimigo> *i){//Cenario *cen){
	if(this->bala != NULL){
		std::list<Inimigo>::iterator it = (*i).begin();
			while(it != (*i).end()){//cen->getInimigos().end()){
					if(this->colidiu(it->getPonto(), this->bala->getPonto())){
						// std::cout << "COLIDIU!!!" << std::endl;
						it = (*i).erase(it);//cen->removeIni(it);
						// delete this->bala;
						// std::cout << it->x << " - " << it->y << std::endl;
						this->bala = NULL;	
						return true;
					}
					// std::cout << "Y: " << it->y << " - X: " << it->x <<  std::endl;
					it++;
			}
	}
	return false;
}

bool Jogador::liberaMemoria(){
	SDL_FreeSurface(this->screen);
	// this->bala->liberaMemoria();
	return true;
}



