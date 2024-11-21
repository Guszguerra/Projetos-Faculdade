CREATE TABLE products(
	id INT PRIMARY KEY,
    name VARCHAR(100),
    amount INT,
    price NUMERIC(10,2)
);

INSERT INTO products(id, name, amount, price) VALUES
(1, 'Two-door wardrobe', 100, 80),
(2, 'Dining table', 1000, 560),
(3, 'Towel holder', 10000, 5.50),
(4, 'Computer desk', 350, 100),
(5, 'Chair', 3000, 210.64),
(6, 'Single bed', 750, 99);

SELECT p.id AS id, p.name AS name
FROM products p
WHERE p.price < 10.0 OR p.price > 100;
-- O setor financeiro da empresa precisa de um relatório que mostre o código e o nome dos produtos cujo preço são menores que 10 ou maiores que 100.