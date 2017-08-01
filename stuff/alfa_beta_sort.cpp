#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int size1=101;
    char carr[1010000];
    char tmpcarr[size1];

    int n=0;
    int l=0;
    bool b=1;
    do
    {
    cin.getline(tmpcarr,101);
    l=strlen(tmpcarr);

    cout<<tmpcarr<<" otrs="<<carr[(n-1)*size1]<<endl;

    if(n==0 || carr[(n-1)*size1]<tmpcarr[0])///piekabina beigas
    {
          int i=0;
        while(tmpcarr[i]!=0)
        {
            carr[i+n*size1]=tmpcarr[i];
            i++;
        }
         carr[i+n*size1]=0;
        n++;
    }
    else if(n>0 && carr[0]>tmpcarr[0])
    {
        ///parbida visus vardus par 1 poziciju
        int i=n+1;
        while(i>0)
        {

                int m=0;
                while(carr[(i-1)*size1+m]!=0)
                {
                    carr[i*size1+m]=carr[(i-1)*size1+m];
                    m++;
                }
                carr[i*size1+m]=0;
                i--;
        }
        i=0;///ieraksta jauno pirmo
        while(tmpcarr[i]!=0)
        {
            carr[i]=tmpcarr[i];
            i++;
        }
         carr[i]=0;
        n++;
    }
    else if(n>0)///binari mekle poziciju
    {
        int first=0;
        int last=n-1;
        int mid=(first+last)/2;
        int m=1;

        cout<<"binari mekle poziciju"<<endl;
        cout<<"mid="<<mid<<" first="<<first<<" last="<<last<<endl;
        cout<<"carr[mid]="<<carr[mid]<<endl;
        while(first<=last && carr[mid*size1]!=tmpcarr[0])
        {
 //cout<<"mid="<<mid<<" last="<<last<<" first="<<first<<" n="<<n<<endl;
            if(carr[mid*size1]==tmpcarr[0])///vienadi sakuma burti
            {
                cout<<"Vienadi sakuma burti"<<endl;
            }
            else if(tmpcarr[0]>carr[mid*size1])///dazadi sakuma burti
            {
                first=mid+1;
            }
            else
            {
                last=mid-1;
            }
            mid=(first+last)/2;

        }
       // cout<<"mid="<<mid<<" last="<<last<<" first="<<first<<" n="<<n<<endl;
        if(first>last)///parbida visus vardus par 1 poziciju
        {
            int p=n;
            cout<<"p="<<p<<endl;
            while(p>first)
            {
                carr[p*size1]=carr[(p-1)*size1];
                p--;
            }
            p=0;
            ///ieraksta jauno vardu vieta
            while(tmpcarr[p]!=0)
            {
                carr[p+first*size1]=tmpcarr[p];
                p++;
            }
            carr[p+first*size1]=0;
            n++;
        }
         /*
       else if(n>0 && carr[0]>tmpcarr[0])
    {

        int i=n+1;
        while(i>0)
        {

                int m=0;
                while(carr[(i-1)*size1+m]!=0)
                {
                    carr[i*size1+m]=carr[(i-1)*size1+m];
                    m++;
                }
                carr[i*size1+m]=0;
                i--;
        }
        i=0;///ieraksta jauno pirmo
        while(tmpcarr[i]!=0)
        {
            carr[i]=tmpcarr[i];
            i++;
        }
         carr[i]=0;
        n++;
    }*/





            cout<<"while cikls apstajas!"<<endl;
       /* while(m!=l && first<=last)
        {


        if(carr[mid*size1]==tmpcarr[0])///vienadi sakuma burti
        {

            while(m<=l)
            {
                if(carr[m+mid*size1]==tmpcarr[m])///parejie burti tiek salidzinati
                {
                    m++;
                }
                else if(carr[m+mid*size1]<tmpcarr[m])
                {
                    first=mid+1;
                    break;
                }
                else if(carr[m+mid*size1]>tmpcarr[m])
                {
                    last=mid-1;
                    break;
                }


            }
            if(m==l)
            {
                cout<<"Vienadi vardi"<<endl;

            }
           // if()

        }

        else if(carr[mid*size1]<tmpcarr[0])
        {
                    first=mid+1;
                    break;
        }
        else if(carr[mid*size1]>tmpcarr[0])
        {
                    last=mid-1;
                    break;
        }
        mid=(first+last)/2;
        }
       /// if(carr[mid*size1])
       // {

       // }
       */
    }
    //cout<<"n cikla beigas="<<n<<endl;

    cout << "Turpinat?" << endl;
    cin>>b;
    cin.clear();
    cin.ignore (101,'\n');
    }
    while(b==1);
    int m=0;
    while(m<n)
    {
        int i=0;
        while(carr[i+m*size1]!=0)
        {
            cout<<carr[i+m*size1];
            i++;
        }
        cout<<endl;
        m++;
    }

    cout<<n<<endl;
    return 0;
}
