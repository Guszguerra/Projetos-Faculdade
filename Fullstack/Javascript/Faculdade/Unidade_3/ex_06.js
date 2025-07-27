//6. Mostre os animais. Use o foreach.

const animais = ["gato", "cachorro", "elefante", "rato", "leao"];
let conjunto = "";

animais.forEach((animal) =>{ //para cada animal no conjunto
  conjunto += animal + " "; //valor de conjunto vai ser atualizado com o valor de conjunto ant mais animal da vez e espaço.
});

console.log(conjunto);

