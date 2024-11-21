
// Nome do aluno: Gustavo Bispo Guerra
#include <stdio.h>  // Inclui a biblioteca padrão de entrada e saída

// Declaração da função calcularResultado, que recebe um vetor e seu tamanho como parâmetros
int calcularResultado(int v[], int n);

int main() {
    int vetor[5], i, resultado;  // Declara um vetor de inteiros com 5 elementos e duas variáveis inteiras 'i' e 'resultado'

    // Loop para preencher o vetor com múltiplos de 2
    for (i = 0; i < 5; i++) {
        vetor[i] = i * 2;  // Atribui a cada posição do vetor o valor de 'i' multiplicado por 2
    }

    // Chama a função calcularResultado para obter a soma dos elementos do vetor
    resultado = calcularResultado(vetor, 5);

    // Exibe o resultado calculado
    printf("O resultado é: %d\n", resultado);

    return 0;  // Retorna 0 para indicar que o programa terminou com sucesso
}

// Função para calcular a soma dos elementos de um vetor
int calcularResultado(int v[], int n) {
    int i, soma = 0;  // Declara uma variável de controle 'i' e inicializa 'soma' como 0

    // Loop para somar todos os elementos do vetor
    for (i = 0; i < n; i++) {
        soma += v[i];  // Adiciona o valor de cada elemento do vetor 'v' à variável 'soma'
    }

    return soma;  // Retorna o valor da soma dos elementos do vetor
}
