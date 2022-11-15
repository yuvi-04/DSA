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

		q->height = 1 + maxNum(height(temp->left),height(temp->right));

		if(prob != NULL)
        {
            int bal = getBalance(prob);

            //ll case
            if(bal > 1 && x < prob->left->info)
                prob = rightRotate(prob);

            //rr case
            if(bal < -1 && x > prob->right->info)
                prob = leftRotate(prob);

            //lr case
            if(bal > 1 && x > prob->left->info)
            {
                prob->left = leftRotate(prob->left);
                prob = rightRotate(prob);
            }

            //rl case
            if(bal < -1 && x < prob->right->info)
            {
                prob->right = rightRotate(prob->right);
                prob = leftRotate(prob);
            }
        }
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
/*int main()
{
	AVLtree tree;
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	tree.insert(40);
	tree.insert(50);
	tree.insert(25);

	Node* root = tree.getRoot();

	tree.preOrder(root);
}*/
