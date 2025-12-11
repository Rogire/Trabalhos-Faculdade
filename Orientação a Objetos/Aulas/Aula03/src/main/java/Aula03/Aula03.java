package Aula03;
<<<<<<< HEAD
import javax.swing.JOptionPane;
/**
 *
 * @author igor
 */
public class Aula03 
{
    public static double D(Ponto P1, Ponto P2)
    {
        return Math.sqrt((Math.pow(P2.getX() - P1.getX(),2)) + (Math.pow(P2.getY() - P1.getY(),2)));
    }
    
    public static void main(String[] args) 
    {
        Ponto A,B,C;
        float x,y;
        double L1,L2,L3;
        A = new Ponto();
        B = new Ponto();
        C = new Ponto();
        Ponto vet[]={A,B,C};
        
        for(int i=0; i<3;i++)
        {
            x = Float.parseFloat((JOptionPane.showInputDialog(null,"Insira o valor do x do ponto "+(i+1))));
            vet[i].setX(x);
            y = Float.parseFloat((JOptionPane.showInputDialog(null,"Insira o valor do y do ponto "+(i+1))));
            vet[i].setY(y);
        }
        L1= D(A,B);
        L2= D(A,C);
        L3= D(B,C);
        
        System.out.println(L1+" "+L2+" "+L3);

            if (L1==L2 && L2==L3)
                System.out.println("Equilátero");
            else if((L1==L2 && L2 !=L3) || L1==L3 && L2!=L3)
                System.out.println("Isósceles");
            else if(L1!=L2 && L2!=L3 && L1!=L3)
            System.out.println("Escaleno");
    }
}
=======
import java.util.Scanner;
/**
 *
 * @author ice
 */
public class Aula03 
{
    public static void main(String[] args) 
    {
     Scanner teclado = new Scanner(System.in);
     double L1,L2,L3;
     Ponto P1=new Ponto(0,0);
     Ponto P2=new Ponto(0,0);
     Ponto P3=new Ponto(0,0);          
     int valor=0;
     for(int i=0;i<3;i++)
     {
        System.out.println("Insira o x ponto "+(i+1)+":");
        valor=teclado.nextInt();
        P1.setX(valor);
        System.out.println("Insira o y ponto "+(i+1)+":");
        valor=teclado.nextInt();
        P1.setY(valor);
     }
     L1=CalcDist(P1,P2);
     L2=CalcDist(P1,P3);
     L3=CalcDist(P2,P3);
     
     System.out.println(L1+" "+L2+" "+L3);
     
     if(L1==L2 && L2==L3)
     {
         System.out.println("Equilátero");
     }
     
     if(EhTriang(L1,L2,L3))
     {
     if((L1==L2 && L2!=L3)||(L1!=L2 && L2==L3))
     {
         System.out.println("Isósceles");
     }
     else if((L1!=L2 && L2!=L3))
     {
         System.out.println("Escaleno");
     }
    }
     else
         System.out.println("Não é um triângulo");
    }
    
    public static double CalcDist(Ponto P1, Ponto P2) //Calcula a distância entre dois pontos(Lados do triangulo) 
    {
        return (Math.sqrt((Math.pow(P2.getX()-P1.getX(),2))+(Math.pow(P2.getY()-P1.getY(),2))));
    }
    public static boolean EhTriang(double L1,double L2, double L3)// Verifica se é triângulo
    {
        double maior = L1;
        double soma=0;
        double Lados[]={L1,L2,L3};
        for(int i=0;i<2;i++)
            if(maior<Lados[i])
                maior=Lados[i];
        
        for(int i=0; i<2;i++)
            if(maior == Lados[i])
                Lados[i]-=maior;
        
        for(int i=0;i<2;i++)
           if(Lados[i]!=0)
               soma+=Lados[i];
        return (soma<maior)?true:false;
    }
}

>>>>>>> fca6a8e (update)
