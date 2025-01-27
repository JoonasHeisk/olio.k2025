#include "lcd.h"

LCD::LCD() {
    cout<<"LCD constructor"<<endl;
}

LCD::~LCD()
{
    cout<<"LCD destructor"<<endl;
}

void LCD::begin()
{
    text= "";
}

void LCD::print(string s)
{
    cout<<s<<endl;
    cout<<text<<endl;
}

string LCD::floatToString(float num)
{
    return to_string(num);
}
