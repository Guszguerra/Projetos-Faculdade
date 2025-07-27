//2. Mostre os numeros maiores que 25. Use foreach.

const numeros = [10, 20, 30, 40, 50];
let maiores = [];//Criando array vazio

numeros.forEach((numero) => {// para cada numero do array 
  if (numero > 25){ //se o numero for maior q 25
    maiores += numero + " "; //array dos numeros maiores q 25
  }
});//

console.log("Os maiores que 25 são: ", maiores);