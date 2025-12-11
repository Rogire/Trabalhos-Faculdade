#include <iostream>
#include "matrizesDiag.h"
#include "matTS.h"
using namespace std;
int main()
{
    int ord;
    cout<<"Insira a ordem da matriz:"<<endl;
    cin>>ord;
    matTS m(ord);
    for(int i=0; i<ord; i++)
    {
        for(int j=0; j<ord; j++)
        {
            m.set(i,j,j+1);
        }
    }
    cout<<"Matriz triangular preenchida com elementos de 1 a "<<ord<<":"<<endl;
    for(int i=0; i<ord; i++)
    {
        for(int j=0; j<ord; j++)
        {
            cout<<m.get(i,j)<<"\t";
            if(j==ord-1) cout <<endl;
        }
    }

    cout<<endl;
    m.imprime();
    return 0;
}
