#ifndef REGISTRO
#define REGISTRO

#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <string>



class registro
{
private:
    std::string _nome{};
    unsigned _ano{};
    unsigned _ocorrencias{};
    size_t _posicao{};

public:
    registro(std::string nome, unsigned ano, unsigned ocrr);
    ~registro();

    // Getters
    std::string get_nome()const;
    unsigned int get_ano() const;
    unsigned int get_ocorrencias() const;

    // Setters
    void set_nome(const std::string& novo_nome);
    void set_ano(unsigned int novo_ano);
    void set_ocorrencias(unsigned int novas_ocorrencias);
};

#endif /* REGISTRO */