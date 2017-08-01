#include <cstdlib>
#include <iostream>
#include <conio.h>


using namespace std;


void sumArray(){
  int sum=0,n;
  float avg=0;
  cout<<"Enter number of items in the data set:";
  cin>>n;
  int dset[n];
  int i;
  for(i=0;i<n;i++) { //input array elements
    cout<<"dset["<<i<<"]:";
    cin>>dset[i];
  }
  //sum elements of the array and calculate the average

  for(i=0;i<n;i++)
      sum=sum+dset[i];
  avg=sum/n;
  cout<<"Total:"<<sum<<endl;
  cout<<"Average:"<<avg<<endl;
  }

//Start main
int main(){
  sumArray();
  getch();
  return 0;

}
