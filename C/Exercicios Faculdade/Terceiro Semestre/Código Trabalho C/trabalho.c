#include <stdio.h>   // Biblioteca padrão para entrada e saída
#include <stdlib.h>  // Biblioteca padrão para alocação de memória e outras funções
#include <ctype.h>   // Biblioteca para funções de manipulação de caracteres

// Função para comparar dois inteiros (usada na ordenação da mediana)
int compara(const void *a, const void *b) {
    return (*(int *)a - *(int *)b); // Retorna a diferença entre os valores apontados
}

// Aplica o filtro da mediana em uma imagem representada como matriz
void filtro_mediana(int altura, int largura, int **imagem) {
    // Aloca uma cópia da matriz para preservar os valores originais
    int **copia = (int **)malloc(altura * sizeof(int *));
    for (int i = 0; i < altura; i++)
        copia[i] = (int *)malloc(largura * sizeof(int));

    // Copia a imagem original para a matriz auxiliar
    for (int i = 0; i < altura; i++)
        for (int j = 0; j < largura; j++)
            copia[i][j] = imagem[i][j];

    // Percorre a matriz aplicando a mediana em uma janela 3x3
    for (int i = 1; i < altura - 1; i++) {
        for (int j = 1; j < largura - 1; j++) {
            int vetor[9], k = 0;

            // Coleta os valores da vizinhança 3x3
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    vetor[k++] = copia[i + di][j + dj];
                }
            }

            // Ordena os valores e atribui a mediana ao pixel central
            qsort(vetor, 9, sizeof(int), compara);
            imagem[i][j] = vetor[4]; // O elemento do meio é a mediana
        }
    }

    // Libera a memória alocada para a cópia
    for (int i = 0; i < altura; i++)
        free(copia[i]);
    free(copia);
}

// Função para ler uma imagem PGM (Portable GrayMap)
int lerPGM(const char *nomeArquivo, int *altura, int *largura, int ***imagem) {
    FILE *arquivo = fopen(nomeArquivo, "rb"); // Abre o arquivo em modo binário
    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return 0;
    }

    char tipo[3];
    int maxValor;

    // Lê o tipo do arquivo (P2 ou P5)
    fscanf(arquivo, "%2s", tipo);

    // Ignora comentários (linhas que começam com '#')
    char c;
    while ((c = fgetc(arquivo)) == '#') {
        while (fgetc(arquivo) != '\n');
    }
    ungetc(c, arquivo); // Devolve o caractere para a stream

    // Lê dimensões da imagem e valor máximo
    fscanf(arquivo, "%d %d %d", largura, altura, &maxValor);
    fgetc(arquivo); // Consome a quebra de linha

    // Aloca memória para a matriz de pixels
    *imagem = (int **)malloc(*altura * sizeof(int *));
    for (int i = 0; i < *altura; i++)
        (*imagem)[i] = (int *)malloc(*largura * sizeof(int));

    // Se o formato for ASCII (P2), lê diretamente os valores
    if (tipo[0] == 'P' && tipo[1] == '2') {
        for (int i = 0; i < *altura; i++)
            for (int j = 0; j < *largura; j++)
                fscanf(arquivo, "%d", &(*imagem)[i][j]);
    }
    // Se for binário (P5), lê os bytes e converte para inteiro
    else if (tipo[0] == 'P' && tipo[1] == '5') {
        printf("Arquivo está no formato binário (P5), convertendo para P2...\n");
        for (int i = 0; i < *altura; i++)
            for (int j = 0; j < *largura; j++)
                (*imagem)[i][j] = fgetc(arquivo);
    }
    else {
        printf("Formato inválido! Apenas PGM ASCII (P2) ou binário (P5) são suportados.\n");
        fclose(arquivo);
        return 0;
    }

    fclose(arquivo);
    return 1; // Retorna sucesso
}

// Função para salvar uma imagem no formato PGM ASCII (P2)
void salvarPGM(const char *nomeArquivo, int altura, int largura, int **imagem) {
    FILE *arquivo = fopen(nomeArquivo, "w"); // Abre o arquivo para escrita
    if (!arquivo) {
        printf("Erro ao criar o arquivo %s\n", nomeArquivo);
        return;
    }

    // Escreve o cabeçalho do arquivo PGM
    fprintf(arquivo, "P2\n");
    fprintf(arquivo, "%d %d\n", largura, altura);
    fprintf(arquivo, "255\n"); // Valor máximo de intensidade

    // Escreve os pixels da imagem
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            fprintf(arquivo, "%d ", imagem[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
}

int main() {
    int **imagem;
    int largura, altura;
    const char *arquivoEntrada = "entrada.pgm";
    const char *arquivoSaida = "saida.pgm";

    // Lê a imagem PGM e converte para P2 se necessário
    printf("Lendo a imagem PGM...\n");
    if (!lerPGM(arquivoEntrada, &altura, &largura, &imagem)) {
        printf("Erro ao ler a imagem.\n");
        return 1;
    }

    printf("Imagem carregada: %dx%d\n", largura, altura);
    printf("Aplicando filtro da mediana...\n");

    // Aplica o filtro da mediana na imagem
    filtro_mediana(altura, largura, imagem);

    // Salva a imagem processada em um novo arquivo
    salvarPGM(arquivoSaida, altura, largura, imagem);

    // Libera a memória alocada para a imagem
    for (int i = 0; i < altura; i++)
        free(imagem[i]);
    free(imagem);

    printf("Imagem processada salva em: %s\n", arquivoSaida);
    return 0;
}
