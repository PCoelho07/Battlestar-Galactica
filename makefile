
CC    = g++
CFLAGS= -std=c++11 -I. -I/usr/local/include
LIBS  = -L/usr/local/lib -lSDL -lSDL_gfx

OBJ   = main.o Cenario.o Jogador.o Ponto.o Bala.o Inimigo.o

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

jogo: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o *~ core
