#include <iostream>

using namespace std;

void add(int&,int, int);

int main()
{
    int x=3, y=4,z;
    add(z,x,y);
    cout << z << endl;
    return 0;
}
void add (int &r,int a, int b)
{
    r=a+b;
    return;
}
