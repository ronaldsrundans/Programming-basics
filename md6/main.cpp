/**/
/*******************************************
Ronalds Rundans
Izveidot programmu valoda C++, kas apstrada teksta
failu seciga rezima. Dati no faila janolasa pa vienam
simbolam (nedrikst nolasit uzreiz visu failu vai veselu
rindinu). Nedrikst dublet visa faila saturu operativaja
atmina.
F8. Doti divi faili f1 un f2. Faila f1 ir patvaligs teksts,
faila f2 ir ne vairak ka 40 vardu parisu, kas atdaliti ar komatiem.
Izdrukat faila tekstu no ieejas faila f1, kura visi vardi,
kas ir sastopami faila f2 ka pirma komponente no parisa, tiek
aizstati ar tam atbilstoso faila f2 noradito vardu. Drikst
uzskatit, ka varda garums faila neparsniedz 40 simbolus.
Par vardu uzskatit patvaligu simbolu virkni, kas atdalita
ar tuksumiem vai pieturas zimem (punkts, komats, apalas iekavas,
izsaukuma zime, jautajuma zime).
Programma izveidota: 2016/02/27
*******************************************/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool letter(char);
void store_lenght(int ,int,int []);
void store(char *, int,int, char [][40]);
void check(char *,int[],char [][40], int, bool&,int&);

int main()
{
    bool atk=1;
    do
    {
    fstream f1("f1.txt", ios::in);
    fstream f2("f2.txt", ios::in);
    char c1;
    char c2;
    char  c1tmp_arr[40];
    char  c2tmp_arr[40];///pagaidu masivs,kura ieraksta pa vienam simbolam no katra faila
     char c10arr[40][40];///masivs pirmas komponentes no parisa
     char c01arr[40][40];///masivs otras komponentes no parisa
    int arr1[40];///no parisa pirmas komponentes varda garums
     int arr2[40];///no parisa otras komponentes varda garums
///vispirms sak parbaudit f2 saturu
    int word_num=0; ///mainigais skaitlis cik vardi kopa ir faila f2
    f2.get(c2);///pagaidu mainigais, kura ieraksta katru vardu bez pieturzimem
    while(!f2.eof())
    {
        int num=0;
        while(letter(c2)==1)///pagaidu mainigo ieraksta masiva lidz paradas pieturzime vai atstarpe
        {
            c2tmp_arr[num]=c2;///cikls turpinas lidz ierakta visu vardu pagaidu masiva
            num++;
            f2.get(c2);
        }
        c2tmp_arr[num]=0;
        if(word_num%2==0)///ja tas ir pirmas komponentes vards
        {
            store_lenght(word_num/2,num,arr1);///padod vertibas funkcijai, kas masivos ierakstis vardu garumus
            store(c2tmp_arr,num,word_num/2,c10arr);///padod vertibas funkcijai, kas pirmo komponenti noglaba masivos
        }
         else if(word_num%2==1)///ja tas ir otras komponentes vards
        {
            store_lenght(word_num/2,num,arr2);///padod vertibas funkcijai, kas masivos ierakstis vardu garumus
            store(c2tmp_arr,num,word_num/2,c01arr);///padod vertibas funkcijai, kas otro komponenti noglaba masivos
        }
             word_num++;///skaita kopeju vardu skaitu faila f2
        f2.get(c2);
    }
    ///seit sak f1 saturu parbaudit
    f1.get(c1);///mainigais c1 glabas katru f1 simbolu pec kartas
    while(!f1.eof())
    {
        int num=0;
        while(letter(c1)==1)
        {
            c1tmp_arr[num]=c1;
            num++;
            f1.get(c1);
        }
        c1tmp_arr[num]=0;
        bool match=0;
        int row=0;///mainigais glabas rindas numuru, kura glabajas otra komponente
        check(c1tmp_arr,arr1,c10arr, num, match,row);
        if(match==1)///ja sakrit pirma komponente no parisa, tad izdruka otro komponenti
        {
            for(int i=0;i<=arr2[row];i++)
            {
                cout<<c01arr[row][i]<<endl;
            }
        }
        else///ja nesakrit pirma komponente no parisa, tad izdruka pagaidu masiva saturu
        {
            for(int i=0;i<num;i++)
            {
                cout<<c1tmp_arr[i]<<endl;
            }
        }
        cout<<c1<<endl;///ja nav vards tad uzreiz izdruka simbolu
        f1.get(c1);
    }
    f1.close();
    f2.close();
     cout<<"Repeat=1 Stop=0"<<endl;
     cin>>atk;
    }
    while(atk==1);
    return 0;
}
bool letter(char c)///funkcija, kas parbauda vai simbols ir no kada varda
{
    if((((int)c>='0')&&(((int)c)<='9'))||(((int)c>='A')&&((int)c<='Z'))||(((int)c>='a')&&(((int)c)<='z')))
           {
               return true;
           }
     else return false;
}
void store(char *c2_tmp,int n,int word_num ,char c00[][40])///funkcija, kas noglaba komponentes vardu
{
        for(int j=0;j<=n;j++)///divu dimensiju masiva aizpildisana, kura katra rinda ieraksta vardu
        {
            c00[word_num][j]=c2_tmp[j];///n-rindas numurs un j ir varda garums
        }
}
void store_lenght(int word_num,int num,int arr[])///funkcija, kas noglaba komponentes vardu garumus
{
    arr[word_num]=num;

}
void check(char *c1,int arr1[], char (*c10)[40], int n, bool& match, int& row)
{
    for(int i=0;i<=20;i++)
    {
        int letters=0;
        if(c1[0]==c10[i][0])///ja sakrit vardu pirmie burti, tad salidzina abus vardus
        {
            for(int j=0;c10[i][j]!=0; j++)
            {
                if(c1[j]==c10[i][j])
                {
                    letters++;///mainigais skaita cik burti sakrit abos vardos
                    if(n==(arr1[i])&&(letters==n))///ja visi burti sakrit
                     {
                        match=true;///vards sakrit ar pirmo komponenti no parisa
                        row=i;///tiek padots rindas numurs ar jauno vardu
                       /// cout<<"cikla row"<<endl;
                     }
                }

            }
        }

    }


}


