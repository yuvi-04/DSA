#include<iostream>
using namespace std;
struct Node
{
    int info;
    Node* left;
    Node* right;
    int height;
    Node(int info)
    {
        this->info = info;
        left = NULL;
        right = NULL;
        height = 1;
    }
};
class AVLtree
{
private:
    Node* root;
    int height(Node* n)
    {
        if(n == NULL)
            return 0;
        return n->height;
    }
    int maxNum(int a,int b)
    {
        return (a > b) ? a: b;
    }
    Node* rightRotate(Node* y)
    {
        Node* x = y->left;
        Node* t = x->right;

        x->right = y;
        y->left = t;

        y->height = maxNum(height(y->left),height(y->right)) + 1;
        x->height = maxNum(height(x->left),height(x->right)) + 1;

        return x;
    }
    Node* leftRotate(Node* y)
    {
        Node* x = y->right;
        Node* t = x->left;

        x->left = y;
        y->right = t;

        y->height = maxNum(height(y->left),height(y->right)) + 1;
        x->height = maxNum(height(x->left),height(x->right)) + 1;

        return x;
    }
    int getBalance(Node* n)
    {
        if(n == NULL)
            return 0;
        return (height(n->left) - height(n->right));
    }
public:
    AVLtree()
    {
        root = NULL;
    }
    Node* getRoot()
    {
        return root;
    }
    void insert(int x)
    {

    }
};
