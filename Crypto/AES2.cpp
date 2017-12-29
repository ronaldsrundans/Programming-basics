
#include <iostream>

using namespace std;

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
void bintohex(int *bin,int binsize)//,char* hex)
{
    int n=0;
    int k=1;
    int i;
    char c;
    for(i=binsize-1;i>=0;i--)
    {
        n=n+bin[i]*k;
        k=k*2;
    }
    c=n+'0';
    if(c>'9')
    {
        c=c-'0'-10+'a';
    }
   // cout<<endl;
    cout<<c;


}

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
void printState(int state[][4], int nk)
{
    for(int i=0;i<nk;i++)
{
    int arrt[4];
    for(int j=0;j<8;j++)
    {
         for(int k=0;k<4;k++)
        {
            arrt[k]=state[j*4+k][i];
        }
        bintohex(arrt,4);
    }
}
 cout<<endl;
}
void xorfunc8(int *arr1, int *arr2, int *arr3)
{
    for(int i=0;i<8;i++)
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

void bintodec(int arr[],int j)
{
    int n=0;
    int b=1;
    for(int i=j;i>=0;i--)
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
void subbytes(int sbox[][16], int input[][4])
{
    int x,y,u,v,i,j,k,l;
    int arr1[4];
    int arr2[4];
    for(j=0;j<4;j++)///col
    {
        for(i=0;i<4;i++)///row
        {
        x=0;
        y=0;

         for(k=0;k<4;k++)///x and y
        {
             arr1[k]=input[k+i*8][j];
            // cout<<arr1[k]<<endl;
            arr2[k]=input[k+4+i*8][j];
             //cout<<arr2[k]<<endl;
        }

        bintodec(arr1,3);
        bintodec(arr2,3);
         x=arr1[0];
         y=arr2[0];
         //cout<<"x="<<x<<endl;
        // cout<<"y="<<y<<endl;
          //  int arrt[4];
          //  int arrr[4];
                   //  cout<<"x="<<x<<endl;
       //  cout<<"y="<<y<<endl;
            for(k=0;k<4;k++)///x and y
            {
               // arrt[k]=sbox[y*8+k][x];
              //  arrr[k]=sbox[y*8+k+4][x];


                input[k+i*8][j]=sbox[y*8+k][x];
               input[k+4+i*8][j]=sbox[y*8+k+4][x];
            }
           // bintohex(arrt,4);
           // bintohex(arrr,4);
           // cout<<endl;
        }
    }

}
void printTable(int sbox[][16])
{

for(int j=0;j<16;j++)///col
{
        int arrt[4];
    for(int i=0;i<16;i++)///row
    {
      for(int k=0;k<4;k++)
        {
            arrt[k]=sbox[i*8+k][j];
        }
        bintohex(arrt,4);
        for(int k=4;k<8;k++)
        {
           arrt[k-4] =sbox[i*8+k][j];
        }
       bintohex(arrt,4);
        cout<<" ";
    }
     cout<<endl;
}
 cout<<endl;

}
void shiftrows(int arr[][4])
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
void invshiftrows(int arr[][4])
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
void mult2(int *arr)
{
    if(arr[0]==1)
    {
        for(int i=0;i<7;i++)
        {
            arr[i]=arr[i+1];
        }
        arr[7]=0;
        int arr2[8]={0,0,0,1,1,0,1,1};
        int arr3[8];
        xorfunc8(arr,arr2,arr3);
        for(int i=0;i<8;i++)
        {
            arr[i]=arr3[i];
        }

    }

}
void mixcol(int tableL[][16], int tableE[][16],int input[][4])
{

 int i,j,k,l,x1, y1,x2,y2, x3, y3,x4,y4;

    int arr1[4];
    int arr2[4];
    int arr3[4];
    int arr4[4];
    int arr5[4];
    int arr6[4];
    int arr7[4];
    int arr8[4];
    int m0[4]={0,0,0,0};
    int m2[4]={0,0,1,0};
    int m3[4]={0,0,1,1};

    for(j=0;j<4;j++)///col
    {
         for(k=0;k<4;k++)///all col elements
        {
            arr1[k]=input[k+i*8][j];
            arr2[k]=input[k+4+i*8][j];
            arr3[k]=input[k+8+i*8][j];
            arr4[k]=input[k+12+i*8][j];
            arr5[k]=input[k+16+i*8][j];
            arr6[k]=input[k+20+i*8][j];
            arr7[k]=input[k+24+i*8][j];
            arr8[k]=input[k+28+i*8][j];
             //cout<<arr2[k]<<endl;
        }

        bintodec(arr1,3);
        bintodec(arr2,3);
        bintodec(arr3,3);
        bintodec(arr4,3);
        bintodec(arr5,3);
        bintodec(arr6,3);
        bintodec(arr7,3);
        bintodec(arr8,3);
        x1=arr1[0];
        y1=arr2[0];
        x2=arr3[0];
        y2=arr4[0];
        x3=arr5[0];
        y3=arr6[0];
        x4=arr7[0];
        y4=arr8[0];
         cout<<"x1="<<x1<<endl;
         cout<<"y1="<<y1<<endl;
          //  int arrt[4];
          //  int arrr[4];
                   //  cout<<"x="<<x<<endl;
       //  cout<<"y="<<y<<endl;
           /* for(k=0;k<4;k++)///x and y
            {
                arr1[k]=tableL[y*8+k][x];
                arr2[k]=tableL[y*8+k+4][x];


               // input[k+i*8][j]=sbox[y*8+k][x];
              // input[k+4+i*8][j]=sbox[y*8+k+4][x];
            }
            bintohex(arr1,4);
            bintohex(arr2,4);*/
            cout<<endl;

    }
}
void invmixcol(int arr[][4])
{

}
void rcon(int n, int round, int bit, int *arr)
{

        char c16[]={"01020408102040801b36"};
        char tmp[9];
        int i;
        tmp[0]=c16[n];
        tmp[1]=c16[n+1];
        for(i=2;i<9;i++)
        {
            tmp[i]='0';
        }
        tmp[i]=0;
        cout<<tmp<<endl;
        hextobin(tmp,8,arr);


}
void rotWord(int *arr, int n)
{
    int i,j,k;
    for(i=0;i<n/2;i++)
    {
        for(j=0;j<8;j++)
        {
         k=arr[i*8+j];
       //  cout<<k<<endl;
         arr[i*8+j]=arr[(n-i-1)*8+j];
         arr[(n-i-1)*8+j]=k;
        }
    }
}

void expandkey()//(byte key[4*Nk], word w[Nb*(Nr+1)], Nk)
{
//    rotWord();
//subbytes();
/*

word temp

int i = 0;

while (i < Nk)
{
  w[i] = word(key[4*i], key[4*i+1], key[4*i+2], key[4*i+3]);

    i = i+1;
}


i = Nk

while (i < Nb * (Nr+1)]
{


temp = w[i-1]

if (i mod Nk = 0)
{
    temp = SubWord(RotWord(temp)) xor Rcon[i/Nk]
}


else if (Nk > 6 and i mod Nk = 4)
{
    temp = SubWord(temp)
}


end if

w[i] = w[i-Nk] xor temp

i = i + 1

}

*/


}
void dectobin(int dec,int* bin)
{
    int tmp=dec;
    for(int i=3;i>=0;i--)
    {
        bin[i]=tmp%2;
        tmp=tmp/2;
    }
}
void tableLelem(int *arr11, int *arr12,int *arr21,int *arr22,int tableL[][16],int *r1,int *r2)
{
    int x1,x2,y1,y2;
    int arr1[8];
    int arr2[8];
    bintodec(arr11,3);
    bintodec(arr12,3);
    bintodec(arr21,3);
    bintodec(arr22,3);
    x1=arr11[0];
    y1=arr12[0];
    x2=arr21[0];
    y2=arr22[0];
    cout<<x1<<endl;
    cout<<x2<<endl;
    cout<<y1<<endl;
    cout<<y2<<endl;
   // bintodec(arr1,7);
   // bintodec(arr2,7);
}
void matrix(int state[][4])
{
    int b1[8];
    int b2[8];
    int b3[8];
    int b4[8];
    int b5[8];
    int b6[8];
    int b7[8];
    int b8[8];
    int m2b1[8];
    int m3b2[8];
    int m2b2[8];
    int m3b3[8];
    int m2b3[8];
    int m3b4[8];
    int m3b1[8];
    int m2b4[8];
    int m0[4]={0,0,0,0};
    int m2[4]={0,0,1,0};
    int m3[4]={0,0,1,1};

    for(int j=0;j<4;j++)
    {
        for (int i=0;i<4;i++)
        {
            b1[i]=state[i][j];
            b2[i]=state[i+4][j];
            b3[i]=state[i+8][j];
            b4[i]=state[i+12][j];
            b5[i]=state[i+16][j];
            b6[i]=state[i+20][j];
            b7[i]=state[i+24][j];
            b8[i]=state[i+28][j];
        }
        /*tableLelem(m0,m2,b1,b2);
        m2b1[8];
        tableLelem(m0,m3,b3,b4);
        m3b2[8];
        tableLelem(m0,m2,b3,b4);
        m2b2[8];
        tableLelem(m0,m3,b5,b6);
        m3b3[8];
        tableLelem(m0,m2,b5,b6);
        m2b3[8];
        tableLelem(m0,m3,b7,b8);
        m3b4[8];
        tableLelem(m0,m3,b1,b2);
        m3b1[8];
        tableLelem(m0,m2,b7,b8);
        m2b4[8];*/



    }

}
sumbinabc(int *a,int *b)
{
    int n1=0;
    int n2=0;
    int n3=0;
    int k=1;
    int i;
    char c;
    for(i=7;i>=0;i--)
    {
        n1=n1+a[i]*k;
        n2=n2+b[i]*k;
        k=k*2;
    }
    n3=n1+n2;
    if(n3>255)
    {
        n3=n3-255;
    }
    cout<<n3<<endl;
    //cout<<n2<<endl;

}



int main()
{
//char plain16[33]="3243f6a8885a308d313198a2e0370734";
//char key16 [33]="2b7e151628aed2a6abf7158809cf4f3c";
///00112233445566778899aabbccddeeff
///0001020304060708090a0b0c0d0e0f
char plain16[33]="00112233445566778899aabbccddeeff";
char key16 [33]="000102030405060708090a0b0c0d0e0f";
int i,j,k;
int s=128;///set key size;
int nk=s/32;
char expkey[9][5];
char inputChar [9][5];
for(j=0;j<nk;j++)///key16 un plain16 tiek sakartoti 2d arr
    ///sk ir izvietoti pa kolonnam
{
    for(i=0;i<8;i++)
    {
        expkey[j][i]=key16[i+j*8];
        inputChar [j][i]=plain16[i+j*8];
       cout<<inputChar[j][i];
    }
     expkey[j][i]=0;
     inputChar [j][i]=0;
      cout<<endl;
}

int arrk[128];
int arrp[128];

char sbox16[513]={"637c777bf26b6fc53001672bfed7ab76ca82c97dfa5947f0add4a2af9ca472c0b7fd9326363ff7cc34a5e5f171d8311504c723c31896059a071280e2eb27b27509832c1a1b6e5aa0523bd6b329e32f8453d100ed20fcb15b6acbbe394a4c58cfd0efaafb434d338545f9027f503c9fa851a3408f929d38f5bcb6da2110fff3d2cd0c13ec5f974417c4a77e3d645d197360814fdc222a908846eeb814de5e0bdbe0323a0a4906245cc2d3ac629195e479e7c8376d8dd54ea96c56f4ea657aae08ba78252e1ca6b4c6e8dd741f4bbd8b8a703eb5664803f60e613557b986c11d9ee1f8981169d98e949b1e87e9ce5528df8ca1890dbfe6426841992d0fb054bb16"};
char tableE16[513]={"0103050F113355FF1A2E7296A1F813355FE13848D87395A4F702060A1E2266AAE5345CE43759EB266ABED97090ABE63153F5040C143C44CC4FD168B8D36EB2CD4CD467A9E03B4DD762A6F10818287888839EB9D06BBDDC7F8198B3CE49DB769AB5C457F9103050F00B1D2769BBD661A3FE192B7D8792ADEC2F7193AEE92060A0FB163A4ED26DB7C25DE73256FA153F41C35EE23D47C940C05BED2C749CBFDA759FBAD564ACEF2A7E829DBCDF7A8E89809BB6C158E82365AFEA256FB1C843C554FC1F2163A5F407091B2D7799B0CB46CA45CF4ADE798B8691A8E33E42C651F30E12365AEE297B8D8C8F8A8594A7F20D17394BDD7C8497A2FD1C246CB4C752F601"};
char tableL16[513]={"0000190132021AC64BC71B6833EEDF036404E00E348D81EF4C7108C8F8691CC17DC21DB5F9B9276A4DE4A6729AC90978652F8A05210FE12412F082453593DA8E968FDBBD36D0CE94135CD2F14046833866DDFD30BF068B62B325E298228891107E6E48C3A3B61E423A6B2854FA853DBA2B790A159B9F5ECA4ED4ACE5F373A757AF58A850F4EAD6744FAEE9D5E7E6ADE82CD7757AEB160BF559CB5FB09CA951A07F0CF66F17C449ECD8431F2DA4767BB7CCBB3E5AFB60B1863B52A16CAA55299D97B2879061BEDCFCBC95CFCD373F5BD15339843C41A26D47142A9E5D56F2D3AB441192D923202E89B47CB8267799E3A5674AEDDEC531FE180D638C80C0F77007"};
int tableE2[2048];
int tableL2[2048];
int sbox2[2048];
int tableE[128][16];
int tableL[128][16];
int sbox[128][16];
hextobin(sbox16,512,sbox2);
hextobin(tableE16,512,tableE2);
hextobin(tableL16,512,tableL2);
hextobin(key16,33,arrk);
hextobin(plain16,33,arrp);
 for(int j=0;j<16;j++)
{
    for(int i=0;i<128;i++)
    {
        sbox[i][j]=sbox2[i+j*128];
        tableE[i][j]=tableE2[i+j*128];
        tableL[i][j]=tableL2[i+j*128];
    }
}
    ///sbox izdruka
cout<<"Check sbox:"<<endl;
printTable(sbox);
cout<<"Check TableE:"<<endl;
printTable(tableE);
cout<<"Check TableL:"<<endl;
printTable(tableL);


int plain2d[32][4];
int state[32][4];
int statesub[32][4];
int keyw[32][4];
for(int i=0;i<nk;i++)
{
    for(int j=0;j<32;j++)
    {
        keyw[j][i]=arrk[j+i*32];
    }
}
//int state[32][4];

for(int i=0;i<nk;i++)
{
    for(int j=0;j<32;j++)
    {
        plain2d[j][i]=arrp[j+i*32];
    }
}

///plain izdruka
cout<<"Check plain:"<<endl;

 printState(plain2d,nk);
 ///keyw izdruka
 cout<<"Check keyw:"<<endl;

 printState(keyw,nk);
 ///keyw izdruka



///add (round)keyw(xor)
for(int i=0;i<nk;i++)
{
    for(int j=0;j<32;j++)
    {
        xorfunc(plain2d, keyw,state,32, i);
    }

}

 ///state izdruka
 cout<<"Check state:"<<endl;
printState(state,nk);
 cout<<endl;
 ///keyw izdruka




///round1
for(i=0;i<1;i++)///pedeja round reize nav mix col
{
    ///sub bytes
    subbytes(sbox,state);
     cout<<"Check sub bytes state:"<<endl;
printState(state,nk);
    ///shift rows
    shiftrows(state);
         cout<<"Check shift rows state:"<<endl;
printState(state,nk);
    ///mix col
    mixcol(tableL,tableE,state);
             cout<<"Check mix col state:"<<endl;
printState(state,nk);
    ///add roundkey(xor)
}

///test mix func
//char mix16[65]={"d4bf5d30e0b452aeb84111f11e2798e5"};
char mix16[65]={"2b7e151628aed2a6abf7158809cf4f3c"};
char mix16a[65]={"046681e5e0cb199a48f8d37a2806264c"};
int mix2[256];
hextobin(mix16,65,mix2);
int mix2a[256];
hextobin(mix16a,65,mix2a);
int mix[32][4];
int mixa[32][4];
for(int i=0;i<4;i++)
{
    for(int j=0;j<32;j++)
    {
        mix[j][i]=mix2[j+i*32];
        mixa[j][i]=mix2a[j+i*32];
    }
}



///plain
///key
int arrtest[32];
for(i=0;i<32;i++)
{
    arrtest[i]=i;
   // cout<<i;
}
rotWord(arrtest,4);
rcon(0,2,3,arrtest);
for(i=0;i<32;i++)
{
    cout<<arrtest[i];
   // i;]=i;
}

cout<<endl;
int a[4]={0,0,0,0};
int c[4]={0,1,1,1};
int b[4]={1,1,1,1};
int d[4]={1,1,1,1};
cout<<"sum"<<endl;
int arra[8]={0,0,0,0,0,1,1,1};
int arrb[8]={1,1,1,1,1,1,1,1};
//tableLelem(a,b,c,d,tableL,a,c);
sumbinabc(arra,arrb);


  /// cout << 16*8<< endl;
    return 0;
}

