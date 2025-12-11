package com.mycompany.contabanc;

public class Conta {
    
    private static int totContas=0;
    private int NumConta;
    private float saldo;
    private Cliente Cli;
    
    public int getNumConta() {
        return NumConta;
    }

    public void setNumConta(int NumConta) {
        this.NumConta = NumConta;
    }

    public float getSaldo() {
        return saldo;
    }

    public void setSaldo(float saldo) {
        this.saldo = saldo;
    }

    public static int getTotContas() {
        return totContas;
    }

    public static void setTotContas(int totContas) {
        Conta.totContas = totContas;
    }
    
    public Conta(int Nc, float sd, String nom, int idd)
    {
        Cli = new Cliente(nom,idd);
        NumConta = Nc;
        saldo = sd;
        totContas++;
    }
    
    public void sacar(float val)
    {
        if(val>0 && val<=getSaldo())
        {
            setSaldo(getSaldo()-val);
        }
        else
        {
            System.out.println("Insira um valor válido");
        }
    }
    public void depositar(float val)
    {
        if(val>0)
        {
            setSaldo(getSaldo()+val);
        }
        else
        {
            System.out.println("Insira um valor válido");
        }
    }
    public void Dados()
    {
        System.out.println("Usuário: "+Cli.getNome()+", idade: "+Cli.getIdade());
        System.out.println("Número da conta: "+getNumConta());
        System.out.println("Valor em conta: "+getSaldo());
    }
}
