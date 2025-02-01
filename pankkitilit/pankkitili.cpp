#include "pankkitili.h"
#include "luottotili.h"
Pankkitili::Pankkitili(string nimi)
{
    omistaja=nimi;
    cout<<"Pankkitili luotu "<<nimi<<":lle"<<endl;
}

double Pankkitili::getBalance()
{
    return saldo;
}

bool Pankkitili::deposit(double s)
{
    if(s < 0)
    {
        return false;
    }
    else
    {
    cout<<"Pankkitili: Talletettu summa: "<<s<<endl;
    saldo = saldo + s;
    return true;
    }
}

bool Pankkitili::withdraw(double s)
{
    if(saldo - s < 0)
    {
        return false;
        cout<<"Pankkitili: Saldo ei riita"<<endl;
    }
    else
    {
        saldo = saldo - s;
        cout<<"Pankkitili: Nostettu summa: "<<s<<endl;
        return true;
    }
}
