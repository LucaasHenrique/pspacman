#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define BOMBA 'b'

#ifndef _PACMAN_H_
#define _PACMAN_H_

void move(char comando);
int acabou();
int ehdirecao(char direcao);
void explodepilula();
void explodepilula2(int x, int y, int somax, int somay, int qtd);
void fantasmas();
int praondefantasmavai(int xatual, int yatual, int *xdestino, int *ydestino);

#endif
