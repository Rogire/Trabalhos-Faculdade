#ifndef PILHAENCAD_H
#define PILHAENCAD_H
#include "No.h"

class PilhaEncad
{
    public:
        PilhaEncad();
        ~PilhaEncad();
        void empilhar(int val);
        int desempilhar();
        bool vazia();
        void imprime();
    private:
        No* topo;

};

#endif // PILHAENCAD_H
