//9. Mostre um array novo com os animais em maiúsculo.

const animais = ["gato", "cachorro", "elefante", "rato", "leao"];

const maiusculo = animais.map((nome) => nome.toUpperCase());

console.log(maiusculo);