/**
2*3*5=30
42=2*3*7
700=2^2 * 5^2 * 7
*/
#include<bits/stdc++.h>
using namespace std;

ifstream fin("atestat5.in");
ofstream fout("atestat5.out");


void citirev(int a[], int &la)
{
    fin>>la;
    for(int i=0; i<la; i++)
        fin>>a[i];
}

void sub_a(int a[], int la)
{
    for(int i=0; i<la; i++)/// parcurg indicii vectorului
        if(a[i]%2==0)/// daca valoarea curenta este para
            cout<<a[i]<<" ";/// afisez

    cout<<'\n';
}

int doarcifreimpare(int nr)
{
    while(nr)
    {
        if((nr%10)%2==0)/// daca cifra este para
            return 0;/// returnez rezultatul NU

        nr/=10;/// elimin ultima cifra
    }

    return 1;///daca am ajuns aici numarul meu are doar cifre impare
}

void sub_b(int a[], int la)
{
    int ok=0;/// presupun ca nu sunt numare cu doar cifre impare

    for(int i=0; i<la; i++)/// parcurg indicii vectorului
    {
        if(doarcifreimpare(a[i]))/// daca valoarea curenta respecta cerinta
        {
            ok=1;/// se neaga presupunerea
            cout<<a[i]<<" ";/// afisez
        }
    }

    if(!ok)/// daca nu am afisat nici un numar afisez mesaj
        cout<<"Nu exista";

    cout<<'\n';
}

int kdivprimi(int k, int x)/// se cer k divizori primi distincti
{
    int d=2, nrdiv=0, p=0;
    while(x%2==0)/// daca numarul se divide cu 2 ( primul divizor prim si singurul par)
    {
        p++;
        x/=2;
    }
    if(p) /// daca numarul se divide cu 2 ...
        nrdiv++;/// il numar pe 2 ca divizor prim
    for(d=3; d*d<=x; d+=2)  /// parcurg numerele impare pana la radacina patrata
    {
        if(x%d==0)/// daca numarul se divide cu d
        {
            nrdiv++;/// il numar pe d ca divizor
            while(x%d==0)
                x/=d;
        }
        if(nrdiv>k) /// daca numarul de div primi distincti depaseste k
            return 0; /// x nu corespunde cerintei
    }
    if(x>1)/// daca nu am gasit toti divizorii primi, numarul este prim
        nrdiv++;/// se numara
    if(nrdiv==k)/// daca x are k div primi distincti ...
        return 1;
    return 0; /// numere cu nr div primi distincti < k ....
}

void sub_c(int a[], int la)
{
    int k1;
    cin>>k1;
    for(int i=0; i<la; i++)
        if(kdivprimi(k1, a[i])==1)
            fout<<a[i]<<" ";
}

int v[30], n;
int main()
{
    citirev(v, n);
    sub_a(v, n);
    sub_b(v, n);
    sub_c(v, n);
    return 0;
}
