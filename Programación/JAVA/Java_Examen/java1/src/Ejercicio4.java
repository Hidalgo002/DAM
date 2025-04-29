/*Crea un programa que te pida una palabra y escriba las letras separadas por espacios. Ejemplo,
a partir de "Pepe" escribirá "P e p e ".*/

import java.util.Scanner;

public class Ejercicio4 {
	
	public static void main(String[] args) {
		Scanner entrada = new Scanner(System.in);
		
		System.out.println("Introduce una palabra: ");
		
		String palabra = entrada.nextLine();
		
		for(int i = 0; i<palabra.length();i++) {
			
			System.out.print(palabra.charAt(i)+" ");
		}
		
		entrada.close();
	}
}
