/*Crea una tabla En HTML que contenga botones numerados del 1 al 9 detrás que
esté vinculada con una matriz que se genera con números del 0-8 al otro de forma
aleatorio, el usuario debe adivinar qué número está detrás pulsando los botones.
Solo tiene tres intentos, que se van descontando a medida que el usuario va
probando números. El número a adivinar se genera también de manera aleatoria. En
la versión fácil los números no se pueden repetir, pero en una versión más difícil los
números se repiten y hay que notificar al usuario cuantos hay de cada número.*/

//Inicialización de variable global
let numeroAdivinar=0;

//Inicialización de matriz
let matriz=[[0,0,0],[0,0,0],[0,0,0]];

//Bandera
let veces=0;

// Nuevo: intentos restantes
let intentosRestantes = 3;



/*Funcion para generar un número aleatorio. '(Math.random()*(numero+1))'
genera un número aleatoro en el rango de 'numero+1'. El 'numero' esta puesto a dedo
'Math.floor' redondea el número. Se guarda en la vaaribal 'numeroAleatorio'*/
function random(numero){
    let numeroAleatorio = Math.floor(Math.random()*(numero+1));
    return numeroAleatorio;
}

function generarNumeroAdivinar(){
    numeroAdivinar = random(8); // corregido: antes estabas creando una variable nueva local
    document.getElementById("numeroAdivinar").textContent=numeroAdivinar;
}

function generarVeces(){
    document.getElementById("veces").textContent = veces; // corregido: se estaba llamando pero no se actualizaba el contenido
}

//Actualizar intentos
function actualizarIntentos(){
    document.getElementById("intentos").textContent = intentosRestantes;
}

//Función de rellenar matriz
function rellenarMatriz(){
    veces=0;
    for(let i=0;i<3;i++){
        for(let j=0;j<3;j++){
            matriz[i][j]=random(8);
            if (matriz[i][j]===numeroAdivinar){
                veces++;
            }
        }
    }

    if(veces===0){
        matriz[random(2)][random(2)]=numeroAdivinar;
        veces=1;
    }
}

//DESACTIVAR BOTONES
function desactivarBoton(boton){
    boton.disabled = true;
}
//desactiva todos los botones del tablero UNA VEZ ACABADOS LOS INTENTOS
function desactivarTodosLosBotones(){
    let botones = document.querySelectorAll(".boton");
    botones.forEach(boton => boton.disabled = true);
}

//Función comprobar numeros
function comprobarNumeros(event){
    let i = event.target.value[0];
    let j = event.target.value[1];

    if(matriz[i][j]===numeroAdivinar){
        document.getElementById(event.target.value).textContent=matriz[i][j];
    } else {
        alert("No es el mismo número");
        console.log("Valor detrás del botón: ",matriz[i][j]);
    }

    desactivarBoton(event.target); // Siempre desactiva el botón tras usarse

    intentosRestantes--;
    actualizarIntentos();

    if (intentosRestantes === 0) {
        alert("¡Has agotado tus 3 intentos!");
        desactivarTodosLosBotones();
    }
}

function main(){
    generarNumeroAdivinar();
    rellenarMatriz();
    generarVeces();
    actualizarIntentos(); // Muestra intentos al iniciar

    let botonesNumeros = document.querySelectorAll(".boton");
    botonesNumeros.forEach(boton=>boton.addEventListener("click",comprobarNumeros));
}

window.addEventListener("DOMContentLoaded", main);
