#include "../include/LZW_IA.h"
#include <iostream>

LZW_IA::LZW_IA()
{
    // Inicializa o dicionário com todos os caracteres ASCII
    dictionarySize = 256;
    for (int i = 0; i < dictionarySize; ++i)
    {
        dictionary[std::string(1, i)] = i;
        reverseDictionary.push_back(std::string(1, i));
    }
}

LZW_IA::~LZW_IA()
{
}

std::vector<int> LZW_IA::compress(const std::string &input)
{
    std::string current;
    std::vector<int> compressed;

    for (char c : input)
    {
        std::string next = current + c;
        if (dictionary.find(next) != dictionary.end())
        {
            current = next;
        }
        else
        {
            compressed.push_back(dictionary[current]);
            dictionary[next] = dictionarySize++;
            current = std::string(1, c);
        }
    }

    if (!current.empty())
    {
        compressed.push_back(dictionary[current]);
    }

    return compressed;
}
void LZW_IA::Salvar(std::vector<int> &posicoes)
{
    std::ofstream outfile ("LZW_IA.txt",std::ios::binary);
    for(int i=0;i<posicoes.size();i++)
    {
        outfile<<(posicoes.at(i))<<",";
    }
    outfile.close();
}

std::string LZW_IA::decompress(const std::vector<int> &compressed)
{
    std::string current(1, compressed[0]);
    std::string result = current;
    std::string entry;
    for (size_t i = 1; i < compressed.size(); ++i)
    {
        int code = compressed[i];
        if (code < reverseDictionary.size())
        {
            entry = reverseDictionary[code];
        }
        else if (code == dictionarySize)
        {
            entry = current + current[0];
        }
        else
        {
            throw std::runtime_error("Código inválido na descompressão");
        }

        result += entry;

        reverseDictionary.push_back(current + entry[0]);
        dictionarySize++;
        current = entry;
    }

    return result;
}