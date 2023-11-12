#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(Node *l, Node *r, int val)
    {
        left = l;
        right = r;
        value = val;
    }
};

class BST
{
public:
    Node *root;

    BST()
    {
        root = NULL;
    }
};

int main()
{
    cout << "here's goes the tree." << endl;

    Node *new_node = new Node(NULL, NULL, 5);
    BST *bst = new BST();
    bst->root = new_node;
    cout << bst->root->value << endl;

    return 0;
}
