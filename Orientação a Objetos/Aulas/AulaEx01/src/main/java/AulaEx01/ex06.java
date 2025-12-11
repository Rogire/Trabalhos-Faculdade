package AulaEx01;
import javax.swing.JOptionPane;
/**
 *
 * @author igor
 */
public class ex06 
{
    final static private String[] NUMEROS = {"0","1","2","3","4","5","6","7","8","9"};
    
    public static boolean ehSoNumero(String str)
    {
        boolean bool=true;
        
        for(int i=0;i<str.length();i++)
        {
            for(int j=0;j<10;j++)
            {
                if(!(NUMEROS[j].charAt(0) == str.charAt(i)))
                    bool=false;
                else
                {
                    bool=true;
                    break;
                }
            }
        }
        return bool;
    }
    
    public static String formata(String tel)
    {
        String DDD="";
        String PrimM="";
        String segM="";
        if(tel.length()==11)//telefone celular
        {
            DDD ="("+tel.substring(0,2)+")";
            PrimM= tel.substring(2,7)+"-";
            segM = tel.substring(7,11);
        }
        else if(tel.length()==10) // telefone fixo
        {
            DDD ="("+tel.substring(0,2)+")";
            PrimM= tel.substring(2,6)+"-";
            segM = tel.substring(6,10);
        }
        String telF = DDD.concat(PrimM).concat(segM);
        return telF;
    }
    
    public static void validaTel(String tel)
    {
        String telef;
        if( tel.length()>=10 && tel.length()<=11)
        {
            if(ehSoNumero(tel))
            {
                telef =formata(tel);
                JOptionPane.showMessageDialog(null,"Seu número "+telef+" foi validado");
            }
            else
            {
                JOptionPane.showMessageDialog(null,"Número inválido");
            }
        }
        else
            JOptionPane.showMessageDialog(null,"Insira todos os números e o código de área");
    }
    
    public static void validaEmail(String email)
    {
        int cont;
        String fimEm = email.substring(email.length()-4,email.length()); //saber se termina com .com
        if(email.contains("@") && fimEm.equals(".com"))  
        {
            cont = email.indexOf("@");
            if(cont>30 || cont<6)
            {
                JOptionPane.showMessageDialog(null, "O nome do usuario deve ter entre 6 e 30 caracteres.", "Erro", JOptionPane.ERROR_MESSAGE);
            }
            else
                JOptionPane.showMessageDialog(null, "Email validado.");
        }
        else
            JOptionPane.showMessageDialog(null, "Email inválido.");
    }
    
    public static void main(String[] args) 
    {    
        String telefone, email;
        email = JOptionPane.showInputDialog(null,"Insira o email");
        telefone = JOptionPane.showInputDialog(null,"Insira o telefone");
        validaEmail(email);
        validaTel(telefone);
    }
    
}
