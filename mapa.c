#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

void lemapa(Mapa *mapa) {
    FILE *f;

    f = fopen("mapa.txt", "r");
    if (f == 0) {
        printf("Erro na leitura do mapa!\n");
        exit(1);
    }

    fscanf(f, "%d %d", &mapa->linhas, &mapa->colunas);
    alocamapa(mapa);

    for (int i = 0; i < 5; ++i) {
        fscanf(f, "%s", mapa->matriz[i]);
    }

    fclose(f);
}

void alocamapa(Mapa *mapa) {
    mapa->matriz = malloc(sizeof(char*) * mapa->linhas);

    for (int i = 0; i < mapa->linhas; ++i) {
        mapa->matriz[i] = malloc(sizeof(char) * mapa->colunas + 1);
    }
}

void liberamapa(Mapa *mapa) {
    for (int i = 0; i < mapa->linhas; ++i) {
        free(mapa->matriz[i]);
    }

    free(mapa->matriz);
}

int encontramapa(Mapa *mapa, Posicao *p, char c) {
    for (int i = 0; i < mapa->linhas; ++i) {
        for (int j = 0; j < mapa->colunas; ++j) {
            if (mapa->matriz[i][j] == c) {
                p->x = i;
                p->y = j;
                return 1;
            }
        }
    }

    return 0;
}

int ehvalida(Mapa *mapa, int x, int y) {
    if(x >= mapa->linhas)
        return 0;
    if(y >= mapa->colunas)
        return 0;

    return 1;
}

void andanomapa(Mapa *mapa, int xorigem, int yorigem, int xdestino, int ydestino) {
    char personagem = mapa->matriz[xorigem][yorigem];
    mapa->matriz[xdestino][ydestino] = personagem;
    mapa->matriz[xorigem][yorigem] = '.';
}

void copiamapa(Mapa *origem, Mapa *destino) {
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;

    alocamapa(destino);

    for (int i = 0; i < origem->linhas; i++) {
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}

int podeandar(Mapa *mapa, char personagem, int x, int y) {

    return ehvalida(mapa, x, y) &&
        !ehparede(mapa, x, y) &&
        !ehpersonagem(mapa, personagem, x, y);
}

int ehparede(Mapa *mapa, int x, int y) {
    return mapa->matriz[x][y] == PAREDE_VERTICAL || mapa->matriz[x][y] == PAREDE_HORIZONTAL;
}

int ehpersonagem(Mapa *mapa, char personagem, int x, int y) {
    return mapa->matriz[x][y] == personagem;
}
