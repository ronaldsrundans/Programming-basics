#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct elem
{
    elem *next=NULL;
    char word[11];
    int n=0;
};
void copyWord(int l,char *from,char*to)
{
    int i=l;
    while(i>=0)
    {
        to[i]=from[i];
        i--;
    }
}
void addElem(elem *&last, elem * newelem)
{

}


int main ()
{
    elem *first, *last, *q, *r,*p ,*start,*print, *printlast;
    first=last=print=NULL;
    char arrE[5][4]={{"E"},{"E+E"},{"E*E"},{"E-E"},{"I"}};
    //char arrI[5][4]={{"I"},{"a"},{"b"},{"aI"},{"Ib"}};
    char tmp1[11];
    char tmp2[11];
    char tmp3[11];
   // char tmp4[11];
    start=new elem;
    int i=0,j=0,l=0,k=0,t=0;
    char startword[11]="E+E";
    while(startword[i]!=0)
    {
       start->word[i]=startword[i];
       i++;
    }
    start->n=i;
    i=0;
    for(i=0;i<5;i++)
    {
        q=new elem;
        j=0;
        while(arrE[i][j]!=0)
        {
            q->word[j]=arrE[i][j];
             j++;
        }
        q->word[j]=0;
        q->n=j;
       // cout<<endl;
        if(first==NULL)
        {

            first=q;
            last=q;
        }
       else
        {
            last->next=q;
            last=q;
        }
        //cout<<arrE[i]<<endl;
    }

    if(start!=NULL)
    {
        l=start->n;
          tmp1[0]=0;
            tmp2[0]=0;
            tmp3[0]=0;
    copyWord(start->n,start->word,tmp1);
    cout<<tmp1<<endl;
    i=0;
    while(tmp1[i]!=0)
    {
        if(tmp1[i]==first->word[0])//sakrit ar "E"
        {
            cout<<"match"<<endl;//then make new strings
            k=0;
            j=0;

           // r=NULL;
            while(j<i)//word sakumu nokope
            {
                tmp2[j]=tmp1[j];
                j++;
            }
             tmp2[j]=0;
            j=j+1;
            while(j<l)//word beigas
            {
                tmp3[j-i-1]=tmp1[j];
                j++;
            }
            tmp3[j-i-1]=0;
            t=j-i-1;

            q=first->next;
            while(q!=NULL)
            {
                r=new elem;
               // cout<<"Goal="<<tmp2<<q->word<<tmp3<<endl;
                k=0;
                while(k<i)///nokope varda pirmo dalu
                {
                   // tmp4[k]=tmp2[k];
                    r->word[k]=tmp2[k];

                    k++;
                }
                k=0;
                while(k<q->n)//aizpilda ar jaunajiem simboliem
                {
                    r->word[k+i]=q->word[k];
                    k++;
                }
                j=k+i;
                while(tmp3[k-j+i]!=0)//aizpilda ar jaunajiem simboliem
                {
                    r->word[k+i]=tmp3[k-j+i];
                    k++;
                }
               r->word[k+i]=0;
              cout<<"r="<<r->word<<endl;//word beigas
                ///saraksta izdruka
                //p=print;


               if(print==NULL)
                {
                    cout<<"This!?"<<endl;
                    cout<<"EMPTY"<<endl;
                    print=r;
                    printlast=r;
                    p=print;
                }
                else
                {
                    printlast->next=r;
                    printlast=printlast->next;
                }
                q=q->next;
            }
        }
        i++;
    }
    delete start;
      for(p=print;p!=NULL;p=p->next)
      {
          cout<<"Print="<<p->word<<endl;
        }
    }

    return 0;
}

