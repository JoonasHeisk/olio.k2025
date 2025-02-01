#include "asiakas.h"



Asiakas::Asiakas(string nimi, double luottoraja) : nimi(nimi), kayttotili(nimi), luottotili(nimi, luottoraja)
{
    cout<<"asiakkuus luotu "<<nimi<<endl;
}

string Asiakas::getNimi()
{

    return nimi;
}

void Asiakas::showSaldo()
{
    cout<<"Kayttotilin saldo "<<kayttotili.getBalance()<<endl;
    cout<<"Luottotilin saldo "<<luottotili.getBalance()<<endl;
}

bool Asiakas::talletus(double summa)
{
    kayttotili.deposit(summa);
    return true;
}

bool Asiakas::nosto(double summa)
{
    kayttotili.withdraw(summa);
    return true;
}

bool Asiakas::luotonMaksu(double summa)
{
    luottotili.deposit(summa);
    return true;
}

bool Asiakas::luotonNosto(double summa)
{
    luottotili.withdraw(summa);
    return true;
}

bool Asiakas::tilisiirto(double summa, Asiakas&toinenAsiakas)
{
    if (summa < 0)
    {
        cout << "Et voi siirtää alle 0,01 euroa." << endl;
        return false;
    }
    cout << "Pankkitili: " << this->getNimi() << " siirtaa " << summa<< " euroa " << toinenAsiakas.getNimi() << ":lle." << endl;
    if (!kayttotili.withdraw(summa))
    {
        cout << "Tilisiirto epäonnistui. Tarkista, riittavatko varat." << endl;
        return false;
    }
    else if (!toinenAsiakas.kayttotili.deposit(summa))
    {
        cout << "Tilisiirto epäonnistui. Talletus toiselle tilille ei onnistunut." << endl;
        kayttotili.deposit(summa); // Palautetaan rahat, koska talletus epäonnistui
        return false;
    }
    else
    {
        cout << this->getNimi() << " Pankkitili: nosto " << summa << " tehty." << endl;
        cout << toinenAsiakas.getNimi() << " Pankkitili: talletus " << summa << " tehty." << endl;
        return true;
    }
}




