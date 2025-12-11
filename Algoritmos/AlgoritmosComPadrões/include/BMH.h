#ifndef BMH_H
#define BMH_H
#include <string>
#include <fstream>
#include <vector>
class BMH
{
public:
public:
    BMH() {}
    ~BMH() {}
    void Busca(const std::string &strArq, const std::string &strBusca, bool imp);

private:
    int* Pref(const std::string &strBusca);
};
#endif // !BMH_H
