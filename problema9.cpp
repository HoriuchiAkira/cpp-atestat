#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("atestat9.in");
ofstream fout("atestat9.out");

void citirem(int a[20][20], int &la) /// citim dimensiunea si matricea patratica
{
    fin>>la;

    for(int i=0; i<la; i++) /// parcurgem indicii liniilor
        for(int j=0; j<la; j++) /// parcurgem indicii coloanelor
            fin>>a[i][j]; /// citim valoarea de pe pozitia curenta
}

void sub_a(int a[20][20], int la) /// se afiseaza matricea
{
    for(int i=0; i<la; i++) /// parcurgem indicii liniilor
    {
        for(int j=0; j<la; j++) /// parcurgem indicii coloanelor
            cout<<a[i][j]<<" "; /// afisez valoarea curenta

        cout<<'\n'; /// dupa afisarea valorilor de pe fiecare linie, se trece la linie noua
    }
}

void sub_b(int a[20][20], int la)
{
    int k;
    cin>>k;

    for(int i=0; i<la; i++) /// se parcurg indicii liniilor
        a[i][la-i-1]=k; /// valoarea de pe diagonala secundara ia valoarea k

    sub_a(a, la);
}

int prim(int nr)
{
    if(nr==2) /// 2 este primul si singurul numar par prim
        return 1;

    if(nr<2) /// o si 1 nu sunt prime
        return 0;

    if(nr%2==0) /// numerele pare nu sunt prime
        return 0;

    for(int d=3; d*d<=nr; d+=2) /// parcurg numerele impare de la 3 pana la radacina patrata a numarului
        if(nr%d==0) /// daca am gasit un divizor, nr nu este prim
            return 0;

    return 1; /// daca am ajuns aici, numarul nostru este prim
}

void sub_c(int a[20][20], int la)
{
    for(int i=0; i<la; i++) /// parcurgem indicii liniilor
        for(int j=0; j<la; j++) /// parcurgem indicii coloanelor
            if(prim(a[i][j])==1) /// daca elementul de pe pozitia curenta este prim
                fout<<a[i][j]<<" "; /// se afiseaza
}

int mat[20][20], n;
int main()
{
    citirem(mat, n);
    sub_a(mat, n);
    sub_b(mat, n);
    sub_c(mat, n);

    return 0;
}
