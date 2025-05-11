#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.h"
#include <time.h>

Mapa mapa;
Posicao heroi;


int acabou() {
    return 0;
}

int ehdirecao(char direcao) {
    return direcao == ESQUERDA ||
        direcao == CIMA ||
        direcao == BAIXO ||
        direcao == DIREITA;
}

void move(char direcao) {

    if (!ehdirecao(direcao)) {
        return;
    }

    int proximox = heroi.x;
    int proximoy = heroi.y;

    switch(direcao) {
        case ESQUERDA:
            proximoy--;
            break;
        case CIMA:
            proximox--;
            break;
        case BAIXO:
            proximox++;
            break;
        case DIREITA:
            proximoy++;
            break;
    }

    if (!ehvalida(&mapa, proximox, proximoy))
        return;

    if (!ehvazia(&mapa, proximox, proximoy))
        return;

    andanomapa(&mapa, heroi.x, heroi.y, proximox, proximoy);
    heroi.x = proximox;
    heroi.y = proximoy;
}

int praondefantasmavai(int xatual, int yatual, int *xdestino, int *ydestino) {

    int opcoes[4][2] = {
        {xatual, yatual+1},
        {xatual + 1, yatual},
        {xatual, yatual - 1},
        {xatual - 1, yatual}
    };

    srand(time(0));


    for (int i = 0; i < 10; i++) {
        int posicao = rand() % 4;

        if (podeandar(&mapa, opcoes[posicao][0], opcoes[posicao][1])) {
            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];
            return 1;
        }
    }


    return 0;
}

void fantasmas() {
    Mapa copia;

    copiamapa(&copia, &mapa);

    for (int i = 0; i < copia.linhas; i++) {
        for (int j = 0; j < copia.colunas; j++) {
            if (copia.matriz[i][j] = FANTASMA) {
               int xdestino;
               int ydestino;

               int encontrou = praondefantasmavai(i, j, &xdestino, &ydestino);

               if (encontrou) {
                   andanomapa(&mapa, i, j, xdestino, ydestino);
               }
            }
        }
    }

    liberamapa(&copia);
}

int main() {

    lemapa(&mapa);
    encontramapa(&mapa, &heroi, HEROI);

    do {
        imprimemapa(&mapa);

        char comando;
        scanf(" %c", &comando);

        move(comando);
        fantasmas();

    } while (!acabou());

    liberamapa(&mapa);
}
