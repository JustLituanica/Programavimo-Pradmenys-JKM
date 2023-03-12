
#include <iostream>
using namespace std;

int main()
{
    double k, v, n;

    cout << "Kiek per menesi vidutiniskai perskaitoma knygu? ";
    cin >> v;

    cout << "Kiek mokiniu per metus apsilanko bibliotekoje? ";
    cin >> n;

    k = (v * 12) / n;

    cout << "Vidutiniskai per metus vienas mokinys perskaito " << k << " knygas";

    return 0;
}