function cuentaAtras(){
    let cuenta;
    clearInterval(cuenta);//Inicializamos a cero el contador

    let valorTiempo = document.getElementById("tiempo").value;//Obtenemos el valor puesto en el temporizador
    let contadorTiempo = document.getElementById("contador");

    cuenta= setInterval(x,1000);
}

/* Crea una tabla en HTML e intenta que dando un botón se rellenen todas las celdas
con números secuenciales.*/
function ejercicio3(){

}

/*Cambia el fondo de un div cada vez que el ratón pase por delante del div.*/
function ejercicio4(){

}

/*Crea un array de palabras, selecciona una palabra aleatoria al cargar la pagina y
botones con cada una de las letras del abecedario. Cuando se pulse el botón de la
letra que compruebe si esa letra está y si esta que sume uno a un contador. Esa letra
no se puede volver a utilizar por lo que hay que desactivar el botón. Si hay dos letras
en la palabra se cuentan las dos*/
function ejercicio5(){

}


function load() {
    /*EJERCICIO 1 --> Crea un ejercicio que cree un número aleatorio y lo muestre cada vez que le des a un botón que diga número aleatorio */

    let botonNumero=document.getElementById("numeroAleatorio");
    botonNumero.addEventListener("click",()=>{
    let numero=Math.floor(Math.random()*100) //generamos un numero hasta el 100 incluido
    document.getElementById("mostrarNumero").textContent=numero;}  );

    /*EJERCICIO 2 --> Crea un reloj que haga una cuenta atrás del número que le hayas insertado a través de un campo de formulario.*/

    let botonAtras=document.getElementById("cuentaAtras");
    botonAtras.addEventListener("submit",cuentaAtras);
    
}

window.addEventListener("DOMContentLoaded", load, false);