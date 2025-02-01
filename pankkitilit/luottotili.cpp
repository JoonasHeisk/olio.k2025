#include "luottotili.h"

Luottotili::Luottotili(string nimi,double sum) : Pankkitili (nimi), luottoraja(-sum)
{
    cout<<"Luottotili luotu "<<nimi<<":lle Luottorajasi on:"<<sum<<endl;
    luottosaldo=luottosaldo-(-sum);
}

bool Luottotili::deposit(double sum)
{
    if (sum <= 0)
    {
        cout<< "Luottotili: Et voi lyhentaa lainaa negatiivisella summalla" << endl;
        return false;
    }
    else if (luottoraja +luottosaldo + sum > 0)
    {
        cout<< "Luottotili: Et voi maksaa enemmän kuin mita olet velkaa. Luottoa jaljella: "<< luottosaldo << " euroa" << endl;
        return false;
    }
    else
    {
        luottosaldo += sum;
        cout<< "Luottotili: Lyhensit lainaa " << sum << " eurolla. Luottoa jaljella: " << luottosaldo << " euroa" << endl;
        return true;
    }
}
double Luottotili::getBalance()
{
    return luottosaldo;
}

bool Luottotili::withdraw(double sum)
{
    if (sum < 0)
    {
        cout << "Luottotili: Et voi nostaa negatiivista summaa rahaa" << endl;
        return false;
    }
    else if (luottosaldo - sum < luottoraja)
    {
        cout << "Luottotili: Luottorajasi ei riita tahan nostoon. Luottoa jaljella: "<< luottosaldo << " euroa" << endl;
        return false;
    }
    else
    {
        luottosaldo -= sum;
        cout << "Luottotili: Nostit: " << sum << " euroa. Luottoa jaljella: " << luottosaldo << " euroa" << endl;
        return true;
    }
}


