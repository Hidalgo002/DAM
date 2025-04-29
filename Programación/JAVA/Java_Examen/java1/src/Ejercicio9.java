/*Crea un programa en JAVA que dibuje un triángulo rectángulo formado por asteriscos(*). Se debe
pedir la altura del triángulo por teclado. Además, añade código adicional para que dibuje dicho
triángulo sin relleno*/

import java.util.Scanner;

public class Ejercicio9 {
		public static void main(String[] args) {
			
			Scanner entrada = new Scanner(System.in);
			
			System.out.println("Introduce la altura del rectángulo.");
			
			int altura = entrada.nextInt();

			entrada.close();
			
			//TRIÁNGULO MACIZO
			System.out.println("Triángulo macizo: ");
			for(int i=0; i<=altura; i++) {
				for(int j=0; j<i; j++) {
						System.out.print("*");
				}
				System.out.println( );
			}
			
			//TRIÁNGULO VACÍO
			System.out.println("Triángulo vacío: ");
			for(int i=1; i<=altura; i++) {
				for(int j=0; j<i; j++) {
					if(i==altura|| j==0 ||j==i-1) {
						System.out.print("*");
					}
					else{
						System.out.print(" ");
						}
				}
				System.out.println( );
			}
				
				
		}
}
	