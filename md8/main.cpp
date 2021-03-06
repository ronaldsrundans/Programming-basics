/*Izveidot programmu valoda C++.  Ja programma darbojas
ar failu, nedrikst dublet visa faila saturu operativaja
atmina. Ar faila komponenti tiek saprasts fikseta garuma
ieraksts.
Uzrakstit programmu, kas visus standarta C++ rezervetos
vardus ieliek  sakartota tabula. Uzrakstit funkciju, kas ar
binaras meklešanas palidzibu nosaka, vai dota simbolu virkne
(garums lidz 30) ir C++ rezervetais vards vai nav. Tabulu realizet
ka tiešas pieejas failu. C++ rezervetie vardi programmai janolasa
no teksta faila.*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int buffer_size=30;
class person
{
    char word[buffer_size];
public:
    void copy_word(const char *n)///iekope vardu no saraksta
    {
        strcpy(word, n);
    }
    void write(ostream &fout)///nokopeto vardu ieraksta bin faila
    {
        fout.write(word, buffer_size);
    }
    bool read(istream &fin)
    {
        fin.clear();
        fin.seekg(0,ios::cur);///sak no faila sakuma
        fin.read (word, buffer_size);///nolasa vardu
        return fin.good();
    }
   char bin_search(istream &fin, char* carr)
    {
        fin.clear();
        char c;
        char c1;
        char c2;
        int mid=0;
        int low=0;
        int high=0;
        fin.seekg(low,ios::beg);///atrod faila sakumu
        low=fin.tellg();
        c1=fin.get();///pirmais burts
        fin.seekg(-30,ios::end);
        high=fin.tellg();
        fin.seekg(high,ios::beg);///atrod pedeja varda pirmo burtu
        c2=fin.get();
        if(carr[0]>c2)///ja pedeja varda burts ir mazaks par ievadito vardu
        {
            return 0;
        }
        else/// binara meklesana
        {
            mid=(((low+high)/2)/30)*30;
            fin.seekg(mid,ios::beg);
            c=fin.get();///videjais burts
            while(c1<=c2)
            {

                mid=(((low+high)/2)/30)*30;
                fin.seekg(mid,ios::beg);
                c=fin.get();///videjais burts
                if(carr[0]==c)
                {
                    return c;///atgriez burtu ar kuru sakas vards
                    break;
                }
                else if(c<carr[0])///ja c vertiba par mazu, tad parbida low
                {
                    low=mid+30;
                    fin.seekg(low,ios::beg);
                    c1=fin.get();
                    c=c1;
                }
                else///ja c vertiba par lielu, tad parbida high
                {
                    high=mid-30;
                    fin.seekg(high,ios::beg);
                    c2=fin.get();
                    c=c2;
                }
            }
            return 0;
        }

    }
    bool search_word(istream &fin, char* carr)///mekle vardu pilna garuma, kas sakrit ar ievadito
    {
         fin.clear();
         int n=strlen(carr);
         int n2=strlen(word);
         int j=0;
        if(carr[0]==word[0]&&n==n2)
        {
            for(int i=0;i<n;i++)
            {
                if(word[i]==carr[i])
                {
                    j++;
                    if(j==n)
                    {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
    void print()
    {
        cout<<"word="<<word<<endl;
    }
};

struct elem
{
    char word[30];

    elem *next;
};
void add_element (elem*&first, elem*&last, char* c)///izveido sarakstu pec pirma simbola alfabetiska kartiba
{
    elem *p = new elem;///jaunais elements
    elem *r = new elem;///norade uz saraksta ieprieksejo elementu
    r->next = NULL;
    int i;
    for(i=0;c[i]!=0;i++)
    {
         p->word[i] = c[i];
    }
    p->word[i] = 0;
    p->next = NULL;
    if (first == NULL)///ja saraksta viens elements
    {
        first = p;
        last = p;
    }
    else
    {
        for(elem *q = first; q!=NULL; q=q->next)
        {
            if(p->word[0]>q->word[0])///ja jaunais elements ir aiz kada varda
            {
                if(r->next!=NULL)
                {
                     if(q==first)///aiz pirma
                    {
                        p->next=q->next;
                        q->next=p;
                    }
                    else if(q==last)
                    {
                        q->next=p;
                        last=p;
                    }
                }
                if(q->next==NULL)///aiz pedeja
                {
                    p->next=q->next;
                    q->next=p;
                     last=p;
                }
            }
            else if(p->word[0]==q->word[0]&& p!=q)
            {

                  p->next=q;
                r->next=p;
                if(q==first)
                {
                    first=p;
                }
                break;
            }
            else if(p->word[0]<q->word[0])
            {
                if(q==first)
                {
                    first=p;
                    p->next=q;
                    break;
                }
                else
                {
                    r->next=p;
                    p->next=q;
                    break;
                }
            }
            r=q;///saglaba noradi uz ieprieksejo
        }
    }
};
void delete_list (elem*&first)///izdzes sarakstu
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
        char carr[30];
        carr[0]=0;
        elem *first=NULL, *last=NULL, *p,*q;
        int i=0;
        int n2=0;
        char c;
        fstream fin("rezervetie.txt", ios::in);
        fstream foutbin("out.bin", ios::out);
        person t;
        fin.get(c);
        while(fin)///no faila ielasa katru vardu un izveido sakartotu sarakstu
        {
            if(c==' 'or c=='\n')
            {
                if(carr[0]!=0)
                {
                    add_element (first, last, carr);///pievieno vardu sarakstam
                    carr[0]=0;
                }
                i=0;
            }
            else
            {
                carr[i]=c;
                i++;
                carr[i]=0;
            }
            fin.get(c);
        }
        if(first==NULL)
        {
              cout<<"Erorr!";
        }
        else
        {
           for (elem *z = first; z!=NULL; z=z->next)
            {
                t.copy_word(z->word);
                t.write(foutbin);
            }
        }
    delete_list (first);///izdzes sarakstu
    fin.close();
    foutbin.close();
    bool repeat=1;
    do{
    cout << "Enter a name: " << endl;
    cin >> carr;
    fstream foutbin2("out.bin", ios::in);
    char c_bin=0;
    c_bin=t.bin_search(foutbin2, carr);///binara meklesana
    foutbin2.close();
    fstream foutbin3("out.bin", ios::in);
    if(c_bin!=0)///ja ir vardi, kas sakas ar ievadita varda burtu
    {
        bool check=0;
        while(t.read(foutbin3))
        {
            if(t.search_word(foutbin3, carr)==1)
              {
                  cout<<"It is a match! Found keyword: "<<carr<<endl;
                  check=1;
              }
        }
        if(check==0)///ja nav sakritosi vardi, kas sakas ar ievadita varda burtu
        {
            cout<<"No such element!" << endl;
        }
    }
    else///ja nav vardi, kas sakas ar ievadita varda burtu
    {
        cout<<"No such element!" << endl;
    }
    foutbin3.close();
    cout<<"Repeat?" << endl;
    cin>>repeat;
    }
    while(repeat==1);
    return 0;
}


