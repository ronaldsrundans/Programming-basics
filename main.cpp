/*******************************************
Ronalds Rundans, rr11043
A20. Izdrukat aritmetiskas progresijas pirmos n loceklus, ja dots a(1) (pirmais loceklis) un d (diference).
Programma izveidota: 2015/09/24
*******************************************/
#include <iostream>
using namespace std;

int main()
{
    int ok;
    do
    {
        float x,a,d;
        int n,b;
        cout<<"Please input first number:"<<endl;
        cin>>a; ///aritmetiskas progresijas pirmais loceklis
        while(!cin.good())
            {
                cin.clear();
                cin.ignore (256,'\n');
                cout<<"ERROR! Try again:  "<<endl;
                cin>>a;
            };
        cout<<"Success:   "<<a<<endl;
        cout<<"Please input the difference:"<<endl;
        cin>>d;///aritmetiskas progresijas diferences vertiba
        while(!cin.good())
            {
                cin.clear();
                cin.ignore (256,'\n');
                cout<<"ERROR! Try again:  "<<endl;
                cin>>d;
            };
        cout<<"Success:   "<<d<<endl;
        cout<<"How many numbers to output. Please input n value:"<<endl;
        cin>>n;///aritmetiskas progresijas loceklu skaits
        while(n<=0)
            {
                cin.clear();
                cin.ignore (256,'\n');
                cout<<"ERROR! Try again:  "<<endl;
                cin>>n;
            };
        cout<<"Aritmetic progression with n="<<n<<" numbers are the following:"<<endl;
        for(b=1;b<=n;b+=1)///skaitla kartas numurs
            {
                x=a+((b-1)*d);///aritmetiskas progresijas formula
                cout<<x<<endl;///katra aritmestiskas progresijas locekla vertiba
            };
        cout<<"If you want to repeat, please input (1), or input (0) to end the programm:"<<endl;
        cin>>ok;///programmas atkartosana
    }
    while(ok==1);
   return 0;
}




