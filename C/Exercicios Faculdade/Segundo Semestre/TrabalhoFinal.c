#include <stdio.h> // Inclui a biblioteca padr�o para entrada e sa�da de dados
#include <stdlib.h> // Inclui a biblioteca padr�o para aloca��o de mem�ria, controle de processos, etc.
#include <string.h> // Inclui a biblioteca padr�o para manipula��o de strings

#define MAX_CATEGORIAS 100 // Define o n�mero m�ximo de categorias permitido
#define MAX_PRODUTOS 100 // Define o n�mero m�ximo de produtos permitido
#define MAX_PEDIDOS 100 // Define o n�mero m�ximo de pedidos permitido
#define MAX_CLIENTES 100 // Define o n�mero m�ximo de clientes permitido

// Estrutura que representa uma categoria
typedef struct {
    int idCategoria; // Identificador �nico da categoria
    char nomeCategoria[50]; // Nome da categoria (m�ximo de 50 caracteres)
    char descricaoCategoria[100]; // Descri��o da categoria (m�ximo de 100 caracteres)
} Categoria;

// Estrutura que representa um produto
typedef struct {
    int idProduto; // Identificador �nico do produto
    char nomeProduto[50]; // Nome do produto (m�ximo de 50 caracteres)
    char descricaoProduto[100]; // Descri��o do produto (m�ximo de 100 caracteres)
    float preco; // Pre�o do produto
    int estoque; // Quantidade dispon�vel no estoque
    int idCategoria; // Identificador da categoria associada ao produto
} Produto;

// Estrutura que representa um pedido
typedef struct {
    int idPedido; // Identificador �nico do pedido
    int idCliente; // Identificador do cliente que realizou o pedido
    char dataPedido[11]; // Data do pedido no formato "dd/mm/aaaa"
    float totalPedido; // Valor total do pedido
} Pedido;

// Estrutura que representa um cliente
typedef struct {
    int id; // Identificador �nico do cliente
    char nome[50]; // Nome do cliente (m�ximo de 50 caracteres)
    char sobrenome[50]; // Sobrenome do cliente (m�ximo de 50 caracteres)
    char telefone[20]; // Telefone do cliente (m�ximo de 20 caracteres)
    char email[50]; // E-mail do cliente (m�ximo de 50 caracteres)
    char endereco[100]; // Endere�o do cliente (m�ximo de 100 caracteres)
} Cliente;

// Declara��o das fun��es relacionadas � manipula��o de categorias
void criarCategoria(Categoria *c); // Fun��o para criar uma nova categoria
void mostrarCategoria(const Categoria categorias[], int numCategorias); // Fun��o para exibir uma categoria espec�fica
void alterarCategoria(Categoria *c); // Fun��o para alterar os dados de uma categoria
int excluirCategoria(Categoria categorias[], int *numCategorias); // Fun��o para excluir uma categoria
void carregarCategorias(Categoria categorias[], int *numCategorias); // Fun��o para carregar categorias de um arquivo
void salvarCategorias(const Categoria categorias[], int numCategorias); // Fun��o para salvar categorias em um arquivo

// Declara��o das fun��es relacionadas � manipula��o de produtos
void criarProduto(Produto *p); // Fun��o para criar um novo produto
void mostrarProduto(const Produto produtos[], int numProdutos); // Fun��o para exibir um produto espec�fico
void alterarProduto(Produto *p); // Fun��o para alterar os dados de um produto
int excluirProduto(Produto produtos[], int *numProdutos); // Fun��o para excluir um produto
void carregarProdutos(Produto produtos[], int *numProdutos); // Fun��o para carregar produtos de um arquivo
void salvarProdutos(const Produto produtos[], int numProdutos); // Fun��o para salvar produtos em um arquivo

// Declara��o das fun��es relacionadas � manipula��o de pedidos
void criarPedido(Pedido *ped); // Fun��o para criar um novo pedido
void mostrarPedido(const Pedido pedidos[], int numPedidos); // Fun��o para exibir um pedido espec�fico
void alterarPedido(Pedido *ped); // Fun��o para alterar os dados de um pedido
int excluirPedido(Pedido pedidos[], int *numPedidos); // Fun��o para excluir um pedido
void carregarPedidos(Pedido pedidos[], int *numPedidos); // Fun��o para carregar pedidos de um arquivo
void salvarPedidos(const Pedido pedidos[], int numPedidos); // Fun��o para salvar pedidos em um arquivo

// Fun��o para criar uma nova categoria
void criarCategoria(Categoria *c) {
    printf("Digite o ID da Categoria: ");
    scanf("%d", &c->idCategoria); // L� o ID e armazena no campo idCategoria da struct Categoria

    printf("Digite o Nome da Categoria: ");
    scanf(" %[^\n]", c->nomeCategoria); // L� o nome da categoria, permitindo espa�os

    printf("Digite a Descricao da Categoria: ");
    scanf(" %[^\n]", c->descricaoCategoria); // L� a descri��o da categoria, permitindo espa�os

    printf("Categoria criada com sucesso!\n"); // Mensagem de sucesso
}

// Fun��o para mostrar uma categoria espec�fica
void mostrarCategoria(const Categoria categorias[], int numCategorias) {
    int id;
    printf("Digite o ID da Categoria a ser mostrado: ");
    scanf("%d", &id); // L� o ID que o usu�rio quer visualizar

    for (int i = 0; i < numCategorias; i++) { // Itera por todas as categorias armazenadas
        if (categorias[i].idCategoria == id) { // Se encontrar a categoria com o ID fornecido
            printf("ID da Categoria: %d\n", categorias[i].idCategoria);
            printf("Nome da Categoria: %s\n", categorias[i].nomeCategoria);
            printf("Descricao da Categoria: %s\n", categorias[i].descricaoCategoria);
            return; // Encerra a fun��o ap�s mostrar a categoria
        }
    }
    printf("Categoria com ID %d nao encontrada.\n", id); // Mensagem de erro se n�o encontrar
}

// Fun��o para alterar os dados de uma categoria
void alterarCategoria(Categoria *c) {
    printf("Digite o novo Nome da Categoria: ");
    scanf(" %[^\n]", c->nomeCategoria); // L� o novo nome da categoria

    printf("Digite a nova Descri��o da Categoria: ");
    scanf(" %[^\n]", c->descricaoCategoria); // L� a nova descri��o da categoria

    printf("Categoria alterada com sucesso!\n"); // Mensagem de sucesso
}

// Fun��o para excluir uma categoria
int excluirCategoria(Categoria categorias[], int *numCategorias) {
    int id;
    printf("Digite o ID da Categoria a ser excluida: ");
    scanf("%d", &id); // L� o ID da categoria a ser exclu�da

    for (int i = 0; i < *numCategorias; i++) { // Itera pelas categorias
        if (categorias[i].idCategoria == id) { // Se encontrar a categoria com o ID fornecido
            categorias[i] = categorias[--(*numCategorias)]; // Remove a categoria, deslocando as demais
            printf("Categoria exclu�da com sucesso!\n"); // Mensagem de sucesso
            return 1; // Retorna 1 indicando sucesso
        }
    }
    printf("Categoria com ID %d nao encontrada.\n", id); // Mensagem de erro se n�o encontrar
    return 0; // Retorna 0 indicando falha
}

// Fun��o para carregar categorias a partir de um arquivo
void carregarCategorias(Categoria categorias[], int *numCategorias) {
    FILE *file = fopen("categorias.txt", "r"); // Tenta abrir o arquivo categorias.txt para leitura
    if (file == NULL) { // Se o arquivo n�o for encontrado
        printf("Arquivo de categorias n�o encontrado. Criando um novo.\n");
        return; // Retorna sem fazer nada se o arquivo n�o for encontrado
    }

    while (fscanf(file, "%d %[^\n] %[^\n]", &categorias[* numCategorias].idCategoria, categorias[*numCategorias].nomeCategoria, categorias[*numCategorias].descricaoCategoria) != EOF) {
        if (*numCategorias < MAX_CATEGORIAS) { // Verifica se n�o ultrapassou o limite
            (*numCategorias)++; // Incrementa o contador de categorias
        } else {
            printf("Limite de categorias atingido ao carregar.\n"); // Mensagem se o limite for atingido
            break; // Encerra o loop se o limite for atingido
        }
    }
    fclose(file); // Fecha o arquivo ap�s leitura
}

// Fun��o para salvar as categorias em um arquivo
void salvarCategorias(const Categoria categorias[], int numCategorias) {
    FILE *file = fopen("categorias.txt", "w"); // Abre o arquivo categorias.txt para escrita
    for (int i = 0; i < numCategorias; i++) { // Percorre todas as categorias
        fprintf(file, "%d %s %s\n", categorias[i].idCategoria, categorias[i].nomeCategoria, categorias[i].descricaoCategoria); // Escreve os dados da categoria no arquivo
    }
    fclose(file); // Fecha o arquivo ap�s escrita
}

// Fun��o para criar um novo produto
void criarProduto(Produto *p) {
    printf("Digite o ID do Produto: ");
    scanf("%d", &p->idProduto); // L� o ID e armazena no campo idProduto da struct Produto

    printf("Digite o Nome do Produto: ");
    scanf(" %[^\n]", p->nomeProduto); // L� o nome do produto, permitindo espa�os

    printf("Digite a Descricao do Produto: ");
    scanf(" %[^\n]", p->descricaoProduto); // L� a descri��o do produto, permitindo espa�os

    printf("Digite o Preco do Produto: ");
    scanf("%f", &p->preco); // L� o pre�o do produto

    printf("Digite o Estoque do Produto: ");
    scanf("%d", &p->estoque); // L� a quantidade em estoque do produto

    printf("Digite o ID da Categoria do Produto: ");
    scanf("%d", &p->idCategoria); // L� o ID da categoria do produto

    printf("Produto criado com sucesso!\n"); // Mensagem de sucesso
}

// Fun��o para mostrar os detalhes de um produto
void mostrarProduto(const Produto produtos[], int numProdutos) {
    int id;
    printf("Digite o ID do Produto a ser mostrado: ");
    scanf("%d", &id); // L� o ID do produto que o usu�rio quer visualizar

    for (int i = 0; i < numProdutos; i++) { // Itera pelas categorias
        if (produtos[i].idProduto == id) { // Se encontrar o produto com o ID fornecido
            printf("ID do Produto: %d\n", produtos[i].idProduto);
            printf("Nome do Produto: %s\n", produtos[i].nomeProduto);
            printf("Descricao do Produto: %s\n", produtos[i].descricaoProduto);
            printf("Preco: %.2f\n", produtos[i].preco);
            printf("Estoque: %d\n", produtos[i].estoque);
            printf("ID da Categoria: %d\n", produtos[i].idCategoria);
            return; // Encerra a fun��o ap�s mostrar o produto
        }
    }
    printf("Produto com ID %d nao encontrado.\n", id); // Mensagem de erro se n�o encontrar
}

// Fun��o para alterar os dados de um produto
void alterarProduto(Produto *p) {
    printf("Digite o novo Nome do Produto: ");
    scanf(" %[^\n]", p->nomeProduto); // L� o novo nome do produto

    printf("Digite a nova Descricao do Produto: ");
    scanf(" %[^\n]", p->descricaoProduto); // L� a nova descri��o do produto

    printf("Digite o novo Preco do Produto: ");
    scanf("%f", &p->preco); // L� o novo pre�o do produto

    printf("Digite o novo Estoque do Produto: ");
    scanf("%d", &p->estoque); // L� a nova quantidade em estoque do produto

    printf("Digite o novo ID da Categoria do Produto: ");
    scanf("%d", &p->idCategoria); // L� o novo ID da categoria do produto

    printf("Produto alterado com sucesso!\n"); // Mensagem de sucesso
}

// Fun��o para excluir um produto
int excluirProduto(Produto produtos[], int *numProdutos) {
    int id;
    printf("Digite o ID do Produto a ser excluido: ");
    scanf("%d", &id); // L� o ID do produto que o usu�rio deseja excluir

for (int i = 0; i < *numProdutos; i++) { // Percorre todos os produtos cadastrados
    if (produtos[i].idProduto == id) { // Verifica se o ID do produto corresponde ao fornecido pelo usu�rio
        produtos[i] = produtos[--(*numProdutos)]; // Substitui o produto exclu�do pelo �ltimo produto da lista e diminui o n�mero de produtos
        printf("Produto excluido com sucesso!\n"); // Informa que o produto foi exclu�do
        return 1; // Retorna 1 indicando sucesso na exclus�o
    }
}
    printf("Produto com ID %d nao encontrado.\n", id); // Caso n�o encontre o produto, exibe uma mensagem de erro
    return 0; // Retorna 0 indicando que a exclus�o falhou
}

// Fun��o para carregar os produtos a partir do arquivo "produtos.txt"
void carregarProdutos(Produto produtos[], int *numProdutos) {
    FILE *file = fopen("produtos.txt", "r"); // Abre o arquivo "produtos.txt" em modo leitura
    if (file == NULL) { // Verifica se o arquivo foi aberto corretamente
        printf("Arquivo de produtos n�o encontrado. Criando um novo.\n"); // Exibe uma mensagem caso o arquivo n�o exista
        return; // Retorna sem fazer nada se o arquivo n�o for encontrado
    }
    // L� os dados dos produtos no arquivo e armazena nas vari�veis correspondentes
    while (fscanf(file, "%d %[^\n] %[^\n] %f %d %d", &produtos[*numProdutos].idProduto, produtos[*numProdutos].nomeProduto, produtos[*numProdutos].descricaoProduto, &produtos[*numProdutos].preco, &produtos[*numProdutos].estoque, &produtos[*numProdutos].idCategoria) != EOF) {
        if (*numProdutos < MAX_PRODUTOS) { // Verifica se n�o ultrapassou o limite
            (*numProdutos)++; // Aumenta o n�mero de produtos lidos
        } else {
            printf("Limite de produtos atingido ao carregar.\n"); // Mensagem se o limite for atingido
            break; // Encerra o loop se o limite for atingido
        }
    }
    fclose(file); // Fecha o arquivo ap�s a leitura
}

// Fun��o para salvar os produtos no arquivo "produtos.txt"
void salvarProdutos(const Produto produtos[], int numProdutos) {
    FILE *file = fopen("produtos.txt", "w"); // Abre o arquivo "produtos.txt" em modo escrita
    for (int i = 0; i < numProdutos; i++) { // Percorre todos os produtos cadastrados
        // Escreve os dados de cada produto no arquivo
        fprintf(file, "%d %s %s %.2f %d %d\n", produtos[i].idProduto, produtos[i].nomeProduto, produtos[i].descricaoProduto, produtos[i].preco, produtos[i].estoque, produtos[i].idCategoria);
    }
    fclose(file); // Fecha o arquivo ap�s salvar os produtos
}

// Fun��es para Pedido
// Fun��o para criar um novo pedido
void criarPedido(Pedido *ped) {
    printf("Digite o ID do Pedido: ");
    scanf("%d", &ped->idPedido); // L� o ID do pedido
    printf("Digite o ID do Cliente: ");
    scanf("%d", &ped->idCliente); // L� o ID do cliente que fez o pedido
    printf("Digite a Data do Pedido (dd/mm/aaaa): ");
    scanf(" %[^\n]", ped->dataPedido); // L� a data do pedido
    printf("Digite o Total do Pedido: ");
    scanf("%f", &ped->totalPedido); // L� o valor total do pedido
    printf("Pedido criado com sucesso!\n"); // Informa que o pedido foi criado com sucesso
}

// Fun��o para mostrar os detalhes de um pedido
void mostrarPedido(const Pedido pedidos[], int numPedidos) {
    int id;
    printf("Digite o ID do Pedido a ser mostrado: ");
    scanf("%d", &id); // L� o ID do pedido a ser exibido

    for (int i = 0; i < numPedidos; i++) { // Percorre todos os pedidos cadastrados
    if (pedidos[i].idPedido == id) { // Verifica se o ID do pedido corresponde ao fornecido
        // Exibe os detalhes do pedido
        printf("ID do Pedido: %d\n", pedidos[i].idPedido);
        printf("ID do Cliente: %d\n", pedidos[i].idCliente);
        printf("Data do Pedido: %s\n", pedidos[i].dataPedido); // Corrigido: removido duplicado
        printf("Total do Pedido: %.2f\n", pedidos[i].totalPedido);
        return; // Encerra a fun��o ap�s exibir o pedido
    }
}
    printf("Pedido com ID %d nao encontrado.\n", id); // Exibe uma mensagem de erro se o pedido n�o for encontrado
}

// Fun��o para alterar um pedido existente
void alterarPedido(Pedido *ped) {
    printf("Digite o novo ID do Cliente: ");
    scanf("%d", &ped->idCliente); // L� o novo ID do cliente
    printf("Digite a nova Data do Pedido (dd/mm/aaaa): ");
    scanf(" %[^\n]", ped->dataPedido); // L� a nova data do pedido
    printf("Digite o novo Total do Pedido: ");
    scanf("%f", &ped->totalPedido); // L� o novo valor total do pedido
    printf("Pedido alterado com sucesso!\n"); // Informa que o pedido foi alterado com sucesso
}

// Fun��o para excluir um pedido
int excluirPedido(Pedido pedidos[], int *numPedidos) {
    int id;
    printf("Digite o ID do Pedido a ser excluido: ");
    scanf("%d", &id); // L� o ID do pedido a ser exclu�do

    for (int i = 0; i < *numPedidos; i++) { // Percorre todos os pedidos cadastrados
        if (pedidos[i].idPedido == id) { // Verifica se o ID do pedido corresponde ao fornecido
            pedidos[i] = pedidos[--(*numPedidos)]; // Substitui o pedido exclu�do pelo �ltimo pedido da lista e diminui o n�mero de pedidos
            printf("Pedido excluido com sucesso!\n"); // Informa que o pedido foi exclu�do
            return 1; // Retorna 1 indicando sucesso na exclus�o
        }
    }
    printf("Pedido com ID %d nao encontrado.\n", id); // Exibe uma mensagem de erro se o pedido n�o for encontrado
    return 0; // Retorna 0 indicando falha na exclus�o
}

// Fun��o para carregar os pedidos a partir do arquivo "pedidos.txt"
void carregarPedidos(Pedido pedidos[], int *numPedidos) {
    FILE *file = fopen("pedidos.txt", "r"); // Abre o arquivo "pedidos.txt" em modo leitura
    if (file == NULL) { // Verifica se o arquivo foi aberto corretamente
        printf("Arquivo de pedidos n�o encontrado. Criando um novo.\n"); // Exibe uma mensagem caso o arquivo n�o exista
        return; // Retorna sem fazer nada se o arquivo n�o for encontrado
    }
    // L� os dados dos pedidos no arquivo e armazena nas vari�veis correspondentes
    while (fscanf(file, "%d %d %[^\n] %f", &pedidos[*numPedidos].idPedido, &pedidos[*numPedidos].idCliente, pedidos[*numPedidos].dataPedido, &pedidos[*numPedidos].totalPedido) != EOF) {
        if (*numPedidos < MAX_PEDIDOS) { // Verifica se n�o ultrapassou o limite
            (*numPedidos)++; // Aumenta o n�mero de pedidos lidos
        } else {
            printf("Limite de pedidos atingido ao carregar.\n"); // Mensagem se o limite for atingido
            break; // Encerra o loop se o limite for atingido
        }
    }
    fclose(file); // Fecha o arquivo ap�s a leitura
}

// Fun��o para salvar os pedidos no arquivo "pedidos.txt"
void salvarPedidos(const Pedido pedidos[], int numPedidos) {
    FILE *file = fopen("pedidos.txt", "w"); // Abre o arquivo "pedidos.txt" em modo escrita
    for (int i = 0; i < numPedidos; i++) { // Percorre todos os pedidos cadastrados
        // Escreve os dados de cada pedido no arquivo
        fprintf(file, "%d %d %s %.2f\n", pedidos[i].idPedido, pedidos[i].idCliente, pedidos[i].dataPedido, pedidos[i].totalPedido);
    }
    fclose(file); // Fecha o arquivo ap�s salvar os pedidos
}

// Fun��o para criar um novo cliente
void criarCliente(Cliente *c) {
    printf("Digite o ID do Cliente: ");
    scanf("%d", &c->id); // L� o ID do cliente
    printf("Digite o Nome do Cliente: ");
    scanf(" %[^\n]", c->nome); // L� o nome do cliente
    printf("Digite o Sobrenome do Cliente: ");
    scanf(" %[^\n]", c->sobrenome); // L� o sobrenome do cliente
    printf("Digite o Telefone do Cliente: ");
    scanf(" %[^\n]", c->telefone); // L� o telefone do cliente
    printf("Digite o Email do Cliente: ");
    scanf(" %[^\n]", c->email); // L� o email do cliente
    printf("Digite o Endereco do Cliente: ");
    scanf(" %[^\n]", c->endereco); // L� o endere�o do cliente
    printf("Cliente criado com sucesso!\n"); // Mensagem de sucesso
}

// Fun��o que exibe os detalhes de um cliente com base no ID fornecido
void mostrarCliente(const Cliente clientes[], int numClientes) {
    int id; // Declara uma vari�vel para armazenar o ID do cliente
    printf("Digite o ID do Cliente a ser mostrado: "); // Solicita ao usu�rio o ID do cliente
    scanf("%d", &id); // L� o ID fornecido pelo usu�rio

    // Loop para percorrer todos os clientes cadastrados
    for (int i = 0; i < numClientes; i++) {
        // Verifica se o ID do cliente na posi��o i � igual ao ID fornecido
        if (clientes[i].id == id) {
            printf("ID: %d\n", clientes[i].id); // Exibe o ID do cliente
            printf("Nome: %s %s\n", clientes[i].nome, clientes[i].sobrenome); // Exibe o nome completo do cliente
            printf("Telefone: %s\n", clientes[i].telefone); // Exibe o telefone do cliente
            printf("Email: %s\n", clientes[i].email); // Exibe o e-mail do cliente
            printf("Endereco: %s\n", clientes[i].endereco); // Exibe o endere�o do cliente
            return; // Encerra a fun��o ap�s mostrar o cliente encontrado
        }
    }
    printf("Cliente com ID %d nao encontrado.\n", id); // Exibe uma mensagem se o cliente n�o for encontrado
}

// Fun��o que altera os dados de um cliente
void alterarCliente(Cliente *c) {
    printf("Digite o novo Nome do Cliente: "); // Solicita ao usu�rio o novo nome
    scanf(" %[^\n]", c->nome); // L� o novo nome do cliente
    printf("Digite o novo Sobrenome do Cliente: "); // Solicita ao usu�rio o novo sobrenome
    scanf(" %[^\n]", c->sobrenome); // L� o novo sobrenome do cliente
    printf("Digite o novo Telefone do Cliente: "); // Solicita ao usu�rio o novo telefone
    scanf(" %[^\n]", c->telefone); // L� o novo telefone do cliente
    printf("Digite o novo Email do Cliente: "); // Solicita ao usu�rio o novo e-mail
    scanf(" %[^\n]", c->email); // L� o novo e-mail do cliente
    printf("Digite o novo Endere�o do Cliente: "); // Solicita ao usu�rio o novo endere�o
    scanf(" %[^\n]", c->endereco); // L� o novo endere�o do cliente
    printf("Cliente alterado com sucesso!\n"); // Exibe uma mensagem indicando que o cliente foi alterado
}

// Fun��o que exclui um cliente com base no ID
int excluirCliente(Cliente clientes[], int *numClientes) {
    int id; // Declara uma vari�vel para armazenar o ID do cliente
    printf("Digite o ID do Cliente a ser excluido: "); // Solicita ao usu�rio o ID do cliente a ser exclu�do
    scanf("%d", &id); // L� o ID fornecido pelo usu�rio

    // Loop que percorre todos os clientes cadastrados
    for (int i = 0; i < *numClientes; i++) {
        // Verifica se o cliente na posi��o i tem o ID igual ao fornecido
        if (clientes[i].id == id) {
            clientes[i] = clientes[--(*numClientes)]; // Remove o cliente, substituindo-o pelo �ltimo cliente da lista
            printf("Cliente excluido com sucesso!\n"); // Exibe uma mensagem indicando que o cliente foi exclu�do
            return 1; // Retorna 1 indicando que a exclus�o foi bem-sucedida
        }
    }
    printf("Cliente com ID %d nao encontrado.\n", id); // Exibe uma mensagem se o cliente n�o for encontrado
    return 0; // Retorna 0 indicando que a exclus�o falhou
}

// Fun��o que carrega os dados dos clientes a partir de um arquivo
void carregarClientes(Cliente clientes[], int *numClientes) {
    FILE *file = fopen("clientes.txt", " r"); // Abre o arquivo "clientes.txt" em modo de leitura
    if (file == NULL) { // Se o arquivo n�o for encontrado
        printf("Arquivo de clientes n�o encontrado. Criando um novo.\n"); // Exibe uma mensagem
        return; // Retorna sem fazer nada
    }

    // Loop que l� os dados dos clientes do arquivo at� o final
    while (fscanf(file, "%d %[^\n] %[^\n] %[^\n] %[^\n] %[^\n]", &clientes[*numClientes].id, clientes[*numClientes].nome, clientes[*numClientes].sobrenome, clientes[*numClientes].telefone, clientes[*numClientes].email, clientes[*numClientes].endereco) != EOF) {
        if (*numClientes < MAX_CLIENTES) { // Verifica se n�o ultrapassou o limite
            (*numClientes)++; // Incrementa o n�mero de clientes carregados
        } else {
            printf("Limite de clientes atingido ao carregar.\n"); // Mensagem se o limite for atingido
            break; // Encerra o loop se o limite for atingido
        }
    }

    fclose(file); // Fecha o arquivo ap�s a leitura
}

// Fun��o que salva os dados dos clientes em um arquivo
void salvarClientes(const Cliente clientes[], int numClientes) {
    FILE *file = fopen("clientes.txt", "w"); // Abre o arquivo "clientes.txt" em modo de escrita
    // Loop para escrever os dados de cada cliente no arquivo
    for (int i = 0; i < numClientes; i++) {
        fprintf(file, "%d %s %s %s %s %s\n", clientes[i].id, clientes[i].nome, clientes[i].sobrenome, clientes[i].telefone, clientes[i].email, clientes[i].endereco); // Escreve os dados do cliente no arquivo
    }
    fclose(file); // Fecha o arquivo ap�s a escrita
}

// Fun��o principal do programa
int main() {
    Categoria categorias[MAX_CATEGORIAS]; // Declara um array para armazenar as categorias
    Produto produtos[MAX_PRODUTOS]; // Declara um array para armazenar os produtos
    Pedido pedidos[MAX_PEDIDOS]; // Declara um array para armazenar os pedidos
    Cliente clientes[MAX_CLIENTES]; // Declara um array para armazenar os clientes
    int numCategorias = 0, numProdutos = 0, numPedidos = 0, numClientes = 0; // Declara vari�veis para contar o n�mero de categorias, produtos, pedidos e clientes
    int escolha; // Declara uma vari�vel para armazenar a escolha do usu�rio

    // Carrega os dados de categorias, produtos, pedidos e clientes a partir de arquivos
    carregarCategorias(categorias, &numCategorias);
    carregarProdutos(produtos, &numProdutos);
    carregarPedidos(pedidos, &numPedidos);
    carregarClientes(clientes, &numClientes);

    // Loop infinito para exibir o menu e capturar a escolha do usu�rio
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
        printf("\nEscolha uma opcao: "); // Solicita ao usu�rio uma op��o
        scanf("%d", &escolha); // L� a op��o escolhida pelo usu�rio

        switch (escolha) { // Inicia o bloco switch, que ir� decidir a a��o com base no valor de 'escolha'
            case 1: // Caso a escolha seja 1, o usu�rio deseja criar uma nova categoria
                if (numCategorias < MAX_CATEGORIAS) { // Verifica se n�o ultrapassou o limite
                    criarCategoria(&categorias[numCategorias++]); // Chama a fun��o para criar uma nova categoria e incrementa o n�mero de categorias
                    salvarCategorias(categorias, numCategorias); // Salva as categorias no arquivo
        } else {
                    printf("Limite de categorias atingido.\n"); // Mensagem se o limite for atingido
                }
                break; // Finaliza o case 1
            case 2: // Caso a escolha seja 2, o usu�rio deseja alterar uma categoria existente
                if (numCategorias > 0) { // Verifica se existem categorias para alterar
                    alterarCategoria(&categorias[numCategorias - 1]); // Chama a fun��o para alterar a �ltima categoria adicionada
                    salvarCategorias(categorias, numCategorias); // Salva as categorias atualizadas
                } else { // Se n�o houver categorias, exibe uma mensagem de erro
                    printf("Nenhuma categoria disponivel para alterar.\n");
                }
                break; // Finaliza o case 2
            case 3: // Caso a escolha seja 3, o usu�rio deseja excluir uma categoria
                if (excluirCategoria(categorias, &numCategorias)) { // Chama a fun��o para excluir uma categoria e verifica se a exclus�o foi bem-sucedida
                    salvarCategorias(categorias, numCategorias); // Salva as categorias atualizadas ap�s a exclus�o
                }
                break; // Finaliza o case 3
            case 4: // Caso a escolha seja 4, o usu�rio deseja exibir as categorias
                mostrarCategoria(categorias, numCategorias); // Chama a fun��o para mostrar todas as categorias
                break; // Finaliza o case 4
            case 5: // Caso a escolha seja 5, o usu�rio deseja criar um novo produto
                if (numProdutos < MAX_PRODUTOS) { // Verifica se n�o ultrapassou o limite
                    criarProduto(&produtos[numProdutos++]); // Chama a fun��o para criar um novo produto e incrementa o n�mero de produtos
                    salvarProdutos(produtos, numProdutos); // Salva os produtos no arquivo
                } else {
                    printf("Limite de produtos atingido.\n"); // Mensagem se o limite for atingido
                }
                break; // Finaliza o case 5
            case 6: // Caso a escolha seja 6, o usu�rio deseja alterar um produto existente
                if (numProdutos > 0) { // Verifica se existem produtos para alterar
                    alterarProduto(&produtos[numProdutos - 1]); // Chama a fun��o para alterar o �ltimo produto adicionado
                    salvarProdutos(produtos, numProdutos); // Salva os produtos atualizados
                } else { // Se n�o houver produtos, exibe uma mensagem de erro
                    printf("Nenhum produto disponivel para alterar.\n");
                }
                break; // Finaliza o case 6
            case 7: // Caso a escolha seja 7, o usu�rio deseja excluir um produto
                if (excluirProduto(produtos, &numProdutos)) { // Chama a fun��o para excluir um produto e verifica se a exclus�o foi bem-sucedida
                    salvarProdutos(produtos, numProdutos); // Salva os produtos atualizados ap�s a exclus�o
                }
                break; // Finaliza o case 7
            case 8: // Caso a escolha seja 8, o usu�rio deseja exibir os produtos
                mostrarProduto(produtos, numProdutos); // Chama a fun��o para mostrar todos os produtos
                break; // Finaliza o case 8
            case 9: // Caso a escolha seja 9, o usu�rio deseja criar um novo pedido
                if (numPedidos < MAX_PEDIDOS) { // Verifica se n�o ultrapassou o limite
                    criarPedido(&pedidos[numPedidos++]); // Chama a fun��o para criar um novo pedido e incrementa o n�mero de pedidos
                    salvarPedidos(pedidos, numPedidos); // Salva os pedidos no arquivo
                } else {
                    printf("Limite de pedidos atingido.\n"); // Mensagem se o limite for atingido
                }
                break; // Finaliza o case 9
            case 10: // Caso a escolha seja 10, o usu�rio deseja alterar um pedido existente
                if (numPedidos > 0) { // Verifica se existem pedidos para alterar
                    alterarPedido(&pedidos[numPedidos - 1]); // Chama a fun��o para alterar o �ltimo pedido adicionado
                    salvarPedidos(pedidos, numPedidos); // Salva os pedidos atualizados
                } else { // Se n�o houver pedidos, exibe uma mensagem de erro
                    printf("Nenhum pedido disponivel para alterar.\n");
                }
                break; // Finaliza o case 10
            case 11: // Caso a escolha seja 11, o usu�rio deseja excluir um pedido
                if (excluirPedido(pedidos, &numPedidos)) { // Chama a fun��o para excluir um pedido e verifica se a exclus�o foi bem-sucedida
                    salvarPedidos(pedidos, numPedidos); // Salva os pedidos atualizados ap�s a exclus�o
                }
                break; // Finaliza o case 11
            case 12: // Caso a escolha seja 12, o usu�rio deseja exibir os pedidos
                mostrarPedido(pedidos, numPedidos); // Chama a fun��o para mostrar todos os pedidos
                break; // Finaliza o case 12
            case 13: // Caso a escolha seja 13, o usu�rio deseja criar um novo cliente
                if (numClientes < MAX_CLIENTES) { // Verifica se n�o ultrapassou o limite
                    criarCliente(&clientes[numClientes++]); // Chama a fun��o para criar um novo cliente e incrementa o n�mero de clientes
                    salvarClientes(clientes, numClientes); // Salva os clientes no arquivo
                } else {
                    printf("Limite de clientes atingido.\n"); // Mensagem se o limite for atingido
                }
                break; // Finaliza o case 13
            case 14: // Caso a escolha seja 14, o usu�rio deseja alterar um cliente existente
                if (numClientes > 0) { // Verifica se existem clientes para alterar
                    alterarCliente(&clientes[numClientes - 1]); // Chama a fun��o para alterar o �ltimo cliente adicionado
                    salvarClientes(clientes, numClientes); // Salva os clientes atualizados
                } else { // Se n�o houver clientes, exibe uma mensagem de erro
                    printf("Nenhum cliente disponivel para alterar.\n");
                }
                break; // Finaliza o case 14
            case 15: // Caso a escolha seja 15, o usu�rio deseja excluir um cliente
                if (excluirCliente(clientes, &numClientes)) { // Chama a fun��o para excluir um cliente e verifica se a exclus�o foi bem-sucedida
                    salvarClientes(clientes, numClientes); // Salva os clientes atualizados ap�s a exclus�o
                }
                break; // Finaliza o case 15
            case 16: // Caso a escolha seja 16, o usu�rio deseja exibir os clientes
                mostrarCliente(clientes, numClientes); // Chama a fun��o para mostrar todos os clientes
                break; // Finaliza o case 16
            case 17: // Caso a escolha seja 17, o usu�rio deseja sair do programa
                printf("Saindo...\n"); // Exibe uma mensagem de despedida
                return 0; // Encerra o programa
            default: // Caso a escolha n�o seja v�lida
                printf("Opcao invalida! Tente novamente.\n"); // Exibe uma mensagem de erro para uma op��o inv�lida
        }
    }

    return 0; // Retorna 0 ao final do programa
}
