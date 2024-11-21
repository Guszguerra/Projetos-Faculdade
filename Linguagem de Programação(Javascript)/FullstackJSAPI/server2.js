// Importação das bibliotecas necessárias
const express = require("express");
const cors = require("cors");

// Criação do servidor Express
const app = express();
const port = 3000;

// Configurações do Express
app.use(express.json());
app.use(cors());

// Array em memória para armazenar os produtos
let produtos = [];
let nextId = 1; // ID inicial

// Rota para listar todos os produtos
app.get("/produtos", (req, res) => {
  res.json(produtos);
});

// Rota para obter um produto por ID
app.get("/produtos/:id", (req, res) => {
  const id = parseInt(req.params.id);
  const produto = produtos.find(p => p.id === id);
  if (produto) {
    res.json(produto);
  } else {
    res.status(404).json({ message: "Produto não encontrado" });
  }
});

// Rota para adicionar um novo produto
app.post("/produtos", (req, res) => {
  const { descricao, quantidade, valor } = req.body;
  const newProduto = { id: nextId++, descricao, quantidade, valor };
  produtos.push(newProduto);
  res.status(201).json(newProduto);
});

// Rota para atualizar um produto
app.put("/produtos/:id", (req, res) => {
  const id = parseInt(req.params.id);
  const index = produtos.findIndex(p => p.id === id);
  if (index !== -1) {
    const { descricao, quantidade, valor } = req.body;
    produtos[index] = { id, descricao, quantidade, valor };
    res.json(produtos[index]);
  } else {
    res.status(404).json({ message: "Produto não encontrado" });
  }
});

// Rota para remover um produto
app.delete("/produtos/:id", (req, res) => {
  const id = parseInt(req.params.id);
  const index = produtos.findIndex(p => p.id === id);
  if (index !== -1) {
    produtos.splice(index, 1);
    res.json({ message: "Produto removido com sucesso" });
  } else {
    res.status(404).json({ message: "Produto não encontrado" });
  }
});

// Inicia o servidor
app.listen(port, () => {
  console.log(`Servidor iniciado na porta ${port}`);
});
