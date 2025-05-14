#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define PILULA 'P'

#ifndef _MAPA_H_
#define _MAPA_H_

typedef struct {
    char **matriz;
    int linhas;
    int colunas;
} Mapa;

typedef struct {
    int x;
    int y;
} Posicao;

void alocamapa(Mapa *mapa);
void lemapa(Mapa *mapa);
void liberamapa(Mapa *mapa);
int encontramapa(Mapa *mapa, Posicao *p, char c);
int ehvalida(Mapa *mapa, int x, int y);
void andanomapa(Mapa *mapa, int xorigem, int yorigem, int xdestino, int ydestino);
void copiamapa(Mapa *destino, Mapa *origem);
int podeandar(Mapa *mapa, char personagem, int x, int y);
int ehparede(Mapa *mapa, int x, int y);
int ehpersonagem(Mapa *mapa, char personagem, int x, int y);

#endif
