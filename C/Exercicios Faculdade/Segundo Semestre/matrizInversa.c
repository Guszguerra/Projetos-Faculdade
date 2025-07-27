//Inserir elemento no inicio do vetor

#include <stdio.h>

int main(){

    int lista[10], i, encontrou = 0;

    for(i=0;i<10;i++){
        int numero;
        printf("\n Digite um numero p/ ir pro inicio do array: \n");
        scanf("%d", &numero);

    int encontrou = 0; //encontrou começa como falso

        for(i=0;i<5;i++){
            if(lista[i] == numero){
                encontrou = 1;
                break;
            }
        }

        if(encontrou)
            printf("Numero encontrado na lista\n.");
        else
            printf("Numero nao encontrado.\n");

        int k;
        for(k=i;k>0;k--) //k = execução //enquanto k for maior q 0, ele diminui
         lista[k] = lista[k-1]; //valores da lista vão ser atualizados para sempre irem pro indice anterior
        lista[0] = numero; // primeiro valor do array sempre começa com o primeiro n
    }

    for(i=0;i<10;i++){
        printf("%d", lista[i]);
    }
}
