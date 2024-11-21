CREATE DATABASE ex01;
USE ex01;

CREATE TABLE costumers(
	id INT PRIMARY KEY,
    name VARCHAR(100),
    street VARCHAR(255),
    city VARCHAR(255),
    state CHAR(2),
    credit_limit INT
);

INSERT INTO costumers (id, name, street, city, state, credit_limit) VALUES
(1, 'Pedro Augusto da Rocha', 'Rua Pedro Carlos Hoffman', 'Porto Alegre', 'RS', 700.00),
(2, 'Antonio Carlos Mamel', 'Av.Pinheiros', 'Belo Horizonte', 'MG', 3500.50),
(3, 'Luiza Augusta Mhor', 'Rua Salto Grande', 'Niteroi', 'RJ', 4000.00),
(4, 'Jane Ester', 'Av 7 de setembro', 'Erechim', 'RS', 800.00),
(5, 'Marcos Antônio dos Santos', 'Av Farrapos', 'Porto Alegre', 'RS', 4250.25);

-- Então, você deve mostrar os nomes de todos os clientes cujo estado seja ‘RS’.

SELECT c.name AS name
FROM costumers c
WHERE c.state = 'RS';