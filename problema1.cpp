/**
FISIERUL ATESTAT.IN CONTINE DOUA LINII.
PE PRIMA LINIE ESTE SCRIS UN NUMAR NATURAL NENUL N, (5<N<15).
PE CEA DE-A DOUA LINIE A FISIERULUI SUNT
SCRISE N NUMERE INTREGI SEPARATE PRIN CâTE UN SPAţIU,
FORMATE FIECARE DIN CEL MULT 4 CIFRE,
REPREZENTâND UN SIR DE N INTREGI .
SA SE SCRIE UN PROGRAM IN LIMBAJUL PASCAL/C/C++, CARE:
A)SA AFISEZE PE PRIMA LINIE A ECRANULUI,
VALORILE DIN FISIER CARE SUNT NUMERE PALINDROAME.
UN NUMAR ESTE PALINDROM DACA SI NUMAI DACA ESTE EGAL
CU OGLINDITUL SAU. EXEMPLU 1221 ESTE PALINDROM.
B) SA AFISEZE PE A DOUA LINIE A ECRANULUI
SEPARATI PRIN CâTE UN SPATIU, NUMARUL DE DIVIZORI
PROPRII PENTRU FIECARE NUMAR DIN SIRUL DIN FISIER;
C) SA SCRIE IN FISIERUL ATESTAT.OUT, PE PRIMA LINIE,
TOATE NUMERELE IMPARE DIN SIR, SEPARATE PRIN CâTE UN SPATIU.
*/
#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("atestat1.in");
ofstream fout("atestat1.out");
int n, v[20];
void citire(int a[], int &la)/// REFERINTA LA DIMENSIUNEA VECTORULUI
{
    int i;
    fin>>la;
    for(i=1; i<=la; i++)
        fin>>a[i];
}
int palindrom(int x)/// verifica palindroame ...
{
    if(x<10) /// TOATE CIFRELE SUNT PALINDROAME
        return 1;
    int aux=x, rast=0;
    while(aux)/// CALCULEZ RASTURNAT
    {
        rast=rast*10+aux%10;
        aux/=10;
    }
    if(x==rast)
        return 1;
    else
        return 0;
}
int divizori_proprii(int x)/// CALCULEAZA DIVIZORI PROPRII
{
    int d, nrd=0;
    for(d=2; d*d<=x; d++)
        if(x%d==0) /// d DIVIDE PE x
        {
            nrd++;/// SE NUMARA
            if(d*d<x) /// DACA d SI x/d SUNT DIFERITI SE NUMARA SI x/d
                nrd++;
        }
    return nrd;
}
void subiect_a(int a[20], int la)
{
    for(int i=1; i<=la; i++)
        if(palindrom(a[i]))/// daca numarul este palindrom
            cout<<a[i]<<" ";/// afisez
    cout<<'\n';
}
void subiect_b(int a[20], int la)
{
    for(int i=1; i<=la; i++)/// parcurg vectorul si afisez nr de div proprii
        cout<<divizori_proprii(a[i])<<" ";
    cout<<'\n';
}
void subiect_c(int a[20], int la)
{
    for(int i=1; i<=la; i++)
        if(a[i]%2)
            fout<<a[i]<<" ";
}
int main()
{
    citire(v,n);
    subiect_a(v,n);
    subiect_b(v,n);
    subiect_c(v,n);
    return 0;
}
