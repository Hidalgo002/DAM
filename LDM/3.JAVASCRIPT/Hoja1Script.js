/*
        function Ejercicio1(){
        // 1. Escribe un programa de una sola línea que haga que aparezca   en la pantalla un alert que diga “Hello World”.    
        alert("Hello World");
       }

       function Ejercicio2(){
        // 2. Escribe un programa de una sola línea que escriba en la pantalla un texto que diga “Hello World” (document.write).
        document.writeln("<h1>Hello World</h1>");
       }

       function Ejercicio3(){
        //3. Escribe un programa de una sola línea que escriba en la pantalla el resultado de sumar 3 + 5.
        //console.log muestra el resultado en la consola que se encuentra en el apartado de desarrolladores al inspeccionar la página
        let a=3;
        let b=5;
        let suma=a+b;
        console.log("Resultado de 3 + 5: " + suma);
       }
       
       function Ejercicio4(){
        //4. Escribe un programa de dos líneas que pida el nombre del usuario con un prompt y escriba un texto que diga “Hola nombreUsuario”
        let nombre= prompt("¿Cómo te llamas?", "Valeria");
        document.writeln("Bienvenid@ " +nombre);
       }

       function Ejercicio5(){
        //5. Escribe un programa de tres líneas que pida un número, pida otro número y escriba el resultado de sumar estos dos números.
        let a1=prompt("Escribe el número1: ");
        let b1=prompt("Escribe el número2: ");
        let resultado1=parseInt(a1)+parseInt(b1);
        document.writeln("<p>Resultado: " + a1 + " + " + b1 + " = " + resultado1 + "</p>");
       }

       function Ejercicio6(){
        //6. Escribe un programa que pida dos números y escriba en la pantalla cual es el mayor.
        alert("Ejercicio6");
        let num1=parseInt(prompt("Escribe el número1: "));
        let num2=parseInt(prompt("Escribe el número2: "));

        if(num1>num2){
           document.writeln("<p> El número mayor es: " +  num1 + "</p>");
        }
        else if(num2>num1){
            document.writeln("<p> El número mayor es: " +  num2 + "</p>");
        }
        else{
            document.writeln("<p>Los dos numeros son iguales</p>");
        }
       }

       function Ejercicio7(){
        //7. Escribe un programa que pida 3 números y escriba en la pantalla el mayor de los tres.
        let n1=prompt("Escribe el número1: ");
        let n2=prompt("Escribe el número2: ");
        let n3=prompt("Escribe el número3: ");
            // Convertir los valores a enteros
            n1 = parseInt(n1);
            n2 = parseInt(n2);
            n3 = parseInt(n3);

        if(n1>=n2 && n1>=n3){
            document.writeln("<p> El número mayor es: " +  n1 + "</p>");
        }
        else if(n2>=n1 && n2>=n3){
            document.writeln("<p> El número mayor es: " +  n2 + "</p>");
        }
        else {document.writeln("<p> El número mayor es: " +  n3 + "</p>");
        }
       }

       function Ejercicio8(){
        //8. Escribe un programa que pida un número y diga si es divisible por 2
        let nuem1=prompt("Escribe un número: ");
        nuem1=parseInt(nuem1);
        if(nuem1%2 == 0){
         document.writeln("<p>Es un número par</p>");
        }
        else{document.writeln("<p>Es un número impar</p>");
        }
       }

       function Ejercicio9() {
        // 9. Escribe un programa que pida una frase y escriba cuántas veces aparece la letra 'a'
        let frase = prompt("Ej9: Escribe una frase: ");
        let contador = 0;
    
        for (let i = 0; i < frase.length; i++) {
            // Comprobar si el carácter es la letra 'a'
            if (frase[i].toLowerCase() === 'a') {
                contador++;  // Incrementar el contador
            }
        }
    
        console.log("Hay " + contador + " letras 'a'");
        }
       


       function Ejercicio10(){
       //10.Escribe un programa que pida una frase y escriba las vocales que aparecen.
       let frase2 = prompt("Ej10: Escribe una frase: ");
       let vocales="aeiouAEIOU";
       let vocalesEncontradas="";

       for(let char of frase2){
        if(vocales.includes(char)){
            if(!vocalesEncontradas.includes(char)){
            vocalesEncontradas=vocalesEncontradas+char
            }
        }//El primer if coje todas las vocales, el segundo if las añade si es que no han aparecido antes, es decir, con el primer bucle se imprime 'aaeeiouuu', el segundo se encarga de poner solo 'aeiou'

       }
       document.writeln(vocalesEncontradas);
       }
       
             
        function Ejercicio11() {
            // Pedir una frase al usuario
            let frase3 = prompt("Ej11: Escribe una frase: ");
            let vocales2 = "aeiouAEIOU";
            let vocalesEncontradas2 = "";
            let contadora = 0;
        
            // Recorrer cada carácter de la frase
            for (let char of frase3) {
                if (vocales2.includes(char)) {
                    if (!vocalesEncontradas2.includes(char)) {
                        vocalesEncontradas2 += char; // Agregar vocal única
                    }
                    contadora++; // Contar cada vocal encontrada
                }
            }
        
            // Mostrar el resultado
            document.writeln("Vocales encontradas: " + contadora);
        }
       

       function Ejercicio12(){
        //12.Escribe un programa que pida una frase y escriba cuántas veces aparecen cada una de las vocales
        let frase4 = prompt("Ej11: Escribe una frase: ");
            let vocales4 = "aeiouAEIOU";
            let vocalesEncontradas4 = {a:0,e:0,i:0,o:0,u:0};//inicializamos las vocales a cero
        
            // Recorrer cada carácter de la frase
            for (let char of frase4) {
                if (vocales4.includes(char.toLocaleLowerCase())) {
                   vocalesEncontradas4[char.toLocaleLowerCase()]++;

                }
            }
        
            // Mostrar el resultado
            document.writeln("Vocales encontradas: " + JSON.stringify(vocalesEncontradas4));
        }
*/
        function Ejercicio14(){
        //14.Añadir al ejercicio anterior que nos diga por cuál de los cuatro es divisible (hay que decir todos por los que es divisible)
        let num14=parseInt(prompt("Introduce un número"));
        let divisibles14 = [];

        if(num14 % 2 === 0) divisibles14.push("2");
        if(num14 % 3 === 0) divisibles14.push("3");
        if(num14 % 5 === 0) divisibles14.push("5");
        if(num14 % 7 === 0) divisibles14.push("7");//Push es un array dinámico, es decir añadirmos forzosamente

        if(divisibles14.length>0){
            document.writeln(divisibles14.join(", "));
        }else{
            document.writeln("No es divisible");
        }
        }


       
       /*function Ejercicio14(){}
       function Ejercicio15(){}
       function Ejercicio16(){}
       function Ejercicio17(){}*/
       //Esta función esta comprendida dentro den evento y dentro de la hoja de html. Es una función que llama a todas las funciones
       function carga(){
          /*  Ejercicio1();//Llamamos a la función
            Ejercicio2();
            Ejercicio3();
            Ejercicio4();
            Ejercicio5();
            Ejercicio6();
            Ejercicio7();
            Ejercicio8();
            Ejercicio9();
            Ejercicio10();
            Ejercicio11();
            Ejercicio12();*/
            Ejercicio14();
            /*Ejercicio15();
            Ejercicio16();
            Ejercicio17();*/

       }
       //Evento-> Cuando la ventana de navegador existe, se dispada el evento DOMContentLoaded que se enlaza con la función cualesquiera que pongamas, en este caso se llama 'carga' como si se llama queso:
       window.addEventListener("DOMContentLoaded",carga, false);
       
