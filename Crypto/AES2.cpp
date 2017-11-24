
#include <iostream>

using namespace std;

void xorfunc(int arr1[][4], int arr2[][4], int arr3[][4], int n, int col)
{
    for(int i=0;i<n;i++)
        {
            if(((arr1[i][col]==1) or (arr2[i][col]==1))&& (arr1[i][col]!= arr2[i][col]))
            {
                arr3[i][col]=1;
            }
            else
            {
                arr3[i][col]=0;
            }
         }
}
void bintodec(int *arr)
{
    int n=0;
    int b=1;
    for(int i=3;i>=0;i++)
    {
        n=n+b*arr[i];
        b=b*2;
        arr[i]=0;
    }
    arr[0]=n;
}
void dectobin(int *arr)
{
    int n=0;
    int b=1;
    for(int i=3;i>=0;i++)
    {
        n=n+b*arr[i];
        b=b*2;
        arr[i]=0;
    }
    arr[0]=n;
}
void addroundkey()
{}
void subbytes(int sbox[][128], int input[][128],int output[][128])
{
    int x,y,u,v,i,j;
//    bintodec();
    for(i=0;i<16;i++)
    {
        for(j=0;j<128;j++)
        {
//            output[][]=sbox[x][y];
        }

    }

}
void invshiftrows(int arr[][4])
{
    int tmp[48];
    int i,j;
    for(i=0;i<8;i++)///row1 copy
    {
        tmp[i]=arr[i+8][0];
    }

    for(j=0;j<3;j++)///row1 shift
    {
        for(i=0;i<8;i++)
        {
            arr[i+8][j]=arr[i+8][j+1];
        }
    }
    for(i=0;i<8;i++)///row1 paste
    {
        arr[i+8][3]=tmp[i];
    }

    for(j=0;j<2;j++)///row2 copy
    {
        for(i=0;i<8;i++)
        {
            tmp[i+j*8+8]=arr[i+16][j];
        }
    }
    for(j=0;j<2;j++)///row2 shift
    {
        for(i=0;i<8;i++)
        {
            arr[i+16][j]=arr[i+16][j+2];
        }
    }
    for(j=2;j<4;j++)///row2 paste
    {
        for(i=0;i<8;i++)
        {
            arr[i+16][j]=tmp[i+j*8-8];
        }
    }
    for(j=0;j<3;j++)///row 3 copy
    {
        for(i=0;i<8;i++)
        {
            tmp[i+24+8*j]=arr[i+24][j];
        }
    }
    ///row 3 shift

        for(i=0;i<8;i++)
        {
            arr[i+24][0]=arr[i+24][3];
        }

    for(j=1;j<4;j++)///row 3 paste
    {
        for(i=0;i<8;i++)
        {
            arr[i+24][j]=tmp[i+16+j*8];
        }
    }
}
void shiftrows(int arr[][4])
{
    int tmp[48];
    int i,j;
    for(i=0;i<8;i++)///row1 copy
    {
        tmp[i]=arr[i+8][3];
    }

    for(j=3;j>0;j--)///row1 shift
    {
        for(i=0;i<8;i++)
        {
            arr[i+8][j]=arr[i+8][j-1];
        }
    }
    for(i=0;i<8;i++)///row1 paste
    {
        arr[i+8][0]=tmp[i];
    }

    for(j=2;j<4;j++)///row2 copy
    {
        for(i=0;i<8;i++)
        {
            tmp[i+j*8-8]=arr[i+16][j];
        }
    }
     for(j=3;j>1;j--)///row2 shift
    {
        for(i=0;i<8;i++)
        {
            arr[i+16][j]=arr[i+16][j-2];
        }
    }
     for(j=0;j<2;j++)///row2 paste
    {
        for(i=0;i<8;i++)
        {
            arr[i+16][j]=tmp[i+j*8+8];
        }
    }
    for(j=1;j<4;j++)///row 3 copy
    {
        for(i=0;i<8;i++)
        {
            tmp[i+16+8*j]=arr[i+24][j];
        }
    }
    ///row 3 shift

        for(i=0;i<8;i++)
        {
            arr[i+24][3]=arr[i+24][0];
        }

    for(j=0;j<3;j++)///row 3 paste
    {
        for(i=0;i<8;i++)
        {
            arr[i+24][j]=tmp[i+24+j*8];
        }
    }
}
void mixcol()
{

}
void expandkey()
{}
void dectobin(int dec,int* bin)
{
    int tmp=dec;
    for(int i=3;i>=0;i--)
    {
        bin[i]=tmp%2;
        tmp=tmp/2;
    }
}
void hextobin(char* hex,int hexcount, int *arr)
{
    int n;
    int k;
    int i;

    for(k=0;k<hexcount;k++)
    {
    //cout<<hex[k]<<endl;
    n=(int)hex[k];
    //cout<<n<<endl;
    if(n>='a')
    {
        n=n-'a'+10;
    }
        else
        {
            n=n-'0';
        }
//cout<<n<<endl;
        for(i=3;i>=0;i--)
        {
            arr[i+k*4]=n%2;
            n=n/2;
        }
    }
}

int main()
{
char plain16[33]="3243f6a8885a308d313198a2e0370734";
char key16 [33]="2b7e151628aed2a6abf7158809cf4f3c";
int i,j,k;
char expkey[9][5];
for(j=0;j<4;j++)
{
    for(i=0;i<8;i++)
    {
        expkey[j][i]=key16[i+j*8];
       cout<<expkey[j][i];
    }
     expkey[j][i]=0;
      cout<<endl;
}

int w0[32];
int w1[32];
int w2[32];
int w3[32];
int w4[32];
int w5[32];
int w6[32];
int w7[32];
int arr[128];
int arrp[128];

char sbox16[513]={"637c777bf26b6fc53001672bfed7ab76ca82c97dfa5947f0add4a2af9ca472c0b7fd9326363ff7cc34a5e5f171d8311504c723c31896059a071280e2eb27b27509832c1a1b6e5aa0523bd6b329e32f8453d100ed20fcb15b6acbbe394a4c58cfd0efaafb434d338545f9027f503c9fa851a3408f929d38f5bcb6da2110fff3d2cd0c13ec5f974417c4a77e3d645d197360814fdc222a908846eeb814de5e0bdbe0323a0a4906245cc2d3ac629195e479e7c8376d8dd54ea96c56f4ea657aae08ba78252e1ca6b4c6e8dd741f4bbd8b8a703eb5664803f60e613557b986c11d9ee1f8981169d98e949b1e87e9ce5528df8ca1890dbfe6426841992d0fb054bb16"};
int sbox2[4096];
int sbox[16][128];
hextobin(sbox16,513,sbox2);
hextobin(key16,33,arr);
hextobin(plain16,33,arrp);
for(int i=0;i<16;i++)
{
    for(int j=0;j<128;j++)
    {
        sbox[i][j]=sbox2[i*128+j];
    }
}
int input[32][4];
int roundinput[32][4];
int roundkey[32][4];
for(int i=0;i<4;i++)
{
    for(int j=0;j<32;j++)
    {
        roundkey[j][i]=arr[j+i*32];
    }
}

for(int i=0;i<4;i++)
{
    for(int j=0;j<32;j++)
    {
        input[j][i]=arrp[j+i*32];
    }
}
for(int i=0;i<4;i++)
{
    for(int j=0;j<32;j++)
    {
        xorfunc(input, roundkey,roundinput,32, i);
    }
    cout<<endl;
}
///plain
///key

    cout << 16*8<< endl;
    return 0;
}
