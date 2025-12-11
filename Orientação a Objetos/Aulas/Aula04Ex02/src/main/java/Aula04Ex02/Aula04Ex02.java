package Aula04Ex02;
import java.util.Scanner;
/**
 *
 * @author ice
 */
public class Aula04Ex02 
{
    public static String ops()
    {
        return
            """
            
            (1) Somar\n 
            (2) Subtrair\n
            (3) Multiplicar\n
            (4) Dividir\n
            (5) Limpar memória\n
            (6) Sair do programa
            """
        ;
    }
    
    public static void main(String[] args) 
    {
        float val=0, v1=0,v2=0,v0=0;
        int op=0;
        Scanner teclado = new Scanner(System.in);
        System.out.println(ops());
        System.out.println("Selecione a operação");
        op=teclado.nextInt();
        
        if(op!=6)
            switch (op)
                {
                    case 1:
                        System.out.println("Insira os valores:");
                        v1=teclado.nextFloat();
                        v2=teclado.nextFloat();
                        val = v1+v2;
                        System.out.println(v1+ " + "+v2+" = "+val);
                        break;

                    case 2:
                        System.out.println("Insira os valores:");
                        v1=teclado.nextFloat();
                        v2=teclado.nextFloat();
                        val = v1-v2;
                        System.out.println(v1+ " - "+v2+" = "+val);
                        break;

                    case 3:
                         System.out.println("Insira os valores:");
                        v1=teclado.nextFloat();
                        v2=teclado.nextFloat();
                        val = v1*v2;
                        System.out.println(v1+ " * "+v2+" = "+val);
                        break;

                    case 4:
                         System.out.println("Insira os valores:");
                        v1=teclado.nextFloat();
                        v2=teclado.nextFloat();
                        val = v1/v2;
                        System.out.println(v1+ " / "+v2+" = "+val);
                        break;

                    case 5:
                        val=0;
                        System.out.println(val);
                        break;
                }
                System.out.println(ops());
                op = teclado.nextInt();
                
                while(op!=6)
                {
                    switch (op)
                    {
                        case 1:
                            System.out.println("Insira o valor:");
                            v1=teclado.nextFloat();
                            v0=val;
                            val += v1;
                            System.out.println(v0+ " + "+v1+" = "+val);
                            break;

                        case 2:
                            System.out.println("Insira o valor:");
                            v1=teclado.nextFloat();
                            v0=val;
                            val -= v1;
                            System.out.println(v0+ " - "+v1+" = "+val);
                            break;

                        case 3:
                            System.out.println("Insira o valor:");
                            v1=teclado.nextFloat();
                            v0=val;
                            val *= v1;
                            System.out.println(v0+ " * "+v1+" = "+val);
                            break;

                        case 4:
                            System.out.println("Insira o valor:");
                            v1=teclado.nextFloat();
                            v0=val;
                            val /= v1;
                            System.out.println(v0+ " / "+v1+" = "+val);
                            break;

                        case 5:
                            val=0;
                            System.out.println(val);
                            break;
                    }
                    System.out.println(ops());
                    op = teclado.nextInt();
                } 
    }
}
