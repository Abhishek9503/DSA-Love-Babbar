#include <iostream>
#include <queue>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the dta: " << endl;

    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in the left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in the right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

// recursion code

void inorder(node *root)
{
    if (root == NULL)
        return;

    // inoder LNR

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preOrder(node *root)
{
    if (root == NULL)
        return;

    // inoder LNR
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node *root)
{
    if (root == NULL)
        return;

    // inoder LNR

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{

    node *root = NULL;

    root = buildTree(root);

    cout << "Printing the lever order traversal output " << endl;

    // inorder(root);
    // preOrder(root);
    preOrder(root);
    cout << endl;

    return 0;
}