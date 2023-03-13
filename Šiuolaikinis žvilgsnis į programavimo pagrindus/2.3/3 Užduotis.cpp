
#include <iostream>
using namespace std;

int main()
{
    int n, d, k, m, a;

    cout << "Kiek balionu gavo Andrius? ";
    cin >> n;

    cout << "Kiek draugu turejo Andrius? ";
    cin >> d;

    cout << "Kiek pucamu balionu sprogo? ";
    cin >> k;

    m = (n - k) / (d + 1);
    a = (n - k) % (d + 1) + m;

    cout << "Kiekvienas draugas gavo po " << m << " balionu" << endl;
    cout << "Andriui teko " << a << " balionu";

    return 0;
}