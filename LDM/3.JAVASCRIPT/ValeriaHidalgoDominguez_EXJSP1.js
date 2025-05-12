/*EJERCICIO 1--> Se pide que dado un formulario se introduzca la matrícula de un coche y los litros y
salga el precio del repostaje sabiendo que cada litro es 1,26 euros. Comprueba que
la matrícula cumple tres letras y 4 números, sino muestra un mensaje de error.*/

function calcularPrecio(){
    let precioLitro = 1.26;
    let litros = parseInt(document.getElementById('litros').value);
        if(litros<0){
            alert("Ese valor no es válido.");
        }
        else{
            let precioTotal = litros * precioLitro;
        }
    let matricula = document.getElementById('matricula').value;
     
    let numerosM = matricula.split(4);
    let letrasM;
}

/*El juego de los trileros. Dados tres botones ubicados en una tabla con una sola fila
que se vinculan con un array, genera aleatoriamente una posición donde está la
bola y el usuario la tiene que adivinar dándole al botón cree que está. Si no está se
bloquea el botón, y si está nuestra la bola representada por una o.*/

function trilero(){
    let tablero=[1,2,3];
    let botones = document.querySelectorAll('.boton');
    let bola = Math.floor(Math.random() * 3);

    
}



function main(){

    document.addEventListener("click", getElementById('0'));
    document.writeln("TOTAL: " + precioTotal + " €.");

    calcularPrecio();

}

window.addEventListener("DOMContentLoaded",main, false);

function generarLetraAleatoria() {
    const abecedario = "abcdefghijklmnopqrstuvwxyz";
    const i = Math.floor(Math.random() * abecedario.length);
    return abecedario[i];
}

function llenarTabla() {
    const celdas = document.querySelectorAll('#tabla td');
    letras = [];

    celdas.forEach(celda => {
        let letra = generarLetraAleatoria();
        celda.textContent = letra;
        letras.push(letra);
        celda.addEventListener('click', () => contarClick(celda));
    });
}

function generarLetraValida() {
    let letra = "";
    do {
        letra = generarLetraAleatoria();
    } while (!letras.includes(letra)); // aseguramos que esté en la tabla
    return letra;
}

function generarNumeroAleatorio() {
    return Math.floor(Math.random() * 5) + 1; // entre 1 y 5
}

let letraObjetivo;
let intentosNecesarios;
let clics = 0;
let letras = [];

function contarClick(celda) {
    if (celda.textContent === letraObjetivo) {
        clics++;
        if (clics === intentosNecesarios) {
            document.getElementById("message").textContent = "¡Correcto! Has hecho " + intentosNecesarios + " clics en '" + letraObjetivo + "'.";
        } else {
            document.getElementById("message").textContent = `Haz clic en '${letraObjetivo}' (${intentosNecesarios - clics} restantes)`;
        }
    }
}

function iniciarJuego() {
    llenarTabla();
    letraObjetivo = generarLetraValida();
    intentosNecesarios = generarNumeroAleatorio();
    clics = 0;
    document.getElementById("message").textContent = `Haz clic en la letra '${letraObjetivo}' ${intentosNecesarios} veces.`;
}

window.addEventListener("DOMContentLoaded", iniciarJuego);
