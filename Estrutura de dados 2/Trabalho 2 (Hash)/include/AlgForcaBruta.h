#ifndef AlgForcaBruta_HPP
#define AlgForcaBruta_HPP

#include <string>
#include <vector>
#include <iostream>

class AlgForcaBruta {
public:
    
AlgForcaBruta(){};
    bool buscarPadrao(const std::string &T, const std::string &P); // Busca a primeira ocorrência
    int posicaoPadrao(const std::string &T, const std::string &P); // Busca a primeira ocorrência
};

#endif // AlgForcaBruta_HPP