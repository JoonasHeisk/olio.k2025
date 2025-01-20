#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int arvaukset=0;
int maxnum;

int game(int maxnum)
{
    srand(11);
    cout <<"anna maksimiarvo etsittavalle luvulle" << endl;
    cin >> maxnum;
    int satunnaisluku = rand() % (maxnum+1);
    bool peli=true;


    while (peli==true){
        cout << "yrita arvata kokonaisluku" << endl;

        int arvaus;
        cin >> arvaus;

        if (arvaus < satunnaisluku){
            arvaukset++;
            cout << "arvauksesi on pienempi kuin etsittava luku" << endl;
        }
        else if (arvaus > satunnaisluku) {
            arvaukset++;
            cout << "arvauksesi on suurempi kuin etsittava luku"<< endl;
        }
        else{
            arvaukset++;
            cout << "arvauksesi on yhtasuuri kuin etsittava luku. Voitit!"<< endl;
            peli=false;
        }
    }
    return arvaukset;

}

int main()
{
  game(maxnum);
    cout << "arvausten maara " << arvaukset << endl;
}
