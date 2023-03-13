
#include <iostream>
using namespace std;

int main()
{
    int m, s;

    cout << "Kokio ilgio virve? ";
    cin >> m;

    s = (m / 4) * ((m - 2 * (m / 4)) / 2);

    cout << "Didziausias plotas: " << s;

    return 0;
}