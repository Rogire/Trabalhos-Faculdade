#ifndef PILHACONT_H
#define PILHACONT_H


class PilhaCont
{
    public:
        PilhaCont(int tam);
        ~PilhaCont();
        int getTopo();
        int empilhar(int val);   //inserir
        int desempilhar();      // remover
        void imprime();
    private:
    int topo;
    int max;
    int *vet;
    bool vazia();
};

#endif // PILHACONT_H
