package com.mycompany.calculadoraprobabilidade;
import java.math.BigInteger;
import java.util.Scanner;


public class CalculadoraProbabilidade {
    
    public static String teste(){
        return """
                Selecione a operação
               (1) Combinação
               (2) Permutação
               (3) Coeficiente Multinomial
               (4) Teorema Binomial
               (5) Sair
               
               """;
        
    }
    
    public static void calculadora(int op,int val1, int val2, Scanner teclado)
    {
        while(op!=5)
    {
        System.out.println("Selecione a nova operação: (5 para sair)");
        op = teclado.nextInt();
        switch (op)
        {
            case 1 -> {
                System.out.println("digite os valores:");
                val1 = teclado.nextInt();
                val2 = teclado.nextInt();
                System.out.println("Cn("+val1+","+val2+")= "+Combinacao(val1,val2));
            }
            case 2 -> {
                System.out.println("digite os valores:");
                val1 = teclado.nextInt();
                val2 = teclado.nextInt();
                System.out.println("Pn("+val1+","+val2+")= "+Permutacao(val1,val2));
            }
            case 3 -> {
                System.out.println("digite o valor, e o número de grupos:");
                val1= teclado.nextInt();
                val2  =teclado.nextInt();
                System.out.println(CoefMult(val1,val2));
            }
            case 4 -> {
            }
        }
    }
    }
    
    
    public static void main(String[] args) 
    {
    Scanner teclado = new Scanner(System.in);
    int op, val1=0, val2=0;
    System.out.println(teste());
    op = teclado.nextInt();
    switch (op)
        {
            case 1 -> {
                System.out.println("digite os valores:");
                val1 = teclado.nextInt();
                val2 = teclado.nextInt();
                System.out.println("Cn("+val1+","+val2+")= "+Combinacao(val1,val2));
            }
            case 2 -> {
                System.out.println("digite os valores:");
                val1 = teclado.nextInt();
                val2 = teclado.nextInt();
                System.out.println("Pn("+val1+","+val2+")= "+Permutacao(val1,val2));
            }
            case 3 -> {
                System.out.println("digite o valor, e o número de grupos:");
                val1= teclado.nextInt();
                val2  =teclado.nextInt();
                System.out.println(CoefMult(val1,val2));
            }
            case 4 -> {
            }
        }
    
        calculadora(op,val1,val2,teclado);
    }
    
    public static BigInteger Combinacao(long m, long n)
    {
        return fatorial(m).divide(fatorial(n).multiply(fatorial(m-n)));
    }
    public static BigInteger Permutacao(long m, long k)
    {
        return fatorial(m).divide(fatorial(m-k));
    }
    public static BigInteger CoefMult(long m, int num)
    {
        Scanner teclado = new Scanner(System.in);
        BigInteger res = BigInteger.ONE;
        int [] arr = new int[num];
        int soma=0;
        
        System.out.println("Insira os valores dos grupos");
        for(int i =0; i<num; i++)
        {
            arr[i] = teclado.nextInt();
            soma+=arr[i];
        }
        
        if(soma>m)
        {
            System.out.println("A soma dos grupos deve ser menor que o valor total.");
            return BigInteger.ZERO;
        }
        
        for(int i =0; i<num; i++)
            res = res.multiply(fatorial((long)arr[i]));
        
        return fatorial(m).divide(res);
    }

    
    public static BigInteger fatorial(long fat)
    {
        BigInteger fatorial = BigInteger.ONE;
        for(int cont=0; cont<fat-1;cont++)
            fatorial = fatorial.multiply(BigInteger.valueOf(fat-cont));

        return fatorial;
    }
}