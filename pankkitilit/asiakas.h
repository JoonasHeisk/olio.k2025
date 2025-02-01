#ifndef ASIAKAS_H
#define ASIAKAS_H
#include <iostream>
#include "luottotili.h"
#include "pankkitili.h"

using namespace std;

class Asiakas
{
public:
    Asiakas(string,double);
    string getNimi();
    void showSaldo();
    bool talletus(double);
    bool nosto(double);
    bool luotonMaksu(double);
    bool luotonNosto(double);
    bool tilisiirto(double, Asiakas &);

private:
    string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;
};




#endif // ASIAKAS_H
