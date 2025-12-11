package AulaEx01;
import java.util.Scanner;
import javax.swing.JOptionPane;
/**
 *
 * @author ice
 */
public class ex02
{
    public static float calculadora(int op,float val,String options[])
    {
        float v1,v0;
        op = JOptionPane.showOptionDialog(null, "Selecione a operação", "Selecione a operação", JOptionPane.OK_CANCEL_OPTION, JOptionPane.QUESTION_MESSAGE, null, options,"");
        while(op!=4)
        {
        switch(op)
        {
            case 0->{
                v1=Float.parseFloat(JOptionPane.showInputDialog(null,"Insira o valor"));
                v0=val;
                val +=v1;
                JOptionPane.showMessageDialog(null,v0 +" + "+v1+"="+val);
                break;
            }
            case 1->{
                v1=Float.parseFloat(JOptionPane.showInputDialog(null,"Insira o valor"));
                v0=val;
                val -=v1;
                JOptionPane.showMessageDialog(null,v0 +" - "+v1+"="+val);
                break;
            }
            case 2->{
                v1=Float.parseFloat(JOptionPane.showInputDialog(null,"Insira o valor"));
                v0=val;
                val /=v1;
                JOptionPane.showMessageDialog(null,v0 +" / "+v1+"="+val);
                break;
            }
            case 3->{
                v1=Float.parseFloat(JOptionPane.showInputDialog(null,"Insira o valor"));
                v0=val;
                val *=v1;
                JOptionPane.showMessageDialog(null,v0 +" * "+v1+"="+val);
                break;
            }
            case 4->
            {
                break;
            }
        }
        op = JOptionPane.showOptionDialog(null, "Selecione a operação", "Selecione a operação", JOptionPane.OK_CANCEL_OPTION, JOptionPane.QUESTION_MESSAGE, null, options,"");
        }
        return val;
    }
    public static void main(String[] args) 
    {
        float v1,v2,val=0;
        int op;
        String[] options={"+","-","/","*","Sair"};
        op = JOptionPane.showOptionDialog(null, "Selecione a operação", "Selecione a operação", JOptionPane.OK_CANCEL_OPTION, JOptionPane.QUESTION_MESSAGE, null, options,"");
        switch(op)
        {
            case 0->{
                v1=Float.parseFloat(JOptionPane.showInputDialog(null,"Insira o valor"));
                v2=Float.parseFloat(JOptionPane.showInputDialog(null,"Insira o valor"));
                val = v1+v2;
                JOptionPane.showMessageDialog(null,v1 +" + "+v2+"="+val);
                break;
            }
            case 1->{
                v1=Float.parseFloat(JOptionPane.showInputDialog(null,"Insira o valor"));
                v2=Float.parseFloat(JOptionPane.showInputDialog(null,"Insira o valor"));
                val = v1-v2;
                JOptionPane.showMessageDialog(null,v1 +" - "+v2+"="+val);
                break;
            }
            case 2->{
                v1=Float.parseFloat(JOptionPane.showInputDialog(null,"Insira o valor"));
                v2=Float.parseFloat(JOptionPane.showInputDialog(null,"Insira o valor"));
                val = v1/v2;
                JOptionPane.showMessageDialog(null,v1 +" / "+v2+"="+val);
                break;
            }
            case 3->
            {
                v1=Float.parseFloat(JOptionPane.showInputDialog(null,"Insira o valor"));
                v2=Float.parseFloat(JOptionPane.showInputDialog(null,"Insira o valor"));
                val = v1*v2;
                JOptionPane.showMessageDialog(null,v1 +" * "+v2+"="+val);
                break;
            }
            case 4->
            {
                break;
            }
        }
        calculadora(op,val,options);
    }
}
