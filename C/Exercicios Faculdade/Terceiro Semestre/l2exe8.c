// Escreva um programa (não é necessário escrever uma função) que armazena, usando um
// laço, em um array a soma dos elementos dos seguintes arrays:

//double a[] = {5, 9, 3, 0, 3, 5.6};
//double b[] = {8, 8.1, 3, 9, 1, 0};

int main(){
    double a[] = {5, 9, 3, 0, 3, 5.6}, b[] = {8, 8.1, 3, 9, 1, 0}, arraysoma[6];
    int tamanho = sizeof(a) / sizeof(a[0]), i=0;

    double soma = 0.0;
    for(i=0;i<tamanho;i++)
        arraysoma[i] = a[i] + b[i];

    for(i=0;i<tamanho;i++)
        printf("%.2f\n", arraysoma[i]);

}
