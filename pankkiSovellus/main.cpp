#include <iostream>
#include "pankkitili.h"

using namespace std;

int main()
{
    cout<<"Luodaan pankkitileja"<<endl;
    Pankkitili tili1("123456", "Anna Virtanen", 500.0);
    Pankkitili tili2("654321", "Matti Meikalainen", 300.0);

    cout<<"Tulostetaan tilitiedot"<<endl;
    std::cout << "Alkutilanne:\n";
    tili1.tulostaTilitiedot();
    tili2.tulostaTilitiedot();

    cout<<"Suoritetaan toimintoja"<<endl;
    tili1.talleta(200.0);
    tili2.nosta(100.0);
    tili1.siirra(tili2, 150.0);

    std::cout << "Tulostetaan tilitiedot uudelleen"<<endl;
    std::cout << "\nTilanne toimintojen jalkeen:\n";
    tili1.tulostaTilitiedot();
    tili2.tulostaTilitiedot();

    return 0;
}
