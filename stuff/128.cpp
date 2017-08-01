#include <iostream>

using namespace std;

int main()
{
    int i,j,a;
    for(i=0;i<128;i++)
    {
        for(j=0;j<128;j++)
        {
            a=i*j;
            while(a>=128)
            {
                a=a-128;
            }
            if(a==0)
            {
                cout<<"i*j="<<a<<" "<<"i="<<i<<" "<<"j="<<j<<endl;
            }
        }
    }
    return 0;
}
