
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





int main()
{

//fout.open ("out.txt", ios::out);
 //   int keyf[56];
    int keyfsh[56];
    int keyfcomp[48];
    int keyfl[28];
    int keyfr[28];
     int tmpl[28];
    int tmpr[28];
    int keyf[56]={0,1,1,0,1,1,0,0,0,1,1,0,0,0,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,0,1,0,1,1,0,0,0,1,1,0,1,0,0,1,1,1,1,0,0,1};
    int plain[64]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0};
    int mplain[64];
    int rplain[64];
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
    int k;

    int ip[]={58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7};

    int kp[]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
    int bsh[]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

    int cp[]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,31};

    int ep[]={32,1,2,3,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,30,31,32,1};

    int fp[]={40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,343,11,51,19,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25};

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
    for(i=0;i<64;i++)
    {
            //tmp=plain[i];
          //  cout<<i<<"   "<<ip[i]<<endl;
            mplain[i]=plain[ip[i]];
          //  cout<<i<<"   "<<mplain[i]<<endl;
           // plain[ip[i]]=tmp;
    }///

    ///L and R
    for(i=0;i<32;i++)
    {
        ln[i]=mplain[i];
//cout<<"LN="<<ln[i]<<endl;

        rn[i]=mplain[i+32];
        //cout<<"RN="<<rn[i]<<endl;

    }

   ///key permutationS
         for(i=0;i<56;i++)
         {
            keyf[kp[i]];
         }
         ///end of key permutation
    for(i=0;i<28;i++)///slit inyo halves
         {
            keyfl[i]=keyf[kp[i]];///left
            keyfr[i]=keyf[kp[i+28]];///right
         }

    ///function F
   /* for(i=0;i<16;i++)
    {
    ///shift
  shift(keyfl,bsh[i]);
  shift(keyfr,bsh[i]);

         ///key after shift
           for(j=0;j<28;j++)
         {
                keyfsh[j]=keyfl[j];
                keyfsh[j+28]=keyfr[j];
                keyf[j]=keyfl[j];
                keyf[j+28]=keyfr[j];
         }

          ///end of key after shift

         ///compression permutation
         for(j=0;j<48;j++)
         {
          keyfcomp[j]=keyfsh[cp[j]];
         }///end of compression permutation


       for(j=0;j<32;j++)///right and left (n-1)
        {
            ln[j]=mplain[j];
            rn[j]=mplain[j+32];
            ln1[j]=mplain[j+32];
        }

        ///Expantion Permutation
        for(j=0;j<48;j++)
        {
            exp[j]=rn[ep[j]];
         }///end of Expantion Permutation

         /// XOR
        for(j=0;j<48;j++)
        {
            if(((keyfcomp[j]==1) or (exp[j]==1))&& (keyfcomp[j]!= exp[j]))
            {
                exp[j]=1;
            }
            else
            {
                exp[j]=0;
            }
         }
         /// end of XOR

         ///Sbox permutation
         ctmp=0;
        for(j=0;j<48;j=j+6)
        {
            row=exp[j]*2+exp[j+5];
            col=8*exp[j+1]+4*exp[j+2]+2*exp[j+3]+exp[j+4];

            if(j==0)            stmp=sbox1[row][col];
            if(j==6)            stmp=sbox2[row][col];
            if(j==12)             stmp=sbox3[row][col];
            if(j==18)             stmp=sbox4[row][col];
            if(j==24)            stmp= sbox5[row][col];
            if(j==30)            stmp= sbox6[row][col];
            if(j==36)             stmp=sbox7[row][col];
            if(j==42)             stmp=sbox8[row][col];
            for(k=3;k>=0;k++)
            {
                fpbox[ctmp+k]=stmp%2;
               // cout<<rn[ctmp+k]<<endl;
                stmp=stmp/2;
            }
            ctmp=ctmp+4;


        }
         ///End of Sbox permutation

         ///Pbox permutation
            for(j=0;j<32;j++)
            {
            //tmp=plain[i];
            rn[j]=fpbox[pbox[j]];
           // plain[ip[i]]=tmp;
            }///
         ///End ofPbox permutation
         ///XOR start
        /// XOR
        for(j=0;j<32;j++)
        {
            if(((rn[j]==1) or (ln[j]==1))&& (rn[j]!= ln[j]))
            {
                rn1[j]=1;
            }
            else
            {
                rn1[j]=0;
            }
         }
         /// end of XOR
         ///XOR END
         ///salipina kopa
            for(j=0;j<32;j++)///right and left (n-1)
        {
            mplain[j]=ln1[j];
            mplain[j+32]=rn1[j];
           // ln1[j]=mplain[j+32];
        }



    }///function F end
*/
         ///Final permutation
    for(i=0;i<64;i++)
    {
            //tmp=plain[i];
            rplain[i]=mplain[fp[i]];
           cout<<rplain[i]<<endl;
           // plain[fp[i]]=tmp;
    }
  //  for

   // fout.close


    cout << "Hello world!" << endl;
    return 0;
}
