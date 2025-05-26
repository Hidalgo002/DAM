import java.util.ArrayList;
import java.util.Scanner;


public class Main {

	public static void main (String[] args) {
		Scanner entrada = new Scanner(System.in);
		menu(entrada);
		entrada.close();
	}
	
	public static void menu(Scanner entrada) {
		
		System.out.println("=================ORDEN DEL DÍA=================");
		System.out.println("1- SE DARÁN DE ALTA A LOS OBJETOS.");
		System.out.println("2-CÁLCULO DE CUÁNTOS VEHÍCULOS HAY EN TOTAL.");
		System.out.println("3-CÁLCULO DE CUÁNTOS VEHÍCULOS SON ELÉCTRICOS.");
		System.out.println("4-CÁLCULO DE CUÁNTOS VEHÍCULOS SON DE COMBATE.");
		System.out.println("5-CÁLCULO DE LA MÉDIA DE KILÓMETROS DE TODOS LOS VEHÍCULOS.");
		darDeAlta(entrada);
		
		System.out.println("=================FIN DEL PROGRAMA=================");


	}


	public static void darDeAlta(Scanner entrada) {
		ArrayList<Coche> coches = new ArrayList<>();
		ArrayList<Barco> barcos = new ArrayList<>();
		ArrayList<Avion> aviones = new ArrayList<>();
		
		for(int i=0; i<2;i++) {
		System.out.println("\n1- Introduzca los datos del coche["+(i+1)+"]");
		System.out.print("     Marca: ");
		String marcaL = entrada.next();
		
		System.out.print("     Color: ");
		String colorL = entrada.next();
		
		System.out.print("     Número de Bastidor: ");
		String numBastidorL = entrada.next();
		
		System.out.print("     Kilómetros: ");
		int kmL = entrada.nextInt();
		
		System.out.print("     Año de Fabricación: ");
		int anFab = entrada.nextInt();
		
		System.out.print("     ¿Es el coche eléctrico? (SÍ -> true, NO->false): ");
		boolean elec = entrada.nextBoolean();
		
		System.out.print("     ¿Es el coche antiguo? (SÍ -> true, NO->false): ");
		boolean ant = entrada.nextBoolean();
		
		
        coches.add(new Coche(marcaL, colorL, numBastidorL, kmL,anFab,elec,ant));
        
        System.out.println("Coche agregado correctamente.");
		
	}
		barcos.add(new Barco("Toyota","Amarillo","548KA",52000,2020,30,10,clase.VELA));
		barcos.add(new Barco("Fiat","Rojo","592GH",85000,2015,20,10,clase.PESCA));
		aviones.add(new Avion("Airbus","Blanco","ASDF85",250000,2019,(byte) 2,1000,false));
		aviones.add(new Avion("Hércules","Verde","POQ958",152846,2002,(byte) 4,2500,true));
		
		System.out.print("\n¿Desea ver todos los vehículos? 1-SI, 2-NO --> ");
		int op = entrada.nextInt();
		
		if(op==1) {
		System.out.println("===COCHES===");
		for(Coche coche : coches) {
	        System.out.println(coche);
			}
		
		System.out.println("===BARCOS===");
		for(Barco barco : barcos) {
        System.out.println(barco);
		}

		System.out.println("===AVIONES===");
		for(Avion avion : aviones) {
	        System.out.println(avion);
			}
		} else {System.out.println("No se mostrarán los datos");};
		
		
		System.out.println("\n¿Desea ver cuántos vehículos hay en total? 1-SI, 2-NO -->");
			int op1 = entrada.nextInt();
		
			if(op1==1) {
			System.out.println("     TOTAL VEHÍCULOS: hay 6 vehículos registrados.");
			} else {System.out.println("     No se mostrarán los datos");};
			
			
		System.out.println("\n¿Desea ver cuántos vehículos son eléctricos? 1-SI, 2-NO -->");
			int op2 = entrada.nextInt();
			
			if(op2==1) {
				for(Coche coche : coches) {
					int contador =0;
				
					boolean electricoEs = coche.isElectrico();
					if(electricoEs==true) {
						System.out.println("Este coche es eléctrico: "+(coche));
						contador++;
						System.out.println("Hay "+contador+" coches eléctricos.");
					}else {System.out.println("     No se mostrarán los datos");};
				}
		
			
		System.out.print("\n¿Desea ver cuántos vehículos son de combate? 1-SI, 2-NO -->");
			int op3 = entrada.nextInt();
			
			if(op3==1) {
				for(Avion avion : aviones) {
					boolean combateES = avion.isCombate();
					if(combateES==true)System.out.println("Este avión es de combate: "+(avion));
					else {System.out.println("Este avión no es de combate");
				}
				}
			
		System.out.print("\n¿Desea saber la media de kilometros realizados entre e todos los vehículos del sistema? 1-SI, 2-NO  -->");
			int op4 = entrada.nextInt();
			
			if(op4==1) {
				
			System.out.println("     MEDIA: ");
			} else {System.out.println("     No se mostrarán los datos");};
}
	
			}}}


	
	
