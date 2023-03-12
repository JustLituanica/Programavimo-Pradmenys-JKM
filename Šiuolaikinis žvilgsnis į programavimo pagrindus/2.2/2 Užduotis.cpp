
#include <iostream>
using namespace std;

int main()
{
    int x, y, m, s;

    cout << "Kiek valandu rodo laikrodis? ";
    cin >> x;

    cout << "Kiek minuciu rodo laikrodis? ";
    cin >> y;

    m = x * 60 + y;
    s = m * 60;

    cout << "Nuo vidurnakcio praejo " << m << " minuciu arba " << s << " sekundziu";

    return 0;
}