#include <iostream>
#include "ListCont.h"
#include "ListEnc.h"
using namespace std;

int main()
{
    int esc;
    cout<<"Escolha 1 para lista contígua, ou 2 para lista encadeada\n";
    cin>>esc;
    while(esc != 0)
    {
        if(esc == 1)
        {
            int t,op,pos=0;
            float val=0;
            cout<<"LISTA CONTÍGUA:\n";
            cout<<"Insira o tamanho da lista:\n";
            cin>>t;
            ListCont l(t);

            cout<<"Operações:\n"<<"Adicionar ao final da lista: 1\n";
            cout<<"Remover ao final da lista: 2\n"<<"Remover ao inicio da lista: 3\n";
            cout<<"Adicionar em qualquer posição da lista: 4\n"<<"Remover em qualquer posição da lista: 5\n";
            cout<<"Mudar o valor de um item da lista: 6\n"<<"Imprimir a lista: 7\n"<<"Sair: 0 \n";
            cout<<"Selecione a operação desejada:\n";
            cin>>op;
            while(op!=0)
            {
            switch (op)
            {
                case 1:
                    cout<<"Selecione o valor que deseja inserir:\n";
                    cin>>val;
                    l.insereFinal(val);
                    break;
                case 2:
                    l.removeFinal();
                    break;
                case 3:
                    l.removeK(1);
                    break;
                case 4:
                    cout<<"Selecione o valor, e a posição em que deseja adicionar:\n";
                    cin>>val>>pos;
                    l.insereK(pos,val);
                    break;
                case 5:
                    cout<<"Selecione a posição que deseja remover:\n";
                    cin>>val;
                    l.removeK(val);
                    break;
                case 6:
                    cout<<"Selecione o valor, e a posição que deseja alterar:\n";
                    cin>>val>>pos;
                    l.set(pos,val);
                    break;
                case 7:
                    l.imprime();
                    break;
            }
            cout<<"Selecione a nova operação\n";
            cin>>op;
        }
        }
        else if(esc == 2)
        {
            cout<<"LISTA ENCADEADA\n";
            int op,pos=0;
            float val=0;
            ListEnc lis;
            cout<<"Operações:\n"<<"Adicionar ao final da lista: 1\n";
            cout<<"Remover ao final da lista: 2\n"<<"Remover ao inicio da lista: 3\n";
            cout<<"Adicionar em qualquer posição da lista: 4\n"<<"Remover em qualquer posição da lista: 5\n";
            cout<<"Imprimir a lista: 6\n"<<"Sair: 0 \n";
            cout<<"Selecione a operação desejada:\n";
            cin>>op;

            while(op!=0)
            {
                if(op==0)
                    break;
                switch (op)
                {
                    case 1:
                        cout<<"Selecione o valor que deseja inserir:\n";
                        cin>>val;
                        lis.insereFinal(val);
                        break;
                    case 2:
                        lis.removeFinal();
                        break;
                    case 3:
                        lis.removeInicio();
                        break;
                    case 4:
                        cout<<"Selecione o valor, e a posição em que deseja adicionar:\n";
                        cin>>val>>pos;
                        lis.insereK(pos,val);
                        break;
                    case 5:
                        cout<<"Selecione a posição que deseja remover:\n";
                        cin>>val;
                        lis.removeK(val);
                        break;
                    case 6:
                        lis.imprime();
                        break;
                }
                cout<<"Selecione a nova operação\n";
                cin>>op;
            }
        }
    }
    return 0;
}
