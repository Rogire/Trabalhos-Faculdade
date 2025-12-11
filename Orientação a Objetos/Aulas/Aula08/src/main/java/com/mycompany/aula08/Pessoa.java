package com.mycompany.aula08;

public class Pessoa 
{

    public double getCPF() {
        return CPF;
    }

    public void setCPF(double CPF) {
        this.CPF = CPF;
    }

    public String getSexo() {
        return sexo;
    }

    public void setSexo(String sexo) {
        this.sexo = sexo;
    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }
    private double CPF;
    private String sexo;
    private String endereco;
    private String nome;
    private int idade;
    
    public Pessoa(String nom,int id,int capefi, String sex,String end){
        CPF = capefi;
        sexo = sex;
        endereco = end;
        nome = nom;
        idade = id;
    }
}
