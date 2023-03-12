
#include <iostream>
using namespace std;

int main()
{
    int a, men, d, v;

    cout << "Kiek metu Tautvydui? ";
    cin >> a;

    men = a * 12;
    d = a * 365;
    v = d * 24;

    cout << "Tautvydas gyvena jau " << men << " menesius" << endl;
    cout << "Tautvydas gyvena jau " << d << " dienas" << endl;
    cout << "Tautvydas gyvena jau " << v << " valandas" << endl;

    return 0;
}