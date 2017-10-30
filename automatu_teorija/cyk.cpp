#include <iostream>
#include <cstring>
using namespace std;

void searchString(char *c,int n,int arr[][4], char arrChar[][6])
{
    int i,j,k;

    for(i=0;i<3;i++)///rinda
    {
        for(k=0;k<arr[i][0];k++)///elem-s p.k.
        {
            for(j=arr[i][1+k];j<arr[i][k+2];j++)///elem-sak un beigas
            {
                cout<<arrChar[i][j];
            }
        }
        cout<<endl;
    }

}

int main()
{
int i,j,k, pos;
int n=0;
char arrChar[3][6]={{"SSAAB"},
                    {"AABa"},
                    {"BBBb"}};
int arrInt[3][4]={{2,1,3,5},{2,1,3,4},{2,1,3,4}};
char c[100];
int arrInt1[4][4];///w11,w22,w33,w44
for(i=0;i<5;i++)
{
  arrInt1[i][0]=0;
}

char word[5]="abbb";
c[0]='a';
searchString(c,1,arrInt,arrChar);
/*for(k=0;k<4;k++)
{
word[k];

}


    for(i=0;i<4;i++)
    {
        j=0;
        while(arrChar[i][j]!=0)
        {

            c[0]=arrChar[i][j];
            if(c[0]==word[k])
            {
                pos=arrInt1[k][0]+1;
                n++;
                //cout<<c<<n<<endl;
                arrInt1[k][pos]=i;
                arrInt1[k][0]=pos;
            }
            j++;
        }

    }
}
*/
for(i=0;i<4;i++)
{
    for(j=1;j<=arrInt1[i][0];j++)
    {
       // cout<<arrInt1[i][j]<<endl;
        //cout<<arrChar[arrInt1[i][j]][0]<<endl;
        c[0]=arrChar[arrInt1[i][j]][0];
        c[1]=arrChar[arrInt1[i+1][j]][0];
        cout<<c[0]<<c[1]<<endl;
        ///mekle string AB un BB
//        searchString(c,2,arrInt2);
    }
}
    cout << "Hello world!" << endl;
    return 0;
}
