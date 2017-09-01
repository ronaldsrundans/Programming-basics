#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> intarray;

int main()
{
    intarray arri(2);
    arri[0]=11;
    arri[1]=22;
    arri.push_back (33);
    for(int i=0;i<arri.size();i++)cout<<arri[i]<<endl;
    intarray::iterator it=arri.begin();
    while (it !=arri.end())
    {
        cout<<*it<<endl;
        it++;
    }
    return 0;
}
