
//Ejercicio 2
function cuentaAtras(event){
    let cuenta;
    clearInterval(cuenta);//Inicializamos a cero el contador

    //Evitar la recarga del formulario
    event.preventDefault(); 

    let valorTiempo = document.getElementById("tiempo").value;//Obtenemos el valor puesto en el temporizador
    let contador = document.getElementById("contador");
 
    console.log=valorTiempo;
    cuenta= setInterval(()=>{
        if(valorTiempo>0){
            contador.textContent=valorTiempo--;
        } else {
            clearInterval(cuenta); //
            contador.textContent="El tiempo ha expirado."
        }
},1000);
}

//Ejercicio 3
function rellenarTable(){
    let numero=10
    for(let i=1;i<=numero;i++){
        document.getElementById(`${i}`).textContent= i;
    }
}

function rellenarTable2(){
    let celdas = document.querySelectorAll("#tablaSegunda td"); //Seleccionamos todas las celdas (td) de la tabla
    celdas.forEach((td,i) => {td.textContent=i+1}); //Recorremos todas las celdas

}

/*Cambia el fondo de un div cada vez que el ratón pase por delante del div.*/
function random(number){
    return Math.floor(Math.random() * (number + 1)); // Genera un número aleatorio entre 0 y el máximo que le pasemos
}

function cambiarFondo(){
    let color = `rgb(${random(255)}, ${random(255)}, ${random(255)})`;
    document.getElementById("fondo").style.backgroundColor = color; // Cambiamos el color de fondo del div
}

/*Crea un array de palabras, selecciona una palabra aleatoria al cargar la pagina y
botones con cada una de las letras del abecedario. Cuando se pulse el botón de la
letra que compruebe si esa letra está y si esta que sume uno a un contador. Esa letra
no se puede volver a utilizar por lo que hay que desactivar el botón. Si hay dos letras
en la palabra se cuentan las dos*/
const palabras = ["carmelo", "rios", "ferrer", "diaz", "alcalde", "grandal"];
let palabraSeleccionada = "";
let palabraMostrada = [];
let contador = 0;

function ahorcado(event) {
    const letra = event.target.textContent;
    let aciertos = 0;

    // Comparar letra con la palabra
    for (let i = 0; i < palabraSeleccionada.length; i++) {
        if (palabraSeleccionada[i] === letra) {
            palabraMostrada[i] = letra;
            aciertos++;
        }
    }

    contador += aciertos;
    document.getElementById("palabra").value = palabraMostrada.join(" ");
    document.getElementById("resultado").value = `Letras adivinadas: ${contador}`;

    event.target.disabled = true;

    if (aciertos > 0) {
        alert(`¡Letra acertada! (${aciertos})`);
    } else {
        alert("Letra incorrecta.");
    }

    if (!palabraMostrada.includes("_")) {
        alert("¡Ganaste! Has adivinado la palabra.");
    }
}



function load() {
    /*EJERCICIO 1 --> Crea un ejercicio que cree un número aleatorio y lo muestre cada vez que le des a un botón que diga número aleatorio */

    let botonNumero=document.getElementById("numeroAleatorio");
    botonNumero.addEventListener("click",()=>{
    let numero=Math.floor(Math.random()*100) //generamos un numero hasta el 100 incluido
    document.getElementById("mostrarNumero").textContent=numero;}  );

    /*EJERCICIO 2 --> Crea un reloj que haga una cuenta atrás del número que le hayas insertado a través de un campo de formulario.*/

    let botonAtras=document.getElementById("cuentaAtras");
    botonAtras.addEventListener("click",cuentaAtras);


    /* EJERCICIO 3 --> Crea una tabla en HTML e intenta que dando un botón se rellenen todas las celdas con números secuenciales.*/
    //opcion 1
    document.getElementById("table").addEventListener("click",rellenarTable);

    //opcion 2
    document.getElementById("table2").addEventListener("click",rellenarTable2);

    
    //EJERCICIO 4 --> Cambia el fondo de un div cada vez que el ratón pase por delante del div.
    document.getElementById("fondo").addEventListener("mouseover", cambiarFondo);

    //EJERCICIO 5 -->
    // Selecciona palabra aleatoria

     palabraSeleccionada = palabras[Math.floor(Math.random() * palabras.length)];
     palabraMostrada = Array(palabraSeleccionada.length).fill("_");
     contador = 0;
 
     // Muestra los guiones bajos para la palabra
     document.getElementById("palabra").value = palabraMostrada.join(" ");
     document.getElementById("resultado").value = `Letras adivinadas: 0`;
 
     // Asocia los botones del abecedario con la función ahorcado
     const botones = document.querySelectorAll(".ejercicio5");
     botones.forEach((boton) => {
         boton.addEventListener("click", ahorcado);
     });
 
     console.log("Palabra seleccionada:", palabraSeleccionada); // Depuración
}

window.addEventListener("DOMContentLoaded", load, false);



