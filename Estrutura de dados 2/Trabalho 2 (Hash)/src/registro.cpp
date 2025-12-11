#include "../include/registro.hpp"

registro::registro(std::string nome, unsigned ano, unsigned ocorrencias)
{
    _nome = nome;
    _ano = ano;
    _ocorrencias = ocorrencias;
    _posicao = -1;
}
registro::~registro() {}

void registro::set_posicao(size_t posicao)
{
    _posicao = posicao;
}

std::string registro::nome()
{
    return _nome;
}

unsigned registro::ano()
{
    return _ano;
}

unsigned registro::ocorrencias()
{
    return _ocorrencias;
}

size_t registro::posicao()
{
    return _posicao;
}



