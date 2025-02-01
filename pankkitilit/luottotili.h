#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H
#include <iostream>
#include "pankkitili.h"
using namespace std;

class Luottotili : public Pankkitili
{
public:
    Luottotili(string,double);
    virtual bool deposit(double) override;
    virtual bool withdraw(double) override;
    virtual double getBalance() override;

protected:
    double luottoraja =  0;
    double luottosaldo = 0;
};

#endif // LUOTTOTILI_H
