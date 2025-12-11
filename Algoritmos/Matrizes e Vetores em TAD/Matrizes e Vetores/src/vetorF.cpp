#include "vetorF.h"
#include <iostream>
using namespace std;
vetorF::vetorF(int c, int f)
{
    co= c;
    fim=f;
    n = fim - co +1;
    vet = new int[n];
}

vetorF::~vetorF()
{
    delete [] vet;
}

int vetorF::get(int i)
{
    int ind = detInt(i);
    if(ind!=-1)
        return vet[ind];
    else
    {
    cout<<"Valor inválido!";
    exit(1);
    }
}

void vetorF::set(int i, int val)
{
    int ind = detInt(i);
    if(ind!=-1)
        vet[ind]=val;
    else
    {
    cout<<"Indice inválido!";
    exit(1);
    }
}

int vetorF::detInt(int i)
{
    return (co<=i && i<=fim)?(i-co):-1;
}
