/**
FISIERUL ATESTAT.IN CONTINE PE PRIMA LINIE O VALOARE N
NUMAR NATURAL (1<N<10) IAR PE URMATOARELE N LINII
CATE UN CUVANT, FIECARE CUVANT FIIND FORMAT DIN LITERE MARI
ALE ALFABETULUI ENGLEZ.
SA SE SCRIE UN PROGRAM IN LIMBAJUL C++, CARE:
A) SA AFISEZE PE PRIMA LINIE A ECRANULUI,
CUVINTELE NUMAI CU LITERE MICI;
B) SA AFISEZE PE ECRAN,
CUVANTUL CU LUNGIME MAXIMA DINTRE CUVINTELE INTIALE
CITITE IN FISIER;
C) SA SCRIE PE PRIMA LINIE A FISIERULUI ATESTAT.OUT,
N+1 CARACTERE FORMATE DUPA REGULA:
PRIMUL CARACTER DIN SIR ESTE PRIMA LITERA DIN PRIMUL CUVâNT,
AL DOILEA CARACTER DIN SIR ESTE A DOUA LITERA DIN AL DOILEA CUVâNT,
AL TREILEA CARACTER DIN SIR ESTE A TREIA LITERA DIN AL TREILEA CUVâNT,ETC.
ULTIMUL CARACTER VA FI '.' (PUNCT).
DACA UNUL DINTRE CUVINTE NU ARE SUFICIENTE LITERE,
SIRUL REZULTAT VA CONTINE PE POZIþIA CORESPUNZATOARE UN SPATIU.

*/
#include <bits/stdc++.h>

using namespace std;
ifstream fin("atestat24.in");
ofstream fout("atestat24.out");
int n;
char v[10][30];
void citire(char a[10][30], int &la)
{
    fin>>la;
    for(int i=1; i<=la; ++i)
        fin>>a[i];
}
void subA(char a[10][30], int la)
{
    for(int i=1; i<=la; ++i)
    {
        for(int j=0; a[i][j]; ++j)
            cout<<(char)tolower(a[i][j]);
        cout<<' ';
    }
    cout<<'\n';
}
void subB(char a[10][30], int la)
{
    int l,lmax=0;
    char s[30];
    for(int i=1; i<=la; ++i)
    {
        l=strlen(a[i]);   /// lungimea fiecarui cuvant
        if(l>lmax)
        {
            lmax=l;
            strcpy(s,a[i]);
        }
    }
    cout<<s<<'\n';
}
void subC(char a[10][30], int la)
{
    for(int i=1; i<=la; ++i)
        if(a[i][i-1])
            cout<<a[i][i-1];
        else
            cout<<' ';
    cout<<'.';
}
int main()
{
    citire(v,n);
    subA(v,n);
    subB(v,n);
    subC(v,n);
    return 0;
}
