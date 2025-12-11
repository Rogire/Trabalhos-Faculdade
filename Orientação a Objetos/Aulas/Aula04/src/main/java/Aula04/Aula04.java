package Aula04;
import java.util.Scanner;
/**
 *
 * @author igor
 */
public class Aula04 
{
    final private static int NUM_ALUNOS=3;
    public static void troca(String [] arr, int i)
    {
        String aux = arr[i-1];
        arr[i-1] = arr[i];
        arr[i]=aux;
    }
    public static String[] Lista(String[] arr, int[] id)
    {
        String[] ordemAl=new String[NUM_ALUNOS];
        String[] Alfabeto = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        int cont=0,contAnt=0;
        for(int i=0;i<NUM_ALUNOS;i++)
        {
            for(int j=0;j<26;j++)
            {
                cont++;
                System.out.print(Alfabeto[j].charAt(0)+" ");
                if(arr[i].charAt(0)==Alfabeto[j].charAt(0))
                {
                   break;
                }
            }
            System.out.println(cont+" "+contAnt);
            if(i==0)
                ordemAl[i]=arr[i];
            else
            {
                if(cont<contAnt)
                {
                    ordemAl[i]=arr[i];
                    troca(ordemAl,i);
                }
                else
                    ordemAl[i]=arr[i];
            }
            contAnt=cont;
            cont=0;
        }
        return ordemAl;
    }
    public static void ler(String[] arr, int[] id,String msg1,String msg2)
    {
        Scanner teclado = new Scanner(System.in);
        System.out.println(msg1);
        
        for(int i=0;i<NUM_ALUNOS;i++)
            arr[i]=teclado.nextLine();
        
        System.out.println(msg2);
        for(int i=0;i<NUM_ALUNOS;i++)
            id[i]=teclado.nextInt(); 
    }
    
    public static void ler(Aluno[] vet,String msg1,String msg2)
    {
        Scanner teclado = new Scanner(System.in);
        System.out.println(msg1);
        
        for(int i=0;i<NUM_ALUNOS;i++)
            vet[i].nome=teclado.nextLine();
        
        System.out.println(msg2);
        for(int i=0;i<NUM_ALUNOS;i++)
            vet[i].idade=teclado.nextInt(); 
    }
    public static String[] Lista(Aluno[] vet)
    {
        String[] ordemAl=new String[NUM_ALUNOS];
        String[] Alfabeto = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        for(int i=0;i<NUM_ALUNOS;i++)
        {
            for(int j=0;j<26;j++)
            {
                vet[i].cont++;
                System.out.print(Alfabeto[j].charAt(0)+" ");
                if(vet[i].nome.charAt(0)==Alfabeto[j].charAt(0))
                {
                   break;
                }
            }
            if(i==0)
                ordemAl[i]=vet[i].nome;
            else
            {
                if(vet[i].cont<vet[i-1].cont)
                {
                    ordemAl[i]=vet[i].nome;
                    troca(ordemAl,i);
                }
                else
                    ordemAl[i]=vet[i].nome;
            }
        }
        return ordemAl;
    }
    public static void imprime(String[] arr, int[] id)
    {
        for(int i=0;i<NUM_ALUNOS;i++)
        {
            System.out.println("Aluno: "+arr[i]+", idade: "+id[i]);
        }
    }
    public static void imprime(String[] arr)
    {
        for(int i=0;i<NUM_ALUNOS;i++)
        {
            System.out.println("Aluno: "+arr[i]);
        }
    }
    public static void main(String[] args) 
    {
        Aluno[] Al = new Aluno[NUM_ALUNOS];
        String[] nomes=new String[NUM_ALUNOS];
        int[] idades = new int[NUM_ALUNOS];
        ler(nomes,idades,"Insira os nomes dos alunos","Insira as idades dos alunos");
        String [] res = Lista(Al);
        imprime(res);
    }
}
