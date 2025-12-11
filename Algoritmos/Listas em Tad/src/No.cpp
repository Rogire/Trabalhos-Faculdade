#include "No.h"
#include <cstddef>
No::No()
{
   prox=NULL;
}

No::~No()
{

}

int No::getinfo()
{
return info;
}

void No::setInfo(float val)
{
    info=val;
}
void No::setProx(No *p)
{
    prox = p;
}

No* No::getProx()
{
return prox;
}
