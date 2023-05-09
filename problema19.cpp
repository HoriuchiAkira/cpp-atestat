/**
FISIERUL ATESTAT.IN CONTINE O SINGURA LINIE
PE CARE SE AFLA SCRIS UN TEXT FORMAT DIN CEL MULT 50 DE CARACTERE,
PRIMUL CARACTER FIIND LITERA, IAR CUVINTELE DIN TEXT
SUNT SEPARATE PRIN CATE UN SPATIU.
FIECARE CUVANT ESTE FORMAT DOAR DIN LITERE MARI
SAU MICI ALE ALFABETULUI LIMBII ENGLEZE.
SA SE SCRIE UN PROGRAM IN LIMBAJUL C++, CARE:
A)	SA AFISEZE  TEXTUL PE O SINGURA LINIE A ECRANULUI,
NUMAI CU LITERE MARI;
B)	SA AFISEZE PE URMATOAREA LINIE A ECRANULUI
TEXTUL FARA SPATII
C) SA SCRIE IN FISIERULUI ATESTAT.OUT,
SUB FORMA DE TRIUNGHI TOATE SECVENTELE MEDIANE
ALE PRIMULUI CUVANT DIN TEXTUL CITIT,
PORNIND DE LA INTREGUL CUVANT,
PANA LA SECVENTA ALCATUITA DIN CARACTERUL
(SAU CELE 2 CARACTERE) DIN MIJLOC.

*/
#include <bits/stdc++.h>

using namespace std;
ifstream fin("atestat19.in");
ofstream fout("atestat19.out");
char sir[101];
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
    for(int i=0; i<l; ++i)
        if(s[i]>='a' && s[i]<='z')
            cout<<(char)(s[i]-32);
        else
            cout<<s[i];
    cout<<'\n';
}
void subiectB(char s[], int l)
{
    char *p, aux[51];
    strcpy(aux,s);
    p=strtok(aux," ");
    while(p)
    {
        cout<<p;
        p=strtok(NULL, " ");
    }
    cout<<'\n';
}
void subiectC(char s[], int l)
{
    char *p, aux[51];
    p=strtok(s," ");  /// aici am primul cuvant in p
    strcpy(aux,p);
    cout<<aux<<'\n';
    for(int i=1;i<=numar_caractere(aux)/2;i++)
    {
        for(int k=1;k<=i;k++)
            cout<<' ';
        for(int j=i;j<strlen(aux)-i;j++)
            cout<<aux[j];
        cout<<'\n';
    }
}

int main()
{
    fin.getline(sir,101);
    ls=numar_caractere(sir);
    subiectA(sir,ls);
    subiectB(sir,ls);
    subiectC(sir,ls);
    return 0;
}
