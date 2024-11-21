const express = require("express");
const cors = require("cors");
const db = require("../mysql"); // Conexão com o banco de dados MySQL

// Criação do servidor Express
const app = express();
const port = 3000;

// Configurações do Express
app.use(express.json()); // Para trabalhar com JSON no corpo das requisições
app.use(cors()); // Habilitar CORS para requisições de outros domínios

// Rota para listar todos os clientes
app.get("/clientes", (req, res) => {
  db.query("SELECT * FROM Cliente", (err, results) => {
    if (err) {
      return res.status(500).json({ error: err.message });
    }
    res.json(results);
  });
});

// Rota para obter um cliente por CPF
app.get("/clientes/:cpf", (req, res) => {
  const cpf = req.params.cpf;
  db.query("SELECT * FROM Cliente WHERE cpf_cli = ?", [cpf], (err, results) => {
    if (err) {
      return res.status(500).json({ error: err.message });
    }
    if (results.length > 0) {
      res.json(results[0]);
    } else {
      res.status(404).json({ message: "Cliente não encontrado" });
    }
  });
});

// Rota para adicionar um novo cliente
app.post("/clientes", (req, res) => {
  const { cpf_cli, nome_cli, endereco_cli, telefone_cli, email_cli, cidade_cli } = req.body;

  // Validação de campos obrigatórios
  if (!cpf_cli || !nome_cli || !telefone_cli || !email_cli || !cidade_cli) {
    return res.status(400).json({ message: "Todos os campos são obrigatórios." });
  }

  const newCliente = { cpf_cli, nome_cli, endereco_cli, telefone_cli, email_cli, cidade_cli };

  db.query("INSERT INTO Cliente SET ?", newCliente, (err, result) => {
    if (err) {
      return res.status(500).json({ error: err.message });
    }
    res.status(201).json({ id_cliente: result.insertId, ...newCliente });
  });
});

// Rota para atualizar um cliente
app.put("/clientes/:cpf", (req, res) => {
  const cpf = req.params.cpf;
  const { nome_cli, endereco_cli, telefone_cli, email_cli, cidade_cli } = req.body;

  const updatedCliente = { nome_cli, endereco_cli, telefone_cli, email_cli, cidade_cli };
  db.query("UPDATE Cliente SET ? WHERE cpf_cli = ?", [updatedCliente, cpf], (err, result) => {
    if (err) {
      return res.status(500).json({ error: err.message });
    }
    if (result.affectedRows > 0) {
      res.json({ cpf_cli: cpf, ...updatedCliente });
    } else {
      res.status(404).json({ message: "Cliente não encontrado" });
    }
  });
});

// Rota para deletar um cliente
app.delete("/clientes/:cpf", (req, res) => {
  const cpf = req.params.cpf;
  db.query("DELETE FROM Cliente WHERE cpf_cli = ?", [cpf], (err, result) => {
    if (err) {
      return res.status(500).json({ error: err.message });
    }
    if (result.affectedRows > 0) {
      res.status(204).send();
    } else {
      res.status(404).json({ message: "Cliente não encontrado" });
    }
  });
});

// Iniciar o servidor
app.listen(port, () => {
  console.log(`Servidor rodando em http://localhost:${port}`);
});
