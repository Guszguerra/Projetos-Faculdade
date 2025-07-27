
// Nome do aluno: Gustavo Bispo Guerra
#include <stdio.h>    // Inclui a biblioteca padr�o de entrada e sa�da
#include <string.h>   // Inclui a biblioteca para manipula��o de strings
#include <locale.h>   // Inclui a biblioteca para defini��o de localidade

// Define a estrutura Carro com tr�s campos: modelo, ano e preco
typedef struct {
    char modelo[50];  // Campo para armazenar o nome do modelo do carro
    int ano;          // Campo para armazenar o ano do carro
    double preco;     // Campo para armazenar o pre�o do carro
} Carro;

// Fun��o para modificar o pre�o de um Carro
void modificarPreco(Carro *c, double novoPreco) {
    c->preco = novoPreco; // Atualiza o campo 'preco' do carro para o novo pre�o
}

// Fun��o para imprimir os dados de um Carro
void imprimirCarro(Carro *c) {
    printf("Modelo: %s\n", c->modelo);          // Exibe o modelo do carro
    printf("Ano: %d\n", c->ano);                // Exibe o ano do carro
    printf("Pre�o: R$ %.2lf\n", c->preco);      // Exibe o pre�o do carro formatado com 2 casas decimais
}

// Fun��o principal do programa
int main() {
    setlocale(LC_ALL, "portuguese"); // Define a localidade para portugu�s (exibe os valores no formato brasileiro)

    Carro carro1;  // Declara uma vari�vel do tipo Carro

    // Define o modelo, ano e pre�o inicial do carro
    strcpy(carro1.modelo, "XYZ");  // Copia o nome "XYZ" para o campo 'modelo' de carro1
    carro1.ano = 2020;             // Define o ano do carro como 2020
    carro1.preco = 90000.00;       // Define o pre�o inicial do carro como 90000.00

    // Imprime os dados do carro antes da modifica��o do pre�o
    printf("Dados antes da modifica��o do pre�o:\n");
    imprimirCarro(&carro1);  // Chama a fun��o para imprimir os dados de carro1

    // Modifica o pre�o do carro para 115000.00
    modificarPreco(&carro1, 115000.00);  // Chama a fun��o para modificar o pre�o de carro1

    // Imprime os dados do carro ap�s a modifica��o do pre�o
    printf("\nDados ap�s a modifica��o do pre�o:\n");
    imprimirCarro(&carro1);  // Chama a fun��o para imprimir os dados de carro1 ap�s a modifica��o

    return 0;  // Retorna 0 para indicar que o programa terminou com sucesso
}
