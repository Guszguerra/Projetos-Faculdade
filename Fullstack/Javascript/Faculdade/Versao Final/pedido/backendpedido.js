const express = require("express");
const cors = require("cors");
const db = require("../mysql"); // Conexão com o banco de dados MySQL

const app = express();
const port = 3000;

app.use(express.json()); // Para trabalhar com JSON no corpo das requisições
app.use(cors()); // Habilitar CORS para requisições de outros domínios

// Rota para listar todos os pedidos
app.get("/pedidos", (req, res) => {
    db.query("SELECT * FROM Pedido", (err, results) => {
        if (err) {
            return res.status(500).json({ error: err.message }); // Retorna erro se houver falha na consulta
        }
        res.json(results); // Retorna a lista de pedidos
    });
});

// Rota para obter um pedido por ID
app.get("/pedidos/:id", (req, res) => {
    const id = req.params.id;
    db.query("SELECT * FROM Pedido WHERE id_pedido = ?", [id], (err, results) => {
        if (err) {
            return res.status(500).json({ error: err.message }); // Retorna erro se houver falha na consulta
        }
        if (results.length === 0) {
            return res.status(404).json({ message: "Pedido não encontrado." }); // Retorna mensagem se o pedido não existir
        }
        res.json(results[0]); // Retorna o pedido encontrado
    });
});

// Rota para criar um novo pedido
app.post("/pedidos", (req, res) => {
    const { data_pedido, status_pedido, cpf_cli, total_pedido } = req.body;

    // Verifica se o CPF está cadastrado
    db.query("SELECT * FROM Cliente WHERE cpf_cli = ?", [cpf_cli], (err, results) => {
        if (err) {
            return res.status(500).json({ error: err.message }); // Retorna erro se houver falha na consulta
        }
        if (results.length === 0) {
            return res.status(400).json({ message: "CPF não encontrado." }); // Retorna mensagem se o CPF não estiver cadastrado
        }

        // Se o CPF estiver cadastrado, insere o novo pedido
        db.query(
            "INSERT INTO Pedido (data_pedido, status_pedido, cpf_cli, total_pedido) VALUES (?, ?, ?, ?)",
            [data_pedido, status_pedido, cpf_cli, total_pedido],
            (err, results) => {
                if (err) {
                    return res.status(500).json({ error: err.message }); // Retorna erro se houver falha na inserção
                }
                res.status(201).json({ message: "Pedido criado com sucesso.", id_pedido: results.insertId }); // Retorna mensagem de sucesso
            }
        );
    });
});

// Rota para atualizar um pedido
app.put("/pedidos/:id", (req, res) => {
    const id = req.params.id;
    const { data_pedido, status_pedido, cpf_cli, total_pedido } = req.body;

    // Verifica se o CPF está cadastrado
    db.query("SELECT * FROM Cliente WHERE cpf_cli = ?", [cpf_cli], (err, results) => {
        if (err) {
            return res.status(500).json({ error: err.message }); // Retorna erro se houver falha na consulta
        }
        if (results.length === 0) {
            return res.status(400).json({ message: "CPF não encontrado." }); // Retorna mensagem se o CPF não estiver cadastrado
        }

        // Se o CPF estiver cadastrado, atualiza o pedido
        db.query(
            "UPDATE Pedido SET data_pedido = ?, status_pedido = ?, cpf_cli = ?, total_pedido = ? WHERE id_pedido = ?",
            [data_pedido, status_pedido, cpf_cli, total_pedido, id],
            (err) => {
                if (err) {
                    return res.status(500).json({ error: err.message }); // Retorna erro se houver falha na atualização
                }
                res.json({ message: "Pedido atualizado com sucesso." }); // Retorna mensagem de sucesso
            }
        );
    });
});

// Rota para excluir um pedido
app.delete("/pedidos/:id", (req, res) => {
    const id = req.params.id;
    db.query("DELETE FROM Pedido WHERE id_pedido = ?", [id], (err, results) => {
        if (err) {
            return res.status(500).json({ error: err.message }); // Retorna erro se houver falha na exclusão
        }
        if (results.affectedRows === 0) {
            return res.status(404).json({ message: "Pedido não encontrado." }); // Retorna mensagem se o pedido não existir
        }
        res.json({ message: "Pedido excluído com sucesso." }); // Retorna mensagem de sucesso
    });
});

// Inicia o servidor
app.listen(port, () => {
    console.log(`Servidor rodando em http://localhost:${port}`); // Mensagem no console ao iniciar o servidor
});
