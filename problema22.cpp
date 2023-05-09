/**
FISIERUL ATESTAT.IN CONTINE PE PRIMA LINIE
NUMARUL NATURAL NENUL N (2<N<10).
PE URMATOARELE N LINII SUNT SCRISE
CATE DOUA NUMERE NATURALE NENULE A SI B,
REPREZENTâND NUMARATORUL (A) SI NUMITORUL (B) UNEI FRACTII ALGEBRICE.
CELE DOUA NUMERE SUNT SEPARATE PRINTR-UN SPATIU.
SA SE SCRIE UN PROGRAM, IN LIMBAJUL C++, CARE:
A) SA AFISEZE PE ECRAN, PE ACEEASI LINIE,
SEPARATE PRIN CATE UN SPATIU, CELE N FRACTII SUB FORMA A/B
(NUMARATOR/NUMITOR);
B)SA AFISEZE PE URMATOAREA LINIE A ECRANULUI PRIMA
FRACTIE CU NUMARATORUL MAXIM;
C) SA SCRIE PE PRIMA LINIE A FISIERULUI ATESTAT.OUT,
SEPARATE PRIN SPATIU, TOATE FRACTIILE IREDUCTIBILE
INCEPAND DIN A DOUA LINIE A FISIERULUI ATESTAT.IN,
SUB FORMA A/B.

*/
#include <bits/stdc++.h>

using namespace std;
ifstream fin("atestat22.in");
ofstream fout("atestat22.out");
struct fractie
{
    int a, b;
};
fractie v[11];
int n;
void citire_fr(fractie x[], int &lx)
{
    fin>>lx;
    for(int i=1; i<=lx; ++i)
        fin>>x[i].a>>x[i].b;
}
void subA(fractie x[], int lx)
{
    for(int i=1; i<=lx; ++i)
        cout<<x[i].a<<'/'<<x[i].b<<" ";
    cout<<'\n';
}
void subB(fractie x[], int lx)
{
    fractie maxim;
    maxim.a=x[1].a;
    maxim.b=x[1].b;
    int maxi=x[1].a;
    for(int i=2; i<=lx; ++i)
    {
        if(x[i].a>maxi)
        {
            maxi=x[i].a;
            maxim.a=x[i].a;
            maxim.b=x[i].b;
        }
    }
    cout<<maxim.a<<'/'<<maxim.b<<'\n';
}
int cmmdc(int y, int z)
{
    int r;
    while(z)
    {
        r=y%z;
        y=z;
        z=r;
    }
    return y;
}
void subC(fractie x[], int lx)
{
    for(int i=1; i<=lx; ++i)
        if(cmmdc(x[i].a, x[i].b)==1)
            fout<<x[i].a<<'/'<<x[i].b<<" ";
    fout<<'\n';
}
int main()
{
    citire_fr(v,n);
    subA(v,n);
    subB(v,n);
    subC(v,n);
    return 0;
}
