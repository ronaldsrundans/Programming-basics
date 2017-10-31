#include <iostream>
#include <cstring>
using namespace std;

void searchString(char*c,int arr[][4], char arrChar[][6],int *arrP)
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
                pos=arrP[0]+1;
               // cout<<"pos="<<pos<<endl;
                cout<<"match="<<c<<i<<endl;
                arrP[pos]=i;
               arrP[0]=pos;
            }
           // cout<<endl;
        }
    }
}

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
    int i,j,k,pos,x,y,tmp;
    int n=0;
    int arrInt1[5];///rinda norada burtu no abbb
    arrInt1[0]=0;
    int arrInt2[3][5];
    char arrChar[3][6]={{"SSAAB"},
                    {"AABa"},
                    {"BBBb"}};
    int arrInt[3][4]={{2,1,3,5},
                {2,1,3,4},
                {2,1,3,4}};
    char word[5]="abbb";
    char c[2];
//cout<<"c=j=0"<<c[0]<<endl;
    for(j=0;j<4;j++)
    {
        //arrInt1[0]=0;
        c[0]=word[j];
        c[1]=0;
      //  tmp=0;
        searchString(c,arrInt,arrChar,arrInt1);
      //  arrInt1[j]=tmp;


    }
    cout<<"arr="<<endl;
        //x=4
         for(y=0;y<3;y++)
        {
            arrInt2[y][0]=0;
        }
        for(y=1;y<4;y++)
        {
            cout<<arrInt1[y]<<arrInt1[y+1]<<endl;
            c[0]=arrChar[arrInt1[y]][0];
            c[1]=arrChar[arrInt1[y+1]][0];
            c[2]=0;
            cout<<c<<endl;
             searchString2(c,arrInt,arrChar,arrInt2,y-1);
        }
    return 0;
}
