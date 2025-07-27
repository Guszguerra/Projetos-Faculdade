let botao = document.getElementById("botaoContar");
botao.addEventListener('click', Contar);

function Contar(){
    let numini = document.getElementById("numini");
    let numfin = document.getElementById("numfin");
    let passo = document.getElementById("passo");
    let res = document.getElementById("res");

    if (numini.value.length == 0 || numfin.value.length == 0 || passo.value.length == 0){
        window.alert("ERRO, faltam dados!");
        res.innerHTML = 'Impossível contar!';       
    }   else {
        res.innerHTML = `Contando: <br>`;
        let i = Number(numini.value);
        let f = Number(numfin.value);
        let p = Number(passo.value);

        if(p <= 0){
            window.alert("Passo Inválido! Considerando passo 1");
            p = 1;
        }
        if(i<f){
            //Contagem crescente
            for(let c = i;c <=f ;c += p) {
                res.innerHTML += `&#128073; ${c}`;
            }
        }
        else{
            //Contagem decrescente
            for (c = i; c >= f; c -= p){
                res.innerHTML += `&#128073; ${c}`;
            }
        }
        res.innerHTML += `&#128073 &#127937;`;
    }

}