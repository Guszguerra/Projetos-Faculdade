//6. Criar uma função chamada multiply que recebe dois números e um callback. A função deve multiplicar
//os dois números e passar o resultado para o callback.

function multiply(a, b, callback){
  let resultado = a * b;
  callback(resultado);
}