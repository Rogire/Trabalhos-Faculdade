#ifndef MATTS_H
#define MATTS_H


class matTS
{
    public:
        matTS(int ordem);
        ~matTS();
        int get(int i, int j);
        void set(int i, int j, int val);
        void imprime();

    private:
    int n;
    int tam;
    int *vet;
    int detInd(int i, int j);
};

#endif // MATTS_H
