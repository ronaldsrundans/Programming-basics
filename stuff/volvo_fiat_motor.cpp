#include <iostream>

using namespace std;
bool good(int x0,int x1,int x2,int x3,int x4,int y0,int y1,int y2,int y3,int z0,int z1,int z2,int z3,int z4)
{
    if(x0==x3&&x0==z1&&z1==z3&&x1==x4&&y0==z2)
    {
        return 1;
    }
    else return 0;
}

int main()
{
    int i,j,k,l,m,n,o,p,r,s;
    int x,x1,x0,x2,x3,x4;
    int y,y0,y1,y2,y3,y4;
    int z,z0,z1,z2,z3,z4;
    for(j=1;j<=9;j++)
    {
        x4=x1=j;
        for(k=0;k<=9;k++)
        {
            z1=z3=x3=x0=k;
            for(l=0;l<=9;l++)
            {
                x2=l;
                x=x0+x1*10+x2*100+x3*1000+x4*10000;

                for(m=1;m<=9;m++)
                {
                    y3=m;
                    for(n=0;n<=9;n++)
                    {
                        y2=n;
                        for(o=0;o<=9;o++)
                        {
                            y1=o;
                            for(i=1;i<=9;i++)
                            {
                                z2=y0=i;
                                y=y0+y1*10+y2*100+y3*1000;

                               for(p=1;p<=9;p++)
                                {
                                     z4=p;
                                    for(r=0;r<=9;r++)
                                    {
                                        z0=r;
                                z=z0+z1*10+z2*100+z3*1000+z4*10000;


                                           if(good(x0,x1,x2,x3,x4,y0,y1,y2,y3,z0,z1,z2,z3,z4)==1)
                                           {
                                               if(x>10000&&y>1000&&)
                                               cout <<"z="<<z<< endl;
                                                cout <<"x="<<x<< endl;
                                                 cout <<"y="<<y<< endl;
                                           }

                                        }


                                    }
                                }
                            }
                        }
                    }
                }
            }

        }return 0;
    }




