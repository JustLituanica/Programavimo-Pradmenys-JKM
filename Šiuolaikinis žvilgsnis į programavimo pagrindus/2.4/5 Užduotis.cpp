
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int A, B, C;
    bool AB = false, AC = false, BC = false;

    cout << "A: ";
    cin >> A;

    cout << "B: ";
    cin >> B;

    cout << "C: ";
    cin >> C;

    int Min = abs(A - B);
    if (Min > abs(A - C)) Min = abs(A - C);
    if (Min > abs(B - C)) Min = abs(B - C);

    if (Min >= abs(A - B)) {
        AB = true;
        Min = abs(A - B);
    }

    if (Min >= abs(A - C)) {
        AC = true;
        Min = abs(A - C);
    }

    if (Min >= abs(B - C)) {
        BC = true;
        Min = abs(B - C);
    }

    cout << "Atstumai maziausi tarp: ";
    if (AB) cout << "A ir B | ";
    if (AC) cout << "A ir C | ";
    if (BC) cout << "B ir C | ";

    return 0;
}