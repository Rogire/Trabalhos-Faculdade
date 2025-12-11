#include <string>
#include <vector>
#include <iostream>

#include "tabelahash.hpp"

// Construtor
tabelahash::tabelahash(size_t tam)
{
    this->tamanho = tam;
    tabela = new registro *[this->tamanho];

    for (size_t i = 0; i < this->tamanho; ++i)
        tabela[i] = nullptr;

    std::cout << "TAMANHO : -----------------  " << this->tamanho << "\n";
}

// Destrutor
tabelahash::~tabelahash()
{
    for (size_t i = 0; i < tamanho; ++i)
    {
        if (tabela[i] != nullptr)
            delete tabela[i];
    }
    delete[] tabela;
}

// passagens de referências constantes nas funções para otimizar o uso de memória em larga escala
size_t tabelahash::hash_function(const std::string &str, const size_t &mod, const int& base) // usando hash de string
{
    size_t HashValue = 0;

    for (char c : str)
        HashValue += HashValue * base + static_cast<unsigned long long>(c) % mod;

    return HashValue;
}

size_t tabelahash::sondagemDupla(const int &i, const size_t &h1, const size_t &h2)
{
    return ((h1) + (i * h2)) % this->tamanho;
}

// Insere um registro na tabela hash .
void tabelahash::insere(std::string &nome, unsigned &ano, unsigned &ocorrencias)
{
    int i = 0, base = 31;
    size_t cCol{0},  mod = 1e9+7, m{this->tamanho}, m2{this->tamanho - 1};

    //calcula o indice usando a função hash de acordo com a sondagem dupla, usando o hash de string, e mod indicados
    size_t h1{hash_function(nome, mod,base) % m}, h2{1 + (hash_function(nome, mod, base) % m2)};
    size_t indice{sondagemDupla(i, h1, h2)};

    while (tabela[indice] != nullptr)
    {
        indice = sondagemDupla(++i, h1, h2);
        ++cCol;
    }
    
    this->numColisoes += cCol;
    tabela[indice] = new registro(nome, ano, ocorrencias);
}

void tabelahash::imprime_tabela()
{
    std::cout << std::left
              << std::setw(10) << "ID"
              << std::setw(15) << "Nome"
              << std::setw(10) << "Ano"
              << std::setw(10) << "Ocorrências"
              << '\n';

    std::cout << "----------------------------------------------------\n";

    for (size_t i = 0; i < tamanho; ++i)
    {
        if (tabela[i] != nullptr)
        {
            std::cout << std::left
                      << std::setw(10) << i
                      << std::setw(15) << tabela[i]->get_nome()
                      << std::setw(10) << tabela[i]->get_ano()
                      << std::setw(10) << tabela[i]->get_ocorrencias()
                      << '\n';
        }
    }
    std::cout <<"\n"<< std::setw(15)<< "Número de colisões na montagem: " << numColisoes << '\n'<<"A tabela foi alocada usando " << this->tamanho << " posições\n" 
    << "Algumas colisões poderiam ter sido evitadas usando hashing extensível(aumentando o tamanho da tabela), mas o menor número de posições na tabela foi priorizado.\n";
}

void tabelahash::contar_ocorrencias(size_t X)
{
    std::unordered_map<std::string, size_t> contagem_nomes;

    // Soma ocorrências por nome
    for (size_t i = 0; i < tamanho; ++i)
    {
        if (tabela[i] != nullptr)
        {
            std::string nome = tabela[i]->get_nome();
            contagem_nomes[nome] += tabela[i]->get_ocorrencias();
        }
    }

    // Criando um vetor de pares (nome, ocorrências)
    std::vector<std::pair<std::string, size_t>> vetor_contagem(contagem_nomes.begin(), contagem_nomes.end());

    // Ordena o vetor em ordem decrescente (parâmetros são iterators e uma função lambda)
    std::sort(vetor_contagem.begin(), vetor_contagem.end(), [](const auto &a, const auto &b)
              { return a.second > b.second; });

    std::cout << "\n----- Os " << X << " nomes mais repetidos -----\n\n";

    for (size_t i = 0; i < X && i < vetor_contagem.size(); ++i)
    {
        std::cout << std::setw(5)<< "Nome: " << vetor_contagem[i].first
                  << ", "<<std::setw(15)<< "Ocorrencias: " << vetor_contagem[i].second << '\n';
    }
}

//retorna o registro passado, caso ele esteja na tabela
registro *tabelahash::pega_registro(std::string nome, unsigned ano, unsigned ocorrencias)
{
    int i = acha_registro(nome, ano, ocorrencias);
    if (i == -1)
        return nullptr; //  Registro não encontrado

    return tabela[i];
}

//acha o registro indicado a partir dos dados passados
size_t tabelahash::acha_registro(std::string nome, unsigned ano, unsigned ocorrencias)
{
    int i {0}, base{31};
    size_t mod = 1e9+7, m{this->tamanho}, m2{this->tamanho - 1};

    size_t h1{hash_function(nome, mod, base) % m}, h2{1 + (hash_function(nome, mod, base) %m2)};
    size_t indice{sondagemDupla(i, h1, h2)};

    while (tabela[indice]->get_nome() != nome || tabela[indice]->get_ano() != ano || tabela[indice]->get_ocorrencias() != ocorrencias)
    {
        indice = sondagemDupla(++i, h1, h2);

        if (indice >= this->tamanho || tabela[indice] == nullptr)
            return -1;
    }

    return indice;
}

//acha o registro indicado a partir do índice
registro* tabelahash::pega_registro(size_t i)
{
    if (i >= this->tamanho || i<0)
        return nullptr;

    return tabela[i];
}