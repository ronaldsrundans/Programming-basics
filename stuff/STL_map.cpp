#include <iostream>
#include <map>

using namespace std;

typedef map<string,string>dictionary;

typedef dictionary::iterator dictit;
int main()
{
    dictionary d;
    d["day"]="giorno";
    d["street"]="strada";
    d["italian"]="italiano";
    d["red"]="rosso";
    string s;
    cin>>s;
    dictit it=d.find(s);
    if (it!=d.end())
          cout << it->first <<" "<<it->second<< endl;
     else   cout << "Not found!" << endl;
    return 0;
}
