
// Nome do aluno: Gustavo Bispo Guerra
#include <stdio.h>    // Inclui a biblioteca padrão de entrada e saída
#include <string.h>   // Inclui a biblioteca para manipulação de strings
#include <locale.h>   // Inclui a biblioteca para definição de localidade

// Define a estrutura Carro com três campos: modelo, ano e preco
typedef struct {
    char modelo[50];  // Campo para armazenar o nome do modelo do carro
    int ano;          // Campo para armazenar o ano do carro
    double preco;     // Campo para armazenar o preço do carro
} Carro;

// Função para modificar o preço de um Carro
void modificarPreco(Carro *c, double novoPreco) {
    c->preco = novoPreco; // Atualiza o campo 'preco' do carro para o novo preço
}

// Função para imprimir os dados de um Carro
void imprimirCarro(Carro *c) {
    printf("Modelo: %s\n", c->modelo);          // Exibe o modelo do carro
    printf("Ano: %d\n", c->ano);                // Exibe o ano do carro
    printf("Preço: R$ %.2lf\n", c->preco);      // Exibe o preço do carro formatado com 2 casas decimais
}

// Função principal do programa
int main() {
    setlocale(LC_ALL, "portuguese"); // Define a localidade para português (exibe os valores no formato brasileiro)

    Carro carro1;  // Declara uma variável do tipo Carro

    // Define o modelo, ano e preço inicial do carro
    strcpy(carro1.modelo, "XYZ");  // Copia o nome "XYZ" para o campo 'modelo' de carro1
    carro1.ano = 2020;             // Define o ano do carro como 2020
    carro1.preco = 90000.00;       // Define o preço inicial do carro como 90000.00

    // Imprime os dados do carro antes da modificação do preço
    printf("Dados antes da modificação do preço:\n");
    imprimirCarro(&carro1);  // Chama a função para imprimir os dados de carro1

    // Modifica o preço do carro para 115000.00
    modificarPreco(&carro1, 115000.00);  // Chama a função para modificar o preço de carro1

    // Imprime os dados do carro após a modificação do preço
    printf("\nDados após a modificação do preço:\n");
    imprimirCarro(&carro1);  // Chama a função para imprimir os dados de carro1 após a modificação

    return 0;  // Retorna 0 para indicar que o programa terminou com sucesso
}
