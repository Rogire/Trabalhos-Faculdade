#ifndef LZW_IA

#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>

class LZW_IA
{
    public:
        LZW_IA();
        ~LZW_IA();

        std::vector<int> compress(const std::string &input);
        std::string decompress(const std::vector<int> &compressed);
        void Salvar(std::vector<int> &posicoes);

    private:
        std::unordered_map<std::string, int> dictionary;
        std::vector<std::string> reverseDictionary;
        int dictionarySize;
};

#endif // LZW_IA_COPILOT_H