#ifndef MATRIZ_H
#define MATRIZ_H


class Matriz
{
    public:
        Matriz(int lin, int col);
        ~Matriz();
        int get(int i, int j);
        void set(int i, int j, float val);
    private:
        float **mat;
        int nL;
        int nC;
        bool verifica(int i, int j);
};

#endif // MATRIZ_H
