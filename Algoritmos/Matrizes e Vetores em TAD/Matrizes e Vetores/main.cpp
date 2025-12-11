#include <iostream>
#include "vetorF.h"
#include "Matriz.h"
#include "matrizLin.h"

using namespace std;

int main()
{
    int col, lin, k;
    cout<<"Insira o número de colunas e linhas da matriz: \n";
    cin>>col>>lin;
    matrizLin m(col,lin);

    cout<<"Insira os valores da matriz:"<<endl;
    for(int i=0; i<4; i++)
    {
       for(int j=0; j<3; j++)
       {
            cin>>k;
            m.set(i, j, k);
       }
    }

    for(int i=0; i<4; i++)
    {
       for(int j=0; j<3; j++)
       {
            cout<<m.get(i, j)<<" ";
            if(j==2)
                cout<<endl;
       }
    }
    return 0;
}
