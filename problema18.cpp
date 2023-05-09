/**
FISIERUL ATESTAT.IN CONTINE O SINGURA LINIE
PE CARE SE AFLA SCRIS UN TEXT FORMAT DIN CEL MULT
100 DE CARACTERE,
PRIMUL CARACTER FIIND LITERA, IAR CUVINTELE DIN TEXT
SUNT SEPARATE PRIN CATE UN SPATIU.
FIECARE CUVANT ESTE FORMAT DOAR DIN LITERE MARI
SAU MICI ALE ALFABETULUI LIMBII ENGLEZE.
SA SE SCRIE UN PROGRAM IN LIMBAJUL C++, CARE:
A)	SA AFISEZE  TEXTUL PE O SINGURA LINIE A ECRANULUI,
NUMAI CU LITERE MICI;
b)	SA AFISEZE PE URMATOARELE LINII A ECRANULUI,
CUVINTELE DIN CARE ESTE FORMAT TEXTUL;
C) SA SCRIE PE PRIMA LINIE A FISIERULUI ATESTAT.OUT
NUMARUL CIFRELOR INTALNITE IN TEXT

*/
#include <bits/stdc++.h>

using namespace std;
ifstream fin("atestat18.in");
ofstream fout("atestat18.out");
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
    for(int i=0; s[i]; ++i)
        if(s[i]>='A' && s[i]<='Z')
            cout<<(char)(s[i]+32);
        else
            cout<<s[i];
    cout<<'\n';
}

void subiectB(char s[], int l)
{
    char *p, aux[101];
    strcpy(aux,s);
    p=strtok(aux," ");
    while(p)
    {
        cout<<p<<'\n';
        p=strtok(NULL, " ");
    }
}
void subiectC(char s[], int l)
{
    int nrc=0;
    for(int i=0; s[i]; ++i)
        if(s[i]>='0' && s[i]<='9') /// cifra
            nrc++;
    cout<<nrc;
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
