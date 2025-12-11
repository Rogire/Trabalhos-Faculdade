package Aula04Ex01;
import java.util.Scanner;
/**
 *
 * @author ice
 */
public class Aula04Ex01 
{
    final private static int NUM_ALUNOS=3;
    public static void ler(Aluno[] Al, String msg1,String msg2)
    {
        Scanner teclado = new Scanner(System.in);
        System.out.println(msg1);
        for(int i=0;i<NUM_ALUNOS;i++)
        {
            Al[i] = new Aluno();
            Al[i].setNome(teclado.nextLine().toUpperCase());
        }
        System.out.println(msg2);
        for(int i=0;i<NUM_ALUNOS;i++)
        {
            Al[i].setIdade(teclado.nextInt());
        }            
    }
    public static void imprime(Aluno[] Al)
    {
        for(int i=0;i<NUM_ALUNOS;i++)
        {
            System.out.println("Aluno: "+Al[i].getNome()+", idade:"+Al[i].getIdade());
        }
    }
    public static void troca(Aluno[] ord,int i, int k)
    {
        Aluno tmp = ord[i];
        ord[i]=ord[k];
        ord[k]=tmp;
    } 
    public static Aluno[] ordenaAlf(Aluno[] Al)
    {
        String[] alfabeto = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        Aluno[] ordemAlf = new Aluno[NUM_ALUNOS];
        for(int i=0; i<NUM_ALUNOS;i++)
        {
           ordemAlf[i]=new Aluno();
           for(int j=0;j<26;j++)
           {
               Al[i].setCont(Al[i].getCont() + 1);
               if(Al[i].getNome().charAt(0) == alfabeto[j].charAt(0)) //Comparação para saber a posição da primeira
               {                                                                //letra do nome do aluno[i] no alfabeto
                   break;
               }   
           }
           if(i==0)
               ordemAlf[i]=Al[i];
           else
           {
               ordemAlf[i]=Al[i];
               for(int k=0;k<i;k++)
               {
                   System.out.println(ordemAlf[i].getCont()+" "+ordemAlf[k].getCont());
                   if(ordemAlf[k].getCont()>ordemAlf[i].getCont()) // comparação contínua do primeiro para o último da lista
                       troca(ordemAlf,i,k);                    // para saber se a primeira letra do ordemAlf[k] é maior
               }                                                  // que a primeira letra do ordemAlf[i], se sim é feita a troca.
           }
        }
        return ordemAlf;
    }
    
    public static void ordenaId(Aluno[]Al)
    {
        for(int i=0;i<NUM_ALUNOS-1;i++)
        {
            if(Al[i].getIdade() > Al[i+1].getIdade())
                troca(Al,i,(i+1));
        }
    }
    public static void main(String[] args) 
    {
        Aluno[] Alunos= new Aluno[NUM_ALUNOS];
        ler(Alunos,"Insira os nomes dos alunos","Insira a idade dos alunos");
        Alunos = ordenaAlf(Alunos);
        ordenaId(Alunos);
        imprime(Alunos);
    }
}
