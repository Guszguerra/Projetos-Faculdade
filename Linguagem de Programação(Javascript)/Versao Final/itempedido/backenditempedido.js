const express = require('express');
const cors = require('cors');
const db = require('../mysql'); // Arquivo de conexão com o MySQL
const app = express();
const port = 3000;

app.use(express.json());
app.use(cors());

// Verificar conexão com o banco de dados
db.connect(err => {
    if (err) {
        console.error("Erro ao conectar ao banco de dados:", err);
        process.exit(1);
    }
    console.log("Conexão com o banco de dados estabelecida");
});

// Validação de Campos
function validarCamposItemPedido(req, res, next) {
    const { id_pedido, id_produto, quantidade_produto, precoUni_produto } = req.body;
    if (!id_pedido || !id_produto || typeof quantidade_produto !== 'number' || typeof precoUni_produto !== 'number') {
        return res.status(400).json({ error: 'Campos obrigatórios ausentes ou inválidos.' });
    }
    next();
}

// Listar todos os Pedidos
app.get('/pedidos', (req, res) => {
    db.query('SELECT id_pedido FROM Pedido', (err, results) => {
        if (err) {
            console.error("Erro ao buscar pedidos:", err);
            return res.status(500).json({ error: 'Erro ao buscar pedidos.' });
        }
        res.json(results);
    });
});

// Listar todos os Produtos
app.get('/produtos', (req, res) => {
    db.query('SELECT id_prod AS id_prod, nome_prod FROM Produto', (err, results) => {
        if (err) {
            console.error("Erro ao buscar produtos:", err);
            return res.status(500).json({ error: 'Erro ao buscar produtos.' });
        }
        res.json(results);
    });
});

// Listar todos os Itens do Pedido
app.get('/itenspedido', (req, res) => {
    db.query(
        `SELECT id_itemPedido AS id_item, id_pedido, id_produto, quantidade_produto AS quantidade, precoUni_produto AS preco_unitario 
         FROM ItemPedido`,
        (err, results) => {
            if (err) {
                console.error("Erro ao buscar itens do pedido:", err);
                return res.status(500).json({ error: 'Erro ao buscar itens do pedido.' });
            }
            res.json(results);
        }
    );
});

// Obter um Item do Pedido por ID
app.get('/itenspedido/:id', (req, res) => {
    const { id } = req.params;
    db.query('SELECT * FROM ItemPedido WHERE id_itemPedido = ?', [id], (err, results) => {
        if (err) {
            console.error("Erro ao buscar item:", err);
            return res.status(500).json({ error: 'Erro ao buscar item do pedido.' });
        }
        if (results.length === 0) {
            return res.status(404).json({ error: 'Item não encontrado.' });
        }
        res.json(results[0]);
    });
});

// Adicionar novo Item do Pedido
app.post('/itenspedido', validarCamposItemPedido, (req, res) => {
    const { id_pedido, id_produto, quantidade_produto, precoUni_produto } = req.body;
    db.query(
        'INSERT INTO ItemPedido (id_pedido, id_produto, quantidade_produto, precoUni_produto) VALUES (?, ?, ?, ?)',
        [id_pedido, id_produto, quantidade_produto, precoUni_produto],
        (err, result) => {
            if (err) {
                console.error("Erro ao adicionar item:", err);
                return res.status(500).json({ error: 'Erro ao adicionar item.' });
            }
            res.status(201).json({ id_item: result.insertId, id_pedido, id_produto, quantidade_produto, precoUni_produto });
        }
    );
});

// Atualizar Item do Pedido
app.put('/itenspedido/:id', validarCamposItemPedido, (req, res) => {
    const { id } = req.params;
    const { id_pedido, id_produto, quantidade_produto, precoUni_produto } = req.body;
    db.query(
        'UPDATE ItemPedido SET id_pedido = ?, id_produto = ?, quantidade_produto = ?, precoUni_produto = ? WHERE id_itemPedido = ?',
        [id_pedido, id_produto, quantidade_produto, precoUni_produto, id],
        (err, result) => {
            if (err) {
                console.error("Erro ao atualizar item:", err);
                return res.status(500).json({ error: 'Erro ao atualizar item.' });
            }
            if (result.affectedRows === 0) {
                return res.status(404).json({ error: 'Item não encontrado.' });
            }
            res.json({ id_item: id, id_pedido, id_produto, quantidade_produto, precoUni_produto });
        }
    );
});

// Deletar Item do Pedido
app.delete('/itenspedido/:id', (req, res) => {
    const { id } = req.params;
    db.query('DELETE FROM ItemPedido WHERE id_itemPedido = ?', [id], (err, result) => {
        if (err) {
            console.error("Erro ao deletar item:", err);
            return res.status(500).json({ error: 'Erro ao deletar item.' });
        }
        if (result.affectedRows === 0) {
            return res.status(404).json({ error: 'Item não encontrado.' });
        }
        res.status(204).send();
    });
});

app.listen(port, () => {
    console.log(`Servidor rodando na porta ${port}`);
});
