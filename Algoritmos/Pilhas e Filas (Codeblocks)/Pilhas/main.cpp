#include <iostream>
#include "PilhaCont.h"
#include "PilhaEncad.h"
using namespace std;

int main()
{
    PilhaEncad p;

    p.empilhar(7);
    p.empilhar(3);
    p.empilhar(4);
    p.empilhar(11);
    p.empilhar(5);
    p.empilhar(9);


    p.imprime();

    p.desempilhar();
    p.desempilhar();
    p.desempilhar();
    p.desempilhar();
    p.imprime();
    return 0;
}
