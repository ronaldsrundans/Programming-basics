
#include <iostream>
#include <cstring>
using namespace std;


void searchString2(char*c,int arr[][4], char arrChar[][6],int **arrP, int n)
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
                cout<<"match[n]="<<c<<endl;
                //<<n<<"i="<<i<<endl;
                arrP[n][pos]=i;
               arrP[n][0]=pos;
            }
           // cout<<endl;
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
    char word[5]="aaab";
    char c[2];
    int arrInt1[4][30];///rinda norada burtu no abbb
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

    n=4;
    tmp=0;


    //
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
   // cout<<"d[i]="<<d[i]<<endl;
    l=l-1;
}


 for(i=0;i<m;i++)
    {
       marr[i]=new int [30];
       marr[i][0]=0;
    }

   // cout<<"test1="<<marr[2][0]<<endl;
     for(j=0;j<n;j++)
    {
        c[0]=word[j];
        c[1]=0;
        searchString2(c,arrInt,arrChar,marr,j);
        // cout<<marr[j][0]<<endl;
        //cout<<arrChar[marr[j][1]][0]<<endl;

    }


    for(i=2;i<=n;i++)///sola garums
    {
       // cout<<"i="<<i<<endl;
        for(j=1;j<=n-i+1;j++)///start of span
        {
            // cout<<"j="<<j<<endl;
            for(k=1;k<=i-1;k++)///partition of span
            {

                 // cout<<"c1 rinda=";
                // cout<<"["<<d[k-1]<<"]+ ["<<j-1<<"] ="<<d[k-1]+j-1<<endl;
               //  cout<<"c1 el sk="<<marr[d[k-1]+j-1][0]<<endl;
                    x1=marr[d[k-1]+j-1][0];///elementu sk rinda
                    y1=marr[d[i-k-1]+j+k-1][0];
                    r=d[i-1]+j-1;
                //    cout<<"c2 rinda=";

                // cout<<"["<<d[i-k-1]<<"]+ ["<<j+k-1<<"] ="<<d[i-k-1]+j+k-1<<endl;
              //   cout<<"c2 el sk="<<marr[d[i-k-1]+j+k-1][0]<<endl;
                // cout<<"rez rinda="<<d[i-1]+j-1<<endl;
                 if(marr[d[i-k-1]+j+k-1][0]==0 ||  marr[d[k-1]+j-1][0]==0)continue;
                 else
                 {
                     for(x=1;x<=x1;x++)
                     {
                         for(y=1;y<=y1;y++)
                         {

                            c[0]=arrChar[marr[d[k-1]+j-1][x]][0];
                            c[1]=arrChar[marr[d[i-k-1]+j+k-1][y]][0];
                            c[2]=0;
                            cout<<c<<endl;
                            searchString2(c,arrInt,arrChar,marr,r);

                         }
                     }

                 }
               /* tmp++;
                cout<<"tmp="<<tmp<<endl;
                // cout<<"k="<<k<<endl;
                 cout<<"ijk  "<<i<<" "<<j<<" "<<k<<endl;
                 ///insert for for

                    cout<<"c1=";
                 cout<<"["<<k<<"] ["<<j<<"]"<<endl;
                    cout<<"c2=";
                 cout<<"["<<i-k<<"] ["<<j+k<<"]"<<endl;
                 */

///missing for for

  /*  for(x=d[k-1]+j-1;x<marr[d[k-1]+j-1][0];x++)///rinda
    {
        for(y=1;y<=marr[x][0];y++)///colonna
        {
                    cout<<"x y"<<x<<"  "<<y<<"=>"<<arrChar[marr[x][y]][0]<<endl;
        }

    }

                cout<<d[k-1]+j-1<<"   "<<d[i-k-1]+j+k-1<<endl;
                 cout<<arrChar[d[k-1]+j-1][0]<<"  "<<arrChar[d[i-k-1]+j+k-1][0]<<endl;
                  c[0]=arrChar[d[k-1]+j-1][0];
                  c[1]=arrChar[d[i-k-1]+j+k-1][0];
                  c[2]=0;
                  cout<<c<<endl;
                  searchString2(c,arrInt,arrChar,marr,d[i-1]+j-1);
                //arrChar[d[k-1]+j-1][0]][0];
               // cout<<c[0]<<endl;
                 cout<<endl;
                 cout<<marr[d[i-1]+j-1][0];
                 break;*/
                   //
                   // c[1]=arrChar[d[i-k-1]+j+k-1][0];


               /*  for()
                 {
                     for()
                     {

                            c[2]=0;
                        cout<<c<<endl;
//cout<<"rez rinda="<<<<endl;
                        searchString2(c,arrInt,arrChar,marr,d[i-1]+j-1);
                     }
                 }*/


                 ///fix search bigger arr
                //


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
    cout<<"end="<<endl;
j=marr[9][0];
for(i=0;i<j;i++)
{
    cout<<marr[9][i]<<endl;
    if(marr[9][i]==0)
    {
        cout<<"pieder!"<<endl;
        break;
    }
}



for (i=0; i<m; i++) delete[] marr[i];
 delete[] marr;

    return 0;
}

