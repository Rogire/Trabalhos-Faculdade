#ifndef NO_H
#define NO_H


class No
{
    public:
        No();
        ~No();
        int getinfo();
        No* getProx();
        void setInfo(float val);
        void setProx(No *p);
    private:
        int info;
        No *prox;
};

#endif // NO_H
