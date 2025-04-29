/*Crea un programa en JAVA que reciba una palabra por teclado e indique si es un palíndromo. Un
palíndromo es una palabra que se lee igual de derecha a izquierda, que de izquierda a derecha.
Ejemplo: RECONOCER*/

import java.util.Scanner;

public class Ejercicio7 {
    public static void main(String[] args){
        Scanner entrada = new Scanner(System.in);
        
        System.out.println("Introduzca una palabra:");
        String cadena = entrada.nextLine();
        cadena=cadena.trim();
        
        if (isPalin(cadena)) {
            System.out.println("La palabra ["+cadena+"] es palíndroma.");
        } else {
            System.out.println("La palabra ["+cadena+"] no es palíndroma.");
        }
        
        entrada.close();
    }

    private static boolean isPalin(String cadena) {
        int longitud = cadena.length() / 2; //Porque comparamos en espejo las dos partes de la palabra
		  									//RECO N OCER, N es el intermedio y nos da igual, cuando divide entre dos
											//saca un entero por lo que no la tiene en cuenta
        
        for (int i = 0; i < longitud; i++) {
            if (cadena.charAt(i) != cadena.charAt(cadena.length() - i - 1)) {
                return false; //Returns nothing
            }
        }
        return true; //returns cadena
    }
}
