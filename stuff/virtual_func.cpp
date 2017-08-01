#include <iostream>

using namespace std;

class number
{
    int a;
public:
    number (int x){a=x;};
    virtual void print ()const {cout<<a<<endl;};
};
class twonumbers : public number
{
    int b;
public:
    twonumbers(int x, int y):number(x)
    {
        b=y;
    };
    void print()const
    {
        number::print();
        cout<<b<<endl;
    }
};
int main()
{
    number* nums[2];
    nums[0]=new number (99);
    nums[1]=new twonumbers(5,7);
    nums[0]->print();
    nums[1]->print();
    //cout << "Hello world!" << endl;
    return 0;
}
