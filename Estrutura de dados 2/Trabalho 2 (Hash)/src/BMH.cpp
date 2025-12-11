#include "../include/BMH.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<int> BMH::tabelaDeslocamentos(const std::string &padrao, int tamAlfabeto)
{
    int tamPadrao = padrao.size();
    std::vector<int> tabela(tamAlfabeto);
    for (int i = 0; i < tamAlfabeto; i++)
    {
        tabela[i] = tamPadrao - 1;
    }
    for (int i = 0; i < tamPadrao - 1; i++)
    {
        tabela[static_cast<unsigned char>(padrao[i])] = tamPadrao - 1 - i; // Correção importante
    }
    return tabela;
}

int BMH::posicaoPadrao(const std::string &texto, const std::string &padrao)
{
    int tamTexto = texto.size();
    int tamPadrao = padrao.size();
    if (tamPadrao == 0 || tamTexto == 0)
        return -1;

    int tamAlfabeto = 256;
    std::vector<int> tabela = tabelaDeslocamentos(padrao, tamAlfabeto);
    int i = tamPadrao - 1;
    while (i < tamTexto)
    {
        int k = 0;
        while (k < tamPadrao && padrao[tamPadrao - 1 - k] == texto[i - k])
            k++;
        if (k == tamPadrao)
        {
            return i - tamPadrao + 1;
        }
        i += tabela[(texto[i])];
    }
    return -1;
}
bool BMH::buscarPadrao(const std::string &texto, const std::string &padrao)
{
    int tamTexto = texto.size();
    int tamPadrao = padrao.size();
    if (tamPadrao == 0 || tamTexto == 0)
        return -1;

    int tamAlfabeto = 256;
    std::vector<int> tabela = tabelaDeslocamentos(padrao, tamAlfabeto);
    int i = tamPadrao - 1;
    while (i < tamTexto)
    {
        int k = 0;
        while (k < tamPadrao && padrao[tamPadrao - 1 - k] == texto[i - k])
            k++;
        if (k == tamPadrao)
        {
            return true;
        }
        i += tabela[(texto[i])];
    }
    return false;
}