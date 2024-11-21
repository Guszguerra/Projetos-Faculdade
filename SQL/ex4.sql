CREATE DATABASE ex4;
USE ex4;

CREATE TABLE providers(
	id INT PRIMARY KEY,
    name VARCHAR(100),
    street VARCHAR(100),
    city VARCHAR(100),
    state CHAR(2)
);

INSERT INTO providers(id, name, street, city, state) VALUES
(1, 'Henrique', 'Av Brasil', 'Rio de Janeiro', 'RJ'),
(2, 'Marcelo Augusto', 'Rua Imigrantes', 'Belo Horizonte', 'MG'),
(3, 'Caroline Silva', 'Av São Paulo', 'Salvador', 'BA'),
(4, 'Guilherme Staff', 'Rua Central', 'Porto Alegre', 'RS'),
(5, 'Isabela Moraes', 'Av Juiz Grande', 'Curitiba', 'PR'),
(6, 'Francisco Accerr', 'Av Paulista', 'São Paulo', 'SP');

CREATE TABLE categories(
	id INT PRIMARY KEY,
    name VARCHAR(100)
);

INSERT INTO categories(id, name) VALUES
(1, 'old stock'),
(2, 'new stock'),
(3, 'modern'),
(4, 'commercial'),
(5, 'recyclable'),
(6, 'executive'),
(7, 'superior'),
(8, 'wood'),
(9, 'super luxury'),
(10, 'vintage');

CREATE TABLE products(
	id INT PRIMARY KEY,
    name VARCHAR(70),
    amount INT,
    price NUMERIC(10, 2),
    id_providers INT,
    FOREIGN KEY (id_providers) REFERENCES providers(id),
    id_categories INT,
    FOREIGN KEY (id_categories) REFERENCES categories(id)
);

INSERT INTO products(id, name, amount, price, id_providers, id_categories) VALUES
(1, 'Two-door wardrobe', 100, 800, 6, 8),
(2, 'Dining Table', 1000, 560, 1, 9),
(3, 'Towel holder', 10000, 25.50, 5, 1),
(4, 'Computer desk', 350, 320.50, 4, 6),
(5, 'Chair', 3000, 210.64, 3, 6),
(6, 'Single bed', 750, 460, 1, 2);

SELECT p.name AS product_name, f.name AS provider_name
FROM products p
JOIN providers f ON p.id_providers = f.id
JOIN categories c ON p.id_categories = c.id
WHERE c.id = 6;


-- Seu trabalho é retornar os nomes dos produtos e dos fornecedores cujo código da categoria é 6.












-- Seu trabalho é retornar os nomes dos produtos e dos fornecedores cujo código da categoria é 6.