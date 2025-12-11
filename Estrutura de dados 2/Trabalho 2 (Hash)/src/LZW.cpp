#include "../include/LZW.h"
#include <algorithm>
#include <fstream>
#include <iostream>

LZW::LZW()
{
    for (int i = 0; i <=255; i++) //inicializa a tabela a partir do espaço
    {
        char c=i;
        std::string *s = new std::string(1,c);
        tabela.push_back(s);// transforma os char em string
    }
}

LZW::~LZW()
{
}

std::vector<int> LZW::Comprimir(std::string arqPath)
{
    std::vector<int> *posicoes = new std::vector<int>();
    std::string prefixo("");
    prefixo += arqPath.at(0);
    char proximo;
    int local = -1;

    for (int i = 1; i < arqPath.length(); i++)
    {
        std::cout<<"valor I"<<i<<std::endl;
        bool existe = false;
        proximo = arqPath.at(i);

        for (int j = 0; j < tabela.size(); j++)
        {
           
            if (*tabela.at(j) == prefixo + proximo)
            {
                existe = true;
                break;
            }
        }

        if (existe)
        {
            prefixo += proximo;
        }
        else
        {
            for (int x = 0; x <tabela.size(); x++)
            {
          
                if (*tabela.at(x) == prefixo)
                {
                    local = x;
                    break;
                }
            }

            if (local != -1)
            {
                posicoes->push_back(local);
                tabela.push_back(new std::string(prefixo + proximo));
                prefixo = proximo;
                local = -1; // Reset local after use
            }
        }
       

    }
    char a=arqPath.at((arqPath.size()-1));
    posicoes->push_back(a);
    return *posicoes;
}
std::string LZW::Descomprimir(std::vector<int> posicoes)
{
    std::string *arquivodescomprimido = new std::string();
    for(int i=0;i<posicoes.size();i++)
    {
        *arquivodescomprimido += *tabela.at(posicoes[i]);
    }
    return *arquivodescomprimido;
}
void LZW::Salvar(std::vector<int> *posicoes)
{
    std::ofstream outfile ("LZW.txt",std::ios::binary);
    for(int i=0;i<posicoes->size();i++)
    {
        outfile<<(posicoes->at(i))<<",";
    }
    outfile.close();
}
