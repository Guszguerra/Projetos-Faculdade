/*10. Criar uma função chamada busca que recebe um array e uma função de callback, e retorna o primeiro
elemento do array que atende a uma determinada condição definida pela função de call-back (que retorna
verdade se o numero for par), caso contrário retorna undefined.*/

//Criar uma função chamada busca
//função busca recebe um array e uma função de callback
//função busca retorna o primeiro elemento do array q atende a uma condição especificada pela função de callback
//função de callback retorna true se o numero for par
// se não for retorna undefined

const produtos = ['Pinho sol','geladeira','abacaxi','bomba','remedio'];

function busca(produtos, callback){ 
  return produtos.find(callback); //retorna primeiro ele do array q atende ao callback
}

function callback(produto){ //retorna true se tiver mais de 6 letras.
  return produto.length > 6;
}

console.log(busca(produtos, callback));