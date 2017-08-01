#include <iostream>
#include <cstring>
using namespace std;
bool ch_bbb(string name)
{
    for(int i=0;name[i]!=0;i++)
    {
        if(name[i]=='b')
        {
            if(name[i+1]=='b')
            {
                if(name[i+2]=='b')
                {
                    return true;
                }
            }
        }
    }
    return false;
}
bool ch_cbc(string name)
{
    for(int i=0;name[i]!=0;i++)
    {
        if(name[i]=='c')
        {
            if(name[i+1]=='b')
            {
                if(name[i+2]=='c')
                {
                    return true;
                }
            }
        }
    }
    return false;
}
bool automats_bbb_cbc(string name)
{
    cout<<"Final state is:"<<endl;
    if(ch_bbb(name)!=ch_cbc(name) && (ch_bbb(name)==1 ||ch_cbc(name)==1 ))
    {
        return true;
    }
    else return false;
}
int main()
{
    bool atk=1;
    do
    {
        string name;
        cout<< "Enter a name!" << endl;
        cin>>name;
        cout<<automats_bbb_cbc(name)<<endl;
        cout<<"Do you want to check different name? Enter:1 or 0!"<<endl;
        cin>>atk;
    }
    while(atk==1);
  return 0;
}
