#include <stdio.h>
//Tabuleiro Batalha Naval, em uma matriz [10][10]
int main() {
    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[10][10];
    
    printf("tabuleiro Batalha Naval!\n");
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; //representa a água '0'
            
        }
    }
    //NAVIOS
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;

    tabuleiro[3][6] = 3;
    tabuleiro[4][6] = 3;
    tabuleiro[5][6] = 3;
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