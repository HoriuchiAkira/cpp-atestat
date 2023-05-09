/**
FISIERUL ATESTAT.IN CONTINE PE PRIMA LINIE NUMARUL N,
NATURAL NENUL (2<N<10), CE REPREZINTA NUMARUL DE NODURI ALE UNUI GRAF ORIENTAT.
PE URMATOARELE LINII PANA LA SFARSITUL FISIERULUI SUNT PERECHI DE VALORI
X Y CU SEMNIFICATIA NODUL X ESTE LEGAT PRINTR-O MUCHIE DE NODUL Y.
SA SE SCRIE UN PROGRAM, IN LIMBAJUL C++, CARE:
A) SA AFISEZE PE ECRAN ELEMENTELE MATRICEI DE ADIACENTA ATASATA GRAFULUI CITIT;
B)	SA AFISEZE PE ECRAN TOATE NODURILE CARE AU PROPRIETATEA CA
NUMARUL ARCELOR CE PLEACA DIN NODUL RESPECTIV
ESTE EGAL CU NUMARUL ARCELOR CARE INTRA IN NODUL RESPECTIV.
(NODURILE CU GRADUL EXTERIOR EGAL CU CEL INTERIOR)
C)	SA CITEASCA DE LA TASTATURA O SECVENTA DE NODURI ALE GRAFULUI
SI SA AFISEZE IN FISIERUL ATESTAT.OUT,
MESAJUL "DA" DACA SECVENTA ESTE DRUM IN GRAFUL CITIT SI "NU" IN CAZ CONTRAR.

*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin("atestat30.in");
ofstream fout("atestat30.out");
int n, a[10][10], v;
void citire_mat(int mat[10][10],int &ln)
{
    fin>>ln;
    int i,j;
    while(fin>>i>>j)
        mat[i][j]=1;  /// graf orientat
}
void subA(int mat[10][10],int ln)
{
    int i,j;
    for(i=1; i<=ln; ++i)
    {
        for(j=1; j<=ln; ++j)
            cout<<mat[i][j]<<" ";
        cout<<'\n';
    }
}
void subB(int mat[10][10],int ln)
{
    int i, j, ok=0;
    for(i=1; i<=ln; ++i)
        for(j=1; j<=ln; ++j)
            mat[i][0]+=mat[i][j];
    for(j=1; j<=ln; ++j)
        for(i=1; i<=ln; ++i)
            mat[0][j]+=mat[i][j];
    for(i=1; i<=ln; ++i)
        if(mat[i][0]==mat[0][i])
        {
            cout<<i<<" ";
            ok=1;
        }
    if(!ok)
        cout<<"NU\n";
    cout<<'\n';
}
void subC(int mat[10][10],int ln)
{
    int nr1, nr2, ok=1;/// presupun ca este drum
    cin>>nr1;    /// citesc primul numar din sir
    do
    {
        cin>>nr2;
        if(nr2!=0)
        {
            if(mat[nr1][nr2]==0)  /// daca nu am muchie
                ok=0;
            nr1=nr2;
        }
        else
            break;
    }
    while(nr1 && ok);
    if(ok)
        fout<<"DA\n";
    else
        fout<<"NU\n";
}
int main()
{
    citire_mat(a,n);
    subA(a,n);
    subB(a,n);
    subC(a,n);
    return 0;
}
