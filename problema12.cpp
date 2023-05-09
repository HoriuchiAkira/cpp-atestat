/**
FISIERUL ATESTAT.IN CONTINE PE PRIMA LINIE NUMARUL N,
NATURAL NENUL (2<N<20), CE REPREZINTA NUMARUL DE LINII
SI COLOANE ALE UNEI MATRICE PATRATICE A.
PE FIECARE DIN URMATOARELE N LINII,
SUNT SCRISE CâTE N NUMERE NATURALE,
SEPARATE PRIN CâTE UN SPATIU,
REPREZENTâND VALORILE ELEMENTELOR MATRICEI PATRATICE A.
SA SE SCRIE UN PROGRAM, IN LIMBAJUL PASCAL/C/C++, CARE:
A)	SA AFISEZE PE ECRAN ELEMENTELE MATRICEI A,
LINIE CU LINIE, ELEMENTELE DE PE ACEEASI
LINIE FIIND SEPARATE PRIN CâTE UN SPATIU;
B)	SA AFISEZE PE URMATOAREA LINIE A ECRANULUI
SUMA ELEMENTELOR MATRICEI A SITUATE PE DIAGONALA SECUNDARA;
C)SA SCRIE IN FISIERUL ATESTAT.OUT,
PE PRIMA LINIE, SEPARATE PRIN CâTE UN SPATIU,
MINIMELE DE PE FIECARE LINIE A MATRICEI.

*/
#include <bits/stdc++.h>

using namespace std;
ifstream fin("atestat12.in");
ofstream fout("atestat12.out");
int a[20][20],n;
void citireM(int v[20][20], int &lv)
{
    fin>>lv;
    for(int i=1; i<=lv; ++i)
        for(int j=1; j<=lv; ++j)
            fin>>v[i][j];
}
void subiectA(int v[20][20], int lv)
{
    for(int i=1; i<=lv; ++i)
    {
        for(int j=1; j<=lv; ++j)
            cout<<v[i][j]<<" ";
        cout<<'\n';
    }
}
void subiectB(int v[20][20], int lv)
{
    int suma=0;
    for(int i=1; i<=lv; ++i)
        suma+=v[i][lv-i+1];/// diagonala secundara i+j==lv+1
    cout<<suma<<'\n';
}

void subiectC(int v[20][20], int lv)
{
    for(int i=1; i<=lv; ++i)
    {
        int minim=v[i][1]; /// PRES. CA PRIMUL ELEMENT DE PE FIECARE LINIE ESTE MINIM
        for(int j=2; j<=lv; ++j)
            if(v[i][j]<minim)
                minim=v[i][j];
        fout<<minim<<" ";
    }
}
int main()
{
    citireM(a,n);
    subiectA(a,n);
    subiectB(a,n);
    subiectC(a,n);
    return 0;
}
