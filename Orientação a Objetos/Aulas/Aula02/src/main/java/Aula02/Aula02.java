package Aula02;
import javax.swing.JOptionPane;
/**
 *
 * @author igor
 */
public class Aula02 
{
    public static void main(String[] args) 
    {
        String nome = JOptionPane.showInputDialog(null,"Insira seu nome:","Nome?",JOptionPane.QUESTION_MESSAGE);
        System.out.println("Olá " + nome + "!");
        int rep=1;
        //calculadora();
        String valor1,valor2,op;
        float v1,v2,res=0;

        while(rep == 1) //while infinito com saída na flag op==0.
        {
        valor1=JOptionPane.showInputDialog("Insira o primeiro valor:");
        op=JOptionPane.showInputDialog("Insira a operação: (0 para sair)");
        if(op.equals("0"))// flag de saída
        {
            JOptionPane.showMessageDialog(null, "Encerrando");
            break;
        }
        valor2=JOptionPane.showInputDialog("Insira o segundo valor:");
        v1 =Float.parseFloat(valor1);
        v2=Float.parseFloat(valor2);
        //operações
        if(op.contains("+"))
            res = v1 + v2;
        else if(op.contains("-"))
            res = v1 - v2;
        else if(op.contains("*"))
            res = v1 * v2;
        else if(op.contains("/"))
            res = v1 / v2;
        else
        {
            JOptionPane.showMessageDialog(null,"Insira um operador válido.");
            break;
        }
        System.out.println(res);
        JOptionPane.showMessageDialog(null, res);
        }      
    }
}
