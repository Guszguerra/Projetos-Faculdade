// Definindo as funções subtrair e multiplicar, que retornam valores.
function subtrair(a, b) {
  return a - b;
}

function multiplicar(a, b) {
  return a * b;
}

// A função Operacao recebe duas funções e dois números como parâmetros.
function Operacao(func1, func2, a, b) {
  // Executa as funções recebendo os números a e b.
  const resultado1 = func1(a, b);
  const resultado2 = func2(a, b);

  // Retorna a soma dos resultados.
  return resultado1 + resultado2;
}

// Definindo a função mostrarSoma para exibir o resultado.
function mostrarSoma(soma) {
  console.log(`A soma dos resultados é: ${soma}.`);
}

// Usando a função Operacao para calcular a soma dos resultados de subtrair e multiplicar.
const resultadoFinal = Operacao(subtrair, multiplicar, 4, 3);

// Exibindo o resultado final.
mostrarSoma(resultadoFinal);