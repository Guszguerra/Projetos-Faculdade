#include <stdio.h> // Inclui a biblioteca padrão para entrada e saída de dados
#include <stdlib.h> // Inclui a biblioteca padrão para alocação de memória, controle de processos, etc.
#include <string.h> // Inclui a biblioteca padrão para manipulação de strings

#define MAX_CATEGORIAS 100 // Define o número máximo de categorias permitido
#define MAX_PRODUTOS 100 // Define o número máximo de produtos permitido
#define MAX_PEDIDOS 100 // Define o número máximo de pedidos permitido
#define MAX_CLIENTES 100 // Define o número máximo de clientes permitido

// Estrutura que representa uma categoria
typedef struct {
    int idCategoria; // Identificador único da categoria
    char nomeCategoria[50]; // Nome da categoria (máximo de 50 caracteres)
    char descricaoCategoria[100]; // Descrição da categoria (máximo de 100 caracteres)
} Categoria;

// Estrutura que representa um produto
typedef struct {
    int idProduto; // Identificador único do produto
    char nomeProduto[50]; // Nome do produto (máximo de 50 caracteres)
    char descricaoProduto[100]; // Descrição do produto (máximo de 100 caracteres)
    float preco; // Preço do produto
    int estoque; // Quantidade disponível no estoque
    int idCategoria; // Identificador da categoria associada ao produto
} Produto;

// Estrutura que representa um pedido
typedef struct {
    int idPedido; // Identificador único do pedido
    int idCliente; // Identificador do cliente que realizou o pedido
    char dataPedido[11]; // Data do pedido no formato "dd/mm/aaaa"
    float totalPedido; // Valor total do pedido
} Pedido;

// Estrutura que representa um cliente
typedef struct {
    int id; // Identificador único do cliente
    char nome[50]; // Nome do cliente (máximo de 50 caracteres)
    char sobrenome[50]; // Sobrenome do cliente (máximo de 50 caracteres)
    char telefone[20]; // Telefone do cliente (máximo de 20 caracteres)
    char email[50]; // E-mail do cliente (máximo de 50 caracteres)
    char endereco[100]; // Endereço do cliente (máximo de 100 caracteres)
} Cliente;

// Declaração das funções relacionadas à manipulação de categorias
void criarCategoria(Categoria *c); // Função para criar uma nova categoria
void mostrarCategoria(const Categoria categorias[], int numCategorias); // Função para exibir uma categoria específica
void alterarCategoria(Categoria *c); // Função para alterar os dados de uma categoria
int excluirCategoria(Categoria categorias[], int *numCategorias); // Função para excluir uma categoria
void carregarCategorias(Categoria categorias[], int *numCategorias); // Função para carregar categorias de um arquivo
void salvarCategorias(const Categoria categorias[], int numCategorias); // Função para salvar categorias em um arquivo

// Declaração das funções relacionadas à manipulação de produtos
void criarProduto(Produto *p); // Função para criar um novo produto
void mostrarProduto(const Produto produtos[], int numProdutos); // Função para exibir um produto específico
void alterarProduto(Produto *p); // Função para alterar os dados de um produto
int excluirProduto(Produto produtos[], int *numProdutos); // Função para excluir um produto
void carregarProdutos(Produto produtos[], int *numProdutos); // Função para carregar produtos de um arquivo
void salvarProdutos(const Produto produtos[], int numProdutos); // Função para salvar produtos em um arquivo

// Declaração das funções relacionadas à manipulação de pedidos
void criarPedido(Pedido *ped); // Função para criar um novo pedido
void mostrarPedido(const Pedido pedidos[], int numPedidos); // Função para exibir um pedido específico
void alterarPedido(Pedido *ped); // Função para alterar os dados de um pedido
int excluirPedido(Pedido pedidos[], int *numPedidos); // Função para excluir um pedido
void carregarPedidos(Pedido pedidos[], int *numPedidos); // Função para carregar pedidos de um arquivo
void salvarPedidos(const Pedido pedidos[], int numPedidos); // Função para salvar pedidos em um arquivo

// Função para criar uma nova categoria
void criarCategoria(Categoria *c) {
    printf("Digite o ID da Categoria: ");
    scanf("%d", &c->idCategoria); // Lê o ID e armazena no campo idCategoria da struct Categoria

    printf("Digite o Nome da Categoria: ");
    scanf(" %[^\n]", c->nomeCategoria); // Lê o nome da categoria, permitindo espaços

    printf("Digite a Descricao da Categoria: ");
    scanf(" %[^\n]", c->descricaoCategoria); // Lê a descrição da categoria, permitindo espaços

    printf("Categoria criada com sucesso!\n"); // Mensagem de sucesso
}

// Função para mostrar uma categoria específica
void mostrarCategoria(const Categoria categorias[], int numCategorias) {
    int id;
    printf("Digite o ID da Categoria a ser mostrado: ");
    scanf("%d", &id); // Lê o ID que o usuário quer visualizar

    for (int i = 0; i < numCategorias; i++) { // Itera por todas as categorias armazenadas
        if (categorias[i].idCategoria == id) { // Se encontrar a categoria com o ID fornecido
            printf("ID da Categoria: %d\n", categorias[i].idCategoria);
            printf("Nome da Categoria: %s\n", categorias[i].nomeCategoria);
            printf("Descricao da Categoria: %s\n", categorias[i].descricaoCategoria);
            return; // Encerra a função após mostrar a categoria
        }
    }
    printf("Categoria com ID %d nao encontrada.\n", id); // Mensagem de erro se não encontrar
}

// Função para alterar os dados de uma categoria
void alterarCategoria(Categoria *c) {
    printf("Digite o novo Nome da Categoria: ");
    scanf(" %[^\n]", c->nomeCategoria); // Lê o novo nome da categoria

    printf("Digite a nova Descrição da Categoria: ");
    scanf(" %[^\n]", c->descricaoCategoria); // Lê a nova descrição da categoria

    printf("Categoria alterada com sucesso!\n"); // Mensagem de sucesso
}

// Função para excluir uma categoria
int excluirCategoria(Categoria categorias[], int *numCategorias) {
    int id;
    printf("Digite o ID da Categoria a ser excluida: ");
    scanf("%d", &id); // Lê o ID da categoria a ser excluída

    for (int i = 0; i < *numCategorias; i++) { // Itera pelas categorias
        if (categorias[i].idCategoria == id) { // Se encontrar a categoria com o ID fornecido
            categorias[i] = categorias[--(*numCategorias)]; // Remove a categoria, deslocando as demais
            printf("Categoria excluída com sucesso!\n"); // Mensagem de sucesso
            return 1; // Retorna 1 indicando sucesso
        }
    }
    printf("Categoria com ID %d nao encontrada.\n", id); // Mensagem de erro se não encontrar
    return 0; // Retorna 0 indicando falha
}

// Função para carregar categorias a partir de um arquivo
void carregarCategorias(Categoria categorias[], int *numCategorias) {
    FILE *file = fopen("categorias.txt", "r"); // Tenta abrir o arquivo categorias.txt para leitura
    if (file == NULL) { // Se o arquivo não for encontrado
        printf("Arquivo de categorias não encontrado. Criando um novo.\n");
        return; // Retorna sem fazer nada se o arquivo não for encontrado
    }

    while (fscanf(file, "%d %[^\n] %[^\n]", &categorias[* numCategorias].idCategoria, categorias[*numCategorias].nomeCategoria, categorias[*numCategorias].descricaoCategoria) != EOF) {
        if (*numCategorias < MAX_CATEGORIAS) { // Verifica se não ultrapassou o limite
            (*numCategorias)++; // Incrementa o contador de categorias
        } else {
            printf("Limite de categorias atingido ao carregar.\n"); // Mensagem se o limite for atingido
            break; // Encerra o loop se o limite for atingido
        }
    }
    fclose(file); // Fecha o arquivo após leitura
}

// Função para salvar as categorias em um arquivo
void salvarCategorias(const Categoria categorias[], int numCategorias) {
    FILE *file = fopen("categorias.txt", "w"); // Abre o arquivo categorias.txt para escrita
    for (int i = 0; i < numCategorias; i++) { // Percorre todas as categorias
        fprintf(file, "%d %s %s\n", categorias[i].idCategoria, categorias[i].nomeCategoria, categorias[i].descricaoCategoria); // Escreve os dados da categoria no arquivo
    }
    fclose(file); // Fecha o arquivo após escrita
}

// Função para criar um novo produto
void criarProduto(Produto *p) {
    printf("Digite o ID do Produto: ");
    scanf("%d", &p->idProduto); // Lê o ID e armazena no campo idProduto da struct Produto

    printf("Digite o Nome do Produto: ");
    scanf(" %[^\n]", p->nomeProduto); // Lê o nome do produto, permitindo espaços

    printf("Digite a Descricao do Produto: ");
    scanf(" %[^\n]", p->descricaoProduto); // Lê a descrição do produto, permitindo espaços

    printf("Digite o Preco do Produto: ");
    scanf("%f", &p->preco); // Lê o preço do produto

    printf("Digite o Estoque do Produto: ");
    scanf("%d", &p->estoque); // Lê a quantidade em estoque do produto

    printf("Digite o ID da Categoria do Produto: ");
    scanf("%d", &p->idCategoria); // Lê o ID da categoria do produto

    printf("Produto criado com sucesso!\n"); // Mensagem de sucesso
}

// Função para mostrar os detalhes de um produto
void mostrarProduto(const Produto produtos[], int numProdutos) {
    int id;
    printf("Digite o ID do Produto a ser mostrado: ");
    scanf("%d", &id); // Lê o ID do produto que o usuário quer visualizar

    for (int i = 0; i < numProdutos; i++) { // Itera pelas categorias
        if (produtos[i].idProduto == id) { // Se encontrar o produto com o ID fornecido
            printf("ID do Produto: %d\n", produtos[i].idProduto);
            printf("Nome do Produto: %s\n", produtos[i].nomeProduto);
            printf("Descricao do Produto: %s\n", produtos[i].descricaoProduto);
            printf("Preco: %.2f\n", produtos[i].preco);
            printf("Estoque: %d\n", produtos[i].estoque);
            printf("ID da Categoria: %d\n", produtos[i].idCategoria);
            return; // Encerra a função após mostrar o produto
        }
    }
    printf("Produto com ID %d nao encontrado.\n", id); // Mensagem de erro se não encontrar
}

// Função para alterar os dados de um produto
void alterarProduto(Produto *p) {
    printf("Digite o novo Nome do Produto: ");
    scanf(" %[^\n]", p->nomeProduto); // Lê o novo nome do produto

    printf("Digite a nova Descricao do Produto: ");
    scanf(" %[^\n]", p->descricaoProduto); // Lê a nova descrição do produto

    printf("Digite o novo Preco do Produto: ");
    scanf("%f", &p->preco); // Lê o novo preço do produto

    printf("Digite o novo Estoque do Produto: ");
    scanf("%d", &p->estoque); // Lê a nova quantidade em estoque do produto

    printf("Digite o novo ID da Categoria do Produto: ");
    scanf("%d", &p->idCategoria); // Lê o novo ID da categoria do produto

    printf("Produto alterado com sucesso!\n"); // Mensagem de sucesso
}

// Função para excluir um produto
int excluirProduto(Produto produtos[], int *numProdutos) {
    int id;
    printf("Digite o ID do Produto a ser excluido: ");
    scanf("%d", &id); // Lê o ID do produto que o usuário deseja excluir

for (int i = 0; i < *numProdutos; i++) { // Percorre todos os produtos cadastrados
    if (produtos[i].idProduto == id) { // Verifica se o ID do produto corresponde ao fornecido pelo usuário
        produtos[i] = produtos[--(*numProdutos)]; // Substitui o produto excluído pelo último produto da lista e diminui o número de produtos
        printf("Produto excluido com sucesso!\n"); // Informa que o produto foi excluído
        return 1; // Retorna 1 indicando sucesso na exclusão
    }
}
    printf("Produto com ID %d nao encontrado.\n", id); // Caso não encontre o produto, exibe uma mensagem de erro
    return 0; // Retorna 0 indicando que a exclusão falhou
}

// Função para carregar os produtos a partir do arquivo "produtos.txt"
void carregarProdutos(Produto produtos[], int *numProdutos) {
    FILE *file = fopen("produtos.txt", "r"); // Abre o arquivo "produtos.txt" em modo leitura
    if (file == NULL) { // Verifica se o arquivo foi aberto corretamente
        printf("Arquivo de produtos não encontrado. Criando um novo.\n"); // Exibe uma mensagem caso o arquivo não exista
        return; // Retorna sem fazer nada se o arquivo não for encontrado
    }
    // Lê os dados dos produtos no arquivo e armazena nas variáveis correspondentes
    while (fscanf(file, "%d %[^\n] %[^\n] %f %d %d", &produtos[*numProdutos].idProduto, produtos[*numProdutos].nomeProduto, produtos[*numProdutos].descricaoProduto, &produtos[*numProdutos].preco, &produtos[*numProdutos].estoque, &produtos[*numProdutos].idCategoria) != EOF) {
        if (*numProdutos < MAX_PRODUTOS) { // Verifica se não ultrapassou o limite
            (*numProdutos)++; // Aumenta o número de produtos lidos
        } else {
            printf("Limite de produtos atingido ao carregar.\n"); // Mensagem se o limite for atingido
            break; // Encerra o loop se o limite for atingido
        }
    }
    fclose(file); // Fecha o arquivo após a leitura
}

// Função para salvar os produtos no arquivo "produtos.txt"
void salvarProdutos(const Produto produtos[], int numProdutos) {
    FILE *file = fopen("produtos.txt", "w"); // Abre o arquivo "produtos.txt" em modo escrita
    for (int i = 0; i < numProdutos; i++) { // Percorre todos os produtos cadastrados
        // Escreve os dados de cada produto no arquivo
        fprintf(file, "%d %s %s %.2f %d %d\n", produtos[i].idProduto, produtos[i].nomeProduto, produtos[i].descricaoProduto, produtos[i].preco, produtos[i].estoque, produtos[i].idCategoria);
    }
    fclose(file); // Fecha o arquivo após salvar os produtos
}

// Funções para Pedido
// Função para criar um novo pedido
void criarPedido(Pedido *ped) {
    printf("Digite o ID do Pedido: ");
    scanf("%d", &ped->idPedido); // Lê o ID do pedido
    printf("Digite o ID do Cliente: ");
    scanf("%d", &ped->idCliente); // Lê o ID do cliente que fez o pedido
    printf("Digite a Data do Pedido (dd/mm/aaaa): ");
    scanf(" %[^\n]", ped->dataPedido); // Lê a data do pedido
    printf("Digite o Total do Pedido: ");
    scanf("%f", &ped->totalPedido); // Lê o valor total do pedido
    printf("Pedido criado com sucesso!\n"); // Informa que o pedido foi criado com sucesso
}

// Função para mostrar os detalhes de um pedido
void mostrarPedido(const Pedido pedidos[], int numPedidos) {
    int id;
    printf("Digite o ID do Pedido a ser mostrado: ");
    scanf("%d", &id); // Lê o ID do pedido a ser exibido

    for (int i = 0; i < numPedidos; i++) { // Percorre todos os pedidos cadastrados
    if (pedidos[i].idPedido == id) { // Verifica se o ID do pedido corresponde ao fornecido
        // Exibe os detalhes do pedido
        printf("ID do Pedido: %d\n", pedidos[i].idPedido);
        printf("ID do Cliente: %d\n", pedidos[i].idCliente);
        printf("Data do Pedido: %s\n", pedidos[i].dataPedido); // Corrigido: removido duplicado
        printf("Total do Pedido: %.2f\n", pedidos[i].totalPedido);
        return; // Encerra a função após exibir o pedido
    }
}
    printf("Pedido com ID %d nao encontrado.\n", id); // Exibe uma mensagem de erro se o pedido não for encontrado
}

// Função para alterar um pedido existente
void alterarPedido(Pedido *ped) {
    printf("Digite o novo ID do Cliente: ");
    scanf("%d", &ped->idCliente); // Lê o novo ID do cliente
    printf("Digite a nova Data do Pedido (dd/mm/aaaa): ");
    scanf(" %[^\n]", ped->dataPedido); // Lê a nova data do pedido
    printf("Digite o novo Total do Pedido: ");
    scanf("%f", &ped->totalPedido); // Lê o novo valor total do pedido
    printf("Pedido alterado com sucesso!\n"); // Informa que o pedido foi alterado com sucesso
}

// Função para excluir um pedido
int excluirPedido(Pedido pedidos[], int *numPedidos) {
    int id;
    printf("Digite o ID do Pedido a ser excluido: ");
    scanf("%d", &id); // Lê o ID do pedido a ser excluído

    for (int i = 0; i < *numPedidos; i++) { // Percorre todos os pedidos cadastrados
        if (pedidos[i].idPedido == id) { // Verifica se o ID do pedido corresponde ao fornecido
            pedidos[i] = pedidos[--(*numPedidos)]; // Substitui o pedido excluído pelo último pedido da lista e diminui o número de pedidos
            printf("Pedido excluido com sucesso!\n"); // Informa que o pedido foi excluído
            return 1; // Retorna 1 indicando sucesso na exclusão
        }
    }
    printf("Pedido com ID %d nao encontrado.\n", id); // Exibe uma mensagem de erro se o pedido não for encontrado
    return 0; // Retorna 0 indicando falha na exclusão
}

// Função para carregar os pedidos a partir do arquivo "pedidos.txt"
void carregarPedidos(Pedido pedidos[], int *numPedidos) {
    FILE *file = fopen("pedidos.txt", "r"); // Abre o arquivo "pedidos.txt" em modo leitura
    if (file == NULL) { // Verifica se o arquivo foi aberto corretamente
        printf("Arquivo de pedidos não encontrado. Criando um novo.\n"); // Exibe uma mensagem caso o arquivo não exista
        return; // Retorna sem fazer nada se o arquivo não for encontrado
    }
    // Lê os dados dos pedidos no arquivo e armazena nas variáveis correspondentes
    while (fscanf(file, "%d %d %[^\n] %f", &pedidos[*numPedidos].idPedido, &pedidos[*numPedidos].idCliente, pedidos[*numPedidos].dataPedido, &pedidos[*numPedidos].totalPedido) != EOF) {
        if (*numPedidos < MAX_PEDIDOS) { // Verifica se não ultrapassou o limite
            (*numPedidos)++; // Aumenta o número de pedidos lidos
        } else {
            printf("Limite de pedidos atingido ao carregar.\n"); // Mensagem se o limite for atingido
            break; // Encerra o loop se o limite for atingido
        }
    }
    fclose(file); // Fecha o arquivo após a leitura
}

// Função para salvar os pedidos no arquivo "pedidos.txt"
void salvarPedidos(const Pedido pedidos[], int numPedidos) {
    FILE *file = fopen("pedidos.txt", "w"); // Abre o arquivo "pedidos.txt" em modo escrita
    for (int i = 0; i < numPedidos; i++) { // Percorre todos os pedidos cadastrados
        // Escreve os dados de cada pedido no arquivo
        fprintf(file, "%d %d %s %.2f\n", pedidos[i].idPedido, pedidos[i].idCliente, pedidos[i].dataPedido, pedidos[i].totalPedido);
    }
    fclose(file); // Fecha o arquivo após salvar os pedidos
}

// Função para criar um novo cliente
void criarCliente(Cliente *c) {
    printf("Digite o ID do Cliente: ");
    scanf("%d", &c->id); // Lê o ID do cliente
    printf("Digite o Nome do Cliente: ");
    scanf(" %[^\n]", c->nome); // Lê o nome do cliente
    printf("Digite o Sobrenome do Cliente: ");
    scanf(" %[^\n]", c->sobrenome); // Lê o sobrenome do cliente
    printf("Digite o Telefone do Cliente: ");
    scanf(" %[^\n]", c->telefone); // Lê o telefone do cliente
    printf("Digite o Email do Cliente: ");
    scanf(" %[^\n]", c->email); // Lê o email do cliente
    printf("Digite o Endereco do Cliente: ");
    scanf(" %[^\n]", c->endereco); // Lê o endereço do cliente
    printf("Cliente criado com sucesso!\n"); // Mensagem de sucesso
}

// Função que exibe os detalhes de um cliente com base no ID fornecido
void mostrarCliente(const Cliente clientes[], int numClientes) {
    int id; // Declara uma variável para armazenar o ID do cliente
    printf("Digite o ID do Cliente a ser mostrado: "); // Solicita ao usuário o ID do cliente
    scanf("%d", &id); // Lê o ID fornecido pelo usuário

    // Loop para percorrer todos os clientes cadastrados
    for (int i = 0; i < numClientes; i++) {
        // Verifica se o ID do cliente na posição i é igual ao ID fornecido
        if (clientes[i].id == id) {
            printf("ID: %d\n", clientes[i].id); // Exibe o ID do cliente
            printf("Nome: %s %s\n", clientes[i].nome, clientes[i].sobrenome); // Exibe o nome completo do cliente
            printf("Telefone: %s\n", clientes[i].telefone); // Exibe o telefone do cliente
            printf("Email: %s\n", clientes[i].email); // Exibe o e-mail do cliente
            printf("Endereco: %s\n", clientes[i].endereco); // Exibe o endereço do cliente
            return; // Encerra a função após mostrar o cliente encontrado
        }
    }
    printf("Cliente com ID %d nao encontrado.\n", id); // Exibe uma mensagem se o cliente não for encontrado
}

// Função que altera os dados de um cliente
void alterarCliente(Cliente *c) {
    printf("Digite o novo Nome do Cliente: "); // Solicita ao usuário o novo nome
    scanf(" %[^\n]", c->nome); // Lê o novo nome do cliente
    printf("Digite o novo Sobrenome do Cliente: "); // Solicita ao usuário o novo sobrenome
    scanf(" %[^\n]", c->sobrenome); // Lê o novo sobrenome do cliente
    printf("Digite o novo Telefone do Cliente: "); // Solicita ao usuário o novo telefone
    scanf(" %[^\n]", c->telefone); // Lê o novo telefone do cliente
    printf("Digite o novo Email do Cliente: "); // Solicita ao usuário o novo e-mail
    scanf(" %[^\n]", c->email); // Lê o novo e-mail do cliente
    printf("Digite o novo Endereço do Cliente: "); // Solicita ao usuário o novo endereço
    scanf(" %[^\n]", c->endereco); // Lê o novo endereço do cliente
    printf("Cliente alterado com sucesso!\n"); // Exibe uma mensagem indicando que o cliente foi alterado
}

// Função que exclui um cliente com base no ID
int excluirCliente(Cliente clientes[], int *numClientes) {
    int id; // Declara uma variável para armazenar o ID do cliente
    printf("Digite o ID do Cliente a ser excluido: "); // Solicita ao usuário o ID do cliente a ser excluído
    scanf("%d", &id); // Lê o ID fornecido pelo usuário

    // Loop que percorre todos os clientes cadastrados
    for (int i = 0; i < *numClientes; i++) {
        // Verifica se o cliente na posição i tem o ID igual ao fornecido
        if (clientes[i].id == id) {
            clientes[i] = clientes[--(*numClientes)]; // Remove o cliente, substituindo-o pelo último cliente da lista
            printf("Cliente excluido com sucesso!\n"); // Exibe uma mensagem indicando que o cliente foi excluído
            return 1; // Retorna 1 indicando que a exclusão foi bem-sucedida
        }
    }
    printf("Cliente com ID %d nao encontrado.\n", id); // Exibe uma mensagem se o cliente não for encontrado
    return 0; // Retorna 0 indicando que a exclusão falhou
}

// Função que carrega os dados dos clientes a partir de um arquivo
void carregarClientes(Cliente clientes[], int *numClientes) {
    FILE *file = fopen("clientes.txt", " r"); // Abre o arquivo "clientes.txt" em modo de leitura
    if (file == NULL) { // Se o arquivo não for encontrado
        printf("Arquivo de clientes não encontrado. Criando um novo.\n"); // Exibe uma mensagem
        return; // Retorna sem fazer nada
    }

    // Loop que lê os dados dos clientes do arquivo até o final
    while (fscanf(file, "%d %[^\n] %[^\n] %[^\n] %[^\n] %[^\n]", &clientes[*numClientes].id, clientes[*numClientes].nome, clientes[*numClientes].sobrenome, clientes[*numClientes].telefone, clientes[*numClientes].email, clientes[*numClientes].endereco) != EOF) {
        if (*numClientes < MAX_CLIENTES) { // Verifica se não ultrapassou o limite
            (*numClientes)++; // Incrementa o número de clientes carregados
        } else {
            printf("Limite de clientes atingido ao carregar.\n"); // Mensagem se o limite for atingido
            break; // Encerra o loop se o limite for atingido
        }
    }

    fclose(file); // Fecha o arquivo após a leitura
}

// Função que salva os dados dos clientes em um arquivo
void salvarClientes(const Cliente clientes[], int numClientes) {
    FILE *file = fopen("clientes.txt", "w"); // Abre o arquivo "clientes.txt" em modo de escrita
    // Loop para escrever os dados de cada cliente no arquivo
    for (int i = 0; i < numClientes; i++) {
        fprintf(file, "%d %s %s %s %s %s\n", clientes[i].id, clientes[i].nome, clientes[i].sobrenome, clientes[i].telefone, clientes[i].email, clientes[i].endereco); // Escreve os dados do cliente no arquivo
    }
    fclose(file); // Fecha o arquivo após a escrita
}

// Função principal do programa
int main() {
    Categoria categorias[MAX_CATEGORIAS]; // Declara um array para armazenar as categorias
    Produto produtos[MAX_PRODUTOS]; // Declara um array para armazenar os produtos
    Pedido pedidos[MAX_PEDIDOS]; // Declara um array para armazenar os pedidos
    Cliente clientes[MAX_CLIENTES]; // Declara um array para armazenar os clientes
    int numCategorias = 0, numProdutos = 0, numPedidos = 0, numClientes = 0; // Declara variáveis para contar o número de categorias, produtos, pedidos e clientes
    int escolha; // Declara uma variável para armazenar a escolha do usuário

    // Carrega os dados de categorias, produtos, pedidos e clientes a partir de arquivos
    carregarCategorias(categorias, &numCategorias);
    carregarProdutos(produtos, &numProdutos);
    carregarPedidos(pedidos, &numPedidos);
    carregarClientes(clientes, &numClientes);

    // Loop infinito para exibir o menu e capturar a escolha do usuário
    while (1) {
        printf("\nMenu:\n");
        printf("\n[1] Criar Categoria\n");
        printf("[2] Alterar Categoria\n");
        printf("[3] Excluir Categoria\n");
        printf("[4] Mostrar Categoria\n");
        printf("---------------------");
        printf("\n[5] Criar Produto\n");
        printf("[6] Alterar Produto\n");
        printf("[7] Excluir Produto\n");
        printf("[8] Mostrar Produto\n");
        printf("---------------------");
        printf("\n[9] Criar Pedido\n");
        printf("[10] Alterar Pedido\n");
        printf("[11] Excluir Pedido\n");
        printf("[12] Mostrar Pedido\n");
        printf("---------------------");
        printf("\n[13] Criar Cliente\n");
        printf("[14] Alterar Cliente\n");
        printf("[15] Excluir Cliente\n");
        printf("[16] Mostrar Cliente\n");
        printf("---------------------");
        printf("\n[17] Sair\n");
        printf("---------------------\n");
        printf("\nEscolha uma opcao: "); // Solicita ao usuário uma opção
        scanf("%d", &escolha); // Lê a opção escolhida pelo usuário

        switch (escolha) { // Inicia o bloco switch, que irá decidir a ação com base no valor de 'escolha'
            case 1: // Caso a escolha seja 1, o usuário deseja criar uma nova categoria
                if (numCategorias < MAX_CATEGORIAS) { // Verifica se não ultrapassou o limite
                    criarCategoria(&categorias[numCategorias++]); // Chama a função para criar uma nova categoria e incrementa o número de categorias
                    salvarCategorias(categorias, numCategorias); // Salva as categorias no arquivo
        } else {
                    printf("Limite de categorias atingido.\n"); // Mensagem se o limite for atingido
                }
                break; // Finaliza o case 1
            case 2: // Caso a escolha seja 2, o usuário deseja alterar uma categoria existente
                if (numCategorias > 0) { // Verifica se existem categorias para alterar
                    alterarCategoria(&categorias[numCategorias - 1]); // Chama a função para alterar a última categoria adicionada
                    salvarCategorias(categorias, numCategorias); // Salva as categorias atualizadas
                } else { // Se não houver categorias, exibe uma mensagem de erro
                    printf("Nenhuma categoria disponivel para alterar.\n");
                }
                break; // Finaliza o case 2
            case 3: // Caso a escolha seja 3, o usuário deseja excluir uma categoria
                if (excluirCategoria(categorias, &numCategorias)) { // Chama a função para excluir uma categoria e verifica se a exclusão foi bem-sucedida
                    salvarCategorias(categorias, numCategorias); // Salva as categorias atualizadas após a exclusão
                }
                break; // Finaliza o case 3
            case 4: // Caso a escolha seja 4, o usuário deseja exibir as categorias
                mostrarCategoria(categorias, numCategorias); // Chama a função para mostrar todas as categorias
                break; // Finaliza o case 4
            case 5: // Caso a escolha seja 5, o usuário deseja criar um novo produto
                if (numProdutos < MAX_PRODUTOS) { // Verifica se não ultrapassou o limite
                    criarProduto(&produtos[numProdutos++]); // Chama a função para criar um novo produto e incrementa o número de produtos
                    salvarProdutos(produtos, numProdutos); // Salva os produtos no arquivo
                } else {
                    printf("Limite de produtos atingido.\n"); // Mensagem se o limite for atingido
                }
                break; // Finaliza o case 5
            case 6: // Caso a escolha seja 6, o usuário deseja alterar um produto existente
                if (numProdutos > 0) { // Verifica se existem produtos para alterar
                    alterarProduto(&produtos[numProdutos - 1]); // Chama a função para alterar o último produto adicionado
                    salvarProdutos(produtos, numProdutos); // Salva os produtos atualizados
                } else { // Se não houver produtos, exibe uma mensagem de erro
                    printf("Nenhum produto disponivel para alterar.\n");
                }
                break; // Finaliza o case 6
            case 7: // Caso a escolha seja 7, o usuário deseja excluir um produto
                if (excluirProduto(produtos, &numProdutos)) { // Chama a função para excluir um produto e verifica se a exclusão foi bem-sucedida
                    salvarProdutos(produtos, numProdutos); // Salva os produtos atualizados após a exclusão
                }
                break; // Finaliza o case 7
            case 8: // Caso a escolha seja 8, o usuário deseja exibir os produtos
                mostrarProduto(produtos, numProdutos); // Chama a função para mostrar todos os produtos
                break; // Finaliza o case 8
            case 9: // Caso a escolha seja 9, o usuário deseja criar um novo pedido
                if (numPedidos < MAX_PEDIDOS) { // Verifica se não ultrapassou o limite
                    criarPedido(&pedidos[numPedidos++]); // Chama a função para criar um novo pedido e incrementa o número de pedidos
                    salvarPedidos(pedidos, numPedidos); // Salva os pedidos no arquivo
                } else {
                    printf("Limite de pedidos atingido.\n"); // Mensagem se o limite for atingido
                }
                break; // Finaliza o case 9
            case 10: // Caso a escolha seja 10, o usuário deseja alterar um pedido existente
                if (numPedidos > 0) { // Verifica se existem pedidos para alterar
                    alterarPedido(&pedidos[numPedidos - 1]); // Chama a função para alterar o último pedido adicionado
                    salvarPedidos(pedidos, numPedidos); // Salva os pedidos atualizados
                } else { // Se não houver pedidos, exibe uma mensagem de erro
                    printf("Nenhum pedido disponivel para alterar.\n");
                }
                break; // Finaliza o case 10
            case 11: // Caso a escolha seja 11, o usuário deseja excluir um pedido
                if (excluirPedido(pedidos, &numPedidos)) { // Chama a função para excluir um pedido e verifica se a exclusão foi bem-sucedida
                    salvarPedidos(pedidos, numPedidos); // Salva os pedidos atualizados após a exclusão
                }
                break; // Finaliza o case 11
            case 12: // Caso a escolha seja 12, o usuário deseja exibir os pedidos
                mostrarPedido(pedidos, numPedidos); // Chama a função para mostrar todos os pedidos
                break; // Finaliza o case 12
            case 13: // Caso a escolha seja 13, o usuário deseja criar um novo cliente
                if (numClientes < MAX_CLIENTES) { // Verifica se não ultrapassou o limite
                    criarCliente(&clientes[numClientes++]); // Chama a função para criar um novo cliente e incrementa o número de clientes
                    salvarClientes(clientes, numClientes); // Salva os clientes no arquivo
                } else {
                    printf("Limite de clientes atingido.\n"); // Mensagem se o limite for atingido
                }
                break; // Finaliza o case 13
            case 14: // Caso a escolha seja 14, o usuário deseja alterar um cliente existente
                if (numClientes > 0) { // Verifica se existem clientes para alterar
                    alterarCliente(&clientes[numClientes - 1]); // Chama a função para alterar o último cliente adicionado
                    salvarClientes(clientes, numClientes); // Salva os clientes atualizados
                } else { // Se não houver clientes, exibe uma mensagem de erro
                    printf("Nenhum cliente disponivel para alterar.\n");
                }
                break; // Finaliza o case 14
            case 15: // Caso a escolha seja 15, o usuário deseja excluir um cliente
                if (excluirCliente(clientes, &numClientes)) { // Chama a função para excluir um cliente e verifica se a exclusão foi bem-sucedida
                    salvarClientes(clientes, numClientes); // Salva os clientes atualizados após a exclusão
                }
                break; // Finaliza o case 15
            case 16: // Caso a escolha seja 16, o usuário deseja exibir os clientes
                mostrarCliente(clientes, numClientes); // Chama a função para mostrar todos os clientes
                break; // Finaliza o case 16
            case 17: // Caso a escolha seja 17, o usuário deseja sair do programa
                printf("Saindo...\n"); // Exibe uma mensagem de despedida
                return 0; // Encerra o programa
            default: // Caso a escolha não seja válida
                printf("Opcao invalida! Tente novamente.\n"); // Exibe uma mensagem de erro para uma opção inválida
        }
    }

    return 0; // Retorna 0 ao final do programa
}
