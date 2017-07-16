/*******************************************
Ronalds Rundans
Dotas divas (zema līmeņa) simbolu virknes  a un b
(sastāv no cipariem un neobligāti mīnusa zīmes), kas
reprezente divus veselus skaitlus. Izveidot funkciju,
kas izveido trešo simbolu virkni c, kas reprezente skaitli
un ir simbolu virkņu a un b reprezentēto skaitļu summa.
Saskaitīšana vai atņemšana jāveic pa vienam ciparam
(kā to dara uz papīra). Funkcijai jāspēj apstrādāt
simbolu virknes līdz garumam 100 ieskaitot.
Programma izveidota: 2015/10/29
*******************************************/
#include <iostream>
#include <cstring>
using namespace std;

void summa(char (*a), char (*b))///ar noradem tiek padoti ievaditie masivi funkcijai
{ int const size=100;
    int i,j,k,m,n,u=1,s=0,v1=0,v2=0,s1=0,s2=0;
    int aInt[size]={0};
    int aFFTL[size]={0};///FFTL=From First To Last(masiva vertibas ar preteju kartiba)
    int bInt[size]={0};
    int bFFTL[size]={0};
    char c[size]={0};
    char cFFTL[size]={0};
    if (a[0]=='-')
        {
            v1++;
        }
        cout<<"Minuss v1="<<v1<<endl;
        if (b[0]=='-')
        {
            v2++;
        }
        cout<<"Minuss v2="<<v2<<endl;
    for(j=0;j<size;j++)/// a-masiva vertibas, izmera a masiva garumu
    {

        if (a[j]=='\0')///ja atrod simbolu virknes beigas, tad partrauc ciklu
        {
            break;
        }
        aInt[j]=a[j]-48;///vertibas no char a parvieto uz int x ciparus, mainot to tipu
    }
    for(k=0;k<size;k++)///b-masiva vertibas, izmera b masiva garumu
    {
        if (b[k]=='\0')///ja atrod simbolu virknes beigas, tad partrauc ciklu
        {
            break;
        }
        bInt[k]=b[k]-48;///vertibas no char b parvieto uz int y ka ciparus, mainot to tipu
    }
    for(m=0;m<j;m++)///preteja kartiba int x vertibam
    {
        //if(aFFTL[()
           {

           }
        aFFTL[(j-m-1)]=aInt[m];///sak nemt no j-1 elementa, jo j-tais ir '\0'
    }


    for(n=0;n<k;n++)///preteja kartiba int y vertibam
    {
        bFFTL[(k-n-1)]=bInt[n];///sak nemt no n-1 elementa, jo n-tais ir '\0'
    }
     if(v1==1)
    {
        aFFTL[j-1]=0;///nodzes '-' simbolu
        j=j-1;
    }
    if(v2==1)
    {
       bFFTL[k-1]=0;///nodzes '-' simbolu
        k=k-1;
    }

    cout<<"j="<<j<<endl;
    cout<<"k="<<k<<endl;
    if(j==k)///ja abi ievaditie masivi ir vienada garuma
    {
        s=j;///mainigais s nosaka izvadama masiva garumu
    }
    else
    {
        if(j>k)///ja pirmais ievaditais masivs ir garaks par otro
        {
            s=j;
        }
        else ///ja otrais ievaditais masivs ir garaks par pirmo
        {
            s=k;
        }
    }
    for(i=s;i>=0;i--)///noskaidro masivu ar lielako skaitlisko vertibu
    {
        if(aFFTL[i]==bFFTL[i])///ja masivu skaitliskas vertibas sakrit
        {
            continue;
        }
         else if(aFFTL[i]>bFFTL[i])///ja pirma masiva skailiska vertiba lielaka
        {
             s1++;
             break;
        }
         else///ja otra masiva skailiska vertiba lielaka
        {
              s2++;
              break;
        }
    }
    cout<<"s1="<<s1<<"s2="<<s2<<endl;///dzest velak
    for(i=0;i<=s;i++)///cFFTL-masivs, izmanto garaka masiva garumu s un satur a un b summu(preteja kartiba)
    {
        if(v1==v2)///ja abiem masiviem sakrita zimes
        {
            cFFTL[i]=cFFTL[i]+(aFFTL[i]+bFFTL[i]); ///saskaita, nemot pa vienam ciparam
            if(cFFTL[i]>=10&&i!=s)///ja skaitlis >=10
            {
                cFFTL[i]=cFFTL[i]-10;///lai butu tikai viens cipars
                cFFTL[i+1]=1;///lai desmitnieks nepazud
            }
        }
        else///ja masiviem ir dazas zimes
        {
            if(s2>s1)///ja otram masivam ir lielaka skaitliska vertiba
            {
                cFFTL[i]=cFFTL[i]+(bFFTL[i]-aFFTL[i]);
                if(cFFTL[i]<0)
                {
                    cFFTL[i]=cFFTL[i]+10;
                    cFFTL[i+1]=cFFTL[i+1]-1;
                }
            }
            else///ja pirmajam masivam ir lielaka vai vienada skaitliska vertiba
            {
                cFFTL[i]=cFFTL[i]+(aFFTL[i]-bFFTL[i]);
            }
                ///no otra masiva atnem pirmo
                if(cFFTL[i]<0)///ja skaitlis <0
                {
                cFFTL[i]=cFFTL[i]+10;///lai butu tikai viens cipars
                cFFTL[i+1]=cFFTL[i+1]-1;;///lai desmitnieks nepazud
                }
        }

    }
    if((int)cFFTL[s]==1)///ja rezultats ir garaks par ievaditajiem skaitliem
    {
        u=0;///lai var izdrukat garaku masivu par ievaditajiem masiviem
    }

    for(i=0;i<=s;i++)///masiva c vertibas klust par ASCII koda simboliem
    {
        cFFTL[i]=cFFTL[i]+48;///nobida vertibas, jo 48 ir "0" simbola ASCII kods
    }
    for(i=0;i<=s;i++)///nonem liekas nulles pirms izdruka rezultatu
    {
            if(cFFTL[s]==48)
            {
                if(s==1)
                {
                    break;
                }
               s--;
            }
    }
    for(i=0;i<=s;i++)///c-masivs
    {

        c[(s-i-u)]=cFFTL[i];///parkato vertibas///!!! vajag "-"zimi izdruka
    }


    if(v1==1 && v2==1)///pieliek "-" zimi ja abi ir negativi skaitli
    {
        for(i=s;i>=0;i--)
        {
            c[i+1]=c[i];
            if(i==0)
            {
                c[0]='-';
            }
        }

    }
    if(v1==1 && s1==1)///pieliek "-" zimi ja pirmais ievaditais ir lielakais skaitlis ir negativs
    {
        for(i=s;i>=0;i--)
        {
            c[i+1]=c[i];
            if(i==0)
            {
                c[0]='-';
            }
        }

    }
     if(v2==1 && s2==1)///pieliek "-" zimi ja pirmais ievaditais ir lielakais skaitlis ir negativs
    {
        for(i=s;i>=0;i--)
        {
            c[i+1]=c[i];
            if(i==0)
            {
                c[0]='-';
            }
        }

    }
    cout << "a+b=c=" <<c<< endl; ///izdruka treso masivu, kas sastav no abu masivu summas
     return;
}
int main()
{
    int ok=1;
    do
    {
        int const size=100;
        char a[size]={0};
        char b[size]={0};
        cout << "Enter char a:" << endl;
        cin.getline(a,size);///pirma masiva vertibas ielasa
        cout << "Enter char b:" << endl;
        cin.getline(b,size);///otra masiva vertibas ielasa
        cout << "Results:" << endl;
        cout << "a=" <<a<< endl;
        cout << "b=" <<b<< endl;
        summa(a,b);///abi masivi tiek padoti funkcijai
        cout <<endl;
        cout << "Enter:1 to repeat, or :0 to exit"<< endl;
        cin>>ok;
        cin.clear();
        cin.ignore (256,'\n');
    }
    while(ok==1);
    return 0;
}


