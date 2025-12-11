#include "PilhaEncad.h"
#include <cstddef>
#include <iostream>
using namespace std;
PilhaEncad::PilhaEncad()
{
    topo = NULL;
}

PilhaEncad::~PilhaEncad()
{
    No *p = topo;
    while(!vazia())
    {
        topo = p->getProx();
        delete p;
        p = topo;
    }
}

bool PilhaEncad::vazia()
{
    return (topo == NULL);
}

void PilhaEncad::empilhar(int val)
{
    No* novo = new No();
    novo->setInfo(val);
    novo->setProx(topo);
    topo = novo;
}

int PilhaEncad::desempilhar()
{
    No* p = topo;
    int val;
    if(topo!=NULL)
    {
        topo = p->getProx();
        val = p->getInfo();
        delete p;
    }
    return val;
}

void PilhaEncad::imprime()
{
    for(No*p = topo;p!=NULL;p=p->getProx())
    {
        cout<<p->getInfo()<<" ";
    }
    cout<<endl;
}

