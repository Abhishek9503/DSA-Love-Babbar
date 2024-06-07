#include <iostream>
#include <queue>

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
        this->left = NULL;
        this->right = NULL;
    }
};
int findPosition(int arr[], int n, int element)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

Node *bulidTreeFromPreOrderInOrder(int inorder[], int preorder[], int size, int &preIndex, int inorderStart, int inorderEnd)
{

    // base case
    if (preIndex >= size || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = preorder[preIndex++];

    Node *root = new Node(element);

    int pos = findPosition(inorder, size, element);

    // step b root->left

    root->left = bulidTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, inorderStart, pos - 1);

    root->right = bulidTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, pos + 1, inorderEnd);

    return root;
}


void levelOrderTraversal(Node *root)
{
    //  15 NULL 25 35 NULL 5 75 90 NULL
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

int main()
{
    int inorder[] = {40, 20, 50, 10, 60, 30, 70};
    int preorder[] = {10, 20, 40, 50, 30, 60, 70};

    int size = 7;

    int preIndex = 0;
    int inorderstart = 0;
    int inorderEnd = size - 1;

    cout << "Building treee :" << endl;

    Node *root = bulidTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, inorderstart, inorderEnd);

    cout << "Printing level order traversal " << endl;

    levelOrderTraversal(root);

    return 0;
}