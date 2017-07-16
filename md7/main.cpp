/**/
/*******************************************
Ronalds Rundans

Izveidot programmu valoda C++, kas lauj izveidot
vienvirziena saistito sarakstu (izmantojot dinamiskas
datu strukturas), kura glabajas noteikta tipa vertibas.
 Jabut  paredzetai iespejai sarakstu papildinat ar
jaunu elementu (pielikt elementu saraksta gala),
izdrukat sarakstu, iznicinat sarakstu. Bez tam jauzraksta
 funkcija, kura aprakstita zemak. Iznicinot saraksta
 elementus, korekti jaatbrivo izdalita atmina. Galvenaja
 programma:
  a) jabut iespejai ievadit saraksta elementus (izveidot patvaligu sarakstu),
  b) japielieto uzrakstita funkcija sarakstam,
  c) jaizdruka saraksts pec funkcijas darbibas.
  d) beigas jaiznicina saraksts (lietojot delete).
Sikakas prasibas sk. Laboratorijas darbu noteikumos.
G10. Uzrakstit funkciju, kas parbauda, vai saraksta ir  vismaz divi elementi ar vienadam vertibam.
Programma izveidota: 2016/03/16
*******************************************/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct elem/// saistita saraksta elementa deklaracija
{
    int num;
    elem *next;
};

bool have_it(int i,elem *first2)///funkcija, kas parbauda vai saraksta jau ir vertiba i
{
    int j;
    for (elem *q = first2; q!=NULL; q=q->next)
    {
        j=q->num;
        if(i==j)
        {
            return true;///ja ir si vertiba saraksta
        }
    };
    return false;///ja nav si vertiba saraksta
}

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

elem *check_id (elem *first1, elem *first2, elem*last2)///funkcija, kas parbauda, vai saraksta ir  vismaz divi elementi ar vienadam vertibam.
{
   elem *q=first2;
   int k;
        for (elem *p = first1; p!=NULL; p=p->next)
        {
            k=0;
             for (elem *q = first1; q!=NULL; q=q->next)
                {
                    if(p->num==q->num)
                    {
                        k++;
                        int i=q->num;
                        bool nav=have_it(i,first2);
                        if(k>1&&nav==0)///ja vertiba atkartojas vismaz 2 reizes un nav iekopeta otra saraksta
                        {
                            k=0;
                            add_element (first2, last2,i);

                        }
                    }
                }
        };
     return first2;
};

int main ()
{
    bool atk=1;
    do
    {
        elem *first1=NULL, *last1=NULL, *first2=NULL, *last2=NULL, *p;
        int i;
        cout << "Enter a list of values and 0 to quit!" << endl;
        cin >> i;
        while (i != 0)
        {
            add_element (first1, last1, i);///vertibas pievienosana saistitajam sarakstam
            cin >> i;
        };
        cout << "The list: " << endl;///saraksta izdruka pirms funkcijas darbibas
        print_list (first1);
        p = check_id (first1, first2, last2);///funkcija, kas parbauda, vai saraksta ir  vismaz divi elementi ar vienadam vertibam.
        if (p == NULL) cout << "No identical elements!" << endl;///neizdruka vertibas, ja nav vienadas vertibas
        else
        {
            cout << "The 2 or more identical values are: " << endl;
            print_list (p);///izdruka vertibas pec funkcijas darbibas
        };
        delete_list (first1);///izdzes ievadito sarakstu
        delete_list (first2);///izdzes vienado vertibu sarakstu
        cout << "To repeat a different list-enter 1 or 0 to quit!" << endl;
        cin>>atk;
        }
        while(atk==1);

    return 0;
}
