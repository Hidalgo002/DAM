//BARCOS
let barco1= "B1";
let barco2= "B2";
let barco3= "B3";
let barco4= "B4";

/****************************** TABLERO ENEMIGO ***********************************/
//MATRIZ TABLERO FIJO
let tableroFijo=[[0,"B1","B1","B1","B1",0,0,0,0,0], //1
            [0,0,0,0,0,0,0,0,0,0], //2
            [0,0,0,0,0,0,0,"B2",0,0], //3
            [0,0,0,0,0,0,0,"B2",0,0], //4
            [0,0,0,0,0,0,0,"B2",0,0], //5
            [0,0,0,0,0,0,0,0,0,0], //6
            [0,0,0,"B3","B3",0,0,0,0,0], //7
            [0,0,0,0,0,0,0,0,0,0], //8
            [0,0,0,0,0,0,0,0,0,0], //9
            [0,0,0,0,0,0,0,"B4",0,0]];//10


//FUNCION COMPROBAR SI LA CELDA ESTA VACIA
function comprobarCeldaF(event) {
      // Obtener el ID de la celda
    const id = event.target.id;

    // Asegurarse de que el id tenga tres caracteres: 100,101...
    if (id.length === 3) {
        // Extraer la fila y la columna del ID
        const fila = parseInt(id.charAt(1)); // El segundo carácter es la fila
        const columna = parseInt(id.charAt(2)); // El tercer carácter es la columna

        console.log(`Fila: ${fila}, Columna: ${columna}`);

        // Comprobar si en la posición (fila, columna) hay barco
        if (tableroFijo[fila][columna] === barco1 || tableroFijo[fila][columna] === barco2 || tableroFijo[fila][columna] === barco3 || tableroFijo[fila][columna] === barco4) {
            event.target.textContent = tableroFijo[fila][columna]; // Mostrar el barco en la celda
            alert("¡TOCADO!");
            event.target.style.background = `rgb(255, 0, 0)`; // Rojo
        } else {
            alert("¡AGUA!");
            event.target.style.background = `rgb(0, 0, 255)`; // Azul
        }
    }
}

/****************************** TABLERO NORMAL ***********************************/
let tableroVariable=[[0,0,0,0,0,0,0,0,0,0], //1
                     [0,0,0,0,0,0,0,0,0,0], //2
                     [0,0,0,0,0,0,0,0,0,0], //3
                     [0,0,0,0,0,0,0,0,0,0], //4
                     [0,0,0,0,0,0,0,0,0,0], //5
                     [0,0,0,0,0,0,0,0,0,0], //6
                     [0,0,0,0,0,0,0,0,0,0], //7
                     [0,0,0,0,0,0,0,0,0,0], //8
                     [0,0,0,0,0,0,0,0,0,0], //9
                     [0,0,0,0,0,0,0,0,0,0]];//10

                     function elegirBarco() {
                        // Tamaño del barco elegido
                        const barco = document.getElementById("barco").value;
                    
                        // seleccione las celdas
                        let celdasSeleccionadas = [];
                        let numCeldas = parseInt(barco);
                    
                        // ingrese de las celdas
                        for (let i = 0; i < numCeldas; i++) {
                            const celda = prompt(`Ingresa la celda ${i + 1} (por ejemplo, 00, 10, 25, etc.):`);
                            celdasSeleccionadas.push(celda);
                        }
                    
                        // Colocar el barco en las celdas seleccionadas
                        celdasSeleccionadas.forEach(celda => {
                            const celdaElement = document.getElementById(celda);
                            if (celdaElement) {
                                celdaElement.textContent = "B";//nombre celda con barco
                                celdaElement.style.backgroundColor = "#00F"; // color celda
                            } else {
                                alert(`La celda ${celda} no es válida.`);
                            }
                        });
                    }
                    

function main() {
    //TABLERO ENEMIGO
        let celdasF = document.querySelectorAll(".celdaT2");
        // Iteramos sobre las celdas y asignamos el eventListener a cada una
        celdasF.forEach(celdaT2 => celdaT2.addEventListener("click", comprobarCeldaF));

    //TABLERO NORMAL
    celdaElement.classList.add("barco");

}

window.addEventListener("DOMContentLoaded", main);
