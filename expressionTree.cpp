#include<cstring>
#include<iostream>
using namespace std;
bool isOperator(char temp)
{
    switch(temp)
    {
    case '+':
        return true;
    case '-':
        return true;
    case '*':
        return true;
    case '/':
        return true;
    default:
        return false;
    }
}
struct Node
{
    char info;
    Node* left;
    Node* right;
    Node* father;

    Node(char info)
    {
        this->info = info;
        left = NULL;
        right = NULL;
        father = NULL;
    }
};
class ExpressionTree
{
public:
    Node* root;
    ExpressionTree()
    {
        root = NULL;
    }
    void inOrder(Node* root)
    {
        if(root == NULL)
            return;
        inOrder(root->left);
        cout<<root->info<<" ";
        inOrder(root->right);
    }
    ExpressionTree createTree(char a[])
    {
        ExpressionTree t;
        int i = strlen(a);
        Node* node = new Node(a[i-1]);
        t.root = node; i = i-2;
        Node* current = t.root;
        while(i != -1)
        {
            char temp = a[i];
            i--;
            Node* n = new Node(temp);
            if(isOperator(temp))
            {
                if(isOperator(current->info))
                {
                    if(current->right == NULL)
                    {
                        current->right = n;
                        n->father = current;
                        current = current->right;
                    }
                    else
                    {
                        current->left = n;
                        n->father = current;
                        current = current->left;
                    }
                }
                if(!isOperator(current->info))
                {
                    while(1)
                    {
                        current = current->father;
                        if(current->left == NULL)
                        {
                            current->left = n;
                            n->father = current;
                            current = current->left;
                            break;
                        }
                        if(current->right == NULL)
                        {
                            current->right = n;
                            n->father = current;
                            current = current->right;
                            break;
                        }
                    }
                }
            }
            if(!isOperator(temp))
            {
                if(isOperator(current->info))
                {
                    if(current->right == NULL)
                    {
                        current->right = n;
                        n->father = current;
                        current = current->right;
                    }
                }
                else if(!isOperator(current->info))
                {
                    while(1)
                    {
                        current = current->father;
                        if(current->right == NULL)
                        {
                            current->right = n;
                            n->father = current;
                            current = current->right;
                            break;
                        }
                        if(current->left == NULL)
                        {
                            current->left = n;
                            n->father = current;
                            current = current->left;
                            break;
                        }
                    }
                }
            }
        }
        return t;
    }
};
int main()
{
    ExpressionTree t1,t2;
    t1 = t2.createTree("346*+8+349*+/");
    t1.inOrder(t1.root);
}
