#include "../include/AlgForcaBruta.h"
bool AlgForcaBruta::buscarPadrao(const std::string &T, const std::string &P){
    int tamPadrao=P.length();
    unsigned long total=T.length()-tamPadrao;
    
    int j=0;
    for(int i=0;i<total;i++)
    {
        for(;j<tamPadrao && T[i+j]==P[j];j++){};
        if(j==tamPadrao)
            return true;    
        j=0;    
    }  
    return false;
}
int AlgForcaBruta::posicaoPadrao(const std::string &T, const std::string &P) {
    int tamPadrao = P.length();
    int tamTexto = T.length();
    if (tamPadrao == 0)
        return 0; // padrão vazio retorna início
    for (int i = 0; i <= tamTexto - tamPadrao; i++) {
        int j = 0;
        while (j < tamPadrao && T[i + j] == P[j])
            j++;
        if (j == tamPadrao)
            return i; 
    }
    return -1; 
}
