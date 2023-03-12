
#include <iostream>
using namespace std;

int main()
{
    int k, n, m;

    cout << "Kiek klaseje yra mokiniu? ";
    cin >> n;
    
    cout << "Kiek lapu sudaro konspekta? ";
    cin >> m;

    k = n * m;
    cout << "Reikes " << k << " lapu";

    return 0;
}