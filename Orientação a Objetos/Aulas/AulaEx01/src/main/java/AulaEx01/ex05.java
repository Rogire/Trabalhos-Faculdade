package AulaEx01;
import javax.swing.JOptionPane;
public class ex05 
{
    public static void main(String[] args) 
    {
        float investimento=0,juros,valorMes=0,valorJuros;
        boolean conf=true;
        String [] options = {"Não","Sim"};
        int itConf,cont=0;
        juros = Float.parseFloat(JOptionPane.showInputDialog(null,"Insira o valor de juros"));
        valorMes = Float.parseFloat(JOptionPane.showInputDialog(null,"Insira o valor para ser investido"
                + " todo mês"));
        while(conf)
        {
            for(int i=0;i<12;i++)
            {
                investimento +=valorMes;
                if(i<11)
                {
                    valorJuros = investimento * (juros/100);
                    investimento +=valorJuros;
                }
            }
            cont++;
            JOptionPane.showMessageDialog(null,(cont==1)?("Saldo do investimento após "+cont+" ano: "+investimento) : ("Saldo do investimento após "+cont+" anos: "+investimento));
            itConf = JOptionPane.showOptionDialog(null, "Deseja processar mais um ano? (S/N)", "Deseja continuar?", JOptionPane.OK_CANCEL_OPTION, JOptionPane.QUESTION_MESSAGE, null,options, options[1]);
            
            switch (itConf)
            {
                case 1->{
                     conf = true;
                     break;
                }
                case 0->{
                    conf=false;
                    break;
                }
                default->
                {
                    break;
                }     
                }
            }
        }
    }
