/*Crea un programa en JAVA que dibuje un triángulo equilátero formado por asteriscos(*). Se debe
pedir la altura del triángulo por teclado. Además, añade código adicional para que dibuje dicho
rectángulo sin relleno */

import java.util.Scanner;

public class Ejercicio10 {

	public static void main(String[] args) {
		
		Scanner entrada = new Scanner(System.in);
		
		System.out.println("Introduce la altura del triángulo.");
		
		int altura = entrada.nextInt();
		
		entrada.close();
		
		//TRIÁNGULO MACIZO
		System.out.println("Triángulo macizo: ");
		
		for(int i=0; i<altura; i++) {
			for(int j = i; j-altura<=0; j++) {
					System.out.print("  ");
			}
			for(int k = 0; k<=i*2; k++) {
				System.out.print("* ");
				}
			System.out.println( );
			}
		}
		
		//TRIÁNGULO VACÍO
		//System.out.println("Triángulo vacío: ");

}