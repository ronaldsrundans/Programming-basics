#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct state
{
    char name[20];
};
bool space(char c)
{
    if(c==' ')return 1;
    else return 0;
};
bool enter(char c)
{
    if(c=='\n')return 1;
    else return 0;
};
void fill_arr(char* arr, char* arrtmp)
{

}
int main()
{
    int n_space=0;
    int n_enter=0;
    int i=0;
    char c;
    char arr_states[30];
    char arr_2d_states[30][3];
    char arr_start[30];
    char arr_language[30];
    char arr_astates[30];

    fstream fin("in.txt", ios::in);
    fin.get(c);
    while(fin)
    {
          if(n_enter==0)///ielasa pirmo rindu no faila
            {
                cout<<"pirma rinda"<<endl;
                for(i=0;c!='\n';i++)
                {
                   /*if(c==' ')
                    {
                            fin.get(c);
                    }*/
                        cout<<c;
                        arr_states[i]=c;
                        fin.get(c);
                }
                arr_states[i]=0;
                fin.get(c);///izlaiz enter
                cout<<"arr_states="<<arr_states;
                n_enter++;
            }
            if(n_enter==1)///ielasa otro rindu no faila
            {
                cout<<"otra rinda"<<endl;
                for(i=0;c!='\n';i++)
                {

                    cout<<c;
                    arr_language[i]=c;
                    fin.get(c);
                }
                arr_language[i]=0;
                 fin.get(c);///izlaiz enter
                cout<<"arr_language="<<arr_language;
                n_enter++;
            }
            if(n_enter==2)///ielasa treso rindu no faila
            {

                cout<<"tresa rinda"<<endl;
                for(i=0;c!='\n';i++)
                {

                    cout<<c;
                    arr_start[i]=c;
                    fin.get(c);
                }
                arr_start[i]=0;
                 fin.get(c);///izlaiz enter
                cout<<"arr_start="<<arr_start;
                n_enter++;
            }
            if(n_enter==3)///ielasa ceturto rindu no faila
            {
                cout<<"ceturta rinda"<<endl;
                for(i=0;c!='\n';i++)
                {

                    cout<<c;
                    arr_astates[i]=c;
                    fin.get(c);
                }
                arr_astates[i]=0;
                fin.get(c);///izlaiz enter
                cout<<"astates="<<arr_astates;
                n_enter++;
            }
            fin.get(c);
    }

    fin.close();
    //cout << "Hello world!" << endl;
    return 0;
}
