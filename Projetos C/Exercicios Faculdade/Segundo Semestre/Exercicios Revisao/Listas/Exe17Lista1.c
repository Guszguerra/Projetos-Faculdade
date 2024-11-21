/*2.9. Leia o salário de um trabalhador e o valor da prestação de um empréstimo. Se a prestação for maior que 20% do
salário imprima: Empréstimo não concedido, caso contrário imprima: Empréstimo concedido.*/

#include <stdio.h>

int main(){
    float sal = 0, prest = 0;

    printf("Digite o valor do seu salario e da prestacao em seguida: ");
    scanf("%f %f", &sal, &prest);

    if(prest > (sal /100) * 20)
        printf("Emprestimo nao concedido");
    else
        printf("Emprestimo concedido");
    return 0;
}
