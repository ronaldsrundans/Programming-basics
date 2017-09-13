#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct elem
{
    elem *right=NULL;
    elem *left=NULL;
    char word[11];
    int n=0;
};

void inorder(elem *ptr)
{
    if (ptr == NULL)
        return;
    //if (ptr != NULL
    else
    {
        inorder(ptr->left);
       // cout<<ptr->key<<"  ";
        inorder(ptr->right);
    }
}
void insertNode(elem *t)
{
    if (t == NULL)
    {
        t = new elem;
        t->left = t->right = NULL;
       // t->key = x;
///t->fix = rand();
    }

        else
        {
           /* if (x < t->key)
            {
                insert(t->left, x);
                if (t->left->fix > t->fix)
                    sigrotr(t);
            }
            else
            {
                insert(t->right, x);
                if (t->right->fix > t->fix)
                sigrotl(t);
            }
        }*/
    }
}
void stringToList(char s[][4], int n,elem* root)
{
    elem* ptr;
    ptr=root;
    int j=0;
    for(int i=0;i<n;i++)///izveido no vardiem sarakstu
    {
        if(ptr==NULL)
        {
            ptr=new elem;
        }
        else
        {
            while(ptr!=NULL)
                  {
                    ptr=ptr->left;
                  }
        }
        j=0;
        while(s[i][j]!=0)
        {
            ptr->word[j]=s[i][j];
             j++;
        }
        ptr->word[j]=0;
        ptr->left=NULL;
        ptr->right=NULL;
    }
}
void makeTree(elem* ptr, elem* &root)///firstI, rootI
{
    ptr=ptr->left;
    elem* tmp;
    if(root==NULL)
    {
        cout<<"NO LIST"<<endl;
        root=ptr;///pirmais elem
    }
    //tmp=root;
    else
    {
        while(ptr!=NULL)
        {
            if(ptr->word[0])
            {
                            cout<<ptr->word<<endl;
            ptr=ptr->left;
            }

        }
    }


}

int main ()
{
    //elem *firstE=NULL, *lastE=NULL, *p;
    elem *firstI=NULL, *rootI=NULL, *q, *r;
    //char arrE[5][4]={{"E"},{"E+E"},{"E*E"},{"E-E"},{"I"}};
    char arrI[5][4]={{"I"},{"a"},{"b"},{"aI"},{"Ib"}};
    char start[4]="I";
    /*
    stringToList(arrI, 5,firstI);
    for(q=firstI;q!=0;q=q->left)
    {
        cout<<q->word[0]<<endl;
    }
*/  int j=0;
    for(int i=0;i<5;i++)
    {
        q=new elem;
        j=0;
        while(arrI[i][j]!=0)
        {
            q->word[j]=arrI[i][j];
          //  cout<<arrI[i][j]<<endl;
             j++;
        }
        q->word[j]=0;
       // cout<<endl;
        if(firstI==NULL)
        {
            firstI=q;
        }
        else
        {
            r=firstI;
            while(r->left!=NULL)
            {
                r=r->left;
            }
            r->left=q;
        }
        //cout<<arrI[i]<<endl;

    }
    q=firstI;
    while(q!=NULL)
    {
       // cout<<q->word<<endl;
        q=q->left;
    }
    makeTree(firstI, rootI);
    q=rootI;
     while(q!=NULL)
    {
        cout<<q->word<<endl;
        q=q->left;
    }
    q=firstI;
    while(q!=NULL)
    {
        cout<<q->word<<endl;
        q=q->left;
    }
//stringToList(arrE, 5,firstE,lastE, p);
//stringToList(arrI, 5,firstI,lastI, p);
   // printList(firstE);
  //  printList(firstI);

  //  deleteList(firstI);

    return 0;
}

