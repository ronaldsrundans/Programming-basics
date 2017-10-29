#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char word[5]="abbb";
    char c;
    char arrChar[3][6]={{"SSAAB"},
                        {"AABa"},
                        {"BBBb"}};
    int i,j,k;
    int arrInt [3][3]={{2,2,2},///rindas pirmais skaitlis norada elementu skaitu
                        {2,2,1},///rindas parejie skaitli - simbolu skaitu katram elementam no arrChar
                        {2,2,1}};


    for(i=0;i<4;i++)
    {
        for(j=1;j<4;j++)
        {
            c=arrChar[i][j];
            if(c==0)break;

            for(k=0;k<5;k++)
            {
                if(word[k]==c)
                {
                    cout<<c<<i<<j<<endl;
                };
            }


        }
    }
    cout << "Hello world!" << endl;
    return 0;
}
