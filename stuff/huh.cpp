#include <iostream>

using namespace std;

int main()
{
    int n;
    for(int i=1;i<=100;i++)
    {
        n=i*i*i+11*i;
        if(n%6==0)
        {
            cout<<i<<endl;
        }
    }
    cout << "Hello world!" << endl;
    return 0;
}
