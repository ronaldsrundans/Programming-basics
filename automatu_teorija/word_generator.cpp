#include <iostream>
#include <cstring>

using namespace std;

struct elem/// saistita saraksta elementa deklaracija
{
    int num;
    elem *next;
};


void add_element (elem*&first, elem*&last, int i)///jauna elementa pievienosana saraksta gala
{
    elem *p = new elem;
    p->num = i;
    p->next = NULL;
    if (first == NULL) first = p;///ja saraksts ir tukss, tad nomaina pirmo elementu
    else last->next = p;///ja saraksts nav tukss, tad pieliek gala
    last = p;
};

void print_list (elem *first)///saraksta izdrukasana
{
    for (elem *p = first; p!=NULL; p=p->next)
    {
        cout << p->num << endl;
    };
};

void delete_list (elem*&first)///saraksta dzesana
{
    elem *p = first;
    while (p!=NULL)
    {
        first = first->next;
        delete p;
        p = first;
    };
};

int main ()
{
        elem *first1=NULL, *last1=NULL, *first2=NULL, *last2=NULL, *p;
        char arrE[5][4]={{"E"},{"E+E"},{"E*E"},{"E-E"},{"I"}};
        char arrI[5][4]={{"I"},{"a"},{"b"},{"aI"},{"Ib"}};

        while (i != 0)
        {
            add_element (first1, last1, i);///vertibas pievienosana saistitajam sarakstam
            cin >> i;
        };
        cout << "The list: " << endl;///saraksta izdruka pirms funkcijas darbibas
        print_list (first1);
        if (p == NULL) cout << "No identical elements!" << endl;///neizdruka vertibas, ja nav vienadas vertibas
        else
        {
            cout << "The 2 or more identical values are: " << endl;
            print_list (p);///izdruka vertibas pec funkcijas darbibas
        };
        delete_list (first1);///izdzes ievadito sarakstu
        delete_list (first2);///izdzes vienado vertibu sarakstu

    return 0;
}

