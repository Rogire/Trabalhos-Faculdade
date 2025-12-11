#ifndef LISTENC_H
#define LISTENC_H
#include "No.h"

class ListEnc
{
    public:
        ListEnc();
        ~ListEnc();
        int get(int k);
        void set(int k,float val);
        void insereInicio(float val);
        void imprime();
        void desinverte();
        void insereFinal(float val);
        int busca(float val);
        void removeInicio();
        void removeFinal();
        void removeK(int k);
        void insereK(int k, float val);
    private:
       No *primeiro;
};

#endif // LISTENC_H
