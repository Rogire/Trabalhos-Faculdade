#include <iostream>
#include <fstream>
#include <sstream>
#include <string>   

#include "tabelahash.hpp"

void carregar_csv(const std::string& caminho_csv, tabelahash& tabela)
{
    std::ifstream arquivo(caminho_csv); // Abre o arquivo para leitura
    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo: " << caminho_csv << "\n";
        return;
    }
    int i{0};
    std::cout << "Arquivo aberto com sucesso: " << "\n";

    std::string id_str{}, nome{}, ano_str{}, genero_str{}, cont_str{};
    unsigned ano{}, cont{};
    std::string linha;
    // Ignorar a primeira linha (cabe�alho)
    std::getline(arquivo, linha);

    while (std::getline(arquivo, linha) &&  i<tabela.getTamanho()) // L� linha por linha
    {
        std::stringstream ss(linha); // Cria um stringstream a partir da linha
        

        // Ler as colunas e ignorar as desnecess�rias
        if (std::getline(ss, id_str, ',') &&     // Ignorar ID
            std::getline(ss, nome, ',') &&       // Nome
            std::getline(ss, ano_str, ',') &&    // Ano
            std::getline(ss, genero_str, ',') && // Ocorr�ncias
            std::getline(ss, cont_str, ','))
        { // Ignorar g�nero

            // Converter ano e ocorr�ncias para inteiros
            ano = std::stoi(ano_str);
            cont = std::stoi(cont_str);

            
            tabela.insere(nome, ano, cont);
        }
        i++;
    }
    arquivo.close();
    std::cout << "Arquivo carregado para a tabela hash com sucesso";
}

size_t getTamanhoDataSet(const std::string &caminho_csv)
{
    std::ifstream arquivo(caminho_csv); // Abre o arquivo para leitura
    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo: " << caminho_csv << "\n";
        return -1;
    }
    size_t i{0};
    std::cout << "Arquivo aberto com sucesso: " << "\n";

    std::string linha;
    // Ignorar a primeira linha (cabe�alho)
    std::getline(arquivo, linha);

    while (std::getline(arquivo, linha)) // L� linha por linha
        i++;
    
    arquivo.close();
    return i;
}

int main()
{ 
    std::string caminho_csv = "/mnt/c/Users/igort/OneDrive/Documentos/Repo_GitHub/atividade-sobre-hash-despreparados/GUSTAVO DUARTE FERNANDES DE JESUS - NationalNames.csv"; // Substitua pelo caminho correto do seu arquivo CSV

    size_t tamTabe{getTamanhoDataSet(caminho_csv)};
    tabelahash tabela(tamTabe);
    carregar_csv(caminho_csv, tabela);

    std::cout << "\nTabela Hash completa:" << std::endl;
    tabela.imprime_tabela();
    
    //Pega registro( a funcao acha registro esta sendo utilizada na funcao pega registro)
    registro* t = tabela.pega_registro("Mishayla", 2008, 5);
    registro* t2 = tabela.pega_registro(6000);

    if (t == nullptr || t2 == nullptr) 
        std::cerr << "Registro não encontrado" << std::endl;
    else 
    {
        std::cout<<std::endl<<"Registro Procurado(dados): ";
        std::cout<<t->get_nome()<<"   "<<t->get_ano()<<"   "<<t->get_ocorrencias()<<std::endl;

        std::cout << std::endl<< "Registro Procurado(índice): ";
        std::cout << t2->get_nome() << "   " << t2->get_ano() << "   " << t2->get_ocorrencias() << std::endl;
    }   

    std::cout<<std::endl;
    tabela.contar_ocorrencias(20);
    return 0;
}
