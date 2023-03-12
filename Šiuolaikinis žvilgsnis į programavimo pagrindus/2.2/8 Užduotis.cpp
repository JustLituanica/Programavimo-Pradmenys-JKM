
#include <iostream>
using namespace std;

int main()
{
    int k, m;

    cout << "Kokia bauda? ";
    cin >> k;

    m = ((k * 100) * 0.83) / 1000;

    cout << "Centai svere " << m << " kg";
     
    return 0;
}