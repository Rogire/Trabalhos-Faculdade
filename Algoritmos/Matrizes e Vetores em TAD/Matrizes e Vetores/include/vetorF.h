#ifndef VETORF_H
#define VETORF_H


class vetorF
{
    public:
        vetorF(int c, int f);
        ~vetorF();
        int get(int i);
        void set(int i, int val);
    private:
    int n;
    int co;
    int fim;
    int *vet;
    int detInt(int i);
};

#endif // VETORF_H
