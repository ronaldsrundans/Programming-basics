#include <iostream>

using namespace std;

typedef pair<string,int>person;
int main()
{
    person p("Liz", 19);
    cout << p.first <<" "<<p.second<< endl;
    return 0;
}
