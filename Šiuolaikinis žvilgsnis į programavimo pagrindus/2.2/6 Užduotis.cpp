
#include <iostream>
using namespace std;

int main()
{
    int x1, y1, x2, y2;
    int s, p;

    cout << "x1: ";
    cin >> x1; 

    cout << "y1: ";
    cin >> y1; 

    cout << "x2: ";
    cin >> x2; 

    cout << "y2: ";
    cin >> y2; 

    p = (x1 + x2) * 2 + (y1 + y2) * 2;
    s = (x1 + x2) * (y1 + y2);

    cout << "Plotas = " << s << " kvard. vnt." << endl;
    cout << "Perimetras = " << p << " vnt." << endl;

    return 0;
}