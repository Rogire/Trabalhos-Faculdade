#include "matrizLin.h"
#include <iostream>
using namespace std;
matrizLin::matrizLin(int nl, int nc)
{
    lin = nl;
    col = nc;
    n = nl*nc;
    vet = new float [n];
}

matrizLin::~matrizLin()
{
    delete [] vet;
}

int matrizLin::get(int i, int j)
{
    int ind = detInd(i,j);
    if(ind !=-1)
        return vet[ind];
    else
    {
    cout<<"Valor inválido!";
    exit(1);
    }
}

void matrizLin::set(int i, int j, float val)
{
    int ind = detInd(i,j);
    if(ind !=-1)
        vet[ind]=val;
    else
    {
    cout<<"Valor inválido!";
    exit(1);
    }
}

int matrizLin::detInd(int i, int j)
{
    return(i>=0 && i<lin && j>=0 && j<col)?i*col+j:-1;
}
