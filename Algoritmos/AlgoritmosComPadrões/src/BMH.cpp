#include "../include/BMH.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int *BMH::Pref(const std::string &strBusca)
{
    int tamPadrao = strBusca.size();
    int *tabela = new int[256];

    for (int i = 0; i < 256; i++)
        tabela[i] = tamPadrao - 1;

    for (int i = 0; i < tamPadrao - 1; i++)
        tabela[static_cast<unsigned char>(strBusca[i])] = tamPadrao - 1 - i; // Correção importante

    return tabela;
}

void BMH::Busca(const std::string &strArq, const std::string &strBusca, bool imp)
{
    int len = strBusca.length(), tamanhoInd = len - 1, pos{0}, i{tamanhoInd}, k{};
    size_t lenCSV{strArq.length()};
    int *cPos = Pref(strBusca);

    while (i < lenCSV)
    {
        k = 0;
        while (k < len && strBusca[len - 1 - k] == strArq[i - k])
            k++;

        if (k == len)
            break;

        i += cPos[(strArq[i])];
    }

    if (imp)          // se necessário pode-se remover a impressão para benchmarks
        if (k == len) // não teve diferença
        {
            std::cout << "O prefixo foi encontrado entre as posições [" << i+k << " , " << i+2*len << "]\n";
            return;
        }
        else
        {
            std::cout << "O prefixo não foi encontrado no documento\n";
            return;
        }
}
