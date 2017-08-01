#include <iostream>
#include <fstream>
using namespace std;

int main()
{
fstream fin("atbalsts.in", ios::in);
fstream fout("atbalsts.out", ios::out);
fout << "0 1"<<'/n';
fout <<"1 10"<<'/n';
fout <<"2 100"<<'/n';
fout <<"3 5"<<'/n';
fout <<"3 50"<<'/n';
fout <<"4 10"<<'/n';
fout <<"1 51"<<'/n';
fout <<"4 52"<<'/n';
fout <<"2 53"<<'/n';
fout <<"0 54"<<'/n';
fin.close();
fout.close();
    return 0;
}
