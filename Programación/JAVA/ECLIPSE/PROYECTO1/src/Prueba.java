
public class Prueba {

	public static void main(String[] args) {
		String fragmentoNombreAlumnos = "Victor";
		String[] nombreAlumnos = {"Antonio", "Marta", "Victor Hugo", "David"};
		
		int resultado = contarUsuarios (fragmentoNombreAlumnos, nombreAlumnos);
			System.out.println("Total resultados: " + resultado);
	}
		
		static int contarUsuarios (String fragmentoNombreAlumnos, String[] nombreAlumnos) {
			boolean encontrado = false;
			int totalEncontrados = 0;
			
			for(String nombreAlumnoActual : nombreAlumnos) {
				if(nombreAlumnoActual.contains(fragmentoNombreAlumnos)) {
					encontrado = true;
				}
				if(encontrado) {
					totalEncontrados++; //Lo unico que hace es localizar una posición. Si ponemos victor en lugar de antonio, retorna 4. 
										//Si lo ponemos donde marta, retorna 3, en su posición actual retorna 2 y en el lugar de david retorna 1.
										//Puede que sea como en la recursividad, donde se itineraban las cosas en cascada y luego al revés.
				}
			}
			
		return totalEncontrados;
	}
}
