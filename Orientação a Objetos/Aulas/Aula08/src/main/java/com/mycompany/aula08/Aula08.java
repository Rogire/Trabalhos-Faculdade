package com.mycompany.aula08;
import java.util.*;



public class Aula08
{
    static List<Pessoa> pessoas = new ArrayList<>();
    static List<Pessoa> SoJ = new ArrayList<>();
    public static void main(String[] args) 
    {
     
     Comparator c;
     pessoas.add(new Pessoa("Junim",19,5524,"Masculino","casa do juninho")); //p1
     pessoas.add(new Pessoa("Cleber",89,156212,"Masculino","casa 7")); //p2
     pessoas.add(new Pessoa("Joana",29,1895,"Feminino","rua Joaninha"));
     pessoas.add(new Pessoa("Elisnete",20,4972,"Feminino","Avenida 6"));
     pessoas.add(new Pessoa("Pedrinho",12,15841,"Masculino","Rodovia 100000"));
     String [] nomP = new String[pessoas.size()];
     
    imprime(pessoas);     
     
    System.out.print("Primeiro J: ");
    PesquisaJ();
     
    Collections.sort(pessoas, new ComparadorPessoa());
     
    imprime(pessoas);
     
    System.out.println("======================");
        
    Collections.sort(SoJ,new ComparadorPessoa());
    
    adicionaJ();
    imprime(SoJ);
    }
    
    public static void imprime(List <Pessoa> p)
    {
        for(Pessoa pes : p)
        {
            System.out.println(pes.getNome());
        }
    }
    
    public static void PesquisaJ()
    {
     for(Pessoa pes : pessoas)
        {
            if(pes.getNome().charAt(0) == 'J')
            {
                System.out.println(pes.getNome());
                return;
            }
        }   
    }
    public static void adicionaJ()
    {
       for(Pessoa pes : pessoas)
        {
            if(pes.getNome().charAt(0) == 'J')
            {
                SoJ.add(pes);
            }
        } 
    }
}
