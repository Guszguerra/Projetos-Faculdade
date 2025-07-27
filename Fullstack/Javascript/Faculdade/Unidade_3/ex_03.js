//3. Mostre os numeros pares. Use filter.

//filter é usado p criar um array novo apenas com elementos que atendam a um determinado requisito dado por uma função callback

const numeros = [10, 20, 30, 40, 50 ];
const pares = numeros.filter((n) => n % 2 === 0);

console.log(pares);