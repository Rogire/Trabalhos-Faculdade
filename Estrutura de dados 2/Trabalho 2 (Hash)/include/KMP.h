#ifndef KMP_HPP
#define KMP_HPP

#include <string>
#include <vector>
#include <iostream>

class KMP {
public:
   
    KMP(){};
    bool buscarPadrao(const std::string &texto, const std::string &padrao) const; // Busca a primeira ocorrência e retorna se ela está ou não
    void imprimeOcorrencias(const std::string &texto, const std::string &padrao) const; // Imprime todas as ocorrências.
    int posicaoPadrao(const std::string &texto, const std::string &padrao) const; // Busca a primeira ocorrência sua posição

private:
    
    std::vector<int> funcaoPrefixo(const std::string &padrao) const;
};

#endif // KMP_HPP