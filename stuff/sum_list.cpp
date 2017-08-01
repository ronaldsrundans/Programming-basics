#include <iostream>

using namespace std;

template <class DataType>

struct Node
{
	DataType data;
	Node<DataType> *next;
};

template <class DataType>
class LinkedList
{
public:
LinkedList()
	LinkedList (const LinkedList<DataType> & aplist);
	~LinkedList();

};

int main()
{
    return 0;
}
