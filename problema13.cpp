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
B)	SA CITEASCA DE LA TASTATURA
UN NUMAR NATURAL K DE CEL MULT 9 CIFRE SI
SA VERIFICE DACA ACESTA SE GASESTE IN MATRICEA A,
AFISANDU-SE PE ECRAN UN MESAJ CORESPUNZATOR;
C)	SA MODIFICE MATRICEA A PRIN ATRIBUIREA VALORII
0 TUTUROR ELEMENTELOR SITUATE PE ULTIMA LINIE A
MATRICEI SI APOI SA SE SCRIE IN FISIERUL ATESTAT.OUT
MATRICEA REZULTATA, LINIE CU LINIE, ELEMENTELE DE
PE ACEEASI LINIE FIIND SEPARATE PRIN CâTE UN SPATIU.


*/
#include <bits/stdc++.h>

using namespace std;
ifstream fin("atestat13.in");
ofstream fout("atestat13.out");
int a[10][10],n;
void citireM(int v[10][10], int &lv)
{
    fin>>lv;
    for(int i=1; i<=lv; ++i)
        for(int j=1; j<=lv; ++j)
            fin>>v[i][j];
}
void subiectA(int v[10][10], int lv)
{
    for(int i=1; i<=lv; ++i)
    {
        for(int j=1; j<=lv; ++j)
            cout<<v[i][j]<<" ";
        cout<<'\n';
    }
}
void subiectB(int v[10][10], int lv)
{
    int K, ok=0;
    cin>>K;
    for(int i=1; i<=lv && !ok; ++i)
        for(int j=1; j<=lv && !ok; ++j)
            if(v[i][j]==K)
                ok=1;
    if(ok)
        cout<<"DA\n";
    else
        cout<<"NU\n";
}
void afisareF(int v[10][10], int lv)
{
    for(int i=1; i<=lv; ++i)
    {
        for(int j=1; j<=lv; ++j)
            fout<<v[i][j]<<" ";
        fout<<'\n';
    }
}
void subiectC(int v[10][10], int lv)
{
    for(int i=1; i<=lv; ++i)
        v[lv][i]=0;
    afisareF(v,lv);
}
int main()
{
    citireM(a,n);
    subiectA(a,n);
    subiectB(a,n);
    subiectC(a,n);
    return 0;
}
