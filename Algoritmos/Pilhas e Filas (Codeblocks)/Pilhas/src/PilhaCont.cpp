#include "PilhaCont.h"
#include <iostream>

using namespace std;
PilhaCont::PilhaCont(int tam)
{
    max = tam;
    vet = new int[tam];
    topo = -1;
}

PilhaCont::~PilhaCont()
{
    delete [] vet;
}

int PilhaCont::getTopo()
{
    return topo;
}
int PilhaCont::empilhar(int val)
{
    if(getTopo()==max-1)
    {
        cout<<"Pilha Cheia!";
        exit(0);
    }

    topo++;
    vet[getTopo()] = val;
}

int PilhaCont::desempilhar()
{
    if(vazia())
    {
        cout<<"Pilha Vazia!";
        exit(0);
    }

    int val = vet[getTopo()];
    topo--;
    return val;
}

void PilhaCont::imprime()
{
    for(int i=0; i<=getTopo(); i++)
    {
        cout<<vet[i]<<" ";
    }
    cout<<endl;
}

bool PilhaCont::vazia()
{
    return (topo == -1)? true:false;
}
