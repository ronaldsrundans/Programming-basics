#include <iostream>
#include <cstring>
using namespace std;

void searchString(char*c,int arr[][4], char arrChar[][6])
{
    int i,j,k,d,m;

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
                cout<<"match"<<endl;
            }
           // cout<<endl;

        }

    }

}

int main()
{

int i,j,k,pos;
int n=0;
char arrChar[3][6]={{"SSAAB"},
                    {"AABa"},
                    {"BBBb"}};
int arrInt[3][4]={{2,1,3,5},{2,1,3,4},{2,1,3,4}};
char c[3]="AB";
//cout<<"c="<<c[0]<<endl;

/*
int arrInt1[4][4];///w11,w22,w33,w44
    for(i=0;i<5;i++)
    {
        arrInt1[i][0]=0;
    }

    char word[5]="abbb";
*/

searchString(c,arrInt,arrChar);

    cout << "Hello world!" << endl;
    return 0;
}
