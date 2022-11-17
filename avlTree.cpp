#include<iostream>
using namespace std;
struct Node
{
    int info;
    Node* left;
    Node* right;
    Node* parent;
    int height;
    Node(int info)
    {
        this->info = info;
        left = NULL;
        right = NULL;
        parent = NULL;
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
        y->left = x;
        if(y != NULL)
            y->parent = x;
        if(t != NULL)
            t->parent = y;

//        y->height = maxNum(height(y->left),height(y->right)) + 1;
//        x->height = maxNum(height(x->left),height(x->right)) + 1;

        return x;
    }
    Node* leftRotate(Node* y)
    {
        Node* x = y->right;
        Node* t = x->left;

        x->left = y;
        y->right = t;
        if(y != NULL)
            y->parent = x;
        if(t != NULL)
            t->parent = y;

//        y->height = maxNum(height(y->left),height(y->right)) + 1;
//        x->height = maxNum(height(x->left),height(x->right)) + 1;

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
		Node* temp = new Node(x);
		if(root == NULL)
		{
			root = temp;
			return;
		}
		Node* p = root, *q, *prob = NULL;
		while(p != NULL)
		{
			if(x < p->info)
			{
				q = p;
				if(getBalance(p) == 1)
                    prob = p;
				p = p->left;
			}
			else
			{
				q = p;
				if(getBalance(p) == -1)
                    prob = p;
				p = p->right;
			}
		}
		if(x < q->info)
			q->left = temp;
		else
			q->right = temp;

        temp->parent = q;

        Node* pr = temp->parent;
        while(pr != NULL)
        {
            pr->height = 1 + maxNum(height(pr->left),height(pr->right));
            cout<<pr->info<<" height changed : "<<pr->height<<endl;
            pr = pr->parent;
        }

		if(prob != NULL)
        {
            int bal = getBalance(prob);
            cout<<"balance of problem node : "<<bal<<endl;
            cout<<"prob node : "<<prob->info<<endl;

            //ll case
            if(bal > 1 && x < prob->left->info)
            {
                if(prob == root)
                {
                    prob = rightRotate(prob);
                    root = prob;
                    root->parent = NULL;
                }
                else
                {
                    Node* a = prob->parent;
                    prob = rightRotate(prob);
                    a->left = prob;
                }
            }

            //rr case
            if(bal < -1 && x > prob->right->info)
            {
                if(prob == root)
                {
                    prob = leftRotate(prob);
                    root = prob;
                    root->parent = NULL;
                }
                else
                {
                    Node* a = prob->parent;
                    prob = leftRotate(prob);
                    a->right = prob;
                }
            }

            //lr case
            if(bal > 1 && x > prob->left->info)
            {
                prob->left = leftRotate(prob->left);
                prob = rightRotate(prob);
            }

            //rl case
            if(bal < -1 && x < prob->right->info)
            {
                if(prob == root)
                {
                    Node* a = rightRotate(prob->right);
                    prob->right = a;
                    prob = leftRotate(prob);
                    root = prob;
                    root->parent = NULL;
                }
                else
                {
                    Node* pr = prob->parent;
                    Node* a = rightRotate(prob->right);
                    prob->right = a;
                    prob = leftRotate(prob);
                    pr->right = prob;
                }
            }
        }
        prob = NULL;
    }
    void preOrder(Node* p)
    {
    	if(p == NULL)
    		return;
    	cout<<p->info<<" ";
    	preOrder(p->left);
    	preOrder(p->right);
	}
};
//int main()
//{
//	AVLtree tree;
//	tree.insert(50);
//	tree.insert(60);
//	tree.insert(55);
//	tree.insert(70);
//	tree.insert(65);
//	tree.insert(68);
//
//	Node* root = tree.getRoot();
//
//    cout<<endl;
//	tree.preOrder(root);
//}
