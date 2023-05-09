#include<bits/stdc++.h>
using namespace std;

ifstream fin("atestat7.in");
ofstream fout("atestat7.out");

void citirev(int a[], int &la)  /// citirea nuemrelor din fisier in vector
{
    fin>>la;
    for(int i=1; i<=la; i++)
        fin>>a[i];
}

void sub_a(int a[31], int la)  /// afisare invers citirii
{
    int i;
    for(i=la; i>=1; i--) /// parcurg indicii de la dreapta la stanga
        cout<<a[i]<<" ";
    cout<<'\n';
}
int numar_cifre(int x)
{
    int nrc=0;
    do
    {
        nrc++;   /// se numara fiecare cifra a numarului x
        x/=10;  /// se elimina ultima cifra

    }while(x);   /// cat timp mai am cifre
    return nrc;   /// se returmeaza numarul de cifre a lui x
}
void sub_b(int a[31], int la)
{
    for(int i=1; i<=la; i++) /// parcurg indicii vectorului
        cout<<numar_cifre(a[i])<<" "; /// afisez numar cifre pozitie curenta
    cout<<'\n';
}

int sub_c(int a[], int la)
{
    int i, s=0;
    for(i=1; i<=la; i++)/// parcurg pozitii vector de la 1 la la ...
        if(a[i]%2)/// numere impare pe pozitia curenta
            s+=a[i];/// se aduna la suma
    return s;
}

int main()
{

    int n;
    int v[31];
    citirev(v, n);
    sub_a(v, n);
    sub_b(v, n);
    fout<<sub_c(v, n);
    return 0;
}
