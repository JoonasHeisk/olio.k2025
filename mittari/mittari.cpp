#include "mittari.h"

Mittari::Mittari()
{
    cout<<"mittari luotu"<<endl;
    setup();
}

Mittari::~Mittari()
{
    cout<<"mittari tuhottu"<<endl;
}

void Mittari::setup()
{
    varoitusvalo = 0;
    lcdOlio.begin();
    dhtOlio.begin();
}

void Mittari::mittaus()
{
    float t = dhtOlio.readTemperature();
    if(t < 10)
    {
        varoitusvalo = 1;
    }
    else
    {
        varoitusvalo = 0;
    }
    if(varoitusvalo == 1)
    {
        cout<<"LAMPOTILA LIIAN ALHAINEN"<<endl;
    }
    string s = lcdOlio.floatToString(t);
    lcdOlio.print(s);
}
