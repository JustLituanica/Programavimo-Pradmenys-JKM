
#include <iostream>
using namespace std;

int main()
{
    int m, n;

    cout << "Kelintais metais vyko olimpines zaidynes? ";
    cin >> m;

    if (m % 2 == 0)
    {
        n = (m - 1896) / 4;
        cout << "Zaidyniu numeris: " << n + 1;
    }
    else
    {
        cout << "Metai neolimpiniai";
    }

    return 0;
}