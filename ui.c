#include <stdio.h>
#include <stdio.h>
#include "mapa.h"

char desenhofantasma[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char desenhoparede[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};
char desenhoheroi[4][7] = {
    {" .--. " },
    {"/ _.-'" },
    {"\\ '-." },
    {" '--' " }
};
char desenhopilula[4][7] = {
    {"     "},
    {" .-. "},
    {" '-' "},
    {"     "}
};
char desenhovazio[4][7] = {
    {"     "},
    {"     "},
    {"     "},
    {"     "}
};

void imprimeparte(char desenho[4][7], int parte) {
    printf("%s", desenho[parte]);
}

void imprimemapa(Mapa *mapa) {
    for (int i = 0; i < mapa->linhas; ++i) {
        for (int parte = 0; parte < 4; parte++) {
            for (int j = 0; j < mapa->colunas; j++) {
                switch (mapa->matriz[i][j]) {
                    case FANTASMA:
                        imprimeparte(desenhofantasma, parte);
                        break;
                    case HEROI:
                        imprimeparte(desenhoheroi, parte);
                        break;
                    case PILULA:
                        imprimeparte(desenhopilula, parte);
                        break;
                    case PAREDE_VERTICAL:
                    case PAREDE_HORIZONTAL:
                        imprimeparte(desenhoparede, parte);
                        break;
                    case VAZIO:
                        imprimeparte(desenhovazio, parte);
                        break;
                    default:

                }
            }
            printf("\n");
        }
    }
}

