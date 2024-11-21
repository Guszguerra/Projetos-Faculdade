CREATE DATABASE IF NOT EXISTS mercado;
USE mercado;

DROP TABLE IF EXISTS ItemPedido;
DROP TABLE IF EXISTS Produto;
DROP TABLE IF EXISTS Categoria;
DROP TABLE IF EXISTS Pedido;
DROP TABLE IF EXISTS Cliente;

CREATE TABLE IF NOT EXISTS Categoria (
    id_categoria INT AUTO_INCREMENT PRIMARY KEY, -- ID da categoria, autoincrementado
    nome_categoria VARCHAR(100) NOT NULL, -- Nome da categoria
    descricao_categoria TEXT, -- Descrição da categoria
    status_categoria ENUM('ativo', 'inativo') DEFAULT 'ativo', -- Status da categoria
    prioridade_categoria INT DEFAULT 0 -- Prioridade da categoria
);

-- Tabela Cliente
CREATE TABLE IF NOT EXISTS Cliente (
    cpf_cli CHAR(11) PRIMARY KEY,
    nome_cli VARCHAR(100),
    endereco_cli VARCHAR(200),
    telefone_cli VARCHAR(15),
    email_cli VARCHAR(100),
    cidade_cli VARCHAR(50)
);

-- Tabela Produto
CREATE TABLE IF NOT EXISTS Produto (
    id_prod INT AUTO_INCREMENT PRIMARY KEY,
    nome_prod VARCHAR(100),
    desc_prod TEXT,
    preco_prod DECIMAL(10, 2),
    categoria_prod INT,
    estoque_prod INT,
    FOREIGN KEY (categoria_prod) REFERENCES Categoria(id_categoria)
);

-- Tabela Pedido
CREATE TABLE IF NOT EXISTS Pedido (
    id_pedido INT AUTO_INCREMENT PRIMARY KEY,
    data_pedido DATE,
    status_pedido VARCHAR(20),
    cpf_cli CHAR(11),
    total_pedido DECIMAL(10, 2),
    FOREIGN KEY (cpf_cli) REFERENCES Cliente(cpf_cli)
);

-- Tabela ItemPedido
CREATE TABLE IF NOT EXISTS ItemPedido (
    id_itemPedido INT AUTO_INCREMENT PRIMARY KEY,
    id_pedido INT,
    id_produto INT,
    quantidade_produto INT,
    precoUni_produto DECIMAL(10, 2),
    FOREIGN KEY (id_pedido) REFERENCES Pedido(id_pedido),
    FOREIGN KEY (id_produto) REFERENCES Produto(id_prod)
);

-- Inserindo dados na tabela Cliente
INSERT INTO Cliente (cpf_cli, nome_cli, endereco_cli, telefone_cli, email_cli, cidade_cli) VALUES
('12345678901', 'João Silva', 'Rua A, 123', '(11) 91234-5678', 'joao.silva@email.com', 'São Paulo'),
('10987654321', 'Maria Oliveira', 'Rua B, 456', '(11) 98765-4321', 'maria.oliveira@email.com', 'Rio de Janeiro'),
('98765432100', 'Carlos Santos', 'Avenida C, 789', '(21) 99876-5432', 'carlos.santos@email.com', 'Belo Horizonte'),
('11223344556', 'Ana Costa', 'Rua D, 321', '(31) 91234-5678', 'ana.costa@email.com', 'Curitiba');

-- Inserindo dados na tabela Categoria
INSERT INTO Categoria (nome_categoria, descricao_categoria, status_categoria, prioridade_categoria) VALUES
('Eletrônicos', 'Dispositivos e gadgets eletrônicos', 'ativo', 1),
('Roupas', 'Vestuário masculino e feminino', 'ativo', 2),
('Livros', 'Livros de diversos gêneros e autores', 'ativo', 3),
('Esportes', 'Equipamentos e roupas para esportes', 'inativo', 4);

-- Inserindo dados na tabela Pedido
INSERT INTO Pedido (data_pedido, status_pedido, cpf_cli, total_pedido) VALUES
('2024-10-01', 'Pendente', '12345678901', 150.00),
('2024-10-05', 'Concluído', '10987654321', 300.00),
('2024-10-10', 'Cancelado', '12345678901', 50.00);

-- Inserindo dados na tabela Produto
INSERT INTO Produto (nome_prod, desc_prod, preco_prod, categoria_prod, estoque_prod) VALUES
('Smartphone', 'Smartphone de última geração com câmera de alta qualidade', 1200.00, 1, 10),
('Camiseta', 'Camiseta de algodão tamanho M', 50.00, 2, 100),
('Fone de Ouvido', 'Fone com cancelamento de ruído', 200.00, 1, 25),
('Calça Jeans', 'Calça jeans azul tamanho 40', 120.00, 2, 50);