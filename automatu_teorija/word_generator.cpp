#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct elem/// saistita saraksta elementa deklaracija
{
    char word[4];
    elem *next;
};
/*struct ctreenode
{
    int key, fix;
    ctree left, right;
};
ctree nullnode, root;

typedef struct namenode *ctname;
struct namenode
{
    int key, fix;
    ctname left, right;
    char carr[101];
};
ctname nullname, rootname, parsename;



void add_element (elem*&first, elem*&last, char *c)///jauna elementa pievienosana saraksta gala
{
    elem *p = new elem;
    int i=0;
    while(c[i]!=0)
    {
        p->word[i] = c[i];
        i++;
    }
    p->word[i]=0;
    p->next = NULL;
    if (first == NULL) first = p;///ja saraksts ir tukss, tad nomaina pirmo elementu
    else last->next = p;///ja saraksts nav tukss, tad pieliek gala
    last = p;
};

void print_list (elem *first)///saraksta izdrukasana
{
    for (elem *p = first; p!=NULL; p=p->next)
    {
        cout << p->word << endl;
    };
};*/

void printString(char s[][4], int n)
{
    int j=0;
    for(int i=0;i<n;i++)
    {
        j=0;
        while(s[i][j]!=0)
        {
             cout<<s[i][j];
             j++;
        }
       cout<<endl;
    }

}

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
void makeList(char (*s)[4], elem* first, elem* last, int n)
{
      for (int i=0;i<n;i++)
        {
           // add_element (first, last, );///vertibas pievienosana saistitajam sarakstam
            //cin >> i;
        };
}

int main ()
{
        elem *first1=NULL, *last1=NULL, *first2=NULL, *last2=NULL, *p;
        char arrE[5][4]={{"E"},{"E+E"},{"E*E"},{"E-E"},{"I"}};
        char arrI[5][4]={{"I"},{"a"},{"b"},{"aI"},{"Ib"}};
        printString(arrE, 5);
        printString(arrI, 5);
       // makeList(arrE, first1,  last1, 5);
      //  makeList(arrE, first2, last3, 5);
        cout << "The list: " << endl;///saraksta izdruka pirms funkcijas darbibas
        /*print_list (first1);
        print_list (first2);
        delete_list (first1);///izdzes ievadito sarakstu
        delete_list (first2);///izdzes vienado vertibu sarakstu
*/
    return 0;
}

