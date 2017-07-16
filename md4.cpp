/*******************************************
Izveidot klasi "Komplekss skaitlis",
kura tiek glabati divi skaitli, kas nosaka kompleksu skaitli.
Klasei izveidot šadas metodes:
(1) konstruktors, ar kuru tiek padotas sakotnejas vertibas,
(2) destruktors, kurš pazino par objekta likvidešanu,
(3) metode "Pieskaitit" ar diviem parametriem,
kas (savam) kompleksajam skaitlim pieskaita otru (kas padots
ar parametriem) kompleksu skaitli un rezultatu noglaba pie sevis,
(4) metode "Reizinat"– ar diviem parametriem, kas sareizina
kompleksus skaitlus,
(5) metode "Drukat", kas izdruka komplekso skaitli.
Programma izveidota: 2015/12/03
*******************************************/

#include <iostream>
#include "kompleksais_skaitlis.h"
using namespace std;

int main()
{
    bool ok=1,metodes=1;
    do
    {
        double x1,x2,y1,y2;
        int izv;
        cout<<"Ievadiet #1 kompleksa skaitla realo dalu x1="<<endl;
        cin>>x1;
        while(!cin.good())
        {
            cin.clear();
            cin.ignore (256,'\n');
            cout<<"Megini velreiz!"<<endl;
            cin>>x1;
        };
        cout<<"Ievadiet #1 kompleksa skaitla imaginaro dalu y1="<<endl;
        cin>>y1;
        while(!cin.good())
        {
            cin.clear();
            cin.ignore (256,'\n');
            cout<<"Megini velreiz!"<<endl;
            cin>>y1;
        };
        kompleksais_skaitlis z(x1,y1);
        z.drukat();
        cout<<endl;
        do
        {
            cout<<"Izvelaties metodi un ievadiet skaitli:"<<endl;
            cout<<" 1 =pieskaitit"<<endl;
            cout<<" 2 =reizinat"<<endl;
            cout<<" 3 =dalit"<<endl;
            cout<<" 4 =drukat"<<endl;
            cin>>izv;///izvelas metodi
            while(!cin.good())
            {
                cin.clear();
                cin.ignore (256,'\n');
                cout<<"Megini velreiz!"<<endl;
                cin>>izv;
            };
            if(izv==1)
            {
                cout<<"Izvelejaties metodi : pieskaitit"<<endl;
            }
            else if(izv==2)
            {
                cout<<"Izvelejaties metodi : reizinat"<<endl;
            }
            else if(izv==3)
            {
                cout<<"Izvelejaties metodi : dalit"<<endl;
            }
            if(izv==1 or izv==2 or izv==3)
            {
                cout<<"Ievadi #2 kompleksa skaitla realo dalu x2="<<endl;///2#
                cin>>x2;
                cout<<"Ievadi #2 kompleksa skaitla imaginaro dalu y2="<<endl;
                cin>>y2;
                if(izv==1)
                {
                    z.pieskaitit(x2,y2);
                    z.drukat();
                }
                else if(izv==2)
                {
                    z.reizinat(x2,y2);
                    z.drukat();
                }
                else if(izv==3)
                {
                    z.dalit(x2,y2);
                    z.drukat();
                }
            }
            else if(izv==4)
            {
                cout<<"Izvelejaties metodi : drukat"<<endl;
                z.drukat();
            }
            cout<<"Vai izmantosiet citu metodi? Ievadiet 1=ja vai 0=ne."<<endl;
            cin>>metodes;
            while(!cin.good())
            {
               cin.clear();
               cin.ignore (256,'\n');
               cout<<"Megini velreiz!"<<endl;
               cin>>metodes;
            };
        }
        while(metodes==1);
        cout<<"Vai atkartot ar citiem skaitliem (tiks likvidets objekts)?"<<endl;
        cin>>ok;
        while(!cin.good())
        {
            cin.clear();
            cin.ignore (256,'\n');
            cout<<"Megini velreiz!"<<endl;
            cin>>ok;
        };///objekts tiek izlikvidets seit!
    }
    while(ok==1);
    return 0;

}
