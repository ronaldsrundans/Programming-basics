#include <iostream>
#include <cstring>
using namespace std;

void sum(char (*a), char (*b))
{
    cout << "Results:" << endl;
    cout << "a=" <<a<< endl;
    cout << "b=" <<b<< endl;
}

int main()
{
    int const size=100;
    char a[size]={0};
    char b[size]={0};
    cout<< "Enter char a:"<< endl;
    cin.getline(a,size);
    cout << "Enter char b:" << endl;
    cin.getline(b,size);
    sum(a,b);
    return 0;

}


   // cout << "a+b=c=" << summa(&char a, &char b)<< endl;



