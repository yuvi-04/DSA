#include<iostream>
using namespace std;
struct Node
{
    int info;
    Node* next;
    Node* prev;
};
class DoublyLlist
{
    Node* start;
public:
    DoublyLlist()
    {
        start = NULL;
    }
    void insert(int x)
    {
        Node* p = new Node;
        p->info = x;
        if(start == NULL)
        {
            start = p;
            start->prev = start;
            start->next = NULL;
        }
        else
        {
            p->next = start;
            p->prev = p;
            start->prev = p;
            start = p;
        }
    }
    void insertAtPos(int pos, int x)
    {
        Node* p = new Node;
        p->info = x;
        if(pos == 0)
            insert(x);
        else
        {
            Node* temp = start;
            Node* q;
            for(int i = 0; i<pos; i++)
            {
                q = temp;
                temp = temp->next;
            }
            p->next = temp;
            p->prev = q;
            q->next = p;
            temp->prev = p;
        }
    }
    void deleteNode()
    {
        start = start->next;
        start->prev = start;
    }
    void deleteNode(Node* temp)
    {
        Node* p = temp->prev;
        Node* q = temp->next;

        p->next = q;
        q->prev = p;
    }
    void deleteAtPos(int pos)
    {
        if(pos == 0)
            deleteNode();
        else
        {
            Node* temp = start;
            Node* q;
            Node* p;
            for(int i = 0; i<pos; i++)
            {
                q = temp;
                temp = temp->next;
            }
            p = temp->next;
            q->next = p;
            p->prev = q;
        }
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
};
int main()
{
    DoublyLlist l;
    l.insert(10);
    l.insert(12);
    l.insert(1);
    l.insert(40);
    l.insert(17);
    l.insert(13);
    l.insert(22);
    l.insert(21);
    l.insert(5);

    l.printList();
    cout<<endl;

    l.deleteNode();

    l.printList();
    cout<<endl;

    l.insertAtPos(1,6);

    l.printList();
    cout<<endl;

    l.insertAtPos(5,66);

    l.printList();
    cout<<endl;

    l.deleteAtPos(5);
    l.printList();
    cout<<endl;

}
