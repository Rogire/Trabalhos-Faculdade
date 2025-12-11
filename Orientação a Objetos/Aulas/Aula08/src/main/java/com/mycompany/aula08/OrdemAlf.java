
package com.mycompany.aula08;

public class OrdemAlf {
        
        public OrdemAlf()
        {
            for(int i=0; i<26; i++)
                Alf[i] = new letra(i+1,minu[i].charAt(0),maiu[i].charAt(0));
        };
        public void imprime()
        {
            for(int i=0; i<26; i++)
            {
            System.out.println("letra: "+Alf[i].getVal()+" "+Alf[i].getVAL()+" pos:"+Alf[i].getPos());
            }
        }
        public static void ordenar(String plvs[], int t)
        {
            auxOrd(plvs,t,0);
        }

        public static void auxOrd(String plvs[], int t, int trocas)
        {
            int c1, c2, rep;
            boolean ord;
            String aux;
            for(int i=0; i<t-1; i++)
                {
                c1=0; c2=0; rep= numRep(plvs, i);
                ord = false;

                for(int j=0; j<plvs[i].length()-rep; j++)
                {
                    for(int c=0; c<26; c++)
                    {
                        if(plvs[i].charAt(j+rep) == Alf[c].getVal() || plvs[i].charAt(j+rep) == Alf[c].getVAL())
                            c1 = Alf[c].getPos();

                        if(plvs[i+1].charAt(j+rep) == Alf[c].getVal() || plvs[i+1].charAt(j+rep) == Alf[c].getVAL())
                            c2 = Alf[c].getPos();

                        if(c1>0 && c2>0) // verifica se c1 e c2 já foram atribuídos
                            if(c1>c2)
                            {
                                aux = new String(plvs[i]);
                                plvs[i] = plvs[i+1];
                                plvs[i+1] = aux;
                                trocas++;
                                ord=true;
                                
                                
                                break;
                            }
                            else if(c1<c2)
                            {
                                ord=true;
                                break;
                            }
                    }
                        if(ord) // para o laço caso a verificação tenha sido feita
                            break;
                }
            }
            
            if(trocas>0)
                auxOrd(plvs,t,0);
        }

    private static final letra[] Alf = new letra[26];
    private static int numRep(String[] plvs,int i)
    {
        int rep=0;
        for(int j=0; j<plvs[i].length();j++)
        {
            if(plvs[i].charAt(j) == plvs[i+1].charAt(j))
                rep++;
            else
                break;
        }

        return rep;
    };
    private final String[] minu = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    private final String[] maiu = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    
    public static void main(String[] args) 
    {
        OrdemAlf teste = new OrdemAlf();
        String[] ex = {"bruno","aurelio","lucas","joel","igor","carlos","belle","fer","tulio","loq","bullets"};
        teste.ordenar(ex,11);
        teste.imprime();
        for(int i=0; i<11; i++)
            System.out.print(ex[i]+" ");
    }
}