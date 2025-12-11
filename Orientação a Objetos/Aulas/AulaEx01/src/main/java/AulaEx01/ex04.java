package AulaEx01;
import java.util.Scanner;
/**
 *
 * @author ice
 */
public class ex04 
{
    public static void main(String[] args) 
    {
        Scanner teclado = new Scanner(System.in);
        int val,prox;
        
        System.out.print("Insira o tamanho da sequência: ");
        val=teclado.nextInt();
        int seq[] = new int[val];
        seq[0]=1;
        seq[1]=1;        
        for(int i=2;i<val;i++)
        {
            prox = seq[i-2]+seq[i-1];
            seq[i]=prox;
        }
         for(int i=0;i<val;i++)
        {
            System.out.print(seq[i]+" ");
        }
    }
    
}
