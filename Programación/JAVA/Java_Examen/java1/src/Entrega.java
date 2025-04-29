package practica;

import java.util.Scanner;

public class Entrega {
		
		public static void main(String[] args) { //Función de scanner de entrada
			Scanner entrada = new Scanner(System.in);
			MENU(entrada);
			entrada.close();
		}
		
		
		public static void MENU(Scanner entrada2) {
			int bandera=0;
			
			do {
					System.out.println("MENÚ.");
					System.out.println("Seleccione un tipo de figura (1- Rectángulo; 2-Triángulo Rectángulo; 3-Triángulo Equilatero; 4-Salir del programa.)");
					boolean comprobacion=entrada2.hasNextInt();
					if(comprobacion==true) {
						int opcion = entrada2.nextInt(); 
						entrada2.nextLine();
						if(opcion==1) {
							System.out.println("RECTÁNGULO.");
							int opcion2=rellOVacio(entrada2);
							if(opcion2==1) {
								System.out.println("RELLENO.");
								rectRelleno(entrada2);
							}
							else if (opcion2==2) {
								System.out.println("VACÍO.");
								rectVacio(entrada2);
							}
						}
						
						else if(opcion==2) {
							System.out.println("TRIÁNGULO RECTÁNGULO.");
							int opcion2=rellOVacio(entrada2);
							if(opcion2==1) {
								System.out.println("RELLENO.");
								trianguloRecRelleno(entrada2);
							}
							else if (opcion2==2) {
								System.out.println("VACÍO.");
								trianguloRecVacio(entrada2);
							}
						}
						
						else if(opcion==3) {
							System.out.println("TRIÁNGULO EQUILÁTERO.");
							int opcion2=rellOVacio(entrada2);
							if(opcion2==1) {
								System.out.println("RELLENO.");
								trianguloEqRelleno(entrada2);
							}
							/*else if (opcion2==2) {
								System.out.println("VACÍO.");
								trianguloEqVacio(entrada2);
							}*/
						}
						else if(opcion==4){
							System.out.println("Saliendo del programa.");
							bandera=1;
						}
					}else {System.out.println("No es un número");
					entrada2.nextLine();}
				}while(bandera!=1);		
		}
		
		public static int  rellOVacio(Scanner entrada2) {
			System.out.println("Seleccione si la figura aparecerá rellena (1) o vacía (2): ");
			int opcion2 = entrada2.nextInt();
			return opcion2; 
		}
		
		public static int base(Scanner entrada2) {
			System.out.println("Introduce la base de la figura.");
			int base = entrada2.nextInt(); 
			return base;
		}
		
		public static int altura(Scanner entrada2) {
			System.out.println("Introduce la altura de la figura.");
			int altura = entrada2.nextInt();
			return altura;
		}

		
		//RECTÁNGULO
				public static void rectRelleno(Scanner entrada2) {
					int baseL=base(entrada2);
					int alturaL=altura(entrada2);
					
						for(int i= 0; i<alturaL; i++) {
							for(int j= 0; j<baseL;j++) {
									System.out.print("*");
								}
							System.out.println();
						}
				}
					
				public static void rectVacio(Scanner entrada2) {	
					int baseL=base(entrada2);
					int alturaL=altura(entrada2);
		
						for(int i= 0; i<alturaL; i++) {
							for(int j= 0; j<baseL;j++) {
								if(i==0|| i==alturaL-1|| j==0 ||j==baseL-1) {
									System.out.print("*");
								}
								else{
									System.out.print(" ");
									}
								}
								System.out.println();
								}	
				}
				
				
		//TRIÁNGULO RECTÁNGULO
				public static void trianguloRecRelleno (Scanner entrada2) {
					int alturaL=altura(entrada2);
					
					for(int i=0; i<=alturaL; i++) {
						for(int j=0; j<i; j++) {
								System.out.print("*");
						}
						System.out.println( );
					}
				}
				
				public static void trianguloRecVacio (Scanner entrada2) {
					int alturaL=altura(entrada2);
					
					for(int i=1; i<=alturaL; i++) {
						for(int j=0; j<i; j++) {
							if(i==alturaL|| j==0 ||j==i-1) {
								System.out.print("*");
							}
							else{
								System.out.print(" ");
								}
						}
						System.out.println( );
					}
				}
				
				
		//TRIÁNGULO EQUILÁTERO
				
				public static void trianguloEqRelleno (Scanner entrada2) {
					int alturaL=altura(entrada2);
					
					for(int i=0; i<alturaL; i++) {
						for(int j = i; j-alturaL<=0; j++) {
								System.out.print("  ");
						}
						for(int k = 0; k<=i*2; k++) {
							System.out.print("* ");
							}
						System.out.println( );
						}
				}
				
				/*public static void trianguloEqVacio (Scanner entrada2) {
					int alturaL=altura(entrada2);
				}*/
		
				
	}


