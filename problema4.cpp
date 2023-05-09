#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("atestat4.in");
ofstream fout("atestat4.out");

void citirev(int a[], int &la)
{
    fin>>la;
    for(int i=0; i<la; i++)
        fin>>a[i];
}

void sub_a(int a[], int la)
{
    int i;

    for(i=0; i<la; i++)
        if(a[i]%2==1)
            cout<<a[i]<<" ";

    cout<<'\n';
}

int doarcifrepare(int nr)
{
    while(nr)
    {
        if((nr%10)%2==1)
            return 0;
        nr/=10;
    }

    return 1;
}

void sub_b(int a[], int la)
{
    int ok=0; /// presupun ca nu am numar care contine doar cifre pare
    for(int i=0; i<la; i++) /// parcurg indicii vectorului
    {
        if(doarcifrepare(a[i])) /// daca valoarea de pe pozitia curenta are doar cifre pare
        {
            ok=1;/// presupunere falsa
            cout<<a[i]<<" ";/// se afiseaza
        }
    }

    if(!ok)/// daca presupunerea a ramas falsa afisez mesaj
        cout<<"Nu exista";
    cout<<'\n';
}

void sub_c(int nr)
{
    short int c[10], i;

    for(i=0 ; i<=9 ; i++) /// vector caracteristic cifre se initializeaza cu 0
        c[i]=0;
    while(nr) /// se parcurg toate cifrele numarului
    {
        c[nr%10]=1;/// se bifeaza cifra gasita in numar
        nr/=10;/// se elinia ultima cifra
    }

    for(i=9 ; i>0 ; i--)/// pentru cel mai mare numar parcurg cifrele de la 9 la 1
    {
        if(c[i]==1)/// daca cifra a fost bifata se afiseaza
            fout<<i;
    }
    fout<<" ";

    for(i=1; i<=9; i++)/// pentru cel mai mic numar cu cifre distincte si nenule
        if(c[i]==1)/// daca cifra a fost bifata se afiseaza
            fout<<i;
}

int n, i, v[31];
int main()
{
    citirev(v, n);/// citesc vectorul
    sub_a(v, n);/// rezolv subict a
    sub_b(v, n); /// rezolv subict b
    sub_c(v[0]); /// /// rezolv subict c
    return 0;
}
