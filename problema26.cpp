/**FISIERUL ATESTAT.IN CONTINE PE PRIMA LINIE NUMARUL N,
 NATURAL NENUL (2<N<10), CE REPREZINTA NUMARUL DE NODURI
  ALE UNUI GRAF ORIENTAT. PE URMATOARELE LINII PâNA LA
  SFâRSITUL FISIERULUI SUNT PERECHI DE VALORI X Y CU
  SEMNIFICATIA NODUL X ESTE LEGAT PRINTR-O MUCHIE DE NODUL Y.
SA SE SCRIE UN PROGRAM, IN LIMBAJUL C++, CARE:
A)	SA AFISEZE PE ECRAN ELEMENTELE MATRICEI DE ADIACENTA
ATASATA GRAFULUI CITIT;
B)	SE CITESTE UN VARF V SI SE AFISEAZA GRADUL INETRIOR
SI GRADUL EXTERIOR.
C) SA AFISEZE IN FISIERUL ATESTAT.OUT,
DACA EXISTA, TOATE DRUMURILE
DE LUNGIME 2 CARE PLEACA DIN VâRFUL V, V CITIT DE LA TASTATURA
*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin("atestat26.in");
ofstream fout("atestat26.out");
int n, m, a[10][10];
void citire(int mat[10][10],int &ln)
{
    fin>>ln;
    int i,j;
    m=0;   /// numara arce
    while(fin>>i>>j)
    {
        ++m;
        mat[i][j]=1;
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
    int V,i, j, gri=0, gre=0;
    cin>>V;
    for(j=1;j<=ln;++j)    /// se parcurge linia V pentru grad exterior
        gre+=mat[V][j];
    for(i=1; i<=ln; ++i)
        gri+=mat[i][V]; /// se parcurge coloana V pentru grad interior
    cout<<gri<<" "<<gre<<'\n';

}
void subC(int mat[10][10],int ln)
{
    int V, i, j, ok=0;
    cin>>V;
    for(j=1; j<=ln; ++j)  /// coloane de pe linia V
        if(mat[V][j]) /// daca am arc
        {
            for(i=1; i<=ln; ++i) /// parcurg coloanele de pe linia j
                if(mat[j][i]) /// daca am arc
                {
                    cout<<V<<" "<<j<<" "<<i<<'\n';
                    ok=1;
                }
        }
    if(!ok)
        cout<<"Nu exista drum de lungime 2 de la varful:  "<<V<<'\n';
}
int main()
{
    citire(a,n);
    subA(a,n);
    subB(a,n);
    subC(a,n);
    return 0;
}
