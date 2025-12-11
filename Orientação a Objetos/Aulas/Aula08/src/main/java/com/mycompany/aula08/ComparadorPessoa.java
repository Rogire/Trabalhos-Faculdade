package com.mycompany.aula08;

public class ComparadorPessoa implements java.util.Comparator<Pessoa>
{
  @Override  
  public int compare(Pessoa a, Pessoa b) 
  {
    return (a.getNome().charAt(0)-'a') - (b.getNome().charAt(0)-'a');
  }
}