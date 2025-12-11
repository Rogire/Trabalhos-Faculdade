package Aula04Ex01;
/**
 *
 * @author ice
 */
public class Aluno 
{
    public Aluno()
    {
        nome = "Nome";
        idade = 0;
        cont=0;
    }
    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getCont() {
        return cont;
    }

    public void setCont(int cont) {
        this.cont = cont;
    }
    int idade;
    String nome;
    int cont;
}
