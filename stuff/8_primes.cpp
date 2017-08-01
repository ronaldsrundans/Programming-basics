#include <iostream>

using namespace std;
bool prime(int num)
{
    for(int i=2;i<num;i++)
    {
        if(num%i==0)return false;
    }
    return true;
}
int main()
{
    int a,b,c,d,e,f,g,h;
    int s=0,r=1,l=100;
    for(a=2;a<l;a++)
    {
        s=0;
        r=1;
        if(prime(a)==1)
        {
            s=s+a*a;
            r=r*a;
         for(b=2;b<l;b++)
         {


           if(prime(b)==1)
            {
                s=s+b*b;
            r=r*b;

              for(c=2;c<l;c++)
              {
                    if(prime(c)==1)
                    {



                   for(d=2;d<l;d++)
                   {
                         if(prime(d)==1)
                            {


                        for(e=2;e<l;e++)
                        {
                              if(prime(e)==1)
                                {


                             for(f=2;f<l;f++)
                             {
                                   if(prime(f)==1)
        {
                                  for(g=2;g<l;g++)
                                  {
                                        if(prime(g)==1)
                                        {
                                       for(h=2;h<l;h++)
                                       {
                                             if(prime(h)==1)
                                            {
                                            cout<<a<<endl;
                                           s=a*a+b*b+c*c+d*d+e*e+f*f+g*g+h*h;
                                           r=4*a*b*c*d*e*f*g*h;
                                           if(s-r==992)
                                           {
                                               cout<<"yes"<<endl;
                                           }
                                            }

                                       }
                                        }
                                  }
        }
                             }
                        }
                        }
        }
                   }
                    }

            }
            }
        }}
    }
    //cin>>n;
   // cout << prime(n) << endl;
    return 0;
}
