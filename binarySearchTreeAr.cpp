#include<iostream>
#include<queue>
#include<stack>
using namespace std;
typedef struct TreeNode
{
    int info;
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode(int info)
    {
        this->info = info;
        left = NULL;
        right = NULL;
    }
}Node;
//FOR POST ORDER NR
struct Pair
{
    Node* ptr;
    int rc;
    Pair(Node* ptr, int rc)
    {
        this->ptr = ptr;
        this->rc = rc;
    }
};
class BSTlinkList
{
public:
    Node* root;
    BSTlinkList()
    {
        root = NULL;
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
        }
        else
        {
            q->right = temp;
        }
    }
    //TRAVERSING METHODS
    void inOrder(Node* root)
    {
        Node* temp = root;
        if(temp == NULL) return;
        inOrder(temp->left);
        if(temp->info == 0) {}
        else
            cout<<temp->info<<" ";
        inOrder(temp->right);
    }
    void inOrderNR(Node* root)
    {
        Node* p = root;
        stack<Node*> s;
        while(1)
        {
            while(p != NULL)
            {
                s.push(p);
                p = p->left;
            }
        if(s.empty()){break;}
        p = s.top();
        s.pop();
        if(p->info == 0) {}
        else
            cout<<p->info<<" ";
        p = p->right;
        }
    }
    void preOrder(Node* root)
    {
        Node* temp = root;
        if(temp == NULL) return;
        if(temp->info == 0) {}
        else
            cout<<temp->info<<" ";
        preOrder(temp->left);
        preOrder(temp->right);
    }
    void preOrderNR(Node* root)
    {
        Node* p = root;
        stack<Node*> s;
        while(1)
        {
            while(p != NULL)
            {
                if(p->info == 0) {}
                else
                    cout<<p->info<<" ";
                s.push(p);
                p = p->left;
            }
        if(s.empty()){break;}
        p = s.top();
        s.pop();
        p = p->right;
        }
    }
    void postOrder(Node* root)
    {
        Node* temp = root;
        if(temp == NULL) return;
        postOrder(temp->left);
        postOrder(temp->right);
        if(temp->info == 0) {}
        else
            cout<<temp->info<<" ";
    }
    void postOrderNR(Node* root)
    {
        stack<Pair> s;
        Pair pr(root,0);
        bool done = false;

        while(1)
        {
            //let us scan left of the p first
            while(pr.ptr != NULL)
            {
                pr = Pair(pr.ptr, 0);
                s.push(pr);
                pr = Pair(pr.ptr->left,0);
            }
            if(s.empty())
            {
                cout<<"end of outer while"<<endl;
                break;
            }
            pr = s.top();
            s.pop();
            if(pr.rc == 0)
            {
                pr.rc = 1;
                s.push(pr);
                pr = Pair(pr.ptr->right,0);
            }
            else
            {
                while(pr.rc == 1)
                {
                    cout<<pr.ptr->info<<" ";
                    if(s.empty())
                    {
                        done = true;
                        break;
                    }
                    pr = s.top();
                    s.pop();
                }
                if(done) break;

                pr.rc = 1;
                s.push(pr);
                pr.ptr = pr.ptr->right;
            }
        }
    }
    void breadthFirstTraversal(Node* root)
    {
        Node* temp = root;
        queue<Node*> q;
        q.push(temp);
        while(!q.empty())
        {
            Node* fr = q.front();
            q.pop();
            cout<<fr->info<<" ";
            if(fr->left != NULL)
                q.push(fr->left);
            if(fr->right != NULL)
                q.push(fr->right);
        }
    }
    void depthFirstTraversal(Node* root)
    {
        Node* temp = root;
        stack<Node*> stk;
        stk.push(temp);
        while(!stk.empty())
        {
            Node* tp = stk.top();
            stk.pop();
            cout<<tp->info<<" ";
            if(tp->left != NULL)
                stk.push(tp->left);
            if(tp->right != NULL)
                stk.push(tp->right);
        }
    }
};
int main()
{
    BSTlinkList b;
    b.insert(50);
    b.insert(25); b.insert(100);
    b.insert(12); b.insert(37); b.insert(0); b.insert(150);
    b.insert(6);
    b.insert(601); b.insert(540); b.insert(42); b.insert(0); b.insert(810); b.insert(125); b.insert(178);
    b.insert(4);

    cout<<"INORDER : ";
    b.inOrder(b.root);
    cout<<endl;
    cout<<"INORDER NR :";
    b.inOrderNR(b.root);
    cout<<endl;

    cout<<"PREORDER : ";
    b.preOrder(b.root);
    cout<<endl;
    cout<<"PREORDER NR :";
    b.preOrderNR(b.root);
    cout<<endl;

    cout<<"POSTORDER : ";
    b.postOrder(b.root);
    cout<<endl;
    cout<<"POSTORDER NR : ";
    b.postOrderNR(b.root);
    cout<<endl;

    cout<<"BREADTH FIRST TRAVERSAL : ";
    b.breadthFirstTraversal(b.root);
    cout<<endl;

    cout<<"DEPTH FIRST TRAVERSAL : ";
    b.depthFirstTraversal(b.root);
    cout<<endl;
}
