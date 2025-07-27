function carregar(){
    let msg = document.getElementById("msg");
    let img = document.getElementById("imagem");
    let data = new Date();
    let hora = data.getHours();
    msg.innerHTML = `Agora são: ${hora}hrs.`;

    if(hora >= 6 && hora < 12){
        //BOMDIA
        img.src = 'fotomanha.png';
        document.body.style.background = '#e8c091';
    } else if(hora >= 12 && hora < 18){
        //BOATARDE
        img.src = 'fototarde.png';
        document.body.style.background = '#ff9b15';
    }   else{
        //BOANOITE
        img.src = 'fotonoite.png';
        document.body.style.background = '#212032';
    }
}    
    
