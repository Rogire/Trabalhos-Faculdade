package A2E01;
import java.text.DecimalFormat;
import javax.swing.JOptionPane;
/**
 *
 * @author ice
 */
public class Aula02Ex01 
{
    public static void main(String[] args) 
    {
        String x1,x2,y1,y2;
        float X1,X2,Y1,Y2;
        double resu;
        DecimalFormat dec = new DecimalFormat("#0.000"); //Formatação do valor resu para 3 digítos
        x1 = JOptionPane.showInputDialog(null,"Insira o x do primeiro ponto");
        y1 = JOptionPane.showInputDialog(null,"Insira o y do primeiro ponto");
        x2 = JOptionPane.showInputDialog(null,"Insira o x do segundo ponto");
        y2 = JOptionPane.showInputDialog(null,"Insira o y do segundo ponto");
        X1 = Float.parseFloat(x1);
        X2 = Float.parseFloat(x2);
        Y1 = Float.parseFloat(y1);
        Y2 = Float.parseFloat(y2);
        
        resu = Math.sqrt(Math.pow(X2-X1,2)+(Math.pow(Y2-Y1,2))); //Cálculo da equação
        JOptionPane.showMessageDialog(null,"A distância entre ("+x1+","+y1+") e ("+x2+","+y2+") é "+dec.format(resu));  
    }
}
