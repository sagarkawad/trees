#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }

    Node()
    {
        left = NULL;
        right = NULL;
    }
};

class Queue
{
public:
    Node *arr[100];
    int top;
    int temp;

public:
    Queue()
    {
        top = -1;
        temp = top;
    }

    void enqueue(Node *value)
    {
        arr[++top] = value;
    }

    Node *dequeue()
    {
        if (temp < top)
        {
            return arr[++temp];
        }
        return 0;
    }

    bool empty()
    {
        if (temp == top)
        {
            return true;
        }
        else
            return false;
    }

    void display()
    {
        for (int i = ++temp; i <= top; i++)
        {
            cout << arr[i]->value << " ";
        }
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

    void insert(int val)
    {
        Node *n = new Node(val);
        if (root == NULL)
        {
            root = n;
        }
        else
        {
            Node *temp = root;
            while (temp != NULL)
            {
                if (val > temp->value)
                {
                    if (temp->right == NULL)
                    {
                        temp->right = n;
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
                else if (val < temp->value)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = n;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    cout << "value already exists" << endl;
                }
            }
        }
    }

    // void find(int val)
    // {
    //     Node *temp = root;

    //     while (temp != NULL)
    //     {
    //         if (val > temp->value)
    //         {
    //             if (temp->right == NULL)
    //             {
    //                 cout << "value " << val << " doesn't exists." << endl;
    //                 break;
    //             }
    //             else
    //             {
    //                 temp = temp->right;
    //             }
    //         }
    //         else if (val < temp->value)
    //         {
    //             if (temp->left == NULL)
    //             {
    //                 cout << "value " << val << " doesn't exists." << endl;
    //                 break;
    //             }
    //             else
    //             {
    //                 temp = temp->left;
    //             }
    //         }
    //         else
    //         {

    //             cout << "value - " << val << " exists." << endl;
    //             break;
    //         }
    //     }
    // }

    void find(int val)
    {
        Node *temp = root;

        while (true)
        {
            if (temp->value == val)
            {
                cout << "value " << val << " exists." << endl;
                break;
            }
            else if ((temp->right == NULL && val > temp->value) || (temp->left == NULL && val < temp->value))
            {
                cout << "value " << val << " does not exists." << endl;
                break;
            }
            else if (val > temp->value)
            {
                temp = temp->right;
            }
            else if (val < temp->value)
            {
                temp = temp->left;
            }
        }
    }

    void BFS()
    {
        const int no = 100;
        Queue q;
        int arr[no];
        int counter = -1;
        Node *node = root;

        // push the root node to the queue
        q.enqueue(node);

        // while q is not empty, push the left and right of the node to the queue
        while (!q.empty())
        {
            node = q.dequeue();
            if (node->left != NULL)
            {
                q.enqueue(node->left);
            }
            if (node->right != NULL)
            {
                q.enqueue(node->right);
            }
            arr[++counter] = node->value;
        }
        for (int i = 0; i <= counter; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

//         5
//     3        10
//  2           8

int main()
{

    BST *bst = new BST();
    bst->insert(5);
    bst->insert(10);
    bst->insert(3);
    bst->insert(8);
    bst->insert(2);
    bst->insert(20);
    bst->find(20);
    bst->find(8);
    bst->find(5);
    bst->BFS();
    //               5
    //     3                10
    // 2                   8     20

    //[5, 3, 10, 2, 8, 20]

    return 0;
}