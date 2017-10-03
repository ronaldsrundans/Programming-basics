

#include <iostream>

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
int main()
{
    int keyf[56];
    int keyfsh[56];
    int keyfcomp[48];
    int keyfl[28];
    int keyfr[28];
     int tmpl[28];
    int tmpr[28];
    int key[64];
    int plain[64];
    int mplain[64];
    int rplain[64];
    int exp[48];
    int rn[32];
    int ln[32];
    int rn1[32];
    int ln1[32];
    int tmp;

    int ip[]={58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7};

    int kp[]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
    int bsh[]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

    int cp[]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,31};

    int ep[]={32,1,2,3,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,30,31,32,1};

    int fp[]={40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,343,11,51,19,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25};

    int sbox1[]={14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,015,7,4,14,2,13,1,10};

    int sbox2[]={15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,3,13,4,7,11};

    int sbox3[]={};

    int sbox4[]={};

    int sbox5[]={};

    int sbox6[]={};

    int sbox7[]={};

    int sbox8[]={};

    int i=0,j=0;
        ///Initial permutation
    for(i=0;i<64;i++)
    {
            //tmp=plain[i];
            mplain[i]=plain[ip[i]];
           // plain[ip[i]]=tmp;
    }

    ///L and R
    for(i=0;i<32;i++)
    {
        ln[i]=mplain[i];

        rn[i]=mplain[i+32];
    }
   ///key
         for(i=0;i<56;i++)
         {
            keyf[kp[i]];
         }
    for(i=0;i<28;i++)
         {
            keyfl[i]=keyf[kp[i]];
            keyfr[i]=keyf[kp[i+28]];
         }

    ///function F
    for(i=0;i<16;i++)
    {
    ///shift
  shift(keyfl,bsh[i]);
  shift(keyfr,bsh[i]);

         ///key after shift
           for(j=0;j<28;j++)
         {
                keyfsh[j]=keyfl[j];
                keyfsh[j+28]=keyfr[j];
         }
          ///end of key after shift

         ///compression permutation
         for(j=0;j<48;j++)
         {
          keyfcomp[j]=keyfsh[cp[j]];
         }///end of compression permutation


       for(j=0;j<32;j++)
        {
            ln[j]=mplain[j];
        }
        for(j=32;j<64;j++)
        {
            rn[j]=mplain[j];
            ln1[j]=mplain[j];
        }

        ///Expantion Permutation
        for(j=0;j<48;j++)
        {
            exp[j]=rn[ep[j]];
         }///end of Expantion Permutation

         /// XOR
        for(j=0;j<48;j++)
        {
         if(keyfcomp[j]xor exp[j])
         {}
         else{}
         }
         /// end of XOR

         ///Sbox permutation

         ///End of Sbox permutation

         ///Pbox permutation
         ///End ofPbox permutation


    }///function F end

         ///Final permutation
    for(i=0;i<64;i++)
    {
            //tmp=plain[i];
            rplain[i]=mplain[fp[i]];
           // plain[fp[i]]=tmp;
    }
    cout << "Hello world!" << endl;
    return 0;
}

