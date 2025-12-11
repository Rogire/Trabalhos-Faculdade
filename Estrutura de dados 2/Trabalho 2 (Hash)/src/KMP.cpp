#include "../include/KMP.h"




std::vector<int> KMP::funcaoPrefixo(const std::string &padrao) const{
    int tamPadrao = padrao.size();                  
    std::vector<int> pi(tamPadrao, 0);           
    int k = 0;                         

    for (int q = 1; q < tamPadrao; q++) {
       
        while (k > 0 && padrao[k] != padrao[q])
          
            k = pi[k - 1];
        
        if (padrao[k] == padrao[q])
        
            k = k + 1;
       
        pi[q] = k;
    }
   
    return pi;
}


void KMP::imprimeOcorrencias(const std::string &texto, const std::string &padrao) const{
    int tamTexto = texto.size();                 
    int tamPadrao = padrao.size();                 
    std::vector<int> pi = funcaoPrefixo(padrao);  
    int q = 0;                      
    for (int i = 0; i < tamTexto; i++) {
   
        while (q > 0 && padrao[q] != texto[i])
      
            q = pi[q - 1];
     
   
        if (padrao[q] == texto[i])
            q = q + 1;
     
        if (q == tamPadrao) {
         
            std::cout << "O padrão ocorre com deslocamento " << (i - tamPadrao + 1) << std::endl;
           
            q = pi[q - 1];
        }
    }
}

bool KMP::buscarPadrao(const std::string &texto, const std::string &padrao) const{
    int tamTexto = texto.size();                 
    int tamPadrao = padrao.size();                 
    std::vector<int> pi = funcaoPrefixo(padrao);  
    int q = 0;                      
    for (int i = 0; i < tamTexto; i++) {
        while (q > 0 && padrao[q] != texto[i])
             q = pi[q - 1];
     
   
        if (padrao[q] == texto[i])
        
            q = q + 1;
     
        if (q == tamPadrao) 
            return true;
    }
    return false;
}

int KMP::posicaoPadrao(const std::string &texto, const std::string &padrao) const {
    int tamTexto = texto.size();
    int tamPadrao = padrao.size();
    if (tamPadrao == 0) 
        return 0; // padrão vazio retorna início
    std::vector<int> pi = funcaoPrefixo(padrao);
    int q = 0;
    for (int i = 0; i < tamTexto; i++) {
        while (q > 0 && padrao[q] != texto[i])
            q = pi[q - 1];
        if (padrao[q] == texto[i])
            q++;
        if (q == tamPadrao)
            return i - tamPadrao + 1; 
    }
    return -1; 
}
