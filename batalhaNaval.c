#include <stdio.h>
#include <stdlib.h>
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
    printf("\n");
    //cordenadas centrais do ataque
    int centro_X = 4;
    int centro_Y = 4;

    //---habilidade 1: Matriz cone---
    //limites da área de ataque 5x5: centro-2 a centro+2
    for (int i = centro_X - 2; i <= centro_X + 2; i++) {
        for (int j = centro_Y - 2; j <= centro_Y + 2; j++) {
            //condicional: desenha um cone(expande para baixo a partir do topo)
            if (i >= centro_X && (i - centro_X >= abs(j - centro_Y)) ) {
                if (i >= 0 && i < 10 && j >= 0 && j < 10) { //verifica os limites do tabuleiro
                    tabuleiro[i][j] = 7; //ataque em CONE, marca com '7'
                }
            }
        }
    } 

    //---habilidade 2: Matriz cruz---
    for (int i = centro_X - 2; i <= centro_X + 2; i++) {
        for (int j = centro_Y - 2; j <= centro_Y + 2; j++) {
            //condicional: linha central ou coluna central da área 5x5
            if (i == centro_X || j == centro_Y) {
                if (i >= 0 && i < 10 && j >= 0 && j < 10) { //verifica os limites do tabuleiro
                    tabuleiro[i][j] = 4; //ataque em CRUZ, marca com '4'    
                }
            }
        }
    }

    //---habilidade 3: matriz Octaedro---
    for (int i = centro_X - 2; i <= centro_X + 2; i++) {
        for (int j = centro_Y - 2; j <= centro_Y + 2; j++) {
            //condicional: soma das distâncias (distância de manhattan) menor ou igual a 2
            if (abs(i - centro_X) + abs(j - centro_Y) <= 2) {
                if (i >= 0 && i < 10 && j >= 0 && j < 10) { //verifica os limites do tabuleiro
                    tabuleiro[i][j] = 5; //ataque em OCTAEDRO, marca com '5'
                }
            }
        }
    }
    //imprime o tabuleiro após a adição dos ataques
     //cabeçalho das colunas a-j
    printf("   ");
    for (int j = 0; j < 10; j++) {
        printf("%c ", linha[j]);
    }
    printf("\n");
    
    for (int i = 0; i < 10; i++) {
        printf("%2d", i);
        for (int j = 0; j <10; j++) {
            printf("%2d", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
            
}