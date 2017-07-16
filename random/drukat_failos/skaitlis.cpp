#include "skaitlis.h"
#include <iostream>

using namespace std;

skaitlis::skaitlis(const int c ,const int d)
{
    a=c;
        b=d;
        //return 0;
    //ctor
};

void skaitlis:: print()
{
    cout<<a<<endl;
    cout<<b<<endl;
        //return 0;
    //ctor
};

skaitlis::~skaitlis()
{

    cout << "S has been deleted!" << endl;
       //dtor
};
