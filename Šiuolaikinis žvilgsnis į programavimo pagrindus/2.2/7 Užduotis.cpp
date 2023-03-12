
#include <iostream>
using namespace std;

int main()
{
    double g, c;

    cout << "Koks tarakono greitis? ";
    cin >> g;

    c = g * 100000 / 3600;

    cout << "Tarakonas nubegs " << c << " cm";

    return 0;
}