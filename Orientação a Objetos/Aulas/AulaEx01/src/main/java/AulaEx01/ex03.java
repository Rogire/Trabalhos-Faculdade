package AulaEx01;
import java.util.Scanner;
/*
 *
 * @author ice
 */
public class ex03 
{
    //B
    final static private int NUM_AULAS=15;
    final static private int NUM_ATV=12;
    public static void finalDeSemestre(Aluno a)
    {
        if(a.numFaltas>NUM_AULAS)
            System.out.println("Aluno reprovado");
        else if(a.numTaf<NUM_ATV)
            System.out.println("Aluno reprovado");
        else if(a.notaFinal<60)
            System.out.println("Aluno tem direito de fazer a prova substitutiva");
        else
            System.out.println("Aluno aprovado");
    }
    
    public static void main(String[] args) 
    {
        //Scanner teclado = new Scanner(System.in);
//==================================EX03-A===========================================    
        /*
        Aluno Al= new Aluno();
        System.out.println("Insira a nota final");
        Al.setNotaFinal(teclado.nextFloat());
        System.out.println("Insira o número de faltas");
        Al.setNumFaltas(teclado.nextInt());
        System.out.println("Insira o número de tarefas feitas");
        Al.setNumTaf(teclado.nextInt());
        finalDeSemestre(Al);
        */
//==================================EX03-B=========================================== 
    /*
        Aluno[] Alunos=new Aluno[3];
    for(int i=0;i<3;i++)
        Alunos[i]=new Aluno();
    
    for(int i=0;i<3;i++)
    {
        System.out.println("Insira a nota final do aluno "+(i+1));
            Alunos[i].setNotaFinal(teclado.nextFloat());
        System.out.println("Insira o número de faltas do aluno "+(i+1));
            Alunos[i].setNumFaltas(teclado.nextInt());
        System.out.println("Insira o número de tarefas feitas do aluno "+(i+1));
            Alunos[i].setNumTaf(teclado.nextInt());
    }
    for(int i=0;i<3;i++)
    { 
       System.out.println("Aluno"+(i+1)+":");
       finalDeSemestre(Alunos[i]);
    }   
    */
}
}
