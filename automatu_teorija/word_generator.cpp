#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

/*typedef struct namenode *ct;

struct namenode
{
    int l1, l2, fix;
    ct left, right;
    char carr[21];
    char arr[21];
};
ct null1, root1, tm1, root2, tm2;

class CT
{
    public:
        void initialize();
        void sigrotl(ct &);
        void sigrotr(ct &);
        void insert(ct &, char*,int,char*,int);//,ct &);
        bool translate(ct , char*,int,ct &);


        CT()
        {}
};
void CT::initialize()
{
    null1 = new namenode;
    null1->left = null1->right = null1;
    root1=null1;
    root2=null1;
    tm1=null1;
    tm2=null1;
}
void CT::sigrotl(ct& k1)
{
    ct k2;
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1 = k2;
}
void CT::sigrotr(ct& k1)
{
    ct k2;
    k2 = k1->left;
    k1->left = k2->right;
    k2->right = k1;
    k1 = k2;
}
void CT::insert(ct& t, char* c, int x,char* a, int y)
{
    if (t == null1)
    {
        t = new namenode;
        t->left = t->right = null1;
        t->l1=x;
        t->l2=y;
        t->fix = rand();
        for(int i=0;i<=x;i++)
        {
            t->carr[i]=c[i];
        }
        for(int i=0;i<=y;i++)
        {
            t->arr[i]=a[i];
        }
    }
    else///ja nav tukss koks
    {
        int i=0;
        while(i<x)
        {
            if(t->carr[i] == c[i])
           {
               i++;
           }
           else
            {
                break;
            }
        }
        if (c[i] < t->carr[i])
            {
                insert(t->left,c,x,a,y);
                if (t->left->fix > t->fix)
                {
                    sigrotr(t);
                }
            }
            else
            {
                insert(t->right,c,x,a,y);
                if (t->right->fix > t->fix)
                sigrotl(t);
            }
    }
}
bool CT::translate(ct t, char* c, int l, ct& n)
{
    if (t == null1)
    {
        return false;
    }
    else
    {
        int i=0;
        while(i<l)
        {
            if(t->carr[i] == c[i])
           {
               i++;
           }
           else
            {
                break;
            }
        }
        if (t->carr[i] == c[i] && i==l)
        {
            n=t;
            return true;
        }
        else
        {
            if (c[i] < t->carr[i])
            {
                translate(t->left,c,l,n);
            }

            else
            {
                translate(t->right,c,l,n);
            }
        }
    }
}*/
int main()
{
    //CT ctn;
    //ctn.initialize();
    int l;
    int l1=0;
    int l2=0;
    char c;
    char tmp[21];
    char tmp1[21];
    char tmp2[21];
    int a=0;
//    fstream fin("tulks.in", ios::in);
 //   fstream fout("tulks.out", ios::out);
   // fin.get(c);
   char arrE[5][4]={{"E"},{"E+E"},{"E*E"},{"E-E"},{"I"}};
 char arrI[5][3]={{"I"},{"a"},{"b"},{"aI"},{"Ib"}};

   /* while(fin)
    {
        while(a==0)
        {
            if(c=='<')
            {
                while(c!='\n')
                {
                         fin.get(c);
                }
                fin.get(c);\
                a=1;
            }
            else if(c=='-')
            {
                 while(c!='\n')
                {
                         fin.get(c);
                }
               fin.get(c);
                a=2;
            }
            else
            {
                l1=0;
                while(c!=' ')
                {
                    tmp1[l1]=c;
                    l1++;
                    fin.get(c);
                }
                tmp1[l1]=0;
                fin.get(c);
                l2=0;
                while(c!='\n')
                {
                    tmp2[l2]=c;
                    l2++;
                    fin.get(c);
                }
                tmp2[l2]=0;
                fin.get(c);
            }
            ctn.insert(root1,tmp1,l1, tmp2,l2);
            ctn.insert(root2,tmp2,l2, tmp1,l1);
        }
        if(a==1)
        {
            l=0;
            while(c!=' '&& c!='\n')
            {
                tmp[l]=c;
                l++;
                fin.get(c);
            }
            tmp[l]=0;
           if(ctn.translate(root2,tmp,l,tm2)==true)
            {
                fout<<tm2->arr;

            }
            else
            {
                 fout<<"?"<<tmp;
            }
            fout<<c;
            fin.get(c);
        }
        else
        {
            l=0;
            while(c!=' '&&c!='\n')
            {
                tmp[l]=c;
                l++;
                fin.get(c);
            }
            tmp[l]=0;
            if(ctn.translate(root1,tmp,l,tm1)==true)
            {
                fout<<tm1->arr;
            }
            else
            {
                fout<<"?"<<tmp;
            }
            fout<<c;
            fin.get(c);
        }
    }
    fin.close();
    fout.close();
    */

    return 0;
}
