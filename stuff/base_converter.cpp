#include <iostream>

using namespace std;

int main()
{
    int b;
    char n[20];
    int num=0;
    cout << "Ievadi skaili!" << endl;
    cin.getline(n,20);
    cout << "Ievadi skaitisanas sistemas bazi!" << endl;
        cin>>b;
        cout<<n<<endl;
        int i=0;
        while(n[i]!='\0')
        {
            if(n[i]<='9')
            {
                num=num*10+((int)n[i]-'0');
                i++;

            }
            else if(n[i]>='A'&& n[i]<='Z')
            {

                num=num*10+((int)n[i]-'A'+10);
                i++;
                //cout<<"num="<<num<<endl;
            }
            else
            {
                num=num*10+((int)n[i]-'a'+10);
                i++;
            }

        }
        int *arr=new int[i];
        for(int j=0;j<=i;j++)
        {
            arr[j]=num%10;
            num=num/10;
        }
        if(b<=10)
        {
            int p=1;
            for(int j=0;j<=i;j++)
            {
              num=num+arr[j]*p;
              p=p*b;
            //cout<<arr[j]<<endl;
            }
        }
        else
        {
            int p=1, k=1;

             for(int j=0;j<=i;j++)
            {

              num=num+arr[j]*k;
              num=num%p;
              p=p*b;
              k=k*10;
            //cout<<arr[j]<<endl;
            }
        }

        delete arr;
        cout <<"Skaitlis "<<num<<endl;
        cout<<"Baze "<<b <<endl;
    return 0;
}
