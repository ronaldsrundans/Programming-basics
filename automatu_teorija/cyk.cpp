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
    int i,j,k,pos,x,y,tmp;
    int n=0;
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
    char word[5]="aaab";
    char c[2];
//cout<<"c=j=0"<<c[0]<<endl;
    for(j=0;j<4;j++)
    {
        //arrInt1[0]=0;
        c[0]=word[j];
        c[1]=0;
      //  tmp=0;
        searchString2(c,arrInt,arrChar,arrInt1,j);
      //  arrInt1[j]=tmp;


    }
   // cout<<"arr="<<endl;
        //x=4
             for(y=0;y<2;y++)
        {
            arrInt3[y][0]=0;
        }
         for(y=0;y<3;y++)
        {
            arrInt2[y][0]=0;
        }

       for(y=0;y<3;y++)
        {
       //
       i=arrInt1[y][1];
       j=arrInt1[1+y][1];
       cout<<i<<j<<endl;
        c[0]=arrChar[i][0];
            c[1]=arrChar[j][0];
            c[2]=0;
cout<<"c=  "<<c<<endl;
             searchString2(c,arrInt,arrChar,arrInt2,y);
 cout<<"arr=  "<<arrInt2[y][0]<<endl;
        }

        for(k=0;k<2;k++)
        {
       cout<<"arr1="<<arrInt1[k][0]<<endl;//<<"  "<<arrInt2[k][0];endl;
       cout<<"arr2="<<arrInt2[k+1][0]<<endl;
        for(i=1;i<=arrInt1[k][0];i++)
        {
             for(j=1;j<=arrInt2[k+1][0];j++)
                {
                    x=arrInt1[k][i];
                    y=arrInt2[k+1][j];
                  //  cout<<x<<"  "<<y<<endl;
                  c[0]=arrChar[x][0];
                   c[1]=arrChar[y][0];
                     c[2]=0;
                     cout<<c<<endl;
                     searchString2(c,arrInt,arrChar,arrInt3,k);
                   //  cout<<"arr3["<<k<<"][0]="<<arrInt3[0][0]<<endl;
                }
        }
         for(i=1;i<=arrInt2[k][0];i++)
            {
                for(j=1;j<=arrInt1[k+2][0];j++)
                {
                   x=arrInt2[k][i];
                    y=arrInt1[k+2][j];
                       cout<<x<<"  "<<y<<endl;
                    c[0]=arrChar[x][0];
                    c[1]=arrChar[y][0];
                    c[2]=0;
                    cout<<"c3="<<c<<endl;
                    searchString2(c,arrInt,arrChar,arrInt3,k);

                    }

            }

            }///for k

            ///Final
            for(i=0;i<2;i++)
            {

                for(j=1;j<=arrInt3[i][0];j++)
                {
                    //cout<<"arrF["<<i<<"]["<<j<<"]="<<arrInt3[i][j]<<endl;
                    if(arrInt3[i][j]==0)///atrada S
                    {
                    cout<<"Pieder!"<<endl;
                    break;
                    }
                }
            }

    return 0;
}
