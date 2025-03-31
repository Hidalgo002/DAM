// EXPRESIONES REGULARES (OBJETO)

function exp1() {
    // Que empiece con A
    let expReg = /^A/;
    let palabra = "hola";

    if (expReg.test(palabra)) {
        document.writeln("<h2>Empieza por A la palabra --> " + palabra + " </h2>");
    } else {
        document.writeln("<h2>No empieza por A la palabra --> " + palabra + " </h2>");
    }
}

function exp2() {
    // Que empiece con A (tanto mayúsculas como minúsculas)
    let expReg = /^[Aa]/;
    let palabra = "arbol";

    if (expReg.test(palabra)) {
        document.writeln("<h2>Empieza por A la palabra --> " + palabra + " </h2>");
    } else {
        document.writeln("<h2>No empieza por A la palabra --> " + palabra + " </h2>");
    }
}

function exp3() {
    // Acaba con o y lo que siga después
    let expReg = /o$/;
    let palabra = "arbol";

    if (expReg.test(palabra)) {
        document.writeln("<h2>Termina con o la palabra --> " + palabra + " </h2>");
    } else {
        document.writeln("<h2>No termina por o la palabra --> " + palabra + " </h2>");
    }
}

function exp4() {
    // La cadena contiene la palabra 'hola' limitada
    let expReg = /\bhola\b/;
    let palabra = "Juana, hola como estás";

    if (expReg.test(palabra)) {
        document.writeln("<h2>True --> " + palabra + " </h2>");
    } else {
        document.writeln("<h2>False --> " + palabra + " </h2>");
    }
}

function exp5() {
    // La cadena contiene la palabra 'hola' pero puede contener más cosas
    let expReg = /\Bhola\B/;
    let palabra = "Juana, hola123 como estás";

    if (expReg.test(palabra)) {
        document.writeln("<h2>True --> " + palabra + " </h2>");
    } else {
        document.writeln("<h2>False --> " + palabra + " </h2>");
    }
}

/*------------------------------------------------------------------- CARACTERES ----------------------------------------------------------------------------*/

function exp6() {
    // Cadena alfabética con mayúsculas y minúsculas
    let expReg = /^[a-zA-Z]+$/;  // Ajustado para solo alfabético, sin espacios
    let palabra = "Juana";

    if (expReg.test(palabra)) {
        document.writeln("<h2>True --> " + palabra + " </h2>");
    } else {
        document.writeln("<h2>False --> " + palabra + " </h2>");
    }
}

function exp7() {
    // Cadena numérica
    let expReg = /^[0-9]+$/;
    let palabra = "123";

    if (expReg.test(palabra)) {
        document.writeln("<h2>True --> " + palabra + " </h2>");
    } else {
        document.writeln("<h2>False --> " + palabra + " </h2>");
    }
}

function exp8() {
    // Cadena numérica con dos valores
    let expReg = /^\b[0-9]{2}\b$/;
    let palabra = "12";

    if (expReg.test(palabra)) {
        document.writeln("<h2>True --> " + palabra + " </h2>");
    } else {
        document.writeln("<h2>False --> " + palabra + " </h2>");
    }
}

function exp9() {
    // Cadena numérica con un rango (2 a 4 dígitos)
    let expReg = /^\b[0-9]{2,4}\b$/;
    let palabra = "123";

    if (expReg.test(palabra)) {
        document.writeln("<h2>True --> " + palabra + " </h2>");
    } else {
        document.writeln("<h2>False --> " + palabra + " </h2>");
    }
}

function exp10() {
    // Cadena numérica con a partir de...2, por ejemplo
    let expReg = /^\b[0-9]{2,}\b$/;
    let palabra = "123";

    if (expReg.test(palabra)) {
        document.writeln("<h2>True --> " + palabra + " </h2>");
    } else {
        document.writeln("<h2>False --> " + palabra + " </h2>");
    }
}

//CARACTERES ESPECIALES
function exp11() {
    // Expresión regular para caracteres especiales (sin letras ni números)
    let expReg = /^[!@#$%^&*()_+={}\[\]:;"'<>,.?/\\|-]*$/;
    let palabra = "@#$%&*()"; // Puedes cambiar esta cadena por otra de tu elección

    if (expReg.test(palabra)) {
        document.writeln("<h2>True --> " + palabra + " </h2>");
    } else {
        document.writeln("<h2>False --> " + palabra + " </h2>");
    }
}

function exp12() {
    // Expresión regular para validar cadenas que contengan letras, números y caracteres especiales
    /*El * es un quantifier (cuantificador) que significa "cero o más veces". 
     Se usa para indicar que el patrón que lo precede puede repetirse cualquier cantidad 
     de veces, incluyendo cero.
     Permite que ningún carácter (una cadena vacía) sea válido.
     Permite que cualquier número de caracteres de los mencionados en el conjunto sea 
     válido (incluyendo más de uno).*/
     
    let expReg = /^[a-zA-Z0-9!@#$%^&*()_+={}\[\]:;"'<>,.?/\\|-]*$/;
    let palabra = "Texto123@#"; // Puedes cambiar esta cadena por otra de tu elección

    if (expReg.test(palabra)) {
        document.writeln("<h2>True --> " + palabra + " </h2>");
    } else {
        document.writeln("<h2>False --> " + palabra + " </h2>");
    }
}


function load() {
    // ASERCIONES
    exp1();
    exp2();
    exp3();
    exp4();
    exp5();
    // CARACTERES
    exp6();
    exp7();
    exp8();
    exp9();
    exp10();
    //CARACTERS ESPECIALES
    exp11();
    exp12();
}
window.addEventListener("DOMContentLoaded", load, false);
