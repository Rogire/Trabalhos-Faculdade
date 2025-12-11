#include "Matriz.h"
#include <iostream>
using namespace std;
Matriz::Matriz(int lin, int col)
{
    nL = lin;
    nC= col;
    mat = new float*[nL];

    for(int i=0; i<nL; i++)
        mat[i]=new float [nC];
}

Matriz::~Matriz()
{
    for(int i=0;i<nL; i++)
        delete [] mat[i];
    delete [] mat;
}

int Matriz::get(int i, int j)
{
    if(verifica(i,j))
        return mat[i][j];
    else
    {
    cout<<"Valor inválido!";
    exit(1);
    }
}

void Matriz::set(int i, int j,float val)
{
    if(verifica(i,j))
        mat[i][j]=val;
    else
    {
    cout<<"Valor inválido!";
    exit(1);
    }
}

bool Matriz::verifica(int i, int j)
{
    return(i>=0 && i<nL && j>=0 && j<nC)?true:false;
}
