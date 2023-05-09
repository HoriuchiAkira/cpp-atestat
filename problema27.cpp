/**
FISIERUL ATESTAT.IN CONTINE PE PRIMA LINIE NUMARUL N,
NATURAL NENUL (2<N<10),
CE REPREZINTA NUMARUL DE NODURI ALE UNUI GRAF NEORIENTAT.
PE URMATOARELE LINII PANA LA SFARSITUL FISIERULUI
SUNT PERECHI DE VALORI X Y CU SEMNIFICATIA MUCHIA (X, Y)
APARTINE GRAFULUI.
SA SE SCRIE UN PROGRAM, IN LIMBAJUL PASCAL/C/C++, CARE:
A)	SA AFISEZE PE ECRAN ELEMENTELE MATRICEI DE ADIACENTA
ATASATA GRAFULUI CITIT;
b)	SA AFISEZE PE ECRAN, DACA EXISTA, NODURILE IZOLATE ALE GRAFULUI;
C)	SA MODIFICE MATRICEA A ASTFEL INCAT NODUL V,
VALOAREA V VA FI CITITA DE LA TASTATURA,
SA FIE ADIACENT CU TOATE CELELALTE NODURI,
IAR MATRICEA ASTFEL
MODIFICATA SA O AFISEZE IN FISIERUL ATESTAT.OUT.

*/
#include <bits/stdc++.h>

using namespace std;
ifstream fin("atestat27.in");
ofstream fout("atestat27.out");
int n, m, a[10][10], V;
void citire_mat(int mat[10][10], int &ln)
{
    fin>>ln;
    int i, j;
    m=0;
    while(fin>>i>>j)
    {
        ++m;
        mat[i][j]=mat[j][i]=1;
    }
}
void subA(int mat[10][10], int ln)
{
    int i, j;
    for(i=1; i<=ln; ++i)
    {
        for(j=1; j<=ln; ++j)
            cout<<mat[i][j]<<" ";
        cout<<'\n';
    }
}
void subB(int mat[10][10], int ln)
{
    int gr, ok=0, i, j;
    for(i=1; i<=ln; i++)
    {
        gr=0;
        for(j=1; j<=ln; ++j)
            gr+=a[i][j];
        if(gr==0)
            ok=i;
    }
    cout<<ok<<'\n';
}
void subC(int mat[10][10], int ln)
{
    int V, i, j;
    cin>>V;
    for(j=1; j<=ln; ++j)
        if(j!=V)
            a[V][j]=1;
    for(i=1; i<=ln; ++i)
    {
        for(j=1; j<=ln; ++j)
            cout<<mat[i][j]<<" ";
        cout<<'\n';
    }
}
int main()
{
    citire_mat(a,n);
    subA(a,n);
    subB(a,n);
    subC(a,n);
    return 0;
}

