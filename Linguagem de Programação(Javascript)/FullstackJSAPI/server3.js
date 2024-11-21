// Importação das bibliotecas necessárias
const express = require("express");
const cors = require("cors");
const mysql = require("mysql2");

// Criação do servidor Express
const app = express();
const port = 3000;

// Configurações do Express
app.use(express.json());
app.use(cors());

// Configuração da conexão com o banco de dados MySQL   
const db = mysql.createConnection({
  host: "127.0.0.1",
  user: "root",
  database: "minha_loja"
});

// Conexão com o banco de dados
db.connect((err) => {
  if (err) {
    console.error("Erro ao conectar ao MySQL:", err);
    return;
  }
  console.log("Conectado ao banco de dados MySQL.");
});

// Rota para listar todos os produtos
app.get("/produtos", (req, res) => {
  db.query("SELECT * FROM Produtos", (err, results) => {
    if (err) {
      return res.status(500).json({ error: err.message });
    }
    res.json(results);
  });
});

// Rota para obter um produto por ID
app.get("/produtos/:id", (req, res) => {
  const id = parseInt(req.params.id);
  db.query("SELECT * FROM Produtos WHERE id = ?", [id], (err, results) => {
    if (err) {
      return res.status(500).json({ error: err.message });
    }
    if (results.length > 0) {
      res.json(results[0]);
    } else {
      res.status(404).json({ message: "Produto não encontrado" });
    }
  });
});

// Rota para adicionar um novo produto
app.post("/produtos", (req, res) => {
  const { descricao, quantidade, valor } = req.body;
  const newProduto = { descricao, quantidade, valor };
  db.query("INSERT INTO Produtos SET ?", newProduto, (err, result) => {
    if (err) {
      return res.status(500).json({ error: err.message });
    }
    res.status(201).json({ id: result.insertId, ...newProduto });
  });
});

// Rota para atualizar um produto
app.put("/produtos/:id", (req, res) => {
  const id = parseInt(req.params.id);
  const { descricao, quantidade, valor } = req.body;
  const updatedProduto = { descricao, quantidade, valor };
  db.query("UPDATE Produtos SET ? WHERE id = ?", [updatedProduto, id], (err, result) => {
    if (err) {
      return res.status(500).json({ error: err.message });
    }
    if (result.affectedRows > 0) {
      res.json({ id, ...updatedProduto });
    } else {
      res.status(404).json({ message: "Produto não encontrado" });
    }
  });
});

// Rota para remover um produto
app.delete("/produtos/:id", (req, res) => {
  const id = parseInt(req.params.id);
  db.query("DELETE FROM Produtos WHERE id = ?", [id], (err, result) => {
    if (err) {
      return res.status(500).json({ error: err.message });
    }
    if (result.affectedRows > 0) {
      res.json({ message: "Produto removido com sucesso" });
    } else {
      res.status(404).json({ message: "Produto não encontrado" });
    }
  });
});

// Inicia o servidor
app.listen(port, () => {
  console.log(`Servidor iniciado na porta ${port}`);
});