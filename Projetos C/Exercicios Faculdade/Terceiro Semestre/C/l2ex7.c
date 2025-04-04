//Escreva uma função que recebe um array de inteiros e seu tamanho e imprime somente os
//elementos com índices par, isto é, os elementos nas posições 0, 2, 4, 6 etc.

void imprimePar(int a[], int t);

int main() {
    int array[] = {5, 4, 2, 9, 8, 32}, tamanho = sizeof(array) / sizeof(array[0]);
    imprimePar(array, tamanho);
    return 0;
}

void imprimePar(int a[], int t){
    int i = 0;
    for(i=0;i<t;i++){
        if(a[i] % 2 == 0)
            printf("%d\n", a[i]);
    }
}
