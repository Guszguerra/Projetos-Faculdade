#include <stdio.h>
#include <stdlib.h>

//Explique o que acontece no seguinte código e qual será sua saída:

int main(){
    int x = 10, y = 20, *p; //variavel x recebe 10, y 20 e é criado um ponteiro inteiro indentificado por p
    p = &x; //o ponteiro p aponta para o espaço de memória da variavel x
    *p = 30; //o espaço de memória para qual o ponteiro p aponta(variavel x) recebe valor 30
    p = &y; //ponteiro p começa a apontar para o espaço de memoria da variavel y
    *p = 40; //o espaço de memoria para qual o ponteiro p aponta(var y) recebe valor 40
    printf("%d %d", x, y); //será impresso: 30 40

}
