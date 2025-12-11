#include "ListCont.h"
#include <iostream>
using namespace std;
ListCont::ListCont(int tam)
{
    max = tam;
    n=0;
    vet = new float[tam];
}

ListCont::~ListCont()
{
    delete [] vet;
}

int ListCont::get(int k)
{
    if(k>0 && k<n)
        return vet[k];
    else
    {
        cout<<"Posição inválda";
        exit(1);
    }
}
void ListCont::set(int k, float val)
{
    if(k>0 && k<n)
        vet[k]=val;
    else
    {
        cout<<"Posição inválda";
        exit(1);
    }
}
void ListCont::insereFinal(float val)
{
    if(n>=max)
    {
        float *nV = new float[max*2];
        for(int i=0; i<n; i++)
            nV[i]=vet[i];

        delete [] vet;

        vet = new float[max*2];
        for(int i=0; i<n; i++)
            vet[i]=nV[i];

        delete []nV;
    }
    vet[n]=val;
    n++;
}
void ListCont::removeFinal()
{
    n--;
}
void ListCont::insereK(int k,float val)
{
    if(n>=max)
    {
        max=max*2;
        float *nV = new float[max];
        for(int i=0; i<n; i++)
            nV[i]=vet[i];

        delete [] vet;

        vet = new float[max];
        for(int i=0; i<n; i++)
            vet[i]=nV[i];

        delete []nV;
    }
    if(k>0 && k<n)
    {
        for(int i=n;i>k;i--)
        {
            vet[i]=vet[i-1];
        }
        vet[k]=val;
        n++;
    }
}
void ListCont::removeK(int k)
{
    for(int i=k; i<n-1;i++)
    {
        vet[i]=vet[i+1];
    }
    n--;
}

void ListCont::imprime()
{
    cout<<"Lista: \n";
    for(int i=0; i<n; i++)
    {
        cout<<vet[i]<<" ";
    }
    cout<<endl;
}
