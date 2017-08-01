#include <iostream>

using namespace std;

int main()
{
    int x,n;
    cin>>n;
    if(n>=10)
    {
        while(n>=10)
        {

              x=n%10;
              n=n/10;
        }

        cout << x << endl;
    }

    return 0;
}
