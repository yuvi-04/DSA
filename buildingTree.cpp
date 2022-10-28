#include<list>
#include<iostream>
using namespace std;
struct BldInfo
{
    int year;
    int floor;
    float dist;
    BldInfo()
    {
        year = 0;
        floor = 0;
        dist = 0;
    }
    BldInfo(int year,int floor,float dist)
    {
        this->year = year;
        this->floor = floor;
        this->dist = dist;
    }
};
struct Node
{
    BldInfo bld;
    Node* left;
    Node* right;
    Node* middle;
    Node(BldInfo bld)
    {
        this->bld = bld;
        left = NULL;
        right = NULL;
        middle = NULL;
    }
};
struct BstNode
{
    float dist;
    Node* node;
    BstNode* left;
    BstNode* right;
    BstNode(float dist)
    {
        this->dist = dist;
        node = NULL;
        left = NULL;
        right = NULL;
    }
};
class BuildingTree
{
    Node* root;
public:
    BuildingTree()
    {
        root = NULL;
    }
    Node* getRoot()
    {
        return root;
    }
    void getlist(Node* p,list<Node*> &l)
    {
        if(p == NULL)
            return;
        else
        {
            l.push_back(p);
            getlist(p->left,l);
            getlist(p->middle,l);
            getlist(p->right,l);
        }
    }
    void insert(BldInfo b)
    {
        Node* temp = new Node(b);
        if(root == NULL)
        {
            root = temp;
            return;
        }
        Node* p = root;
        Node* q;
        while(p != NULL)
        {
            if(b.year < p->bld.year)
            {
                q = p;
                p = p->left;
            }
            else if(b.year > p->bld.year)
            {
                q = p;
                p = p->right;
            }
            else
            {
                q = p;
                p = p->middle;
            }
        }
        if(temp->bld.year < q->bld.year)
            q->left = temp;
        if(temp->bld.year > q->bld.year)
            q->right = temp;
        if(temp->bld.year == q->bld.year)
            q->middle = temp;
    }
    void inOrder(Node* p)
    {
        Node* temp = p;
        if(temp == NULL) return;
        inOrder(temp->left);
        cout<<"year : "<<temp->bld.year<<" floors: "<<temp->bld.floor<<" dist : "<<temp->bld.dist<<endl;
        inOrder(temp->middle);
        inOrder(temp->right);
    }
};
int main()
{
    BuildingTree b;

    BldInfo b1(1996,10,2.6);
    BldInfo b2(1974,15,6.2);
    BldInfo b3(2001,12,1.5);
    BldInfo b4(1996,4,3.0);
    BldInfo b5(1976,6,5.1);
    BldInfo b6(2004,34,3.4);

    b.insert(b1); b.insert(b2); b.insert(b3); b.insert(b4); b.insert(b5); b.insert(b6);

    Node* root = b.getRoot();

    list<Node*> temp;
    b.getlist(root,temp);
    for(auto const &i : temp)
        cout<<i<<endl;
}
