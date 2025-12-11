package com.mycompany.contabanc;
public final class Cliente {

    protected String getNome() {
        return nome;
    }

    protected void setNome(String nome) {
        this.nome = nome;
    }

    protected int getIdade() {
        return idade;
    }
    
    protected static String teste(){return "teste";}

    protected void setIdade(int idade) {
        this.idade = idade;
    }
    private String nome;
    private int idade;
    
    public Cliente(String n, int id)
    {
        nome = n;
        idade = id;
    }
}
