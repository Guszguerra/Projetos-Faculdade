/*1.Defina uma função que receba uma função como argumento e retorne
o resultado da função.*/

//Fazer isso com uma msg com o nome do usuario e uma msg  de exclusao de conta
//Primeiro fazer uma função excluir com a msg de exclusão e o nome da pessoa
//Depois fazer uma função que faz a msg ser exibida.

function excluir(nome, callback){
  console.log("Olá, " + nome + "!");
  callback();
}

function mostrarMsg(){
  console.log("Venho infelizmente informar que sua conta foi deletada.");
}

excluir("Gustavo", mostrarMsg);