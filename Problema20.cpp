/**
FISIERUL ATESTAT.IN CONTINE O SINGURA LINIE PE CARE SE AFLA
SCRIS UN TEXT FORMAT DIN CEL MULT 100 DE CARACTERE, PRIMUL
SI ULTIMUL CARACTER SUNT LITERE, IAR CUVINTELE DIN TEXT
SUNT SEPARATE PRIN C‚TE UN SPATIU.
FIECARE CUV‚NT ESTE FORMAT DOAR DIN LITERE MARI SAU MICI
ALE ALFABETULUI LIMBII ENGLEZE.
SA SE SCRIE UN PROGRAM, IN LIMBAJUL PASCAL/C/C++, CARE:
A)SA AFISEZE TEXTUL PE ECRAN, PE O SINGURA LINIE, NUMAI CU LITERE MARI;
B)SA AFISEZE PE URMATOAREA LINIE A ECRANULUI  TEXTUL INITIAL,
FARA SPATII INTRE CUVINTE;
C)SA SCRIE IN FISIERULUI ATESTAT.OUT,
PERECHILE DE CUVINTE CARE SUNT ANAGRAME.
DOUA CUVINTE SUNT ANAGRAME DACA
AU LUNGIME EGALA SI SUNT FORMATE
DIN ACELEASI LITERE EVENTUAL IN ALTA ORDINE.
COMPARATIA CELOR DOUA CUVINTE SE REALIZEAZA
FARA A TINE CONT DE LITERE MARI SAU
MICI ALE ALFABETULUI.
*/
#include <bits/stdc++.h>

using namespace std;
ifstream fin("atestat20.in");
ofstream fout("atestat20.out");
char s[101];
int n;
void subiectA(char v[])
{
    for(int i=0; v[i]; ++i)
        if(v[i]>='a' && v[i]<='z')///caracter mic
            cout<<(char)(toupper(v[i]));
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
}
int anagrame(char s1[], char s2[])
{
    if(strlen(s1)!=strlen(s2))
        return 0;
    int fr1[27], fr2[27];
    for(int i=0; i<27; ++i)
        fr1[i]=fr2[i]=0;
    for(int i=0; s1[i]; ++i)
        fr1[tolower(s1[i])-'a']++;
    for(int i=0; s2[i]; ++i)
        if(fr1[tolower(s2[i])-'a']==0) ///DACA CARACTERUL DIN S2 NU A FOST GASIT IN S1
            return 0;
        else
            fr2[tolower(s2[i])-'a']++;
    for(int i=0; i<27; ++i)
        if(fr1[i]!=fr2[i]) /// DACA AM FRECVENTE DIFERITE
            return 0;
    return 1;
}
void subiectC(char s[])
{
    char *p, v[101][101];
    int lv=0;
    p=strtok(s," ");
    while(p)
    {
       strcpy(v[lv], p);
       lv++;
       p=strtok(NULL," ");
    }
    for(int i=0; i<lv-1; ++i)
        for(int j=i+1; j<lv; ++j)
            if(anagrame(v[i],v[j]))
                fout<<v[i]<<" "<<v[j]<<'\n';
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
