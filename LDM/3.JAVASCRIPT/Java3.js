/*1.Introducir una fecha en formato cadena mediante el método prompt() y 
en formato dd,mm, aaaa (por ejemplo, 23,01, 2008) y devolver en un cuadro
de mensaje el número de días que han pasado hasta la fecha actual. 
Si la cadena introducida no se reconoce como fecha devolverá false.*/

function ifFecha(fechaEntrada) {
    // Expresión regular para validar formatos dd-mm-aaaa, dd/mm/aaaa o dd,mm,aaaa
    const regex = /^(0[1-9]|[1-2][0-9]|3[0-1])[-/,](0[1-9]|1[0-2])[-/,](\d{4})$/;
    return regex.test(fechaEntrada); // Devuelve true si el formato es correcto, false si no lo es
}

function ej1() {
    let fechaEntrada = prompt("Introduce una fecha en formato dd-mm-aaaa, dd/mm/aaaa o dd,mm,aaaa (por ejemplo, 23-01-2008):");

    if (ifFecha(fechaEntrada)) {
        document.writeln("<h2>Formato correcto --> " + fechaEntrada + " </h2>");
        
        // Separar la fecha con cualquier delimitador: -, /, ,
        let FechaPorPartes = fechaEntrada.split(/[-\/,]/);


        let day = parseInt(FechaPorPartes[0]);
        let month = parseInt(FechaPorPartes[1]);
        let year = parseInt(FechaPorPartes[2]);

        // Crear objeto Date en JavaScript (el mes va de 0 a 11, por eso se resta 1)
        let fechaIntroducida = new Date(year, month - 1, day);
        
        // Obtener la fecha actual
        let fechaActual = new Date();

        // Calcular la diferencia en milisegundos
        let diferenciaTiempo = fechaActual - fechaIntroducida;

        // Convertir la diferencia a días
        let diasPasados = Math.floor(diferenciaTiempo / (1000 * 60 * 60 * 24));

        document.writeln("<h2>Días transcurridos hasta hoy: " + diasPasados + " días</h2>");

    } else {
        document.writeln("<h2>Formato incorrecto --> " + fechaEntrada + " </h2>");
    }
}




/*2.Introduce mediante un prompt un correo electrónico, si dicho correo electrónico es
válido devolverá el número de letras que tiene el usuario. Si no determinará que es
invalido y determinará dónde está el error si en el usuario o el dominio. valeria@gmail.com*/
function ej2() {
    let correo = prompt("Introduzca un correo electrónico:");

    // Expresión regular básica para validar formato de email
    let expReg = /^[a-zA-Z0-9._]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;

    if (expReg.test(correo)) {
        document.writeln("<h2>True --> " + correo + " </h2>");
    } else {
        // Dividimos el correo en dos partes: usuario y dominio
        let partesCorreo = correo.split("@");

        if (partesCorreo.length !== 2) {
            alert("El correo no tiene el formato correcto con un solo '@'");
            return;
        }

        let usuario = partesCorreo[0];
        let dominio = partesCorreo[1];

        if (!isUserCorrect(usuario) && !isDomainCorrect(dominio)) {
            alert("Tanto el usuario como el dominio no cumplen los caracteres alfanuméricos requeridos");
        } else if (!isUserCorrect(usuario)) {
            alert("El usuario es incorrecto, no tiene letras y números: " + usuario);
        } else if (!isDomainCorrect(dominio)) {
            alert("El dominio es incorrecto: " + dominio);
        } else {
            alert("Formato inválido, pero no se pudo determinar si fue por usuario o dominio.");
        }
    }
}

function isUserCorrect(user) {
    // Solo letras, números, puntos o guiones bajos
    return /^[a-zA-Z0-9._]+$/.test(user);
}

function isDomainCorrect(domain) {
    // Dominio debe tener letras, números, puntos o guiones
    return /^[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/.test(domain);
}



/*3. Introduce mediante el método prompt un teléfono de la siguiente forma 91-234-12-23-23 y 
determinará si el teléfono es válido, si el teléfono es válido se mostrará de dónde viene la llamada 
según el prefijo. Si es inválido contará los caracteres y determinará si tiene más o menos de lo que debería tener. */
function ej3(){
    let telefono  = prompt("Introduzca un número telefónico: ");

    let expReg =/^[0-9]{2}-[0-9]{3}-[0-9]{2}-[0-9]{2}-[0-9]{2}$/;

    if(expReg.test(telefono)) {
        document.writeln("<h2>True --> " + telefono + " </h2>");
        let TelPorPartes = telefono.split(/[-]/);
        let prefijo = parseInt(TelPorPartes[0]);

        if(prefijo==34){
            document.writeln("<h2>El teléfono-> " + telefono + " llama desde: ESPAÑA.<h2>");
        } else if(prefijo==49){
            document.writeln("<h2>El teléfono-> " + telefono + " llama desde: ALEMANIA.<h2>");
        } else if(prefijo==33){
            document.writeln("<h2>El teléfono-> " + telefono + " llama desde: FRANCIA.<h2>");
        } else if(prefijo==44){
            document.writeln("<h2>El teléfono-> " + telefono + " llama desde: REINO UNIDO.<h2>");
        } else if(prefijo==39){
            document.writeln("<h2>El teléfono-> " + telefono + " llama desde: ITALIA.<h2>");
        } else if(prefijo==31){
            document.writeln("<h2>El teléfono-> " + telefono + " llama desde: PAÍSES BAJOS.<h2>");
        } else if(prefijo==32){
            document.writeln("<h2>El teléfono-> " + telefono + " llama desde: BÉLGICA.<h2>");
        } else {
            document.writeln("<h2>El teléfono-> " + telefono + " tiene un prefijo desconocido.<h2>");
        } 

    } else {
        document.writeln("<h2>False --> " + telefono + "<h2>");
    }
}

/*4. Un programador ha publicado un desafío, que consiste en encontrar el número de veces que se encuentra 
una palabra en una frase, se tiene la siguiente oración de ejemplo: 
‘Este es un ejemplo de texto con ejemplo de palabra repetida‘ la palabra a buscar es “ejemplo". 
Crea un script que permita resolver este desafío.*/

function ej4(){
    let fraseEJ4= "Este es un ejemplo de texto con ejemplo de palabra repetida";
    let palabraEJ4 = "ejemplo";
    let contadorEJ4 = 0;

    if (fraseEJ4.includes(palabraEJ4)) {
        contadorEJ4++;
        document.writeln("La palabra 'ejemplo' se encuentra en la frase " +contadorEJ4+ " veces.");
    } else {
         document.writeln("La palabra no está en la frase.");
    }
}

/*5. En un hackaton se ha publicado un reto, el cual consiste en buscar un conjunto de caracteres dentro de una 
oración y reemplazarlo por otro patrón. La frase de ejemplo es: “Lorem ipsum dolor sit amet, consectetur 
adipiscing elit“, la palabra que se debe de buscar es: “/ipsum/” y por la que se debe de reemplazar es: “dolor“.
Crea un script que permita resolver este reto. */
function ej5() {
    let frase = "Lorem ipsum dolor sit amet, consectetur adipiscing elit";
    let palabraBuscar = "ipsum";  // Palabra a buscar
    let palabraReemplazar = "dolor";  // Palabra por la que reemplazamos

    // Usamos el método replace para reemplazar la palabra
    let nuevaFrase = frase.replace(palabraBuscar, palabraReemplazar);

    // Muestra la frase resultante
    document.writeln("<h2>Frase original: </h2>" + frase);
    document.writeln("<h2>Frase modificada: </h2>" + nuevaFrase);
}


/*6. La empresa developer S.A. de C.V. requiere que se pueda validar si una contraseña
dada contiene un letra mayúscula, tiene un número y una letra minúscula. Crea un
script donde se utilice una expresión regular para solventar este requerimiento. */
function ej6() {
    let contraseña = prompt("Introduce una contraseña para validar:");

    // Expresión regular para validar la contraseña
    let expReg = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d).+$/;

    // Verificamos si la contraseña cumple con el patrón
    if (expReg.test(contraseña)) {
        document.writeln("<h2>Contraseña válida: " + contraseña + "</h2>");
    } else {
        document.writeln("<h2>Contraseña inválida. La contraseña debe contener al menos una letra mayúscula, una letra minúscula y un número.</h2>");
    }
}
 

function load() {
    // ASERCIONES
    ej1();
    ej2();
    ej3();
    ej4();
    ej5();
    ej6();
}
window.addEventListener("DOMContentLoaded", load, false);

