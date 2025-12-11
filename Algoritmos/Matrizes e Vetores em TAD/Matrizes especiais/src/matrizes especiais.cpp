#include "matrizesDiag.h"
#include <iostream>
using namespace std;
matrizesDiag::matrizesDiag(int ordem)
{
    n=ordem;
    vet = new int [n];
}

matrizesDiag::~matrizesDiag()
{
    delete [] vet;
}

int matrizesDiag::get(int i, int j)
{
    int ind = detInt(i,j);
    if(ind>-1)
        return vet[ind];
    if(ind == -1)
        return 0;
    else
    {
    cout<<"Valor inválido";
    exit(1);
    }
}

void matrizesDiag::set(int i, int j, int val)
{
    int ind = detInt(i,j);
    if(ind>-1)
        vet[ind] = val;
    else if(ind == -1)
        false;
    else
    {
    cout<<"Valor inválido";
    exit(1);
    }
}

int matrizesDiag::detInt(int i, int j)
{
    //return(i>=0 && j>=0 && i<lin && j<col)?i*col+j:-1;
    //Matriz Diagonal:
    if(i>=0 && j>=0 && i<n && j<n)
        if(i==j)
        {
            return i*n+j;
        }
        else return -1;

    else return -2;

}
