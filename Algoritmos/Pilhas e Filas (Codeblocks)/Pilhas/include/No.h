#ifndef NO_H
#define NO_H
#include <cstddef>

class No
{
    public:
        No() {prox=NULL;};
        ~No() {}
        No* getProx(){return prox;};
        int getInfo(){return val;};
        void setProx(No* p){prox = p;};
        void setInfo(int v){val = v;};
    private:
    No *prox;
    int val;
};

#endif // NO_H
