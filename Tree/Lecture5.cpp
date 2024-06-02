#include <iostream>
#include <Queue>
#include <map>

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

    // cout << "Enter data for left part of " << data << "node" << endl;

    root->left = buildTree();

    // cout << "Enter data for right part of " << data << "node" << endl;

    root->right = buildTree();

    return root;
};

void printTopView(Node *root)
{
    if (root == NULL)
        return;

    map<int, int> topNode;

    // level Order
    // we will store a pair consisting fo Node and horizontal Distance

    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        if (topNode.find(hd) == topNode.end())
        {
            topNode[hd] = frontNode->data;
        }

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));

        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }

    // ab answer print krde h

    for (auto i : topNode)
    {
        cout << i.first << "->" << i.second << endl;
    }
}

void bottomview(Node *root)
{
    if (root == NULL)
        return;

    map<int, int> topNode;

    // level Order
    // we will store a pair consisting fo Node and horizontal Distance

    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        topNode[hd] = frontNode->data;

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));

        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }

    // ab answer print krde h

    for (auto i : topNode)
    {
        cout << i.first << "->" << i.second << endl;
    }
}

void leftview(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;

    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    leftview(root->left, ans, level + 1);
    leftview(root->right, ans, level + 1);
}

void rightview(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;

    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    rightview(root->right, ans, level + 1);

    rightview(root->left, ans, level + 1);
}

void printleftNode(Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;
    cout << root->data << " ";
    if (root->left)
    {
        printleftNode(root->left);
    }
    else
    {
        printleftNode(root->right);
    }
}

void printleafNode(Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
    }
    printleafNode(root->left);
    printleafNode(root->right);
}

void printrightNode(Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;
    if (root->right)
    {
        printrightNode(root->right);
    }
    else
    {
        printrightNode(root->left);
    }

    cout << root->data << " ";
}

// boundary tarversal
void boundaryTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";

    printleftNode(root->left);
    printleafNode(root);
    printrightNode(root->right);
}

int main()
{

    Node *root = buildTree();

    // printTopView(root);
    // cout << endl;
    // bottomview(root);
    // cout << endl;

    // vector<int> ans;
    // int level = 0;
    // // leftview(root, ans, level);

    // rightview(root, ans, level);

    boundaryTraversal(root);
    // printnign the left view
    // for (auto i : ans)
    // {
    //     cout << i;
    //     cout << " ";
    // }
    return 0;
}
 
