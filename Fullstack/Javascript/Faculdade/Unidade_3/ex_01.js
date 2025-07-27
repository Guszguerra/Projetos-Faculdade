const numeros = [10, 20, 30, 40, 50];
let soma = 0;

numeros.forEach((numero) => { //numero é o elemento atual do array
  soma += numero; //a cada elemento do array numeros a soma vai ser atualizada com o valor anterior de soma + o valor atual 
});

console.log("A soma dos numeros é:", soma);