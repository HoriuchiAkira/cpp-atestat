#include<bits/stdc++.h>
using namespace std;

ifstream fin("atestat6.in");
ofstream fout("atestat6.out");

void citirev(double a[], int &la)
{
    fin>>la;
    for(int i=1; i<=la; i++)
        fin>>a[i];
}

void sub_a(double a[31], int la)
{
    int i;
    for(i=1; i<=la ; i++)
        cout<<a[i]<<" ";

    cout<<'\n';
}

void sub_b(double a[31], int la) /// ma pt. real <0
{
    int i, nrnumere=0;
    double S=0, ma;

    for(i=1; i<=la; i++)
    {
        if(a[i]<0)
        {
            nrnumere++; /// se numara numerele reale <0
            S+=a[i];   /// se aduna la suma
        }
    }
    if(nrnumere)  /// se afiseaza media aritmetica
    {
        ma=S/nrnumere;
        cout<<fixed<<setprecision(2)<<ma<<'\n';
    }
    else cout<<0;
}
void sortam(double a[], int poz1, int poz2)
{
    for(int i=poz1; i<poz2; i++) /// se parcurg indicii de la poz1 la penultimul element fata de poz2
        for(int j=i+1; j<=poz2; j++) ///se parcurg indici de la pozitia curenta +1 la poz2
            if(a[i]>a[j]) /// daca ordinea nu este cea ceruta ( crescatoare)
                swap(a[i], a[j]);/// se interschimba val

}
void sub_c(double a[], int la)
{
    int i, j, p1, p2;
    cin>>p1>>p2;
    sortam(a,p1,p2);
    for(i=1; i<la; i++)
        fout<<a[i]<<" ";
}

int main()
{

    int n;
    double v[31];
    citirev(v, n);
    sub_a(v, n);
    sub_b(v, n);
    sub_c(v, n);

    return 0;
}
