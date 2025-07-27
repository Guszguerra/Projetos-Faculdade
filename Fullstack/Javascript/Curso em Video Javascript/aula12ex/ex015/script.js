let botao = document.getElementById("botaoidadesexo");
botao.addEventListener('click', verificar);

function verificar(){
    let data = new Date();
    let ano = data.getFullYear();
    let fano = document.getElementById("txtano");
    let res = document.querySelector("div#res");

    if(fano.value.length == 0 || Number(fano.value) > ano){
        alert("Esta data não condiz com o sistema.\nDigite uma data real.");
    } else {
        let fsex = document.getElementsByName("radsex");
        let idade = ano - Number(fano.value);
        let genero = '';
        let imagem = document.createElement('img');
        imagem.setAttribute('id', 'foto');

        if(fsex[0].checked){
            genero = 'Homem';
            if(idade >= 0 && idade < 10){
                imagem.setAttribute('src', 'homembebeimagem.png');
            } else if(idade < 21){
                imagem.setAttribute('src', 'homemjovemimagem.png');
            } else if(idade < 60){
                imagem.setAttribute('src', 'homemmaduroimagem.png');
            } else{
                imagem.setAttribute('src', 'velhoimagem.png');
            }

        } else if(fsex[1].checked){
            genero = 'Mulher';

            if(idade >= 0 && idade < 10){
                imagem.setAttribute('src', 'mulherbebeimagem.png');
            } else if(idade < 21){
                imagem.setAttribute('src', 'mulherjovemimagem.png');
            } else if(idade < 60){
                imagem.setAttribute('src', 'mulhermaduraimagem.png');
            } else {
                imagem.setAttribute('src', 'velhaimagem.png');
            }
        }

        res.style.textAlign = 'center';
        res.innerHTML = `Detectamos ${genero} com ${idade} anos.`;
        res.appendChild(imagem);
    }

}