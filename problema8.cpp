#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("atestat8.in");
ofstream fout("atestat8.out");

void citirev(int a[], int &la) /// se citesc numerele in vector
{
    fin>>la;

    for(int i=0; i<la; i++)
        fin>>a[i];
}

void sub_a(int a[], int la) /// se afiseaza elementele in ordine inversa a citirii
{
    for(int i=la-1; i>=0; i--)
        cout<<a[i]<<" ";

    cout<<'\n';
}

int cautb(int a[], int la, int val)
{
    int li=0, ls=la-1, mij; /// li=limita inferioara, ls=limita superioara

    do
    {
        mij=(li+ls)/2; /// se calculeaza pozitia de mijloc

        if(a[mij]==val) /// daca valoarea de pe pozitia de mijloc este egala cu valoarea cautata
            return mij; /// se returneaza pozitia ei

        else if(a[mij]<val) /// daca ea este mai mica, se muta cautarea in partea stanga
            ls=mij-1;

        else li=mij+1; /// altfel se muta cautarea in partea dreapta
    }while(li<=ls);

    return -1;
}

void sub_b(int a[], int la)
{
    int x;
    cin>>x;

    if(cautb(a, la, x)>=0)
        cout<<"DA";
    else
        cout<<"NU";
}

void sub_c(int a[], int la)
{
    int s=0;

    for(int i=0; i<la; i++)
        if(a[i]>0)
            s+=a[i];

    fout<<s;
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
