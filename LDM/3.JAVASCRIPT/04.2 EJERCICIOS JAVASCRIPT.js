/*1.Introducir una fecha en formato cadena mediante el método prompt() y 
en formato dd,mm, aaaa (por ejemplo, 23,01, 2008) y devolver en un cuadro
de mensaje el número de días que han pasado hasta la fecha actual. 
Si la cadena introducida no se reconoce como fecha devolverá false.*/

function ifFecha(fechaEntrada) {
    // Expresión regular para validar formatos dd-mm-aaaa, dd/mm/aaaa o dd,mm,aaaa
    const regex =/^(0[1-9]|[1-2][0-9]|3[0-1])[\/,-](0[1-9]|1[0-2])[\/,-](\d{4})$/;
    // const regex= /^[0-9]{2}[\/,-][0-9]{2}[\/,-][0-9]{4}$/;
    //const regex= /^[0-9]{2}[\/,-]\d{2}[\/,-]\d{4}$/;
 
    return regex.test(fechaEntrada); // Devuelve true si el formato es correcto, false si no lo es
}

function ej1() {
    let fechaEntrada = prompt("Introduce una fecha en formato dd-mm-aaaa, dd/mm/aaaa o dd,mm,aaaa (por ejemplo, 23-01-2008):");

    if (ifFecha(fechaEntrada)) {
        document.writeln("<h2>Formato correcto --> " + fechaEntrada + " </h2>");
        let FechaPorPartes=fechaEntrada.split("[\/,-]");

        let day = parseInt(FechaPorPartes[0]);
        let month = parseInt(FechaPorPartes[1]);
        let year = parseInt(FechaPorPartes[2]);

        let fechaIntroducida= new Date(day, month, year);

    } else {
        document.writeln("<h2> Formato incorrecto --> " + fechaEntrada + " </h2>");
    }
}



/*2.Introduce mediante un prompt un correo electrónico, si dicho correo electrónico es
válido devolverá el número de letras que tiene el usuario. Si no determinará que es
invalido y determinará dónde está el error si en el usuario o el dominio. valeria@gmail.com*/
function ej2(){
    let correo = prompt("Introduzca un correo electrónico: ");

    let expReg =/^[a-zA-Z0-9._-]+@[a-zA-Z0-9._-]+\.[a-zA-Z]{2,}$/;

    if(expReg.test(correo)) {
        document.writeln("<h2>True --> " + correo + " </h2>");
    } else {
        document.writeln("<h2>False --> " + correo + "<h2>");
    }

}



function load() {
    // ASERCIONES
    ej1();
    ej2();
}
window.addEventListener("DOMContentLoaded", load, false);
