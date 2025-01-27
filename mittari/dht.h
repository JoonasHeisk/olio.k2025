#ifndef DHT_H
#define DHT_H
#include <iostream>
using namespace std;

class DHT
{
public:
    DHT();
    ~DHT();
    void begin();
    float readTemperature();
private:
    float temperature;
};

#endif // DHT_H
