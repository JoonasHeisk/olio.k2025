#include <iostream>
#include "pankkitili.h"
#include "luottotili.h"
#include "asiakas.h"
using namespace std;

int main()
{
    Asiakas kalle("Kalle", 1000);  // Luottoraja -1000
    kalle.showSaldo();
    cout<<endl;
    kalle.talletus(250);
    kalle.luotonNosto(150);
    kalle.showSaldo();
    cout<<endl;

    Asiakas bertta("Bertta", 1000);
    bertta.showSaldo();
    cout<<endl;

    cout<<kalle.getNimi()<<endl;
    kalle.showSaldo();
    kalle.tilisiirto(50, bertta);

    cout<<bertta.getNimi()<<endl;
    bertta.showSaldo();

    return 0;
}
