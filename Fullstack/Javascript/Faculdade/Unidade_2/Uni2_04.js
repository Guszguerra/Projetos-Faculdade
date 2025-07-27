function criarMultiplicador(multiplicador) {
  return function(numero) {
    return numero * multiplicador;
  };
}

function imprimirResultado(numero, multiplicador, resultado) {
  console.log(`${numero} * ${multiplicador} = ${resultado}`);
}

// Exemplo de uso:
let multiplicarPor3 = criarMultiplicador(3);
let numero = 5;
let resultado = multiplicarPor3(numero);

imprimirResultado(numero, 3, resultado);