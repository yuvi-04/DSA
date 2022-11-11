#include<iostream>
using namespace std;
struct ThrNode
{
    int data;
    ThrNode* left,*right;
    bool thread;
    ThrNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        thread = false;
    }
};
class ThrTree
{
    ThrNode* root;
public:
    ThrTree()
    {
        root = NULL;
    }
    ThrNode* getRoot()
    {
        return root;
    }
    void inOrderNR(ThrNode* temp)
    {
        ThrNode* current = temp;
        while(current->left != NULL)
            current = current->left;
        while(current != NULL)
        {
            cout<<current->data<<" ";
            if(current->thread)
                current = current->right;
            else
            {
                current = current->right;
                while(current->left != NULL)
                    current = current->left;
            }
        }
    }
    void insertTree(int x)
    {
        ThrNode* n = new ThrNode(x);
        if(root == NULL)
        {
            root = n;
            return;
        }
        ThrNode* p = root;
        ThrNode* q;
        while(p != NULL)
        {
            if(x < p->data)
            {
                q = p;
                p = p->left;
            }
            else
            {
                if(!p->thread)
                {
                    q = p;
                    p = p->right;
                }
                else
                {
                    q = p;
                    p = NULL;
                }
            }
        }
        if(x < q->data)
        {
            q->left = n;
            n->right = q;
            n->thread = true;
        }
        else
        {
            n->right = q->right;
            q->thread = false;
            n->thread = true;
            q->right = n;
        }
    }
};
//int main()
//{
//    ThrTree tree;
//    tree.insertTree(50);
//    tree.insertTree(25);
//    tree.insertTree(75);
//    tree.insertTree(12);
//    tree.insertTree(37);
//    tree.insertTree(67);
//    tree.insertTree(100);
//    tree.insertTree(18);
//    tree.insertTree(30);
//    tree.insertTree(42);
//    tree.insertTree(15);
//    tree.insertTree(21);
//
//    tree.inOrderNR(tree.getRoot());
//}
