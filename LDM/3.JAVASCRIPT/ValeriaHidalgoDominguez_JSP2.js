//EJERCICIO1
function ejercicio1(){
    let palabra = prompt("Introduzca una palabra: ");
    document.writeln("<h3>PALABRA: "+palabra+"</h3>");
    if(palabra.length>10){
        document.writeln("<h4>La palabra: ["+palabra+"] excede el máximo de letras.</h4>");
    }
    else{
        document.writeln("<h4>La palabra: ["+palabra+"] tiene una longitud correcta.</h4>");
    }
    let valido=/^[a-zA-Z]+$/;

    if (valido.test(palabra)) {
       document.writeln("<h4>La palabra: ["+palabra+"] no contiene números.</h4>");
    } else {
        document.writeln("<h4>La palabra: ["+palabra+"] contiene números.</h4>");
    }
}

//EJERCICIO2 
function random(number){
    return Math.floor(Math.random() * (number + 1)); // Genera un número aleatorio entre 0 y el máximo que le pasemos
}

function ejercicio2(){
    let color1 = `rgb(${random(255)}, ${random(255)}, ${random(255)})`;
    document.getElementById("color1").style.backgroundColor = color1;

    let color2 = `rgb(${random(255)}, ${random(255)}, ${random(255)})`;
    document.getElementById("color2").style.backgroundColor = color2;

    let color3 = `rgb(${random(255)}, ${random(255)}, ${random(255)})`;
    document.getElementById("color3").style.backgroundColor = color3;

    let color4 = `rgb(${random(255)}, ${random(255)}, ${random(255)})`;
    document.getElementById("color4").style.backgroundColor = color4;

    if(color2===color3){
        alert("HAN COINCIDIDO.")
    }
    else{
        alert("PRUEBA OTRA VEZ.")
    }
}

//EJERCICIO3


function ejercicio3(){
    let palabras=prompt("Introduzca las tres palabras (SEPARÁNDOLAS CON ESPACIOS Y EN MINÚSCULAS).");


    let contadorA=0;
    let contadorE=0;
    let contadorI=0;
    let contadorO=0;
    let contadorU=0;


    for(let i=0;i<palabras.length;i++){
    if (palabras[i]==='a'){
            contadorA++;
        }
    else if(palabras[i]==='e'){
            contadorE++;}
    else if(palabras[i]==='i'){
            contadorI++;}
    else if(palabras[i]==='o'){
            contadorO++;}
    else if(palabras[i]==='u'){
            contadorU++;}
    }
    let total=contadorA+contadorE+contadorI+contadorO+contadorU;

     document.writeln("<h4>PALABRA 1: </h4>");
        document.writeln("-> A - ["+contadorA+"]");
        document.writeln("-> E - ["+contadorE+"]");
        document.writeln("-> I - ["+contadorI+"]");
        document.writeln("-> O - ["+contadorO+"]");
        document.writeln("-> U - ["+contadorU+"]");
        document.writeln(" <h4> TOTAL DE VOCALES: "+total+"</h4>");
       
}

//EJERCICIO4
function ejercicio4(event){ 
    let contadorF;
    clearInterval(contadorF);

    event.preventDefault(); 

    let tiempo = document.getElementById("tiempo").value;
    let contador = document.getElementById("contador");
 
    contadorF= setInterval(()=>{
        if(tiempo>0){
            contador.textContent=tiempo++;
        } else {
            clearInterval(contadorF);
            contador.textContent="FIN"}},1000);

}



function main(){
    let select=prompt("SELECCIONE UN EJERCICIO (1,2,3)");

    let menu = parseInt(select);

    if(menu===1){ejercicio1();}
    else if(menu===2){ejercicio2();}
    else if(menu===3){ejercicio3();}
    else{alert("NO VÁLIDO.")}

    let botonAtras=document.getElementById("ejercicio4");
    botonAtras.addEventListener("click",ejercicio4);

    ejercicio4();

}

window.addEventListener("DOMContentLoaded", main);

