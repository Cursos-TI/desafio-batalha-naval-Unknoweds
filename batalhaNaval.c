#include <stdio.h>
//Tabuleiro Batalha Naval, em uma matriz [10][10]

int main() {
    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[10][10];
    
    printf("tabuleiro Batalha Naval!\n");
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; //inicializa com água '0'
            
        }
    }
    //NAVIOS
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;

    tabuleiro[3][3] = 3;
    tabuleiro[3][4] = 3;
    tabuleiro[3][5] = 3;

    //NAVIOS EM DIAGONAL
    // navio 1 de 3 casas na diagonal cima/direita
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][i] = 3; //navio de 3 casas em diagonal
    }
    // navio 2 de 3 casas na diagonal baixo/esquerda
    for (int i = 0; i < 3; i++) {
        tabuleiro[9 - i][i] = 3; //navio de 3 casas em diagonal
    }
    //cabeçalho das colunas a-j
    printf("   ");
    for (int j = 0; j < 10; j++) {
        printf("%c ", linha[j]);
    } 
    printf("\n");
    //cabeçalho das linhas
    for (int i = 0; i < 10; i++) {
        printf("%2d", i);
        for (int j = 0; j <10; j++) {
        printf("%2d", tabuleiro[i][j]);
    }
    printf("\n");
    }

    return 0;
            
}