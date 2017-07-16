#include "kompleksais_skaitlis.h"
#include <iostream>
using namespace std;

kompleksais_skaitlis::kompleksais_skaitlis(double x1,double y1)
///ar parametriem padod sakotnejas vertibas(kompl.sk.#1)
{
    a=x1;///tiek noglabata #1 kompl.sk.reala dala
    b=y1;///tiek noglabata #1 kompl.sk.imaginara dala
}
void kompleksais_skaitlis::pieskaitit(double x2,double y2)
///ar parametriem padod #2 kompl.sk.vertibas
{
    double a1,b1;
    a1=a+x2;
    b1=b+y2;
    a=a1;
    b=b1;
};
void kompleksais_skaitlis::dalit(double x2,double y2)
///ar parametriem padod #2 kompl.sk.vertibas
{
    double a3,b3;
    if(x2!=0 or y2!=0)///ja #2 skaitlis nav 0+0i
    {
       a3=(((a*x2)+(b*y2))/((x2*x2)+(y2*y2)));
        b3=(((x2*b)-(a*y2))/((x2*x2)+(y2*y2)));
        a=a3;
        b=b3;
    }
    else///ja megina dalit ar 0+0i
    {
        cout<<"Dalisana nav defineta, ja dala ar 0+0i"<<endl;
    }
};
void kompleksais_skaitlis::reizinat(double x2,double y2)
///ar parametriem padod #2 kompl.sk.vertibas
{
    double a2,b2;
    a2=((a*x2)-(b*y2));
    b2=((y2*a)+(b*x2));
    a=a2;
    b=b2;
};
void kompleksais_skaitlis::drukat()
///kompl.sk.izdrukasana
{
    cout<<"Komplekss skaitlis= ";
    if(b>0)///ja imag.dala ir pozitiva
    {
        cout<<a<<"+"<<b<<"i"<<endl;
    }
    else if(b<0)
    {///ja imag.dala ir negativa
        cout<<a<<"-"<<-b<<"i"<<endl;
    }
    else if(b==0)
    {///ja imag.dala ir 0
        cout<<a<<endl;
    }
};
kompleksais_skaitlis::~kompleksais_skaitlis()///destruktors ar pazinojumu
{
    cout<<"Pazinojums:Objekts tika likvidets!"<<endl;
}
