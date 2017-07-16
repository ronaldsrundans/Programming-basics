#include <iostream>
#include "skaitlis.h"
using namespace std;


int main()
{
    int x,y;
    cin>>x;
    cin>>y;
    skaitlis *s;
    s=new skaitlis(x,y);
    //s->print();
   delete s;
    //s->~skaitlis();
    return 0;
}
