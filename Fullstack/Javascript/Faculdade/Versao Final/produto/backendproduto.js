const express = require('express');
const cors = require('cors');
const db = require('../mysql'); // Arquivo de conexão com o MySQL

const app = express();
const port = 3000;

app.use(express.json());
app.use(cors());

// Rota para listar todas as categorias
app.get('/categorias', (req, res) => {
    db.query('SELECT id_categoria, nome_categoria FROM Categoria', (err, results) => {
        if (err) {
            console.error("Erro ao buscar categorias:", err);
            return res.status(500).json({ error: 'Erro ao buscar categorias.' });
        }
        res.json(results);
    });
});

// Rota para listar todos os produtos
app.get('/produtos', (req, res) => {
    db.query(
        `SELECT Produto.*, Categoria.nome_categoria 
         FROM Produto 
         JOIN Categoria ON Produto.categoria_prod = Categoria.id_categoria`,
        (err, results) => {
            if (err) {
                console.error("Erro ao buscar produtos:", err);
                return res.status(500).json({ error: 'Erro ao buscar produtos.' });
            }
            res.json(results);
        }
    );
});

// Rota para obter um produto por ID
app.get('/produtos/:id', (req, res) => {
    const { id } = req.params;
    db.query('SELECT * FROM Produto WHERE id_prod = ?', [id], (err, results) => {
        if (err) {
            console.error("Erro ao buscar produto:", err);
            return res.status(500).json({ error: 'Erro ao buscar produto.' });
        }
        if (results.length === 0) {
            return res.status(404).json({ error: 'Produto não encontrado.' });
        }
        res.json(results[0]);
    });
});

// Rota para adicionar um novo produto
app.post('/produtos', (req, res) => {
    const { nome_prod, desc_prod, preco_prod, categoria_prod, estoque_prod } = req.body;

    db.query(
        'INSERT INTO Produto (nome_prod, desc_prod, preco_prod, categoria_prod, estoque_prod) VALUES (?, ?, ?, ?, ?)',
        [nome_prod, desc_prod, preco_prod, categoria_prod, estoque_prod],
        (err, result) => {
            if (err) {
                console.error("Erro ao adicionar produto:", err);
                return res.status(500).json({ error: 'Erro ao adicionar produto.' });
            }
            console.log("Produto adicionado com sucesso:", result);
            res.status(201).json({ id_prod: result.insertId, nome_prod, desc_prod, preco_prod, categoria_prod, estoque_prod });
        }
    );
});

// Rota para atualizar um produto
app.put('/produtos/:id', (req, res) => {
    const { id } = req.params;
    const { nome_prod, desc_prod, preco_prod, categoria_prod, estoque_prod } = req.body;

    db.query(
        'UPDATE Produto SET nome_prod = ?, desc_prod = ?, preco_prod = ?, categoria_prod = ?, estoque_prod = ? WHERE id_prod = ?',
        [nome_prod, desc_prod, preco_prod, categoria_prod, estoque_prod, id],
        (err, result) => {
            if (err) {
                console.error("Erro ao atualizar produto:", err);
                return res.status(500).json({ error: 'Erro ao atualizar produto.' });
            }
            if (result.affectedRows === 0) {
                console.warn("Produto não encontrado para atualização:", id);
                return res.status(404).json({ error: 'Produto não encontrado.' });
            }
            console.log("Produto atualizado com sucesso:", id);
            res.json({ id_prod: id, nome_prod, desc_prod, preco_prod, categoria_prod, estoque_prod });
        }
    );
});

// Rota para deletar um produto
app.delete('/produtos/:id', (req, res) => {
    const { id } = req.params;

    db.query('DELETE FROM Produto WHERE id_prod = ?', [id], (err, result) => {
        if (err) {
            console.error("Erro ao deletar produto:", err);
            return res.status(500).json({ error: 'Erro ao deletar produto.' });
        }
        if (result.affectedRows === 0) {
            console.warn("Produto não encontrado para exclusão:", id);
            return res.status(404).json({ error: 'Produto não encontrado.' });
        }
        console.log("Produto deletado com sucesso:", id);
        res.status(204).end();
    });
});

app.listen(port, () => {
    console.log(`Servidor rodando em http://localhost:${port}`);
});
