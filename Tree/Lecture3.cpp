#include <iostream>
#include <Queue>

using namespace std;
// build treee from inorder and preoder travaersal

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

int findPosition(int arr[], int n, int element)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
        return -1;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();

        q.pop();

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

Node *buildTreeFromPreOderInOrder(int inorder[], int preorder[], int size, int &preIndex, int inorderStart, int inorderEnd)
{

    // vase case
    if (preIndex >= size || inorderStart > inorderEnd)
    {
        return NULL;
    }

    // Step A;
    int element = preorder[preIndex++];

    Node *root = new Node(element);

    int pos = findPosition(inorder, size, element);

    root->left = buildTreeFromPreOderInOrder(inorder, preorder, size, preIndex, inorderStart, pos - 1);
    root->right = buildTreeFromPreOderInOrder(inorder, preorder, size, preIndex, inorderStart, pos + 1);

    return root;
}
int main()
{
    int inorder[] = {40, 20, 50, 10, 60, 30, 70};
    int preorder[] = {10, 20, 40, 50, 30, 60, 70};
    int size = 7;
    int preIndex = 0;
    int inorderStart = 0;
    int inorderEnd = size - 1;

    std::cout << "Building Tree" << endl;

    Node *root = buildTreeFromPreOderInOrder(inorder, preorder, size, preIndex, inorderStart, inorderEnd);

    std::cout << endl;
    cout << "Printing level order traversal" << endl;
    levelOrderTraversal(root);
    return 0;
}
