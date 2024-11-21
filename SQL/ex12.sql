CREATE DATABASE exe12;
USE exe12;

CREATE TABLE costomers(
	id INT PRIMARY KEY,
    name VARCHAR(70),
    street VARCHAR(255),
    city VARCHAR(255)
);

INSERT INTO costomers (id, name, street, city) VALUES
(1, 'Giovanna G. Oliveira', 'Rua Mato Grosso', 'Canoas'),
(2, 'Kauã Azevedo Ribeiro', 'Travessa Ibía', 'Uberlândia'),
(3, 'Rebeca Barbosa Santos', 'Rua Observatório Meteorológico', 'Salvador'),
(4, 'Sarah Carvalho Correia', 'Rua Antônio Carlos da Silva', 'Apucarana'),
(5, 'João Almeida Lima', 'Rua Rio Taiuva', 'Ponta Grossa'),
(6, 'Diogo Melo Dias', 'Rua Duzentos e Cinquenta', 'Várzea Grande');

CREATE TABLE rentals(
	id INT PRIMARY KEY,
    rentals_date DATE,
    id_costomers INT,
    FOREIGN KEY (id_costomers) REFERENCES costomers(id)
);

INSERT INTO rentals(id, rentals_date, id_costomers)	VALUES 
(1, '2016-09-10', 3),
(2, '2016-02-09', 1),
(3, '2016-02-08', 4),
(4, '2016-02-09', 2),
(5, '2016-02-03', 6),
(6, '2016-04-04', 4);

SELECT c.name, DATE_FORMAT(r.rentals_date, '%d/%m/%Y') as rentals_date
FROM costomers c
JOIN rentals r ON c.id = r.id_costomers -- coluna de alugueis  
WHERE EXTRACT(YEAR_MONTH FROM r.rentals_date) = 201609;