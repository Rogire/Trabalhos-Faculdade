#ifndef PADROES_H
#include <vector>
#include<string>
#include<iostream>
#include "BMH.h"

class Padroes
{
private:
    BMH bmh;

public:
    Padroes(){};
    ~Padroes(){};

    void ordena(std::vector<std::string> *palavras);
    void Buscar(std::string strDt, std::string strB) { this->bmh.Busca(strDt, strB, true); }
};

#endif // !PADROES_H