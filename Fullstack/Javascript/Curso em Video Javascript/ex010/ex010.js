let textovel = document.getElementById('txtvel');

function calcular() {
    let numerovel = Number(textovel.value);
    let resultado = document.querySelector("p#Resultado");
    if(numerovel > 70){
        resultado.innerHTML = `<br>Sua velocidade é de ${numerovel}<strong>Km/h</strong>,<br>Você está acima do limite permitido e você será multado.`;
    }
    else{
        resultado.innerHTML += `<br>Sua velocidade é de ${numerovel}<strong>Km/h</strong>,<br>Você está dentro do limite permitido.`;    
    }
}
