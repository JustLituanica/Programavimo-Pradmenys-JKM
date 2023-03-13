
#include <iostream>
using namespace std;

int main()
{
    int g;
    int k100, k50, k20, k10, k5, k2, k1;

    cout << "Iveskite pirkejo graza: ";
    cin >> g;

    k100 = g / 100; g = g % 100;
    k50 = g / 50; g = g % 50;
    k20 = g / 20; g = g % 20;
    k10 = g / 10; g = g % 10;
    k5 = g / 5; g = g % 5;
    k2 = g / 2; g = g % 2;
    k1 = g;

    cout << "Pardaveja graza atiduos taip: " << endl;
    cout << "------------------------------" << endl;
    cout << "100 Eur ------> " << k100 << endl;
    cout << "50 Eur ------> " << k50 << endl;
    cout << "20 Eur ------> " << k20 << endl;
    cout << "10 Eur ------> " << k10 << endl;
    cout << "5 Eur ------> " << k5 << endl;
    cout << "2 Eur ------> " << k2 << endl;
    cout << "1 Eur ------> " << k1 << endl;

    return 0;
}