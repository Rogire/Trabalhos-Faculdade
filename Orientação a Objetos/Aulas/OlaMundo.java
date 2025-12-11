import java.util.Scanner;
public class OlaMundo 
{
    public static void main(String[] args) 
    {
        Scanner teclado = new Scanner(System.in);
        int v1=0;
        v1 = teclado.nextInt();
        
        for(int i=1; i<v1;i++)
            System.out.println(i);
    }
}
