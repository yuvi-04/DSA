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

        while(1)
        {
            //let us scan left of the p first
            while(pr.ptr != NULL)
            {
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
                        break;
                    pr = s.top();
                    s.pop();
                }
                 if(s.empty())
                        break;
                pr.rc = 1;
                s.push(pr);
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
    int height(Node* root)
    {
        if(root == NULL)
            return 0;
        else
        {
            int i = height(root->left);
            int j = height(root->right);
            return (i > j) ? (i + 1) : (j + 1);
        }
    }
    //FUNCTION FOR MAX WIDTH
    int getWidth(Node* root,int level)
    {
        if(root == NULL)
            return 0;
        if(level == 1)
            return 1;
        else if(level > 1)
            return (getWidth(root->left,level-1) + getWidth(root->right,level-1));
    }
    int maxWidth(Node* root)
    {
        int maxWidth = 0;
        int width;
        int h = height(root);

        for(int i = 1; i <= h; i++)
        {
            width = getWidth(root,i);
            if(width > maxWidth)
                maxWidth = width;
        }
        return maxWidth;
    }
    Node* mirrorImage(Node* p)
    {
        if(p == NULL)
            return NULL;
        else
        {
            Node* temp = new Node(p->info);
            temp->left = mirrorImage(p->right);
            temp->right = mirrorImage(p->left);
            return temp;
        }
    }
    bool isEqual(Node* r1,Node* r2)
    {
        if(r1 == NULL && r2 == NULL)
            return true;
        if(r1 != NULL && r2 != NULL)
        {
            return (r1->info == r2->info
                && isEqual(r1->left,r2->left)
                && isEqual(r1->right,r2->right));
        }
        return false;
    }
    bool isMirrorImage(Node* p,Node* q)
    {
        if(p == NULL && q == NULL)
            return true;
        if(p && q && p->info == q->info)
            return (isMirrorImage(p->left,q->right) && isMirrorImage(p->right,q->left));
        return false;
    }
};
int main()
{
    BSTlinkList b;
    b.insert(80); b.insert(10); b.insert(100); b.insert(9); b.insert(22);
    b.insert(96); b.insert(120); b.insert(4); b.insert(18);
    b.insert(40); b.insert(101); b.insert(125); b.insert(12);

    BSTlinkList b1;
    b1.insert(80); b1.insert(10); b1.insert(100); b1.insert(9); b1.insert(22);
    b1.insert(96); b1.insert(120); b1.insert(4); b1.insert(18);
    b1.insert(40); b1.insert(101); b1.insert(125); b1.insert(12);


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

    cout<<"HEIGHT OF TREE : "<<b.height(b.root);
    cout<<endl;

    cout<<"MAX WIDTH OF TREE : "<<b.maxWidth(b.root);
    cout<<endl;

    Node* mirror = b.mirrorImage(b.root);
    cout<<"MIRROR IMAGE : ";
    b.inOrder(mirror);
    cout<<endl;

    bool test = b.isEqual(b.root,mirror);
    if(test == true)
        cout<<"TREES ARE EQUAL"<<endl;
    else
        cout<<"trees are not equal"<<endl;

    bool isMirror = b.isMirrorImage(b.root,mirror);
    if(isMirror)
        cout<<"MIRROR IMAGE CONFIRMED";
    else
        cout<<"NOT A MIRROR IMAGE";
}
