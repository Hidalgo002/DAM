function random(number){
    return Math.floor(Math.random()*(number+1)); //Devuelve un número aleatorio cuyo 
                                    // máximo es un número introducido por el usuario +1
}

function cambiarFondo() {
    document.body.style.background = `rgb(${random(255)}, ${random(255)}, ${random(255)})`;
}

function cambiarTexto(){
    document.body.innerHTML="HOLA";
}

function load() {
    let boton1 = document.getElementById("button1"); // Document hace referencia al documento HTML principal
                                                      // getElementById busca el id en específico dentro del HTML
    boton1.addEventListener("click", cambiarFondo, false);

    let boton2=document.getElementById("button2");
    boton2.addEventListener("click", cambiarTexto, false);

    let cuadroTexto=document.getElementById("cuadroTexto");
    cuadroTexto=addEventListener("keydown",(event)=>(), false);
}


window.addEventListener("DOMContentLoaded", load, false);
