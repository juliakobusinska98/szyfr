//POP 2016-12-05 projekt 2 Kobusinska Julia EIT 5 165159 CodeBlocks 16.01 GNU GCC Compiler 4.9
#include <iostream>
#include<string>
#include<algorithm>


using namespace std;
const int n=26;

/***********************************************************FUNKCJA TWORZACA TABLICE*****************************************************/
void Tablica(char tab[n][n])
{
    int k;
    k=65;
    int a;//zmienna odpowiadajaca za wiersz
    int b;//zmienna dpowiadajaca za kolumne
    for(b=0; b<26; b++)
    {
        for (int i = k,a = 0; i < 91,a<26; i++,a++)
        {
            tab[a][b]=static_cast<char>(i);
            if(i>90)
            {
                if(b>0)
                {
                    for(int i=k,c=0, d=0; i<91,a<26; i++,a++,c++)
                    {
                        tab[a][b]=tab[c][d];
                    }
                }

            }
        }
        k++;
    }
    for(int b=0;b<26;b++)
    {
        for(int a=0; a<26;a++)
        {
            cout<<tab[a][b]<<" ";
        }cout<<endl;
    }
}
/*********************************************************STRUKTURA DO DE/SZYFROWANIA****************************************************/
struct bufory
{
    int bufor_wiersza;
    int bufor_kolumny;
};

/**********************************************************FUNKCJA GLOWNA****************************************************************/
int main()
{

    char tab[n][n];
    Tablica(tab);
    cout<<"Podaj klucz, ktorym chcesz szyfrowac tekst ( bez spacji, jedynie litery alfabetu lacinskiego ):"<<endl;
    string klucz;
    getline(cin,klucz);
    cout<<endl;
    transform(klucz.begin(),klucz.end(),klucz.begin(),::toupper);
    int dlugosc_klucza=klucz.length();

    bool spacja=0;
    for(int i=0; i<dlugosc_klucza; i++)
    {
        if(isspace(klucz[i]))
        {
            spacja=1;
            klucz.erase(i,1);
        }

    }

    cout<<"Podaj tekst,ktory chcesz zaszyfrowac ( zawieraj¹cy jedynie litery alfabetu lacinskiego):"<<endl;
    string tekst;
    getline(cin,tekst);
    cout<<endl;
    transform(tekst.begin(),tekst.end(),tekst.begin(),::toupper);
    int dlugosc_tekstu=tekst.length();

    /*************************************************POWIELANIE HASLA******************************************************************/
    string klucz_powielony;


    for(int i=0,j=0; i<(dlugosc_klucza),j<dlugosc_tekstu; i++,j++)

    {
        if(spacja)
        {
            if (i<dlugosc_klucza-1)
            {
                klucz_powielony+=klucz[i];
            }
            else

            {
                i=0;

                klucz_powielony+=klucz[i];

            }
        }
        if(!spacja)
        {
            if (i<dlugosc_klucza)
            {
                klucz_powielony+=klucz[i];
            }
            else

            {
                i=0;

                klucz_powielony+=klucz[i];

            }
        }
    }


    int licznik=0;
    for(int i=0; i<dlugosc_tekstu; i++)
    {
        if(isspace(tekst[i]))
        {
            licznik++;
            klucz_powielony.insert(i," ");
        }
    }

    klucz_powielony.erase(dlugosc_tekstu,licznik);

    dlugosc_tekstu=tekst.length();
    dlugosc_klucza=klucz_powielony.length();

    /****************************************************************SZYFROWANIE***************************************************************/
    bufory szyfrowanie[dlugosc_tekstu];
    for(int x=0; x<dlugosc_tekstu; x++)
    {

        for(int j=0; j<=26; j++)

        {
            if (tekst[x]==tab[0][j]||isspace(tekst[x]))
            {
                szyfrowanie[x].bufor_kolumny=j;

            }
        }
        for(int i=0; i<=26; i++)
        {
            if (klucz_powielony[x]==tab[i][0]||isspace(klucz_powielony[x]))
            {
                szyfrowanie[x].bufor_wiersza=i;

            }
        }
    }

    cout<<"ZASZYFROWANY TEKST:  ";
    for(int x=0,z=0,v=0; x<dlugosc_tekstu; x++)
    {
        if(szyfrowanie[x].bufor_wiersza<26)
        {
            v=szyfrowanie[x].bufor_kolumny;
            z=szyfrowanie[x].bufor_wiersza;
            cout<<tab[z][v];
        }
        else cout<<" ";
    }
    cout<<endl<<endl<<endl;
    /************************************************DESZYFROWANIE***********************************************************************/
    bufory deszyfrowanie[dlugosc_tekstu];
    string szyfr;
    cout<<"Podaj zaszyfrowana wiadomosc:"<<endl;
    getline(cin,szyfr);
    cout<<endl;
    transform(szyfr.begin(),szyfr.end(),szyfr.begin(),::toupper);
    int dlugosc_szyfru=szyfr.length();
    cout<<"Podaj klucz, ktorym chcesz odszyfrowac tekst:"<<endl;
    string klucz2;
    getline(cin,klucz2);
    cout<<endl;
    transform(klucz2.begin(),klucz2.end(),klucz2.begin(),::toupper);
    int dlugosc_klucza2=klucz2.length();
    bool spacja1=0;
    for(int i=0; i<dlugosc_klucza2; i++)
    {
        if(isspace(klucz2[i]))
        {
            spacja1=1;
            klucz2.erase(i,1);
        }

    }
    string klucz2_powielony;


    for(int i=0,j=0; i<(dlugosc_klucza2),j<dlugosc_szyfru; i++,j++)

    {

        if(spacja1)
        {


            if (i<dlugosc_klucza2-1)//ostatnie miejsce to /NULL
            {
                klucz2_powielony+=klucz2[i];
            }
            else

            {
                i=0;

                klucz2_powielony+=klucz2[i];

            }
        }
        if(!spacja1)
        {


            if (i<dlugosc_klucza2)
            {
                klucz2_powielony+=klucz2[i];
            }
            else

            {
                i=0;

                klucz2_powielony+=klucz2[i];

            }
        }

    }


    int licznik2=0;
    for(int i=0; i<dlugosc_szyfru; i++)
    {
        if(isspace(szyfr[i]))
        {
            licznik2++;
            klucz2_powielony.insert(i," ");
        }
    }

    klucz2_powielony.erase(dlugosc_szyfru,licznik2);


    dlugosc_szyfru=szyfr.length();
    dlugosc_klucza2=klucz2_powielony.length();

    for(int x=0; x<dlugosc_szyfru; x++)
    {

        for(int j=0; j<=26; j++)

        {
            if (klucz2_powielony[x]==tab[0][j]||isspace(klucz2_powielony[x]))
            {

                deszyfrowanie[x].bufor_kolumny=j;


            }

        }
    }
    for(int x=0; x<dlugosc_szyfru; x++)
    {
        for(int i=0,v=0; i<=26; i++)
        {
            v=deszyfrowanie[x].bufor_kolumny;
            if (szyfr[x]==tab[i][v]||isspace(szyfr[x]))
            {

                deszyfrowanie[x].bufor_wiersza=i;

            }
        }
    }
    cout<<"WYNIK DESZYFROWANIA:  ";
    for(int x=0,z=0; x<dlugosc_szyfru; x++)
    {
        if(deszyfrowanie[x].bufor_wiersza<26)
        {
            z=deszyfrowanie[x].bufor_wiersza;
            cout<<tab[z][0];
        }
        else cout<<" ";
    }
    return 0;
}
