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

    int n = 1; //pradedame nuo 1, nes paskutin�je eilut�je ned�jome "Enter", tod�l n�ra simbolio '\n'
    int m = 1;
    int k = 0; //pradedame nuo 0, nes neskaitome i� failo, o prisiskiriame funkcijoje

    int indeksas; //kintamasis pigiausio leidinio indekui

    ofstream fr(CRfv);
    fr.close(); //i�valome rezultat� fail�

    Skaityti(CDfva, A, n); //duomen� skaitymo � masyv� funkcija (i� failo "LeidiniaiS.txt")
    Spausdinti(A, n, "Pradiniai duomenys is failo 'LeidiniaiS.txt'"); //duomen� spausdinimo funkcija

    Skaityti(CDfvb, B, m); //duomen� skaitymo � masyv� funkcija (i� failo "LeidiniaiN.txt")
    Spausdinti(B, m, "Pradiniai duomenys is failo 'LeidiniaiN.txt'"); //duomen� spausdinimo funkcija

    Koreguoti(A, n, B, m); //koregavimo funkcija
    MenesioKainos(A, n, C, k); //naujo masyvo sudarimo ir menesio kain� apskai�iavimo funkcija
    Rikiuoti(C, k); //rikiavimo funkcija
    indeksas = PigiausiasLeidinys(C, k); //pigiausio leidinio radimo funkcija

    SpausdintiRez(C, k, "Sutvarkytas laikrasciu ir zurnalu kainorastis", indeksas); //rezultat� spausdinimo funkcija

    return 0;
}

void Skaityti(const char fv[], Leidiniai A[], int& n)
{
    ifstream fd(fv); //atidarome duomen� fail�

    char eil[CPav + 1];

    //========= Susirandame kiek duomen� duota faile ================

    fd.ignore(80, '\n');

    while (!fd.eof()) //kol failas n�ra tu��ias
    {
        fd.ignore(80, '\n');
        n++; //skai�iuojame skirting� leidini� kiek�
    }

    fd.close();
    //===============================================================

    fd.open(fv); //atidarome fail� i� naujo

    for (int i = 0; i < n; i++)
    {
        fd.get(eil, CPav);
        A[i].pav = eil; //�sivedame laikra��io pavadinim� � struktur�

        fd >> A[i].kiek >> A[i].kaina; //isivedame laikra��io kiek� per m�nes� ir vieno vnt. kain�

        fd.ignore(80, '\n'); //pereiname � kit� eilut�
    }

    fd.close(); //u�darome duomen� fail�
}

void Spausdinti(Leidiniai A[], int n, string komentaras)
{
    ofstream fr(CRfv, ios::app); //atidarome ir leid�iame pildyti rezultat� fail�

    fr << komentaras << endl; //spausdiname reikiam� komentar�
    fr << "====================================================================" << endl;
    fr << " Leidinio pav.     Kiek kartu iseina per men.    Vieno egz. kaina   " << endl;
    fr << "====================================================================" << endl;

    for (int i = 0; i < n; i++)
    {
        fr << setw(30) << left << A[i].pav << setw(28) << A[i].kiek << setw(20) << A[i].kaina << endl; //spausdiname duomenis eilut�mis lentel�je
    }

    fr << "====================================================================" << endl;
    fr << endl << endl;

    fr.close(); //u�darome rezultat� fail�
}

void SpausdintiRez(Kainos C[], int k, string komentaras, int indeksas)
{
    ofstream fr(CRfv, ios::app); //atidarome ir leid�iame pildyti rezultat� fail�

    fr << komentaras << endl; //spausdiname reikiam� komentar�
    fr << "==================================================================================================================================" << endl;
    fr << " Leidinio pav.     Kiek kartu iseina per men.    Vieno egz. kaina          3 men. kaina        6 men. kaina       12 men. kaina   " << endl;
    fr << "==================================================================================================================================" << endl;

    for (int i = 0; i < k; i++) 
    {    
        fr << setw(30) << left << C[i].pav << setw(28) << C[i].kiek << setw(20) << C[i].kaina
            << setw(20) << C[i].men3 << setw(20) << C[i].men6 << setw(20) << C[i].men12 << endl;
        //spausdiname rezultatus eilutemis lenteleje, taip pat spausdiname m�nesio kainas
    }

    fr << "==================================================================================================================================" << endl;
    fr << "Pigiausias leidinys metinei prenumeratai: " << C[indeksas].pav << endl; //spausdiname pigiausio laikra��io pavadinim�
    fr << "Jis, metams, kainuoja: " << C[indeksas].men12 << endl; //spausdiname pigiausio laikra��io metin� kain�
    fr << endl;

    fr.close(); //u�darome rezultat� fail�
}


void Koreguoti(Leidiniai A[], int & n, Leidiniai B[], int m)
{
    int z; //kintamasis kuriuo patikrinsime ar yra nauj� laikra��i� kataloge

    if (n > m) //...jei n�ra nauj� laikra��i�...
    {
        z = n; //...prisiskiriame kintam�j�
    }
    else //...jei yra nauj� laikra��i�...
    {
        z = m; //...prisiskiriame kintam�j�
    }

    for (int i = 0; i < z; i++)
    {
        //Koreguojame nauj� laikra��io kain�
        if (A[i].pav == B[i].pav && A[i].kaina != B[i].kaina)
        {
            A[i].kaina = B[i].kaina;
        }

        //Koreguojame nauj� laikra��io leidini� kiek�
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
        C[i].pav = A[i].pav; //naujam masyvui prisiskiriame leidinio pavadinim�

        C[i].kiek = A[i].kiek; //naujam masyvui prisiskiriame leidini� kiek� per m�nes�
        C[i].kaina = A[i].kaina; //naujam masyvui prisiskiriame leidinio 1 vnt. kain�

        C[i].men3 = (C[i].kaina * C[i].kiek) * 3; 
        C[i].men6 = (C[i].kaina * C[i].kiek) * 6;
        C[i].men12 = (C[i].kaina * C[i].kiek) * 12;
        //suskai�iuojame kiek leidinys kainuos perkant 3/6/12 m�nesi� naudojant formul�
        //(vnt. kaina * leidiniai per m�nes�) * laikotarpis

        k++; //skai�iojame skirting� leidini� kiek�
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
                C[j - 1].pav = pav; //surikiuojame leidini� pavadinimus

                kiek = C[j].kiek;
                C[j].kiek = C[j - 1].kiek;
                C[j - 1].kiek = kiek; //surikiuojame leidini� kiek� per m�nes�

                kaina = C[j].kaina;
                C[j].kaina = C[j - 1].kaina;
                C[j - 1].kaina = kaina; //surikiuojame leidinio 1 vnt. kain�

                men3 = C[j].men3;
                C[j].men3 = C[j - 1].men3;
                C[j - 1].men3 = men3; //surikiuojame leidinio kain� per 3 m�nesius

                men6 = C[j].men6;
                C[j].men6 = C[j - 1].men6;
                C[j - 1].men6 = men6; //surikiuojame leidinio kain� per 6 m�nesius

                men12 = C[j].men12;
                C[j].men12 = C[j - 1].men12;
                C[j - 1].men12 = men12; //surikiuojame leidinio kain� per 12 m�nesi�
            }
        }
    }
}

int PigiausiasLeidinys(Kainos C[], int k)
{
    int min = 9999; //laikinas kintamasis kuriuo tikrinsime pigiausi� leidin�
    int indeksas; //kintamasis kuriame laikysime pigiausio leidinio indeks�

    for (int i = 0; i < k; i++)
    {
        if (C[i].men12 < min) //tikriname ar laikra�tis pigesnis u� buvus�
        {
            min = C[i].men12; //prisikiriame pigiausi� leidin� prie "min" kintamojo

            indeksas = i; //prisikiriame pigiausio leidinio indeks�
        }
    }
    return indeksas; //gra�iname pigiausio leidinio indeks�
}