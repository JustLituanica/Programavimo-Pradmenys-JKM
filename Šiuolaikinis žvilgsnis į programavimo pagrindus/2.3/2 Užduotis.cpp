
#include <iostream>
using namespace std;

int main()
{
    int n, m, s, k;

    cout << "Kiek devintoku dalyvavo olimpiadoje? ";
    cin >> n;

    cout << "Kiek saldainiu nupirko mokytoja? ";
    cin >> m;

    s = m / n;
    k = m % n;

    cout << "Kiekvienas mokinys gavo po " << s << " saldainius";
    cout << "Mokytojai liko " << k << " saldainiai";

    return 0;
}