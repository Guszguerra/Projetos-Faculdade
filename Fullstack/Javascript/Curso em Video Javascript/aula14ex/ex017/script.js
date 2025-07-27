let botao = document.getElementById("botao");
let tab = document.getElementById("seltab");
botao.addEventListener('click', Gerar);

function Gerar(){

let number = document.getElementById("numero");
if(number.value.length == 0){
    window.alert("Digite um valor válido no campo.");
}
else{
    let n = Number(number.value);
    tab.innerHTML = "";
    for(let i = 1; i<=10; i++){
        let nresultado = n * i;
        let item = document.createElement('option');
        item.text = `${n} x ${i} = ${nresultado}`;
        item.value = `tab${c}`;
        tab.appendChild(item);
    }    
}

}