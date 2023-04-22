//P12V_Launikonis_Justinas_Egzaminas
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const char CDfva[] = "LeidiniaiS.txt";
const char CDfvb[] = "LeidiniaiN.txt";
const char CRfv[] = "Rezultatai.txt";

const int CMax = 30;
const int CPav = 20;

struct Leidiniai
{
    string pav;
    int kiek;
    int kaina;
};

struct Kainos
{
    string pav;
    int kiek;
    int kaina;

    int men3;
    int men6;
    int men12;
};

void Skaityti(const char fv[], Leidiniai A[], int & n);
void Spausdinti(Leidiniai A[], int n, string komentaras);
void Koreguoti(Leidiniai A[], int & n, Leidiniai B[], int m);
void MenesioKainos(Leidiniai A[], int n, Kainos C[], int& k);
void Rikiuoti(Kainos C[], int k);
int  PigiausiasLeidinys(Kainos C[], int k);
void SpausdintiRez(Kainos C[], int k, string komentaras, int indeksas);

int main()
{
    Leidiniai A[CMax];
    Leidiniai B[CMax];
    Kainos C[CMax];

    int n = 1; //pradedame nuo 1, nes paskutinëje eilutëje nedëjome "Enter", todël nëra simbolio '\n'
    int m = 1;
    int k = 0; //pradedame nuo 0, nes neskaitome ið failo, o prisiskiriame funkcijoje

    int indeksas; //kintamasis pigiausio leidinio indekui

    ofstream fr(CRfv);
    fr.close(); //iðvalome rezultatø failà

    Skaityti(CDfva, A, n); //duomenø skaitymo á masyvà funkcija (ið failo "LeidiniaiS.txt")
    Spausdinti(A, n, "Pradiniai duomenys is failo 'LeidiniaiS.txt'"); //duomenø spausdinimo funkcija

    Skaityti(CDfvb, B, m); //duomenø skaitymo á masyvà funkcija (ið failo "LeidiniaiN.txt")
    Spausdinti(B, m, "Pradiniai duomenys is failo 'LeidiniaiN.txt'"); //duomenø spausdinimo funkcija

    Koreguoti(A, n, B, m); //koregavimo funkcija
    MenesioKainos(A, n, C, k); //naujo masyvo sudarimo ir menesio kainø apskaièiavimo funkcija
    Rikiuoti(C, k); //rikiavimo funkcija
    indeksas = PigiausiasLeidinys(C, k); //pigiausio leidinio radimo funkcija

    SpausdintiRez(C, k, "Sutvarkytas laikrasciu ir zurnalu kainorastis", indeksas); //rezultatø spausdinimo funkcija

    return 0;
}

void Skaityti(const char fv[], Leidiniai A[], int& n)
{
    ifstream fd(fv); //atidarome duomenø failà

    char eil[CPav + 1];

    //========= Susirandame kiek duomenø duota faile ================

    fd.ignore(80, '\n');

    while (!fd.eof()) //kol failas nëra tuðèias
    {
        fd.ignore(80, '\n');
        n++; //skaièiuojame skirtingø leidiniø kieká
    }

    fd.close();
    //===============================================================

    fd.open(fv); //atidarome failà ið naujo

    for (int i = 0; i < n; i++)
    {
        fd.get(eil, CPav);
        A[i].pav = eil; //ásivedame laikraðèio pavadinimà á strukturà

        fd >> A[i].kiek >> A[i].kaina; //isivedame laikraðèio kieká per mënesá ir vieno vnt. kainà

        fd.ignore(80, '\n'); //pereiname á kità eilutæ
    }

    fd.close(); //uþdarome duomenø failà
}

void Spausdinti(Leidiniai A[], int n, string komentaras)
{
    ofstream fr(CRfv, ios::app); //atidarome ir leidþiame pildyti rezultatø failà

    fr << komentaras << endl; //spausdiname reikiamà komentarà
    fr << "====================================================================" << endl;
    fr << " Leidinio pav.     Kiek kartu iseina per men.    Vieno egz. kaina   " << endl;
    fr << "====================================================================" << endl;

    for (int i = 0; i < n; i++)
    {
        fr << setw(30) << left << A[i].pav << setw(28) << A[i].kiek << setw(20) << A[i].kaina << endl; //spausdiname duomenis eilutëmis lentelëje
    }

    fr << "====================================================================" << endl;
    fr << endl << endl;

    fr.close(); //uþdarome rezultatø failà
}

void SpausdintiRez(Kainos C[], int k, string komentaras, int indeksas)
{
    ofstream fr(CRfv, ios::app); //atidarome ir leidþiame pildyti rezultatø failà

    fr << komentaras << endl; //spausdiname reikiamà komentarà
    fr << "==================================================================================================================================" << endl;
    fr << " Leidinio pav.     Kiek kartu iseina per men.    Vieno egz. kaina          3 men. kaina        6 men. kaina       12 men. kaina   " << endl;
    fr << "==================================================================================================================================" << endl;

    for (int i = 0; i < k; i++) 
    {    
        fr << setw(30) << left << C[i].pav << setw(28) << C[i].kiek << setw(20) << C[i].kaina
            << setw(20) << C[i].men3 << setw(20) << C[i].men6 << setw(20) << C[i].men12 << endl;
        //spausdiname rezultatus eilutemis lenteleje, taip pat spausdiname mënesio kainas
    }

    fr << "==================================================================================================================================" << endl;
    fr << "Pigiausias leidinys metinei prenumeratai: " << C[indeksas].pav << endl; //spausdiname pigiausio laikraðèio pavadinimà
    fr << "Jis, metams, kainuoja: " << C[indeksas].men12 << endl; //spausdiname pigiausio laikraðèio metinæ kainà
    fr << endl;

    fr.close(); //uþdarome rezultatø failà
}


void Koreguoti(Leidiniai A[], int & n, Leidiniai B[], int m)
{
    int z; //kintamasis kuriuo patikrinsime ar yra naujø laikraðèiø kataloge

    if (n > m) //...jei nëra naujø laikraðèiø...
    {
        z = n; //...prisiskiriame kintamàjá
    }
    else //...jei yra naujø laikraðèiø...
    {
        z = m; //...prisiskiriame kintamàjá
    }

    for (int i = 0; i < z; i++)
    {
        //Koreguojame naujà laikraðèio kainà
        if (A[i].pav == B[i].pav && A[i].kaina != B[i].kaina)
        {
            A[i].kaina = B[i].kaina;
        }

        //Koreguojame naujà laikraðèio leidiniø kieká
        if (A[i].pav == B[i].pav && A[i].kiek != B[i].kiek)
        {
            A[i].kiek = B[i].kiek;
        }

        //Koreguojame ir pridedame nauju leidinius
        if (A[i].pav != B[i].pav)
        {
            A[i].pav = B[i].pav;
            A[i].kiek = B[i].kiek;
            A[i].kaina = B[i].kaina;
            n++;
        }
    }
}

void MenesioKainos(Leidiniai A[], int n, Kainos C[], int & k)
{
    for (int i = 0; i < n; i++)
    {
        C[i].pav = A[i].pav; //naujam masyvui prisiskiriame leidinio pavadinimà

        C[i].kiek = A[i].kiek; //naujam masyvui prisiskiriame leidiniø kieká per mënesá
        C[i].kaina = A[i].kaina; //naujam masyvui prisiskiriame leidinio 1 vnt. kainà

        C[i].men3 = (C[i].kaina * C[i].kiek) * 3; 
        C[i].men6 = (C[i].kaina * C[i].kiek) * 6;
        C[i].men12 = (C[i].kaina * C[i].kiek) * 12;
        //suskaièiuojame kiek leidinys kainuos perkant 3/6/12 mënesiø naudojant formulæ
        //(vnt. kaina * leidiniai per mënesá) * laikotarpis

        k++; //skaièiojame skirtingø leidiniø kieká
    }
}

void Rikiuoti(Kainos C[], int k)
{
    string pav;
    int kiek, kaina, men3, men6, men12;
    //trumpalaikiai kintamieji reikalingi rikuojant burbuliuko metodu

    for (int i = 0; i < k; i++)
    {
        for (int j = k - 1; j > i; j--)
        {
            if (C[j].pav < C[j - 1].pav)
            {
                pav = C[j].pav;
                C[j].pav = C[j - 1].pav;
                C[j - 1].pav = pav; //surikiuojame leidiniø pavadinimus

                kiek = C[j].kiek;
                C[j].kiek = C[j - 1].kiek;
                C[j - 1].kiek = kiek; //surikiuojame leidiniø kieká per mënesá

                kaina = C[j].kaina;
                C[j].kaina = C[j - 1].kaina;
                C[j - 1].kaina = kaina; //surikiuojame leidinio 1 vnt. kainà

                men3 = C[j].men3;
                C[j].men3 = C[j - 1].men3;
                C[j - 1].men3 = men3; //surikiuojame leidinio kainà per 3 mënesius

                men6 = C[j].men6;
                C[j].men6 = C[j - 1].men6;
                C[j - 1].men6 = men6; //surikiuojame leidinio kainà per 6 mënesius

                men12 = C[j].men12;
                C[j].men12 = C[j - 1].men12;
                C[j - 1].men12 = men12; //surikiuojame leidinio kainà per 12 mënesiø
            }
        }
    }
}

int PigiausiasLeidinys(Kainos C[], int k)
{
    int min = 9999; //laikinas kintamasis kuriuo tikrinsime pigiausià leidiná
    int indeksas; //kintamasis kuriame laikysime pigiausio leidinio indeksà

    for (int i = 0; i < k; i++)
    {
        if (C[i].men12 < min) //tikriname ar laikraðtis pigesnis uþ buvusá
        {
            min = C[i].men12; //prisikiriame pigiausià leidiná prie "min" kintamojo

            indeksas = i; //prisikiriame pigiausio leidinio indeksà
        }
    }
    return indeksas; //graþiname pigiausio leidinio indeksà
}