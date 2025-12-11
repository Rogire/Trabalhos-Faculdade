
package com.mycompany.aula08;

public final class letra {
    public letra(int p, char m, char M)
    {
        setPos(p);
        setVal(m);
        setVAL(M);
    }
    public void setPos(int p){ pos = p;}
    public int getPos(){return pos;}
    public void setVal(char v){val=v;}
    public char getVal(){return val;}
    public void setVAL(char V){VAL=V;}
    public char getVAL(){return VAL;}
    
    private static char val;
    private static char VAL;
    private static int pos;
}