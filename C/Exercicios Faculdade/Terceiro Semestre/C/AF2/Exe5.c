#include <stdio.h>
#define MAX 10
/*
Pilha Estática
Implemente uma pilha estática para armazenar números inteiros, incluindo
funções para push, pop e topo.*/

typedef struct{
    int valores[MAX];
    int topo;
} Pilha;

void inicializa(Pilha *ptr);
int push(Pilha *ptr, int valor);
int pop(Pilha *ptr);
int topo(Pilha *ptr, int *valor);
void visualizar(Pilha *ptr);


int main(){
    int opcao = 0, num = 0, valmaior = 0;

    Pilha p;

    while(1){
        printf("Por favor, selecione uma opcao. \n1- Inicializar pilha. \n2- Adicionar elemento.\n3- Remover Elemento. \n4- Ver topo. \n5- Visualizar Pilha");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                inicializa(&p);
                break;
            case 2:
                printf("Qual numero vc deseja adicionar a pilha? \n");
                scanf("%d", &num);
                push(&p, num);
                break;
            case 3:
                pop(&p);
                break;
            case 4:
                if(topo(&p, &valmaior) == 0){
                    printf("O topo da pilha e: %d\n", valmaior);
                }
                else{
                    printf("Pilha vazia \n");
                }

                break;
            case 5:
                visualizar(&p);
                break;
        }
    }

}

void inicializa(Pilha *ptr){
    ptr->topo = -1; //Indica pilha vazia
}

int push(Pilha *ptr, int valor){
    //Primeiro verificar se a pilha esta cheia
    //Pilha esta cheia qnd o topo é igual ao Numero MAX - 1, (pq os indices vao de 0 até N - 1
    if(ptr->topo == MAX - 1){ //pilha esta cheia
        printf("A pilha esta cheia. \n");
        return 1;
    }

    ptr->valores[++ptr->topo] = valor;
}

int pop(Pilha *ptr){
    //Primeiro verificar se pilha esta vazia
    if(ptr->topo == -1){
        printf("A pilha esta vazia");
        return 1;
    }

    ptr->topo--;
}

int topo(Pilha *ptr, int *valor){
    if(ptr->topo == -1){ //Verificando de a pilha esta vazia
        return 1;
    }
    *valor = ptr->valores[ptr->topo];
    return 0;
}

void visualizar(Pilha *ptr){
    if(ptr->topo == -1){
        printf("Pilha vazia. \n");
        return;
    }

    else{
        int i = 0;
        for(i=0;i <= ptr->topo;i++){
            printf("%d\n", ptr->valores[i]);
        }
    }
}


