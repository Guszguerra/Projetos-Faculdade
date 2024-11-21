//7. Mostre os animais com mais de 5 letras. Use filter.

const animais = ["gato", "cachorro", "elefante", "rato", "leao"];

const maiores = animais.filter((animal) => animal.length > 5); //filtrar os nomes de animais q tem mais de 5 letras de tamanho.

console.log(maiores);