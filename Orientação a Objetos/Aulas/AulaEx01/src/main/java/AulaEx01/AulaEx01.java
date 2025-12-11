package AulaEx01;
import javax.swing.JOptionPane;
/**
 *
 * @author ice
 */
public class AulaEx01 
{
    public static void main(String[] args) 
    {
        Ponto p1 = new Ponto();
        Ponto p2 = new Ponto();
        Ponto[] pontos = {p1,p2};
        int conf=1;
        String[] options = {"Não","Sim"};
        
        while(conf==1)
        {
        for(int i =0;i<2;i++)
        {
            String x = JOptionPane.showInputDialog(null,"Insira o valor de x"+(i+1));
            String y = JOptionPane.showInputDialog(null,"Insira o valor de y"+(i+1));
            while(x.equals(""))
                x = JOptionPane.showInputDialog(null,"Insira um valor válido");
            while(y.equals(""))
                y = JOptionPane.showInputDialog(null,"Insira um valor válido");
            
            pontos[i].setX(Integer.parseInt(x));
            pontos[i].setY(Integer.parseInt(y));
        }
        
        JOptionPane.showMessageDialog(null,"P1: ("+p1.getX()+","+p1.getY()+")\nP2: ("+p2.getX()+","+p2.getY()+")");
        
        JOptionPane.showMessageDialog(null, "Distância:"+
                Math.sqrt((Math.pow(p2.getX()-p1.getX(),2))+(Math.pow(p2.getY()-p1.getY(),2))));
        
        conf = JOptionPane.showOptionDialog(null, "Deseja continuar?", "Deseja continuar?", JOptionPane.OK_CANCEL_OPTION, JOptionPane.QUESTION_MESSAGE, null, options, options[1]);
        }
    }
}
