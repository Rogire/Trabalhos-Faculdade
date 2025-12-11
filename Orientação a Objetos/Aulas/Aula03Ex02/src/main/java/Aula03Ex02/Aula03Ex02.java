package Aula03Ex02;
import java.util.Scanner;
/**
 *
 * @author igor
 */
public class Aula03Ex02 
{
    public static void main(String[] args) 
    {
        int num,cont=0;
        Scanner teclado = new Scanner(System.in);
        num = teclado.nextInt();
        
        if(num%2==0 && num%5==0)
        {
            while(num%2!=0)
            {
                num %=2;
                cont++;
            }
        }
        else if(num%2 ==0)
        {
           while(num%2!=0)
            {
                num =num%2;
                System.out.println(cont);
                cont++;
            } 
        }
        System.out.println(64%2);
    }
}
