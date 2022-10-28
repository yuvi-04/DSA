#include<iostream>
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
        Node* first = start;
        Node* last = start;
        Node* p = start->next;
        while(p != NULL)
        {
            if(p->info > last->info)
            {
                Node* temp = p;
                p = p->next;
                last->next = temp;
                last = temp;
                //cout<<"if 1 success"<<endl;
            }
            else if(first->info > p->info)
            {
                Node* temp = p;
                p = p->next;
                temp->next = first;
                first = temp;
                //cout<<"if 2 success"<<endl;
            }
            else
            {
                Node* temp = p;
                p = p->next;
                Node* current;
                Node* q = first;
                while(q->info < temp->info)
                {
//                    cout<<"mini while entered"<<endl;
                    current = q;
                    q = q->next;
                }
                temp->next = q;
                current->next = temp;
  //              cout<<"if 3 success"<<endl;
            }
        }
        last->next = NULL;
        start = first;
        return;
    }
    void rev()
    {
        Node* current = start;
        Node* prev = NULL;
        Node* p = start->next;
        current->next = NULL;
        while(p != NULL)
        {
            prev = current;
            current = p;
            p = p->next;
            current->next = prev;
        }
        start = current;
        return;
    }
};
int main()
{
    LinkedList list1;
    list1.insert(27);
    list1.insert(31);
    list1.insert(11);
    list1.insert(10);
    list1.insert(51);
    list1.insert(4);
    list1.insert(21);

    cout<<"ORIGNAL LIST : "; list1.printList(); cout<<endl;
    cout<<"SORTED LIST : "; list1.sortList(); list1.printList(); cout<<endl;
    cout<<"REVERSED LIST : "; list1.rev(); list1.printList();
}
