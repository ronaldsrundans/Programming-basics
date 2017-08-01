#include <iostream>
#include <cstring>
using namespace std;
int lenght(char *c)
{
 int a;
    a=strlen(c);
    return a;
}
void fja(char*a, char* b, char*arr3)
{

    int x,y,z,u;
    x=lenght(a);
    y=lenght(b);
    if(x>y)
    {
        u=y;
    }
    else
    {
        u=x;
    }
    z=x+y;

   // char arr3[z];
    for(int i=0;i<(u*2);i++)
    {

            if(i%2==0)
            {
            arr3[i]=a[i/2];
            }
            else
            {
            arr3[i]=b[i/2];
            }
    }
    for(int i=(u*2);i<z;i++)
    {
        if(u==y)
        {
            arr3[i]=a[i-u];
        }
        else
        {
            arr3[i]=b[i-u];
        }
    }
    arr3[z]=0;

}
int main()
{
    char arr1[]="Super!";
    char arr2[]="Hello world!";//"Super!";
    char arr3[lenght(arr1)+lenght(arr2)];

    fja(arr1,arr2, arr3);
cout<<arr3<<endl;
    return 0;
}
