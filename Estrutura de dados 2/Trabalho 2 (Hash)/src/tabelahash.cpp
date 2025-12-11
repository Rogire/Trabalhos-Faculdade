#include "../include/tabelahash.hpp"
#include "../include/registro.hpp"
#include <cmath>
#include <unordered_map>

const size_t TAMANHO = 1e9 + 7;
const size_t MOD = 1e9 + 7;
const size_t BASE = 31;
const size_t INDICE_INVALIDO = std::numeric_limits<size_t>::max();

tabelahash::tabelahash()
{
    tabela = new registro *[TAMANHO];
    tamanho=TAMANHO;
    for (size_t i = 0; i < TAMANHO; ++i)
        tabela[i] = nullptr;
}

tabelahash::~tabelahash()
{
    for (size_t i = 0; i < tamanho; ++i) {
        delete tabela[i];
    }
    delete[] tabela;
}

size_t tabelahash::hash1(const std::string chave)
{
    size_t hashValue = 0;
    for (char c : chave)
        hashValue = (hashValue * BASE + static_cast<unsigned long long>(c)) % MOD;
    return hashValue;
}

size_t tabelahash::hash2(const std::string chave) {
    size_t hashValue = 0;
    for (char c : chave)
        hashValue = (hashValue * BASE + static_cast<unsigned long long>(c)) % (MOD - 1);
    return (hashValue % (tamanho - 1)) + 1;
}

void tabelahash::insere(const std::string nome, unsigned ano, unsigned ocorrencias)
{
    registro *novoRegistro = new registro(nome, ano, ocorrencias);
    size_t indice = hash1(nome);
    size_t passo = hash2(nome);

    while (tabela[indice] != nullptr)
        indice = (indice + passo) % TAMANHO;

    tabela[indice] = novoRegistro;
    novoRegistro->set_posicao(indice);
}

void tabelahash::imprime_tabela()
{
    for (size_t i = 0; i < tamanho; i++)
        if (tabela[i] != nullptr)
            std::cout << "[" << i << "] "
                      << tabela[i]->nome() << ", "
                      << tabela[i]->ano() << ", "
                      << tabela[i]->ocorrencias() << std::endl;
}

void tabelahash::imprime_maiores_ocorrencias_registros(unsigned x)
{
    std::vector<registro *> registros;

    // Copia registros para um vetor
    for (size_t i = 0; i < tamanho; ++i)
        if (tabela[i] != nullptr)
            registros.push_back(tabela[i]);

    // Ordena os registros por número de ocorrências
    std::sort(registros.begin(), registros.end(), [](registro *a, registro *b)
              { return a->ocorrencias() > b->ocorrencias(); });

    // Imprime os x registros com mais ocorrências
    for (size_t i = 0; i < x && i < registros.size(); ++i) {
            std::cout << "[" << registros[i]->posicao() << "] "
              << registros[i]->nome() << ", "
              << registros[i]->ano() << ", "
              << registros[i]->ocorrencias() << std::endl;
}
}

void tabelahash::imprime_maiores_ocorrencias(unsigned x) {
    if (x == 0) {
        std::cout << "Nenhuma ocorrência a exibir.\n";
        return;
    }

    std::unordered_map<std::string, unsigned> soma_ocorrencias;

    // Acumula ocorrências por nome
    for (size_t i = 0; i < tamanho; ++i) {
        if (tabela[i] != nullptr) {
            soma_ocorrencias[tabela[i]->nome()] += tabela[i]->ocorrencias();
        }
    }

    // Copia e ordena os dados
    std::vector<std::pair<std::string, unsigned>> ocorrencias_vetor(
        soma_ocorrencias.begin(), soma_ocorrencias.end());

    std::sort(ocorrencias_vetor.begin(), ocorrencias_vetor.end(),
              [](const auto &a, const auto &b) {
                  return a.second > b.second;
              });

    // Imprime os X primeiros
    std::cout << "Maiores ocorrências:\n";
    for (unsigned i = 0; i < x && i < ocorrencias_vetor.size(); ++i) {
        std::cout << ocorrencias_vetor[i].first << ": "
                  << ocorrencias_vetor[i].second << " ocorrências\n";
    }
}



//Procura baseada somente em nome, entrega o primeiro registro que encontrar
registro* tabelahash::pega_registro(std::string nome) {
    size_t indice = hash1(nome);
    size_t passo = hash2(nome);
    size_t tentativas = 0; 
    while (tabela[indice] != nullptr && tentativas<tamanho) {
        if (tabela[indice]->nome() == nome) {
            return tabela[indice];  // Registro encontrado
        }

        // Avança para o próximo índice usando Double Hashing
        indice = (indice + passo) % tamanho;
        tentativas++;  // Incrementa contador de tentativas
    }
    
    return nullptr;  // Registro não encontrado após percorrer toda a tabela
}

//Procura baseada em nome e ano, entregando apenas se o registro for compatível com os dois parâmetros passados.
registro* tabelahash::pega_registro(std::string nome, unsigned ano) {
    size_t indice = acha_registro(nome,ano);
    if(indice!=INDICE_INVALIDO)
        return tabela[indice];
    return nullptr;  
}

size_t tabelahash::acha_registro(const std::string nome, unsigned ano) {
    size_t indice = hash1(nome);
    size_t passo = hash2(nome);
    size_t tentativas = 0;

    while (tentativas < tamanho) {
        if (tabela[indice] == nullptr || (tabela[indice]->nome() == nome && tabela[indice]->ano() == ano)) {
            return indice;
        }
        indice = (indice + passo) % tamanho;
        tentativas++;
    }

    return INDICE_INVALIDO;
}


void tabelahash::carrega_arquivo(const std::string arquivo_csv)
{
    std::ifstream arquivo(arquivo_csv);
    if (!arquivo.is_open())
    {
        std::cerr << "Não foi possível abrir o arquivo: " << arquivo_csv << std::endl;
        return;
    }

    std::string linha;
    unsigned linha_num = 0;

    if (!std::getline(arquivo, linha)) // Pula o cabeçalho
    {
        std::cerr << "Arquivo vazio ou não legível: " << arquivo_csv << std::endl;
        return;
    }

    while (std::getline(arquivo, linha))
    {
        ++linha_num;

        if (linha.empty())
            continue;

        std::stringstream ss(linha);
        std::string id, nome, ano_str, genero, ocorrencias_str;
        unsigned ano, ocorrencias;

        try
        {
            if (!std::getline(ss, id, ','))
                throw std::runtime_error("Campo 'id' ausente");

            if (!std::getline(ss, nome, ','))
                throw std::runtime_error("Campo 'nome' ausente");

            // Remove espaços em branco ao redor do nome
            nome.erase(0, nome.find_first_not_of(" \t"));
            nome.erase(nome.find_last_not_of(" \t") + 1);

            if (!std::getline(ss, ano_str, ','))
                throw std::runtime_error("Campo 'ano' ausente");
            ano = std::stoi(ano_str);

            if (!std::getline(ss, genero, ','))
                throw std::runtime_error("Campo 'gênero' ausente");

            if (!std::getline(ss, ocorrencias_str))
                throw std::runtime_error("Campo 'ocorrências' ausente");
            ocorrencias = std::stoi(ocorrencias_str);

            // Chama o método insere da instância atual
            this->insere(nome, ano, ocorrencias);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Erro ao processar linha " << linha_num << ": " << e.what() << std::endl;
            continue;
        }
    }
}