#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("atestat10.in");
ofstream fout("atestat10.out");

int k, mat[20][20], n, m;

void citirem(int a[20][20], int &lin, int &col)
{
    fin>>lin>>col;

    for(int i=0; i<lin; i++)
        for(int j=0; j<col; j++)
            fin>>a[i][j];

    fin>>k; /// se citeste nr de valori de 0 cerut la punctul b
}

void sub_a(int a[20][20], int lin, int col)
{
    for(int i=0; i<lin; i++)
    {
        for(int j=0; j<col; j++)
            cout<<a[i][j]<<" ";

        cout<<'\n';
    }
}

void sub_b(int a[20][20], int lin, int col)
{
    int nr0, ok=0;

    for(int i=0; i<lin; i++) /// parcurg liniile
    {
        nr0=0; ///pe linia i n-am gasit nicio valoare nula

        for(int j=0; j<col; j++) /// parcurg coloanele de pe linia i
            if(a[i][j]==0) /// numar valorile de 0 de pe pozitia curenta
                nr0++;

        if(nr0==k) /// daca pe linia i sunt k valori nule
        {
            cout<<i+1<<" "; /// afisez numarul liniei
            ok=1; /// am gasit linie cu k valori nule
        }
    }

    if(!ok)
        cout<<"Nu exista";

    cout<<'\n';
}

void sub_c(int a[20][20], int lin, int col)
{
    int c, ok=0;
    cin>>c;
    c-=1; /// a fost memorata matricea de pe pozitia 0, deci coloana cautata este c-1

    for(int i=0; i<lin; i++) /// se parcurge fiecare linie
        if(a[i][c]%2==1) /// daca elementul curent este impar
        {
            fout<<a[i][c]<<" "; /// se afiseaza elementul curent
            ok=1; /// am gasit un numar impar
        }

    if(!ok) /// daca nu am gasit niciun numar impar
        fout<<"NU";
}

int main()
{
    citirem(mat, n, m);
    sub_a(mat, n, m);
    sub_b(mat, n, m);
    sub_c(mat, n, m);

    return 0;
}
