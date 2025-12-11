#ifndef LISTCONT_H
#define LISTCONT_H


class ListCont
{
    public:
        ListCont(int tam);
        ~ListCont();
        int get(int k);
        void set(int k, float val);
        void insereFinal(float val);
        void removeFinal();
        void insereK(int k,float val);
        void removeK(int k);
        void imprime();
    private:
    int max;
    int n;
    float *vet;
};

#endif // LISTCONT_H
