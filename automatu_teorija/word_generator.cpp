#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct elem
{
    char word[4];
    elem *next;
};
struct tree
{
    tree *right;
    tree *left;
    char wordstring[11];
};
tree* root=NULL;
void stringToList(char s[][4], int n,elem*&first, elem* &last, elem* &r)
{
    int j=0;
    for(int i=0;i<n;i++)
    {
        r=new elem;
        j=0;
        while(s[i][j]!=0)
        {
            r->word[j]=s[i][j];
             j++;
        }
        r->word[j]=0;
        r->next=NULL;
        if (first==NULL)
        {
            first=last=r;
        }
        else
        {
            last->next=r;
            last=last->next;
        }
    }
}
void printList(elem*first)
{
    elem* r;
 for(r=first;r!=NULL;r=r->next)
        {
            cout<<r->word<<endl;
        }
}
void deleteList (elem*&first)///saraksta dzesana
{
    elem *p = first;
    while (p!=NULL)
    {
        first = first->next;
        delete p;
        p = first;
    };
};
/*
 * Insert Element into Tree
 */
void insertTree(tree*t, char* c)
{
    if (t == NULL)
    {
        cout<<"t->NULL!"<<endl;
        t = new tree;
        t->left = t->right = NULL;
    }
    else///ja nav tukss koks
    {
        cout<<"t->else!"<<endl;
        int i=0;

        //else
//{
            if (c[i] < t->wordstring[i])
            {
                insertTree(t->left, c);
            }
            else
            {
                insertTree(t->right, c);
            }
        //}
    }
}



int main ()
{
    elem *firstE=NULL, *lastE=NULL, *p;
    elem *firstI=NULL, *lastI=NULL, *q;
    char arrE[5][4]={{"E"},{"E+E"},{"E*E"},{"E-E"},{"I"}};
    char arrI[5][4]={{"I"},{"a"},{"b"},{"aI"},{"Ib"}};
    char start[4]="E";
    stringToList(arrE, 5,firstE,lastE, p);
    stringToList(arrI, 5,firstI,lastI, p);
   // printList(firstE);
  //  printList(firstI);
    for(p=firstE;p!=NULL;p=p->next)
    {

        for(q=firstI;q!=NULL;q=q->next)
        {
            insertTree(root, q->word);
            cout<<p->word<<"  "<<q->word<<endl;

        }
    }
    deleteList(firstE);
    deleteList(firstI);
    return 0;
}

