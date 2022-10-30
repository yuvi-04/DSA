//IMPORTING STRUCTURE BldInfo FOR TESTING TREES OF OBJECT
#include "buildingTree.cpp"
#include<iostream>
using namespace std;
template<class D,class K>
struct BSTnode
{
    D* data;
    K key;
    BSTnode* left;
    BSTnode* right;
    BSTnode* parent;
    BSTnode()
    {
        data = NULL;
        key = 0;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    BSTnode(K key)
    {
        data = NULL;
        this->key = key;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    BSTnode(D* data,K key)
    {
        this->data = data;
        this->key = key;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};
template<class D,class K>
class BST
{
    BSTnode<D,K>* root;
public:
    BST()
    {
        root = NULL;
    }
    void inOrder(BSTnode<D,K>* temp)
    {
        if(temp == NULL)
            return;
        else
        {
            inOrder(temp->left);
            cout<<temp->key<<" ";
            inOrder(temp->right);
        }
    }
    BSTnode<D,K>* getRoot()
    {
        return root;
    }
    void insertTree(D* data,K key)
    {
        BSTnode<D,K>* node = new BSTnode<D,K>(data,key);
        BSTnode<D,K>* temp = root;
        if(root == NULL)
        {
            root = node;
            return;
        }
        BSTnode<D,K>* p;
        while(temp != NULL)
        {
            if(node->key < temp->key)
            {
                p = temp;
                temp = temp->left;
            }
            else
            {
                p = temp;
                temp = temp->right;
            }
        }
        if(node->key < p->key)
            p->left = node;
        else
            p->right = node;
    }
};
int main()
{
    static BldInfo b1(1996,10,2.6), b2(1974,15,6.2), b3(2001,12,1.5);
    static BldInfo b4(1996,4,3.0), b5(1976,6,5.1), b6(2004,34,3.4);

    BST<BldInfo,float> tree;
    tree.insertTree(&b1,b1.dist);
    tree.insertTree(&b2,b2.dist);
    tree.insertTree(&b3,b3.dist);
    tree.insertTree(&b4,b4.dist);
    tree.insertTree(&b5,b5.dist);
    tree.insertTree(&b6,b6.dist);

    BSTnode<BldInfo,float>* root = tree.getRoot();

    tree.inOrder(root);
}
