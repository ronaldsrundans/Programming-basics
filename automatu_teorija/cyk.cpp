
#include <iostream>
#include <cstring>
using namespace std;


void searchString2(char*c,int arr[][4], char arrChar[][6],int arrP[][5], int n)
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

//cout<<"c="<<c[m]<<endl;
                //cout<<arrChar[i][j];
                if(c[m]==arrChar[i][j])
                {
                    m++;
                   // continue;
                }
                else break;
            }
          //  cout<<d<<"m="<<m<<endl;
            if(d==m)
            {
                //arrP[n]=i;
                pos=arrP[n][0]+1;
               // cout<<"pos="<<pos<<endl;
                cout<<"match[n]="<<n<<"i="<<i<<endl;
                arrP[n][pos]=i;
               arrP[n][0]=pos;
            }
           // cout<<endl;
        }
    }
}
int main()
{
    int i,j,k,l,pos,x,y,tmp;
    int n=0;
    int m=0;
    int **marr;
    char word[5]="aaab";
    char c[2];
    int arrInt1[4][5];///rinda norada burtu no abbb
    for(y=0;y<4;y++)
    {
        arrInt1[y][0]=0;
    }
    int arrInt2[3][5];
    int arrInt3[2][5];
    int arrInftF[1][5];

    char arrChar[3][6]={{"SSAAB"},
                    {"AABa"},
                    {"BBBb"}};
    int arrInt[3][4]={{2,1,3,5},
                {2,1,3,4},
                {2,1,3,4}};

//cout<<"c=j=0"<<c[0]<<endl;
    for(j=0;j<4;j++)
    {
        c[0]=word[j];
        c[1]=0;
        searchString2(c,arrInt,arrChar,arrInt1,j);
        //cout<<arrChar[arrInt1[j][1]][0]<<endl;
    }
    n=4;
    //
    for(i=1;i<n;i++)///sola garums
    {
        m=m+i;
    }
    cout<<"m="<<m<<endl;
    cout<<"n="<<n<<endl;
marr=new int* [m];
 for(i=0;i<m;i++)///sola garums
    {
       marr[i]=new int [n];
    }
    for(i=2;i<=n;i++)///sola garums
    {
       // cout<<"i="<<i<<endl;
        for(j=1;j<=n-i+1;j++)///start of span
        {
            // cout<<"j="<<j<<endl;
            for(k=1;k<=i-1;k++)///partition of span
            {
                // cout<<"k="<<k<<endl;
                 //cout<<"ijk  "<<i<<" "<<j<<" "<<k<<endl;
                 ///insert for for
                 cout<<"["<<k<<"] ["<<j<<"] "<<endl;

                 cout<<"["<<i-k<<"] ["<<j+k<<"] "<<endl;
                 ///fix search bigger arr
                 cout<<endl;
  //cout<<"start="<<j<<"  l="<<i<<endl;


        /*
cout<<"l-p="<<i-k<<"  s+p="<<j+k<<endl;

               //cout<<"l-p="<<i-k<< cout<<"s+p="<<j+k<<endl;

               //cout<<"s="<<j<<"  "<<arrChar[j][0]<<arrChar[j+k+1][0]<<endl;


                c[0]=0;///arrChar[i][0];
                c[1]=0;
                 c[2]=0;
             //  searchString2(c,arrInt,arrChar,arrInt1,j);
               for(y=0;y<3;y++)///izvedumi
                {

                }*/
            }
        }

    }
for (int i=0; i<m; i++) delete[] marr[i];
 delete[] marr;

    return 0;
}

