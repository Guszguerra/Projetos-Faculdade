-- 1. Criar o banco de dados e usar
CREATE DATABASE IF NOT EXISTS ex2;
USE ex2;

-- 2. Remover tabelas e procedimentos existentes
DROP TABLE IF EXISTS dependente;
DROP TABLE IF EXISTS empregado;
DROP TABLE IF EXISTS dpto;
DROP TABLE IF EXISTS sexo;
DROP TABLE IF EXISTS estado_civil;

DROP PROCEDURE IF EXISTS infodpto;
DROP PROCEDURE IF EXISTS sexo_func;
DROP PROCEDURE IF EXISTS inserirValores;
DROP PROCEDURE IF EXISTS alteraSalario;
DROP PROCEDURE IF EXISTS ganhoPercent;
DROP PROCEDURE IF EXISTS mediaSalarioEmpregados; -- Removendo se existir

-- 3. Criar tabelas
CREATE TABLE IF NOT EXISTS dpto(
    cod_dpto INT PRIMARY KEY,
    nome VARCHAR(50)
);

CREATE TABLE IF NOT EXISTS sexo (
    cod_sexo CHAR(1) PRIMARY KEY,
    descricao VARCHAR(10) NOT NULL
);

CREATE TABLE IF NOT EXISTS estado_civil (
    cod_estado_civil CHAR(1) PRIMARY KEY,
    descricao VARCHAR(15) NOT NULL
);

CREATE TABLE IF NOT EXISTS empregado(
    cod_empregado INT PRIMARY KEY,
    cod_dpto INT,
    FOREIGN KEY (cod_dpto) REFERENCES dpto(cod_dpto) ON DELETE CASCADE,
    nome VARCHAR(50),
    dt_nascimento DATE,
    cod_sexo CHAR(1),
    FOREIGN KEY (cod_sexo) REFERENCES sexo(cod_sexo),
    dt_admissao DATE,
    cod_estado_civil CHAR(1),
    FOREIGN KEY (cod_estado_civil) REFERENCES estado_civil(cod_estado_civil),
    salario NUMERIC(10,2)
);

CREATE TABLE IF NOT EXISTS dependente(
    cod_dependente INT PRIMARY KEY,
    cod_empregado INT,
    FOREIGN KEY (cod_empregado) REFERENCES empregado(cod_empregado) ON DELETE CASCADE,
    nome VARCHAR(50),
    dt_nascimento DATE,
    sexo CHAR(1)
);

-- 4. Inserir dados nas tabelas
INSERT IGNORE INTO dpto(cod_dpto, nome) VALUES
(1, 'Financeiro'),
(2, 'Administrativo'),
(3, 'Pessoal'),
(4, 'Marketing');

INSERT IGNORE INTO sexo(cod_sexo, descricao) VALUES
('M', 'Masculino'),
('F', 'Feminino');

INSERT IGNORE INTO estado_civil(cod_estado_civil, descricao) VALUES
('S', 'Solteiro'),
('C', 'Casado'),
('D', 'Divorciado'),
('V', 'Viúvo');

INSERT IGNORE INTO empregado(cod_empregado, cod_dpto, nome, dt_nascimento, cod_sexo, dt_admissao, cod_estado_civil, salario) VALUES
(1, 3, 'Roberto', '1980-08-15', 'M', NOW(), 'S', 1360.29),
(2, 1, 'Ana', '1990-03-22', 'F', '2005-04-27', 'C', 2500.00),
(3, 2, 'Carlos', '1985-07-10', 'M', NOW(), 'S', 1800.50),
(4, 3, 'Fernanda', '1992-01-15', 'F', '2001-09-15', 'C', 2100.75),
(5, 1, 'Ricardo', '1988-05-30', 'M', NOW(), 'S', 2300.00),
(6, 2, 'Patrícia', '1983-11-25', 'F', '1997-05-16', 'D', 2200.00),
(7, 3, 'João', '1975-09-12', 'M', NOW(), 'S', 3000.00);

-- Exemplo de inserção de dependentes (para teste)
INSERT IGNORE INTO dependente(cod_dependente, cod_empregado, nome, dt_nascimento, sexo) VALUES
(1, 1, 'Filho1', '2010-01-01', 'M'),
(2, 1, 'Filho2', '2012-02-02', 'F'),
(3, 2, 'Filho3', '2015-03-03', 'M');

-- 5. Criar Stored Procedures
DELIMITER $$

CREATE PROCEDURE infodpto(IN p_cod_dpto INT)
BEGIN
    DECLARE soma_dpto DECIMAL(10, 2) DEFAULT 0;
    DECLARE media_dpto DECIMAL(10,2) DEFAULT 0;
    DECLARE maior_salario DECIMAL(10, 2) DEFAULT 0;
    DECLARE menor_salario DECIMAL(10, 2) DEFAULT 0;

    SELECT SUM(salario) INTO soma_dpto FROM empregado WHERE cod_dpto = p_cod_dpto;
    SELECT AVG(salario) INTO media_dpto FROM empregado WHERE cod_dpto = p_cod_dpto;
    SELECT MIN(salario) INTO menor_salario FROM empregado WHERE cod_dpto = p_cod_dpto;
    SELECT MAX(salario) INTO maior_salario FROM empregado WHERE cod_dpto = p_cod_dpto;

    SELECT soma_dpto AS 'Total Salarios',
           media_dpto AS 'Media Salarios',
           maior_salario AS 'Maior Salario',
           menor_salario AS 'Menor Salario';
END $$

CREATE PROCEDURE sexo_func(IN p_cod_dpto INT)
BEGIN
    DECLARE qntd_masc INT DEFAULT 0;
    DECLARE qntd_fem INT DEFAULT 0;
    
    SELECT COUNT(*)
    INTO qntd_masc
    FROM empregado
    WHERE cod_dpto = p_cod_dpto AND cod_sexo = 'M';
    
    SELECT COUNT(*)
    INTO qntd_fem
    FROM empregado
    WHERE cod_dpto = p_cod_dpto AND cod_sexo = 'F';
    
    SELECT qntd_masc AS 'Funcionarios',
           qntd_fem AS 'Funcionarias';
END $$

CREATE PROCEDURE inserirValores(IN p_cod_dpto INT, IN p_nome_dpto VARCHAR(50))
BEGIN
    INSERT INTO dpto(cod_dpto, nome) VALUES (p_cod_dpto, p_nome_dpto);
END $$

CREATE PROCEDURE alteraSalario()
BEGIN
    UPDATE empregado
    SET salario = salario * 1.05
    WHERE cod_sexo = 'F';
END $$

CREATE PROCEDURE ganhoPercent(IN p_valor_percent DECIMAL(5,2))
BEGIN
    UPDATE empregado
    SET salario = salario * (1 + p_valor_percent / 100)
    WHERE cod_sexo = 'M';
END $$

-- 6. Nova Stored Procedure para calcular a média salarial de todos os empregados
-- Objetivo: Esta stored procedure calcula e retorna a média salarial de todos os empregados na tabela "empregado".
CREATE PROCEDURE mediaSalarioEmpregados()
BEGIN
    DECLARE media_salario DECIMAL(10, 2) DEFAULT 0;

    SELECT AVG(salario) INTO media_salario FROM empregado;

    SELECT media_salario AS 'Media Salarial de Todos os Empregados';
END $$

DELIMITER ;

-- 7. Chamar procedimentos de exemplo
CALL inserirValores(5, 'TI');
CALL alteraSalario();
CALL ganhoPercent(10);
CALL mediaSalarioEmpregados(); -- Chama a nova stored procedure
