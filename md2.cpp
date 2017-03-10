/*******************************************
Ronalds Rundans, rr11043
B15. Doti naturali skaili n un a(1),a(2),a(3),...,a(n). Atrast minimalo no dotajiem skaitliem(t.i.,tadiem, kas nav pirmskaitli).
Programma izveidota: 2015/09/30
*******************************************/
#include <iostream>
using namespace std;

int main()
{
    int ok;
    do
    {
        int m=0,n,i,g,a=0,s=0,f=0;
        cout<<"You you can enter only natural numbers"<<endl;
        cout<<"How many numbers you want to input? Please enter n:";
        cin>>n;///cik vertibas tiks parbauditas?
        while(n<=0)
        {
            cin.clear();
            cin.ignore (256,'\n');
            cout<<"ERROR! Enter n again:  "<<endl;
            cin>>n;
        };
        cout<<"You entered n="<<n<<endl;
        const int size=(n-1);
        int arr[size];///masiva glabasies ievaditas a(n)vertibas
        for (i=0; i<=(n-1); i++)
        {
            cout << " Please enter number a("<<(i+1)<<"):"<<endl;
            cin >> arr[i];///ievada katru a(n) vertibu
            while(arr[i]<=0)
            {
                cin.clear();
                cin.ignore (256,'\n');
                cout<<"ERROR! Enter a("<<(i+1)<<") again:  "<<endl;
                cin>>arr[i];
            };
            a=arr[i];
            for( g=2; g<a ; g++)///parbauda vai a(n) ir pirmskaitlis.
            {
                if(a%g==0)
                {
                    s++;///mainas tikai tad, ja a(n) nav pirmskaitlis
                }
            };
            if((s!=0)&&(m==0||m>a))///ja a(n) nav pirmskaitlis.
            {
                m=a;///saglabajam mazako a(n) vertibu.
            }
            s=0;///var nakamo a(n) parbaudit.
            }
        if(m==0)///rezultats, ja visi a(n)ir pirmskaitli.
        {
            cout<<"Results:You entered only prime numbers"<<endl;
        }
        else ///parada mazako  a(n) nepirmskaila vertibu.
        {
            cout<<"Results:"<<m<<" is the smallest nonprime number value!"<<endl;
        }
        cout<<"If you want to repeat, please input (1), or input (0) to end the programm:"<<endl;
        cin>>ok;///programmas atkartosana.
    }
    while(ok==1);
    return 0;
}
