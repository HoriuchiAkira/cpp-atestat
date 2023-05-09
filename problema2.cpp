/**
FISIERUL ATESTAT2.IN CONTINE DOUA LINII.
PE PRIMA LINIE ESTE SCRIS UN NUMAR NATURAL NENUL N, (5<N<30).
PE CEA DE-A DOUA LINIE A FISIERULUI SUNT SCRISE N NUMERE
INTREGI POZITIVE SEPARATE PRIN CATE UN SPATIU,
FORMATE FIECARE DIN CEL MULT 4 CIFRE.
IN SIRUL DE VALORI VOR FI CEL PUTIN O VALOARE PARA SI UNA IMPARA.
SA SE SCRIE UN PROGRAM IN LIMBAJUL PASCAL/C/C++, CARE:
A)	SA AFISEZE PE PRIMA LINIE A ECRANULUI,
VALORILE DIN FISIER CARE SUNT NUMERE PRIME.
UN NUMAR ESTE PRIM DACA SI NUMAI DACA
ARE EXACT DOI DIVIZORI 1 SI NUMARUL INSUSI. 1 NU ESTE NUMAR PRIM.
B)SA AFISEZE PE A DOUA LINIE A ECRANULUI SEPARATE
PRIN CâTE UN SPATIU, CEA MAI MARE VALOARE PARA
SI CEA MAI MICA VALOARE IMPARA CARE APAR IN SIRUL
VALORILOR DIN FISIER;
C)
SA SCRIE IN FISIERUL ATESTAT2.OUT,
PENTRU CEA MAI MARE VALOARE PARA, MAX,
DETERMINATA LA PUNCTUL ANTERIOR DOUA
VALORI IMPARE PRIME CARE AU SUMA EGALA CU MAX.

*/
#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("atestat2.in");
ofstream fout("atestat2.out");
int n, v[31], minim, maxim;
void citire(int a[], int &la)/// REFERINTA LA DIMENSIUNEA VECTORULUI
{
    int i;
    fin>>la;
    for(i=1; i<=la; i++)
        fin>>a[i];
}
int prime(int x)
{
    if(x==2)
        return 1;
    if(x<2)
        return 0;
    if(!(x%2)) /// numere > 2 si pare
        return 0;
    for(int d=3; d*d<=x; d+=2) /// verific numerele impare
        if(!(x%d))
            return 0;
    return 1;
}
void subiect_a(int a[], int la)
{
    for(int i=1; i<=la; i++)
        if(prime(a[i]))/// daca numarul este prim
            cout<<a[i]<<" ";/// afisez
    cout<<'\n';
}
void subiect_b(int a[], int la, int &marep, int &mici)
{
    marep=0;
    mici=10000;
    for(int i=1; i<=la; i++)
    {
        if(a[i]%2==0)/// daca nr din vector este par
        {
            if(a[i]>marep) /// compar cu maxim
                marep=a[i];
        }
        else /// nr din vector este impar
        {
           if(a[i]<mici) /// compar cu minim
                mici=a[i];
        }
    }
}
void subiect_c(int x)
{
    int nr1=x-1, nr2=1;
    while(prime(nr1)==0 || prime(nr2)==0) /// cat timp nr1 sau nr2 nu-s prime
    {
        nr1-=2;
        nr2+=2;
    }
    fout<<nr1<<" "<<nr2;
}
int main()
{
    citire(v,n);
    subiect_a(v,n);
    subiect_b(v,n, maxim, minim);
    cout<<maxim<<" "<<minim;
    subiect_c(maxim);
    return 0;
}
