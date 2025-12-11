/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Aula04;

/**
 *
 * @author igor
 */
public class Aluno 
{

    public String getNome() {
        return nome;
    }

    public int getIdade() {
        return idade;
    }

    public int getCont() {
        return cont;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public void setCont(int cont) {
        this.cont = cont;
    }
    
    String nome;
    int idade;
    int cont=0;
}
