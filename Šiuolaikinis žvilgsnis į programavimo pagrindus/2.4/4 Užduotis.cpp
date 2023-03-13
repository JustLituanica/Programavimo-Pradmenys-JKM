
#include <iostream>
using namespace std;

int main()
{
    int t;

    cout << "Kelinta minute? ";
    cin >> t;

    if (t % 5 == 0)
    {
        cout << "Raudona, tuoj bus zalia" << endl;
    }
    else if (t % 5 == 3)
    {
        cout << "Zalia, tuoj bus raudona" << endl;
    }
    else if (t % 5 < 3)
    {
        cout << "Zalia" << endl;
    }
    else
    {
        cout << "Raudona" << endl;
    }

    return 0;
}