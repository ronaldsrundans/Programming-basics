
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void shift(int* arr,int n)
{
    int tmp1,tmp2,tmp3;
    tmp1=arr[0];
    tmp2=arr[1];
    tmp3=arr[27];
    for(int k=0;k<26;k++)
    {
        arr[k]=arr[k+n];
    }
    if(n==2)
    {
        arr[26]=tmp1;
        arr[27]=tmp2;
    }
    else
    {
          arr[27]=tmp1;
        arr[26]=tmp3;
    }
}
void xorfunc(int *arr1, int *arr2, int* arr3, int n)
{
    for(int i=0;i<n;i++)
        {
            if(((arr1[i]==1) or (arr2[i]==1))&& (arr1[i]!= arr2[i]))
            {
                arr3[i]=1;
            }
            else
            {
                arr3[i]=0;
            }
         }
}

void permutation(int n, int* arr1, int *arr2, int *arrp)
{
    int tmp;
    for(int i=0;i<n;i++)
    {

            arr2[i]=arr1[arrp[i]-1];
    }
}
void dectobin(int dec,int* bin)
{
    int tmp=dec;
    //cout<<"tmp="<<tmp<<endl;
    for(int i=3;i>=0;i--)
    {
        bin[i]=tmp%2;
        tmp=tmp/2;
    }
}
void split(int *arr, int* arr1, int *arr2, int n)
{
    for(int i=0;i<n;i++)
    {
        arr1[i]=arr[i];
        arr2[i]=arr[i+n];
    }
}




int main()
{
    fstream fout;
    fout.open ("out.txt", ios::out);
    int keyfsh[56];
    //int keyfcomp[48];
    int kpkeyl[28];
    int kpkeyr[28];
    int kpkey[56];
    int fkey[56];
    int cpkey[48];
    int rnexp[48];
    int bintmp[4];
    int sbox[32];
    int xbox[32];
   // int tmpl[28];
   // int tmpr[28];
    int key[64]={1,1,1,0,0,1,0,1,0,1,1,1,0,1,1,0,0,0,1,1,0,0,0,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,0,1,0,1,1,0,0,0,1,1,0,1,0,1,1,1,1,0,0,1};
    int plain[64]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0};
    int ipplain[64];
    int cypher[64];
    int exp[48];
    int rn[32];
    int ln[32];
    int rn1[32];
    int ln1[32];
    int fpbox[32];
    int tmp;
    int row;
    int col;
    int stmp;
    int ctmp;
    //int k;
    /*int bina[4];
    dectobin(14,bina);
    for(int y=0;y<4;y++)
    {
        cout<<"bina="<<bina[y]<<endl;
    }*/

    int ip[]={58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7};

/*for(int y=1;y<65;y++)
 {
     plain[y-1]=y;
    // cout<<"test1["<<y<<"]="<< test1[y-1]<<endl;
 }
int test1[64];
 int test2[64];


 permutation(64,test1,test2,ip);

  for(int y=0;y<64;y++)
 {
     cout<<test2[y]<<endl;
 }*/

    int kp[]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
    int bsh[]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

    int cp[]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,31};

    int ep[]={32,1,2,3,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,30,31,32,1};

    int fp[]={40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,
             38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,
             36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,
             34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25};

    int sbox1[4][16]={{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
                        {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
                        {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
                        {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}};

    int sbox2[4][16]={{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
                   { 3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
                    {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
                    {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}};

    int sbox3[4][16]={{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
                    {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
                    {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
                    {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}};

    int sbox4[4][16]={{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
                {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
                {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
                {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}};

    int sbox5[4][16]={{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
                    {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
                    {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
                    {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}};

    int sbox6[4][16]={{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
                    {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
                    {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
                    {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}};

    int sbox7[4][16]={{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
                    {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
                    {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
                    {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}};

    int sbox8[4][16]={{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
                    {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
                    {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
                    {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}};
    int pbox[32]={16,7,20,21,29,12, 28, 17, 1, 15, 23, 26 ,5 ,18 ,31 ,10, 2 ,8 ,24 ,14 ,32 ,27, 3, 9,19,13,30,6,22,11,4,25};

    int i=0,j=0;
        ///Initial permutation
    permutation(64, plain, ipplain, ip);
    /*  for(int y=0;y<64;y++)
 {
     cout<<"ipplain="<<ipplain[y]<<endl;
 }*/

    /*for(i=0;i<64;i++)
    {
            //tmp=plain[i];
          //  cout<<i<<"   "<<ip[i]<<endl;
            mplain[i]=plain[ip[i]];
          //  cout<<i<<"   "<<mplain[i]<<endl;
           // plain[ip[i]]=tmp;
    }/*/

 /////split into L and R
//split(ipplain,ln,rn,32);

   /*   for(int y=0;y<32;y++)
    {
        cout<<"ln="<<ln[y]<<endl;
        cout<<"rn="<<rn[y]<<endl;
    }
         ln[i]=mplain[i];
//cout<<"LN="<<ln[i]<<endl;

        rn[i]=mplain[i+32];
        //cout<<"RN="<<rn[i]<<endl;

    }
*/
   ///key permutationS
//   key[0]<<endl;
    permutation(56, key, kpkey, kp);

    ///split key

    split(kpkey,kpkeyl,kpkeyr,28);

      /*for(int y=0;y<56;y++)
    {
//cout<<"kpkeyl="<<kpkeyl[y]<<endl;
//cout<<"kpkeyr="<<kpkeyr[y]<<endl;
cout<<"kpkey="<<kpkey[y]<<endl;
    }

   for(i=0;i<56;i++)
         {
            cout<<"key="<<kpkey[i]<<endl;
         }
 */

/*for(int y=1;y<29;y++)
    {
       kpkeyl[y-1]=y;
       kpkeyr[y-1]=y+28;
    }*/



    ///function F
     for(i=0;i<16;i++)
    {
       // fout<<"funcF="<<i+1<<endl;
         ///split into L and R
        split(ipplain,ln,rn,32);
        for(j=0;j<32;j++)
        {
            ln1[j]=rn[j];
        }

        //cout<<kpkeyl[27]<<endl;
        ///bit shift
        shift(kpkeyl,bsh[i]);
        shift(kpkeyr,bsh[i]);
        for(j=0;j<28;j++)
        {
             //fout<<"kpkeyr="<<kpkeyr[y]<<endl;
            fkey[j]=kpkeyl[j];
            fkey[j+28]=kpkeyr[j];
        }
///fkey compression permutation
 permutation(48, fkey, cpkey, cp);

///Expantion Permutation
 permutation(48, rn, rnexp, cp);
 /// XOR (RNEXP,CPKEY)
 xorfunc(rnexp,cpkey,exp,48);
     ///Sbox substitution
         ctmp=0;
        for(j=0;j<48;j=j+6)
        {
            row=exp[j]*2+exp[j+5];
            col=8*exp[j+1]+4*exp[j+2]+2*exp[j+3]+exp[j+4];
            stmp=0;
            if(j==0)stmp=sbox1[row][col];
            else if(j==6)stmp=sbox2[row][col];
            else if(j==12)stmp=sbox3[row][col];
            else if(j==18)stmp=sbox4[row][col];
           else  if(j==24)stmp= sbox5[row][col];
            else if(j==30)stmp= sbox6[row][col];
            else if(j==36)stmp=sbox7[row][col];
           else  if(j==42)stmp=sbox8[row][col];
            fout<<"round="<<i;//<<" dec="<<stmp;
            dectobin(stmp,bintmp);
            fout<<"  bin=";
            for(int k=0;k<4;k++)
            {
                fout<<bintmp[k];
            }
fout<<endl;
            for(int k=0;k<4;k++)
            {

                sbox[ctmp+k]=bintmp[k];
                fout<<"n="<<ctmp+k<<"  sbox="<< sbox[ctmp+k]<<endl;
            }
            fout<<endl;
            ctmp=ctmp+4;
        }///Sbox substitution END
        fout<<"sbox=";
         for(int k=0;k<32;k++)
            {
                fout<<sbox[k];
            }
            fout<<endl;
    ///Pbox permutation
permutation(32, sbox, xbox, pbox);
 fout<<"xbox=";
 for(int k=0;k<32;k++)
            {
                fout<<xbox[k];
            }
            fout<<endl;
/// XOR(xbox,ln)
fout<<"ln=";
for(int k=0;k<32;k++)
            {
                fout<<ln[k];
            }
            fout<<endl;
xorfunc(xbox,ln,rn1,32);
fout<<"rn1=";
for(int k=0;k<32;k++)
            {
                fout<<rn1[k];
            }
            fout<<endl;
///new ipplain
 for(j=0;j<32;j++)
        {
         ipplain[j]=ln1[j];
            ipplain[j+32]=rn1[j];
        }
    }///function F end

         ///Final permutation
permutation(64, ipplain,cypher , fp);
for(i=0;i<64;i++)
    {
        fout<<cypher[i]<<endl;

    }




    fout.close();


    cout << "Hello world!" << endl;
    return 0;
}
