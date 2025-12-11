package com.mycompany.agendas;
import java.util.Scanner;
public class Agenda {
    private int dia;
    private int mes;
    private int ano;
    private int anoAt;
    private final int [] tem31={0,2,4,6,7,9,11};
    Scanner teclado =  new Scanner(System.in);
    String[] anot = new String[365];
    
    public Agenda()
    {
       this.dia =0;
       this.mes=0;
       this.ano=0;
       this.anoAt=2024;
    }
    
    public void fazerAnotacao(int d, int an,int mes, String anotacao)
    {
        while(!validar(d,an,mes,anotacao))
        {
            System.out.println("Insira os dados novamente:");
            System.out.println("dia:");
            d = teclado.nextInt();
            System.out.println("mes:");
            mes = teclado.nextInt();
            System.out.println("Anotação:");
            anotacao = teclado.next();
        }
        
        if(validar(d,an,mes,anotacao))
        {
            System.out.println("Anotação feita!");
            
        }
    }
    
    public boolean validar(int d, int an,int mes, String anotacao)
    {
        
        int cont = 0;
        if(an<anoAt)
        {
            System.out.println("Insira um ano válido");
            return false;
        }
        for(int i=0;i<12;i++)
        {
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            {
                if(d>=0 && d<=31)
                {
                     anot[mes*d] = anotacao;
                    return true;
                }
                else
                {
                    System.out.println("Insira um dia válido");
                    return false;
                }
            }
            else if(i == 2)
            {
                if(d>=0 && d<=31)
                {
                    anot[mes*d] = anotacao;
                     return true;
                }
                else
                {
                    System.out.println("Insira um dia válido");
                    return false;
                }
            }
        else
        {
            if(d>=0 && d<=30)
            {
                anot[mes*d] = anotacao;    
                return true;
            }
            else
            {
                System.out.println("Insira um dia válido");
                return false;
            }
        }
    }
    return false;
}
}
