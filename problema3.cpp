/**
FIşIERUL ATESTAT.IN CONţINE DOUă LINII.
PE PRIMA LINIE ESTE SCRIS UN NUMăR NATURAL NENUL N, (5<N<30). PE CEA DE-A DOUA LINIE A FIşIERULUI SUNT SCRISE N NUMERE NATURALE SEPARATE PRIN CâTE UN SPAţIU, FORMATE FIECARE DIN CEL MULT 9 CIFRE,  REPREZENTâND UN şIR DE N NUMERE NATURALE.
Să SE SCRIE UN PROGRAM îN LIMBAJUL PASCAL/C/C++, CARE:
A)	Să AFIşEZE PE PRIMA LINIE A ECRANULUI VALORILE
PARE DIN FIşIER, SEPARATE PRIN CâTE UN SPAţIU;
B)	Să AFIşEZE PE ECRAN, PE LINII DIFERITE,
CEL MAI MIC NUMăR A şI CEL MAI MARE NUMăR B DIN şIRUL DAT;
C)	Să SCRIE îN FIşIERUL ATESTAT.OUT
CEL MAI MARE DIVIZOR COMUN AL NUMERELOR A şI B,
DETERMINATE LA PUNCTUL B).

*/
#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("atestat3.in");
ofstream fout("atestat3.out");
int n, v[35], maxim, minim;
void citire(int a[], int &la)/// REFERINTA LA DIMENSIUNEA VECTORULUI
{
    int i;
    fin>>la;
    for(i=1; i<=la; i++)
        fin>>a[i];
}

void subiect_a(int a[], int la)
{
    for(int i=1; i<=la; i++)
        if(a[i]%2==0)/// daca numarul este par
            cout<<a[i]<<" ";/// afisez
    cout<<'\n';
}
void subiect_b(int a[20], int la, int &mare, int &mic)
{
    mare=mic=a[1];
    for(int i=2; i<=la; i++)
    {
        if(a[i]>mare)
            mare=a[i];
        if(a[i]<mic)
            mic=a[i];
    }
}
int gcd(int A, int B)/// ALGORITM EUCLID
{
    int r;
    while(B)
    {
        r=A%B;
        A=B;
        B=r;
    }
    return A;
}
int main()
{
    citire(v,n);
    subiect_a(v,n);
    subiect_b(v,n, maxim, minim);
    cout<<maxim<<" "<<minim<<'\n';
    fout<<gcd(maxim,minim);
    return 0;
}
