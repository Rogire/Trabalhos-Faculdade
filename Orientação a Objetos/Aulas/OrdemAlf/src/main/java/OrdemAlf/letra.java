/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package OrdemAlf;

/**
 *
 * @author igort
 */
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
    
    private char val;
    private char VAL;
    private int pos;
}
