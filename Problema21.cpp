/**
FISIERUL ATESTAT.IN CONTINE O SINGURA LINIE PE CARE SE AFLA
SCRIS UN TEXT FORMAT DIN CEL MULT 100 DE CARACTERE, PRIMUL
SI ULTIMUL CARACTER SUNT LITERE, IAR CUVINTELE DIN TEXT
SUNT SEPARATE PRIN C‚TE UN SPATIU.
FIECARE CUV‚NT ESTE FORMAT DOAR DIN LITERE MARI SAU MICI
ALE ALFABETULUI LIMBII ENGLEZE.
SA SE SCRIE UN PROGRAM, IN LIMBAJUL PASCAL/C/C++, CARE:
A)SA AFISEZE TEXTUL PE ECRAN, PE O SINGURA LINIE, NUMAI CU LITERE MICI;
B)SA AFISEZE PE URMATOAREA LINIE A ECRANULUI  TEXTUL INITIAL,
FARA SPATII INTRE CUVINTE;
C)SA SCRIE IN FISIERULUI ATESTAT.OUT,
CUVINTELE CARE AU PROPRIETATEA DE PALINDROM
*/
#include <bits/stdc++.h>

using namespace std;
ifstream fin("atestat21.in");
ofstream fout("atestat21.out");
char s[101];
int n;
void subiectA(char v[])
{
    for(int i=0; v[i]; ++i)
        if(v[i]>='A' && v[i]<='Z')///caracter mare
            cout<<(char)(tolower(v[i]));
        else
            cout<<(char)v[i];
    cout<<'\n';
}
void subiectB(char v[])
{
    for(int i=0; v[i]; ++i)
        if(v[i]!=' ')/// orice carater diferit de spatiu
            cout<<(char)v[i];
    cout<<'\n';
    /** SAU
    char *p;
    p=strtok(v," ")
    while(p)
    {
        cout<<p;
        p=strtok(NULL," ");
    }
    */
}
int palindrom(char v[])
{   int lv=0;
    lv=strlen(v);
    for(int i=0; i<lv/2; ++i)
        if(tolower(v[i])!=tolower(v[lv-i-1]))
            return 0;
    return 1;
}
void subiectC(char s[])
{   char *p;
    p=strtok(s," ");
    while(p)
    {
        if(palindrom(p))
            cout<<p<<'\n';
        p=strtok(NULL," ");
    }
}
int main()
{
    fin.getline(s,101);
    n=strlen(s);
    subiectA(s);
    subiectB(s);
    subiectC(s);
    return 0;
}
