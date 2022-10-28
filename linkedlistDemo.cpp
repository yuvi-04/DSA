#include<iostream>
#include<list>
using namespace std;
struct Node
{
    int info;
    Node* next;
};
class LinkedList
{
    Node* start;
public:
    LinkedList()
    {
        start = NULL;
    }
    void insert(int x)
    {
        Node* p = new Node;
        p->info = x;
        p->next = start;
        start = p;
    }
    void printList()
    {
        Node* p = start;
        while(p != NULL)
        {
            cout<<p->info<<" ";
            p = p->next;
        }
    }
    int deleteNode()
    {
        int x = start->info;
        Node* p = start;
        start = p->next;
        delete(p);
        return x;
    }
    void sortList()
    {

    }
};
int main()
{
    LinkedList list1;
    list1.insert(5);
    list1.insert(10);
    list1.insert(2);
    list1.insert(3);
    list1.insert(11);
    list1.insert(17);

    list1.printList();
    int x = list1.deleteNode();
    cout<<"deleted value : "<<x<<endl;
    list1.printList();
}
