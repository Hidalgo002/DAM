import java.util.Scanner;

public class AltaAlumnos {
    
    public static void main(String[] args){
        Scanner entrada = new Scanner(System.in);

        System.out.println("Introduzca el número de alumnos: ");
        int totalAlumnos = entrada.nextInt();
        entrada.nextLine(); // limpiar salto de línea

        String[] nombres = new String[totalAlumnos];
        String[] apellidos = new String[totalAlumnos];
        int[] edades = new int[totalAlumnos];
        double[] notas = new double[totalAlumnos];

        for (int i = 0; i < totalAlumnos; i++) {
            System.out.println("Alumno [" + (i + 1) + "]");

            System.out.print("Nombre: ");
            nombres[i] = entrada.nextLine();

            System.out.print("Apellido: ");
            apellidos[i] = entrada.nextLine();

            System.out.print("Edad: ");
            edades[i] = entrada.nextInt();
            entrada.nextLine(); // limpiar salto

            System.out.print("Nota: ");
            notas[i] = entrada.nextDouble();
            entrada.nextLine(); // limpiar salto
        }

        entrada.close();

        System.out.println("\n--- LISTA DE ALUMNOS ---");
        for (int i = 0; i < totalAlumnos; i++) {
            System.out.println("Alumno[" + (i + 1) + "]; Nombre[" + nombres[i] + "]; Apellido[" + apellidos[i] + "]; Edad[" + edades[i] + "]; Nota[" + notas[i] + "]");
        }
    }
}
