#ifndef REGISTRO
#define REGISTRO

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstddef>

class registro
{
private:
    std::string _nome;
    unsigned _ano;
    unsigned _ocorrencias;
    size_t _posicao;

public:
    registro(std::string nome, unsigned ano, unsigned ocorrencias);
    ~registro();

    void set_posicao(size_t posicao);

    std::string nome();
    unsigned ano();
    unsigned ocorrencias();
    size_t posicao();
};

#endif /* REGISTRO */
