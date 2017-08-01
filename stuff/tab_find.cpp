#include <iostream>

using namespace std;

int main()
{
    int arr[7][2]={{0,5},{1,4},{2,0},{3,1},{4,6},{5,3},{6,2}};

    int p=arr[0][1];
 //  cout <<"p=" <<p << endl;
    for(int i=p;i!=0;i=p)
  {
        cout<<arr[p][0]<<endl;
        p=arr[p][1];
   }

  //  cout <<"p="<< p << endl;
    return 0;
}
