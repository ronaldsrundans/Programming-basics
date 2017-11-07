
#include <iostream>
#include <cstring>
using namespace std;

void Print(int n, int **arr)///funkcija izmet atkartojumus
{
   // cout<<arr[n][0]<<endl;
   int tmp[100000];
    int j=arr[n][0];
    int i,k, pos;
    tmp[0]=0;
    for(i=j;i>0;i--)
    {
        pos=tmp[0]+1;
        if(arr[n][i]>-1)
        {
            tmp[pos]=arr[n][i];
            for(k=j;k>0;k--)
            {
                if(arr[n][k]==tmp[pos])arr[n][k]=-1;

            }
            tmp[0]=pos;
        }
        else continue;
    }
    for(i=tmp[0];i>-1;i--)///
    {
        arr[n][i]=tmp[i];
    }
}
void searchString2(char*c,int arr[][20], char arrChar[][100],int **arrP, int n)
{///funkcija salidzina ar gramatiku
    int i,j,k,d,m,pos;
    for(i=0;i<28;i++)///rinda
    {
        for(k=0;k<arr[i][0];k++)///elem-s p.k.
        {
            //cout<<"Match="<<c<<endl;
            d=arr[i][k+2]-arr[i][1+k];
            m=0;
            for(j=arr[i][1+k];j<arr[i][k+2];j++)///elem-sak un beigas
            {
                if(c[m]==arrChar[i][j])
                {
                    m++;
                }
                else break;
            }
            if(d==m)///atrada
            {

                pos=arrP[n][0]+1;
                arrP[n][pos]=i;///ieraksta vieta
               arrP[n][0]=pos;
            }
        }
    }
}
int main()
{
    int i,j,k,l,x,y,x1,y1,r;
    int n=0;
    int m=0;
    int **marr;
    int *d;
   /// char word[1000]="bbaa";
char word[30]="abbabbabbacabbaaaaabbaac"; ///pieder L(G)

///char word[30]="acaaaaaabbaaaaaaaaaaaaaaaaaa"; ///pieder L(G)
///char word[30]="abbabbabbbbabbabbaaaaabb";///pieder L(G)


    char c[2];
///gramatika-rindas pirmais simbols vai klut par kadu no nakamajiem simboliem
char arrChar[28][100]={   {"SX3XTCXXHXCYYSUFEA2XGSCEQXBXM"},
                        {"AYUXKXBEWUSXIFEXXA2XGSCEQ"},
                        {"CXEYUXKXB"},
                        {"DXYXOZYXU"},
                        {"EEWUSXIFEXXA2XGSCEQXB"},
                        {"FA2FEXGSCEQXBXM"},
                    {"Yb"},
                    {"Xa"},
                    {"Zc"},
                    {"3EH"},
                    {"OEU"},
                    {"MCP"},
                        {"QXM"},
                        {"VXY"},
                        {"ICS"},
                        {"WXX"},
                        {"JAL"},
                        {"KXJ"},
                    {"LYC"},
                    {"PDX"},
                    {"BVC"},
                    {"GEB"},
                    {"RAZ"},
                    {"1AR"},
                        {"2X1"},
                        {"TEC"},
                        {"UYY"},
                        {"HXU"}};
                        ///masivs ir saistits ar ieprieksejo masivu
                        ///rindas pirmais elements rada cik elementi sekos
                        ///otrais un parejie ir elementu sakuma pozicijas
                        ///{1,1,2} nozime: 1elements, sakas ar poziciju 1, beidzas ar poziciju 2 masiva
        int arrInt[28][20]={{14,1,3,5,7,9,11,13,15,17,19,21,23,25,27,28},
                            {12,1,3,5,7,9,11,13,15,17,19,21,23,25},
                            {4,1,3,5,7,9},
                             {4,1,3,5,7,9},
                            {10,1,3,5,7,9,11,13,15,17,19,21},
                            {7,1,3,5,7,9,11,13,15},
                        {1,1,2},
                        {1,1,2},
                        {1,1,2},
                        {1,1,3},
                        {1,1,3},
                        {1,1,3},
                            {1,1,3},
                            {1,1,3},
                            {1,1,3},
                            {1,1,3},
                            {1,1,3},
                            {1,1,3},
                        {1,1,3},
                        {1,1,3},
                        {1,1,3},
                        {1,1,3},
                        {1,1,3},
                        {1,1,3},
                            {1,1,3},
                            {1,1,3},
                            {1,1,3},
                            {1,1,3}
                                    };
    n=0;
    while(word[n]!=0)
    {
        n++;
    }
    for(i=1;i<=n;i++)///sola garums
    {
        m=m+i;
    }

    marr=new int* [m];
    d=new int[n];///diff
    d[0]=0;
    l=n;
    for(i=1;i<n;i++)///set diff arr
    {
        d[i]=d[i-1]+l;
        l=l-1;
    }
    for(i=0;i<m;i++)///viena rinda saja masiva atbilst vienai rutinai cyk algoritma
    {
       marr[i]=new int [1000000];
       marr[i][0]=0;
    }
    for(j=0;j<n;j++)
    {
        c[0]=word[j];
        c[1]=0;
        searchString2(c,arrInt,arrChar,marr,j);
    }
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=n-i+1;j++)///start of span
        {
            for(k=1;k<=i-1;k++)///partition of span
            {
                x1=marr[d[k-1]+j-1][0];///elementu sk rinda
                y1=marr[d[i-k-1]+j+k-1][0];
                r=d[i-1]+j-1;///rezultata rinda masiva marr
                for(x=1;x<=x1;x++)
                {
                    for(y=1;y<=y1;y++)
                    {
                        c[0]=arrChar[marr[d[k-1]+j-1][x]][0];
                        c[1]=arrChar[marr[d[i-k-1]+j+k-1][y]][0];
                        c[2]=0;
                        searchString2(c,arrInt,arrChar,marr,r);
                        Print(r,marr);

                    }
                }
            }
        }
    }
    j=marr[m-1][0];

    for(i=1;i<=j;i++)
    {
        if(marr[m-1][i]==0)
        {
            cout<<"Ir uz generejams!"<<endl;
            break;
        }
    }

for (i=0; i<m; i++) delete[] marr[i];
 delete[] marr;

    return 0;
}
