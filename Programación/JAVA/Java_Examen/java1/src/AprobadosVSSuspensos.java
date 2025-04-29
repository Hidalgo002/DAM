import java.util.Scanner;

public class AprobadosVSSuspensos{
public static void main(String[] args){
    int n;
    int s=0;
    boolean suspensos;
    suspensos = false;

    Scanner entrada = new Scanner (System.in);
 
  for (int i=0;i<5;i++){
     System.out.print("Introduzca nota (de 0 a 10): ");
      n=entrada.nextInt();
     
      if(n<5){
      suspensos = true;
      s++;
      }
     }

     if(suspensos==true){
      System.out.println("Hay " +s + " alumnos suspensos.");
     }
     else{
      System.out.println("No hay suspensos");
     }
 }
}