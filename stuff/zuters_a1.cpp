#include <iostream>
#include <fstream>
using namespace std;
struct elem
{
    int num;
    elem* next;
};
void move_last(elem* &first,elem* last,const char *filename)
{
    fstream fin2(filename, ios::in);
    fin2.close();
    last->num;
    elem*r=first;
    elem *p=NULL;
    elem *q=NULL;
    elem *l=last;
    while(r!=NULL)
    {
        //cout<<p->num<<endl;
        if(p!=NULL)
        {
     cout<<p->num<<endl;
        }
        if(q!=NULL)
        {
     cout<<q->num<<endl;
        }
        cout<<r->num<<endl;
        if(r->next==NULL)
        {
             cout<<"yes!"<<endl;
             last=r;
             delete last;

             //delete p;
             //delete q;

        }
        l=p;
        p=q;
        q=r;
        r=r->next;
    }
    last=l;
    last->next=NULL;

}

int main()
{
    int n;
    fstream fout("filename.bin", ios::out);
    for(int i=1;i<6;i++)
    {
        fout.write((char*)&i,sizeof(int));
    }
    fout.close();
    fstream fin("filename.bin", ios::in);
    fin.read((char*)&n,sizeof(int));
    while(fin)
    {
        cout<<n<<endl;
        fin.read((char*)&n,sizeof(int));
    }
    fin.close();
    elem* first=NULL, *last=NULL, *p;
    int i=1;
    while(i<6)
    {
        p=new elem ;
        p->num=i;
        p->next=NULL;
        if (first ==NULL)
        {
            first=last=p;
        }
        else
        {
            last->next=p;
            last=last->next;
        }
        i++;
    }
    cout << "Hello world!" << endl;
    char*f="filename.bin" ;
    cout<<f<<endl;
    move_last(first,last,f);
    cout << "Hello world!" << endl;
    for(p=first;p!=NULL;p=p->next)
    {
        cout<<p->num<<endl;
    }
    while(p!=NULL)
    {
        first=first->next;
        delete p;
        p=first;
    }

    return 0;
}
