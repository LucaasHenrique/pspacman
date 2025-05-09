#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.h"

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

void fantasma() {
    for (int i = 0; i < mapa.linhas; i++) {
        for (int j = 0; j < mapa.colunas; j++) {
            if (mapa.matriz[i][j] = FANTASMA) {
                if(ehvalida(&mapa, i, j+1)) {
                    andanomapa(&mapa, i, j, i, j+1);
                }
            }
        }
    }
}

int main() {

    lemapa(&mapa);
    encontramapa(&mapa, &heroi, HEROI);

    do {
        imprimemapa(&mapa);

        char comando;
        scanf(" %c", &comando);

        move(comando);

    } while (!acabou());

    liberamapa(&mapa);
}
