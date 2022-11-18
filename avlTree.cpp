#include<iostream>
using namespace std;
struct Node
{
    int info;
    Node* left;
    Node* right;
    int bal;
    Node(int info)
    {
        this->info = info;
        left = NULL;
        right = NULL;
        bal = 0;
    }
};
class AVLtree
{
private:
    Node* root;

    Node* rightRotate(Node* y)
    {
        Node* x = y->left;
        Node* t = x->right;

        x->right = y;
        y->left = t;

        y->bal--;
        x->bal--;

        return x;
    }
    Node* leftRotate(Node* y)
    {
        Node* x = y->right;
        Node* t = x->left;

        x->left = y;
        y->right = t;

        y->bal++;
        x->bal++;

        return x;
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
		Node* p = root, *q = NULL, *prob = NULL,*pr = NULL;
		bool htchanged = false;
		while(p != NULL)
		{
			if(x < p->info)
			{
				if(p->bal != 0)
                {
                    prob = p;
                    pr = q;
                }
                q = p;
				p = p->left;
			}
			else
			{
				if(p->bal != 0)
                {
                    prob = p;
                    pr = q;
                }
                q = p;
				p = p->right;
			}
		}
		if(x < q->info)
        {
            q->left = temp;
            if(q->right)
                htchanged = false;
            else
                htchanged = true;
        }
		else
        {
            q->right = temp;
            if(q->left)
                htchanged = false;
            else
                htchanged = true;
        }

        if(prob == NULL && htchanged)
        {
            Node* lastUnchanged = root;
            while(lastUnchanged != temp)
            {
                if(temp->info > lastUnchanged->info)
                {
                    lastUnchanged->bal = lastUnchanged->bal - 1;
                    lastUnchanged = lastUnchanged->right;
                }
                else
                {
                    lastUnchanged->bal = lastUnchanged->bal + 1;
                    lastUnchanged = lastUnchanged->left;
                }
            }
        }

        if(!htchanged && prob != NULL)
        {
            q->bal = 0;
            return;
        }

		if(htchanged && prob)
        {
            //ll case
            if(prob->left && x < prob->left->info)
            {
                Node* lastUnchanged = prob;
                lastUnchanged = lastUnchanged->left;
                while(lastUnchanged != temp)
                {
                    if(temp->info > lastUnchanged->info)
                    {
                        lastUnchanged->bal = lastUnchanged->bal - 1;
                        lastUnchanged = lastUnchanged->right;
                    }
                    else
                    {
                        lastUnchanged->bal = lastUnchanged->bal + 1;
                        lastUnchanged = lastUnchanged->left;
                    }
                }
                if(prob->bal == 1)
                {
                    if(prob == root)
                    {
                       prob = rightRotate(prob);
                       root = prob;
                    }
                    else
                    {
                        prob = rightRotate(prob);
                        pr->left = prob;
                    }
                }
                return;
            }

            //rr case
            if(prob->right && x > prob->right->info)
            {
                Node* lastUnchanged = prob;
                lastUnchanged = lastUnchanged->right;
                while(lastUnchanged != temp)
                {
                    if(temp->info > lastUnchanged->info)
                    {
                        lastUnchanged->bal = lastUnchanged->bal - 1;
                        lastUnchanged = lastUnchanged->right;
                    }
                    else
                    {
                        lastUnchanged->bal = lastUnchanged->bal + 1;
                        lastUnchanged = lastUnchanged->left;
                    }
                }
                if(prob->bal == -1)
                {
                    if(prob == root)
                    {
                       prob = leftRotate(prob);
                       root = prob;
                    }
                    else
                    {
                        prob = leftRotate(prob);
                        pr->right = prob;
                    }
                }
                return;
            }

            //rl case
            if(prob->right && prob->right->left && x < prob->right->info)
            {
                Node* lastUnchanged = prob;
                lastUnchanged = lastUnchanged->right;
                while(lastUnchanged != temp)
                {
                    if(temp->info > lastUnchanged->info)
                    {
                        lastUnchanged->bal = lastUnchanged->bal - 1;
                        lastUnchanged = lastUnchanged->right;
                    }
                    else
                    {
                        lastUnchanged->bal = lastUnchanged->bal + 1;
                        lastUnchanged = lastUnchanged->left;
                    }
                }
                if(prob->bal == -1)
                {
                    if(prob == root)
                    {
                        Node* pright = prob->right;
                        Node* rep = prob->right->left;

                        if(rep->right)
                            pright->left = rep->right;
                        if(rep->left)
                            pright->left = rep->left;

                        rep->left = prob;
                        rep->right = pright;
                        prob->right = NULL;

                        rep->bal = 0;
                        prob->bal = prob->bal - 2;
                        pright->bal--;

                        root = rep;
                    }
                    else
                    {
                        Node* pright = prob->right;
                        Node* rep = prob->right->left;

                        if(rep->right)
                            pright->left = rep->right;
                        if(rep->left)
                            pright->left = rep->left;

                        rep->left = prob;
                        rep->right = pright;
                        prob->right = NULL;

                        rep->bal = 0;
                        prob->bal = prob->bal - 2;
                        pright->bal--;

                        pr->right = rep;
                    }
                }
                return;
            }

            //lr case
            if(prob->left && prob->left->right && x > prob->left->info)
            {
                Node* lastUnchanged = prob;
                lastUnchanged = lastUnchanged->left;
                while(lastUnchanged != temp)
                {
                    if(temp->info > lastUnchanged->info)
                    {
                        lastUnchanged->bal = lastUnchanged->bal - 1;
                        lastUnchanged = lastUnchanged->right;
                    }
                    else
                    {
                        lastUnchanged->bal = lastUnchanged->bal + 1;
                        lastUnchanged = lastUnchanged->left;
                    }
                }
                if(prob->bal == 1)
                {
                    if(prob == root)
                    {
                        Node* pleft = prob->left;
                        Node* rep = prob->left->right;
                        if(rep->left)
                            prob->left = rep->left;
                        if(rep->right)
                            prob->left = rep->right;
                        else
                            prob->left = NULL;

                        rep->left = pleft;
                        rep->right = prob;
                        pleft->right = NULL;

                        rep->bal = 0;
                        prob->bal--;
                        pleft->bal = pleft->bal + 2;

                        root = rep;
                    }
                    else
                    {
                        Node* pleft = prob->left;
                        Node* rep = prob->left->right;
                        if(rep->left)
                            prob->left = rep->left;
                        if(rep->right)
                            prob->left = rep->right;
                        else
                            prob->left = NULL;

                        rep->left = pleft;
                        rep->right = prob;
                        pleft->right = NULL;

                        rep->bal = 0;
                        prob->bal--;
                        pleft->bal = pleft->bal + 2;

                        pr->left = rep;
                    }
                }
                return;
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
int main()
{
	AVLtree tree;
	tree.insert(50);
	tree.insert(25);
	tree.insert(75);
	tree.insert(67);
	tree.insert(100);
	tree.insert(69);

	Node* root = tree.getRoot();

    cout<<endl;
	tree.preOrder(root);
}
