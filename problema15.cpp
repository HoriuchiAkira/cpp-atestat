/**
FISIERUL ATESTAT.IN CONTINE O SINGURA LINIE
PE CARE SE AFLA SCRIS UN TEXT FORMAT DIN CEL MULT 250 DE CARACTERE,
PRIMUL CARACTER FIIND LITERA, IAR CUVINTELE DIN TEXT
SUNT SEPARATE PRIN CATE UN SPATIU.
FIECARE CUVANT ESTE FORMAT DOAR DIN LITERE MARI
SAU MICI ALE ALFABETULUI LIMBII ENGLEZE.
SA SE SCRIE UN PROGRAM IN LIMBAJUL C++, CARE:
A)	SA AFISEZE  TEXTUL PE O SINGURA LINIE A ECRANULUI,
NUMAI CU LITERE MARI;
B)	SA AFISEZE PE URMATOAREA LINIE A ECRANULUI
NUMARUL DE CONSOANE DIN TEXT;
C)	SA SCRIE IN FISIERUL ATESTAT.OUT, PE PRIMA LINIE,
NUMARUL CUVINTELOR DIN TEXT

*/
#include <bits/stdc++.h>

using namespace std;
ifstream fin("atestat15.in");
ofstream fout("atestat15.out");
char sir[251];
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
    char voc[]="aeiuoAEIOU";
    int nrvoc=0, nrsp=0;
    for(int i=0; i<l; ++i)
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) /// numar vocale
        {
                if(strchr(voc, s[i]))
                    nrvoc++;
        }
        else if(s[i]==' ') /// numar spatii
            nrsp++;
    cout<<(l-nrvoc-nrsp)<<'\n';
}
void subiectC_strtok(char s[], int l)
{
    char *p;
    int nrc=0;
    p=strtok(s," ");
    while(p)
    {
        nrc++;
        p=strtok(NULL, " ");
    }
    fout<<nrc;
}
void subiectC_spatii(char s[], int l)
{
    int nrc=0;
    for(int i=0; s[i]; ++i)
        if(s[i]==' ')
            nrc++;
    fout<<nrc+1;
}
int main()
{
    fin.getline(sir,251);
    ls=numar_caractere(sir);
    subiectA(sir,ls);
    subiectB(sir,ls);
    subiectC_spatii(sir,ls);
    return 0;
}
