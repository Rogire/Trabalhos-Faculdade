#ifndef TABELA_HASH
#define TABELA_HASH

#include "registro.hpp"

class tabelahash
{
private:
    size_t tamanho;
    registro **tabela;

    size_t hash1(const std::string chave);
    size_t hash2(const std::string chave);

public:
    tabelahash();
    ~tabelahash();

    void insere(std::string nome, unsigned ano, unsigned ocorrencias);
    void imprime_tabela();
    void imprime_maiores_ocorrencias(unsigned x);
    void imprime_maiores_ocorrencias_registros(unsigned x);
    void carrega_arquivo(std::string arquivo_csv);

    registro *pega_registro(std::string nome);
    registro *pega_registro(std::string nome,unsigned ano);

    size_t acha_registro(std::string nome, unsigned ano);
};

#endif /* TABELA_HASH */

