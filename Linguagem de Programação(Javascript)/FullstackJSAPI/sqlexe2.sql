-- Criação do banco de dados
CREATE DATABASE IF NOT EXISTS minha_loja;

-- Uso do banco de dados
USE minha_loja;

-- Criação da tabela Produtos
CREATE TABLE IF NOT EXISTS Produtos (
    id INT AUTO_INCREMENT PRIMARY KEY,
    descricao VARCHAR(255) NOT NULL,
    quantidade INT NOT NULL,
    valor DECIMAL(10, 2) NOT NULL
);

-- Inserindo dados de exemplo na tabela Produtos
INSERT INTO Produtos (descricao, quantidade, valor) VALUES
('Produto A', 10, 19.99),
('Produto B', 20, 29.99),
('Produto C', 15, 39.50);

SELECT User, Host FROM mysql.user;

