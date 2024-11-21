//2. Defina uma função que receba uma função e retorne uma nova função que executa a função original
//apenas um número limitado de vezes.

function LimiteChamadaFuncao(func, limite){ //Conta quantas vezes a função foi chamada

  let contChamadas = 1; 

  return function(...args){ //função  do limite de chamada retorna função que controla n de chamadas

    if(contChamadas <= limite){
      //Aumenta o valor do contador em 1
      contChamadas++

      return func(...args); //Retorna a função original para checar novamente.
    }

    else{
      console.log("Limite de chamadas atingido.")
    }
  };
}

  //Exemplo de uso

  function dizerOi(nome){
    console.log(`Seja muito bem vindo(a)${nome}`);
  }

  const OiLimitado = LimiteChamadaFuncao(dizerOi, 2);

  OiLimitado('José');
  OiLimitado('Carlos');
  OiLimitado('Maria');
  OiLimitado('Joana');