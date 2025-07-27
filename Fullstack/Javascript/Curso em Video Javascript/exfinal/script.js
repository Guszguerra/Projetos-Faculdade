let nums = []; //Criando uma variavel que vai guardar o conjunto de números adicionados pelos usuários.
let tab = document.getElementById("tab"); //Trazendo a tabela(na vdd é um select) do html pro JS

function Adicionar(){ //Criando uma função que dispara quando o botão Adicionar receber um click
    let newnum = Number(document.getElementById("txtnum").value); //Pegando o valor do numero digitado
  
    if((nums.includes(newnum)) || (newnum > 100) || (newnum < 1) || (isNaN(newnum))){ //Se((já houver um valor igual o que for ser adicionado no array nums) ou (numero maior que 100 ou menor que um) ou (novo numero não for um numero))
        alert("Valor inválido ou já encontrado na lista.");
    }
    else{ //Se nao
        nums.push(newnum); //Coloca o valor novo adicionado como Último valor do array.
        tab.innerHTML = ""; //Limpando a exibição anterior
    
        for(num of nums){ //Para cada numero no array nums:
            let exibicao = document.createElement('option'); //Criando variavel que cria um elemento novo de opção no Html
            exibicao.text = `${num} adicionado.`; //Texto da opção, que vai conter o valor adicionado
            tab.appendChild(exibicao); //Mostrando o texto na tabela/select
        }
    }   
}

function Contar(){ //Criando uma função que dispara quando o botão Finalizar receber um click
    if(nums.length == 0){  //Se a quantidade de numeros dentro do array nums for igual à zero
        alert("Adicione valores antes de finalizar.")
    }
    else{ //Se não
        let res = document.getElementById("res"); //Trazendo a segunda do html pro JS (P/ guardar texto final)
        nums.sort(); //Colocando os valores em ordem crescente
        let maiornum; //Criando uma variável para o maior número
        maiornum = nums[nums.length - 1]; // guardando o maior numero do array nela(fazemos isso selecionando o numero resultante da largura do array menos 1)
        let menornum; //Criando uma variável para o menor número
        menornum = nums[0]; //menor número é a posíção zero do array ordenado
        let soma = 0; //Criando a variável soma para guardar a soma dos numeros do array, inicia com um valor numérico.
        for(let index in nums){ //Para cada index(numero) no array nums
            soma += nums[index]; //soma recebe o valor da soma anterior + o valor do número(de todos os index)
        }
        let media = soma/nums.length;



        res.innerHTML = ""; //Limpando para ficar organizado na adição de novos números ao array.
        res.innerHTML += `Ao todo, temos ` + nums.length + ` números cadastrados.<br>`;
        res.innerHTML += `<br> O maior número informado foi:  ` + maiornum + `.<br>`;
        res.innerHTML += `<br> O menor número informado foi: ` + menornum + `.<br>`;
        res.innerHTML += `<br> O valor da soma dos números informados foi: ` + soma + `.<br>`;
        res.innerHTML += `<br> O valor da média dos números informados foi: ` + media + `.<br>`;
    }
}


