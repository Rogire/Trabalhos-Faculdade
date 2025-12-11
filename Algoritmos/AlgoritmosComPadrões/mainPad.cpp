#include <iostream>
#include <string>
#include <vector>
#include "include/pad.h"
using namespace std;

int main()
{
    Padroes p;
    std::vector<string> ex = {"bruno", "aurelio", "lucas", "joel", "igor", "carlos", "belle", "fer", "tulio", "loq", "bullets", "gerson"};

    p.ordena(&ex);

    for (int i = 0; i < 12; i++)
        cout << ex[i] << " ";

    cout << endl;

    string t = "";

    for(string s : ex)
    {
        for(char c : s)
            t += c;
    }

    //std::cout << t<<'\n';

    p.Buscar(t, "fer");

    return 0;
}
