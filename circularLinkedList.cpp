#include<iostream>
using namespace std;
struct Node
{
    int info;
    Node* next;
};
class CLlist
{
    Node* start;
    Node* last;
public:
    CLlist()
    {
        start = NULL;
        last = NULL;
    }
    void insert(int x)
    {
        Node* p = new Node;
        p->info = x;
        if(start == NULL)
        {
            start = p;
            last = p;
            last->next = start;
            cout<<"first node added : "<<x<<endl;
        }
        else
        {
            last->next = p;
            last = p;
            last->next = start;
            cout<<"adding node : "<<x<<endl;
        }
    }
    void printCList()
    {
        Node* p = start;
        while(p != last)
        {
            cout<<p->info<<" ";
            p = p->next;
        }
        cout<<p->info;
    }
    void insertPos(int pos,int x)
    {
        Node* temp = new Node;
        temp->info = x;
        if(pos == 0)
        {
            Node* p = start;
            while(p->next != start)
            {
                p = p->next;
            }
            temp->next = start;
            start = temp;
            p->next = temp;
        }
        else
        {
            Node* p = start;
            Node* q;
            for(int i = 0; i<pos; i++)
            {
                q = p;
                p = p->next;
            }
            temp->next = p;
            q->next = temp;
        }
    }
    //QUEUE(FIRST IN FIRST OUT)
    void deleteNode()
    {
        start = start->next;
        last->next = start;
    }
    //STACK(LAST IN FIRST OUT)
    void deleteLast()
    {
        Node* p = start;
        Node* q;
        while(p->next != start)
        {
            q = p;
            p = p->next;
        }
        q->next = start;
        last = q;
    }
    void deletePos(int pos)
    {
        if(pos == 0)
            deleteNode();
        else
        {
            Node* p = start;
            Node* q;
            for(int i = 0; i<pos; i++)
            {
                q = p;
                p = p->next;
            }
            q->next = p->next;
        }
    }
};
int main()
{
    CLlist l;
    l.insert(7);
    l.insert(5);
    l.insert(20);
    l.insert(14);
    l.insert(3);
    l.insert(78);
    l.insert(10);
    cout<<endl<<"ORIGNAL LIST : "; l.printCList(); cout<<endl;
    cout<<"STACK : "; l.deleteLast(); l.printCList(); cout<<endl;
    cout<<"QUEUE : "; l.deleteNode(); l.printCList();
}
