/**
FISIERUL ATESTAT.IN CONTINE PE PRIMA LINIE NUMARUL N,
NATURAL NENUL (2<N<10), CE REPREZINTA NUMARUL DE NODURI ALE UNUI GRAF NEORIENTAT.
PE URMATOARELE LINII PANA LA SFARSITUL FISIERULUI SUNT PERECHI DE VALORI
X Y CU SEMNIFICATIA NODUL X ESTE LEGAT PRINTR-O MUCHIE DE NODUL Y.
SA SE SCRIE UN PROGRAM, IN LIMBAJUL C++, CARE:
A) SA AFISEZE PE ECRAN ELEMENTELE MATRICEI DE ADIACENTA ATASATA GRAFULUI CITIT;
B) SA CITEASCA DE LA TASTATURA O SECVENTA DE NODURI
SI SA AFISEZE MESAJUL "DA" DACA SECVENTA DE NODURI ESTE LANT IN GRAF
SI "NU" IN CAZ CONTRAR;
C) SA CITEASCA DE LA TASTATURA VALOAREA UNUI NOD V
SI SA AFISEZE IN FISIERUL ATESTAT.OUT
CARE ESTE LISTA DE ADIACENTA A NODULUI CITIT.

*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin("atestat29.in");
ofstream fout("atestat29.out");
int n,a[10][10],v;
void citire_mat(int mat[10][10],int &ln)
{
    fin>>ln;
    int i,j;
    while(fin>>i>>j)
        mat[i][j]=mat[j][i]=1;
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
    int nr1, nr2, ok=1;/// presupun ca este lant
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
    }while(nr1 && ok);
    if(ok)
        cout<<"DA\n";
    else
        cout<<"NU\n";
}
void subC(int mat[10][10],int ln)
{
    cin>>v;
    for(int i=1; i<=ln;i++)
        if(mat[v][i])
            fout<<i<<" ";   /// lista de adiacenta a lui v
}
int main()
{
    citire_mat(a,n);
    subA(a,n);
    subB(a,n);
    subC(a,n);
    return 0;
}
