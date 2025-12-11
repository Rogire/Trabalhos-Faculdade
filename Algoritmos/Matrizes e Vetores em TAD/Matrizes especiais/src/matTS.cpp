#include "matTS.h"
#include <iostream>
using namespace std;
matTS::matTS(int ordem)
{
    n = ordem;
    tam =n*(n+1)/2;
    vet=new int [tam];
}

matTS::~matTS()
{
    delete [] vet;
}

int matTS::get(int i, int j)
{
    int ind =detInd(i,j);
    if(ind > -1)
        return vet[ind];
    else if(ind == -1)
        return 0;
    else
    {
    cout<<"Valor inválido";
    exit(1);
    }
}

void matTS::set(int i, int j, int val)
{
    int ind = detInd(i,j);
    if(ind>-1)
        vet[ind]=val;
    else if(ind ==-1)
        false;
    else
    {
    cout<<"Valor inválido";
    exit(1);
    }
}
int matTS::detInd(int i, int j)
{
    if(i>=0 && j>=0 && i<n && j<n)
        if(j>=i)
            return j*(j+1)/2 +i;
        else return -1;
    else return -2;
}

void matTS::imprime()
{
    for(int i=0; i<tam; i++)
        cout<<vet[i]<<" ";
}

