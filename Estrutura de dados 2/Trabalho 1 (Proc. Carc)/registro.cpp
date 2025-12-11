#include <string>
#include "registro.hpp" 
// Construtor
registro::registro(std::string nome, unsigned ano, unsigned ocrr) : _nome(nome), _ano(ano), _ocorrencias(ocrr)
{}


// Destrutor
registro::~registro() {}

// Getters
std::string registro::get_nome() const { return this->_nome; }
unsigned int registro::get_ano() const { return this->_ano;}
unsigned int registro::get_ocorrencias() const { return this->_ocorrencias; }

// Setters
void registro::set_nome(const std::string& novo_nome) { this->_nome = novo_nome;}
void registro::set_ano(unsigned int novo_ano) {this->_ano = novo_ano; }
void registro::set_ocorrencias(unsigned int novas_ocorrencias) { this->_ocorrencias = novas_ocorrencias; }
