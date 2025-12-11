#ifndef LZW
#include <string>
#include <vector>
#include <fstream>

class LZW
{
private:
    std::string* arqPath{};
    std::vector<std::string*> tabela;

public:
    LZW();
    ~LZW();
    std::vector<int> Comprimir(std::string arqPath);
    std::string Descomprimir(std::vector<int> posicoes);
    void Salvar(std::vector<int> *posicoes);
};
#endif // !LZW

