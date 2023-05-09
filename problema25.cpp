/**FISIERUL ATESTAT.IN CONTINE PE PRIMA LINIE NUMARUL N,
 NATURAL NENUL (2<N<10), CE REPREZINTA NUMARUL DE NODURI
  ALE UNUI GRAF NEORIENTAT. PE URMATOARELE LINII PâNA LA
  SFâRSITUL FISIERULUI SUNT PERECHI DE VALORI X Y CU
  SEMNIFICATIA NODUL X ESTE LEGAT PRINTR-O MUCHIE DE NODUL Y.
SA SE SCRIE UN PROGRAM, IN LIMBAJUL PASCAL/C/C++, CARE:
A)	SA AFISEZE PE ECRAN ELEMENTELE MATRICEI DE ADIACENTA
ATASATA GRAFULUI CITIT;
B)	SA CITEASCA DE LA TASTATURA O SECVENTA DE NODURI SI SA
AFISEZE MESAJUL "DA" DACA SECVENTA DE NODURI ESTE LANT IN
GRAF SI "NU" IN CAZ CONTRAR;
C)	SA CITEASCA DE LA TASTATURA VALOAREA UNUI NOD V SI SA
AFISEZE IN FISIERUL ATESTAT.OUT CARE ESTE LISTA DE ADIACENTA
 A NODULUI CITIT.

*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin("atestat25.in");
ofstream fout("atestat25.out");
int n,m,a[10][10];
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
    int V,j,gr=0;
    cin>>V;
    for(j=1;j<=ln;++j)
        gr+=mat[V][j];
    cout<<gr<<'\n';

}
void subC(int mat[10][10],int ln)
{
    int i,j;
    for(i=1;i<=ln;++i)
    for(j=1;j<=ln;++j)
        if(i!=j)
            mat[i][j]=1; ///am construit matricea unui graf complet
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
