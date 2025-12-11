#ifndef TABELA_HASH
#define TABELA_HASH
#include <iostream>
#include <string>
#include "registro.hpp"


class tabelahash
{
private:
    size_t tamanho{};
    registro** tabela{};
    size_t numColisoes{0};

    size_t hash_function(const std::string &strnome, const size_t& t, const int& base);
    size_t sondagemDupla (const int& i, const size_t &h1, const size_t &h2);

public:
    tabelahash(size_t tam);
    ~tabelahash();
    size_t getTamanho() { return tamanho; };
    void insere(std::string& nome, unsigned& ano, unsigned& ocorrencias);
    void imprime_tabela();
    void contar_ocorrencias(size_t X);

    registro *pega_registro(std::string nome, unsigned ano, unsigned ocorrencias);
    registro *pega_registro(size_t i);
    size_t acha_registro(std::string nome, unsigned ano, unsigned ocorrencias);
};

#endif /* TABELA_HASH */