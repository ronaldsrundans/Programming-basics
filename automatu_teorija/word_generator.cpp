

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

int haveElem(char* c1,char* c2, int n,int x,int &num)
{
    int i=0;
   // cout<<num<<endl;
   if (n==x)
   {
    while(c1[i]==c2[i]&&i<n)
    {       // cout<<"c1="<<c1->word[i]<<"  c2="<<c2->word[i]<<endl;
            i++;
    }
    if(i==n)
    {
        //cout<<"yes"<<endl;
                num=0;///ja ir vienadi vardi
    }
    else
        num=1;
    }
    else
    {
    num=1;
    }


}
void addElem(elem* &last, elem* &a)
{
    last->next=a;
    last=last->next;

}
int haveElem2(elem* c1,elem* c2)
{
    elem* p;
    p=c1;
    int i=0;
    while(c1->word[i]==c2->word[i]&&i<c1->n)
    {       // cout<<"c1="<<c1->word[i]<<"  c2="<<c2->word[i]<<endl;
            i++;
    }
    if(i==c1->n)
    {
        //cout<<"yes"<<endl;
                return 1;
    }
    else return 0;

}


void stringToList(char s[][4], int n,elem* &f, elem* &l)
{
    elem* t;
    int j=0;
    for(int i=0;i<n;i++)///izveido no vardiem sarakstu
   {
        t=new elem;
        j=0;
        while(s[i][j]!=0)
        {
            t->word[j]=s[i][j];
             j++;
        }
        t->word[j]=0;
        t->n=j;
       // cout<<t->word<<endl;
        if(f==NULL)
        {

            f=t;
            l=t;
        }
       else
        {
            l->next=t;
            l=t;
        }
        //cout<<arrE[i]<<e
     }
 }
 void printList(elem *f)
 {

 elem* p;

     for(p=f;p!=NULL;p=p->next)
      {
      cout<<p->word<<endl;
      }
 }



int main ()
{
    elem *first, *last, *q, *r,*p ,*u, *v,*ptr,*tmpfirst, *tmplast,*z,*firstE, *lastE,*firstI, *lastI,*start, *stop;
     firstI=lastI=firstE=lastE=first=last=tmpfirst=tmplast=NULL;
     ///izveduma likumi
    char arrE[5][4]={{"E"},{"E+E"},{"E*E"},{"E-E"},{"I"}};
    char arrI[5][4]={{"I"},{"a"},{"b"},{"aI"},{"Ib"}};
    char tmp1[11];
    char tmp2[11];
    char tmp3[11];
    char tmp4[11];
    first=new elem;
    int i=0,j=0,l=0,k=0,t=0,m=0,countE=0,countI=0, num=0;
    ///sakuma vards
    char startword[11]="E";
  while(startword[i]!=0)
    {
       first->word[i]=startword[i];
       i++;
    }
    first->n=i;
    stringToList(arrE,5,firstE, lastE);
    stringToList(arrI,5,firstI, lastI);
    ///test
   // first=firstE;
    ptr=first;
    last=first;
while(ptr!=NULL && t<4)
{
      //  cout<<ptr->word[0]<<endl;
        tmpfirst=NULL;
        q=first;
        tmp1[0]=0;
        tmp2[0]=0;
        tmp3[0]=0;
        tmp4[0]=0;
        countE=0;
        countI=0;
        //start=NULL;
       // stop=NULL;
        i=0;
        l=ptr->n;

        while(i<l)
        {
            tmp1[i]=ptr->word[i];
            i++;
        }
        tmp1[i]=0;
        i=0;
        while(i<l)///sakas simbolu meklesana
        {
     if(tmp1[i]==firstE->word[0])
            {
            //cout<<"yes E="<<tmp1<<endl;
                countE++;
                k=0;
                j=0;
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
                q=firstE->next;
                while(q!=NULL)
                {
                    k=0;
                    while(k<i)///nokope varda pirmo dalu
                    {
                        tmp4[k]=tmp2[k];
                        k++;
                    }
                    k=0;
                    while(k<q->n)//aizpilda ar jaunajiem simboliem
                    {
                        tmp4[k+i]=q->word[k];
                        k++;
                    }
                    j=k+i;
                    while(tmp3[k-j+i]!=0)//aizpilda ar jaunajiem simboliem
                    {
                        tmp4[k+i]=tmp3[k-j+i];
                        k++;
                    }
                    tmp4[k+i]=0;
                    if(k+i<11)
                    {

                         m=1;
                      for(p=tmpfirst;p!=NULL;p=p->next)
                      {

                             haveElem(p->word, tmp4,p->n,k+i,m);
                             if(m==0)
                            {
                                break;
                             }
                        }

                     if(m==1)
                      {
                         //addElem(printlast,r);

                        r=new elem;
                         r->n=k+i;
                         for(m=k+i;m>=0;m--)
                         {
                             r->word[m]=tmp4[m];
                         }
                          if(tmpfirst==NULL)
                         {
                             tmpfirst=r;
                             tmplast=r;
                         }
                         else
                         {
                            tmplast->next=r;
                             tmplast=tmplast->next;
                         }
                     }
                    }
                  q=q->next;
              }
            }


            i++;
        }///beidzas E meklesana un jaunu elementu izveidosana


       // tmp1[0]=0;
        tmp2[0]=0;
        tmp3[0]=0;
        tmp4[0]=0;
       // countE=0;
        //countI=0;
        //start=NULL;
       // stop=NULL;
        i=0;
        l=ptr->n;

        while(i<l)
        {
            tmp1[i]=ptr->word[i];
            i++;
        }
        tmp1[i]=0;
        i=0;
        while(i<l)///sakas simbolu meklesana
        {


///I parbaude
        i=0;
        while(i<l)///sakas simbolu meklesana
        {
              if(tmp1[i]==firstI->word[0])
            {
            //cout<<"yes I="<<tmp1<<endl;
                countI++;
                k=0;
                j=0;
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
                q=firstI->next;
                while(q!=NULL)
                {
                    k=0;
                    while(k<i)///nokope varda pirmo dalu
                    {
                        tmp4[k]=tmp2[k];
                        k++;
                    }
                    k=0;
                    while(k<q->n)//aizpilda ar jaunajiem simboliem
                    {
                        tmp4[k+i]=q->word[k];
                        k++;
                    }
                    j=k+i;
                    while(tmp3[k-j+i]!=0)//aizpilda ar jaunajiem simboliem
                    {
                        tmp4[k+i]=tmp3[k-j+i];
                        k++;
                    }
                    tmp4[k+i]=0;
                    if(k+i<11)
                    {

                         m=1;
                      for(p=tmpfirst;p!=NULL;p=p->next)
                      {

                             haveElem(p->word, tmp4,p->n,k+i,m);
                             if(m==0)
                            {
                                break;
                             }
                        }

                     if(m==1)
                      {
                         //addElem(printlast,r);

                        r=new elem;
                         r->n=k+i;
                         for(m=k+i;m>=0;m--)
                         {
                             r->word[m]=tmp4[m];
                         }
                          if(tmpfirst==NULL)
                         {
                             tmpfirst=r;
                             tmplast=r;
                         }
                         else
                         {
                            tmplast->next=r;
                             tmplast=tmplast->next;
                         }
                     }
                    }
                        tmp4[0]=0;
                  q=q->next;
              }
            }


            i++;
        }///beidzas E meklesana un jaunu elementu izveidosana


 if(countI==0 && countE==0)///varda izdrukasa jo nesatur ne E ne I
        {

        cout<<"Print="<<tmp1<<endl;

        }

        ///sak pievienot jaunos elementus saraksta gala

p=tmpfirst;
while(p!=NULL)
{
q=p->next;
last->next=p;
last=last->next;
p=p->next;
}
       }

///lec uz nakamo elementu saraksta un izdzes esoso
        q=ptr->next;
        first=q;
        delete ptr;
        ptr=q;
        t++;
    }


printList(first);
    return 0;
}

