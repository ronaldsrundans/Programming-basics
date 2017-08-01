#include <iostream>

using namespace std;

int main()
{
    int n=0;
    int* arr=new int[81];
    for(int i=0;i<81;i++)
    {
        arr[i]=1;
    }
     for(int i=0;i<81;i++)
    {
        n=n*10+1;
        cout<<"n="<<n<<endl;
        if(n<81)
        {
            continue;
        }
        else
        {
            n=n%81;
            cout<<n<<endl;
        }

    }
    delete arr;
   // cout << "Hello world!" << endl;
    return 0;
}
