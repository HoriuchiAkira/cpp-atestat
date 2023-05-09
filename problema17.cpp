/**
FISIERUL ATESTAT.IN CONTINE O SINGURA LINIE
PE CARE SE AFLA SCRIS UN TEXT FORMAT DIN CEL MULT 70 DE CARACTERE,
PRIMUL CARACTER FIIND LITERA, IAR CUVINTELE DIN TEXT
SUNT SEPARATE PRIN CATE UN SPATIU.
FIECARE CUVANT ESTE FORMAT DOAR DIN LITERE MARI
SAU MICI ALE ALFABETULUI LIMBII ENGLEZE.
SA SE SCRIE UN PROGRAM IN LIMBAJUL C++, CARE:
A)	SA AFISEZE  TEXTUL PE O SINGURA LINIE A ECRANULUI,
NUMAI CU LITERE MICI;
b)	SA AFISEZE PE URMATOAREA LINIE A ECRANULUI,
NUMARUL DE CUVINTE DIN CARE ESTE FORMAT TEXTUL;
C)	SA CITEASCA DE LA TASTATURA O LITERA,
SA MODIFICE FIECARE CUVANT CARE INCEPE CU LITERA 'M'
PRIN INLOCUIREA ACESTEIA CU LITERA
CITITA DE LA TASTATURA SI SA SCRIE IN FISIERUL ATESTAT.OUT,
PE PRIMA LINIE,  TEXTUL MODIFICAT.

*/
#include <bits/stdc++.h>

using namespace std;
ifstream fin("atestat17.in");
ofstream fout("atestat17.out");
char sir[71];
int ls;
int numar_caractere(char s[])
{
    int nrc=0;
    for(int i=0; s[i]; ++i)
        ++nrc;
    return nrc;
}
void subiectA(char s[], int l)
{
    for(int i=0; s[i]; ++i)
        if(s[i]>='A' && s[i]<='Z')
            cout<<(char)(s[i]+32);
        else
            cout<<s[i];
    cout<<'\n';
}

void subiectB(char s[], int l)
{
    char *p, aux[71];
    strcpy(aux,s);
    int nrc=0;
    p=strtok(aux," ");
    while(p)
    {
        nrc++;
        p=strtok(NULL, " ");
    }
    cout<<nrc<<'\n';
}
void subiectC(char s[], int l)
{
    char *p, aux[71], ch;
    cin>>ch;
    strcpy(aux,s);
    p=strtok(aux," ");
    while(p)
    {
        if(p[0]=='M')
            p[0]=ch;
        fout<<p<<" ";
        p=strtok(NULL, " ");
    }
}
int main()
{
    fin.getline(sir,71);
    ls=numar_caractere(sir);
    subiectA(sir,ls);
    subiectB(sir,ls);
    subiectC(sir,ls);
    return 0;
}
