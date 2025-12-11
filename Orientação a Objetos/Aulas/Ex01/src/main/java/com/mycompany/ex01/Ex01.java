
package com.mycompany.ex01;
import java.util.Scanner;
public class Ex01 
{

    public static void main(String[] args) 
    {
       Scanner teclado = new Scanner(System.in);
       int valor=0;
       int resto=0;
       System.out.println("Insira o valor em centavos:");
       valor = teclado.nextInt();
       
       System.out.println("A menor combinação de moedas é: ");
       System.out.println(valor/100 + " moedas de 1 real");
       resto=valor%100;
       System.out.println(resto/50+" moedas de 50 centavos");
       resto%=50;
       System.out.println(resto/25+" moedas de 25 centavos");
       resto%=25;
       System.out.println(resto/10+" moedas de 10 centavos");
       resto%=10;
       System.out.println(resto/5+" moedas de 5 centavos");
    }
}
