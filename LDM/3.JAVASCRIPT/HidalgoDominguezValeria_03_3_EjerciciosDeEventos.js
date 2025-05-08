//BARCOS
let barcos=[4,,3,2,1];

//Tablero Usuario
let tableroUsuario;

function esBarco2(posicion1, posicion2,m){ //posicion es la cadena que nos devuelve el id->u01
    if(m[i][j]==m[][]){

    }
}

function guardarBarco(event, tablero){
    let i= event.target.value[1]; //saber si es 'u' de usurio o la 'o' de ordenador
    let j= event.target.value[2];
    if(i==event.target.id[0]==='u'){
        tablero[i][j]="x";
    }
    console.log("La posición guardada es ["+i+"] ["+j+"]")
}


function main() {
    let celdasTabla = document.querySelectorAll(".celda");
    celdasTabla.forEach(celda => celda.addEventListener("keydown",guardarBarco));

}

window.addEventListener("DOMContentLoaded", main);
