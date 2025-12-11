package Aula01;
import java.util.Scanner;

public class Aula01 
{
    public static void main(String[] args) 
    {
       Scanner teclado = new Scanner(System.in);
       int valor=0;
       System.out.println("Insira o valor em centavos:");
       valor = teclado.nextInt();
       calcula(valor);
    }
    
    public static void calcula(int valor)
    {
        int MOEDAS[]={100,50,25,10,5};
        int restoAt=0, totAt;
        System.out.println("Menor divisão de moedas: ");
        
        for(int i=0; i<5;i++)
        {
            System.out.println("resto: "+restoAt + " dividindo por: "+MOEDAS[i]);
            if(i==0)
            {
                totAt=valor/MOEDAS[i];
                if(totAt>1)
                    System.out.println(totAt+" moedas de 1 real\n");
                else
                    System.out.println(totAt+" moeda de 1 real\n");
            }
            else
            {
                totAt=restoAt/MOEDAS[i];
                if(totAt>=1)
                    System.out.println(totAt+" moedas de "+MOEDAS[i]+" real\n");
                else if(totAt<=0)
                    System.out.println(totAt+" moeda de "+MOEDAS[i]+" real\n");
            }
            
            restoAt = valor%MOEDAS[i];
            
        }
    }
}
