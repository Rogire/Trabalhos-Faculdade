#include "ListEnc.h"
#include <cstddef>
#include <iostream>
using namespace std;
ListEnc::ListEnc()
{
    primeiro = NULL;
}

ListEnc::~ListEnc()
{
    No *p=primeiro;
    while(p!=NULL)
    {
        No *t = p->getProx();
        delete p;
        p=t;
    }
}

void ListEnc::insereInicio(float val)
{
    No *p =new No();
    p->setInfo(val);
    p->setProx(primeiro);
    primeiro = p;
}

void ListEnc::imprime()
{
    for(No *p=primeiro;p!=NULL;p= p->getProx())
    {
        cout<< p->getinfo()<<" ";
    }
    cout<<endl;
}

void ListEnc::insereFinal(float val)
{
    No *p=new No();
    p->setInfo(val);

    if(primeiro ==NULL)
        primeiro = p;
    else
    {
    No *prox = primeiro;
    while(prox->getProx())
        prox = prox->getProx();
    prox->setProx(p);
    }

}

int ListEnc::busca(float val)
{
    int i=1;
    for(No *p=primeiro;p!=NULL;p=p->getProx())
    {
        if(p->getinfo()==val)
        {
            return i;
        }
        else if(p->getProx()==NULL)
        {
            cout<<"O valor não está presente na lista\n";
            exit(0);
        }
        i++;
    }
}

void ListEnc::removeInicio()
{
    if(primeiro != NULL)
    {
        No *p = primeiro;
        primeiro= p->getProx();
        delete p;
    }
}
void ListEnc::removeFinal()
{
    if(primeiro!=NULL)
    {
        No *p = primeiro;
        No *aux1, *aux2;

        while(p->getProx())
        {
            p=p->getProx();
            if(p->getProx())
            {
                aux1 = p->getProx();
                aux2= aux1->getProx();
            }
            if(aux2 ==NULL)
            {
                p->setProx(NULL);
                break;
            }
        }
    }
}
void ListEnc::removeK(int k)
{
    if(primeiro!=NULL)
    {
        No *p = primeiro;
        No *aux1, *aux2;
        int cont=1;

        while(p->getProx())
        {
            if(p->getProx())
                {
                    aux1 = p->getProx();
                    aux2= aux1->getProx();
                }

            if(k==1)
            {
                primeiro = p->getProx();
                delete p;
                break;
            }
            else if(k>1 && cont==k-1)
            {
                p->setProx(aux2);
                break;
            }

            p=p->getProx();
            cont++;
        }
    }
}

void ListEnc::insereK(int k, float val)
{
    if(k>0)
    {
     No *p = primeiro;
     No *novo = new No();
     No *aux;
     novo->setInfo(val);
     int cont=1;

        while(p->getProx())
        {
            aux = p->getProx();
            if(k==1)
            {
                primeiro = novo;
                novo->setProx(p);
                break;
            }
            else if(k>1 && cont==k-1)
            {
                p->setProx(novo);
                novo->setProx(aux);
                break;
            }

            p=p->getProx();
            cont++;
        }
    }
}












