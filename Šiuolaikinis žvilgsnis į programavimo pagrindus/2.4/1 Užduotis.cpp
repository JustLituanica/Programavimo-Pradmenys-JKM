
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    double d, x1, x2;

    cout << "Iveskite kvadratines lygties koeficientus a, b ir c: ";
    cin >> a >> b >> c;

    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    d = b * b - 4 * a * c;

    if (d < 0)
    {
        cout << "Lygtis neturi realiu sprendiniu";
    }
    else if (d == 0)
    {
        x1 = -b / (2 * a);
        cout << "Lygtis turi tik viena sprendini: x = " << x1;
    }
    else
    {
        x1 = (-b - sqrt(d)) / (2 * a);
        x2 = (-b + sqrt(d)) / (2 * a);

        cout << "Lygtis turi du sprendinius: x1 = " << setprecision(2) << x1 << ", x2 = " << setprecision(2) << x2;
    }

    return 0;
}