#include <stdio.h>

int main(){

    int jg1=0, jg2=0, jg3=0, i=0, j=0;
    int pontos[3][5];

    for(i=0;i<3;i++){ //Para cada linha(jogador) enquanto for menos q 3(0,1 e 2)

        for(j=0;j<5;j++){ //Para cada coluna(ponto) enquanto for menor q 5(0,1,2,3,4)
            printf("\nDigite um valor para a pontuacao: \n");
            scanf("%d", &pontos[i][j]);

            if(i==0)
                jg1 += pontos[i][j];

            else if(i==1)
                jg2 += pontos[i][j];

            else
                jg3 += pontos[i][j];
        }

    }

    printf("Jogador 1: %d pontos.", jg1);
    printf("Jogador 2: %d pontos.", jg2);
    printf("Jogador 3: %d pontos.", jg3);


    if(jg1 > jg2 && jg1 > jg3)
        printf("\nVencedor: Jogador 1.\n");
    else if(jg2 > jg1 && jg2 > jg3)
        printf("\nVencedor: Jogador 2.\n");
    else if(jg3 > jg1 && jg3 > jg2)
        printf("\nVencedor: Jogador 3.\n");
    else
        printf("\nEmpate entre os jogadores.\n");
}
