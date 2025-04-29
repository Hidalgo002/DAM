/*Crear un programa en JAVA que dibuje un rectángulo formado por asteriscos(*). Se deben pedir JAVA
base y altura por teclado. Además, añade código adicional para que dibuje dicho rectángulo sin
relleno*/

import java.util.Scanner;

public class Ejercicio8 {
 
	public static void main(String[] args) {
		Scanner entrada = new Scanner(System.in);
		
		System.out.println("Introduce la base del rectángulo.");
		
		int base = entrada.nextInt();
		
		System.out.println("Introduce la altura del rectángulo.");
		
		int altura = entrada.nextInt();
		
		entrada.close();
		
		System.out.println("Rectángulo relleno: ");
		//RELLENO:
		for(int i= 0; i<altura; i++) { //
			for(int j= 0; j<base;j++) {
					System.out.print("*");
				}
			System.out.println();
		}
		
		System.out.println("Rectángulo con espacio: ");
		//CON ESPACIO
		for(int i= 0; i<altura; i++) { //
			for(int j= 0; j<base;j++) {
				if(i==0|| i==altura-1|| j==0 ||j==base-1) {
					System.out.print("*");
				}
				else{
					System.out.print(" ");
					}
			}
			System.out.println();
		}
	}
}