#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "aritmetica.h"


int main(int argc, char*argv[]) { //Calculadora

  setlocale(LC_ALL, "Portuguese");

  int x, y, z; //Numero 1,2 e o resultado.
  char operacao;

  printf("--------------------------------------------------------------\n");
  printf("-        Seja bem vindo a melhor calculadora do mundo        -\n");
  printf("--------------------------------------------------------------\n\n");

  printf("Para comecarmos, digite uma operacao:\n\n");
  printf("Lista de operacoes:\n\n+ -> Adicao\n- -> Subtracao\n* -> Multiplicacao\n/ -> Divisao\n\n");
  printf("Digite aqui o simbolo da operacao desejada:");
  operacao = getchar();

  printf("Digite dois valores:");
  scanf("%d %d", &x,&y);

  
  switch (operacao) {
    case '+': z = soma(x, y); break;
    case '-': z = subtracao(x, y); break;
  
  default: z = soma(x, y);
  }

    printf("\n\nO resultado: %d", z);

    return 0;







}
