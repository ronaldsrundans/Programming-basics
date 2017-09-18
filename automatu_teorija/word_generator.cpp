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


int main ()
{
    elem *first=NULL, *last=NULL, *q, *r, *start;//=NULL;
    char arrE[5][4]={{"E"},{"E+E"},{"E*E"},{"E-E"},{"I"}};
    //char arrI[5][4]={{"I"},{"a"},{"b"},{"aI"},{"Ib"}};
    char tmp1[11];
    char tmp2[11];
    char tmp3[11];
    char tmp4[11];
    start=new elem;
    int i=0,j=0,l=0,k=0;
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
    copyWord(start->n,start->word,tmp1);
    cout<<tmp1<<endl;
    i=0;
    while(tmp1[i]!=0)
    {
        if(tmp1[i]==first->word[0])//sakrit ar "E"
        {
            cout<<"match"<<endl;//then make new strings
            j=0;
            while(j<i)//word sakumu nokope
            {
                tmp2[j]=tmp1[j];
                j++;
            }
             tmp2[j]=0;
            j=i+1;
            while(j<l)//word beigas
            {
                tmp3[j-i-1]=tmp1[j];
                j++;
            }
            tmp3[j-i-1]=0;
            cout<<"tmp1="<<tmp1<<endl;//word
            cout<<"tmp2="<<tmp2<<endl;//word sakums
            cout<<"tmp3="<<tmp3<<endl;//word beigas
            q=first->next;
            while(q!=NULL)
            {
                cout<<tmp2<<q->word<<tmp3<<endl;
                q=q->next;
            }
            /* k=0;
            while(k<i)//sak
            {
                tmp4[k]=tmp1[k];
                k++;
            }
            while(k<j-i-1+k)//vidus
            {
                tmp4[k]=tmp1[k];
                k++;
            }
            while(k<)//beigas
             {
                tmp4[k]=tmp1[k];
                k++;
            }
*/




        }
        i++;
    }

        q=first;
        while(q!=NULL)
        {
           // cout<<q->word<<endl;
            q=q->next;
        }
    }

    return 0;
}

