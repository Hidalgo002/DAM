/*Dada una secuencia de números enteros acabada en 0, obtener la suma de aquellos números tales
que su número de cifras sea igual a la suma de las mismas. No se pueden utilizar Arrays. Entrada: 1,
5, 111, 66, 201, 273, 0 | Salida: 1 + 111 + 201 = 313*/

import java.util.Scanner;

public class Ejercicio3 {

    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        int numero;
        int total = 0;
        String frase = "";

        System.out.println("Introduce números (termina con 0):");

        do {
            numero = entrada.nextInt();
            if (numero == 0) break;

            int sumaDigitos = 0;
            int contadorDigitos = 0;
            int temp = numero;

            while (temp > 0) {
                sumaDigitos += temp % 10;
                temp /= 10;
                contadorDigitos++;
            }

            if (sumaDigitos == contadorDigitos) {
                total += numero;
                frase += numero + " + ";
            }

        } while (numero != 0);

        if (!frase.isEmpty()) {
            frase = frase.substring(0, frase.length() - 3); // eliminar el último " + "
            System.out.println(frase + " = " + total);
        } else {
            System.out.println("No hay números que cumplan la condición.");
        }
        entrada.close();
    }
}