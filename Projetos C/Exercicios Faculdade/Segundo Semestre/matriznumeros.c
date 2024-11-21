#include <stdio.h>

int main(){

    int n=0,i=0,j=0,num=0;

    printf("Qual é o tamanho da matriz?");
    scanf("%d", &n);

    int matriz[n][n];

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i<j)
                matriz[i][j] = 0;
            else if(i==j)
                matriz[i][j] = i + 1;
            else
                matriz[i][j] = j + 1;
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
}
