#include <iostream>

#include <Queue>
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
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // LNr

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int ans = 1 + max(leftHeight, rightHeight);
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree();

    levelOrderTraversal(root);
    cout << endl;

    // inorderTraversal(root);

    cout << endl;

    // cout << "Height of the tree is " << height(root) << endl;

    return 0;
}