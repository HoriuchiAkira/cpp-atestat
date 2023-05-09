/**
FISIERUL ATESTAT.IN CONTINE PE PRIMA LINIE NUMARUL N,
NATURAL NENUL (2<N<20), CE REPREZINTA NUMARUL DE LINII
SI COLOANE ALE UNEI MATRICE PATRATICE A.
PE FIECARE DIN URMATOARELE N LINII,
SUNT SCRISE CâTE N NUMERE REALE,
SEPARATE PRIN CATE UN SPATIU,
REPREZENTAND VALORILE ELEMENTELOR MATRICEI PATRATICE A.
SA SE SCRIE UN PROGRAM, IN LIMBAJUL PASCAL/C/C++, CARE:
A)	SA AFISEZE PE ECRAN ELEMENTELE MATRICEI A,
LINIE CU LINIE, ELEMENTELE DE PE ACEEASI
LINIE FIIND SEPARATE PRIN CâTE UN SPATIU;
B)	SA AFISEZE PE URMATOAREA LINIE A ECRANULUI,
MEDIA ARITMETICA A ELEMENTELOR DE PE DIAGONALA PRINCIPALA;
C)	SA DETERMINE SUMA ELEMENTELOR MATRICEI
SITUATE PE LINIA K,
UNDE K (0<K<=N) ESTE UN NUMAR NATURAL
CITIT DE LA TASTATURA SI SA SCRIE PE
PRIMA LINIE A FISIERULUI ATESTAT.OUT
VALOAREA ACESTEI SUME.


*/
#include <bits/stdc++.h>

using namespace std;
ifstream fin("atestat14.in");
ofstream fout("atestat14.out");
int n;
float a[11][11];
void citireM(float v[11][11], int &lv)
{
    fin>>lv;
    for(int i=1; i<=lv; ++i)
        for(int j=1; j<=lv; ++j)
            fin>>v[i][j];
}
void subiectA(float v[11][11], int lv)
{
    for(int i=1; i<=lv; ++i)
    {
        for(int j=1; j<=lv; ++j)
            cout<<v[i][j]<<" ";
        cout<<'\n';
    }
}
void subiectB(float v[11][11], int lv)
{
    float ma=0.0;
    for(int i=1; i<=lv; ++i)
        ma+=v[i][i];
    ma=ma/((float)lv);
    cout<<ma<<'\n';
}

void subiectC(float v[11][11], int lv)
{
    int k;
    float suma=0;
    do   /// citire cu validare
    {
        cout<<"k= ";
        cin>>k;

    }while(k>lv);
    for(int j=1; j<=lv; ++j)
        suma+=v[k][j];
    fout<<suma;
}
int main()
{
    citireM(a,n);
    subiectA(a,n);
    subiectB(a,n);
    subiectC(a,n);
    return 0;
}
