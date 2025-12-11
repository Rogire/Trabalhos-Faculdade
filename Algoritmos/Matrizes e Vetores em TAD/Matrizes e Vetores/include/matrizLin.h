#ifndef MATRIZLIN_H
#define MATRIZLIN_H


class matrizLin
{
    public:
        matrizLin(int nl, int nc);
        ~matrizLin();
        int get(int i, int j);
        void set(int i, int j, float val);

    private:
    float *vet;
    int n;
    int lin;
    int col;
    int detInd(int i, int j);
};

#endif // MATRIZLIN_H
