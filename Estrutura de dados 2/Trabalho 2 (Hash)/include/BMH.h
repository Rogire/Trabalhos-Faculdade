#ifndef BMH_H
#define BMH_H
#include <string>
#include <fstream>
#include <vector>
class BMH
{
public:
    BMH() {}
    ~BMH() {}
    bool buscarPadrao(const std::string &texto, const std::string &padrao);
    int posicaoPadrao(const std::string &texto, const std::string &padrao);

private:
    std::vector<int> tabelaDeslocamentos(const std::string &padrao, int tamAlfabeto);
};
#endif // !BMH_H
