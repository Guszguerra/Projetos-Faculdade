const express = require("express");
const cors = require("cors");
const db = require("../mysql"); // Conexão com o banco de dados MySQL

// Criação do servidor Express
const app = express();
const port = 3000;

// Configurações do Express
app.use(express.json()); // Para trabalhar com JSON no corpo das requisições
app.use(cors()); // Habilitar CORS para requisições de outros domínios

// Rota para listar todas as categorias
app.get("/categorias", (req, res) => {
  db.query("SELECT * FROM Categoria", (err, results) => { // Alterado aqui
    if (err) {
      return res.status(500).json({ error: err.message });
    }
    res.json(results);
  });
});

// Rota para obter uma categoria por ID
app.get("/categorias/:id", (req, res) => {
  const id = parseInt(req.params.id);
  db.query("SELECT * FROM Categoria WHERE id_categoria = ?", [id], (err, results) => { // Alterado aqui
    if (err) {
      return res.status(500).json({ error: err.message });
    }
    if (results.length > 0) {
      res.json(results[0]);
    } else {
      res.status(404).json({ message: "Categoria não encontrada" });
    }
  });
});

// Rota para adicionar uma nova categoria
app.post("/categorias", (req, res) => {
  const { nome_categoria, descricao_categoria, status_categoria, prioridade_categoria } = req.body;

  // Validação de campos obrigatórios e intervalo de prioridade
  if (!nome_categoria || prioridade_categoria < 0 || prioridade_categoria > 5) {
    return res.status(400).json({ message: "Nome e prioridade são obrigatórios e prioridade deve estar entre 0 e 5." });
  }

  // Cria uma nova categoria sem definir id_categoria (autoincrementado no banco)
  const newCategoria = { nome_categoria, descricao_categoria, status_categoria, prioridade_categoria };

  // Executa a inserção
  db.query("INSERT INTO Categoria SET ?", newCategoria, (err, result) => { // Alterado aqui
    if (err) {
      return res.status(500).json({ error: err.message });
    }
    res.status(201).json({ id_categoria: result.insertId, ...newCategoria });
  });
});

// Rota para atualizar uma categoria
app.put("/categorias/:id", (req, res) => {
  const id = parseInt(req.params.id);
  const { nome_categoria, descricao_categoria, status_categoria, prioridade_categoria } = req.body;

  if (!nome_categoria || prioridade_categoria < 0 || prioridade_categoria > 5) {
    return res.status(400).json({ message: "Nome e prioridade são obrigatórios e prioridade deve estar entre 0 e 5." });
  }

  const updatedCategoria = { nome_categoria, descricao_categoria, status_categoria, prioridade_categoria };
  db.query("UPDATE Categoria SET ? WHERE id_categoria = ?", [updatedCategoria, id], (err, result) => { // Alterado aqui
    if (err) {
      return res.status(500).json({ error: err.message });
    }
    if (result.affectedRows > 0) {
      res.json({ id_categoria: id, ...updatedCategoria });
    } else {
      res.status(404).json({ message: "Categoria não encontrada" });
    }
  });
});

// Rota para deletar uma categoria
app.delete("/categorias/:id", (req, res) => {
  const id = parseInt(req.params.id);
  db.query("DELETE FROM Categoria WHERE id_categoria = ?", [id], (err, result) => { // Alterado aqui
    if (err) {
      return res.status(500).json({ error: err.message });
    }
    if (result.affectedRows > 0) {
      res.status(204).send();
    } else {
      res.status(404).json({ message: "Categoria não encontrada" });
    }
  });
});

// Iniciar o servidor
app.listen(port, () => {
  console.log(`Servidor rodando em http://localhost:${port}`);
});
