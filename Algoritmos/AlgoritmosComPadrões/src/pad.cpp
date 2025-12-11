#include "../include/pad.h"

using std::string;
using std::vector;

void Padroes::ordena(std::vector<string> *palavras)
{
    for (int i{0}; i < palavras->size() - 1; i++)
    {
        for (int j{i + 1}; j < palavras->size(); j++)
        {
            if ((*palavras)[j] < (*palavras)[i])
            {
                string aux = (*palavras)[i];
                (*palavras)[i] = (*palavras)[j];
                (*palavras)[j] = aux;
            }
        }
    }
}
