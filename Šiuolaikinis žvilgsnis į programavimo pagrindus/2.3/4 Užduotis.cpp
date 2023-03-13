
#include <iostream>
using namespace std;

int main()
{
    int a, b, c, v, m;

    cout << "Kelinta val pakilo lektuvas? ";
    cin >> a;

    cout << "Kelinta min pakilo lektuvas? ";
    cin >> b;

    cout << "Kiek laiko ore praleido lektuvas? ";
    cin >> c;

    v = (a + (c / 60)) / 60;
    m = (b + c) % 60;

    cout << "Nusileis kai bus " << v << " valandu ir " << m << " minuciu";


    return 0;
}