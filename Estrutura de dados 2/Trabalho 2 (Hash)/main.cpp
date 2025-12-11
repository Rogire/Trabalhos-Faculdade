#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <string>
#include <thread>

#include "include/AlgForcaBruta.h"
#include "include/BMH.h"
#include "include/tabelahash.hpp"
#include "include/LZW.h"
#include "include/LZW_IA.h"
#include "include/KMP.h" 
#include "include/RLE.h" 
void Parte1()
{
    tabelahash tabela;

    tabela.carrega_arquivo("../RENAN ANDRADE SOARES COURI - NationalNames.csv");

    std::cout << "Tabela Hash:" << std::endl;
    // tabela.imprime_tabela();

    std::cout << "Top 10 nomes com maiores ocorrências:" << std::endl;
    tabela.imprime_maiores_ocorrencias(10);

    std::cout << "Top 10 registros com maiores ocorrências:" << std::endl;
    tabela.imprime_maiores_ocorrencias_registros(10);
    registro *teste = tabela.pega_registro("Linda", 1947);
    registro *teste2 = tabela.pega_registro("Linda");
    std::cout << std::endl
              << "Nome: " << teste->nome() << std::endl
              << "Ano: " << teste->ano() << "       Ocorrências: " << teste->ocorrencias() << std::endl;
    std::cout << std::endl
              << "Nome: " << teste2->nome() << std::endl
              << "Ano: " << teste2->ano() << "       Ocorrências: " << teste2->ocorrencias() << std::endl;
    registro *teste3 = tabela.pega_registro("iii777", 1993);

    if (teste3 == nullptr)
        std::cout << "iii777 não se encontra" << std::endl;
}

std::string lerArquivoCSV(const std::string &nomeArquivo)
{
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return "";
    }

    std::ostringstream buffer;
    buffer << arquivo.rdbuf(); // Lê todo o conteúdo todo de uma vez
    return buffer.str();
}

void execCadeiaCaracteres() {
    std::string texto = lerArquivoCSV("../RENAN ANDRADE SOARES COURI - NationalNames.csv");
    // Vetor de padrões (exemplos; você pode ajustar conforme seu caso)
    std::vector<std::string> padroes = {
        "Mary", "Romario,2014","aabababbcba","Marianna,1906"
         "1880", ",1986", "Roger,2014",
         "Zyel", "2014", "Jorginho", "2077"
    };

    std::cout << "\n----- Busca de Padrões - Processamento de Cadeia de Caracteres para os três métodos implementados-----\n";
    std::cout<< "Cumprimos a requsição de cada um de ter um no início, fim e um inexistente(Os três primeiros). Também há ouros depois\n";
    // KMP
    std::cout << "\nKMP:" << std::endl;
    KMP kmp;
    for (std::string padrao : padroes) {
        int pos = kmp.posicaoPadrao(texto, padrao);
        if (pos != -1)
            std::cout << "Padrão \"" << padrao << "\" encontrado na posição " << pos << std::endl;
        else
            std::cout << "Padrão \"" << padrao << "\" não encontrado." << std::endl;
    }

    // Força Bruta
    std::cout << "\nForça Bruta:" << std::endl;
    AlgForcaBruta fb;
    for (std::string padrao : padroes) {
        int pos = fb.posicaoPadrao(texto, padrao);
        if (pos != -1)
            std::cout << "Padrão \"" << padrao << "\" encontrado na posição " << pos << std::endl;
        else
            std::cout << "Padrão \"" << padrao << "\" não encontrado." << std::endl;
    }

    // BMH
    std::cout << "\nBMH:" << std::endl;
    BMH bmh;
    for (std::string padrao : padroes) {
        int pos = bmh.posicaoPadrao(texto, padrao);
        if (pos != -1)
            std::cout << "Padrão \"" << padrao << "\" encontrado na posição " << pos << std::endl;
        else
            std::cout << "Padrão \"" << padrao << "\" não encontrado." << std::endl;
    }
}


void execCompressaoArquivos() {
    RLE rle;
    std::string inputFile = "../RENAN ANDRADE SOARES COURI - NationalNames.csv";
    std::string compressedFileBinary = "../compressed_rle_binary.rle";
    std::string decompressedFileBinary = "../decompressed_rle_binary.csv";
    std::string compressedFileString = "../compressed_rle_string.rle";
    std::string decompressedFileString = "../decompressed_rle_string.csv";

    std::cout << "\n##### Execução da Compressão RLE BINÁRIO (pair<char, int>) #####\n";
    rle.compressFile(inputFile, compressedFileBinary);
    rle.decompressFile(compressedFileBinary, decompressedFileBinary);
    std::cout << "Arquivos gerados:\n" << compressedFileBinary << "\n" << decompressedFileBinary << std::endl;

    std::cout << "\n##### Execução da Compressão RLE STRING (a3b4...) #####\n";
    rle.compressFileString(inputFile, compressedFileString);
    rle.decompressFileString(compressedFileString, decompressedFileString);
    std::cout << "Arquivos gerados:\n" << compressedFileString << "\n" << decompressedFileString << std::endl;
}

// Menu da Execução Principal da Parte 2
void menuExecucaoParte2() {
    int opcao;
    std::cout << "\n=== Execução Principal - Parte 2 ===\n";
    std::cout << "Selecione:\n1 - Processamento de Cadeia de Caracteres\n2 - Compressão de Arquivos\n";
    std::cin >> opcao;
    if (opcao == 1) {
        execCadeiaCaracteres();
    } else if (opcao == 2) {
        execCompressaoArquivos();
    } else {
        std::cout << "Opção inválida.\n";
    }
}


// Medição dos tempos de processamento de cadeia de caracteres
void medirTemposCadeia() {
    std::string padroesProcura[] = {"Marianna,1906",
        "Romario,2014",
        "aabbaabbaabbaabb",
        "Ota",
        ",1986", 
        "-/,",
        "1664226,Addeline,2010,F,19",
        "xkz.;-=09pxdf%<>trkqwl8*5$",
        "aaaa"
    };
    std::string texto = lerArquivoCSV("../RENAN ANDRADE SOARES COURI - NationalNames.csv");
    std::ofstream resultados("tempos_execucao_medias_cadeia.csv");
    resultados << "Algoritmo,Caso,Media_Tempo(s)\n";
    const int repeticoes = 25;

    // KMP
    for (int i = 0; i < 9; i++) {
        double somaTempo = 0.0;
        KMP kmp;
        for (int j = 0; j < repeticoes; j++) {
            auto inicio = std::chrono::steady_clock::now();
            kmp.buscarPadrao(texto, padroesProcura[i]);
            auto fim = std::chrono::steady_clock::now();
            somaTempo += std::chrono::duration<double>(fim - inicio).count();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        double media = somaTempo / repeticoes;
        std::cout << "KMP para padrão " << padroesProcura[i] << ": Média de " << media << " segundos.\n";
        resultados << "KMP,Padrão " << padroesProcura[i]  << ", " << std::fixed << std::setprecision(8) << media << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    // Força Bruta
    for (int i = 0; i < 9; i++) {
        double somaTempo = 0.0;
        AlgForcaBruta fb;
        for (int j = 0; j < repeticoes; j++) {
            auto inicio = std::chrono::steady_clock::now();
            fb.buscarPadrao(texto, padroesProcura[i]);
            auto fim = std::chrono::steady_clock::now();
            somaTempo += std::chrono::duration<double>(fim - inicio).count();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        double media = somaTempo / repeticoes;
        std::cout << "Força Bruta para padrão " << padroesProcura[i]  << ": Média de " << media << " segundos.\n";
        resultados << "Força Bruta,Padrão " << padroesProcura[i]  << ", " << std::fixed << std::setprecision(8) << media << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    // BMH
    for (int i = 0; i < 9; i++) {
        double somaTempo = 0.0;
        BMH bmh;
        for (int j = 0; j < repeticoes; j++) {
            auto inicio = std::chrono::high_resolution_clock::now();
            bmh.buscarPadrao(texto, padroesProcura[i]);
            auto fim = std::chrono::high_resolution_clock::now();
            somaTempo += std::chrono::duration<double>(fim - inicio).count();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        double media = somaTempo / repeticoes;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "BMH para padrão " << padroesProcura[i]  << ": Média de " << media << " segundos.\n";
        resultados << "BMH,Padrão " << padroesProcura[i] << ", " << std::fixed << std::setprecision(8) << media << "\n";
    }
    resultados.close();
    std::cout << "\nTestes de média (cadeia) finalizados. Resultados gravados em 'tempos_execucao_medias_cadeia.csv'.\n";
}

// Medição dos tempos de compressão e descompressão (usando RLE)
void medirTemposCompressao() {
    RLE rle;
    std::string inputFile = "../RENAN ANDRADE SOARES COURI - NationalNames.csv";
    std::string compressedFileBinary = "../compressed_rle_binary.rle";
    std::string decompressedFileBinary = "../decompressed_rle_binary.csv";
    std::string compressedFileString = "../compressed_rle_string.rle";
    std::string decompressedFileString = "../decompressed_rle_string.csv";

    const int repeticoes = 25;
    std::ofstream resultados("tempos_execucao_medias_compressao.csv");
    resultados << "Metodo,Operacao,Media_Tempo(s)\n";

    double somaCompressBinary = 0.0, somaDecompressBinary = 0.0;
    for (int i = 0; i < repeticoes; i++) {
        auto inicio = std::chrono::high_resolution_clock::now();
        rle.compressFile(inputFile, compressedFileBinary);
        auto fim = std::chrono::high_resolution_clock::now();
        somaCompressBinary += std::chrono::duration<double>(fim - inicio).count();

        inicio = std::chrono::high_resolution_clock::now();
        rle.decompressFile(compressedFileBinary, decompressedFileBinary);
        fim = std::chrono::high_resolution_clock::now();
        somaDecompressBinary += std::chrono::duration<double>(fim - inicio).count();
    }
    double mediaCompressBinary = somaCompressBinary / repeticoes;
    double mediaDecompressBinary = somaDecompressBinary / repeticoes;
    std::cout << "RLE Binário - Compressão: " << mediaCompressBinary << " s, Descompressão: " << mediaDecompressBinary << " s.\n";
    resultados << "RLE Binário,Compressão," << std::fixed << std::setprecision(8) << mediaCompressBinary << "\n";
    resultados << "RLE Binário,Descompressão," << std::fixed << std::setprecision(8) << mediaDecompressBinary << "\n";

    double somaCompressString = 0.0, somaDecompressString = 0.0;
    for (int i = 0; i < repeticoes; i++) {
        auto inicio = std::chrono::high_resolution_clock::now();
        rle.compressFileString(inputFile, compressedFileString);
        auto fim = std::chrono::high_resolution_clock::now();
        somaCompressString += std::chrono::duration<double>(fim - inicio).count();

        inicio = std::chrono::high_resolution_clock::now();
        rle.decompressFileString(compressedFileString, decompressedFileString);
        fim = std::chrono::high_resolution_clock::now();
        somaDecompressString += std::chrono::duration<double>(fim - inicio).count();
    }
    double mediaCompressString = somaCompressString / repeticoes;
    double mediaDecompressString = somaDecompressString / repeticoes;
    std::cout << "RLE String - Compressão: " << mediaCompressString << " s, Descompressão: " << mediaDecompressString << " s.\n";
    resultados << "RLE String,Compressão," << std::fixed << std::setprecision(8) << mediaCompressString << "\n";
    resultados << "RLE String,Descompressão," << std::fixed << std::setprecision(8) << mediaDecompressString << "\n";

    resultados.close();
    std::cout << "\nTestes de média (compressão) finalizados. Resultados gravados em 'tempos_execucao_medias_compressao.csv'.\n";
}

// Menu para a Medição de Tempos da Parte 2
void execMedicaoTempos() {
    int opcao;
    std::cout << "\n=== Medição de Tempos - Parte 2 ===\n";
    std::cout << "Selecione:\n1 - Medição de Processamento de Cadeia de Caracteres\n2 - Medição de Compressão de Arquivos\n";
    std::cin >> opcao;
    if (opcao == 1)
        medirTemposCadeia();
    else if (opcao == 2)
        medirTemposCompressao();
    else
        std::cout << "Opção inválida.\n";
}


// Menu da Parte 2 - Segundo Menu (Execução Principal ou Medição de Tempos)
void Parte2() {
    int escolha;
    std::cout << "\n=== Parte 2 do Trabalho ===\n";
    std::cout << "Selecione:\n1 - Execução Principal\n2 - Medição de Tempos\n";
    std::cin >> escolha;
    if (escolha == 1) {
        int subOpcao;
        std::cout << "\nSelecione:\n1 - Processamento de Cadeia de Caracteres\n2 - Compressão de Arquivos\n";
        std::cin >> subOpcao;
        if (subOpcao == 1)
            execCadeiaCaracteres();
        else if (subOpcao == 2)
            execCompressaoArquivos();
        else
            std::cout << "Opção inválida.\n";
    } else if (escolha == 2) {
        execMedicaoTempos();
    } else {
        std::cout << "Opção inválida.\n";
    }
}


// Menu Principal
void Menu() {
    int sel = -1;
    std::cout << "\n=== Menu Principal ===\n";
    std::cout << "Selecione a parte do trabalho:\n1 - Parte 1\n2 - Parte 2\n0 - Sair\n";
    std::cin >> sel;
    switch (sel) {
        case 1:
            std::cout << "\nIniciando Parte 1...\n";
            Parte1();
            break;
        case 2:
            std::cout << "\nIniciando Parte 2...\n";
            Parte2();
            break;
        case 0:
            std::cout << "\nOperação finalizada.\n";
            return;
        default:
            std::cout << "\nOpção inválida.\n";
            break;
    }
    Menu();
}

int main() {
    Menu();
    return 0;
}
