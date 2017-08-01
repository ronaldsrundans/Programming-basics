#include <iostream>

using namespace std;

int main()
{
    int v=0,o=0,l=0,f=0,i=0,a=0,t=0,m=0,r=0;
     int volvo=0;
    int fiat=0;
    int motor=0;
    int sum=0;
    int n=1;

    for(v=1;v<10;v++)
    {
        for(f=1;f<10;f++)
            if(v!=f)
        {
            for(m=1;m<10;m++)
            {
                if(m!=f&&m!=v)
                {
                    for(o=0;o<10;o++)
                    {
                        if(o!=m&&o!=v&&o!=f)
                        {
                            for(l=0;l<10;l++)
                            {
                                if(l!=o&&l!=v&&l!=f &&m!=l)
                                {
                                    for(i=0;i<10;i++)
                                    {
                                        if(i!=l&&i!=v&&i!=o&&i!=m&&i!=f)
                                        {
                                            for(a=0;a<10;a++)
                                            {
                                                if(a!=l&&a!=v&&a!=o&&a!=m&&a!=f&&a!=i)
                                                {
                                                    for(t=0;t<10;t++)
                                                    {
                                                        if(t!=l&&t!=v&&t!=o&&t!=m&&t!=f&&t!=i&&t!=a)
                                                        {
                                                            for(r=0;r<10;r++)
                                                            {
                                                                if(r!=l&&r!=v&&r!=o&&r!=m&&r!=f&&r!=i&&r!=a&&r!=t)
                                                                {
                                                                    volvo=v*10010+o*1001+l*100;
                                                                    fiat=f*1000+i*100+a*10+t;
                                                                    motor=m*10000+o*1010+t*100+r;
                                                                    if(volvo+fiat==motor)
                                                                    {
                                                                        cout<<"NR"<<n<<" v="<<v<<" o="<<o<<" m="<<m<<" l="<<l<<" f="<<f<<" i="<<i<<" a="<<a<<" t="<<t<<" r="<< r<<endl;
                                                                        n++;
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
            }
        }



    }
    /*int volvo=v*10010+o*1001+l*100;
    int fiat=f*1000+i*100+a*10+t;
    int motor=m*10000+o*1010+t*100+r;*/
    cout << "Hello world!" << endl;
    return 0;
}
