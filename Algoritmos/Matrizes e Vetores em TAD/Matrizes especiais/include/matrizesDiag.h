#ifndef MATRIZESDIAG_H
#define MATRIZESDIAG_H


class matrizesDiag
{
    public:
        matrizesDiag(int ordem);
        ~matrizesDiag();
        int get(int i, int j);
        void set(int i, int j, int val);

    private:
    int *vet;
    int n;
    int detInt(int i, int j);
};

#endif // MATRIZES ESPECIAIS_H
