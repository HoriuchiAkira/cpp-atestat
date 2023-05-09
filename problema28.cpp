/**FISIERUL ATESTAT.IN CONTINE PE PRIMA LINIE NUMARUL N,
 NATURAL NENUL (2<N<10), CE REPREZINTA NUMARUL DE NODURI
  ALE UNUI GRAF NEORIENTAT. PE URMATOARELE LINII PâNA LA
  SFâRSITUL FISIERULUI SUNT PERECHI DE VALORI X Y CU
  SEMNIFICATIA NODUL X ESTE LEGAT PRINTR-O MUCHIE DE NODUL Y.
SA SE SCRIE UN PROGRAM, IN LIMBAJUL PASCAL/C/C++, CARE:
A)	SA AFISEZE PE ECRAN ELEMENTELE MATRICEI DE ADIACENTA
ATASATA GRAFULUI CITIT;
B)	SA AFISEZE PE ECRAN, NODUL SAU NODURILE CARE AU GRADUL MAXIM;
C)	SA MODIFICE MATRICEA A ASTFEL INCâT NODUL V, VALOAREA
V VA FI CITITA DE LA TASTATURA, SA DEVINA NOD IZOLAT, IAR
MATRICEA ASTFEL MODIFICATA SA O AFISEZE IN FISIERUL ATESTAT.OUT.
*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin("atestat28.in");
ofstream fout("atestat28.out");
int n,m,a[10][10],V;
void citire_mat(int mat[10][10],int &ln)
{
    fin>>ln;
    int i,j;
    m=0;
    while(fin>>i>>j)
    {
        ++m;
        mat[i][j]=mat[j][i]=1;
    }
}
void subA(int mat[10][10],int ln)
{
    int i,j;
    for(i=1;i<=ln;++i)
    {
        for(j=1;j<=ln;++j)
            cout<<mat[i][j]<<" ";
        cout<<'\n';
    }
}
void subB(int mat[10][10],int ln)
{
    int gr,j,i,maxim=0,mx[10];
    for(i=1;i<=ln;++i)
    {
        gr=0;
        for(j=1;j<=ln;++j)
            gr+=mat[i][j];
        if(gr>maxim) ///stabilim gradul maxim
            maxim=gr;
        mx[i]=gr;
        mx[i]=gr;///se memoreazagrsdul

    }
    for(i=1;i<=ln;++i)
        if(mx[i]==maxim)
            cout<<i<<" ";
            cout<<'\n';
}
void subC(int mat[10][10],int ln)
{
    int i,j;
    cin>>V;
    for(j=1;j<=ln;++j)
        mat[V][j]=0;
    for(i=1;i<=ln;++i)
    {
        for(j=1;j<=ln;++j)
            fout<<mat[i][j]<<" ";
        fout<<'\n';
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
