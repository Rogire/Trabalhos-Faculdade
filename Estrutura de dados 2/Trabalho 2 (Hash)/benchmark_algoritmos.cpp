#include <benchmark/benchmark.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// Seus includes
#include "include/KMP.h"
#include "include/BMH.h"
#include "include/AlgForcaBruta.h"

// Função para ler o CSV com verificação de erro
std::string lerArquivoCSV(const std::string &nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        exit(1); // Encerra o programa ao falhar na leitura
    }
    std::ostringstream buffer;
    buffer << arquivo.rdbuf();
    return buffer.str();
}

// ------------------------ Variáveis Globais ----------------------------

// Inicialização de variáveis globais
std::string texto;
std::string padraoIni1 = "1664226,Addeline,2010,F,19";  // Padrão no início
std::string padraoFim1= "xkz.;-=09pxdf%<>trkqwl8*5$";
std::string padraoFim2 = "1111";                             // Padrão no meio
std::string padraoInex1 = "1111";              // Padrão inexistente

// Função para inicializar o texto antes de qualquer benchmark
void inicializarTexto() {
    texto = lerArquivoCSV("../RENAN ANDRADE SOARES COURI - NationalNames.csv");
    if (texto.empty()) {
        std::cerr << "O arquivo foi lido, mas está vazio. Verifique o conteúdo." << std::endl;
        exit(1);
    }
}


// ------------------------ Força Bruta Benchmarks ----------------------------

// Força Bruta com padrão no início
static void BM_FB_Ini(benchmark::State &state) {
    for (auto _ : state) {
        auto result = AlgForcaBruta().buscarPadrao(texto, padraoIni1);
        
    }
}
BENCHMARK(BM_FB_Ini)->Unit(benchmark::kNanosecond);

// Força Bruta com padrão no final
static void BM_FB_Fim(benchmark::State &state) {
    for (auto _ : state) {
        auto result = AlgForcaBruta().buscarPadrao(texto, padraoFim1);
       
    }
}
BENCHMARK(BM_FB_Fim)->Unit(benchmark::kNanosecond);

// Força Bruta com padrão inexistente
static void BM_FB_Inex(benchmark::State &state) {
    for (auto _ : state) {
        auto result = AlgForcaBruta().buscarPadrao(texto, padraoInex1);
        
    }
}
BENCHMARK(BM_FB_Inex)->Iterations(20)->Unit(benchmark::kNanosecond);

// ------------------------ KMP Benchmarks ----------------------------

// KMP com padrão no início
static void BM_KMP_Ini(benchmark::State &state) {
    for (auto _ : state) {
        auto result = KMP().buscarPadrao(texto, padraoIni1);
        
    }
}
BENCHMARK(BM_KMP_Ini)->Unit(benchmark::kNanosecond);

// KMP com padrão no final
static void BM_KMP_Fim(benchmark::State &state) {
    for (auto _ : state) {
        auto result = KMP().buscarPadrao(texto, padraoFim1);
        
    }
}
BENCHMARK(BM_KMP_Fim)->Unit(benchmark::kNanosecond);

// KMP com padrão inexistente
static void BM_KMP_Inex(benchmark::State &state) {
    for (auto _ : state) {
        auto result = KMP().buscarPadrao(texto, padraoInex1);
        
    }
}
BENCHMARK(BM_KMP_Inex)->Unit(benchmark::kNanosecond);

// ------------------------ BMH Benchmarks ----------------------------

// BMH com padrão no início

static void BM_BMH_Ini(benchmark::State &state) {
    for (auto _ : state) {
        auto result = BMH().buscarPadrao(texto, padraoIni1);
       
    }
}
BENCHMARK(BM_BMH_Ini)->Unit(benchmark::kNanosecond);

// BMH com padrão no final
static void BM_BMH_Fim(benchmark::State &state) {
    for (auto _ : state) {
        auto result = BMH().buscarPadrao(texto, padraoFim1);
       
    }
}
BENCHMARK(BM_BMH_Fim)->Unit(benchmark::kNanosecond);

// BMH com padrão inexistente
static void BM_BMH_Inex(benchmark::State &state) {
    for (auto _ : state) {
        auto result = BMH().buscarPadrao(texto, padraoInex1);
        
    }
}
BENCHMARK(BM_BMH_Inex)->Iterations(25)->Unit(benchmark::kNanosecond);


// ------------------------ Main com Inicialização ----------------------------

int main(int argc, char **argv) {
    inicializarTexto(); // Garante leitura antes dos benchmarks
    ::benchmark::Initialize(&argc, argv);
    ::benchmark::RunSpecifiedBenchmarks();
    
    return 0;
}
