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
B)	SA AFISEZE PE URMATOAREA LINIE A ECRANULUI,
ULTIMA CIFRA A PRODUSULUI TUTUROR ELEMENTELOR MATRICEI
A SITUATE SUB DIAGONALA PRINCIPALA;
C)	SA SCRIE IN FISIERUL ATESTAT.OUT,
PE PRIMA LINIE, SEPARATE PRIN CATE UN SPATIU,
TOATE NUMERELE DE TIP PALINDROM DIN MATRICEA A.
UN NUMAR ESTE PALINDROM DACA NUMARUL
CITIT DE LA STANGA LA DREAPTA ESTE EGAL CU
NUMARUL CITIT DE LA DREAPTA LA STANGA,
DE EXEMPLU: 11, 22, 33.
DACA NU EXISTA ASTFEL DE NUMERE SE VA SCRIE PE PRIMA
LINIE A FISIERULUI MESAJUL "NU EXISTA".
*/
#include <bits/stdc++.h>

using namespace std;
ifstream fin("atestat11.in");
ofstream fout("atestat11.out");
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
    int pr=1;
    for(int i=1; i<=lv; ++i)
        for(int j=1; j<i; ++j)
            pr=(pr*a[i][j])%10;
    cout<<pr<<'\n';
}
int palindrom(int nr)
{
    int rast=0, aux=nr;
    while(aux)
    {
        rast=rast*10+aux%10;
        aux/=10;
    }
    if(rast==nr)
        return 1;
    return 0;
}
void subiectC(int v[20][20], int lv)
{
    int ok=0;
    for(int i=1; i<=lv; ++i)
        for(int j=1; j<=lv; ++j)
            if(palindrom(v[i][j]))
            {
                ok=1;
                fout<<v[i][j]<<" ";
            }
    if(!ok)
        fout<<"Nu exista";

}
int main()
{
    citireM(a,n);
    subiectA(a,n);
    subiectB(a,n);
    subiectC(a,n);
    return 0;
}
