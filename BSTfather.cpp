#include<iostream>
using namespace std;
typedef struct TreeNode
{
    int info;
    TreeNode* left;
    TreeNode* right;
    TreeNode* father;
public:
    TreeNode(int info)
    {
        this->info = info;
        left = NULL;
        right = NULL;
        father = NULL;
    }
}Node;
class BSTFather
{
    Node* root;
public:
    BSTFather()
    {
        root = NULL;
    }
    Node* getRoot()
    {
        return root;
    }
    Node* getFather(Node* temp)
    {
        return temp->father;
    }
    //TRAVERSING METHOD TO PRINT TREE
    void inOrder(Node* p)
    {
        Node* temp = p;
        if(temp == NULL)
        {
            return;
        }
        inOrder(temp->left);
        if(temp->info == 0) {}
        else
            cout<<temp->info<<" ";
        inOrder(temp->right);
    }
    void insert(int x)
    {
        Node* temp = new Node(x);
        if(root == NULL)
        {
            root = temp;
            return;
        }
        Node* p = root;
        Node* q;
        while(p != NULL)
        {
            if(x == p->info) return;
            if(x < p->info)
            {
                q = p;
                p = p->left;
            }
            else
            {
                q = p;
                p = p->right;
            }
        }
        if(temp->info < q->info)
        {
            q->left = temp;
            temp->father = q;
        }
        else
        {
            q->right = temp;
            temp->father = q;
        }
    }
    Node* inOrderSuccessor(Node* temp)
    {
        Node* p = temp;
        if(p->right != NULL)
        {
            Node* r = p->right;
            Node* lm;
            while(r != NULL)
            {
                lm = r;
                r = r->left;
            }
            return lm;
        }
        if(p->father->left == p)
            return p->father;

        while(p->father->right == p)
            p = p->father;

        return p->father;
    }
    Node* inOrderPredecessor(Node* temp)
    {
        Node* p = temp;
        Node* rm;
        if(p->left != NULL)
        {
            Node* l = p->left;
            while(l != NULL)
            {
                rm = l;
                l = l->right;
            }
            return rm;
        }
        if(p->father->right == p)
            return p->father;

        while(p->father->left == p)
            p = p->father;

        return p->father;
    }
private:
    //FUNCTION TO IMPLEMENT DELETE NODE WITH ONE OR NO CHILD : USED IN DEL2
    Node* del0OR1(Node* temp)
    {
        Node* p = temp;
        Node* son;
        if(p->left == NULL && p->right == NULL)
        {
            if(p == root && p->left == NULL && p->right == NULL)
            {
                temp = root;
                root = NULL;
                return temp;
            }
            if(p->father->left == p)
                p->father->left = NULL;
            else
                p->father->right = NULL;
            return p;
        }
        if(p->left != NULL)
            son = p->left;
        else
            son = p->right;
        if(p == root)
        {
            root = son;
            return son;
        }
        if(p->father->left == p)
            p->father->left = son;
        else
            p->father->right = son;
        return p;
    }
public:
    Node* del2(Node* p)
    {
        if(p->left == NULL || p->right == NULL)
        {
            Node* temp = del0OR1(p);
            return temp;
        }
        Node* rep = inOrderSuccessor(p);
        Node* temp = del0OR1(rep);
        temp->left = p->left;
        temp->right = p->right;
        if(p == root)
        {
            Node* q = p;
            root = temp;
            return q;
        }
        if(p->father->left == p)
            p->father->left = temp;
        else
            p->father->right = temp;
        return p;
    }
};
int main()
{
    BSTFather b;
    b.insert(80); b.insert(10); b.insert(100); b.insert(9); b.insert(22);
    b.insert(96); b.insert(120); b.insert(4); b.insert(18);
    b.insert(40); b.insert(101); b.insert(125); b.insert(12);

    Node* root = b.getRoot();

    Node* successor = b.inOrderSuccessor(root);
    cout<<"SUCCESSOR OF "<<root->info<<" = "<<successor->info<<endl;

    Node* predecessor = b.inOrderPredecessor(root);
    cout<<"PREDECESSOR OF "<<root->info<<" = "<<predecessor->info<<endl;

    cout<<"TREE : ";
    b.inOrder(root);
    cout<<endl;

    Node* temp = b.del2(root);

    cout<<"DELETED NODE : "<<temp->info<<endl;

    root = b.getRoot();

    cout<<"TREE : ";
    b.inOrder(root);
    cout<<endl;
}
