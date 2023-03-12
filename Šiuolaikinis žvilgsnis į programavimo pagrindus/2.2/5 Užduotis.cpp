
#include <iostream>
using namespace std;

int main()
{
    int k, n, m, v;

    cout << "Kiek traukinyje keleiviu? ";
    cin >> n;

    cout << "Kiek keleiviu vyksta ne i Vilniu? ";
    cin >> m;

    cout << "Kiek vagonu traukinyje? ";
    cin >> v;

    k = (n - m) / v;

    cout << "Viename traukinio vagone vaziuoja " << k << " keleiviu i Vilniu";

    return 0;
}