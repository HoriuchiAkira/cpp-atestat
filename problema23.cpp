/**
FISIERUL ATESTAT.IN CONTINE PE PRIMA LINIE
NUMARUL NATURAL NENUL N (2<N<10).
PE FIECARE DINTRE URMATOARELE N
LINII SUNT SCRISE CâTE DOUA NUMERE NATURALE X SI Y,
SEPARATE PRINTR-UN SPATIU,
REPREZENTâND COORDONATELE UNUI PUNCT DIN PLANUL XOY.
SA SE SCRIE UN PROGRAM, IN LIMBAJUL C++, CARE:
A) SA AFISEZE PE ECRAN PUNCTELE DIN PLANUL XOY,
CATE UNUL PE LINIE, SUB FORMA (X,Y);
B) SA AFISEZE PE URMATOAREA LINIE A ECRANULUI
NUMARUL PUNCTELOR CARE SUNT SITUATE PE AXA OX;
C) SA SCRIE IN FISIERUL ATESTAT.OUT,
PE LINII DISTINCTE, TOATE PUNCTELE DIN
FISIERUL ATESTAT.IN
CARE AU AMBELE COORDONATE PARE, SUB FORMA (X,Y).

*/
#include <bits/stdc++.h>

using namespace std;
ifstream fin("atestat23.in");
ofstream fout("atestat23.out");
struct punct
{
    int a, b;
};
punct v[11];
int n;
void citire_pct(punct x[], int &lx)
{
    fin>>lx;
    for(int i=1; i<=lx; ++i)
        fin>>x[i].a>>x[i].b;
}
void subA(punct x[], int lx)
{
    for(int i=1; i<=lx; ++i)
        cout<<"( "<<x[i].a<<", "<<x[i].b<<")\n";
}
void subB(punct x[], int lx)
{
    int nrpct=0;
    for(int i=1; i<=lx; ++i)
        if(x[i].b==0)   /// numere de pe axa Ox
            nrpct++;
    cout<<nrpct<<'\n';
}

void subC(punct x[], int lx)
{
    for(int i=1; i<=lx; ++i)
        if(x[i].a%2==0 && x[i].b%2==0)
            fout<<"( "<<x[i].a<<", "<<x[i].b<<")\n";
}
int main()
{
    citire_pct(v,n);
    subA(v,n);
    subB(v,n);
    subC(v,n);
    return 0;
}
