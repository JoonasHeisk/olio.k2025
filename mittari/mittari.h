#ifndef MITTARI_H
#define MITTARI_H
#include "dht.h"
#include "lcd.h"
#include <iostream>

using namespace std;

class Mittari
{
public:
    Mittari();
    ~Mittari();
    void setup();
    void mittaus();
private:
    int varoitusvalo;
    LCD lcdOlio;
    DHT dhtOlio;
};

#endif // MITTARI_H
