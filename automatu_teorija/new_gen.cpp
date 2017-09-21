
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
fstream fout;
fout.open("out.txt",ios::out);
    int arr[10]={0,0,0,0,0,0,0,0,0,0};
    int i=0,k=0,m=0,n=0,o=0,p=0,q=0,r=0,s=0,j=0;
    char c1[3]="ab";
    char c2[6]="ab+-*";
    char c[11];
    c[10]=0;
    for(j=0;j<3;j++)///pos 9
    {
        arr[9]=j;
        for(s=0;s<6;s++)///pos 8
        {
            arr[8]=s;
            for(r=0;r<6;r++)///pos 7
            {
                arr[7]=r;
                for(q=0;q<6;q++)///pos 6
                {
                    arr[6]=q;
                    for(p=0;p<6;p++)///pos 5
                    {
                        arr[5]=p;
                        for(o=0;o<6;o++)///pos 4
                        {
                            arr[4]=o;
                            for(n=0;n<6;n++) ///pos 3
                            {
                                arr[3]=n;
                                for(m=0;m<6;m++)                ///pos 2
                                {
                                    arr[2]=m;
                                    for(k=0;k<6;k++)                ///pos 1
                                    {
                                        arr[1]=k;
                                        for(i=0;i<2;i++)///pos 0
                                        {
                                            arr[0]=i;

                                            ///pos 0
                                            c[0]=c1[arr[0]];///te bus tikai "a" vai "b"
                                            ///pos1

                                           // c[1]=c2[arr[1]];
if (arr[2]==5 && arr[1]==5)c[1]=c2[arr[1]];///ja (nak) pos ir"/0" un pats a vai b
else if(arr[2]<2 && arr[1]<5)c[1]=c2[arr[1]];
else continue;
/*
if (arr[2]==5 && arr[1]<2)c[1]=c2[arr[1]];///ja (nak) pos ir"/0" un pats a vai b
else if(arr[2]<2 && arr[1]!=5)c[1]=c2[arr[1]];///ja (nak)pos 2 ir a,b un " un pats nav /0"
else if(arr[1]==5 && arr[2]==5)c[1]=c2[arr[1]];///ja pats un nak  abi ir "/0"
else continue;*/
               //c[1]=c2[arr[1]];
/*
if(arr[1]<5 && arr[2]<2)c[1]=c2[arr[1]];
else if (arr[1]<2 && arr[2]==5)c[1]=c2[arr[1]];
else if(arr[1]==5 && arr[2]==5)c[1]=c2[arr[1]];
else continue;*/


//if(arr[2]<2)c[2]=c2[arr[1]];
//else if(arr[1]<2 or arr[1]==5)c[1]=c2[arr[1]];
//else continue;
              // if()
//if (c[2]==0)cout << "Hello world!" << endl;
                                                ///pos2
/*
if (arr[3]==5 && arr[2]<2)c[2]=c2[arr[2]];///ja (nak) pos ir"/0" un pats a vai b
//else if(arr[3]<2 && arr[1]<2 && arr[2]!=5)c[2]=c2[arr[2]];///ja (nak un iepr)pos (1 un 3) ir a,b un " un pats nav /0"
else if(arr[3]<2 && arr[1]<2 && arr[2]<5)c[2]=c2[arr[2]];
else if(arr[3]==5 && arr[2]==5)c[2]=c2[arr[2]];
else continue;*/
/*
if(arr[2]==5  )c[2]=c2[arr[2]];
else if(arr[2]==5 && arr[3]==5)c[2]=c2[arr[2]];
else continue;*/

/*
if(arr[3]<2)c[2]=c2[arr[2]];
else if(arr[2]<2 or arr[2]==5)c[2]=c2[arr[2]];
else continue;*/
if (arr[3]==5 && arr[2]==5)c[2]=c2[arr[2]];///ja (nak) pos ir"/0" un pats a vai b
else if(arr[3]<2 && arr[2]<5)c[2]=c2[arr[2]];
else continue;

//c[2]=c2[arr[2]];


                                                ///pos3
/*
if (arr[4]==5 && arr[3]<2)c[3]=c2[arr[3]];///ja (nak) pos ir"/0" un pats a vai b
else if(arr[4]<2 && arr[2]<2 && arr[3]!=5)c[3]=c2[arr[3]];///ja (nak un iepr)pos (1 un 3) ir a,b un " un pats nav /0"
//else if(arr[4]<2&&arr[3]!=5)c[3]=c2[arr[3]];
else if(arr[4]==5 && arr[3]==5)c[3]=c2[arr[3]];
else continue;*/
    ///test
   /* arr[4]=5;
             //   c[3]=c2[arr[3]];

if(arr[4]<2)c[3]=c2[arr[3]];
else if(arr[3]<2 or arr[4]==5)c[3]=c2[arr[3]];
else continue;*/
                                            //c[3]=c2[arr[3]];
if (arr[4]==5 && arr[3]==5)c[3]=c2[arr[3]];///ja (nak) pos ir"/0" un pats a vai b
else if(arr[4]<2 && arr[3]<5)c[3]=c2[arr[3]];
else continue;
                                                ///pos4
/*
if (arr[5]==5 && arr[4]<2)c[4]=c2[arr[4]];///ja (nak) pos ir"/0" un pats a vai b
//else if(arr[5]<2 && arr[3]<2&& arr[4]!=5)c[4]=c2[arr[4]];
else if(arr[5]<2 && arr[3]<2 && arr[4]!=5)c[4]=c2[arr[4]];
else if(arr[4]==5 && arr[5]==5)c[4]=c2[arr[4]];
else continue;*/
                                        //c[4]=c2[arr[4]];
            if (arr[5]==5 && arr[4]==5)c[4]=c2[arr[4]];///ja (nak) pos ir"/0" un pats a vai b
else if(arr[5]<2 && arr[4]<5)c[4]=c2[arr[4]];
else continue;

                                                ///pos5
/*
if (arr[6]==5 && arr[5]<2)c[5]=c2[arr[5]];///ja (nak) pos ir"/0" un pats a vai b
else if(arr[6]<2 && arr[4]<2&&  arr[5]!=5)c[5]=c2[arr[5]];
else if(arr[5]==5 && arr[6]==5)c[5]=c2[arr[5]];
else continue;*/
                                            //c[5]=c2[arr[5]];
if (arr[6]==5 && arr[5]==5)c[5]=c2[arr[5]];///ja (nak) pos ir"/0" un pats a vai b
else if(arr[6]<2 && arr[5]<5)c[5]=c2[arr[5]];
else continue;

                                                ///pos6
/*
if ((arr[7]==5 && arr[6]<2)or(arr[6]==5 && arr[7]==5))c[6]=c2[arr[6]];///ja (nak) pos ir"/0" un pats a vai b
else if(arr[7]<2 && arr[5]<2 && arr[6]<5)c[6]=c2[arr[6]];
//else if(arr[6]==5&& arr[7]==5)c[6]=c2[arr[6]];
else continue;*/
if (arr[7]==5 && arr[6]==5)c[6]=c2[arr[6]];///ja (nak) pos ir"/0" un pats a vai b
else if(arr[7]<2 && arr[6]<5)c[6]=c2[arr[6]];
else continue;
                                                //c[6]=c2[arr[6]];

                                                ///pos7
/*
if ((arr[8]==5 && arr[7]==5)or(arr[8]==5 && arr[7]<2))c[7]=c2[arr[7]];///ja (nak) pos ir"/0" un pats a vai b
else if(arr[8]<2 && arr[7]<5)c[7]=c2[arr[7]];
//else if(arr[8]==5 && arr[7]==5)c[7]=c2[arr[7]];
else continue;
*/
if (arr[8]==5 && arr[7]==5)c[7]=c2[arr[7]];///ja (nak) pos ir"/0" un pats a vai b
else if(arr[8]<2 && arr[7]<5)c[7]=c2[arr[7]];
else continue;
                                           // c[7]=c2[arr[7]];
                                            ///pos8



if (arr[9]==5 && arr[8]==5)c[8]=c2[arr[8]];///ja (nak) pos ir"/0" un pats a vai b
else if(arr[9]<2 && arr[8]<5)c[8]=c2[arr[8]];
else continue;
                                      //  c[8]=c2[arr[8]];
                                        ///pos9
                                        c[9]=c1[arr[9]];


                                        fout<<"c="<<endl;
                                        cout<<c<<endl;
                                    }///pos 0
                                }///pos 1
                            }///pos 2
                        }///pos 3
                    }///pos 4
                }///pos 5
            }///pos 6
        }///pos 7
    }///pos 8
}///pos 3
    //if (c[3]==0)cout << "Hello world!" << endl;
    return 0;
}
