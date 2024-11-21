CREATE TABLE cliente (

	id_cliente INT PRIMARY KEY,
    nome_cliente VARCHAR(255),
    rua_cliente VARCHAR(255),
    cidade_cliente VARCHAR(255),
    estado_cliente VARCHAR(2),
    limitecredito_cliente DECIMAL(10,2)

);

INSERT INTO cliente (id_cliente, nome_cliente, rua_cliente, cidade_cliente, estado_cliente, limitecredito_cliente)
VALUES (2, 'Antonio Carlos Mamel', 'Av. Pinheiros', 'Belo Horizonte', 'MG', 3500.50),
       (3, 'Luiza Augusta Mhor', 'Rua Salto Grande', 'Niteroi', 'RJ', 4000.00),
       (4, 'Jane Ester', 'Av 7 de Setembro', 'Erechim', 'RS', 800.00),
       (5, 'Marcos Antônio dos Santos', 'Av Farrapos', 'Porto Alegre', 'RS', 4250.25);
       
SELECT nome_cliente
FROM cliente
WHERE estado_cliente = 'RS';
       
