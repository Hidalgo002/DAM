/*Crea un programa en JAVA que lea por teclado una cadena de texto e indique la cantidad de 
palabras que tiene. De la clase String, únicamente se pueden utilizar los métodos charAt(), trim()
y length(). */

import java.util.Scanner;

public class Ejercicio6 {
	public static void main(String[] args) {
		 Scanner entrada = new Scanner(System.in);
		 
		 int contador=0;
		 
		 System.out.println("Introduzca las palabras.");
		 String cadena=entrada.nextLine();
		 cadena=cadena.trim();
		 
		 if(cadena.length() == 0){
			 System.out.println("No hay ninguna palabra");
		 } else {
			 for(int i = 0; i<cadena.length();i++) {
				 
				 if(cadena.charAt(i) == ' '&& cadena.charAt(i+1)!=' '){
					 contador++; 
				 }
				 
			 	}
			 System.out.println("Hay "+(contador+1)+" palabras.");
			 }
		 
		 
		 
		 entrada.close();
	}
}

