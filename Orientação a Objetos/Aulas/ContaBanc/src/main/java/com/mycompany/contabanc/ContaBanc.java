package com.mycompany.contabanc;
public class ContaBanc {
    public static void main(String[] args) 
    {
        Conta cn = new Conta(152,150,"Igor",19);
        Conta cn2 = new Conta(153,1500,"Junin",12);
        Conta cn3 = new Conta(154,1819,"Cleber",29);
        Conta cn4 = new Conta(155,2067.89f,"Joelma",52);
        cn.Dados();
        cn2.Dados();
        cn3.Dados();
        cn4.Dados();
        
        System.out.println(Conta.getTotContas());
        System.out.println(Cliente.teste());
    }
}
