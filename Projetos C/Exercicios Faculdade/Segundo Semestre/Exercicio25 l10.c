#include <stdio.h>
#include <stdlib.h>

typedef struct disciplina t_disciplina;
struct disciplina {
    int cod;
    char *nome;
    int creditos;
};

int main(){
    t_disciplina *pe = malloc(sizeof(t_disciplina));
    pe->cod = 555;
    pe->nome = "Programacao";
    pe->creditos = 4;

    printf("cod = %d \nnome = %s \ncreditos = %d\n",
           pe->cod, pe->nome,pe->creditos);
    free(pe);

    return 0;
}
