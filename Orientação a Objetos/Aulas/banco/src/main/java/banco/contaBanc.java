/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package banco;

/**
 *
 * @author igort
 */
public class contaBanc {
    private String agencia;
    private String numero;
    private String cliente;
    private float saldo;
    
    public contaBanc(String ag, String num, String cl, float sd)
    {
        agencia = ag;
        numero = num;
        cliente = cl;
        saldo = sd;
    }
    
    public void sacar(int valor)
    {
        if(saldo >= valor)
            saldo -= valor;
        else
            System.out.println("Valor inválido");
    }
    public void depositar(int valor)
    {
        if(valor <= 0)
            System.out.println("Valor inválido");
        else
            saldo+=valor;
    }
}
