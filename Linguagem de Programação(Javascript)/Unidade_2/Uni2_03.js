//Definir uma função de primeira classe que retorna outra função.
//Função de soma q retorna função de mostrar a soma.

function Somar(a, b, mostrarSoma){ //Definindo função de primeira classe
  let resultado = a+b;
  return function(){ //Retorna outra função(a de mostrar a soma)
    mostrarSoma(resultado);
  } ;
}

function mostrarSoma(resultado){ //Função de mostrar a soma
  console.log(`${resultado}.`);
}

//Exemplo em uso
const funcaoMostrar = Somar(9, 8, mostrarSoma); //Criando uma funcao q vai mostrar o resultado da função somar com 9 e 8 de parametros.

funcaoMostrar();

