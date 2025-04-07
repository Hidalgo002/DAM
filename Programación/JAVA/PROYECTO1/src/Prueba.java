
public class Prueba {

	public static void main(String[] args) {
		String fragmentoNombreAlumnos = "Victor";
		String[] nombreAlumnos = {"Antonio", "Marta", "Hugo Victor", "David"};
		
		int resultado = contarUsuarios (fragmentoNombreAlumnos, nombreAlumnos);
			System.out.println("Total resultados: " + resultado);
	}
		
		static int contarUsuarios (String fragmentoNombreAlumnos, String[] nombreAlumnos) {
			//boolean encontrado = false;
			int totalEncontrados = 0;
			
			for(String nombreAlumnoActual : nombreAlumnos) {//En la variable AlumnoActual que aparece aqui por primera vez se va guardando 
															//el elemento del array de nombreAlumnos y lo recorre automáticamente desde el cero hasta el último.
				if(nombreAlumnoActual.contains(fragmentoNombreAlumnos)) {//.contains comprueba si lo que estamos itinerando y el fragmentoNombre es igual, si lo es, pues como en un if normal,
																		// se levanta la bandera y de suma el totalencontrados
				//	encontrado = true; EN ESTE CASO, NO NECESITAMOS LA BANDERA
				/*}
				if(encontrado) {*///Este if es innecesario, con el primero if confirmamos que hay un victor por lo que es redundante ponder un segundo if con la bandera y el aumento del contador
					totalEncontrados++; //Lo unico que hace es añadir totalEncontrados++ desde que se encuentra Victor, porque cuando se encuentra, siempre se comple la condición de que '(encontrado)'
				
					
				}
			}
			
		return totalEncontrados;
	}
}


