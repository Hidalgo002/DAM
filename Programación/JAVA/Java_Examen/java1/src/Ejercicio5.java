/*Crea un programa en JAVA que reciba 5 palabras y luego nos muestre la que tiene una longitud mayor*/

import java.util.Scanner;

public class Ejercicio5 {
	 public static void main(String[] args) {
		 Scanner entrada = new Scanner(System.in);
		 String palabraMayor="";
		 int lonMayor=0;
		 
		 System.out.println("Introduzca cinco palabras.");
		 for(int i = 0; i<5;i++) {
			 System.out.println("Palabra ["+(i+1)+"]: ");
			 String palabra=entrada.nextLine();
		 
			 if(palabra.length()>lonMayor) {
				 palabraMayor=palabra;
				 lonMayor=palabra.length();
			 }
			 
		 }
		 
		 entrada.close();
		 
		 System.out.println("Palabra de mayor longitud: " + palabraMayor);
		 System.out.println("Tamaño: " + lonMayor);
	 }
}