#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> intarray;

class lastdigit_compare
{
public:
    bool operator()(const int &v1, const int &v2)const
    {
        return v1%10<v2%10;
    }
};
int main()
{
    intarray arri(3);
    arri[0]=52;
    arri[1]=28;
    arri[2]=47;
    sort(arri.begin(), arri.end());
    for(int i=0;i<arri.size();i++)cout<<arri[i]<<endl;
    sort(arri.begin(), arri.end(),lastdigit_compare());
    cout<<endl;
  for(int i=0;i<arri.size();i++)cout<<arri[i]<<endl;
    return 0;
}
