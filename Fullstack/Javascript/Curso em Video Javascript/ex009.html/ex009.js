var botao = document.getElementById("botaopais");
botao.addEventListener('click', verificar);

    function verificar(){
        var txtpais = document.getElementById("txtcountry").value;
        var resposta = document.getElementById("Resposta");
        resposta.innerHTML = (`Você mora em: <strong>${txtpais}</strong>.<br>`);

        if(txtpais === "Brasil"){
            resposta.innerHTML += "<br>Você é <strong>Brasileiro</strong>.";
        } else{
            resposta.innerHTML += "<br>Você é <strong>estrangeiro</strong>.";
        }
    }