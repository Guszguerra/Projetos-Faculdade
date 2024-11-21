//10. Defina uma função seta que seja passada como argumento para outra função.

const somar = (a, b) => a + b;

function mostrarMsg(funcaoDeSoma, a,b){
  const resultado = funcaoDeSoma(a, b);
  console.log(`A soma é ${resultado}.`);
}

mostrarMsg(somar,2, 6);