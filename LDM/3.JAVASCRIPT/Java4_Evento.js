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

function mostrarDatos(event) {
    event.preventDefault();
    let nombre = document.getElementById("nombre").value;
    document.getElementById("resultado").innerHTML = `Valor: ${nombre}`;
}

function load() {
//1. FUNCIÓN.
    let boton1 = document.getElementById("button1"); // Document hace referencia al documento HTML principal
                                                      // getElementById busca el id en específico dentro del HTML
    boton1.addEventListener("click", cambiarFondo, false);

//2. FUNCIÓN.
    let boton2=document.getElementById("button2");
    boton2.addEventListener("click", cambiarTexto, false);

//3. FUNCIÓN. Muestra en la consola y en el texto debajo del cuadro de texto todo lo que se ha escrito o pulsado, si se da al "Enter", entonces se ecribe Enter en el texto. Concatena todas la teclas que hemos pulsado en el teclado.
    let cuadroTexto = document.getElementById("cuadroTexto");

    cuadroTexto.addEventListener("keydown", (event)=>(document.getElementById("textoSalida").textContent+=`${event.key}`));

//4. FUNCIÓN --> En la parte de "Herramientas de desarrolladores > Consola", guarda lo que se ha hecho (un click) y las coordenadas del click
    let boton4=document.getElementById("button4");
    boton4.addEventListener("click", (event)=>console.log(event));

// Función para ver las coordenadas en una zona en concreto
    let zona = document.getElementById("zona");
    zona.addEventListener("mousemove", (event) => {
    document.getElementById("coordenadas").textContent = `Coordenadas: X=${event.clientX} - Y=${event.clientY}`;});

//6. Formulario.
    let formulario = document.getElementById("formulario");
    formulario.addEventListener("submit", mostrarDatos);

}


window.addEventListener("DOMContentLoaded", load, false);


