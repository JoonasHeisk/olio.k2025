//#include <iostream>
//#include "lcd.h"
//#include "dht.h"
//using namespace std;
#include "mittari.h"

int main()
{
    Mittari M;
    for(int i = 0; i < 5; i++){
        M.mittaus();
    }
    return 0;
}
