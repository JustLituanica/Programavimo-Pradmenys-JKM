
#include <iostream>
using namespace std;

int main()
{
    int ilgis, plotis;
    int plotas;
    double m2kaina, psuma;

    cout << "Iveskite kambario ilgi: ";
    cin >> ilgis;

    cout << "Iveskite kambario ploti: ";
    cin >> plotis;

    cout << "Iveskite plyteliu 1 kvadratinio metro kaina: ";
    cin >> m2kaina;

    plotas = ilgis * plotis;
    cout << "Pinigu suma, kuria reikia sumoketi: " << psuma;

    psuma = 1.05 * plotas * m2kaina;
    cout << "Kambario grindu plotas: " << plotas << endl;

    return 0;
}