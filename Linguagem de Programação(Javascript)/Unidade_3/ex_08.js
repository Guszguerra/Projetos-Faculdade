//8. Mostre o primeiro animal com mais de 6 letras. Use find.

const animais = ["gato", "cachorro", "elefante", "rato", "leao"];

const Maior = animais.find((animais) => animais.length > 6);

console.log(Maior);