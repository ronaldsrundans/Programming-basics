#include <iostream>

using namespace std;

class number
{
    int c[32];
   // int c2[32];
    int base;
    int d=0;
    int length=0;
public:
    void set(int m, char*n)
    {
        int i=0;
        while(n[i]!='\0')
        {
            if(n[i]<='9')
            {
                c[i]=((int)n[i]-'0');
                i++;

            }
            else if(n[i]>='A'&& n[i]<='Z')
            {

               c[i]=((int)n[i]-'A'+10);
                i++;
                //cout<<"num="<<num<<endl;
            }
            else
            {
               c[i]=((int)n[i]-'a'+10);
                i++;
            }
            length++;

        }
        base=m;
        for(int j=0;j<length;j++)
        {
            d=d*base+c[j];
            //cout<<c[j]<<endl;
        }
        //while()

    }
    void print ()
    {
        cout<<"base="<<base<<endl;
        cout<<"num_dec="<<d<<endl;
        for(int i=0;i<length;i++)
        {
           // d=c
        //    cout<<c[i]<<endl;
        }
    }
    void change(int n)
    {
        base=n;
        if(base<=10)
        {
            int j=0;
            while(d>0)
            {
                c[j]=d%base;
                d=d/base;
             j++;
            }
            length=j;
        }
        for(int j=length-1;j>=0;j--)
        {
            cout<<c[j];
        }



    }

};
int main()
{
    int base;
    char c[33];
    number n;
    cout << "Ievadi skaili!" << endl;
    cin.getline(c,33);
    cout << "Ievadi skaitisanas sistemas bazi!" << endl;
    cin>>base;
    n.set(base,c);
    n.print();
    cout << "Ievadi jaunas skaitisanas sistemas bazi!" << endl;
    cin>>base;
    n.change(base);


   // cout<<c<<endl;
    //cout << "Hello world!" << endl;
    return 0;
}
