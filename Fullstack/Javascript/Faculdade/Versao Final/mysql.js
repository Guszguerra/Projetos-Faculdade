const mysql = require("mysql2");

// Configuração da conexão com o banco de dados MySQL
const db = mysql.createConnection({
  host: "127.0.0.1",
  user: "root",
  password: "Mitaka73289135.", // Adicione sua senha aqui, se houver
  database: "mercado" // Usando seu banco de dados 'categoria_prod'
});

// Conexão com o banco de dados
db.connect((err) => {
  if (err) {
    console.error("Erro ao conectar ao MySQL:", err);
    return;
  }
  console.log("Conectado ao banco de dados MySQL.");
});

module.exports = db;
