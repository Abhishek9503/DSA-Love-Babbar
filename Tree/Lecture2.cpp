#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree()
{
    int data;
    cout << "Enter the data:" << endl;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    // step A B and C
    Node *root = new Node(data);

    cout << "Enter data for left part of " << data << "node" << endl;

    root->left = buildTree();

    cout << "Enter data for right part of " << data << "node" << endl;

    root->right = buildTree();

    return root;
};

bool kthAnestor(Node *root, int &k, int p)
{

    if (root == NULL)
        return false;

    if (root->data == p)
        return true;

    bool left = kthAnestor(root->left, k, p);
    bool right = kthAnestor(root->right, k, p);

    if (left || right)
        k--;
    if (k == 0)
    {
        cout << "Answer" << root->data << endl;
        k = -1;
    }

    return left || right;
}

int main()
{
    Node *root = NULL;
    root = buildTree();

    cout << endl;
    int k = 1;
    int p = 4;
    bool found = kthAnestor(root, k, p);
    return 0;
}