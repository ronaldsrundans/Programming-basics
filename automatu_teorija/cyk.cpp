
#include <iostream>
#include <cstring>
using namespace std;

void searchString2(char*c,int arr[][20], char arrChar[][100],int **arrP, int n)
{
    int i,j,k,d,m,pos;
    for(i=0;i<3;i++)///rinda
    {
        for(k=0;k<arr[i][0];k++)///elem-s p.k.
        {
            d=arr[i][k+2]-arr[i][1+k];
            m=0;
            for(j=arr[i][1+k];j<arr[i][k+2];j++)///elem-sak un beigas
            {
                if(c[m]==arrChar[i][j])
                {
                    m++;
                }
                else break;
            }
            if(d==m)
            {
                pos=arrP[n][0]+1;
                arrP[n][pos]=i;
               arrP[n][0]=pos;
            }
        }
    }
}
int main()
{
    int i,j,k,l,pos,x,y,x1,y1,r,tmp;
    int n=0;
    int m=0;
    int **marr;
    int *d;
   // char word[30]="ababa";

char word[30]="abbabbabbacabbaaaaabbaac";
///char word[30]="acaaaaaabbaaaaaaaaaaaaaaaaaa";
///char word[30]="abbabbabbbbabbabbaaaaabb";


    char c[2];
    int arrInt2[3][5];
    int arrInt3[2][5];
    int arrInftF[1][5];
/*
    char arrChar[3][6]={{"SSAAB"},
                    {"AABa"},
                    {"BBBb"}};
    int arrInt[3][4]={{2,1,3,5},
                {2,1,3,4},
                {2,1,3,4}};
                */
char arrChar[6][100]={{"SaEabbaECCaaabbaCbbSbbFEAaAAcaEabCSCEaCDaaabCaCDa"},
                    {"AbbbaaAbCaabCEaabbS"},
                    {"CaEabCaabC"},
                    {"DabaEbbcbabb"},
                    {"EEaabbSaCSFEaaAaAAcaEabCSCEaCDa"},
                    {"FAaAAcFEaEabCSCEaCDaaabCaCDa"}
                };
                int arrInt[6][20]={{14,1,6,9,11,15,17,19,22,24,29,34,36,41,45,49},
                                    {12,1,4,9,13,16,19,22,24,26,31,36,38,43},
                                   {4,1,3,6,11,15},
                                   {4,1,3,7,9,12},
                                   {11,1,4,7,10,12,14,19,24,26,30,34,38},
                                   {7,1,6,8,13,15,20,24,28},
                                    };
    n=0;
    while(word[n]!=0)
    {
        n++;
    }
    tmp=0;
    for(i=1;i<=n;i++)///sola garums
    {
        m=m+i;
    }
    cout<<"m="<<m<<endl;
    cout<<"n="<<n<<endl;
    marr=new int* [m];
    d=new int[n];///diff
    d[0]=0;
    l=n;
    for(i=1;i<n;i++)///set diff arr
    {
        d[i]=d[i-1]+l;
        l=l-1;
    }
    for(i=0;i<m;i++)
    {
       marr[i]=new int [10000];
       marr[i][0]=0;
    }
    for(j=0;j<n;j++)
    {
        c[0]=word[j];
        c[1]=0;
        searchString2(c,arrInt,arrChar,marr,j);
    }
    for(i=2;i<=n;i++)///sola garums
    {
        for(j=1;j<=n-i+1;j++)///start of span
        {
            for(k=1;k<=i-1;k++)///partition of span
            {
                x1=marr[d[k-1]+j-1][0];///elementu sk rinda
                y1=marr[d[i-k-1]+j+k-1][0];
                r=d[i-1]+j-1;
                for(x=1;x<=x1;x++)
                {
                    for(y=1;y<=y1;y++)
                    {
                        c[0]=arrChar[marr[d[k-1]+j-1][x]][0];
                        c[1]=arrChar[marr[d[i-k-1]+j+k-1][y]][0];
                        c[2]=0;
                        searchString2(c,arrInt,arrChar,marr,r);
                    }
                }
            }
        }
    }
    j=marr[m-1][0];
    for(i=1;i<=j;i++)
    {
        if(marr[m-1][i]==0)
        {
            cout<<"pieder!"<<endl;
            break;
        }
    }

for (i=0; i<m; i++) delete[] marr[i];
 delete[] marr;

    return 0;
}

