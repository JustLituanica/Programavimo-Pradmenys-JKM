
#include <iostream>
using namespace std;

int main()
{
    int n, x;

    cout << "Ivesk n reiskme: ";
    cin >> n; 

    cout << "Trizenklis skaicius x = ";
    cout << n / 10 % 10;
    cout << n / 100;
    cout << n % 10;

    return 0;
}